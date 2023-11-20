//
//  ThingSmartFamilyBiz.h
//  ThingSmartFamilyBizKit
//
//  Created by Thing on 2019/2/18.
//

#import <Foundation/Foundation.h>
#import "ThingSmartFamilyCityModel.h"
#import "ThingSmartFamilyRequestModel.h"
#import "ThingSmartFamilyDeviceGroupOrderRequestModel.h"

#import <ThingSmartDeviceKit/ThingSmartHome.h>
#import <ThingSmartDeviceKit/ThingSmartHomeModel.h>
#import <ThingSmartDeviceKit/ThingSmartHomeModelUtils.h>
#import <ThingSmartDeviceKit/ThingSmartHomeMemberModel.h>
#import <ThingSmartDeviceKit/ThingSmartHomeAddMemberRequestModel.h>
#import <ThingSmartDeviceKit/ThingSmartWeatherSketchModel.h>
#import <ThingSmartDeviceKit/ThingSmartWeatherOptionModel.h>
#import <ThingSmartDeviceKit/ThingSmartWeatherModel.h>
#import <ThingSmartUtil/ThingSmartUtil.h>


@class ThingSmartFamilyBiz;
@protocol ThingSmartFamilyBizDelegate <NSObject>

@optional

/**
 * MQTT service connection success callback
 */
- (void)serviceConnectedSuccess;

/**
 *  The delegate that is instantiated when a home is added.
 *
 *  @param familyBiz    Instance of family management
 *  @param homeModel    The home model
 */
- (void)familyBiz:(ThingSmartFamilyBiz *)familyBiz didAddHome:(ThingSmartHomeModel *)homeModel;

/**
 *  The delegate that is instantiated when an existing home is removed.
 *
 *  @param familyBiz    Instance of family management
 *  @param homeModel    The home model
 */
- (void)familyBiz:(ThingSmartFamilyBiz *)familyBiz didRemoveHome:(ThingSmartHomeModel *)homeModel;

/**
 *  The delegate of home update information, such as the name.
 *
 *  @param familyBiz    Instance of family management
 *  @param homeModel    The home model.
 */
- (void)familyBiz:(ThingSmartFamilyBiz *)familyBiz didUpdateHome:(ThingSmartHomeModel *)homeModel;

/**
 *  The delegate of switching the current home
 *
 *  @param familyBiz    Instance of family management
 *  @param homeModel    The home model
 */
- (void)familyBiz:(ThingSmartFamilyBiz *)familyBiz didChangeCurrentHome:(ThingSmartHomeModel *)homeModel;

/**
 *  The delegate that is instantiated when a new device is added.
 *
 *  @param familyBiz            Instance of family management
 *  @param deviceModel       The device model
 *  @param homeModel            The home model
 */
- (void)familyBiz:(ThingSmartFamilyBiz *)familyBiz didAddDevice:(ThingSmartDeviceModel *)deviceModel atHome:(ThingSmartHomeModel *)homeModel;

/**
 *  The delegate that is instantiated when an existing device is removed.
 *
 *  @param familyBiz        Instance of family management
 *  @param deviceId          Deleted Device ID
 *  @param homeModel        The home model
 */
- (void)familyBiz:(ThingSmartFamilyBiz *)familyBiz
  didRemoveDevice:(NSString *)deviceId
           atHome:(ThingSmartHomeModel *)homeModel;

/**
 *  The delegate that is instantiated when a new group is added.
 *
 *  @param familyBiz         Instance of family management
 *  @param groupModel       The group model
 *  @param homeModel         The home model
 */
- (void)familyBiz:(ThingSmartFamilyBiz *)familyBiz
      didAddGroup:(ThingSmartGroupModel *)groupModel
           atHome:(ThingSmartHomeModel *)homeModel;

/**
 *  The delegate that is instantiated when an existing group is removed.
 *
 *  @param familyBiz        Instance of family management
 *  @param groupId            Deleted group ID
 *  @param homeModel        The home model
 */
- (void)familyBiz:(ThingSmartFamilyBiz *)familyBiz
   didRemoveGroup:(NSString *)groupId
           atHome:(ThingSmartHomeModel *)homeModel;

/**
 *  The delegate of updates on the shared device list.
 *
 *  @param familyBiz        Instance of family management
 *  @param homeModel        The home model
 */
- (void)familyBiz:(ThingSmartFamilyBiz *)familyBiz
   didUpdateSharedListAtHome:(ThingSmartHomeModel *)homeModel;

@end

@interface ThingSmartFamilyBiz : NSObject

+ (instancetype)sharedInstance;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

#pragma mark - Listener

/**
 *  Adding a Listener
 *
 *  @param observer     Implementation ThingSmartFamilyBizDelegate  protocol
 */
- (void)addObserver:(id<ThingSmartFamilyBizDelegate>)observer;

/**
 *  Removing a Listener
 *
 *  @param observer     Implementation ThingSmartFamilyBizDelegate  protocol
 */
- (void)removeObserver:(id<ThingSmartFamilyBizDelegate>)observer;

#pragma mark - Current Family

/**
 *  Get current family ID
 *
 *  @return homeId
 */
- (long long)getCurrentFamilyId;

/**
 *  Get the current family model
 *
 *  @return homeModel of current family
 */
- (ThingSmartHomeModel *)getCurrentFamily;

/**
 *  Update the current family ID and cache to local
 *
 *  @param homeId   Current Family ID
 */
- (void)setCurrentFamilyId:(long long)homeId;

/**
 *  Load Current Family ID
 *
 *  @param appGroupName Set the appGroupName of the ThingCustomConfig
 *  @discussion When the app is launched,  call thie method to load the last recorded current family ID
 */
