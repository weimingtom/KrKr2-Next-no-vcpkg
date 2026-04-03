LOCAL_PATH := $(call my-dir)

####################################

include $(CLEAR_VARS)

LOCAL_MODULE:= ogg

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include

LOCAL_CFLAGS +=

LOCAL_SRC_FILES += src/bitwise.c
LOCAL_SRC_FILES += src/framing.c

include $(BUILD_STATIC_LIBRARY)
