//
//  TuSDKPFCameraView.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/3.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TuSDKPFCameraFilterView.h"

#pragma mark - TuSDKPFCameraFlashView
@class TuSDKPFCameraFlashView;
/**
 *  默认相机闪光灯视图委托
 */
@protocol TuSDKPFCameraFlashDelegate <NSObject>
/**
 *  选中闪光灯模式
 *
 *  @param view 默认相机闪光灯视图
 *  @param mode 闪光灯模式
 */
- (void)onTuSDKPFCameraFlashView:(TuSDKPFCameraFlashView *)view selectedMode:(AVCaptureFlashMode)mode;
@end

/**
 *  默认相机闪光灯视图
 */
@interface TuSDKPFCameraFlashView : UIButton{
    @protected
    // 闪光灯包装视图
    UIImageView *_flashWrapView;
    // 闪光灯选项按钮列表
    NSMutableArray *_buttons;
}

/**
 *  默认相机闪光灯视图委托
 */
@property (nonatomic, assign) id<TuSDKPFCameraFlashDelegate> delegate;

/**
 *  设置闪光灯按钮坐标
 *
 *  @param frame 坐标
 */
- (void)setFlashFrame:(CGRect)frame;

/**
 *  显示视图
 *
 *  @param isShow 是否显示视图
 */
- (void)showView:(BOOL)isShow;
@end

#pragma mark - TuSDKPFCameraConfigView
/**
 *  默认相机控制栏视图
 */
@interface TuSDKPFCameraConfigView : UIView{
    @protected
    // 关闭按钮
    UIButton *_closeButton;
    // 闪光灯按钮
    UIButton *_flashButton;
    // 前后摄像头切换按钮
    UIButton *_switchButton;
}
/**
 *  关闭按钮
 */
@property (nonatomic, readonly) UIButton *closeButton;

/**
 *  闪光灯按钮
 */
@property (nonatomic, readonly) UIButton *flashButton;

/**
 *  前后摄像头切换按钮
 */
@property (nonatomic, readonly) UIButton *switchButton;

/**
 *  闪光灯模式
 */
@property (nonatomic) AVCaptureFlashMode flashMode;
@end

#pragma mark - TuSDKPFCameraConfigView
/**
 *  默认相机底部栏视图
 */
@interface TuSDKPFCameraBottomView : UIView{
    @protected
    // 拍摄按钮
    UIButton *_captureButton;
    // 滤镜开关按钮
    UIButton *_filterButton;
}
/**
 *  拍摄按钮
 */
@property (nonatomic, readonly) UIButton *captureButton;

/**
 *  滤镜开关按钮
 */
@property (nonatomic, readonly) UIButton *filterButton;

/**
 *  创建滤镜开关按钮
 */
- (void)buildFilterButton;
@end

#pragma mark - TuSDKPFCameraView
@class TuSDKPFCameraView;
/**
 *  默认相机视图委托
 */
@protocol TuSDKPFCameraViewDelegate <NSObject>
/**
 *  选中一个闪光灯模式
 *
 *  @param mode 闪光灯模式
 */
- (void)onTuSDKPFCameraSelectedFlashMode:(AVCaptureFlashMode)mode;
@end

/**
 *  默认相机视图
 */
@interface TuSDKPFCameraView : UIView<TuSDKPFCameraFlashDelegate>{
    @protected
    // 显示图像视图
    UIImageView *_displayView;
    // 默认相机控制栏视图
    TuSDKPFCameraConfigView *_configBar;
    // 默认相机底部栏视图
    TuSDKPFCameraBottomView *_bottomBar;
    // 闪光灯视图
    TuSDKPFCameraFlashView *_flashView;
    // 滤镜视图
    TuSDKPFCameraFilterView *_filterView;
}
/**
 *  显示图像视图
 */
@property (nonatomic, readonly) UIView *displayView;

/**
 *  默认相机控制栏视图
 */
@property (nonatomic, readonly) TuSDKPFCameraConfigView *configBar;

/**
 *  默认相机底部栏视图
 */
@property (nonatomic, readonly) TuSDKPFCameraBottomView *bottomBar;

/**
 *  闪光灯视图
 */
@property (nonatomic, readonly) TuSDKPFCameraFlashView *flashView;

/**
 *  滤镜列表视图
 */
@property (nonatomic, readonly) TuSDKPFCameraFilterView *filterView;

/**
 *  滤镜视图
 */
@property (nonatomic, assign) id<TuSDKPFCameraViewDelegate> delegate;

/**
 *  通知系统旋转
 *
 *  @param deviceOrientation 设备方向
 */
- (void)orientationChanged:(UIDeviceOrientation)deviceOrientation;

/**
 *  创建滤镜视图
 */
- (void)buildFilterView;
@end