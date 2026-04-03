## Xubuntu 20.04, VirtualBox
## (Not good for glfw3+gles) Ubuntu 25.04, VMware

## sudo apt update
## sudo apt install gedit lftp make gcc g++ pkg-config
## (Not need libstdc++-14-dev)
## sudo apt install libfmt-dev libonig-dev libspdlog-dev libwebp-dev libfreetype-dev libopencv-core-dev libopencv-imgproc-dev liblz4-dev libvorbis-dev libopusfile-dev libopenal-dev libsdl2-dev libgtk2.0-dev libtinyxml2-dev libuchardet-dev libglfw3-dev
## (Change libopencv-dev to libopencv-core-dev libopencv-imgproc-dev)
## (Not need libhwy-dev ?)
## sudo apt install libgles2-mesa-dev libegl1-mesa-dev mesa-utils 
## (Not need mesa-utils-extra)

## (On Ubuntu 25.04 in VMware, if make test, Failed to load module "canberra-gtk-module")
## sudo apt remove libcanberra-gtk3-module
## sudo apt install libcanberra-gtk3-module

## ([core] [warning] internal font file not found: NotoSansCJK-Regular.ttc)
## gedit ./cpp/core/visual/ogl/krkr_egl_context.cpp
## gedit platforms/linux/main.cpp 
## (gdb)
## egl.Initialize(
## egl.InitializeWithWindow(
## b krkr_egl_context.cpp:520
## b krkr_egl_context.cpp:111
##if (!eglMakeCurrent(display_, target, target, context_)) {

CC  := gcc
CPP := g++
AR  := ar cru
RANLIB := ranlib
RM := rm -rf

CPPFLAGS := 
#make verbose from xubuntu 20.04, wamsoft_krkrz_verbose.txt
#makefile from krkrsdl2_fork2

####CPPFLAGS += --target=aarch64-none-linux-android34 
####CPPFLAGS += --sysroot=/home/wmt/android-ndk-r27d/toolchains/llvm/prebuilt/linux-x86_64/sysroot 
#CPPFLAGS += -fPIC 
#CPPFLAGS += -g 
#
#CPPFLAGS += -DANDROID 
#CPPFLAGS += -D_FORTIFY_SOURCE=2 
#
#CPPFLAGS += -fdata-sections 
#CPPFLAGS += -ffunction-sections 
#CPPFLAGS += -funwind-tables 
#CPPFLAGS += -fstack-protector-strong 
#CPPFLAGS += -no-canonical-prefixes 
#CPPFLAGS += -Wformat 
#CPPFLAGS += -Werror=format-security  
#
#CPPFLAGS += -std=c++17 
#
####CPPFLAGS += -Xlinker 
####CPPFLAGS += --dependency-file=CMakeFiles/engine_api.dir/link.d 
####CPPFLAGS += -Wl,--build-id=sha1 
####CPPFLAGS += -Wl,--no-undefined-version 
####CPPFLAGS += -Wl,--fatal-warnings 
####CPPFLAGS += -Wl,--no-undefined -Qunused-arguments  
####CPPFLAGS += -shared 
####CPPFLAGS += -Wl,-soname,libengine_api.so 
####CPPFLAGS += -o libengine_api.so 

CPPFLAGS += -g3 -O0

CPPFLAGS += -fPIC 
CPPFLAGS += -fexceptions
#FIXME:added
CPPFLAGS += -Wno-null-dereference 
###-Wno-tautological-constant-out-of-range-compare

#cpp/core/tjs2/tjsString.h:394:32: error: format string is not a string
#      literal (potentially insecure) [-Werror,-Wformat-security]
#            snprintf(str, 255, format, args...);
#FIXME:added
CPPFLAGS += -Wno-format-security

#gtk2+
CPPFLAGS += -Wno-deprecated-declarations

#cpp/core/visual/ogl/RenderManager_ogl.cpp:165:12: error: 'fGetProcAddress' does not name a type
CPPFLAGS += -DLINUX 

CPPFLAGS += -DMY_USE_MINLIB=1
CPPFLAGS += -DMY_USE_MINLIB_SDL2=1
CPPFLAGS += -DMY_USE_DISABLE_CRASH_SIGNAL_HANDLE=1
CPPFLAGS += -DUNICODE
CPPFLAGS += -DTJS_TEXT_OUT_CRLF
CPPFLAGS += -DTJS_JP_LOCALIZED
CPPFLAGS += -DENGINE_API_BUILD_SHARED
CPPFLAGS += -DENGINE_API_USE_KRKR2_RUNTIME

####ubuntu25.04
###CPPFLAGS += -I/usr/include/c++/14
CPPFLAGS += -I/usr/include/freetype2
CPPFLAGS += -I/usr/include/opencv4
#for opusfile
CPPFLAGS += -I/usr/include/opus
CPPFLAGS += -I/usr/include/SDL2
CPPFLAGS += -I/usr/include/gtk-2.0
CPPFLAGS += -I/usr/include/glib-2.0
CPPFLAGS += -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
CPPFLAGS += -I/usr/include/cairo
CPPFLAGS += -I/usr/include/pango-1.0
CPPFLAGS += -I/usr/include/harfbuzz
CPPFLAGS += -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include
CPPFLAGS += -I/usr/include/gdk-pixbuf-2.0
CPPFLAGS += -I/usr/include/atk-1.0
CPPFLAGS += -I/usr/include/uchardet

