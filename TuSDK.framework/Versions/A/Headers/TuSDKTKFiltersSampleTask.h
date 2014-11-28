//
//  TuSDKTKFiltersSampleTask.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/4.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKTKFiltersTempTask.h"


@class TuSDKTKFiltersSampleTask;

/**
 *  滤镜预览效果列表委托
 */
@protocol TuSDKTKFiltersSampleTaskDelegate <NSObject>

/**
 *  滤镜预览效果列表任务创建完
 *
 *  @param task 滤镜预览效果列表任务
 *  @param name 已创建的滤镜名称
 */
- (void)onTuSDKTKFiltersSampleTask:(TuSDKTKFiltersSampleTask *)task result:(TuSDKTKFilterTaskResult *)result;
@end

/**
 *  滤镜预览效果列表任务
 */
@interface TuSDKTKFiltersSampleTask : TuSDKTKFiltersTaskBase{
    @protected
    // 滤镜临时预览效果列表任务
    TuSDKTKFiltersTempTask *_tempTask;
}

/**
 *  版本号
 */
@property (nonatomic, readonly) CGFloat version;

/**
 *  输入的源图片路径  (默认: lasFilterUIBundle/style_default_camera_filter_sample.jpg)
 */
@property (nonatomic, retain) NSString *inputImagePath;

/**
 *  是否需要清理旧版本预览图 (默认: YES)
 */
@property (nonatomic) BOOL needClearOldVersion;

/**
 *  滤镜预览效果列表委托
 */
@property (nonatomic, assign) id<TuSDKTKFiltersSampleTaskDelegate> delegate;

/**
 *  滤镜临时预览效果列表任务
 */
@property (nonatomic, readonly) TuSDKTKFiltersTempTask *tempTask;

/**
 *  滤镜预览效果列表任务
 *
 *  @param version 滤镜版本
 *
 *  @return 滤镜预览效果列表任务
 */
+ (instancetype)taskWithVersion:(CGFloat)version;

/**
 *  尝试创建滤镜临时预览效果列表任务
 *
 *  @param image 输入的图片
 */
- (void)tryBuildTempTaskWithInputImage:(UIImage *)image;
@end