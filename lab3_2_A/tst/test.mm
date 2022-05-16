#import <XCTest/XCTest.h>
#include "Student.hpp"

@interface test : XCTestCase

@end

@implementation test

- (void)testExample {
    
    Student s[2];
    
    s[0].Physics = 5;
    s[0].Mathematics =5;
    s[0].Informatics =5;
    
    s[1].Physics = 4;
    s[1].Mathematics = 3;
    s[1].Informatics = 5;

    XCTAssertEqual(AverageGrade(s, 0), 5);
}

@end