#miss cpp/core/common
CPPFLAGS += -Icpp/external/highway-1.3.0/
CPPFLAGS += -Icpp/core/common
CPPFLAGS += -Icpp/core/environ/
CPPFLAGS += -Icpp/core/environ/android
CPPFLAGS += -Icpp/core/environ/win32
CPPFLAGS += -Icpp/core/tjs2
CPPFLAGS += -Icpp/core/tjs2/gen
###CPPFLAGS += -Icpp/external/onig/src
###CPPFLAGS += -Icpp/external/lpng
###CPPFLAGS += -Icpp/external/freetype/include
###CPPFLAGS += -Icpp/external/glm
###CPPFLAGS += -Icpp/external/libogg-1.1.3/include
###CPPFLAGS += -Icpp/external/libvorbis-1.2.0/include
###CPPFLAGS += -Icpp/external/boost-1.88.0
###CPPFLAGS += -Icpp/external/fmt-11.2.0/include
###CPPFLAGS += -Icpp/external/spdlog-1.15.3/include
###CPPFLAGS += -Icpp/external/highway-1.3.0
###CPPFLAGS += -Icpp/external/libwebp-1.0.0/include
###CPPFLAGS += -Icpp/external/libwebp-1.0.0/src
###CPPFLAGS += -Icpp/external/opencv-2.4.13
###CPPFLAGS += -Icpp/external/opencv-2.4.13/include
###CPPFLAGS += -Icpp/external/opencv-2.4.13/modules/core/include
###CPPFLAGS += -Icpp/external/opencv-2.4.13/modules/imgproc/include
###CPPFLAGS += -Icpp/external/lz4-1.10.0/include
###CPPFLAGS += -Icpp/external/jxrlib-f752187/include
###CPPFLAGS += -Icpp/external/libbpg
###CPPFLAGS += -Icpp/external/libjpeg-turbo
###CPPFLAGS += -Icpp/external/libjpeg-turbo/include
###CPPFLAGS += -Icpp/external/libjpeg-turbo/android
###CPPFLAGS += -Icpp/external/vorbis-1.3.7/include
###CPPFLAGS += -Icpp/external/opusfile/include
###CPPFLAGS += -Icpp/external/opus/include
###CPPFLAGS += -Icpp/external/openal-soft-1.17.0/include
###CPPFLAGS += -Icpp/external/oboe-1.8.0/include
###CPPFLAGS += -Icpp/external/SDL2-2.0.10/include
###CPPFLAGS += -Icpp/external/tinyxml2-11.0.0
###CPPFLAGS += -Icpp/external/uchardet-v0.0.8/include
###CPPFLAGS += -Icpp/external/zlib-1.3.1/contrib
CPPFLAGS += -Icpp/core
CPPFLAGS += -Icpp/core/base
CPPFLAGS += -Icpp/core/base/impl
CPPFLAGS += -Icpp/core/extension
CPPFLAGS += -Icpp/core/sound
CPPFLAGS += -Icpp/core/sound/win32
CPPFLAGS += -Icpp/core/movie
CPPFLAGS += -Icpp/core/movie/ffmpeg
CPPFLAGS += -Icpp/core/utils
CPPFLAGS += -Icpp/core/utils/encoding
CPPFLAGS += -Icpp/core/utils/iconv
CPPFLAGS += -Icpp/core/utils/win32
CPPFLAGS += -Icpp/core/visual
CPPFLAGS += -Icpp/core/visual/simd
CPPFLAGS += -Icpp/core/visual/gl
CPPFLAGS += -Icpp/core/visual/ogl
CPPFLAGS += -Icpp/core/visual/impl
CPPFLAGS += -Icpp/core/plugin
CPPFLAGS += -Icpp/plugins
CPPFLAGS += -Ibridge/engine_api/include

CPPFLAGS2 += -std=c++17 
#CPPFLAGS2 += -std=gnu++17 

LDFLAGS :=