- (void)launchCurrentFamilyWithAppGroupName:(NSString  * _Nullable )appGroupName;

/**
 *  Empty the current family cache
 */
- (void)clearCurrentFamily;

#pragma mark - Family Management

/**
 * Get a cached list of families
 *
 * @return Array of homeModel
 * @discussion Cached family data is only available after calling [ThingSmartFamilyBiz getFamilyListWithSuccess:failure:]
 */
- (NSArray <ThingSmartHomeModel *>*)getCachedHomes;

/**
 *  Get a rough list of family information
 *
 *  @param success      Success callback
 *  @param failure      Failure callback
 */
- (void)getFamilyListWithSuccess:(void(^)(NSArray<ThingSmartHomeModel *> * homes))success
                         failure:(ThingFailureError)failure;

/**
 *  Get family details
 *
 *  @param homeId       Family ID
 *  @param success     Success callback
 *  @param failure     Failure callback
 */
- (void)getFamilyDetailWithHomeId:(long long)homeId
                          success:(void(^)(ThingSmartHome *home))success
                          failure:(ThingFailureError)failure;



/**
 *  Creating a Default Family
 *  @param name             Family name
 *  @param success      Success callback
 *  @param failure      Failure callback
 */
- (void)createDefaultFamilyWithName:(NSString *)name
                            success:(void(^)(long long homeId))success
                            failure:(ThingFailureError)failure;

/**
 *  Add Family
 *
 *  @param model           Request Model of  Adding a Family
 *  @param success      Success callback
 *  @param failure      Failure callback
 */

- (void)addFamilyWithModel:(ThingSmartFamilyRequestModel *)model
                   success:(void(^)(long long homeId))success
                   failure:(ThingFailureError)failure;

/**
 *  Delete family
 *
 *  @param homeId          Family ID
 *  @param success        Success callback
 *  @param failure        Failure callback
 */
- (void)deleteFamilyWithHomeId:(long long)homeId
                       success:(ThingSuccessHandler)success
                       failure:(ThingFailureError)failure;
                

/**
 *  Update family information
 *
 *  @param homeId           Family ID
 *  @param model             Family model
 *  @param success        Success callback
 *  @param failure        Failure callback
 */
- (void)updateFamilyWithHomeId:(long long)homeId
                         model:(ThingSmartFamilyRequestModel *)model
                       success:(ThingSuccessHandler)success
                       failure:(ThingFailureError)failure;

/**
 *  Get information about the city where your family lives
 *
 *  @param latitude       Latitude where the family is located
 *  @param longitude     Longitude where the family is located
 *  @param success         Success callback
 *  @param failure         Failure callback
 */
- (void)getCityInfo:(double)latitude
          longitude:(double)longitude
            success:(void(^)(ThingSmartFamilyCityModel *cityModel))success
            failure:(ThingFailureError)failure;


/**
 *  Members leaving the family
 *
 *  @param homeId            Family ID
 *  @param memberId       ID of the member to be removed
 *  @param success         Success callback
 *  @param failure         Failure callback
 */
- (void)leaveFamilyWithHomeId:(long long)homeId
                     memberId:(long long)memberId
                      success:(ThingSuccessHandler)success
                      failure:(ThingFailureError)failure;

/**
 *  Join the family by invitation code
 *
 *  @param invitationCode   Invitation code
 *  @param success                  Success callback
 *  @param failure                  Failure callback
 */
- (void)joinFamilyWithInvitationCode:(NSString *)invitationCode
                             success:(ThingSuccessBOOL)success
                             failure:(ThingFailureError)failure;

/**
 *  Accepting an invitation to join a family
 *
 *  @param homeId           ID of the family invited to join
 *  @param success         Success callback
 *  @param failure         Failure callback
 */
- (void)acceptJoinFamilyWithHomeId:(long long)homeId
                           success:(ThingSuccessBOOL)success
                           failure:(ThingFailureError)failure;
/**
 * Declining an invitation to join a family
 *
 *  @param homeId           ID of the family invited to join
 *  @param success         Success callback
 *  @param failure         Failure callback
 */
- (void)rejectJoinFamilyWithHomeId:(long long)homeId
                           success:(ThingSuccessBOOL)success
                           failure:(ThingFailureError)failure;

/**
 *  Get rough information about the weather in your home area
 *
 *  @param homeId           Family ID
 *  @param success         Success callback
 *  @param failure         Failure callback
 */
- (void)getHomeWeatherSketchWithHomeId:(long long)homeId
                               success:(void(^)(ThingSmartWeatherSketchModel *))success
                               failure:(ThingFailureError)failure;

/**
 *  Get detailed information about the weather in your home area
 *
 *  @param homeId           Family ID
 *  @param success         Success callback
 *  @param failure         Failure callback
 */
- (void)getHomeWeatherDetailWithHomeId:(long long)homeId
                                option:(ThingSmartWeatherOptionModel *)optionModel
                               success:(void(^)(NSArray<ThingSmartWeatherModel *> *))success
                               failure:(ThingFailureError)failure;

/**
 *  Under-family devices, group sorting
 *
 *  @param homeId           Family ID
 *  @param orderList    Device, Group List
 *  @param success         Success callback
 *  @param failure         Failure callback
 */
- (void)sortDeviceOrGroupWithHomeId:(long long)homeId
                          orderList:(NSArray<ThingSmartFamilyDeviceGroupOrderRequestModel *> *)orderList
                            success:(ThingSuccessHandler)success
                            failure:(ThingFailureError)failure;

@end
