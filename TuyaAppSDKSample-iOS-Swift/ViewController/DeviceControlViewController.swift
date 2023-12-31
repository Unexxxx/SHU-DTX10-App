//
//  DeviceControlTableViewController.swift
//  ThingAppSDKSample-iOS-Swift
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.tuya.com/)

import UIKit
import NotificationCenter
import ThingSmartDeviceKit

@available(iOS 13.0, *)
class DeviceControlViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {

    // MARK: - Property
    var device: ThingSmartDevice?
    var targetSchemaModel : ThingSmartSchemaModel? //View specific Data Point
    @IBOutlet var tableView: UITableView!
    @IBOutlet var viewDistance: UIView!
    @IBOutlet var distanceMeter: UITextField!
    @IBOutlet var deviceOffline: UILabel!
    var metersValue = 0.0 {
        didSet {
            guard let savedURLScheme = UserDefaults.standard.string(forKey: "urlScheme") else {
                     showAlert(message: "URL Scheme not set.")
                     return
                  }
                  
                  let updatedURLScheme = savedURLScheme.replacingOccurrences(of: "<<VALUE>>", with: "\(metersValue)")
                  
                  if let url = URL(string: updatedURLScheme) {
                     UIApplication.shared.open(url, options: [:], completionHandler: nil)
                  } else {
                     showAlert(message: "Something's wrong with the URL Scheme.")
                  }
        }
    }
    
    
    // MARK: - Lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        tableView.delegate = self
        tableView.dataSource = self
        distanceMeter.delegate = self
        tableView.register(SwitchTableViewCell.self, forCellReuseIdentifier: "SwitchCell")
        view.addSubview(tableView)
        device?.delegate = self
        NotificationCenter.default.addObserver(self, selector: #selector(deviceHasRemoved(_:)), name: .SVProgressHUDDidDisappear, object: nil)
        
        
        let gearIcon = UIImage(systemName: "gear")
        let gearButton = UIBarButtonItem(image: gearIcon, style: .plain, target: self, action: #selector(urlSchemeTapped))
        navigationItem.rightBarButtonItem = gearButton
        
        viewDistance.layer.cornerRadius = 15
        viewDistance.layer.masksToBounds = true
        viewDistance.alpha = 1
        
        distanceMeter.borderStyle = .none
        distanceMeter.background = nil
        distanceMeter.backgroundColor = UIColor.clear
        distanceMeter.isEnabled = true
        distanceMeter.font = UIFont.systemFont(ofSize: 50)
        distanceMeter.adjustsFontSizeToFitWidth = false
        
        let toolbar = UIToolbar()
        toolbar.sizeToFit()
        
        let flexibleSpace = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        let doneButton = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(doneButtonTapped))
        toolbar.items = [flexibleSpace, doneButton]
        distanceMeter.inputAccessoryView = toolbar
        
        detectDeviceAvailability()
        
        tableView.addObserver(self, forKeyPath: "reloadData", options: .new, context: nil)

    }
    
    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {

        if keyPath == "reloadData" {
            distanceMeter.text = updateDistanceMeter(with: metersValue)
        }
    }
    
