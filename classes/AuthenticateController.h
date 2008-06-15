//
//  AuthenticateController.h
//  lustro
//
//  Created by Simon Schoeters on 09/06/08.
//  Copyright 2008 IMEC. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "GoogleExport.h"
#import "AGKeychain.h"

@interface AuthenticateController : NSObject {
	NSUserDefaults *defaults;
	IBOutlet NSWindow *panel;
	IBOutlet NSTextField *errorLabel;
	IBOutlet NSTextField *usernameField;
	IBOutlet NSTextField *passwordField;
	IBOutlet NSButton *signInButton;
	@private NSString *username;
	@private NSString *password;
}

- (IBAction)closeLogPanel:(id)sender;
- (IBAction)signIn:(id)sender;

@property (retain, readonly) NSWindow *panel;
@property (retain, readonly) NSString *username;
@property (retain, readonly) NSString *password;
@end