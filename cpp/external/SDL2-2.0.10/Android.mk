LOCAL_PATH := $(call my-dir)

####################################

include $(CLEAR_VARS)

LOCAL_MODULE := SDL2

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include

# for SDL2
LOCAL_CFLAGS += -DGL_GLEXT_PROTOTYPES
#LOCAL_CFLAGS += \
#	-Wall -Wextra \
#	-Wdocumentation \
#	-Wdocumentation-unknown-command \
#	-Wmissing-prototypes \
#	-Wunreachable-code-break \
#	-Wunneeded-internal-declaration \
#	-Wmissing-variable-declarations \
#	-Wfloat-conversion \
#	-Wshorten-64-to-32 \
#	-Wunreachable-code-return \
#	-Wshift-sign-overflow \
#	-Wstrict-prototypes \
#	-Wkeyword-macro

LOCAL_SRC_FILES :=
#SDL2
LOCAL_SRC_FILES += ./src/SDL.c
LOCAL_SRC_FILES += ./src/SDL_assert.c
LOCAL_SRC_FILES += ./src/SDL_dataqueue.c
LOCAL_SRC_FILES += ./src/SDL_error.c
LOCAL_SRC_FILES += ./src/SDL_hints.c
LOCAL_SRC_FILES += ./src/SDL_log.c
LOCAL_SRC_FILES += ./src/audio/SDL_audio.c
LOCAL_SRC_FILES += ./src/audio/SDL_audiocvt.c
LOCAL_SRC_FILES += ./src/audio/SDL_audiodev.c
LOCAL_SRC_FILES += ./src/audio/SDL_audiotypecvt.c
LOCAL_SRC_FILES += ./src/audio/SDL_mixer.c
LOCAL_SRC_FILES += ./src/audio/SDL_wave.c
LOCAL_SRC_FILES += ./src/audio/android/SDL_androidaudio.c
LOCAL_SRC_FILES += ./src/audio/dummy/SDL_dummyaudio.c
#LOCAL_SRC_FILES += $(wildcard ./src/audio/aaudio/*.c)
LOCAL_SRC_FILES += ./src/audio/openslES/SDL_openslES.c
LOCAL_SRC_FILES += ./src/atomic/SDL_atomic.c.arm
LOCAL_SRC_FILES += ./src/atomic/SDL_spinlock.c.arm
LOCAL_SRC_FILES += ./src/core/android/SDL_android.c
LOCAL_SRC_FILES += ./src/cpuinfo/SDL_cpuinfo.c
LOCAL_SRC_FILES += ./src/dynapi/SDL_dynapi.c
LOCAL_SRC_FILES += ./src/events/SDL_clipboardevents.c
LOCAL_SRC_FILES += ./src/events/SDL_displayevents.c
LOCAL_SRC_FILES += ./src/events/SDL_dropevents.c
LOCAL_SRC_FILES += ./src/events/SDL_events.c
LOCAL_SRC_FILES += ./src/events/SDL_gesture.c
LOCAL_SRC_FILES += ./src/events/SDL_keyboard.c
LOCAL_SRC_FILES += ./src/events/SDL_mouse.c
LOCAL_SRC_FILES += ./src/events/SDL_quit.c
LOCAL_SRC_FILES += ./src/events/SDL_touch.c
LOCAL_SRC_FILES += ./src/events/SDL_windowevents.c
LOCAL_SRC_FILES += ./src/file/SDL_rwops.c
LOCAL_SRC_FILES += ./src/haptic/SDL_haptic.c
LOCAL_SRC_FILES += ./src/haptic/android/SDL_syshaptic.c
#LOCAL_SRC_FILES += $(wildcard ./src/hidapi/*.c)
LOCAL_SRC_FILES += ./src/hidapi/android/hid.cpp
LOCAL_SRC_FILES += ./src/joystick/SDL_gamecontroller.c
LOCAL_SRC_FILES += ./src/joystick/SDL_joystick.c
LOCAL_SRC_FILES += ./src/joystick/android/SDL_sysjoystick.c
LOCAL_SRC_FILES += ./src/joystick/hidapi/SDL_hidapijoystick.c
LOCAL_SRC_FILES += ./src/joystick/hidapi/SDL_hidapi_ps4.c
LOCAL_SRC_FILES += ./src/joystick/hidapi/SDL_hidapi_switch.c
LOCAL_SRC_FILES += ./src/joystick/hidapi/SDL_hidapi_xbox360.c
LOCAL_SRC_FILES += ./src/joystick/hidapi/SDL_hidapi_xboxone.c
#LOCAL_SRC_FILES += $(wildcard ./src/joystick/virtual/*.c)
LOCAL_SRC_FILES += ./src/loadso/dlopen/SDL_sysloadso.c
#LOCAL_SRC_FILES += $(wildcard ./src/locale/*.c)
#LOCAL_SRC_FILES += $(wildcard ./src/locale/android/*.c)
#LOCAL_SRC_FILES += $(wildcard ./src/misc/*.c)
#LOCAL_SRC_FILES += $(wildcard ./src/misc/android/*.c)
LOCAL_SRC_FILES += ./src/power/SDL_power.c
LOCAL_SRC_FILES += ./src/power/android/SDL_syspower.c
LOCAL_SRC_FILES += ./src/filesystem/android/SDL_sysfilesystem.c
LOCAL_SRC_FILES += ./src/sensor/SDL_sensor.c
LOCAL_SRC_FILES += ./src/sensor/android/SDL_androidsensor.c
LOCAL_SRC_FILES += ./src/render/SDL_d3dmath.c
LOCAL_SRC_FILES += ./src/render/SDL_render.c
LOCAL_SRC_FILES += ./src/render/SDL_yuv_sw.c
LOCAL_SRC_FILES += ./src/render/opengl/SDL_render_gl.c
LOCAL_SRC_FILES += ./src/render/opengl/SDL_shaders_gl.c
LOCAL_SRC_FILES += ./src/render/opengles/SDL_render_gles.c
LOCAL_SRC_FILES += ./src/render/opengles2/SDL_render_gles2.c
LOCAL_SRC_FILES += ./src/render/opengles2/SDL_shaders_gles2.c
LOCAL_SRC_FILES += ./src/render/software/SDL_blendfillrect.c
LOCAL_SRC_FILES += ./src/render/software/SDL_blendline.c
LOCAL_SRC_FILES += ./src/render/software/SDL_blendpoint.c
LOCAL_SRC_FILES += ./src/render/software/SDL_drawline.c
LOCAL_SRC_FILES += ./src/render/software/SDL_drawpoint.c
LOCAL_SRC_FILES += ./src/render/software/SDL_render_sw.c
LOCAL_SRC_FILES += ./src/render/software/SDL_rotate.c
LOCAL_SRC_FILES += ./src/stdlib/SDL_getenv.c
LOCAL_SRC_FILES += ./src/stdlib/SDL_iconv.c
LOCAL_SRC_FILES += ./src/stdlib/SDL_malloc.c
LOCAL_SRC_FILES += ./src/stdlib/SDL_qsort.c
LOCAL_SRC_FILES += ./src/stdlib/SDL_stdlib.c
LOCAL_SRC_FILES += ./src/stdlib/SDL_string.c
LOCAL_SRC_FILES += ./src/thread/SDL_thread.c
LOCAL_SRC_FILES += ./src/thread/pthread/SDL_syscond.c
LOCAL_SRC_FILES += ./src/thread/pthread/SDL_sysmutex.c
LOCAL_SRC_FILES += ./src/thread/pthread/SDL_syssem.c
LOCAL_SRC_FILES += ./src/thread/pthread/SDL_systhread.c
LOCAL_SRC_FILES += ./src/thread/pthread/SDL_systls.c
LOCAL_SRC_FILES += ./src/timer/SDL_timer.c
LOCAL_SRC_FILES += ./src/timer/unix/SDL_systimer.c
LOCAL_SRC_FILES += ./src/video/SDL_blit.c
LOCAL_SRC_FILES += ./src/video/SDL_blit_0.c
LOCAL_SRC_FILES += ./src/video/SDL_blit_1.c
LOCAL_SRC_FILES += ./src/video/SDL_blit_A.c
LOCAL_SRC_FILES += ./src/video/SDL_blit_auto.c
LOCAL_SRC_FILES += ./src/video/SDL_blit_copy.c
LOCAL_SRC_FILES += ./src/video/SDL_blit_N.c
LOCAL_SRC_FILES += ./src/video/SDL_blit_slow.c
LOCAL_SRC_FILES += ./src/video/SDL_bmp.c
LOCAL_SRC_FILES += ./src/video/SDL_clipboard.c
LOCAL_SRC_FILES += ./src/video/SDL_egl.c
LOCAL_SRC_FILES += ./src/video/SDL_fillrect.c
LOCAL_SRC_FILES += ./src/video/SDL_pixels.c
LOCAL_SRC_FILES += ./src/video/SDL_rect.c
LOCAL_SRC_FILES += ./src/video/SDL_RLEaccel.c
LOCAL_SRC_FILES += ./src/video/SDL_shape.c
LOCAL_SRC_FILES += ./src/video/SDL_stretch.c
LOCAL_SRC_FILES += ./src/video/SDL_surface.c
LOCAL_SRC_FILES += ./src/video/SDL_video.c
LOCAL_SRC_FILES += ./src/video/SDL_vulkan_utils.c
LOCAL_SRC_FILES += ./src/video/SDL_yuv.c
LOCAL_SRC_FILES += ./src/video/android/SDL_androidclipboard.c
LOCAL_SRC_FILES += ./src/video/android/SDL_androidevents.c
LOCAL_SRC_FILES += ./src/video/android/SDL_androidgl.c
LOCAL_SRC_FILES += ./src/video/android/SDL_androidkeyboard.c
LOCAL_SRC_FILES += ./src/video/android/SDL_androidmessagebox.c
LOCAL_SRC_FILES += ./src/video/android/SDL_androidmouse.c
LOCAL_SRC_FILES += ./src/video/android/SDL_androidtouch.c
LOCAL_SRC_FILES += ./src/video/android/SDL_androidvideo.c
LOCAL_SRC_FILES += ./src/video/android/SDL_androidvulkan.c
LOCAL_SRC_FILES += ./src/video/android/SDL_androidwindow.c
LOCAL_SRC_FILES += ./src/video/yuv2rgb/yuv_rgb.c
LOCAL_SRC_FILES += ./src/test/SDL_test_assert.c
LOCAL_SRC_FILES += ./src/test/SDL_test_common.c
LOCAL_SRC_FILES += ./src/test/SDL_test_compare.c
LOCAL_SRC_FILES += ./src/test/SDL_test_crc32.c
LOCAL_SRC_FILES += ./src/test/SDL_test_font.c
LOCAL_SRC_FILES += ./src/test/SDL_test_fuzzer.c
LOCAL_SRC_FILES += ./src/test/SDL_test_harness.c
LOCAL_SRC_FILES += ./src/test/SDL_test_imageBlit.c
LOCAL_SRC_FILES += ./src/test/SDL_test_imageBlitBlend.c
LOCAL_SRC_FILES += ./src/test/SDL_test_imageFace.c
LOCAL_SRC_FILES += ./src/test/SDL_test_imagePrimitives.c
LOCAL_SRC_FILES += ./src/test/SDL_test_imagePrimitivesBlend.c
LOCAL_SRC_FILES += ./src/test/SDL_test_log.c
LOCAL_SRC_FILES += ./src/test/SDL_test_md5.c
LOCAL_SRC_FILES += ./src/test/SDL_test_memory.c
LOCAL_SRC_FILES += ./src/test/SDL_test_random.c

ifeq ($(NDK_DEBUG),1)
    cmd-strip :=
endif

#LOCAL_STATIC_LIBRARIES := cpufeatures

###ld: error: duplicate symbol: JNI_OnLoad
LOCAL_CFLAGS += -DMY_USE_DISABLE_JNI_ONLOAD=1
include $(BUILD_STATIC_LIBRARY)

# JNI_OnLoad, multiple definition of 'JNI_OnLoad'
# for SDL2
# Warnings we haven't fixed (yet)
# LOCAL_CFLAGS += -Wno-unused-parameter -Wno-sign-compare
###LOCAL_LDLIBS := -ldl -lGLESv1_CM -lGLESv2 -lOpenSLES -llog -landroid
###include $(BUILD_SHARED_LIBRARY)


####################################