#-L/home/wmt/KrKr2-Next/build/vcpkg_installed/arm64-android/lib/pkgconfig/../../lib  
#../../cpp/plugins/libkrkr2plugin.a 
#../../vcpkg_installed/arm64-android/debug/lib/libEGL_angle.a 
#../../vcpkg_installed/arm64-android/debug/lib/libGLESv2_angle.a 
#-llog 
#-landroid 
#
#../../vcpkg_installed/arm64-android/debug/lib/libuchardet.a 
#../../vcpkg_installed/arm64-android/debug/lib/libunrar.a 
#../../vcpkg_installed/arm64-android/debug/lib/libarchive.a 
#../../vcpkg_installed/arm64-android/debug/lib/libxml2.a 
#../../vcpkg_installed/arm64-android/debug/lib/libzstd.a 
#../../vcpkg_installed/arm64-android/debug/lib/libSDL2main.a 
#../../vcpkg_installed/arm64-android/debug/lib/libSDL2.so 
#../../vcpkg_installed/arm64-android/debug/lib/libminizip.a 
#../../vcpkg_installed/arm64-android/lib/libz.a 
#../../vcpkg_installed/arm64-android/debug/lib/lib7zip.a
#../../vcpkg_installed/arm64-android/debug/lib/libminizip.a 
#../../vcpkg_installed/arm64-android/lib/libz.a 
#../../vcpkg_installed/arm64-android/debug/lib/libtinyxml2.a 
#../../vcpkg_installed/arm64-android/lib/liboboe.a 
#../../vcpkg_installed/arm64-android/debug/lib/libvorbisfile.a 
#../../vcpkg_installed/arm64-android/debug/lib/libvorbisenc.a
#../../vcpkg_installed/arm64-android/debug/lib/libvorbis.a 
#../../vcpkg_installed/arm64-android/debug/lib/libopusfile.a 
#../../vcpkg_installed/arm64-android/debug/lib/libopus.a 
#../../vcpkg_installed/arm64-android/debug/lib/libogg.a 
#../../vcpkg_installed/arm64-android/debug/lib/libopenal.a 
#
#-Wl,-z,max-page-size=16384 
#../../vcpkg_installed/arm64-android/debug/lib/libfmtd.a 
#
#../../cpp/external/libbpg/liblibbpg.a
#
#../../vcpkg_installed/arm64-android/lib/libavfilter.a 
#../../vcpkg_installed/arm64-android/lib/libavformat.a 
#../../vcpkg_installed/arm64-android/lib/libavcodec.a 
#../../vcpkg_installed/arm64-android/lib/libswresample.a 
#../../vcpkg_installed/arm64-android/lib/libswscale.a 
#../../vcpkg_installed/arm64-android/lib/libavutil.a 
#../../vcpkg_installed/arm64-android/debug/lib/libiconv.a 
#../../vcpkg_installed/arm64-android/debug/lib/liblzma.a 
#../../vcpkg_installed/arm64-android/lib/libbz2.a 
#../../vcpkg_installed/arm64-android/debug/lib/libwebpdecoder.a 
#../../vcpkg_installed/arm64-android/debug/lib/libwebpdemux.a 
#../../vcpkg_installed/arm64-android/debug/lib/libwebp.a 
#../../vcpkg_installed/arm64-android/debug/lib/libsharpyuv.a 
#../../vcpkg_installed/arm64-android/debug/lib/libcpufeatures-webp.a 
#../../vcpkg_installed/arm64-android/debug/lib/libEGL_angle.a 
#../../vcpkg_installed/arm64-android/debug/lib/libGLESv2_angle.a 
#../../vcpkg_installed/arm64-android/debug/lib/ANGLE.a 
#../../vcpkg_installed/arm64-android/debug/lib/libSPIRV-Tools.a 
#../../vcpkg_installed/arm64-android/lib/libjxrglue.a 
#../../vcpkg_installed/arm64-android/lib/libjpegxr.a 
#../../vcpkg_installed/arm64-android/debug/lib/libturbojpeg.a 
#../../vcpkg_installed/arm64-android/debug/sdk/native/staticlibs/arm64-v8a/libopencv_imgproc4d.a 
#../../vcpkg_installed/arm64-android/debug/sdk/native/staticlibs/arm64-v8a/libopencv_core4d.a 
#../../vcpkg_installed/arm64-android/debug/lib/manual-link/opencv4_thirdparty/libtegra_hald.a 
#../../vcpkg_installed/arm64-android/debug/lib/liblz4d.a 
#../../vcpkg_installed/arm64-android/debug/lib/libfreetyped.a 
#../../vcpkg_installed/arm64-android/debug/lib/libbz2d.a 
#../../vcpkg_installed/arm64-android/debug/lib/libpng16d.a 
#../../vcpkg_installed/arm64-android/debug/lib/libz.a 
#../../vcpkg_installed/arm64-android/debug/lib/libbrotlidec.a 
#../../vcpkg_installed/arm64-android/debug/lib/libbrotlicommon.a 
#../../vcpkg_installed/arm64-android/lib/libbz2.a 
#../../vcpkg_installed/arm64-android/lib/libbrotlidec.a
#../../vcpkg_installed/arm64-android/lib/libbrotlicommon.a 
#../../vcpkg_installed/arm64-android/lib/libpng16.a 
#../../vcpkg_installed/arm64-android/lib/libz.a 
#../../cpp/core/visual/simd/libtvpgl_simd.a 
#../../vcpkg_installed/arm64-android/debug/lib/libhwy.a 
#../../cpp/core/tjs2/libtjs2.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_locale.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_charconv.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_thread.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_atomic.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_chrono.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_date_time.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_container.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_system.a 
#../../vcpkg_installed/arm64-android/debug/lib/libspdlogd.a 
#../../vcpkg_installed/arm64-android/debug/lib/libfmtd.a 
#../../vcpkg_installed/arm64-android/debug/lib/libonig.a 
#
#/home/wmt/android-ndk-r27d/toolchains/llvm/prebuilt/linux-x86_64/lib/clang/18/lib/linux/aarch64/libomp.so 
#-lOpenSLES 
#
#../../vcpkg_installed/arm64-android/debug/lib/libspdlogd.a 
#../../vcpkg_installed/arm64-android/debug/lib/libfmtd.a 
#../../vcpkg_installed/arm64-android/lib/libz.a 
#../../vcpkg_installed/arm64-android/lib/liblibgdiplus.a 
#
#-lglib-2.0 
#-lintl 
#-latomic 
#-liconv 
#-lpcre2-8 
#-lcairo 
#-lfontconfig 
#-lexpat 
#-lfreetype 
#-lbz2 
#-lpng16 
#-lz 
#-lbrotlidec 
#-lbrotlicommon 
#-lpixman-1 
#-liconv 
#-lpcre2-8 
#-lcairo 
#-lfontconfig 
#-lexpat 
#-lfreetype 
#-lbz2 
#-lpng16 
#-lz 
#-lbrotlidec 
#-lbrotlicommon 
#-lpixman-1 
#../../vcpkg_installed/arm64-android/lib/libjpeg.a 
#../../vcpkg_installed/arm64-android/lib/libtiff.a 
#../../vcpkg_installed/arm64-android/lib/liblzma.a 
#../../vcpkg_installed/arm64-android/lib/libjpeg.a 
#../../vcpkg_installed/arm64-android/lib/libtiff.a 
#../../vcpkg_installed/arm64-android/lib/liblzma.a 
#../../vcpkg_installed/arm64-android/lib/libz.a 
#../../vcpkg_installed/arm64-android/lib/libpng16.a 
#../../vcpkg_installed/arm64-android/lib/libz.a 
#../../vcpkg_installed/arm64-android/lib/libpng16.a 
#-lexif 
#-lm 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_thread.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_atomic.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_chrono.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_date_time.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_container.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_iostreams.a 
#../../vcpkg_installed/arm64-android/lib/libz.a 
#../../vcpkg_installed/arm64-android/lib/libbz2.a 
#../../vcpkg_installed/arm64-android/lib/liblzma.a 
#../../vcpkg_installed/arm64-android/debug/lib/libzstd.a 
#-pthread 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_random.a 
#../../vcpkg_installed/arm64-android/debug/lib/libboost_system.a 
#-llog 
#-landroid 
#../../vcpkg_installed/arm64-android/debug/lib/ANGLE.a 
#../../vcpkg_installed/arm64-android/lib/libz.a 
#../../vcpkg_installed/arm64-android/debug/lib/libSPIRV-Tools.a 
#-ldl 
#-latomic 
#-lm

