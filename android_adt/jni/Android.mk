###from krkrm_v32.5_krkrz_dev_multi_platform_rollback_20170801_display_good.7z
###from krkr2-no-vcpkg
#LoadJXR.cpp

##-DBOOST_LOCALE_NO_LIB 
##-DBOOST_LOCALE_STATIC_LINK 
##-DNDEBUG 
##-DONIG_STATIC 
##-DSPDLOG_COMPILED_LIB 
##-DSPDLOG_FMT_EXTERNAL 
##-I/home/wmt/KrKr2-Next/cpp/core/common 
##-I/home/wmt/KrKr2-Next/cpp/core/tjs2 
##-I/home/wmt/KrKr2-Next/build/cpp/core/tjs2/gen 
##-isystem /home/wmt/KrKr2-Next/build/vcpkg_installed/arm64-android/include 
##-g 
##-DANDROID 
##-fdata-sections 
##-ffunction-sections 
##-funwind-tables 
##-fstack-protector-strong 
##-no-canonical-prefixes 
##-D_FORTIFY_SOURCE=2 
##-Wformat 
##-Werror=format-security  
##-std=c++17 
##-fPIC 
##-Wno-inconsistent-missing-override 
##-fno-delete-null-pointer-checks 
##-pthread

# -DTVP_ENABLE_EXECUTE_AT_EXCEPTION
# -DTVP_LOG_TO_COMMANDLINE_CONSOLE

#$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo
#$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/android
#$(LOCAL_PATH)/../../cpp/external/opusfile/include
#$(LOCAL_PATH)/../../cpp/external/opus/include

#-DKRKR_USE_ANGLE

#$(NDK)/source/cpufeatures




LOCAL_PATH := $(call my-dir)

####################################




include $(CLEAR_VARS)

LOCAL_MODULE    := core_tjs

LOCAL_CFLAGS += \
				-DMY_USE_MINLIB=1 \
				-DMY_USE_MINLIB_SDL2=1 \
				-DMY_USE_DISABLE_CRASH_SIGNAL_HANDLE=1 \
				-DUNICODE \
				-DTJS_TEXT_OUT_CRLF \
				-DTJS_JP_LOCALIZED \
				-DENGINE_API_BUILD_SHARED \
				-DENGINE_API_USE_KRKR2_RUNTIME

LOCAL_CPPFLAGS += -std=c++17 
#FIXME:added
LOCAL_CPPFLAGS += -Wno-null-dereference -Wno-tautological-constant-out-of-range-compare

#cpp/core/tjs2/tjsString.h:394:32: error: format string is not a string
#      literal (potentially insecure) [-Werror,-Wformat-security]
#            snprintf(str, 255, format, args...);
#FIXME:added
LOCAL_CPPFLAGS += -Wno-format-security

LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES += \
$(LOCAL_PATH) \
$(LOCAL_PATH)/../../cpp/core/common \
$(LOCAL_PATH)/../../cpp/core/environ \
$(LOCAL_PATH)/../../cpp/core/environ/android \
$(LOCAL_PATH)/../../cpp/core/environ/win32 \
$(LOCAL_PATH)/../../cpp/core/tjs2 \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen \
$(LOCAL_PATH)/../../cpp/external/onig/src \
$(LOCAL_PATH)/../../cpp/external/lpng \
$(LOCAL_PATH)/../../cpp/external/freetype/include \
$(LOCAL_PATH)/../../cpp/external/glm \
$(LOCAL_PATH)/../../cpp/external/libogg-1.1.3/include \
$(LOCAL_PATH)/../../cpp/external/libvorbis-1.2.0/include \
$(LOCAL_PATH)/../../cpp/external/boost-1.88.0 \
$(LOCAL_PATH)/../../cpp/external/fmt-11.2.0/include \
$(LOCAL_PATH)/../../cpp/external/spdlog-1.15.3/include \
$(LOCAL_PATH)/../../cpp/external/highway-1.3.0 \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/include \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/src \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13 \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/core/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/imgproc/include \
$(LOCAL_PATH)/../../cpp/external/lz4-1.10.0/include \
$(LOCAL_PATH)/../../cpp/external/jxrlib-f752187/include \
$(LOCAL_PATH)/../../cpp/external/libbpg \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/include \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/android \
$(LOCAL_PATH)/../../cpp/external/vorbis-1.3.7/include \
$(LOCAL_PATH)/../../cpp/external/opusfile/include \
$(LOCAL_PATH)/../../cpp/external/opus/include \
$(LOCAL_PATH)/../../cpp/external/openal-soft-1.17.0/include \
$(LOCAL_PATH)/../../cpp/external/oboe-1.8.0/include \
$(LOCAL_PATH)/../../cpp/external/SDL2-2.0.10/include \
$(LOCAL_PATH)/../../cpp/external/tinyxml2-11.0.0 \
$(LOCAL_PATH)/../../cpp/external/uchardet-v0.0.8/include \
$(LOCAL_PATH)/../../cpp/external/zlib-1.3.1/contrib \
$(LOCAL_PATH)/../../cpp/core \
$(LOCAL_PATH)/../../cpp/core/base \
$(LOCAL_PATH)/../../cpp/core/base/impl \
$(LOCAL_PATH)/../../cpp/core/extension \
$(LOCAL_PATH)/../../cpp/core/sound \
$(LOCAL_PATH)/../../cpp/core/sound/win32 \
$(LOCAL_PATH)/../../cpp/core/movie \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg \
$(LOCAL_PATH)/../../cpp/core/utils \
$(LOCAL_PATH)/../../cpp/core/utils/encoding \
$(LOCAL_PATH)/../../cpp/core/utils/iconv \
$(LOCAL_PATH)/../../cpp/core/utils/win32 \
$(LOCAL_PATH)/../../cpp/core/visual \
$(LOCAL_PATH)/../../cpp/core/visual/simd \
$(LOCAL_PATH)/../../cpp/core/visual/gl \
$(LOCAL_PATH)/../../cpp/core/visual/ogl \
$(LOCAL_PATH)/../../cpp/core/visual/impl \
$(LOCAL_PATH)/../../cpp/core/plugin \
$(LOCAL_PATH)/../../cpp/plugins \
$(LOCAL_PATH)/../../bridge/engine_api/include


LOCAL_SRC_FILES := \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen/tjs.tab.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen/tjsdate.tab.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen/tjspp.tab.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsLex.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsNative.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsRandomGenerator.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsDebug.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsRegExp.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsBinarySerializer.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsInterCodeGen.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsObject.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsConstArrayData.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsUtils.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsException.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsDictionary.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsInterCodeExec.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsVariantString.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsScriptBlock.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsMath.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjs.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsMessage.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsDisassemble.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsDate.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsError.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsInterface.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsMT19937ar-cok.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsArray.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsByteCodeLoader.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsDateParser.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsGlobalStringMap.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsOctPack.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsNamespace.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsScriptCache.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsConfig.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsCompileControl.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsObjectExtendable.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsVariant.cpp \
$(LOCAL_PATH)/../../cpp/core/tjs2/tjsString.cpp \





include $(BUILD_STATIC_LIBRARY)

####################################
####################################

include $(CLEAR_VARS)

LOCAL_MODULE    := core_extension_visual_simd

