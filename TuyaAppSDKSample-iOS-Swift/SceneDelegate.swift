//
//  SceneDelegate.swift
//  ThingAppSDKSample-iOS-Swift
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.tuya.com/)

import UIKit
import ThingSmartBaseKit

@available(iOS 13.0, *)
class SceneDelegate: UIResponder, UIWindowSceneDelegate {

    var window: UIWindow?

    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {
        // Use this method to optionally configure and attach the UIWindow `window` to the provided UIWindowScene `scene`.
        // If using a storyboard, the `window` property will automatically be initialized and attached to the scene.
        // This delegate does not imply the connecting scene or session are new (see `application:configurationForConnectingSceneSession` instead).
//        guard let _ = (scene as? UIWindowScene) else { return }
        
        if let url = connectionOptions.urlContexts.first?.url {
            handle(url)
        }
        
        if let windowScene = scene as? UIWindowScene {
            self.window = UIWindow(windowScene: windowScene)
            
            if ThingSmartUser.sharedInstance().isLogin {
                // User has already logged, launch the app with the main view controller.
                let storyboard = UIStoryboard(name: "ShuDtxMain", bundle: nil)
                let vc = storyboard.instantiateInitialViewController()
                window?.rootViewController = vc
                window?.makeKeyAndVisible()
            } else {
                // There's no user logged, launch the app with the login and register view controller.
                let storyboard = UIStoryboard(name: "Main", bundle: nil)
                let vc = storyboard.instantiateInitialViewController()
                window?.rootViewController = vc
                window?.makeKeyAndVisible()
            }
        }
    }
    
    func sceneDidBecomeActive(_ scene: UIScene) {
        if let navigationController = window?.rootViewController as? UINavigationController {
            if let currentHome = Home.current, let home = ThingSmartHome(homeId: currentHome.homeId), let deviceModel = home.deviceList.first {
                let viewModel = CardCellViewModel()
                viewModel.dpParser = ThingSmartDpParser.create(withTargetInfo: deviceModel)
                viewModel.device = ThingSmartDevice(deviceId: deviceModel.devId)
                viewModel.name = deviceModel.name
                viewModel.icon = deviceModel.iconUrl
                jumpDeviceDetail(viewModel: viewModel, smartDp: nil, controller: navigationController)
            }
        }
    }
    
    // this gets called when you called the app via deep, this is where we get the schemeparameters
    func scene(_ scene: UIScene, openURLContexts URLContexts: Set<UIOpenURLContext>) {
        guard let url = URLContexts.first?.url else {
            return
        }
        
        handle(url)
    }
    
    func handleURL(_ url: URL) {
        let urlString = url.absoluteString
        let components = urlString.components(separatedBy: "://")
        if components.count > 1 {
            let parameter = components[1]
            UserDefaults.standard.setValue(parameter, forKey: "schemeParameter")
            UserDefaults.standard.synchronize()
        }
    }
    
    func handle(_ url: URL) {
        guard let components = URLComponents(url: url, resolvingAgainstBaseURL: true),
              let queryItems = components.queryItems else {
            return
        }
        
        var urlParams = ""
        for item in queryItems {
            if item.name == "fileName" {
                UserDefaults.standard.setValue(item.value, forKey: "fileName")
            } else {
                print("\(item.name) = \(item.value ?? "")")
                urlParams.append("$\(item.name)=\(item.value ?? "")")
            }
        }
        UserDefaults.standard.setValue(urlParams, forKey: "schemeParameter")
        NotificationCenter.default.post(name: .reconnectDevice, object: nil)
    }
    
    private func jumpDeviceDetail(viewModel: CardCellViewModel, smartDp: ThingSmartDp?, controller: UINavigationController) {
        guard let device = viewModel.device else { return }
        
        let storyboard = UIStoryboard(name: "ShuDtxMain", bundle: nil)
        let isSupportThingModel = device.deviceModel.isSupportThingModelDevice()
        let identifier = isSupportThingModel ? "ThingLinkDeviceControlController" : "DeviceControlViewController"
        
        let vc = storyboard.instantiateViewController(withIdentifier: identifier)
        if isSupportThingModel {
            let thingLinkVC = vc as! ThingLinkDeviceControlController
            jumpThingLinkDeviceControl(thingLinkVC, device: device, controller: controller)
        } else {
            if let deviceControlVC = vc as? DeviceControlViewController {
                deviceControlVC.targetSchemaModel = smartDp?.schemaModel
                jumpNormalDeviceControl(deviceControlVC, device: device, controller: controller)
            }
        }
    }
    
    private func jumpNormalDeviceControl(_ vc: DeviceControlViewController, device: ThingSmartDevice, controller: UINavigationController) {
        if !(controller.topViewController is DeviceControlViewController) {
            vc.device = device
            controller.pushViewController(vc, animated: true)
        }
    }
    
    private func jumpThingLinkDeviceControl(_ vc: ThingLinkDeviceControlController, device: ThingSmartDevice, controller: UINavigationController) {
        let goThingLinkControl = { () -> Void in
            if !(controller.topViewController is ThingLinkDeviceControlController) {
                vc.device = device
                controller.pushViewController(vc, animated: true)
            }
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
}