###pkg-config --libs glfw3
LDFLAGS += -lglfw
LDFLAGS += `pkg-config --libs gtk+-2.0`
###-lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lharfbuzz -lfontconfig -lfreetype 
LDFLAGS += -lonig 
LDFLAGS += -lpng 
LDFLAGS += -lfreetype
LDFLAGS += -lvorbisfile 
LDFLAGS += -lvorbis 
LDFLAGS += -logg  
LDFLAGS += -lopusfile 
LDFLAGS += -lopus 
LDFLAGS += -lopencv_core
LDFLAGS += -lopencv_imgproc 
###LDFLAGS += -loboe 
LDFLAGS += -lfmt 
LDFLAGS += -lwebp 
LDFLAGS += -ltinyxml2 
LDFLAGS += -llz4 
LDFLAGS += -ljpeg
###-ljpeg not -ljpeg-turbo, libjpeg-turbo8-dev
LDFLAGS += -luchardet 
LDFLAGS += -lopenal 
LDFLAGS += -lSDL2
LDFLAGS += -lEGL 
LDFLAGS += -lGLESv1_CM 
LDFLAGS += -lGLESv2 
###LDFLAGS += -lOpenSLES 
LDFLAGS += -lz 
###for engine_api
LDFLAGS += -ldl 
LDFLAGS += -lpthread