LOCAL_CFLAGS += \
				-DMY_USE_MINLIB=1 \
				-DMY_USE_MINLIB_SDL2=1 \
				-DMY_USE_DISABLE_CRASH_SIGNAL_HANDLE=1 \
				-DUNICODE \
				-DTJS_TEXT_OUT_CRLF \
				-DTJS_JP_LOCALIZED \
				-DENGINE_API_BUILD_SHARED \
				-DENGINE_API_USE_KRKR2_RUNTIME

LOCAL_CPPFLAGS += -std=c++17 
#FIXME:added
LOCAL_CPPFLAGS += -Wno-null-dereference -Wno-tautological-constant-out-of-range-compare

LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES += \
$(LOCAL_PATH) \
$(LOCAL_PATH)/../../cpp/core/common \
$(LOCAL_PATH)/../../cpp/core/environ \
$(LOCAL_PATH)/../../cpp/core/environ/android \
$(LOCAL_PATH)/../../cpp/core/environ/win32 \
$(LOCAL_PATH)/../../cpp/core/tjs2 \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen \
$(LOCAL_PATH)/../../cpp/external/onig/src \
$(LOCAL_PATH)/../../cpp/external/lpng \
$(LOCAL_PATH)/../../cpp/external/freetype/include \
$(LOCAL_PATH)/../../cpp/external/glm \
$(LOCAL_PATH)/../../cpp/external/libogg-1.1.3/include \
$(LOCAL_PATH)/../../cpp/external/libvorbis-1.2.0/include \
$(LOCAL_PATH)/../../cpp/external/boost-1.88.0 \
$(LOCAL_PATH)/../../cpp/external/fmt-11.2.0/include \
$(LOCAL_PATH)/../../cpp/external/spdlog-1.15.3/include \
$(LOCAL_PATH)/../../cpp/external/highway-1.3.0 \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/include \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/src \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13 \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/core/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/imgproc/include \
$(LOCAL_PATH)/../../cpp/external/lz4-1.10.0/include \
$(LOCAL_PATH)/../../cpp/external/jxrlib-f752187/include \
$(LOCAL_PATH)/../../cpp/external/libbpg \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/include \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/android \
$(LOCAL_PATH)/../../cpp/external/vorbis-1.3.7/include \
$(LOCAL_PATH)/../../cpp/external/opusfile/include \
$(LOCAL_PATH)/../../cpp/external/opus/include \
$(LOCAL_PATH)/../../cpp/external/openal-soft-1.17.0/include \
$(LOCAL_PATH)/../../cpp/external/oboe-1.8.0/include \
$(LOCAL_PATH)/../../cpp/external/SDL2-2.0.10/include \
$(LOCAL_PATH)/../../cpp/external/tinyxml2-11.0.0 \
$(LOCAL_PATH)/../../cpp/external/uchardet-v0.0.8/include \
$(LOCAL_PATH)/../../cpp/external/zlib-1.3.1/contrib \
$(LOCAL_PATH)/../../cpp/core \
$(LOCAL_PATH)/../../cpp/core/base \
$(LOCAL_PATH)/../../cpp/core/base/impl \
$(LOCAL_PATH)/../../cpp/core/extension \
$(LOCAL_PATH)/../../cpp/core/sound \
$(LOCAL_PATH)/../../cpp/core/sound/win32 \
$(LOCAL_PATH)/../../cpp/core/movie \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg \
$(LOCAL_PATH)/../../cpp/core/utils \
$(LOCAL_PATH)/../../cpp/core/utils/encoding \
$(LOCAL_PATH)/../../cpp/core/utils/iconv \
$(LOCAL_PATH)/../../cpp/core/utils/win32 \
$(LOCAL_PATH)/../../cpp/core/visual \
$(LOCAL_PATH)/../../cpp/core/visual/simd \
$(LOCAL_PATH)/../../cpp/core/visual/gl \
$(LOCAL_PATH)/../../cpp/core/visual/ogl \
$(LOCAL_PATH)/../../cpp/core/visual/impl \
$(LOCAL_PATH)/../../cpp/core/plugin \
$(LOCAL_PATH)/../../cpp/plugins \
$(LOCAL_PATH)/../../bridge/engine_api/include


LOCAL_SRC_FILES += \
$(LOCAL_PATH)/../../cpp/core/visual/simd/tvpgl_simd_init.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/simd/tvpgl_simd_copy.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/simd/tvpgl_simd_alpha_blend.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/simd/tvpgl_simd_arithmetic_blend.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/simd/tvpgl_simd_const_blend.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/simd/tvpgl_simd_premul_blend.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/simd/tvpgl_simd_ps_blend.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/simd/tvpgl_simd_ps_blend2.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/simd/tvpgl_simd_convert.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/simd/tvpgl_simd_misc.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/simd/tvpgl_simd_blur.cpp \


LOCAL_SRC_FILES += \
$(LOCAL_PATH)/../../cpp/core/extension/Extension.cpp \





include $(BUILD_STATIC_LIBRARY)

####################################
####################################

include $(CLEAR_VARS)

LOCAL_MODULE    := core_utils

LOCAL_CFLAGS += \
				-DMY_USE_MINLIB=1 \
				-DMY_USE_MINLIB_SDL2=1 \
				-DMY_USE_DISABLE_CRASH_SIGNAL_HANDLE=1 \
				-DUNICODE \
				-DTJS_TEXT_OUT_CRLF \
				-DTJS_JP_LOCALIZED \
				-DENGINE_API_BUILD_SHARED \
				-DENGINE_API_USE_KRKR2_RUNTIME

LOCAL_CPPFLAGS += -std=c++17 
#FIXME:added
LOCAL_CPPFLAGS += -Wno-null-dereference -Wno-tautological-constant-out-of-range-compare

LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES += \
$(LOCAL_PATH) \
$(LOCAL_PATH)/../../cpp/core/common \
$(LOCAL_PATH)/../../cpp/core/environ \
$(LOCAL_PATH)/../../cpp/core/environ/android \
$(LOCAL_PATH)/../../cpp/core/environ/win32 \
$(LOCAL_PATH)/../../cpp/core/tjs2 \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen \
$(LOCAL_PATH)/../../cpp/external/onig/src \
$(LOCAL_PATH)/../../cpp/external/lpng \
$(LOCAL_PATH)/../../cpp/external/freetype/include \
$(LOCAL_PATH)/../../cpp/external/glm \
$(LOCAL_PATH)/../../cpp/external/libogg-1.1.3/include \
$(LOCAL_PATH)/../../cpp/external/libvorbis-1.2.0/include \
$(LOCAL_PATH)/../../cpp/external/boost-1.88.0 \
$(LOCAL_PATH)/../../cpp/external/fmt-11.2.0/include \
$(LOCAL_PATH)/../../cpp/external/spdlog-1.15.3/include \
$(LOCAL_PATH)/../../cpp/external/highway-1.3.0 \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/include \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/src \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13 \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/core/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/imgproc/include \
$(LOCAL_PATH)/../../cpp/external/lz4-1.10.0/include \
$(LOCAL_PATH)/../../cpp/external/jxrlib-f752187/include \
$(LOCAL_PATH)/../../cpp/external/libbpg \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/include \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/android \
$(LOCAL_PATH)/../../cpp/external/vorbis-1.3.7/include \
$(LOCAL_PATH)/../../cpp/external/opusfile/include \
$(LOCAL_PATH)/../../cpp/external/opus/include \
$(LOCAL_PATH)/../../cpp/external/openal-soft-1.17.0/include \
$(LOCAL_PATH)/../../cpp/external/oboe-1.8.0/include \
$(LOCAL_PATH)/../../cpp/external/SDL2-2.0.10/include \
$(LOCAL_PATH)/../../cpp/external/tinyxml2-11.0.0 \
$(LOCAL_PATH)/../../cpp/external/uchardet-v0.0.8/include \
$(LOCAL_PATH)/../../cpp/external/zlib-1.3.1/contrib \
$(LOCAL_PATH)/../../cpp/core \
$(LOCAL_PATH)/../../cpp/core/base \
$(LOCAL_PATH)/../../cpp/core/base/impl \
$(LOCAL_PATH)/../../cpp/core/extension \
$(LOCAL_PATH)/../../cpp/core/sound \
$(LOCAL_PATH)/../../cpp/core/sound/win32 \
$(LOCAL_PATH)/../../cpp/core/movie \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg \
$(LOCAL_PATH)/../../cpp/core/utils \
$(LOCAL_PATH)/../../cpp/core/utils/encoding \
$(LOCAL_PATH)/../../cpp/core/utils/iconv \
$(LOCAL_PATH)/../../cpp/core/utils/win32 \
$(LOCAL_PATH)/../../cpp/core/visual \
$(LOCAL_PATH)/../../cpp/core/visual/simd \
$(LOCAL_PATH)/../../cpp/core/visual/gl \
$(LOCAL_PATH)/../../cpp/core/visual/ogl \
$(LOCAL_PATH)/../../cpp/core/visual/impl \
$(LOCAL_PATH)/../../cpp/core/plugin \
$(LOCAL_PATH)/../../cpp/plugins \
$(LOCAL_PATH)/../../bridge/engine_api/include 


