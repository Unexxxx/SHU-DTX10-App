//
//  ViewController.swift
//  SHU DTX10
//
//  Created by Kent Onyx Arintok on 10/7/23.
//

import UIKit
import CoreBluetooth

class ViewController: UIViewController {
    
    @IBOutlet var bluetoothOn: UIImageView!
    @IBOutlet var bluetoothOff: UIImageView!
    @IBOutlet var bluetoothConnected: UILabel!
    @IBOutlet var bluetoothDisconnected: UILabel!
    @IBOutlet var measureDeviceLabel: UILabel!
    
    @IBOutlet var exitButton: UIImageView!
    @IBOutlet var settingsButton: UIImageView!
    
    
    var centralManager: CBCentralManager!
    var connectedPeripheral: CBPeripheral?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
//        // Initialize the central manager and set yourself as the delegate
//        centralManager = CBCentralManager(delegate: self, queue: nil)
        
        // Initially, hide the bluetoothOn and bluetoothConnected views
        bluetoothOn.alpha = 0
        bluetoothConnected.alpha = 0
        measureDeviceLabel.alpha = 0
        
        // Delay execution for 10 seconds
        DispatchQueue.main.asyncAfter(deadline: .now() + 3) {
            // Animate the fade-out of bluetoothOff and bluetoothDisconnected
            UIView.animate(withDuration: 1.0, animations: {
                self.bluetoothOff.alpha = 0
                self.bluetoothDisconnected.alpha = 0
            }) { _ in
                // After the fade-out animation completes, show bluetoothOn and bluetoothConnected
                UIView.animate(withDuration: 1.0) {
                    self.bluetoothOn.alpha = 1
                    self.bluetoothConnected.alpha = 1
                    self.measureDeviceLabel.alpha = 1
                }
            }
        }
        
        // Add a tap gesture recognizer to the exit button
        let exitButtonGesture = UITapGestureRecognizer(target: self, action: #selector(showExitConfirmationAlert))
        exitButton.addGestureRecognizer(exitButtonGesture)
        exitButton.isUserInteractionEnabled = true
        
        // Add a tap gesture recognizer to the settings button
        let settingsButtonGesture = UITapGestureRecognizer(target: self, action: #selector(showURLSchemeAlert))
        settingsButton.addGestureRecognizer(settingsButtonGesture)
        settingsButton.isUserInteractionEnabled = true
    }
    
    // Function to display the UIAlertController
    @objc func showExitConfirmationAlert() {
        let alertController = UIAlertController(title: "Are you sure you want to close the app?",message: nil, preferredStyle: .alert)
        
        let yesAction = UIAlertAction(title: "Yes", style: .destructive) { _ in
            // Close the app
            UIControl().sendAction(#selector(NSXPCConnection.suspend), to: UIApplication.shared, for: nil)
        }
        
        let noAction = UIAlertAction(title: "No", style: .cancel, handler: nil)
        
        alertController.addAction(yesAction)
        alertController.addAction(noAction)
        
        self.present(alertController, animated: true, completion: nil)
    }
    
    @objc func showURLSchemeAlert() {
        let alertController = UIAlertController(title: "Edit URL Scheme", message: nil, preferredStyle: .alert)
        
        alertController.addTextField { textField in
            textField.placeholder = "Enter URL Scheme"
        }
        
        let cancelAction = UIAlertAction(title: "Cancel", style: .cancel, handler: nil)
        
        let saveAction = UIAlertAction(title: "Save", style: .default) { [weak self] _ in
            // Handle the Save button action here
            if let textField = alertController.textFields?.first, let urlScheme = textField.text {
                // Use the entered URL Scheme as needed
                print("Entered URL Scheme: \(urlScheme)")
            }
        }
        
        alertController.addAction(cancelAction)
        alertController.addAction(saveAction)
        
        self.present(alertController, animated: true, completion: nil)
    }
}

//extension ViewController: CBCentralManagerDelegate {
//    
//    func centralManagerDidUpdateState(_ central: CBCentralManager) {
//        switch central.state {
//        case .poweredOn:
//            // Start scanning for peripherals when Bluetooth is powered on
//            central.scanForPeripherals(withServices: nil, options: nil)
//        default:
//            // Hide the connected view and show the disconnected view when Bluetooth is off
//            bluetoothOn.isHidden = true
//            bluetoothConnected.isHidden = true
//            bluetoothOff.isHidden = false
//            bluetoothDisconnected.isHidden = false
//        }
//    }
//    
//    func centralManager(_ central: CBCentralManager, didDiscover peripheral: CBPeripheral,
//                        advertisementData: [String: Any], rssi RSSI: NSNumber) {
//        // You can check if the discovered peripheral matches your criteria and then connect to it
//        // For example, you can check the peripheral's name or services
//        // If the connection is successful, update the UI accordingly
//        
//        if peripheral.name == "YourBluetoothDeviceName" {
//            central.connect(peripheral, options: nil)
//        }
//    }
//    
//    func centralManager(_ central: CBCentralManager, didConnect peripheral: CBPeripheral) {
//        // Update the UI when a Bluetooth device is connected
//        bluetoothOn.isHidden = false
//        bluetoothConnected.isHidden = false
//        bluetoothOff.isHidden = true
//        bluetoothDisconnected.isHidden = true
//        
//        // Store the connected peripheral
//        connectedPeripheral = peripheral
//    }
//    
//    func centralManager(_ central: CBCentralManager, didDisconnectPeripheral peripheral: CBPeripheral, error: Error?) {
//        // Update the UI when a Bluetooth device is disconnected
//        bluetoothOn.isHidden = true
//        bluetoothConnected.isHidden = true
//        bluetoothOff.isHidden = false
//        bluetoothDisconnected.isHidden = false
//        
//        // Clear the connected peripheral
//        connectedPeripheral = nil
//    }
//}


