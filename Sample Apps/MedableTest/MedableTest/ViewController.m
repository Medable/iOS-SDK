//
//  ViewController.m
//  MedableTest
//
//  Copyright (c) 2015 Medable Inc. All rights reserved.
//

#import "ViewController.h"
#import <Medable/Medable.h>

@interface ViewController ()

@property (nonatomic, weak) IBOutlet UILabel *orgName;
@property (nonatomic, weak) IBOutlet UILabel *status;
@property (nonatomic, weak) IBOutlet UILabel *orgCode;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.orgName.text = @"";
    self.orgCode.text = @"";
    
    MDAPIClient *client = [MDAPIClient sharedClient];
    
    if ( client != nil )
    {
        self.status.text = @"Initialized";
    }
    else
    {
        self.status.text = @"Error on Init";
    }
}

-(IBAction)getOrganization:(id)sender
{
    MDAPIClient *client = [MDAPIClient sharedClient];
    
    [client getOrgInfoWithCallback:^(MDOrg *org, MDFault *fault)
    {
        if ( org != nil )
        {
            self.orgName.text = org.name;
            self.orgCode.text = org.code;
            self.status.text = @"Ok";
        }
        
        if ( fault != nil )
        {
            self.status.text = @"Error";
            
            UIAlertController *alert = [UIAlertController new];
            alert.title = @"Error";
            alert.message = fault.message;
            
            UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Ok"
                                                                   style:UIAlertActionStyleCancel
                                                                 handler:^(UIAlertAction *action)
            {
                                                                     
            }];
            
            [alert addAction:cancelAction];
            
            [self presentViewController:alert animated:YES completion:^
            {
                
            }];
        }
    }];
}


@end


