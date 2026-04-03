#ndk-build NDK_DEBUG=1 -j8

#gnustl_static tested, c++_static failed, stlport_static failed
APP_STL := c++_static
#APP_STL := c++_shared
#gnustl_static
#APP_STL := c++_static
#APP_STL := stlport_static

#android-24 tested, android-20 failed
APP_PLATFORM := android-24
#APP_PLATFORM := android-20

APP_CPPFLAGS := -frtti -std=c++17 
#-fsigned-char
#APP_LDFLAGS := -latomic

#ifeq ($(NDK_DEBUG),1)
############for more logcat info, see TVP_LOG_TO_COMMANDLINE_CONSOLE and TVPAddLog and __android_log_print, use 'adb logcat -s krkrz'
  APP_CPPFLAGS += -D_DEBUG
  APP_OPTIM := debug
#else
#  APP_CPPFLAGS += -DNDEBUG
#  APP_OPTIM := release
#endif

#don't use armeabi, see libjpeg-turbo
#APP_ABI := armeabi-v7a
APP_ABI := arm64-v8a