LOCAL_SRC_FILES += \
$(LOCAL_PATH)/../../cpp/core/utils/ClipboardIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/DebugIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/MathAlgorithms_Default.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/md5.c \
$(LOCAL_PATH)/../../cpp/core/utils/MiscUtility.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/PadIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/Random.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/RealFFT_Default.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/ThreadIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/TickCount.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/TimerIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/VelocityTracker.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/encoding/gbk2unicode.c \
$(LOCAL_PATH)/../../cpp/core/utils/encoding/jis2unicode.c \
$(LOCAL_PATH)/../../cpp/core/utils/win32/ClipboardImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/win32/DebugImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/win32/PadImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/win32/ThreadImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/win32/TimerImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/utils/win32/TVPTimer.cpp \





include $(BUILD_STATIC_LIBRARY)

####################################
####################################

include $(CLEAR_VARS)

LOCAL_MODULE    := core_visual

LOCAL_CFLAGS += \
				-DMY_USE_MINLIB=1 \
				-DMY_USE_MINLIB_SDL2=1 \
				-DMY_USE_DISABLE_CRASH_SIGNAL_HANDLE=1 \
				-DUNICODE \
				-DTJS_TEXT_OUT_CRLF \
				-DTJS_JP_LOCALIZED \
				-DENGINE_API_BUILD_SHARED \
				-DENGINE_API_USE_KRKR2_RUNTIME

LOCAL_CPPFLAGS += -std=c++17 
#FIXME:added
LOCAL_CPPFLAGS += -Wno-null-dereference -Wno-tautological-constant-out-of-range-compare

LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES += \
$(LOCAL_PATH) \
$(LOCAL_PATH)/../../cpp/core/common \
$(LOCAL_PATH)/../../cpp/core/environ \
$(LOCAL_PATH)/../../cpp/core/environ/android \
$(LOCAL_PATH)/../../cpp/core/environ/win32 \
$(LOCAL_PATH)/../../cpp/core/tjs2 \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen \
$(LOCAL_PATH)/../../cpp/external/onig/src \
$(LOCAL_PATH)/../../cpp/external/lpng \
$(LOCAL_PATH)/../../cpp/external/freetype/include \
$(LOCAL_PATH)/../../cpp/external/glm \
$(LOCAL_PATH)/../../cpp/external/libogg-1.1.3/include \
$(LOCAL_PATH)/../../cpp/external/libvorbis-1.2.0/include \
$(LOCAL_PATH)/../../cpp/external/boost-1.88.0 \
$(LOCAL_PATH)/../../cpp/external/fmt-11.2.0/include \
$(LOCAL_PATH)/../../cpp/external/spdlog-1.15.3/include \
$(LOCAL_PATH)/../../cpp/external/highway-1.3.0 \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/include \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/src \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13 \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/core/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/imgproc/include \
$(LOCAL_PATH)/../../cpp/external/lz4-1.10.0/include \
$(LOCAL_PATH)/../../cpp/external/jxrlib-f752187/include \
$(LOCAL_PATH)/../../cpp/external/libbpg \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/include \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/android \
$(LOCAL_PATH)/../../cpp/external/vorbis-1.3.7/include \
$(LOCAL_PATH)/../../cpp/external/opusfile/include \
$(LOCAL_PATH)/../../cpp/external/opus/include \
$(LOCAL_PATH)/../../cpp/external/openal-soft-1.17.0/include \
$(LOCAL_PATH)/../../cpp/external/oboe-1.8.0/include \
$(LOCAL_PATH)/../../cpp/external/SDL2-2.0.10/include \
$(LOCAL_PATH)/../../cpp/external/tinyxml2-11.0.0 \
$(LOCAL_PATH)/../../cpp/external/uchardet-v0.0.8/include \
$(LOCAL_PATH)/../../cpp/external/zlib-1.3.1/contrib \
$(LOCAL_PATH)/../../cpp/core \
$(LOCAL_PATH)/../../cpp/core/base \
$(LOCAL_PATH)/../../cpp/core/base/impl \
$(LOCAL_PATH)/../../cpp/core/extension \
$(LOCAL_PATH)/../../cpp/core/sound \
$(LOCAL_PATH)/../../cpp/core/sound/win32 \
$(LOCAL_PATH)/../../cpp/core/movie \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg \
$(LOCAL_PATH)/../../cpp/core/utils \
$(LOCAL_PATH)/../../cpp/core/utils/encoding \
$(LOCAL_PATH)/../../cpp/core/utils/iconv \
$(LOCAL_PATH)/../../cpp/core/utils/win32 \
$(LOCAL_PATH)/../../cpp/core/visual \
$(LOCAL_PATH)/../../cpp/core/visual/simd \
$(LOCAL_PATH)/../../cpp/core/visual/gl \
$(LOCAL_PATH)/../../cpp/core/visual/ogl \
$(LOCAL_PATH)/../../cpp/core/visual/impl \
$(LOCAL_PATH)/../../cpp/core/plugin \
$(LOCAL_PATH)/../../cpp/plugins \
$(LOCAL_PATH)/../../bridge/engine_api/include 



