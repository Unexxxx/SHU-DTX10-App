//
//  DeviceDetailKitVC.swift
//  TuyaAppSDKSample-iOS-Swift
//
//  Copyright (c) 2014-2023 Tuya Inc. (https://developer.tuya.com/)

import UIKit

class DeviceDetailKitVC: DeviceListBaseVC {

    override func handle(index: Int) {
        let alert = UIAlertController(title: nil, message: nil, preferredStyle: .actionSheet)
        
        if (self.isGroup) {
            if (index >= home.groupList.count) {return}
            let group = self.home.groupList[index]

            alert.addAction(UIAlertAction(title: "Timer", style: .default, handler: { action in
                let vc = DeviceDetailKitTimerVC(bizId: group.groupId, isGroup: true)
                self.navigationController?.pushViewController(vc, animated: true)
            }))
            
            alert.addAction(UIAlertAction(title: "Edit Group", style: .default, handler: { action in
                self.editGroup(with: group)
            }))
            
            alert.addAction(UIAlertAction(title: "Delete Group", style: .default, handler: { action in
                self.deleteGroup(with: group)
            }))
            
                        
        }else{
            if (index >= home.deviceList.count) {return}
            let device = self.home.deviceList[index]
            
            alert.addAction(UIAlertAction(title: "Device Information", style: .default, handler: { action in
                let vc = DeviceDetailKitInfoVC(deviceId: device.devId)
                self.navigationController?.pushViewController(vc, animated: true)
            }))
            
            
            alert.addAction(UIAlertAction(title: "Timer.", style: .default, handler: { action in
                let vc = DeviceDetailKitTimerVC(bizId: device.devId, isGroup: false)
                self.navigationController?.pushViewController(vc, animated: true)
            }))
            
            alert.addAction(UIAlertAction(title: "Create Group", style: .default, handler: { action in
                self.createGroup(with: device)
            }))
            
        }
        
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        self.present(alert, animated: true)
    }
    
    
    var service: ThingGroupServiceProtocol?
    func createGroup(with device: ThingSmartDeviceModel) {
        //Query group type based on device ID.
        let groupType = ThingGroupMakerHelper.groupBizType(fromDeviceId: device.devId)

        //Build parameters based on group type.
        var params: [AnyHashable: AnyObject] = [:]
        params["devId"] = device.devId! as AnyObject

        if (groupType == .bleMesh || groupType == .sigMesh || groupType == .beacon) {
            let impl = ThingModule.service(ofOptionalProtocol: ThingBusinessGroupProtocol.self) as? ThingBusinessGroupProtocol
            let deviceList = impl?.deviceListForCurrentSpace() ?? []
            params["deviceList"] = deviceList as AnyObject
        }


        // Create Service
        self.service = ThingGroupServiceMaker.groupServiceMaker(withBuildQuery: params)
        
        
        SVProgressHUD.show()
        //Retrieve a list of devices that meet the criteria under the group.
        self.service?.fetchDeviceList?(success: { list in
            
            guard let listIds = list?.compactMap({ return $0.devId }) else {
                SVProgressHUD.dismiss()
                return
            }
            
            self.service?.createGroup?(withName: "My group Name", deviceList: listIds, process: { process in
                
            }, success: { groupId in
                SVProgressHUD.dismiss()
                return
            }, failure: { e in
                SVProgressHUD.dismiss()
                return
            })
            
        }, failure: { e in
            SVProgressHUD.dismiss()
            return
        })
    }
    
    
    func editGroup(with group: ThingSmartGroupModel) {
        //Query group type based on group ID.
        let groupType = ThingGroupMakerHelper.groupBizType(fromDeviceId: group.groupId)

        //Build parameters according to group type.
        var params: [AnyHashable: AnyObject] = [:]
        params["groupId"] = group.groupId! as AnyObject

        if (groupType == .bleMesh || groupType == .sigMesh || groupType == .beacon) {
            let impl = ThingModule.service(ofOptionalProtocol: ThingBusinessGroupProtocol.self) as? ThingBusinessGroupProtocol
            let deviceList = impl?.deviceListForCurrentSpace() ?? []
            params["deviceList"] = deviceList as AnyObject
        }
        
        
        // Create service
        self.service = ThingGroupServiceMaker.groupServiceMaker(withBuildQuery: params)
        
        SVProgressHUD.show()
        //Retrieve a list of devices that meet the criteria under the group.
        self.service?.fetchDeviceList?(success: { list in
            
            guard let listIds = list?.compactMap({ return $0.devId }) else {
                SVProgressHUD.dismiss()
                return
            }
            
            
            //Update group devices
            self.service?.updateGroup?(withDeviceList: listIds, process: { process in
                
            }, success: { groupId in
                SVProgressHUD.dismiss()
                return
            }, failure: { e in
                SVProgressHUD.dismiss()
                return
            })
            
        }, failure: { e in
            SVProgressHUD.dismiss()
            return
        })
    }
    
    
    func deleteGroup(with group: ThingSmartGroupModel) {
        //Query group type based on group ID.
        let groupType = ThingGroupMakerHelper.groupBizType(fromDeviceId: group.groupId)

        //Build parameters based on group type.
        var params: [AnyHashable: AnyObject] = [:]
        params["groupId"] = group.groupId! as AnyObject

        if (groupType == .bleMesh || groupType == .sigMesh || groupType == .beacon) {
            let impl = ThingModule.service(ofOptionalProtocol: ThingBusinessGroupProtocol.self) as? ThingBusinessGroupProtocol
            let deviceList = impl?.deviceListForCurrentSpace() ?? []
            params["deviceList"] = deviceList as AnyObject
        }
        
        
        // Create Service.
        self.service = ThingGroupServiceMaker.groupServiceMaker(withBuildQuery: params)
        
        SVProgressHUD.show()
        self.service?.removeGroup?(withGroupId: group.groupId, success: {
            SVProgressHUD.dismiss()
            self.tableView.reloadData()
            return
        }, failure: { e in
            SVProgressHUD.dismiss()
            return
        })
    }
    
}
