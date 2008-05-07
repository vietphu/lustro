//
//  ExportGoogle.h
//  lustro
//
//  Created by Jelle Vandebeeck & Simon Schoeters on 22/04/08.
//  Copyright 2008 eggnog. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AddressBook/AddressBook.h>
#import <AddressBook/ABPerson.h>
#import "ExportController.h"
#import "ExportProtocol.h"
#import "GData/GDataContacts.h"
#import "GData/GDataFeedGoogleBase.h"

@interface ExportGoogle : ExportController < ExportProtocol > {
	GDataServiceGoogleContact* service;
	NSString *username;
	NSString *password;
	GDataServiceTicket *ticket;
}

// A "service" object handles networking tasks. Service objects contain user authentication information as well as networking state information (such as cookies and the "last modified" date for fetched data.)

- (id)initWithAddressBook:(ABAddressBook *)addressBook username:(NSString *)user password:(NSString *)pass target:(id)errorCtrl selector:(SEL)msg; 
- (void)authenticate;									// Get a contact service object with the current username/password
- (void)createContacts;									// Creates a GData contact with the information from Address Book
- (void)removeAllContacts;								// Fetch the feed with all the Google Contacts and call the didFinishSelector to remove each contact

- (NSString *)makeRelFromLabel:(NSString *)label;		// Translates Address Book labels to Googles rel attributes or to the 'other' attribute if nothing found

@end
