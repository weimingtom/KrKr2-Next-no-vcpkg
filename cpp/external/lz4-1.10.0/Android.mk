LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

#LOCAL_ARM_MODE := arm

LOCAL_MODULE := lz4
LOCAL_CFLAGS := 
#-w -std=c11 -O3

LOCAL_SRC_FILES := \
lib/lz4.c \
lib/lz4file.c \
lib/lz4frame.c \
lib/lz4hc.c \
lib/xxhash.c

include $(BUILD_STATIC_LIBRARY)