LOCAL_SRC_FILES += \
$(LOCAL_PATH)/../../cpp/core/visual/LoadWEBP.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/TransIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/MenuItemIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/SaveTLG5.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/FontSystem.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/LoadPVRv3.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/RectItf.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/VideoOvlIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/LayerBitmapIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/FontImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/RenderManager.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/LoadJPEG.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/GraphicsLoaderIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/SaveTLG6.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/FreeType.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/LoadJXR.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/ImageFunction.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/tvpgl.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/LoadTLG.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/LayerTreeOwnerImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/GraphicsLoadThread.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/LayerManager.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/PrerenderedFont.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/LoadBPG.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/WindowIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/FreeTypeFontRasterizer.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/LoadPNG.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/LayerIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/ComplexRect.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/CharacterData.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/BitmapLayerTreeOwner.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/BitmapIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/argb.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/LoadAMV.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/gl/blend_function.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/gl/ResampleImage.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/gl/WeightFunctor.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/ogl/astcrt.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/ogl/etcpak.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/ogl/imagepacker.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/ogl/pvrtc.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/ogl/PVRTDecompress.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/ogl/RenderManager_ogl.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/ogl/krkr_gl.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/ogl/krkr_egl_context.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/BasicDrawDevice.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/BitmapBitsAlloc.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/BitmapInfomation.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/DInputMgn.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/DrawDevice.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/GraphicsLoaderImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/LayerBitmapImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/LayerImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/MenuItemImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/PassThroughDrawDevice.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/TVPScreen.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/VideoOvlImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/visual/impl/WindowImpl.cpp \






include $(BUILD_STATIC_LIBRARY)

####################################
####################################

include $(CLEAR_VARS)

LOCAL_MODULE    := core_sound

LOCAL_CFLAGS += \
				-DMY_USE_MINLIB=1 \
				-DMY_USE_MINLIB_SDL2=1 \
				-DMY_USE_DISABLE_CRASH_SIGNAL_HANDLE=1 \
				-DUNICODE \
				-DTJS_TEXT_OUT_CRLF \
				-DTJS_JP_LOCALIZED \
				-DENGINE_API_BUILD_SHARED \
				-DENGINE_API_USE_KRKR2_RUNTIME

LOCAL_CPPFLAGS += -std=c++17 
#FIXME:added
LOCAL_CPPFLAGS += -Wno-null-dereference -Wno-tautological-constant-out-of-range-compare

LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES += \
$(LOCAL_PATH) \
$(LOCAL_PATH)/../../cpp/core/common \
$(LOCAL_PATH)/../../cpp/core/environ \
$(LOCAL_PATH)/../../cpp/core/environ/android \
$(LOCAL_PATH)/../../cpp/core/environ/win32 \
$(LOCAL_PATH)/../../cpp/core/tjs2 \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen \
$(LOCAL_PATH)/../../cpp/external/onig/src \
$(LOCAL_PATH)/../../cpp/external/lpng \
$(LOCAL_PATH)/../../cpp/external/freetype/include \
$(LOCAL_PATH)/../../cpp/external/glm \
$(LOCAL_PATH)/../../cpp/external/libogg-1.1.3/include \
$(LOCAL_PATH)/../../cpp/external/libvorbis-1.2.0/include \
$(LOCAL_PATH)/../../cpp/external/boost-1.88.0 \
$(LOCAL_PATH)/../../cpp/external/fmt-11.2.0/include \
$(LOCAL_PATH)/../../cpp/external/spdlog-1.15.3/include \
$(LOCAL_PATH)/../../cpp/external/highway-1.3.0 \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/include \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/src \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13 \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/core/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/imgproc/include \
$(LOCAL_PATH)/../../cpp/external/lz4-1.10.0/include \
$(LOCAL_PATH)/../../cpp/external/jxrlib-f752187/include \
$(LOCAL_PATH)/../../cpp/external/libbpg \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/include \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/android \
$(LOCAL_PATH)/../../cpp/external/vorbis-1.3.7/include \
$(LOCAL_PATH)/../../cpp/external/opusfile/include \
$(LOCAL_PATH)/../../cpp/external/opus/include \
$(LOCAL_PATH)/../../cpp/external/openal-soft-1.17.0/include \
$(LOCAL_PATH)/../../cpp/external/oboe-1.8.0/include \
$(LOCAL_PATH)/../../cpp/external/SDL2-2.0.10/include \
$(LOCAL_PATH)/../../cpp/external/tinyxml2-11.0.0 \
$(LOCAL_PATH)/../../cpp/external/uchardet-v0.0.8/include \
$(LOCAL_PATH)/../../cpp/external/zlib-1.3.1/contrib \
$(LOCAL_PATH)/../../cpp/core \
$(LOCAL_PATH)/../../cpp/core/base \
$(LOCAL_PATH)/../../cpp/core/base/impl \
$(LOCAL_PATH)/../../cpp/core/extension \
$(LOCAL_PATH)/../../cpp/core/sound \
$(LOCAL_PATH)/../../cpp/core/sound/win32 \
$(LOCAL_PATH)/../../cpp/core/movie \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg \
$(LOCAL_PATH)/../../cpp/core/utils \
$(LOCAL_PATH)/../../cpp/core/utils/encoding \
$(LOCAL_PATH)/../../cpp/core/utils/iconv \
$(LOCAL_PATH)/../../cpp/core/utils/win32 \
$(LOCAL_PATH)/../../cpp/core/visual \
$(LOCAL_PATH)/../../cpp/core/visual/simd \
$(LOCAL_PATH)/../../cpp/core/visual/gl \
$(LOCAL_PATH)/../../cpp/core/visual/ogl \
$(LOCAL_PATH)/../../cpp/core/visual/impl \
$(LOCAL_PATH)/../../cpp/core/plugin \
$(LOCAL_PATH)/../../cpp/plugins \
$(LOCAL_PATH)/../../bridge/engine_api/include 



LOCAL_SRC_FILES += \
$(LOCAL_PATH)/../../cpp/core/sound/CDDAIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/FFWaveDecoder.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/MIDIIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/PhaseVocoderDSP.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/PhaseVocoderFilter.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/SoundBufferBaseIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/VorbisWaveDecoder.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/WaveFormatConverter.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/WaveIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/WaveLoopManager.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/WaveSegmentQueue.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/win32/CDDAImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/win32/MIDIImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/win32/SoundBufferBaseImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/win32/tvpsnd.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/win32/WaveImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/sound/win32/WaveMixer.cpp \






include $(BUILD_STATIC_LIBRARY)

####################################
####################################

include $(CLEAR_VARS)

LOCAL_MODULE    := core_movie

LOCAL_CFLAGS += \
				-DMY_USE_MINLIB=1 \
				-DMY_USE_MINLIB_SDL2=1 \
				-DMY_USE_DISABLE_CRASH_SIGNAL_HANDLE=1 \
				-DUNICODE \
				-DTJS_TEXT_OUT_CRLF \
				-DTJS_JP_LOCALIZED \
				-DENGINE_API_BUILD_SHARED \
				-DENGINE_API_USE_KRKR2_RUNTIME

LOCAL_CPPFLAGS += -std=c++17 
#FIXME:added
LOCAL_CPPFLAGS += -Wno-null-dereference -Wno-tautological-constant-out-of-range-compare

LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES += \
$(LOCAL_PATH) \
$(LOCAL_PATH)/../../cpp/core/common \
$(LOCAL_PATH)/../../cpp/core/environ \
$(LOCAL_PATH)/../../cpp/core/environ/android \
$(LOCAL_PATH)/../../cpp/core/environ/win32 \
$(LOCAL_PATH)/../../cpp/core/tjs2 \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen \
$(LOCAL_PATH)/../../cpp/external/onig/src \
$(LOCAL_PATH)/../../cpp/external/lpng \
$(LOCAL_PATH)/../../cpp/external/freetype/include \
$(LOCAL_PATH)/../../cpp/external/glm \
$(LOCAL_PATH)/../../cpp/external/libogg-1.1.3/include \
$(LOCAL_PATH)/../../cpp/external/libvorbis-1.2.0/include \
$(LOCAL_PATH)/../../cpp/external/boost-1.88.0 \
$(LOCAL_PATH)/../../cpp/external/fmt-11.2.0/include \
$(LOCAL_PATH)/../../cpp/external/spdlog-1.15.3/include \
$(LOCAL_PATH)/../../cpp/external/highway-1.3.0 \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/include \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/src \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13 \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/core/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/imgproc/include \
$(LOCAL_PATH)/../../cpp/external/lz4-1.10.0/include \
$(LOCAL_PATH)/../../cpp/external/jxrlib-f752187/include \
$(LOCAL_PATH)/../../cpp/external/libbpg \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/include \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/android \
$(LOCAL_PATH)/../../cpp/external/vorbis-1.3.7/include \
$(LOCAL_PATH)/../../cpp/external/opusfile/include \
$(LOCAL_PATH)/../../cpp/external/opus/include \
$(LOCAL_PATH)/../../cpp/external/openal-soft-1.17.0/include \
$(LOCAL_PATH)/../../cpp/external/oboe-1.8.0/include \
$(LOCAL_PATH)/../../cpp/external/SDL2-2.0.10/include \
$(LOCAL_PATH)/../../cpp/external/tinyxml2-11.0.0 \
$(LOCAL_PATH)/../../cpp/external/uchardet-v0.0.8/include \
$(LOCAL_PATH)/../../cpp/external/zlib-1.3.1/contrib \
$(LOCAL_PATH)/../../cpp/core \
$(LOCAL_PATH)/../../cpp/core/base \
$(LOCAL_PATH)/../../cpp/core/base/impl \
$(LOCAL_PATH)/../../cpp/core/extension \
$(LOCAL_PATH)/../../cpp/core/sound \
$(LOCAL_PATH)/../../cpp/core/sound/win32 \
$(LOCAL_PATH)/../../cpp/core/movie \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg \
$(LOCAL_PATH)/../../cpp/core/utils \
$(LOCAL_PATH)/../../cpp/core/utils/encoding \
$(LOCAL_PATH)/../../cpp/core/utils/iconv \
$(LOCAL_PATH)/../../cpp/core/utils/win32 \
$(LOCAL_PATH)/../../cpp/core/visual \
$(LOCAL_PATH)/../../cpp/core/visual/simd \
$(LOCAL_PATH)/../../cpp/core/visual/gl \
$(LOCAL_PATH)/../../cpp/core/visual/ogl \
$(LOCAL_PATH)/../../cpp/core/visual/impl \
$(LOCAL_PATH)/../../cpp/core/plugin \
$(LOCAL_PATH)/../../cpp/plugins \
$(LOCAL_PATH)/../../bridge/engine_api/include 



LOCAL_SRC_FILES += \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/AEChannelInfo.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/AEFactory.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/AEStreamInfo.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/AEUtil.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/AudioCodecFFmpeg.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/AudioCodecPassthrough.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/AudioDevice.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/BaseRenderer.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/BitstreamStats.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/Clock.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/CodecUtils.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/Demux.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/DemuxFFmpeg.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/DemuxPacket.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/FactoryCodec.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/InputStream.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/krffmpeg.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/KRMovieLayer.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/KRMoviePlayer.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/Message.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/MessageQueue.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/ProcessInfo.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/RenderFlags.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/StreamInfo.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/Thread.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/Timer.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/TimeUtils.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/VideoCodec.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/VideoCodecFFmpeg.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/VideoPlayer.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/VideoPlayerAudio.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/VideoPlayerVideo.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/VideoReferenceClock.cpp \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg/VideoRenderer.cpp \






include $(BUILD_STATIC_LIBRARY)

####################################
####################################

include $(CLEAR_VARS)

LOCAL_MODULE    := core_plugin_environ

LOCAL_CFLAGS += \
				-DMY_USE_MINLIB=1 \
				-DMY_USE_MINLIB_SDL2=1 \
				-DMY_USE_DISABLE_CRASH_SIGNAL_HANDLE=1 \
				-DUNICODE \
				-DTJS_TEXT_OUT_CRLF \
				-DTJS_JP_LOCALIZED \
				-DENGINE_API_BUILD_SHARED \
				-DENGINE_API_USE_KRKR2_RUNTIME

LOCAL_CPPFLAGS += -std=c++17 
#FIXME:added
LOCAL_CPPFLAGS += -Wno-null-dereference -Wno-tautological-constant-out-of-range-compare

LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES += \
$(LOCAL_PATH) \
$(LOCAL_PATH)/../../cpp/core/common \
$(LOCAL_PATH)/../../cpp/core/environ \
$(LOCAL_PATH)/../../cpp/core/environ/android \
$(LOCAL_PATH)/../../cpp/core/environ/win32 \
$(LOCAL_PATH)/../../cpp/core/tjs2 \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen \
$(LOCAL_PATH)/../../cpp/external/onig/src \
$(LOCAL_PATH)/../../cpp/external/lpng \
$(LOCAL_PATH)/../../cpp/external/freetype/include \
$(LOCAL_PATH)/../../cpp/external/glm \
$(LOCAL_PATH)/../../cpp/external/libogg-1.1.3/include \
$(LOCAL_PATH)/../../cpp/external/libvorbis-1.2.0/include \
$(LOCAL_PATH)/../../cpp/external/boost-1.88.0 \
$(LOCAL_PATH)/../../cpp/external/fmt-11.2.0/include \
$(LOCAL_PATH)/../../cpp/external/spdlog-1.15.3/include \
$(LOCAL_PATH)/../../cpp/external/highway-1.3.0 \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/include \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/src \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13 \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/core/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/imgproc/include \
$(LOCAL_PATH)/../../cpp/external/lz4-1.10.0/include \
$(LOCAL_PATH)/../../cpp/external/jxrlib-f752187/include \
$(LOCAL_PATH)/../../cpp/external/libbpg \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/include \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/android \
$(LOCAL_PATH)/../../cpp/external/vorbis-1.3.7/include \
$(LOCAL_PATH)/../../cpp/external/opusfile/include \
$(LOCAL_PATH)/../../cpp/external/opus/include \
$(LOCAL_PATH)/../../cpp/external/openal-soft-1.17.0/include \
$(LOCAL_PATH)/../../cpp/external/oboe-1.8.0/include \
$(LOCAL_PATH)/../../cpp/external/SDL2-2.0.10/include \
$(LOCAL_PATH)/../../cpp/external/tinyxml2-11.0.0 \
$(LOCAL_PATH)/../../cpp/external/uchardet-v0.0.8/include \
$(LOCAL_PATH)/../../cpp/external/zlib-1.3.1/contrib \
$(LOCAL_PATH)/../../cpp/core \
$(LOCAL_PATH)/../../cpp/core/base \
$(LOCAL_PATH)/../../cpp/core/base/impl \
$(LOCAL_PATH)/../../cpp/core/extension \
$(LOCAL_PATH)/../../cpp/core/sound \
$(LOCAL_PATH)/../../cpp/core/sound/win32 \
$(LOCAL_PATH)/../../cpp/core/movie \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg \
$(LOCAL_PATH)/../../cpp/core/utils \
$(LOCAL_PATH)/../../cpp/core/utils/encoding \
$(LOCAL_PATH)/../../cpp/core/utils/iconv \
$(LOCAL_PATH)/../../cpp/core/utils/win32 \
$(LOCAL_PATH)/../../cpp/core/visual \
$(LOCAL_PATH)/../../cpp/core/visual/simd \
$(LOCAL_PATH)/../../cpp/core/visual/gl \
$(LOCAL_PATH)/../../cpp/core/visual/ogl \
$(LOCAL_PATH)/../../cpp/core/visual/impl \
$(LOCAL_PATH)/../../cpp/core/plugin \
$(LOCAL_PATH)/../../cpp/plugins \
$(LOCAL_PATH)/../../bridge/engine_api/include 