OBJS += cpp/core/tjs2/gen/tjs.tab.o
OBJS += cpp/core/tjs2/gen/tjsdate.tab.o
OBJS += cpp/core/tjs2/gen/tjspp.tab.o
OBJS += cpp/core/tjs2/tjsLex.o
OBJS += cpp/core/tjs2/tjsNative.o
OBJS += cpp/core/tjs2/tjsRandomGenerator.o
OBJS += cpp/core/tjs2/tjsDebug.o
OBJS += cpp/core/tjs2/tjsRegExp.o
OBJS += cpp/core/tjs2/tjsBinarySerializer.o
OBJS += cpp/core/tjs2/tjsInterCodeGen.o
OBJS += cpp/core/tjs2/tjsObject.o
OBJS += cpp/core/tjs2/tjsConstArrayData.o
OBJS += cpp/core/tjs2/tjsUtils.o
OBJS += cpp/core/tjs2/tjsException.o
OBJS += cpp/core/tjs2/tjsDictionary.o
OBJS += cpp/core/tjs2/tjsInterCodeExec.o
OBJS += cpp/core/tjs2/tjsVariantString.o
OBJS += cpp/core/tjs2/tjsScriptBlock.o
OBJS += cpp/core/tjs2/tjsMath.o
OBJS += cpp/core/tjs2/tjs.o
OBJS += cpp/core/tjs2/tjsMessage.o
OBJS += cpp/core/tjs2/tjsDisassemble.o
OBJS += cpp/core/tjs2/tjsDate.o
OBJS += cpp/core/tjs2/tjsError.o
OBJS += cpp/core/tjs2/tjsInterface.o
OBJS += cpp/core/tjs2/tjsMT19937ar-cok.o
OBJS += cpp/core/tjs2/tjsArray.o
OBJS += cpp/core/tjs2/tjsByteCodeLoader.o
OBJS += cpp/core/tjs2/tjsDateParser.o
OBJS += cpp/core/tjs2/tjsGlobalStringMap.o
OBJS += cpp/core/tjs2/tjsOctPack.o
OBJS += cpp/core/tjs2/tjsNamespace.o
OBJS += cpp/core/tjs2/tjsScriptCache.o
OBJS += cpp/core/tjs2/tjsConfig.o
OBJS += cpp/core/tjs2/tjsCompileControl.o
OBJS += cpp/core/tjs2/tjsObjectExtendable.o
OBJS += cpp/core/tjs2/tjsVariant.o
OBJS += cpp/core/tjs2/tjsString.o

### gedit /home/wmt/KrKr2-Next/cpp/core/visual/tvpgl.cpp
### Line 14136
### TVPGL_SIMD_Init();  // Highway SIMD override
#OBJS += cpp/core/visual/simd/tvpgl_simd_init.o
#OBJS += cpp/core/visual/simd/tvpgl_simd_copy.o
#OBJS += cpp/core/visual/simd/tvpgl_simd_alpha_blend.o
#OBJS += cpp/core/visual/simd/tvpgl_simd_arithmetic_blend.o
#OBJS += cpp/core/visual/simd/tvpgl_simd_const_blend.o
#OBJS += cpp/core/visual/simd/tvpgl_simd_premul_blend.o
#OBJS += cpp/core/visual/simd/tvpgl_simd_ps_blend.o
#OBJS += cpp/core/visual/simd/tvpgl_simd_ps_blend2.o
#OBJS += cpp/core/visual/simd/tvpgl_simd_convert.o
#OBJS += cpp/core/visual/simd/tvpgl_simd_misc.o
#OBJS += cpp/core/visual/simd/tvpgl_simd_blur.o

OBJS += cpp/core/extension/Extension.o

OBJS += cpp/core/utils/ClipboardIntf.o
OBJS += cpp/core/utils/DebugIntf.o
OBJS += cpp/core/utils/MathAlgorithms_Default.o
OBJS += cpp/core/utils/md5.o
OBJS += cpp/core/utils/MiscUtility.o
OBJS += cpp/core/utils/PadIntf.o
OBJS += cpp/core/utils/Random.o
OBJS += cpp/core/utils/RealFFT_Default.o
OBJS += cpp/core/utils/ThreadIntf.o
OBJS += cpp/core/utils/TickCount.o
OBJS += cpp/core/utils/TimerIntf.o
OBJS += cpp/core/utils/VelocityTracker.o
OBJS += cpp/core/utils/encoding/gbk2unicode.o
OBJS += cpp/core/utils/encoding/jis2unicode.o
OBJS += cpp/core/utils/win32/ClipboardImpl.o
OBJS += cpp/core/utils/win32/DebugImpl.o
OBJS += cpp/core/utils/win32/PadImpl.o
OBJS += cpp/core/utils/win32/ThreadImpl.o
OBJS += cpp/core/utils/win32/TimerImpl.o
OBJS += cpp/core/utils/win32/TVPTimer.o

