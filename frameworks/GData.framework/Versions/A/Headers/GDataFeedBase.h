/* Copyright (c) 2007 Google Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

//
//  GDataFeedBase.h
//

#import "GDataObject.h"

#import "GDataGenerator.h"
#import "GDataTextConstruct.h"
#import "GDataLink.h"
#import "GDataEntryBase.h"
#import "GDataCategory.h"
#import "GDataPerson.h"
#import "GDataBatchOperation.h"
#import "GDataAtomPubControl.h"

#undef _EXTERN
#undef _INITIALIZE_AS
#ifdef GDATAFEEDBASE_DEFINE_GLOBALS
#define _EXTERN 
#define _INITIALIZE_AS(x) =x
#else
#define _EXTERN extern
#define _INITIALIZE_AS(x)
#endif

// this constant, returned by a subclass implementation of -classForEntries,
// specifies that a feed's entry class should be determined by inspecting
// the XML for a "kind" category and looking at the registered entry classes
// for an appropriate match 
_EXTERN Class kUseRegisteredEntryClass _INITIALIZE_AS(nil);

@interface GDataFeedBase : GDataObject {

  GDataGenerator *generator_;
  
  NSString *idString_;
  GDataTextConstruct *title_;
  GDataTextConstruct *subtitle_;
  GDataTextConstruct *rights_;
  NSString *icon_;
  NSString *logo_;
  
  NSMutableArray *links_;
  NSMutableArray *authors_;
  NSMutableArray *contributors_;
  NSMutableArray *categories_;
  
  GDataDateTime* updatedDate_;

  NSNumber *totalResults_;
  NSNumber *startIndex_;
  NSNumber *itemsPerPage_;
  
  NSMutableArray *entries_;
}

+ (id)feedWithXMLData:(NSData *)data;
- (id)initWithData:(NSData *)data;

// subclasses override initFeed to set up their ivars
- (void)initFeedWithXMLElement:(NSXMLElement *)element;

// subclasses may implement this
- (NSMutableArray *)itemsForDescription; 

// subclass may override this to specify an entry class or
// to return kUseRegisteredEntryClass
- (Class)classForEntries;

- (BOOL)canPost;

// getters and setters
- (GDataGenerator *)generator;
- (void)setGenerator:(GDataGenerator *)gen;

- (NSString *)identifier;
- (void)setIdentifier:(NSString *)theString;

- (GDataTextConstruct *)title;
- (void)setTitle:(GDataTextConstruct *)theTitle;
- (void)setTitleWithString:(NSString *)str;

- (GDataTextConstruct *)subtitle;
- (void)setSubtitle:(GDataTextConstruct *)theSubtitle;
- (void)setSubtitleWithString:(NSString *)str;

- (GDataTextConstruct *)rights;
- (void)setRights:(GDataTextConstruct *)theRights;
- (void)setRightsWithString:(NSString *)str;

- (NSString *)icon;
- (void)setIcon:(NSString *)theString;

- (NSString *)logo;
- (void)setLogo:(NSString *)theString;

- (NSArray *)links;
- (void)setLinks:(NSArray *)links;
- (void)addLink:(GDataLink *)obj;
- (void)removeLink:(GDataLink *)obj;

- (NSArray *)authors;
- (void)setAuthors:(NSArray *)authors;
- (void)addAuthor:(GDataPerson *)obj;

- (NSArray *)contributors;
- (void)setContributors:(NSArray *)array;
- (void)addContributor:(GDataPerson *)obj;

- (NSArray *)categories;
- (void)setCategories:(NSArray *)categories;
- (void)addCategory:(GDataCategory *)category;
- (void)removeCategory:(GDataCategory *)category;

- (GDataDateTime *)updatedDate;
- (void)setUpdatedDate:(GDataDateTime *)theDate;

- (NSArray *)entries;

// setEntries: and addEntry: assert if the entries have other parents
// already set; use setEntriesWithEntries: and addEntryWithEntry: to copy
// entries that have other parents
- (void)setEntries:(NSArray *)entries;
- (void)addEntry:(GDataEntryBase *)obj;

- (void)setEntriesWithEntries:(NSArray *)entries;
- (void)addEntryWithEntry:(GDataEntryBase *)obj;

- (NSNumber *)totalResults;
- (void)setTotalResults:(NSNumber *)theString;

- (NSNumber *)startIndex;
- (void)setStartIndex:(NSNumber *)theString;

- (NSNumber *)itemsPerPage;
- (void)setItemsPerPage:(NSNumber *)theString;

// Atom publishing control
- (GDataAtomPubControl *)atomPubControl;
- (void)setAtomPubControl:(GDataAtomPubControl *)obj;

// Batch support
- (GDataBatchOperation *)batchOperation;
- (void)setBatchOperation:(GDataBatchOperation *)obj;

// convenience routines

// find the entry with the given identifier, or nil if none found
- (id)entryForIdentifier:(NSString *)str;

@end