LOCAL_SRC_FILES += \
$(LOCAL_PATH)/../../cpp/core/plugin/ncbind.cpp \
$(LOCAL_PATH)/../../cpp/core/plugin/PluginIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/plugin/PluginImpl.cpp \


LOCAL_SRC_FILES += \
$(LOCAL_PATH)/../../cpp/core/environ/Application.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/DetectCPU.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/DumpSend.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/EngineBootstrap.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/EngineLoop.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/XP3ArchiveRepack.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/android/AndroidUtils.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/android/KrkrJniHelper.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/linux/Platform.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/MainScene.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/ConfigManager/GlobalConfigManager.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/ConfigManager/IndividualConfigManager.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/ConfigManager/LocaleConfigManager.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/sdl/tvpsdl.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/stubs/ui_stubs.cpp \
$(LOCAL_PATH)/../../cpp/core/environ/win32/SystemControl.cpp \







include $(BUILD_STATIC_LIBRARY)

####################################
####################################

include $(CLEAR_VARS)

LOCAL_MODULE    := core_base

LOCAL_CFLAGS += \
				-DMY_USE_MINLIB=1 \
				-DMY_USE_MINLIB_SDL2=1 \
				-DMY_USE_DISABLE_CRASH_SIGNAL_HANDLE=1 \
				-DUNICODE \
				-DTJS_TEXT_OUT_CRLF \
				-DTJS_JP_LOCALIZED \
				-DENGINE_API_BUILD_SHARED \
				-DENGINE_API_USE_KRKR2_RUNTIME

LOCAL_CPPFLAGS += -std=c++17 
#FIXME:added
LOCAL_CPPFLAGS += -Wno-null-dereference -Wno-tautological-constant-out-of-range-compare

LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES += \
$(LOCAL_PATH) \
$(LOCAL_PATH)/../../cpp/core/common \
$(LOCAL_PATH)/../../cpp/core/environ \
$(LOCAL_PATH)/../../cpp/core/environ/android \
$(LOCAL_PATH)/../../cpp/core/environ/win32 \
$(LOCAL_PATH)/../../cpp/core/tjs2 \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen \
$(LOCAL_PATH)/../../cpp/external/onig/src \
$(LOCAL_PATH)/../../cpp/external/lpng \
$(LOCAL_PATH)/../../cpp/external/freetype/include \
$(LOCAL_PATH)/../../cpp/external/glm \
$(LOCAL_PATH)/../../cpp/external/libogg-1.1.3/include \
$(LOCAL_PATH)/../../cpp/external/libvorbis-1.2.0/include \
$(LOCAL_PATH)/../../cpp/external/boost-1.88.0 \
$(LOCAL_PATH)/../../cpp/external/fmt-11.2.0/include \
$(LOCAL_PATH)/../../cpp/external/spdlog-1.15.3/include \
$(LOCAL_PATH)/../../cpp/external/highway-1.3.0 \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/include \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/src \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13 \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/core/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/imgproc/include \
$(LOCAL_PATH)/../../cpp/external/lz4-1.10.0/include \
$(LOCAL_PATH)/../../cpp/external/jxrlib-f752187/include \
$(LOCAL_PATH)/../../cpp/external/libbpg \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/include \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/android \
$(LOCAL_PATH)/../../cpp/external/vorbis-1.3.7/include \
$(LOCAL_PATH)/../../cpp/external/opusfile/include \
$(LOCAL_PATH)/../../cpp/external/opus/include \
$(LOCAL_PATH)/../../cpp/external/openal-soft-1.17.0/include \
$(LOCAL_PATH)/../../cpp/external/oboe-1.8.0/include \
$(LOCAL_PATH)/../../cpp/external/SDL2-2.0.10/include \
$(LOCAL_PATH)/../../cpp/external/tinyxml2-11.0.0 \
$(LOCAL_PATH)/../../cpp/external/uchardet-v0.0.8/include \
$(LOCAL_PATH)/../../cpp/external/zlib-1.3.1/contrib \
$(LOCAL_PATH)/../../cpp/core \
$(LOCAL_PATH)/../../cpp/core/base \
$(LOCAL_PATH)/../../cpp/core/base/impl \
$(LOCAL_PATH)/../../cpp/core/extension \
$(LOCAL_PATH)/../../cpp/core/sound \
$(LOCAL_PATH)/../../cpp/core/sound/win32 \
$(LOCAL_PATH)/../../cpp/core/movie \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg \
$(LOCAL_PATH)/../../cpp/core/utils \
$(LOCAL_PATH)/../../cpp/core/utils/encoding \
$(LOCAL_PATH)/../../cpp/core/utils/iconv \
$(LOCAL_PATH)/../../cpp/core/utils/win32 \
$(LOCAL_PATH)/../../cpp/core/visual \
$(LOCAL_PATH)/../../cpp/core/visual/simd \
$(LOCAL_PATH)/../../cpp/core/visual/gl \
$(LOCAL_PATH)/../../cpp/core/visual/ogl \
$(LOCAL_PATH)/../../cpp/core/visual/impl \
$(LOCAL_PATH)/../../cpp/core/plugin \
$(LOCAL_PATH)/../../cpp/plugins \
$(LOCAL_PATH)/../../bridge/engine_api/include 



LOCAL_SRC_FILES += \
$(LOCAL_PATH)/../../cpp/core/base/7zArchive.cpp \
$(LOCAL_PATH)/../../cpp/core/base/BinaryStream.cpp \
$(LOCAL_PATH)/../../cpp/core/base/CharacterSet.cpp \
$(LOCAL_PATH)/../../cpp/core/base/EventIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/base/ScriptMgnIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/base/StorageIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/base/SysInitIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/base/SystemIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/base/TARArchive.cpp \
$(LOCAL_PATH)/../../cpp/core/base/TextStream.cpp \
$(LOCAL_PATH)/../../cpp/core/base/UtilStreams.cpp \
$(LOCAL_PATH)/../../cpp/core/base/XP3Archive.cpp \
$(LOCAL_PATH)/../../cpp/core/base/ZIPArchive.cpp \
$(LOCAL_PATH)/../../cpp/core/base/KAGParser.cpp \
$(LOCAL_PATH)/../../cpp/core/base/MsgIntf.cpp \
$(LOCAL_PATH)/../../cpp/core/base/impl/EventImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/base/impl/FileSelector.cpp \
$(LOCAL_PATH)/../../cpp/core/base/impl/NativeEventQueue.cpp \
$(LOCAL_PATH)/../../cpp/core/base/impl/ScriptMgnImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/base/impl/StorageImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/base/impl/SysInitImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/base/impl/SystemImpl.cpp \
$(LOCAL_PATH)/../../cpp/core/base/impl/MsgImpl.cpp \







include $(BUILD_STATIC_LIBRARY)

####################################
####################################

include $(CLEAR_VARS)

LOCAL_MODULE    := plugins