    func updateDistanceMeter(with value: Double) -> String {

        let formattedDistance = String(format: "%.3f", value)
        return formattedDistance

    }

    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        SVProgressHUD.dismiss()
        NotificationCenter.default.removeObserver(self, name: .SVProgressHUDDidDisappear, object: nil)
    }
    
    
    // MARK: -  Private Method
    
    private func detectDeviceAvailability() {
        if let isOnline = device?.deviceModel.isOnline, isOnline {
            NotificationCenter.default.post(name: .deviceOnline, object: nil)
//            SVProgressHUD.dismiss()
            deviceOffline.isHidden = true
            
        } else {
            NotificationCenter.default.post(name: .deviceOffline, object: nil)
//            SVProgressHUD.show(withStatus: NSLocalizedString("The device is offline. The control panel is unavailable.", comment: ""))
            deviceOffline.isHidden = false
        }
    }
    
    private func publishMessage(with dps: NSDictionary) {
        guard let dps = dps as? [AnyHashable : Any] else { return }

        device?.publishDps(dps, success: {

        }, failure: { (error) in
            let errorMessage = error?.localizedDescription ?? ""
            SVProgressHUD.showError(withStatus: errorMessage)
        })
    }
    @IBAction func removeDeviceTapped(_ sender: UIButton) {
        let removeAction = UIAlertAction(title: NSLocalizedString("Remove", comment: "Perform remove device action"), style: .destructive) { [weak self] (action) in
            guard let self = self else { return }
            self.device?.remove({
                // Clear UserDefaults
                UserDefaults.standard.removePersistentDomain(forName: Bundle.main.bundleIdentifier!)
                UserDefaults.standard.synchronize()
                
                guard let vc = self.navigationController?.viewControllers[(self.navigationController?.viewControllers.count)! - 2] else { return }
                self.navigationController?.popToViewController(vc, animated: true)
            }, failure: { (error) in
                let errorMessage = error?.localizedDescription ?? ""
                Alert.showBasicAlert(on: self, with: NSLocalizedString("Failed to Remove", comment: "Failed to remove the device"), message: errorMessage)
            })
        }
        
        let cancelAction = UIAlertAction(title: NSLocalizedString("Cancel", comment: ""), style: .cancel)
        
        let alert = UIAlertController(title: NSLocalizedString("Remove the Device?", comment: ""), message: NSLocalizedString("If you choose to remove the device, you'll no long hold control over this device.", comment: ""), preferredStyle: .actionSheet)
        alert.addAction(removeAction)
        alert.addAction(cancelAction)
        
        alert.popoverPresentationController?.sourceView = sender
        
        self.present(alert, animated: true, completion: nil)
    }
    
    @IBAction func sendButton(_ sender: Any) {
//        // Retrieve the URL scheme from UserDefaults
//            guard let savedURLScheme = UserDefaults.standard.string(forKey: "urlScheme") else {
//                // Handle the case where the URL scheme is not available
//                showAlert(message: "URL Scheme not set. Please set a URL Scheme in the settings.")
//                return
//            }
//        
//        let updatedURLScheme = savedURLScheme.replacingOccurrences(of: "<<VALUE>>", with: "\(metersValue)")
//        
//        // Create a URL using the scheme
//        if let url = URL(string: "\(updatedURLScheme)") {
//            // Open the app corresponding to the URL scheme
//            UIApplication.shared.open(url, options: [:], completionHandler: nil)
//        } else {
//            // Handle the case where the app cannot be opened
//            showAlert(message: "Something's wrong with the URL Scheme.")
//        }
    }
    
    func showAlert(message: String) {
        let alertController = UIAlertController(title: "Error", message: message, preferredStyle: .alert)
        let okAction = UIAlertAction(title: "OK", style: .default, handler: nil)
        alertController.addAction(okAction)
        present(alertController, animated: true, completion: nil)
    }

    
    @objc func urlSchemeTapped() {
        let alertController = UIAlertController(title: "Edit URL Scheme", message: nil, preferredStyle: .alert)
        
        alertController.addTextField { textField in
            textField.placeholder = "Enter URL Scheme"
            
            UserDefaults.standard.synchronize()
            if let savedURLScheme = UserDefaults.standard.string(forKey: "urlScheme") {
                textField.text = savedURLScheme
            }
        }
        
        let cancelAction = UIAlertAction(title: "Cancel", style: .cancel, handler: nil)
        
        let saveAction = UIAlertAction(title: "Save", style: .default) { _ in
            // Handle the Save button action here
            if let textField = alertController.textFields?.first, let urlScheme = textField.text {
                // Use the entered URL Scheme as needed
                print("Entered URL Scheme: \(urlScheme)")
                
                UserDefaults.standard.set(urlScheme, forKey: "urlScheme")
            }
        }
        
        alertController.addAction(cancelAction)
        alertController.addAction(saveAction)
        
        self.present(alertController, animated: true, completion: nil)
    }
    
    
    @objc private func deviceHasRemoved(_ notification: Notification) {
        guard let key = notification.userInfo?[SVProgressHUDStatusUserInfoKey] as? String,
              key.contains("removed")
        else { return }
        navigationController?.popViewController(animated: true)
    }
    
    @objc func doneButtonTapped() {
        distanceMeter.resignFirstResponder()
    }
    
    // MARK: - Table view data source

    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if (targetSchemaModel != nil) {
            return 1
        }
        return device?.deviceModel.schemaArray?.count ?? 0
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let defaultCell = UITableViewCell(style: .default, reuseIdentifier: nil)
        guard let device = device else { return defaultCell }

        let schema = targetSchemaModel != nil ? targetSchemaModel! : device.deviceModel.schemaArray[indexPath.row]
        let dps = device.deviceModel.dps
        var isReadOnly = false
        let cellIdentifier = DeviceControlCell.cellIdentifier(with: schema)
        guard let cell = tableView.dequeueReusableCell(withIdentifier: cellIdentifier.rawValue) else {
            return defaultCell
        }
        
        if let mode = schema.mode {
            isReadOnly = mode == "ro"
        }
        
        switch cellIdentifier {
        case .switchCell:
            guard let cell = cell as? SwitchTableViewCell,
                  let dps = dps,
                  let dpID = schema.dpId,
                  let isOn = dps[dpID] as? Bool
            else { break }
            
            cell.label.text = "Remote Measurement"/*schema.name*/
            cell.switchButton.isOn = isOn
            cell.isReadOnly = isReadOnly
            
            cell.switchAction = { [weak self] switchButton in
                guard let self = self,
                      let dpID = schema.dpId
                else { return }
                
                self.publishMessage(with: [dpID : switchButton.isOn])
            }
            
        case .sliderCell:
            guard let cell = cell as? SliderTableViewCell,
                  let dps = dps,
                  let dpID = schema.dpId,
                  let value = dps[dpID] as? Int
            else { break }
            
            metersValue = Double(value) / 1000.0
            
            cell.label.text = schema.name
            cell.label.text = "Current Distance"
            cell.detailLabel.text = String(format: "%.3f", metersValue)
            distanceMeter.text = updateDistanceMeter(with: metersValue)
            cell.slider.minimumValue = Float(schema.property.min)
            cell.slider.maximumValue = Float(schema.property.max)
            cell.slider.isContinuous = false
            cell.slider.value = Float(value)
            cell.isReadOnly = isReadOnly
            
            cell.sliderAction = { [weak self] slider in
                guard let self = self,
                      let dpID = schema.dpId
                else { return }
                
                let step = Float(schema.property.step)
                let roundedValue = round(slider.value / step) * step
                self.publishMessage(with: [dpID : Int(roundedValue)])
            }
            
        case .enumCell:
            guard let cell = cell as? EnumTableViewCell,
                  let dps = dps,
                  let dpID = schema.dpId,
                  let option = dps[dpID] as? String,
                  let range = schema.property.range as? [String]
            else { break }
            
            cell.label.text = "Unit of measure"
            cell.optionArray = range
            cell.currentOption = option
            cell.isReadOnly = isReadOnly
            
            cell.selectAction = { [weak self] option in
                guard let self = self else { return }
                self.publishMessage(with: [dpID : option])
            }
            
        case .stringCell:
            guard let cell = cell as? StringTableViewCell,
                  let dps = dps,
                  let dpID = schema.dpId
            else { break }
            
            let value = dps[dpID] ?? ""
            var text = ""
            
            ((value as? Int) != nil) ? (text = String(value as! Int)) : (text = value as? String ?? "")
            
            cell.label.text = "Area Data"/*schema.name*/
            cell.textField.text = text
            cell.isReadOnly = isReadOnly
            
            cell.buttonAction = { [weak self] text in
                guard let self = self else { return }
                self.publishMessage(with: [dpID : text])
            }
            
        case .labelCell:
            guard let cell = cell as? LabelTableViewCell,
                  let dps = dps,
                  let dpID = schema.dpId,
                  let value = dps[dpID]
            else { break }
            
            var text = ""
            
            ((value as? Int) != nil) ? (text = String(value as! Int)) : (text = value as? String ?? "")
            
            cell.label.text = schema.name
            cell.detailLabel.text = text
            
        case .textviewCell:
            guard let cell = cell as? TextViewTableViewCell,
                  let dps = dps,
                  let dpID = schema.dpId,
                  let value = dps[dpID]
            else { break }
            
            cell.title.text = schema.name
            cell.textview.text = ""
            if let data = try? JSONSerialization.data(withJSONObject: value, options: []) as Data,
               let s = String.init(data: data, encoding: .utf8) {
                cell.textview.text = s
            }
        }
        
        return cell
    }

    
}

@available(iOS 13.0, *)
extension DeviceControlViewController: ThingSmartDeviceDelegate {
    func deviceInfoUpdate(_ device: ThingSmartDevice) {
        detectDeviceAvailability()
        tableView.reloadData()
    }
    
    func deviceRemoved(_ device: ThingSmartDevice) {
        NotificationCenter.default.post(name: .deviceOffline, object: nil)
        SVProgressHUD.showError(withStatus: NSLocalizedString("The device has been removed.", comment: ""))
    }
    
    func device(_ device: ThingSmartDevice, dpsUpdate dps: [AnyHashable : Any]) {
        detectDeviceAvailability()
        tableView.reloadData()
    }
}

@available(iOS 13.0, *)
extension DeviceControlViewController: UITextFieldDelegate {
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        
        let currentText = textField.text ?? ""
        let newText = (currentText as NSString).replacingCharacters(in: range, with: string)
    
        if textField == distanceMeter {
            // Update distanceMeter when the user types a new character
            if let currentText = textField.text, let range = Range(range, in: currentText) {
                let updatedText = currentText.replacingCharacters(in: range, with: string)
                
                // You can update distanceMeter or perform any other actions with updatedText
            }
        }
        return newText.count <= 10
    }
}