OBJS += cpp/core/visual/LoadWEBP.o
OBJS += cpp/core/visual/TransIntf.o
OBJS += cpp/core/visual/MenuItemIntf.o
OBJS += cpp/core/visual/SaveTLG5.o
OBJS += cpp/core/visual/FontSystem.o
OBJS += cpp/core/visual/LoadPVRv3.o
OBJS += cpp/core/visual/RectItf.o
OBJS += cpp/core/visual/VideoOvlIntf.o
OBJS += cpp/core/visual/LayerBitmapIntf.o
OBJS += cpp/core/visual/FontImpl.o
OBJS += cpp/core/visual/RenderManager.o
OBJS += cpp/core/visual/LoadJPEG.o
OBJS += cpp/core/visual/GraphicsLoaderIntf.o
OBJS += cpp/core/visual/SaveTLG6.o
OBJS += cpp/core/visual/FreeType.o
OBJS += cpp/core/visual/LoadJXR.o
OBJS += cpp/core/visual/ImageFunction.o
OBJS += cpp/core/visual/tvpgl.o
OBJS += cpp/core/visual/LoadTLG.o
OBJS += cpp/core/visual/LayerTreeOwnerImpl.o
OBJS += cpp/core/visual/GraphicsLoadThread.o
OBJS += cpp/core/visual/LayerManager.o
OBJS += cpp/core/visual/PrerenderedFont.o
OBJS += cpp/core/visual/LoadBPG.o
OBJS += cpp/core/visual/WindowIntf.o
OBJS += cpp/core/visual/FreeTypeFontRasterizer.o
OBJS += cpp/core/visual/LoadPNG.o
OBJS += cpp/core/visual/LayerIntf.o
OBJS += cpp/core/visual/ComplexRect.o
OBJS += cpp/core/visual/CharacterData.o
OBJS += cpp/core/visual/BitmapLayerTreeOwner.o
OBJS += cpp/core/visual/BitmapIntf.o
OBJS += cpp/core/visual/argb.o
OBJS += cpp/core/visual/LoadAMV.o
OBJS += cpp/core/visual/gl/blend_function.o
OBJS += cpp/core/visual/gl/ResampleImage.o
OBJS += cpp/core/visual/gl/WeightFunctor.o
OBJS += cpp/core/visual/ogl/astcrt.o
OBJS += cpp/core/visual/ogl/etcpak.o
OBJS += cpp/core/visual/ogl/imagepacker.o
OBJS += cpp/core/visual/ogl/pvrtc.o
OBJS += cpp/core/visual/ogl/PVRTDecompress.o
OBJS += cpp/core/visual/ogl/RenderManager_ogl.o
OBJS += cpp/core/visual/ogl/krkr_gl.o
OBJS += cpp/core/visual/ogl/krkr_egl_context.o
OBJS += cpp/core/visual/impl/BasicDrawDevice.o
OBJS += cpp/core/visual/impl/BitmapBitsAlloc.o
OBJS += cpp/core/visual/impl/BitmapInfomation.o
OBJS += cpp/core/visual/impl/DInputMgn.o
OBJS += cpp/core/visual/impl/DrawDevice.o
OBJS += cpp/core/visual/impl/GraphicsLoaderImpl.o
OBJS += cpp/core/visual/impl/LayerBitmapImpl.o
OBJS += cpp/core/visual/impl/LayerImpl.o
OBJS += cpp/core/visual/impl/MenuItemImpl.o
OBJS += cpp/core/visual/impl/PassThroughDrawDevice.o
OBJS += cpp/core/visual/impl/TVPScreen.o
OBJS += cpp/core/visual/impl/VideoOvlImpl.o
OBJS += cpp/core/visual/impl/WindowImpl.o

OBJS += cpp/core/sound/CDDAIntf.o
OBJS += cpp/core/sound/FFWaveDecoder.o
OBJS += cpp/core/sound/MIDIIntf.o
OBJS += cpp/core/sound/PhaseVocoderDSP.o
OBJS += cpp/core/sound/PhaseVocoderFilter.o
OBJS += cpp/core/sound/SoundBufferBaseIntf.o
OBJS += cpp/core/sound/VorbisWaveDecoder.o
OBJS += cpp/core/sound/WaveFormatConverter.o
OBJS += cpp/core/sound/WaveIntf.o
OBJS += cpp/core/sound/WaveLoopManager.o
OBJS += cpp/core/sound/WaveSegmentQueue.o
OBJS += cpp/core/sound/win32/CDDAImpl.o
OBJS += cpp/core/sound/win32/MIDIImpl.o
OBJS += cpp/core/sound/win32/SoundBufferBaseImpl.o
OBJS += cpp/core/sound/win32/tvpsnd.o
OBJS += cpp/core/sound/win32/WaveImpl.o
OBJS += cpp/core/sound/win32/WaveMixer.o

