#import <XCTest/XCTest.h>
#include "Student.hpp"

@interface test : XCTestCase

@end

@implementation test


- (void)testExample {
    
    Student s[2];
    
    s[0].Physics = 5;
    s[0].Mathematics =5;
    s[0].Programming =5;
    
    s[1].Physics = 4;
    s[1].Mathematics = 3;
    s[1].Programming = 5;

    XCTAssertEqual(PhysicsFive(s, 1), 1);

}

@end


