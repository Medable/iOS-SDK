//
//  MDVersion.h
//  MedableCortex
//
//  Created by Martin Adoue on 2018/05/28.
//  Copyright © 2018 Medable. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MDVersion
+(NSString *)version;
+(NSString *)name;
+(NSString *)sha;
+(NSNumber *)build;
@end

