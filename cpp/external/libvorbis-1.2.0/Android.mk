LOCAL_PATH := $(call my-dir)

####################################

include $(CLEAR_VARS)

LOCAL_MODULE:= vorbis

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include \
   $(LOCAL_PATH)/lib \
   $(LOCAL_PATH)/../libogg-1.1.3/include  

LOCAL_CFLAGS +=

LOCAL_SRC_FILES += lib/analysis.c
#LOCAL_SRC_FILES += lib/barkmel.c
LOCAL_SRC_FILES += lib/bitrate.c
LOCAL_SRC_FILES += lib/block.c
LOCAL_SRC_FILES += lib/codebook.c
LOCAL_SRC_FILES += lib/envelope.c
LOCAL_SRC_FILES += lib/floor0.c
LOCAL_SRC_FILES += lib/floor1.c
LOCAL_SRC_FILES += lib/info.c
LOCAL_SRC_FILES += lib/lookup.c
LOCAL_SRC_FILES += lib/lpc.c
LOCAL_SRC_FILES += lib/lsp.c
LOCAL_SRC_FILES += lib/mapping0.c
LOCAL_SRC_FILES += lib/mdct.c
LOCAL_SRC_FILES += lib/psy.c
#LOCAL_SRC_FILES += lib/psytune.c
LOCAL_SRC_FILES += lib/registry.c
LOCAL_SRC_FILES += lib/res0.c
LOCAL_SRC_FILES += lib/sharedbook.c
LOCAL_SRC_FILES += lib/smallft.c
LOCAL_SRC_FILES += lib/synthesis.c
#LOCAL_SRC_FILES += lib/tone.c
LOCAL_SRC_FILES += lib/vorbisenc.c
LOCAL_SRC_FILES += lib/vorbisfile.c
LOCAL_SRC_FILES += lib/window.c

include $(BUILD_STATIC_LIBRARY)
