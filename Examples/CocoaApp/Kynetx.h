//
//  kynetx.h
//  kynetx-desktop
//
//  Created by Alex  on 12/23/10.
//  Copyright 2010 Kynetx. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "JSON/JSON.h"

/** 
 @brief An object that handles raising events to kynetx and parsing returned directives
 @author Alex Olson
 */
@interface Kynetx : NSObject {
	// silence is golden. Actually properties are golden. Hence this emptiness.
}

/** 
 @brief The event domain for the raised events.
 
 This is built-in and cannot be changed
 */
@property (readonly, nonatomic, retain) NSString* eventDomain;

/**
 @brief The appid to raise the specified events too
 
 This is the ruleset that will recieve the events raised.
 */
@property (nonatomic, retain) NSString* appid;

/** 
 @brief Basic init method.
 @returns self 
 */
-(id) init;

/**
 @brief method to initialize with an App ID.
 
 This is the preferred initialization method. 
 @param input the appid to initialize the object with. 
 @returns self
 */
-(id) initWithAppID:(id) input;

/**
 @brief method to raise event to kynetx servers
 
 This method raises events to the kynetx servers.
 See the
 <a href = "http://docs.kynetx.com/docs/Kynetx_Network_Service_API" target="_blank">kynetx documentation</a>
 for more information regarding events.
 @param name name of the event to raise
 @param params a dictionary of key-value pairs to send to kynetx ruleset
 @returns result of parseDirectives
 */
-(NSArray*) raiseEvent:(NSString*) name params:(NSDictionary*) params; 

/**
 @brief parse directives returned by KNS for a raised event
 @param response NSData* object returned by a GET request
 @returns NSArray* of NSDictionary* directives
*/
-(NSArray*) parseDirectives:(NSData*) response;

/**
 @brief build a NSURL* from a NSDictionary and a NSString
 @param params url paramaters to add to url string
 @param URLString URL string to add params to
 @returns NSURL* 
 */
-(NSURL*) URLFromDict:(NSDictionary*) params withBaseURL:(NSString*) URLString;

/// destructor
-(void) dealloc;


@end