LOCAL_CFLAGS += \
				-DMY_USE_MINLIB=1 \
				-DMY_USE_MINLIB_SDL2=1 \
				-DMY_USE_DISABLE_CRASH_SIGNAL_HANDLE=1 \
				-DUNICODE \
				-DTJS_TEXT_OUT_CRLF \
				-DTJS_JP_LOCALIZED \
				-DENGINE_API_BUILD_SHARED \
				-DENGINE_API_USE_KRKR2_RUNTIME

LOCAL_CPPFLAGS += -std=c++17 
#FIXME:added
LOCAL_CPPFLAGS += -Wno-null-dereference -Wno-tautological-constant-out-of-range-compare

LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES += \
$(LOCAL_PATH) \
$(LOCAL_PATH)/../../cpp/core/common \
$(LOCAL_PATH)/../../cpp/core/environ \
$(LOCAL_PATH)/../../cpp/core/environ/android \
$(LOCAL_PATH)/../../cpp/core/environ/win32 \
$(LOCAL_PATH)/../../cpp/core/tjs2 \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen \
$(LOCAL_PATH)/../../cpp/external/onig/src \
$(LOCAL_PATH)/../../cpp/external/lpng \
$(LOCAL_PATH)/../../cpp/external/freetype/include \
$(LOCAL_PATH)/../../cpp/external/glm \
$(LOCAL_PATH)/../../cpp/external/libogg-1.1.3/include \
$(LOCAL_PATH)/../../cpp/external/libvorbis-1.2.0/include \
$(LOCAL_PATH)/../../cpp/external/boost-1.88.0 \
$(LOCAL_PATH)/../../cpp/external/fmt-11.2.0/include \
$(LOCAL_PATH)/../../cpp/external/spdlog-1.15.3/include \
$(LOCAL_PATH)/../../cpp/external/highway-1.3.0 \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/include \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/src \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13 \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/core/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/imgproc/include \
$(LOCAL_PATH)/../../cpp/external/lz4-1.10.0/include \
$(LOCAL_PATH)/../../cpp/external/jxrlib-f752187/include \
$(LOCAL_PATH)/../../cpp/external/libbpg \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/include \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/android \
$(LOCAL_PATH)/../../cpp/external/vorbis-1.3.7/include \
$(LOCAL_PATH)/../../cpp/external/opusfile/include \
$(LOCAL_PATH)/../../cpp/external/opus/include \
$(LOCAL_PATH)/../../cpp/external/openal-soft-1.17.0/include \
$(LOCAL_PATH)/../../cpp/external/oboe-1.8.0/include \
$(LOCAL_PATH)/../../cpp/external/SDL2-2.0.10/include \
$(LOCAL_PATH)/../../cpp/external/tinyxml2-11.0.0 \
$(LOCAL_PATH)/../../cpp/external/uchardet-v0.0.8/include \
$(LOCAL_PATH)/../../cpp/external/zlib-1.3.1/contrib \
$(LOCAL_PATH)/../../cpp/core \
$(LOCAL_PATH)/../../cpp/core/base \
$(LOCAL_PATH)/../../cpp/core/base/impl \
$(LOCAL_PATH)/../../cpp/core/extension \
$(LOCAL_PATH)/../../cpp/core/sound \
$(LOCAL_PATH)/../../cpp/core/sound/win32 \
$(LOCAL_PATH)/../../cpp/core/movie \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg \
$(LOCAL_PATH)/../../cpp/core/utils \
$(LOCAL_PATH)/../../cpp/core/utils/encoding \
$(LOCAL_PATH)/../../cpp/core/utils/iconv \
$(LOCAL_PATH)/../../cpp/core/utils/win32 \
$(LOCAL_PATH)/../../cpp/core/visual \
$(LOCAL_PATH)/../../cpp/core/visual/simd \
$(LOCAL_PATH)/../../cpp/core/visual/gl \
$(LOCAL_PATH)/../../cpp/core/visual/ogl \
$(LOCAL_PATH)/../../cpp/core/visual/impl \
$(LOCAL_PATH)/../../cpp/core/plugin \
$(LOCAL_PATH)/../../cpp/plugins \
$(LOCAL_PATH)/../../bridge/engine_api/include 



LOCAL_SRC_FILES += \
$(LOCAL_PATH)/../../cpp/plugins/scriptsEx.cpp \
$(LOCAL_PATH)/../../cpp/plugins/win32dialog.cpp \
$(LOCAL_PATH)/../../cpp/plugins/dirlist.cpp \
$(LOCAL_PATH)/../../cpp/plugins/csvParser.cpp \
$(LOCAL_PATH)/../../cpp/plugins/layerExMovie.cpp \
$(LOCAL_PATH)/../../cpp/plugins/varfile.cpp \
$(LOCAL_PATH)/../../cpp/plugins/saveStruct.cpp \
$(LOCAL_PATH)/../../cpp/plugins/getabout.cpp \
$(LOCAL_PATH)/../../cpp/plugins/addFont.cpp \
$(LOCAL_PATH)/../../cpp/plugins/wutcwf.cpp \
$(LOCAL_PATH)/../../cpp/plugins/windowEx.cpp \
$(LOCAL_PATH)/../../cpp/plugins/getSample.cpp \
$(LOCAL_PATH)/../../cpp/plugins/layerExPerspective.cpp \
$(LOCAL_PATH)/../../cpp/plugins/fftgraph.cpp \
$(LOCAL_PATH)/../../cpp/plugins/LayerExBase.cpp \
$(LOCAL_PATH)/../../cpp/plugins/xp3filter.cpp \
$(LOCAL_PATH)/../../cpp/plugins/extrans.cpp \
$(LOCAL_PATH)/../../cpp/plugins/textrender.cpp \
$(LOCAL_PATH)/../../cpp/plugins/alphamovie.cpp \
$(LOCAL_PATH)/../../cpp/plugins/layerExBTOA.cpp \
$(LOCAL_PATH)/../../cpp/plugins/layerExImage.cpp \
$(LOCAL_PATH)/../../cpp/plugins/layerExRaster.cpp \
$(LOCAL_PATH)/../../cpp/plugins/layerExAreaAverage.cpp \
$(LOCAL_PATH)/../../cpp/plugins/layerExLongExposure.cpp \
$(LOCAL_PATH)/../../cpp/plugins/krkrgles.cpp \
$(LOCAL_PATH)/../../cpp/plugins/drawDeviceD2DCompat.cpp \
$(LOCAL_PATH)/../../cpp/plugins/wfBasicEffectCompat.cpp \
$(LOCAL_PATH)/../../cpp/plugins/wfTypicalDSPCompat.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psdfile/main.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psdfile/psdclass.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psdfile/psdclass_loadmem.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psdfile/psdclass_loadstream.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psdfile/psdclass_loadstreambase.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/main.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/PSBValue.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/PSBFile.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/PSBMedia.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/types/PimgType.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/types/MotionType.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/types/ScnType.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/types/ImageType.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/types/MmoType.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/types/ArchiveType.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/types/SoundArchiveType.cpp \
$(LOCAL_PATH)/../../cpp/plugins/psbfile/resources/ImageMetadata.cpp \
$(LOCAL_PATH)/../../cpp/plugins/layerex_draw/general/main.cpp \
$(LOCAL_PATH)/../../cpp/plugins/layerex_draw/general/LayerExDraw.cpp \
$(LOCAL_PATH)/../../cpp/plugins/layerex_draw/general/DrawPath.cpp \
$(LOCAL_PATH)/../../cpp/plugins/motionplayer/main.cpp \
$(LOCAL_PATH)/../../cpp/plugins/motionplayer/EmotePlayer.cpp \
$(LOCAL_PATH)/../../cpp/plugins/motionplayer/Player.cpp \
$(LOCAL_PATH)/../../cpp/plugins/motionplayer/ResourceManager.cpp \
$(LOCAL_PATH)/../../cpp/plugins/kagparserex/kagparserex_plugin.cpp \
$(LOCAL_PATH)/../../cpp/plugins/fstat/main.cpp \







