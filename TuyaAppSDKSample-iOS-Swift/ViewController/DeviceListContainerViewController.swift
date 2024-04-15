//
//  DeviceListTableViewController.swift
//  ThingAppSDKSample-iOS-Swift
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.tuya.com/)

import UIKit
import ThingSmartDeviceKit
import ThingSmartDeviceCoreKit

@available(iOS 13.0, *)
class DeviceListContainerViewController: UITableViewController, CardCellDelegate {
    // MARK: - Property
    private var home: ThingSmartHome?
    private var viewModelList : [CardCellViewModel]!
    
    
    // MARK: - Lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        self.tableView.allowsSelection = false
        self.tableView.separatorStyle = .none
        self.tableView.sectionFooterHeight = 15.0
        self.tableView.sectionHeaderHeight = CGFLOAT_MIN

        viewModelList = []
        
        if let currentHome = Home.current {
            home = ThingSmartHome(homeId: currentHome.homeId)
            home?.delegate = self
            updateHomeDetail()
        }
        
        NotificationCenter.default.addObserver(self, selector: #selector(moveToDeviceDetails), name: .goToDetails, object: nil)
    }

    @objc func moveToDeviceDetails() {
        if UserDefaults.standard.string(forKey: "schemeParameter") != nil, let viewModel = viewModelList.first {
            clickCardView(viewModel: viewModel)
        }
    }
    
    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        viewModelList.removeAll()
        
        home?.deviceList.forEach({ deviceModel in
            let viewModel = CardCellViewModel()
            viewModel.dpParser = ThingSmartDpParser.create(withTargetInfo: deviceModel)
            viewModel.device = ThingSmartDevice(deviceId: deviceModel.devId)
            viewModel.name = deviceModel.name
            viewModel.icon = deviceModel.iconUrl
            
            viewModelList.append(viewModel)
        })

        return viewModelList.count
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard let cell = tableView.dequeueReusableCell(withIdentifier: "card-cell") as? Cardcell else { return UITableViewCell(style: .default, reuseIdentifier: nil)}
        cell.cellDelegate = self
        let viewModel = viewModelList[indexPath.section]
        cell.update(viewModel: viewModel)
        return cell
    }

    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        let viewModel = viewModelList[indexPath.section]
        return Cardcell.cellHeight(viewModel: viewModel)
    }

    
    // MARK: - Private method
    func updateHomeDetail() {
        home?.getDataWithSuccess({ (model) in
            self.tableView.reloadData()
        }, failure: { [weak self] (error) in
            guard let self = self else { return }
            let errorMessage = error?.localizedDescription ?? ""
            Alert.showBasicAlert(on: self, with: NSLocalizedString("Failed to Fetch Home", comment: ""), message: errorMessage)
        })
    }
    
    private func jumpThingLinkDeviceControl(_ vc: ThingLinkDeviceControlController, device: ThingSmartDevice) {
        let goThingLinkControl = { () -> Void in
            vc.device = device
            self.navigationController?.pushViewController(vc, animated: true)
        }
        
        if let _ = device.deviceModel.thingModel {
            goThingLinkControl()
        } else {
            SVProgressHUD.show(withStatus: NSLocalizedString("Fetching Thing Model", comment: ""))
            device.getThingModel { _ in
                SVProgressHUD.dismiss()
                goThingLinkControl()
            } failure: { error in
                SVProgressHUD.showError(withStatus: NSLocalizedString("Failed to Fetch Thing Model", comment: ""))
            }
        }
    }
    
    private func jumpNormalDeviceControl(_ vc: DeviceControlViewController, device: ThingSmartDevice) {
        vc.device = device
        navigationController?.pushViewController(vc, animated: true)
    }

    // MARK: - CardCellDelegate
    func clickCardView(viewModel: CardCellViewModel) {
        jumpDeviceDetail(viewModel: viewModel, smartDp: nil)
    }
    
    func clickSwitchView(viewModel: CardCellViewModel, dps:Dictionary<AnyHashable, Any>) {
        if (viewModel.device != nil) {
            viewModel.device!.publishDps(dps, success: {
            }, failure: { (error) in
                self.tableView.reloadData();
                let errorMessage = error?.localizedDescription ?? ""
                SVProgressHUD.showError(withStatus: errorMessage)
            })
        } else if (viewModel.group != nil) {
            viewModel.group!.publishDps(dps, success: {
            }, failure: { (error) in
                self.tableView.reloadData();
                let errorMessage = error?.localizedDescription ?? ""
                SVProgressHUD.showError(withStatus: errorMessage)
            })
        }
    }
    
    func clickOperableDpView(viewModel: CardCellViewModel, smartDp: ThingSmartDp) {
        jumpDeviceDetail(viewModel: viewModel, smartDp: smartDp)
    }
    
    private func jumpDeviceDetail(viewModel: CardCellViewModel, smartDp: ThingSmartDp?) {
        guard let device = viewModel.device else { return }
        
        let storyboard = UIStoryboard(name: "ShuDtxMain", bundle: nil)
        let isSupportThingModel = device.deviceModel.isSupportThingModelDevice()
        let identifier = isSupportThingModel ? "ThingLinkDeviceControlController" : "DeviceControlViewController"
        
        let vc = storyboard.instantiateViewController(withIdentifier: identifier)
        if isSupportThingModel {
            let thingLinkVC = vc as! ThingLinkDeviceControlController
            jumpThingLinkDeviceControl(thingLinkVC, device: device)
        } else {
            if let deviceControlVC = vc as? DeviceControlViewController {
                deviceControlVC.targetSchemaModel = smartDp?.schemaModel
                jumpNormalDeviceControl(deviceControlVC, device: device)
            }
        }
    }
}

@available(iOS 13.0, *)
extension DeviceListContainerViewController: ThingSmartHomeDelegate{
    func homeDidUpdateInfo(_ home: ThingSmartHome!) {
        tableView.reloadData()
    }
    
    func home(_ home: ThingSmartHome!, didAddDeivice device: ThingSmartDeviceModel!) {
        tableView.reloadData()
    }
    
    func home(_ home: ThingSmartHome!, didRemoveDeivice devId: String!) {
        tableView.reloadData()
    }
    
    func home(_ home: ThingSmartHome!, deviceInfoUpdate device: ThingSmartDeviceModel!) {
        tableView.reloadData()
    }
    
    func home(_ home: ThingSmartHome!, device: ThingSmartDeviceModel!, dpsUpdate dps: [AnyHashable : Any]!) {
        tableView.reloadData()
    }
}
