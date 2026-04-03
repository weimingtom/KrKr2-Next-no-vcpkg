LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:= libopusfile

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include \
	$(LOCAL_PATH)/src \
	$(LOCAL_PATH)/../libogg/include \
	$(LOCAL_PATH)/../libogg-1.1.3/include \
	$(LOCAL_PATH)/../opus/include

LOCAL_CFLAGS += -DOP_FIXED_POINT

LOCAL_SRC_FILES := \
src/http.c \
src/info.c \
src/internal.c \
src/opusfile.c \
src/stream.c \
src/wincerts.c

include $(BUILD_STATIC_LIBRARY)