OBJS += cpp/core/movie/ffmpeg/AEChannelInfo.o
OBJS += cpp/core/movie/ffmpeg/AEFactory.o
OBJS += cpp/core/movie/ffmpeg/AEStreamInfo.o
OBJS += cpp/core/movie/ffmpeg/AEUtil.o
OBJS += cpp/core/movie/ffmpeg/AudioCodecFFmpeg.o
OBJS += cpp/core/movie/ffmpeg/AudioCodecPassthrough.o
OBJS += cpp/core/movie/ffmpeg/AudioDevice.o
OBJS += cpp/core/movie/ffmpeg/BaseRenderer.o
OBJS += cpp/core/movie/ffmpeg/BitstreamStats.o
OBJS += cpp/core/movie/ffmpeg/Clock.o
OBJS += cpp/core/movie/ffmpeg/CodecUtils.o
OBJS += cpp/core/movie/ffmpeg/Demux.o
OBJS += cpp/core/movie/ffmpeg/DemuxFFmpeg.o
OBJS += cpp/core/movie/ffmpeg/DemuxPacket.o
OBJS += cpp/core/movie/ffmpeg/FactoryCodec.o
OBJS += cpp/core/movie/ffmpeg/InputStream.o
OBJS += cpp/core/movie/ffmpeg/krffmpeg.o
OBJS += cpp/core/movie/ffmpeg/KRMovieLayer.o
OBJS += cpp/core/movie/ffmpeg/KRMoviePlayer.o
OBJS += cpp/core/movie/ffmpeg/Message.o
OBJS += cpp/core/movie/ffmpeg/MessageQueue.o
OBJS += cpp/core/movie/ffmpeg/ProcessInfo.o
OBJS += cpp/core/movie/ffmpeg/RenderFlags.o
OBJS += cpp/core/movie/ffmpeg/StreamInfo.o
OBJS += cpp/core/movie/ffmpeg/Thread.o
OBJS += cpp/core/movie/ffmpeg/Timer.o
OBJS += cpp/core/movie/ffmpeg/TimeUtils.o
OBJS += cpp/core/movie/ffmpeg/VideoCodec.o
OBJS += cpp/core/movie/ffmpeg/VideoCodecFFmpeg.o
OBJS += cpp/core/movie/ffmpeg/VideoPlayer.o
OBJS += cpp/core/movie/ffmpeg/VideoPlayerAudio.o
OBJS += cpp/core/movie/ffmpeg/VideoPlayerVideo.o
OBJS += cpp/core/movie/ffmpeg/VideoReferenceClock.o
OBJS += cpp/core/movie/ffmpeg/VideoRenderer.o

OBJS += cpp/core/plugin/ncbind.o
OBJS += cpp/core/plugin/PluginIntf.o
OBJS += cpp/core/plugin/PluginImpl.o

OBJS += cpp/core/environ/Application.o
OBJS += cpp/core/environ/DetectCPU.o
OBJS += cpp/core/environ/DumpSend.o
OBJS += cpp/core/environ/EngineBootstrap.o
OBJS += cpp/core/environ/EngineLoop.o
OBJS += cpp/core/environ/XP3ArchiveRepack.o
###OBJS += cpp/core/environ/android/AndroidUtils.o
OBJS += cpp/core/environ/android/KrkrJniHelper.o
OBJS += cpp/core/environ/linux/Platform.o
OBJS += cpp/core/environ/MainScene.o
OBJS += cpp/core/environ/ConfigManager/GlobalConfigManager.o
OBJS += cpp/core/environ/ConfigManager/IndividualConfigManager.o
OBJS += cpp/core/environ/ConfigManager/LocaleConfigManager.o
OBJS += cpp/core/environ/sdl/tvpsdl.o
OBJS += cpp/core/environ/stubs/ui_stubs.o
OBJS += cpp/core/environ/win32/SystemControl.o

OBJS += cpp/core/base/7zArchive.o
OBJS += cpp/core/base/BinaryStream.o
OBJS += cpp/core/base/CharacterSet.o
OBJS += cpp/core/base/EventIntf.o
OBJS += cpp/core/base/ScriptMgnIntf.o
OBJS += cpp/core/base/StorageIntf.o
OBJS += cpp/core/base/SysInitIntf.o
OBJS += cpp/core/base/SystemIntf.o
OBJS += cpp/core/base/TARArchive.o
OBJS += cpp/core/base/TextStream.o
OBJS += cpp/core/base/UtilStreams.o
OBJS += cpp/core/base/XP3Archive.o
OBJS += cpp/core/base/ZIPArchive.o
OBJS += cpp/core/base/KAGParser.o
OBJS += cpp/core/base/MsgIntf.o
OBJS += cpp/core/base/impl/EventImpl.o
OBJS += cpp/core/base/impl/FileSelector.o
OBJS += cpp/core/base/impl/NativeEventQueue.o
OBJS += cpp/core/base/impl/ScriptMgnImpl.o
OBJS += cpp/core/base/impl/StorageImpl.o
OBJS += cpp/core/base/impl/SysInitImpl.o
OBJS += cpp/core/base/impl/SystemImpl.o
OBJS += cpp/core/base/impl/MsgImpl.o

