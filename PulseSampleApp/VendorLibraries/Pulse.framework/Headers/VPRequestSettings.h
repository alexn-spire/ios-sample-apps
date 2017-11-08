//
//  VPRequestSettings.h
//  Pulse
//
//  Created by Jacques du Toit on 20/04/15.
//  Copyright (c) 2015 Ooyala. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Options for types you can set in the insertionPointFilter property in
 VPRequestSettings. These will determine when the received ads are to be played.
 */
typedef NS_OPTIONS(NSUInteger, VPInsertionPointType) {
  /// The default, which will include all types.
  VPInsertionPointTypeAll              = 0,
  /// Request ads to be played before the content, or 'preroll' ads.
  VPInsertionPointTypeOnBeforeContent  = 1 << 0,
  /**
   Request midroll ads and/or overlay ads, to be played at the positions
   specified in linearPlaybackPositions and nonlinearPlaybackPositions respectively.
   */
  VPInsertionPointTypePlaybackPosition = 1 << 1,
  /// Request ads to be played after the content, or 'postroll' ads.
  VPInsertionPointTypeOnContentEnd     = 1 << 2,
  /// Request ads to be played when the content is paused.
  VPInsertionPointTypeOnPause          = 1 << 3,
  /**
   Request overlay ads to be displayed; based on the content duration, which must
   which must be specified as well.
  */
  VPInsertionPointTypePlaybackTime     = 1 << 4
};

/** 
 Settings about the environment in which the ad will play.
 */
@interface VPRequestSettings : NSObject


- (id)copyExistingProperties:(VPRequestSettings *)sourceRequestSetting
     OverrrideRequestSetting:(VPRequestSettings *)overrideRs;

/** 
 Height in pixels of the video area where ads will be shown.
 */
@property (nonatomic, assign) NSInteger height;

/**
 Width in pixels of the video area where ads will be shown.
 */
@property (nonatomic, assign) NSInteger width;

/**
 The maximum bitrate of the media files in the ad response.
 */
@property (nonatomic, assign) NSInteger maxBitRate;

/**
 The advertising identifier unique for each iOS device.
 If RTB ads are configured in Pulse, this information will be forwarded to the DSP.
 */
@property (nonatomic, copy) NSString *IDFA;

/**
 The id of the application using this SDK in the format "A1B2C3D4E5.com.domainame.applicationname".
 If RTB ads are configured in Pulse, this information will be forwarded to the DSP.
 */
@property (nonatomic, copy) NSString *applicationID;

/**
 The name of the application using this SDK. An example would be: "pulseplayer".
 If RTB ads are configured in Pulse, this information will be forwarded to the DSP.
 */
@property (nonatomic, copy) NSString *applicationName;

/**
 The version of the application using this SDK. An example would be: "1.0.0".
 If RTB ads are configured in Pulse, this information will be forwarded to the DSP.
 */
@property (nonatomic, copy) NSString *applicationVersion;

/**
 The bundle id of the application using this SDK, in the format "com.domainname.applicationname"
 If RTB ads are configured in Pulse, this information will be forwarded to the DSP.
 */
@property (nonatomic, copy) NSString *applicationBundle;

/**
 The App Store URL where you can download the application using this SDK. An example would be: "https://itunes.apple.com/us/app/keynote/id361285480?mt=8"
 If RTB ads are configured in Pulse, this information will be forwarded to the DSP.
 */
@property (nonatomic, copy) NSString *storeUrl;

/**
 An array of numbers which defines points in time when linear ads should be shown.
 */
@property (nonatomic, copy) NSArray *linearPlaybackPositions;

/**
 An array of numbers which defines points in time when non-linear ads should be shown.
 */
@property (nonatomic, copy) NSArray *nonlinearPlaybackPositions;

/**
 A bitmask that determines which kinds of insertion points will be requested. 
 If not set, all types will be requested.
 */
@property (nonatomic, assign) VPInsertionPointType insertionPointFilter;

/**
 Overrides the HTTP header's referrer property
 */
@property (nonatomic, copy) NSURL *referrerUrl;

/**
 The maximum duration in seconds of linear ad breaks.
 */
@property (nonatomic, assign) NSInteger maxLinearBreakDuration;

@end