include $(BUILD_STATIC_LIBRARY)

####################################

include $(CLEAR_VARS)

LOCAL_MODULE    := engine_api

LOCAL_CFLAGS += \
				-DMY_USE_MINLIB=1 \
				-DMY_USE_MINLIB_SDL2=1 \
				-DMY_USE_DISABLE_CRASH_SIGNAL_HANDLE=1 \
				-DUNICODE \
				-DTJS_TEXT_OUT_CRLF \
				-DTJS_JP_LOCALIZED \
				-DENGINE_API_BUILD_SHARED \
				-DENGINE_API_USE_KRKR2_RUNTIME

LOCAL_CPPFLAGS += -std=c++17 
#FIXME:added
LOCAL_CPPFLAGS += -Wno-null-dereference -Wno-tautological-constant-out-of-range-compare

LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES += \
$(LOCAL_PATH) \
$(LOCAL_PATH)/../../cpp/core/common \
$(LOCAL_PATH)/../../cpp/core/environ \
$(LOCAL_PATH)/../../cpp/core/environ/android \
$(LOCAL_PATH)/../../cpp/core/environ/win32 \
$(LOCAL_PATH)/../../cpp/core/tjs2 \
$(LOCAL_PATH)/../../cpp/core/tjs2/gen \
$(LOCAL_PATH)/../../cpp/external/onig/src \
$(LOCAL_PATH)/../../cpp/external/lpng \
$(LOCAL_PATH)/../../cpp/external/freetype/include \
$(LOCAL_PATH)/../../cpp/external/glm \
$(LOCAL_PATH)/../../cpp/external/libogg-1.1.3/include \
$(LOCAL_PATH)/../../cpp/external/libvorbis-1.2.0/include \
$(LOCAL_PATH)/../../cpp/external/boost-1.88.0 \
$(LOCAL_PATH)/../../cpp/external/fmt-11.2.0/include \
$(LOCAL_PATH)/../../cpp/external/spdlog-1.15.3/include \
$(LOCAL_PATH)/../../cpp/external/highway-1.3.0 \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/include \
$(LOCAL_PATH)/../../cpp/external/libwebp-1.0.0/src \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13 \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/core/include \
$(LOCAL_PATH)/../../cpp/external/opencv-2.4.13/modules/imgproc/include \
$(LOCAL_PATH)/../../cpp/external/lz4-1.10.0/include \
$(LOCAL_PATH)/../../cpp/external/jxrlib-f752187/include \
$(LOCAL_PATH)/../../cpp/external/libbpg \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/include \
$(LOCAL_PATH)/../../cpp/external/libjpeg-turbo/android \
$(LOCAL_PATH)/../../cpp/external/vorbis-1.3.7/include \
$(LOCAL_PATH)/../../cpp/external/opusfile/include \
$(LOCAL_PATH)/../../cpp/external/opus/include \
$(LOCAL_PATH)/../../cpp/external/openal-soft-1.17.0/include \
$(LOCAL_PATH)/../../cpp/external/oboe-1.8.0/include \
$(LOCAL_PATH)/../../cpp/external/SDL2-2.0.10/include \
$(LOCAL_PATH)/../../cpp/external/tinyxml2-11.0.0 \
$(LOCAL_PATH)/../../cpp/external/uchardet-v0.0.8/include \
$(LOCAL_PATH)/../../cpp/external/zlib-1.3.1/contrib \
$(LOCAL_PATH)/../../cpp/core \
$(LOCAL_PATH)/../../cpp/core/base \
$(LOCAL_PATH)/../../cpp/core/base/impl \
$(LOCAL_PATH)/../../cpp/core/extension \
$(LOCAL_PATH)/../../cpp/core/sound \
$(LOCAL_PATH)/../../cpp/core/sound/win32 \
$(LOCAL_PATH)/../../cpp/core/movie \
$(LOCAL_PATH)/../../cpp/core/movie/ffmpeg \
$(LOCAL_PATH)/../../cpp/core/utils \
$(LOCAL_PATH)/../../cpp/core/utils/encoding \
$(LOCAL_PATH)/../../cpp/core/utils/iconv \
$(LOCAL_PATH)/../../cpp/core/utils/win32 \
$(LOCAL_PATH)/../../cpp/core/visual \
$(LOCAL_PATH)/../../cpp/core/visual/simd \
$(LOCAL_PATH)/../../cpp/core/visual/gl \
$(LOCAL_PATH)/../../cpp/core/visual/ogl \
$(LOCAL_PATH)/../../cpp/core/visual/impl \
$(LOCAL_PATH)/../../cpp/core/plugin \
$(LOCAL_PATH)/../../cpp/plugins \
$(LOCAL_PATH)/../../bridge/engine_api/include 




LOCAL_SRC_FILES += \
$(LOCAL_PATH)/../../bridge/engine_api/src/engine_api.cpp \
$(LOCAL_PATH)/../../platforms/android/cpp/krkr2_android.cpp \
$(LOCAL_PATH)/org_github_krkr2_flutter_engine_bridge_EngineBindings.cpp


ifneq ($(filter $(TARGET_ARCH_ABI), x86_64 x86),)
endif

LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM -lGLESv2 -lOpenSLES -lz 
#-latomic

LOCAL_WHOLE_STATIC_LIBRARIES += core_tjs core_extension_visual_simd core_utils core_visual core_sound core_movie core_plugin_environ core_base plugins 
LOCAL_WHOLE_STATIC_LIBRARIES += libonig libpng libfreetype vorbis ogg libopusfile libopus opencv_core_imgproc oboe fmt webp tinyxml2 lz4 libjpeg-turbo uchardet libopenal SDL2
###bpg

LOCAL_STATIC_LIBRARIES := 
#LOCAL_STATIC_LIBRARIES += android_native_app_glue cpufeatures ndk_helper
#see blow call import-module

LOCAL_SHARED_LIBRARIES :=
LOCAL_SHARED_LIBRARIES += 
#SDL2 
#libopenal

include $(BUILD_SHARED_LIBRARY)

$(call import-module,external/freetype)
$(call import-module,external/libjpeg-turbo)
$(call import-module,external/onig)
$(call import-module,external/lpng)
$(call import-module,external/opusfile)
$(call import-module,external/opus)
###$(call import-module,external/libogg)

###$(call import-module,android/cpufeatures)
###$(call import-module,android/native_app_glue)
###$(call import-module,android/ndk_helper)

$(call import-module,external/opencv-2.4.13)
$(call import-module,external/SDL2-2.0.10)
$(call import-module,external/oboe-1.8.0)
$(call import-module,external/fmt-11.2.0)
$(call import-module,external/openal-soft-1.17.0)
$(call import-module,external/libwebp-1.0.0)
$(call import-module,external/tinyxml2-11.0.0)
$(call import-module,external/lz4-1.10.0)
###$(call import-module,external/libbpg)
$(call import-module,external/libogg-1.1.3)
$(call import-module,external/libvorbis-1.2.0)
$(call import-module,external/uchardet-v0.0.8)
