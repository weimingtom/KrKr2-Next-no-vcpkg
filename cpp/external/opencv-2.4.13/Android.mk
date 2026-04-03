LOCAL_PATH := $(call my-dir)

####################################

include $(CLEAR_VARS)

LOCAL_MODULE := opencv_core_imgproc

###LOCAL_CPPFLAGS += -std=c++17
###for use of undeclared identifier 'mem_fun_ref'
LOCAL_CPPFLAGS += -std=c++11

LOCAL_CPP_FEATURES += exceptions

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
$(LOCAL_PATH)/include \
$(LOCAL_PATH)/modules/core/include \
$(LOCAL_PATH)/modules/dynamicuda/include \
$(LOCAL_PATH)/modules/imgproc/include

LOCAL_SRC_FILES :=

LOCAL_SRC_FILES += ./modules/core/src/algorithm.cpp
LOCAL_SRC_FILES += ./modules/core/src/alloc.cpp
LOCAL_SRC_FILES += ./modules/core/src/arithm.cpp
LOCAL_SRC_FILES += ./modules/core/src/array.cpp
LOCAL_SRC_FILES += ./modules/core/src/cmdparser.cpp
LOCAL_SRC_FILES += ./modules/core/src/convert.cpp
LOCAL_SRC_FILES += ./modules/core/src/copy.cpp
LOCAL_SRC_FILES += ./modules/core/src/datastructs.cpp
LOCAL_SRC_FILES += ./modules/core/src/drawing.cpp
LOCAL_SRC_FILES += ./modules/core/src/dxt.cpp
LOCAL_SRC_FILES += ./modules/core/src/gl_core_3_1.cpp
LOCAL_SRC_FILES += ./modules/core/src/glob.cpp
LOCAL_SRC_FILES += ./modules/core/src/gpumat.cpp
LOCAL_SRC_FILES += ./modules/core/src/lapack.cpp
LOCAL_SRC_FILES += ./modules/core/src/mathfuncs.cpp
LOCAL_SRC_FILES += ./modules/core/src/matmul.cpp
LOCAL_SRC_FILES += ./modules/core/src/matop.cpp
LOCAL_SRC_FILES += ./modules/core/src/matrix.cpp
LOCAL_SRC_FILES += ./modules/core/src/opengl_interop.cpp
LOCAL_SRC_FILES += ./modules/core/src/opengl_interop_deprecated.cpp
LOCAL_SRC_FILES += ./modules/core/src/out.cpp
LOCAL_SRC_FILES += ./modules/core/src/parallel.cpp
LOCAL_SRC_FILES += ./modules/core/src/persistence.cpp
LOCAL_SRC_FILES += ./modules/core/src/rand.cpp
LOCAL_SRC_FILES += ./modules/core/src/stat.cpp
LOCAL_SRC_FILES += ./modules/core/src/system.cpp
LOCAL_SRC_FILES += ./modules/core/src/tables_core.cpp


LOCAL_SRC_FILES += ./modules/imgproc/src/avx/imgwarp_avx.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/avx2/imgwarp_avx2.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/accum.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/approx.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/canny.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/clahe.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/color.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/contours.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/convhull.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/corner.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/cornersubpix.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/deriv.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/distransform.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/emd.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/featureselect.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/filter.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/floodfill.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/gabor.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/generalized_hough.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/geometry.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/grabcut.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/histogram.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/hough.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/imgwarp.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/linefit.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/matchcontours.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/moments.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/morph.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/phasecorr.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/pyramids.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/rotcalipers.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/samplers.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/segmentation.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/shapedescr.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/smooth.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/subdivision2d.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/sumpixels.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/tables.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/templmatch.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/thresh.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/undistort.cpp
LOCAL_SRC_FILES += ./modules/imgproc/src/utils.cpp

#LOCAL_CPPFLAGS := -DTJS_TEXT_OUT_CRLF -fexceptions
#-DONIG_EXTERN=extern -DNOT_RUBY -DEXPORT
#LOCAL_CFLAGS := -DTJS_TEXT_OUT_CRLF 
#-DONIG_EXTERN=extern -DNOT_RUBY -DEXPORT

include $(BUILD_STATIC_LIBRARY)


####################################

