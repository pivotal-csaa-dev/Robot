#import "RBMacros.h"

RB_INLINE NSArray *RBForceIntoArrayIfNotNil(id objectOrArray) {
    if ([objectOrArray isKindOfClass:[NSArray class]]) {
        return objectOrArray;
    } else if (objectOrArray) {
        return @[objectOrArray];
    }
    return nil;
}

#define RBTIME(BLOCK) \
    static NSTimeInterval cumulativeDuration = 0; \
    NSDate *startDate = [NSDate date]; \
    (BLOCK); \
    NSDate *endDate = [NSDate date]; \
    NSTimeInterval delta = [endDate timeIntervalSinceDate:startDate]; \
    cumulativeDuration += delta; \
    NSLog(@"> culm duration: %f (+ %f)", cumulativeDuration, delta);