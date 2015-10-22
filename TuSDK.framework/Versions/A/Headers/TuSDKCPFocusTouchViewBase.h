//
//  TuSDKCPFocusTouchViewBase.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/29.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TuSDKVideoCameraInterface.h"

/**
 *  相机聚焦触摸视图
 */
@interface TuSDKCPFocusTouchViewBase : UIView

/**
 *  相机对象
 */
@property (nonatomic, assign) id<TuSDKVideoCameraInterface> camera;

/**
 *  聚焦模式
 */
@property (nonatomic) AVCaptureFocusMode focusMode;

/**
 *  是否开启长按拍摄 (默认: NO)
 */
@property (nonatomic) BOOL enableLongTouchCapture;

/**
 *  禁用持续自动对焦 (默认: NO)
 */
@property (nonatomic) BOOL disableContinueFoucs;

/**
 *  自动聚焦延时 (默认: 5秒)
 */
@property (nonatomic) NSTimeInterval autoFoucsDelay;

/**
 *  长按延时 (默认: 1.2秒)
 */
@property (nonatomic) NSTimeInterval longTouchDelay;

/**
 *  显示区域百分比
 */
@property (nonatomic) CGRect regionPercent;

/**
 *  相机状态改变
 *
 *  @param state 改变
 */
- (void)cameraStateChanged:(lsqCameraState)state;

/**
 *  当前聚焦状态
 *
 *  @param isFocusing 是否正在聚焦
 */
- (void)onAdjustingFocus:(BOOL)isFocusing;

/**
 *  聚焦点
 *
 *  @param point 聚焦点
 *
 *  @return 是否允许聚焦
 */
- (BOOL)onFocusWithPoint:(CGPoint)point;

/**
 *  重置聚焦到中心
 */
- (void)resetFoucsCenter;

/**
 *  通知相机聚焦点
 *
 *  @param point 聚焦点
 */
- (void)notifyCameraWithFocusPoint:(CGPoint)point;
@end
