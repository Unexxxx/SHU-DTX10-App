//
//  ThingSmartMemberBiz.h
//  ThingSmartFamilyBizKit
//
//  Created by Thing on 2023/8/10.
//

#import <Foundation/Foundation.h>
#import <ThingSmartDeviceKit/ThingSmartHomeAddMemberRequestModel.h>
#import <ThingSmartDeviceKit/ThingSmartHomeMemberRequestModel.h>
#import <ThingSmartDeviceKit/ThingSmartHomeMemberModel.h>
#import "ThingSmartMemberLinkDeviceListModel.h"
#import "ThingSmartHomeMemberAssocaiteRequestModel.h"
#import "ThingSmartFamilyMemberModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMemberBiz : NSObject

+ (instancetype)sharedInstance;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

/**
 *  Get the list of family members
 *
 *  @param homeId               Family ID
 *  @param success             Success callback
 *  @param failure             Failure callback
 */
- (void)getHomeMemberListWithHomeId:(long long)homeId
                            success:(void(^)(NSArray <ThingSmartHomeMemberModel *> * list))success
                            failure:(ThingFailureError )failure;

/**
 *  Get family member information corresponding to memberId
 *
 *  @param homeId       Family ID
 *  @param memberId   Member ID
 *  @param success     Success callback
 *  @param failure     Failure callback
 */
- (void)getHomeMemberInfoWithHomeId:(long long)homeId
                           memberId:(long long)memberId
                            success:(void(^)(ThingSmartHomeMemberModel * model))success
                            failure:(ThingFailureError)failure;
/**
 *  Get device available to family member
 *
 *  @param memberId    Member ID
 *  @param success      Success callback
 *  @param failure      Failure callback
 */
- (void)getHomeMemberDeviceListWithMemberId:(long long)memberId
                                    success:(void(^)(NSArray <ThingSmartMemberLinkDeviceListModel *> * list))success
                                    failure:(ThingFailureError)failure;

/**
 *  Transfer family ownership
 *
 *  @param memberId    Member ID of the receiving family
 *  @param success      Success callback
 *  @param failure      Failure callback
*/
- (void)transferHomeWithMemberId:(long long)memberId
                         success:(ThingSuccessHandler)success
                         failure:(ThingFailureError)failure;

/**
 *  Get Invitation Records
 *
 *  @param homeId        Family ID
 *  @param success      Success callback
 *  @param failure      Failure callback
 */
- (void)getInvitationRecordListWithHomeId:(long long)homeId
                                    success:(void(^)(NSArray<ThingSmartHomeInvitationRecordModel *> *invitationRecordList))success
                                    failure:(ThingFailureError)failure;

/**
 *  Create an invitation to join a family
 *
 *  @param homeId        Family ID
 *  @param success      Success callback
 *  @param failure      Failure callback
 */
- (void)createInvitationWithHomeId:(long long)homeId
                           success:(void(^)(ThingSmartHomeInvitationResultModel *invitationResultModel))success
                           failure:(ThingFailureError)failure;

/**
 *  Renewed invitation
 *
 *  @param invitationId     Invitation Record ID
 *  @param success                Success callback
 *  @param failure                Failure callback
 */
- (void)reinviteInvitationWithInvitationId:(NSNumber *)invitationId
                                   success:(void(^)(ThingSmartHomeInvitationResultModel *invitationResultModel))success
                                   failure:(ThingFailureError)failure;

/**
 *  Update invitation information
 *
 *  @param invitationInfoRequestModel    Invitation Information Request Model
 *  @param success                                              Success callback
 *  @param failure                                              Failure callback
 */
- (void)updateInvitationWithModel:(ThingSmartHomeInvitationInfoRequestModel *)invitationInfoRequestModel
                          success:(ThingSuccessBOOL)success
                          failure:(ThingFailureError)failure;

/**
 *  Cancel invitation
 *
 *  @param invitationId     Invitation Record ID
 *  @param success                Success callback
 *  @param failure                Failure callback
 */
- (void)cancelInvitationWithInvitationId:(NSNumber *)invitationId
                                 success:(ThingSuccessBOOL)success
                                 failure:(ThingFailureError)failure;

/**
 *  Add a home member
 *
 *  @param model           Adding Family Member Models
 *  @param homeId         Family ID
 *  @param success       Success callback
 *  @param failure       Failure callback
 */
- (void)addHomeMemberWithModel:(ThingSmartHomeAddMemberRequestModel *)model
                        homeId:(long long)homeId
                       success:(void(^)(ThingSmartFamilyMemberModel *memberModel))success
                       failure:(ThingFailureError)failure;

/**
 *  Delete member
 *
 *  @param memberId       Member ID
 *  @param success         Success callback
 *  @param failure         Failure callback
 */
- (void)removeHomeMemberWithMemberId:(long long)memberId
                             success:(ThingSuccessHandler)success
                             failure:(ThingFailureError)failure;

/**
 *  Update family member information
 *
 *  @param model         Add family member request model
 *  @param success    Success callback
 *  @param failure    Failure callback
 */
- (void)updateHomeMemberInfoWithModel:(ThingSmartHomeMemberRequestModel *)model
                              success:(ThingSuccessHandler)success
                              failure:(ThingFailureError)failure;

/**
 *  Associated User Accounts
 *
 *  @param model            Request model
 *  @param success        Success callback
 *  @param failure        Failure callback
 */
- (void)associateHomeMemberWithModel:(ThingSmartHomeMemberAssocaiteRequestModel *)model
                             success:(void(^)(BOOL result))success
                             failure:(ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