OBJS += cpp/plugins/scriptsEx.o
OBJS += cpp/plugins/win32dialog.o
OBJS += cpp/plugins/dirlist.o
OBJS += cpp/plugins/csvParser.o
OBJS += cpp/plugins/layerExMovie.o
OBJS += cpp/plugins/varfile.o
OBJS += cpp/plugins/saveStruct.o
OBJS += cpp/plugins/getabout.o
OBJS += cpp/plugins/addFont.o
OBJS += cpp/plugins/wutcwf.o
OBJS += cpp/plugins/windowEx.o
OBJS += cpp/plugins/getSample.o
OBJS += cpp/plugins/layerExPerspective.o
OBJS += cpp/plugins/fftgraph.o
OBJS += cpp/plugins/LayerExBase.o
OBJS += cpp/plugins/xp3filter.o
OBJS += cpp/plugins/extrans.o
OBJS += cpp/plugins/textrender.o
OBJS += cpp/plugins/alphamovie.o
OBJS += cpp/plugins/layerExBTOA.o
OBJS += cpp/plugins/layerExImage.o
OBJS += cpp/plugins/layerExRaster.o
OBJS += cpp/plugins/layerExAreaAverage.o
OBJS += cpp/plugins/layerExLongExposure.o
OBJS += cpp/plugins/krkrgles.o
OBJS += cpp/plugins/drawDeviceD2DCompat.o
OBJS += cpp/plugins/wfBasicEffectCompat.o
OBJS += cpp/plugins/wfTypicalDSPCompat.o
OBJS += cpp/plugins/psdfile/main.o
OBJS += cpp/plugins/psdfile/psdclass.o
OBJS += cpp/plugins/psdfile/psdclass_loadmem.o
OBJS += cpp/plugins/psdfile/psdclass_loadstream.o
OBJS += cpp/plugins/psdfile/psdclass_loadstreambase.o
OBJS += cpp/plugins/psbfile/main.o
OBJS += cpp/plugins/psbfile/PSBValue.o
OBJS += cpp/plugins/psbfile/PSBFile.o
OBJS += cpp/plugins/psbfile/PSBMedia.o
OBJS += cpp/plugins/psbfile/types/PimgType.o
OBJS += cpp/plugins/psbfile/types/MotionType.o
OBJS += cpp/plugins/psbfile/types/ScnType.o
OBJS += cpp/plugins/psbfile/types/ImageType.o
OBJS += cpp/plugins/psbfile/types/MmoType.o
OBJS += cpp/plugins/psbfile/types/ArchiveType.o
OBJS += cpp/plugins/psbfile/types/SoundArchiveType.o
OBJS += cpp/plugins/psbfile/resources/ImageMetadata.o
OBJS += cpp/plugins/layerex_draw/general/main.o
OBJS += cpp/plugins/layerex_draw/general/LayerExDraw.o
OBJS += cpp/plugins/layerex_draw/general/DrawPath.o
OBJS += cpp/plugins/motionplayer/main.o
OBJS += cpp/plugins/motionplayer/EmotePlayer.o
OBJS += cpp/plugins/motionplayer/Player.o
OBJS += cpp/plugins/motionplayer/ResourceManager.o
OBJS += cpp/plugins/kagparserex/kagparserex_plugin.o
OBJS += cpp/plugins/fstat/main.o

OBJS += bridge/engine_api/src/engine_api.o
###OBJS += platforms/android/cpp/krkr2_android.o

KRKR2_OBJS := 

all : krkr2

krkr2: platforms/linux/main.cpp platforms/linux/test.cpp krkr2.a $(KRKR2_OBJS)
	$(CPP) platforms/linux/main.cpp platforms/linux/test.cpp $(KRKR2_OBJS) krkr2.a -o $@ $(CPPFLAGS) $(LDFLAGS)

krkr2.a : $(OBJS)
	$(AR) $@ $(OBJS)
	$(RANLIB) $@

%.o : %.cpp
	$(CPP) $(CPPFLAGS2) $(CPPFLAGS) -o $@ -c $<

%.o : %.cc
	$(CPP) $(CPPFLAGS2) $(CPPFLAGS) -o $@ -c $<

%.o : %.c
	$(CC) $(CPPFLAGS) -o $@ -c $<

test:
	./krkr2

debug:
	gdb --args ./krkr2

clean :
	$(RM) $(OBJS) $(KRKR2_OBJS) krkr2.a krkr2 

#libxcb-xinput-dev
## sudo apt install libdbus-1-dev libudev-dev libx11-dev libgles-dev libwayland-dev libxkbcommon-dev libxext-dev libxcursor-dev libxi-dev libxrandr-dev libxss-dev libpulse-dev libasound2-dev

## sudo apt install libonig-dev libglm-dev libfmt-dev libopusfile-dev libvorbis-dev libfreetype-dev libturbojpeg-dev

## sudo apt install libgles2-mesa-dev libegl1-mesa-dev mesa-utils mesa-utils-extra
## glxgears
## es2gears_x11

#
#TODO:ERROR: [form.cpp:SDL3WindowForm:54] SDL3WindowForm: Failed to create SDL Window: Could not create GLES window surface
#strace ./krkrz, vmwgfx_dri.so not found
#gedit ./sdl3/environ/form.cpp
###if defined(TVP_USE_OPENGL)
##	flags |= SDL_WINDOW_OPENGL;
###endif
##mesa-vulkan-drivers mesa-va-drivers libgl1-mesa-dri
## sudo apt install libgl1-mesa-dri

#TODO:miniaudio
#TODO:picojson
#TODO:SDL3
#TODO:external/movie-player, generic/app/movie.cpp:25
#TODO:gedit sdl3/environ/stdapp.cpp, line 67


