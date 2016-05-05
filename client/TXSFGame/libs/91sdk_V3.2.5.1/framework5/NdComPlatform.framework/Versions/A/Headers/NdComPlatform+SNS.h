//
//  NdComPlatform+SNS.h
//  NdComPlatform_SNS
//
//  Created by xujianye on 12-5-24.
//  Copyright 2012 NetDragon WebSoft Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NdComPlatformBase.h"
#import "NdComPlatformAPIResponse.h"
#import "NdComPlatformAPIResponse+ThirdPlatform.h"
#import "NdComPlatformAPIResponse+UserInfo.h"

@interface NdComPlatform(SNS)

/**
 @brief 进入好友中心
 @param nFlag  预留，默认为0。
 */
- (void)NdEnterFriendCenter:(int) nFlag;

/**
 @brief 进入指定用户的空间
 @param uin 用户uin
 @result 错误码
 */
- (int)NdEnterUserSpace:(NSString*)uin;

/**
 @brief 进入看看谁在玩
 @param nFlag 预留，目前传0即可
 @result 错误码
 */
- (int)NdEnterAppUserCenter:(int)nFlag;

/**
 @brief 邀请好友
 @param strInviteContent 邀请内容
 @result 错误码
 */
- (int)NdInviteFriend:(NSString*)strInviteContent;




#pragma mark -
#pragma mark Download Data

/**
 @brief 获取当前应用的用户
 @param pagination 分页信息
 @param delegate 回调对象，回调接口参见 NdComPlatformUIProtocol
 @result 错误码
 */
- (int)NdGetAppUserList:(NdPagination *)pagination delegate:(id)delegate;

/**
 @brief 获取当前应用的我的好友
 @param pagination 分页信息
 @param delegate 回调对象，回调接口参见 NdComPlatformUIProtocol
 @result 错误码
 */
- (int)NdGetAppMyFriendList:(NdPagination *)pagination delegate:(id)delegate;

/**
 @brief 获取我的好友
 @param pagination 分页信息
 @param delegate 回调对象，回调接口参见 NdComPlatformUIProtocol
 @result 错误码
 */
- (int)NdGetMyFriendList:(NdPagination *)pagination delegate:(id)delegate;

/**
 @brief 给好友发送信息
 @param uin 要发送的好友uin
 @param msgContent 要发送的消息内容
 @param delegate 回调对象，回调接口参见 NdComPlatformUIProtocol
 @result 错误码
 */
- (int)NdSendFriendMsg:(NSString *)uin msgContent:(NSString *)msgContent delegate:(id)delegate;

/**
 @brief 获取好友在通讯录中的名字
 @param uin 好友uin
 @result 好友联系人名称，如果联系人中没有查找到，则返回空
 */
- (NSString*)NdGetContactName:(NSString*)uin;

/**
 @brief 获取新消息数和新系统消息数
 @param delegate 回调对象，回调接口参见 NdComPlatformUIProtocol
 @result 错误码
 @note 该接口从网络获取数据，返回结果会回调给delegate；同时，如果消息数目有变化，也会发kNdCPNewMessageNotification消息通知。
 */
- (int)NdGetNewMsgAndNewSysMsgCount:(id)delegate;

/**
 @brief 获取新系统消息数
 @result 新系统消息数
 @note 平台会定期刷新该数据。如果有变更，会发kNdCPNewMessageNotification消息通知。如果要立即更新，调用NdGetNewMsgAndNewSysMsgCount接口。
 */
- (int)NdGetNewMsgCountSys;

/**
 @brief 获取新消息数（来自好友的）
 @result 新消息数
 @note 平台会定期刷新该数据。如果有变更，会发kNdCPNewMessageNotification消息通知。如果要立即更新，调用NdGetNewMsgAndNewSysMsgCount接口。
 */
- (int)NdGetNewMsgCount;

/**
 @brief 获取用户的详细信息
 @param uin		 用户uin，不能为空
 @param flag	 标志位，按位与组合。1＝基本信息，2＝积分，4＝心情。
 @param delegate 回调对象，回调接口参见 NdComPlatformUIProtocol
 @result 错误码
 */
- (int)NdGetUserInfoDetail:(NSString*)uin  flag:(int)flag  delegate:(id)delegate;

/**
 @brief 使用动态模版发送动态
 @param templateId 模版ID
 @param paramList 参数列表，键值对。
 @param delegate 回调对象，回调接口参见 NdComPlatformUIProtocol
 @result 错误码
 */
- (int)NdSendTemplateActivity:(int)templateId paramList:(NSDictionary*)dicParamList delegate:(id)delegate;


@end




#pragma mark -
#pragma mark -

@protocol NdComPlatformUIProtocol_SNS


/**
 @brief NdGetAppUserList的回调
 @param error 错误码，如果error为0，则代表API执行成功，否则失败。错误码涵义请查看NdComPlatformError文件 
 @param resultList 应用用户信息列表
 */
- (void)getAppUserListDidFinish:(int)error resultList:(NdStrangerUserInfoList *)userInfoList;


/**
 @brief NdGetAppMyFriendList的回调
 @param error 错误码，如果error为0，则代表API执行成功，否则失败。错误码涵义请查看NdComPlatformError文件 
 @param resultList 应用好友信息列表
 */
- (void)getAppMyFriendListDidFinish:(int)error resultList:(NdFriendUserInfoList *)userInfoList;


/**
 @brief NdGetMyFriendList的回调
 @param error 错误码，如果error为0，则代表API执行成功，否则失败。错误码涵义请查看NdComPlatformError文件 
 @param resultList 搜索结果
 */
- (void)searchMyFriendDidFinish:(int)error resultList:(NdFriendUserInfoList *)friendUserInfoList;


/**
 @brief NdSendFriendMsg的回调
 @param error 错误码，如果error为0，则代表API执行成功，否则失败。错误码涵义请查看NdComPlatformError文件 
 @param msgId 发送成功后返回的消息id
 */
- (void)sendFriendMsgDidFinish:(int)error msgId:(NSString *)msgId;


/**
 @brief NdGetNewMsgAndNewSysMsgCount的回调函数
 @param error 错误码，如果error为0，则代表API执行成功，否则失败。错误码涵义请查看NdComPlatformError文件 
 @param newMsgCount 新消息个数
 @param newSysMsgCount 新系统消息个数
 */
- (void)getNewMsgAndNewSysMsgCountDidFinish:(int)error newMsgCount:(int)newMsgCount newSysMsgCount:(int)newSysMsgCount;


/**
 @brief NdGetUserInfoDetail 的回调
 @param error 错误码，如果error为0，则代表API执行成功，否则失败。错误码涵义请查看NdComPlatformError文件
 @param userInfo 获取到的用户信息
 */
- (void)getUserInfoDidFinish:(int)error userInfo:(NdUserInfo *)userInfo;


/**
 @brief NdSendTemplateActivity的回调
 @param error 错误码，如果error为0，则代表API执行成功，否则失败。错误码涵义请查看NdComPlatformError文件  
 */
- (void)sendTemplateActivityDidFinish:(int)error;


@end