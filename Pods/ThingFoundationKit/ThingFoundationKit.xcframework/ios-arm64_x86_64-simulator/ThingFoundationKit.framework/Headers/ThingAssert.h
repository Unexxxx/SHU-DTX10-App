//
//  ThingAssert.h
//  Pods
//
//  Created by 尼奥 on 2020/8/13.
//

#ifndef ThingAssert_h
#define ThingAssert_h

#ifdef __OPTIMIZE__

/* relese */

#define ThingAssertCond(__cond)             do {} while (0)
#define ThingAssertCondDesc(__cond, __desc) do {} while (0)
#define ThingAssertCondDescs(__cond, __desc, ...) do {} while (0)

#else

/* debug */

#include <assert.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/sysctl.h>

// 检查是否处于被 Xcode 调试中
// 参考 https://developer.apple.com/library/archive/qa/qa1361/_index.html
static inline bool AmIBeingDebugged(void)
    // Returns true if the current process is being debugged (either
    // running under the debugger or has a debugger attached post facto).
{
    int                 junk;
    int                 mib[4];
    struct kinfo_proc   info;
    size_t              size;

    // Initialize the flags so that, if sysctl fails for some bizarre
    // reason, we get a predictable result.

    info.kp_proc.p_flag = 0;

    // Initialize mib, which tells sysctl the info we want, in this case
    // we're looking for information about a specific process ID.

    mib[0] = CTL_KERN;
    mib[1] = KERN_PROC;
    mib[2] = KERN_PROC_PID;
    mib[3] = getpid();

    // Call sysctl.

    size = sizeof(info);
    junk = sysctl(mib, sizeof(mib) / sizeof(*mib), &info, &size, NULL, 0);
    assert(junk == 0);

    // We're being debugged if the P_TRACED flag is set.

    return ( (info.kp_proc.p_flag & P_TRACED) != 0 );
}

/*
 替换系统断言宏，当遇到断言时会在 Xcode 触发一次命中断点，可以方便的保留调用栈的上下文
 相关背景信息可以查看 https://registry.code.thing-inc.top/thingIOS/ThingFoundationKit/issues/1
 */

/* break */
#if TARGET_IPHONE_SIMULATOR && XCODE_VERSION_MAJOR > 1200
    #define Thing_ASSERT_BREAK_POINT asm("int3");
#elif TARGET_OS_IPHONE
/// 为了避免测试使用 DEBUG 遇到断言导致闪退， 仅在 Xcode 环境中 DEBUG 时才生效
    #define Thing_ASSERT_BREAK_POINT \
        do { \
            if(AmIBeingDebugged()) { \
                raise(SIGINT); \
            } \
        } while(0)
#else
    #define Thing_ASSERT_BREAK_POINT do {} while (0)
#endif

/* thing style assert */
#define ThingAssertCond(__cond)              ThingAssertCondDesc(__cond, @"ThingAssert")
#define ThingAssertCondDesc(__cond, __desc)  ThingAssertCondDescs(__cond, __desc)
#define ThingAssertCondDescs(__cond, __desc, ...)  do { \
    if(!(__cond)) { \
        NSLog(__desc,  ##__VA_ARGS__); \
        Thing_ASSERT_BREAK_POINT; \
    } \
} while (0)

///* replace apple assert */
//#undef NSAssert
//#define NSAssert(condition, desc, ...) do { \
//    __PRAGMA_PUSH_NO_EXTRA_ARG_WARNINGS \
//    ThingAssertCondDescs(condition, desc, ##__VA_ARGS__); \
//    __PRAGMA_POP_NO_EXTRA_ARG_WARNINGS \
//} while(0)
//
///* replace apple assert */
//#undef NSCAssert
//#define NSCAssert(condition, desc, ...)  do { \
//    __PRAGMA_PUSH_NO_EXTRA_ARG_WARNINGS \
//    ThingAssertCondDescs(condition, desc, ##__VA_ARGS__); \
//    __PRAGMA_POP_NO_EXTRA_ARG_WARNINGS \
//} while(0)

#endif /* __OPTIMIZE__ */

#endif /* ThingAssert_h */
