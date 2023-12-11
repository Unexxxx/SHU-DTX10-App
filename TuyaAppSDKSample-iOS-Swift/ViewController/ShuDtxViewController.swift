//


import UIKit
import ThingSmartBLEKit
import ThingSmartFamilyBizKit
import ThingSmartDeviceKit
import ThingSmartDeviceCoreKit

@available(iOS 13.0, *)
class ShuDtxViewController: UIViewController {

    private var isSuccess = false
    let homeManager = ThingSmartHomeManager()
    
    override func viewDidLoad() {
        navigationItem.title = "DTX10 App"
        
        let gearIcon = UIImage(systemName: "gear")
        let gearButton = UIBarButtonItem(image: gearIcon, style: .plain, target: self, action: #selector(settingsButtonTapped))
        navigationItem.leftBarButtonItem = gearButton
        
        let addDeviceButton = UIBarButtonItem(title: "Add Device", style: .plain, target: self, action: #selector(addDeviceButtonTapped))
        navigationItem.rightBarButtonItem = addDeviceButton
        
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
    
    @objc func settingsButtonTapped() {
        let storyboard = UIStoryboard(name: "ThingSmartMain", bundle: nil)
        let vc = storyboard.instantiateInitialViewController()
        self.window?.rootViewController = vc
    }
    
    @objc func addDeviceButtonTapped() {
        ThingSmartBLEManager.sharedInstance().delegate = self
        // Start finding un-paired BLE devices.
        ThingSmartBLEManager.sharedInstance().startListening(true)
        SVProgressHUD.show(withStatus: NSLocalizedString("Searching", comment: ""))
        
        // Set a timer for 20secs
        DispatchQueue.main.asyncAfter(deadline: .now() + 20.0) {
            SVProgressHUD.dismiss()
        }
    }
}

@available(iOS 13.0, *)
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
