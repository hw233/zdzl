//
//  TBPlatformBase.h
//  TBP3
//
//  Created by YLo. on 13-6-4.
//  Copyright (c) 2013年 ios_team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBPlatformAPIResponse.h"
#import <UIKit/UIKit.h>
@interface TBPlatform : NSObject
@property (nonatomic, readonly, assign) UIInterfaceOrientation orientation;	
/**
 @brief 获取TBPlatform实例对象
 */
+ (TBPlatform *)defaultPlatform;


/**
 @brief 获取SDK的版本号
 */
+ (NSString *)version;

/**
 @brief 获取屏幕截图
 */
+ (UIImage *)TBGetScreenShot;


/**
 @brief 设定平台初始方向
 */
- (void)TBSetScreenOrientation:(UIInterfaceOrientation)orientation;

/**
 @brief 设置是否自动旋转。
 @note
 1、默认开启自动旋转（横屏转横屏，竖屏转竖屏）
 2、设置NO后，使用TBSetScreenOrientation设置的方向
 */
- (void)TBSetAutoRotation:(BOOL)isAutoRotate;

/**
 *	@brief	打开调试模式
 *
 *	@param 	nFlag 	预留，0
 */
- (void)TBSetDebugMode:(int)nFlag;


/**
 *	@brief	设置是否显示欢迎标题
 *
 *	@param 	isShow 	BOOL，是否显示
 *
 */
- (void)TBSetWelcomeTipShow:(BOOL)isShow;

#pragma mark -
#pragma mark SDK接入时需要的验证信息

/**
 @brief 设置应用Id
 @param appId 应用程序id，需要向用户中心申请，合法的id大于0
 */
- (BOOL)setAppId:(int)appId;

/**
 @brief 获取用户信息，需登录
 */
- (TBPlatformUserInfo *)getUserInfo;
/**
 @brief 获取appId，需要预先设置
 */
- (int)appId;

#pragma mark -
#pragma mark Version Update

/**
 @brief 检查自身版本更新
 @param nFlag 标识（按位标识）默认为0，检测更新
 @param delegate 回调对象，回调接口参见 TBPlatformUpdateProtocol
 @result 错误码
 */
- (int)TBAppVersionUpdate:(int)nFlag delegate:(id)delegate;


@end

#pragma mark - check update protocol

@protocol TBPlatformUpdateProtocol


typedef enum  _TB_APP_UPDATE_RESULT {
	TB_APP_UPDATE_NO_NEW_VERSION = 0,                   /**< 没有新版本 */
	TB_APP_UPDATE_UPDATE_CANCEL_BY_USER = 1,            /**< 用户取消下载更新 */
	TB_APP_UPDATE_NEW_VERSION_DOWNLOAD_FAIL = 2,        /**< 下载新版本失败 */
	TB_APP_UPDATE_CHECK_NEW_VERSION_FAIL = 3,           /**< 检测新版本失败 */
}	TB_APP_UPDATE_RESULT;
/**
 @brief TBAppVersionUpdate的回调函数
 @param updateResult 检测更新结果
 */
- (void)appVersionUpdateDidFinish:(TB_APP_UPDATE_RESULT)updateResult;


@end

