//
//  ShuDtxViewController.swift
//  TuyaAppSDKSample-iOS-Swift
//
//  Copyright (c) 2014-2023 Tuya Inc. (https://developer.tuya.com/)

import UIKit
import ThingSmartBLEKit
import ThingSmartFamilyBizKit

class ShuDtxViewController: UIViewController {

    @IBOutlet var settings: UIButton!
    private var isSuccess = false
    let homeManager = ThingSmartHomeManager()
    
    override func viewDidLoad() {
        initiateCurrentHome()
        ThingSmartFamilyBiz.sharedInstance().getFamilyList { _ in
            ThingSmartFamilyBiz.sharedInstance().launchCurrentFamily(withAppGroupName: "")
        } failure: { error in
            
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        stopConfigBLE()
    }
    
    private func stopConfigBLE() {
        if !isSuccess {
            SVProgressHUD.dismiss()
        }

        ThingSmartBLEManager.sharedInstance().delegate = nil
        ThingSmartBLEManager.sharedInstance().stopListening(true)
    }
    
    private func initiateCurrentHome() {
        homeManager.getHomeList { (homeModels) in
            Home.current = homeModels?.first
        } failure: { (error) in
            
        }
    }
    
    @IBAction func addDevice(_ sender: Any) {
        ThingSmartBLEManager.sharedInstance().delegate = self
        // Start finding un-paired BLE devices.
        ThingSmartBLEManager.sharedInstance().startListening(true)
        SVProgressHUD.show(withStatus: NSLocalizedString("Searching", comment: ""))
        
        // Set a timer for 1 minute
        DispatchQueue.main.asyncAfter(deadline: .now() + 30.0) {
            SVProgressHUD.dismiss()
            ThingSmartBLEManager.sharedInstance().stopListening(true)
            AlertManager.showAlert(title: "No Devices Found", message: "Please try Searching again", viewController: self)
        }
    }
    
    @IBAction func settings(_ sender: Any) {
        let storyboard = UIStoryboard(name: "ThingSmartMain", bundle: nil)
        let vc = storyboard.instantiateInitialViewController()
        self.window?.rootViewController = vc
    }
}

extension ShuDtxViewController: ThingSmartBLEManagerDelegate {
    // When the BLE detector finds one un-paired BLE device, this delegate method will be called.
    func didDiscoveryDevice(withDeviceInfo deviceInfo: ThingBLEAdvModel) {
        guard let homeID = Home.current?.homeId else {
            SVProgressHUD.showError(withStatus: NSLocalizedString("No Home Selected", comment: ""))
            return
        }
        
        let bleType = deviceInfo.bleType
        if bleType == ThingSmartBLETypeBLEWifi ||
            bleType == ThingSmartBLETypeBLEWifiSecurity ||
            bleType == ThingSmartBLETypeBLEWifiPlugPlay ||
            bleType == ThingSmartBLETypeBLEWifiPriorBLE ||
            bleType == ThingSmartBLETypeBLELTESecurity {
            print("Please use Dual Mode to pair: %@", deviceInfo.uuid ?? "")
            return
        }
        
        SVProgressHUD.show(withStatus: NSLocalizedString("Activating", comment: "Active BLE."))
        
        // Trying to active the single BLE device.
        ThingSmartBLEManager.sharedInstance().activeBLE(deviceInfo, homeId: homeID) { model in
            let name = model.name ?? NSLocalizedString("Unknown Name", comment: "Unknown name device.")
            SVProgressHUD.showSuccess(withStatus: NSLocalizedString("Successfully Added \(name)", comment: "Successfully added one device."))
            self.isSuccess = true
            self.navigationController?.popViewController(animated: true)
            
        } failure: {
            SVProgressHUD.showError(withStatus: NSLocalizedString("Failed to Activate BLE Device", comment: ""))
        }
    }
}
