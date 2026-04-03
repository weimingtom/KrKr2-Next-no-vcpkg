#include <string.h>
#include <jni.h>
#include <android/log.h>
#include <string.h>
#include <stdio.h>
#include "engine_api.h"
#include "engine_options.h"
#include "org_github_krkr2_flutter_engine_bridge_EngineBindings.h"

#define LOG_TAG "krkr2"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineGetRuntimeApiVersion
  (JNIEnv *env, jobject /*thiz*/, jintArray out_api_version) {
	if (out_api_version == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	jint* arrayElements = env->GetIntArrayElements(out_api_version, 0);
    if (arrayElements == 0) return ENGINE_RESULT_INTERNAL_ERROR;
    jsize arrayLength = env->GetArrayLength(out_api_version);	
	if (arrayLength < 1) return ENGINE_RESULT_INTERNAL_ERROR;
	
	engine_result_t result = engine_get_runtime_api_version((uint32_t *)arrayElements);
	
	env->ReleaseIntArrayElements(out_api_version, arrayElements, 0);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineCreate
  (JNIEnv *env, jobject /*thiz*/, jobject obj, jlongArray out_handle) {
	if (!obj) return ENGINE_RESULT_INTERNAL_ERROR;
	jclass cls = env->GetObjectClass(obj);	  
	
	engine_create_desc_t desc = {sizeof(engine_create_desc_t)};
	
	//jfieldID structSize_fid = env->GetFieldID(cls, "structSize", "I");
    //if (!structSize_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    //desc.struct_size = env->GetIntField(obj, structSize_fid);
	
	jfieldID apiVersion_fid = env->GetFieldID(cls, "apiVersion", "I");
    if (!apiVersion_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    desc.api_version = env->GetIntField(obj, apiVersion_fid);

	jfieldID writablePathUtf8_fid = env->GetFieldID(cls, "writablePathUtf8", "Ljava/lang/String;");
    if (!writablePathUtf8_fid) return ENGINE_RESULT_INTERNAL_ERROR;
	jstring writablePathUtf8_jstring = (jstring)env->GetObjectField(obj, writablePathUtf8_fid);
	const char *writablePathUtf8_string = 0;
	if (writablePathUtf8_jstring) {
		writablePathUtf8_string = env->GetStringUTFChars(writablePathUtf8_jstring, 0);
	}
    desc.writable_path_utf8 = writablePathUtf8_string;

	jfieldID cachePathUtf8_fid = env->GetFieldID(cls, "cachePathUtf8", "Ljava/lang/String;");
    if (!cachePathUtf8_fid) return ENGINE_RESULT_INTERNAL_ERROR;
	jstring cachePathUtf8_jstring = (jstring)env->GetObjectField(obj, cachePathUtf8_fid);
	const char *cachePathUtf8_string = 0;
	if (cachePathUtf8_jstring) {
		cachePathUtf8_string = env->GetStringUTFChars(cachePathUtf8_jstring, 0);
	}
    desc.cache_path_utf8 = cachePathUtf8_string;

	jfieldID userData_fid = env->GetFieldID(cls, "userData", "J");
    if (!userData_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    desc.user_data = (void *)env->GetLongField(obj, userData_fid);
	
	if (out_handle == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	jlong* arrayElements = env->GetLongArrayElements(out_handle, 0);
    if (arrayElements == 0) return ENGINE_RESULT_INTERNAL_ERROR;
    jsize arrayLength = env->GetArrayLength(out_handle);	
	if (arrayLength < 1) return ENGINE_RESULT_INTERNAL_ERROR;
	
	engine_result_t result = engine_create(&desc, (engine_handle_t *)arrayElements);
	
	env->ReleaseLongArrayElements(out_handle, arrayElements, 0);
	if (cachePathUtf8_jstring && cachePathUtf8_string) env->ReleaseStringUTFChars(cachePathUtf8_jstring, cachePathUtf8_string);
	if (writablePathUtf8_jstring && writablePathUtf8_string) env->ReleaseStringUTFChars(writablePathUtf8_jstring, writablePathUtf8_string);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineDestroy
  (JNIEnv *env, jobject /*thiz*/, jlong handle) {
	engine_result_t result = engine_destroy((engine_handle_t)handle);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineOpenGame
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jstring game_root_path_utf8, jstring startup_script_utf8) {
	const char *game_root_path_utf8_str = game_root_path_utf8 ? env->GetStringUTFChars(game_root_path_utf8, 0) : 0;
    //if (game_root_path_utf8_str == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	const char *startup_script_utf8_str = startup_script_utf8 ? env->GetStringUTFChars(startup_script_utf8, 0) : 0;
    //if (startup_script_utf8_str == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	
	engine_result_t result = engine_open_game((engine_handle_t)handle, game_root_path_utf8_str, startup_script_utf8_str);
	
	if (startup_script_utf8 && startup_script_utf8_str) env->ReleaseStringUTFChars(startup_script_utf8, startup_script_utf8_str);
	if (game_root_path_utf8 && game_root_path_utf8_str) env->ReleaseStringUTFChars(game_root_path_utf8, game_root_path_utf8_str);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineOpenGameAsync
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jstring game_root_path_utf8, jstring startup_script_utf8) {
	const char *game_root_path_utf8_str = game_root_path_utf8 ? env->GetStringUTFChars(game_root_path_utf8, 0) : 0;
    //if (game_root_path_utf8_str == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	const char *startup_script_utf8_str = startup_script_utf8 ? env->GetStringUTFChars(startup_script_utf8, 0) : 0;
    //if (startup_script_utf8_str == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	
	engine_result_t result = engine_open_game_async((engine_handle_t)handle, game_root_path_utf8_str, startup_script_utf8_str);
	
	if(startup_script_utf8 && startup_script_utf8_str) env->ReleaseStringUTFChars(startup_script_utf8, startup_script_utf8_str);
	if(game_root_path_utf8 && game_root_path_utf8_str) env->ReleaseStringUTFChars(game_root_path_utf8, game_root_path_utf8_str);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineGetStartupState
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jintArray out_state) {
	if (out_state == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	jint* arrayElements = env->GetIntArrayElements(out_state, 0);
    if (arrayElements == 0) return ENGINE_RESULT_INTERNAL_ERROR;
    jsize arrayLength = env->GetArrayLength(out_state);	
	if (arrayLength < 1) return ENGINE_RESULT_INTERNAL_ERROR;
	
	engine_result_t result = engine_get_startup_state((engine_handle_t)handle, (uint32_t *)arrayElements);
	
	env->ReleaseIntArrayElements(out_state, arrayElements, 0);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineDrainStartupLogs
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jbyteArray out_buffer, jint /*buffer_size*/, jintArray out_bytes_written) {
	if (out_buffer == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	jbyte* arrayElements = env->GetByteArrayElements(out_buffer, 0);
    if (arrayElements == 0) return ENGINE_RESULT_INTERNAL_ERROR;
    jsize arrayLength = env->GetArrayLength(out_buffer);	  

	if (out_bytes_written == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	jint* arrayElements_written = env->GetIntArrayElements(out_bytes_written, 0);
    if (arrayElements_written == 0) return ENGINE_RESULT_INTERNAL_ERROR;
    jsize arrayLength_written = env->GetArrayLength(out_bytes_written);	
	if (arrayLength_written < 1) return ENGINE_RESULT_INTERNAL_ERROR;
	
	engine_result_t result = engine_drain_startup_logs((engine_handle_t)handle, (char *)arrayElements, arrayLength, (uint32_t *)arrayElements_written);
	
	env->ReleaseIntArrayElements(out_bytes_written, arrayElements_written, 0);
	env->ReleaseByteArrayElements(out_buffer, arrayElements, 0);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineTick
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jint delta_ms) {
	engine_result_t result = engine_tick((engine_handle_t)handle, delta_ms);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_enginePause
  (JNIEnv *env, jobject /*thiz*/, jlong handle) {
	engine_result_t result = engine_pause((engine_handle_t)handle);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineResume
  (JNIEnv *env, jobject /*thiz*/, jlong handle) {
	engine_result_t result = engine_resume((engine_handle_t)handle);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineSetOption
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jobject obj) {
	if (!obj) return ENGINE_RESULT_INTERNAL_ERROR;
	jclass cls = env->GetObjectClass(obj);
	
	engine_option_t option = {0};
	
	jfieldID keyUtf8_fid = env->GetFieldID(cls, "keyUtf8", "Ljava/lang/String;");
    if (!keyUtf8_fid) return ENGINE_RESULT_INTERNAL_ERROR;
	jstring keyUtf8_jstring = (jstring)env->GetObjectField(obj, keyUtf8_fid);
	const char *keyUtf8_string = 0;
	if (keyUtf8_jstring) {
		keyUtf8_string = env->GetStringUTFChars(keyUtf8_jstring, 0);
	}
    option.key_utf8 = keyUtf8_string;

	jfieldID valueUtf8_fid = env->GetFieldID(cls, "valueUtf8", "Ljava/lang/String;");
    if (!valueUtf8_fid) return ENGINE_RESULT_INTERNAL_ERROR;
	jstring valueUtf8_jstring = (jstring)env->GetObjectField(obj, valueUtf8_fid);
	const char *valueUtf8_string = 0;
	if (valueUtf8_jstring) {
		valueUtf8_string = env->GetStringUTFChars(valueUtf8_jstring, 0);
	}
    option.value_utf8 = valueUtf8_string;
	
	engine_result_t result = engine_set_option((engine_handle_t)handle, &option);
	
	if (valueUtf8_jstring && valueUtf8_string) env->ReleaseStringUTFChars(valueUtf8_jstring, valueUtf8_string);
	if (keyUtf8_jstring && keyUtf8_string) env->ReleaseStringUTFChars(keyUtf8_jstring, keyUtf8_string);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineSetSurfaceSize
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jint width, jint height) {
	engine_result_t result = engine_set_surface_size((engine_handle_t)handle, width, height);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineGetFrameDesc
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jobject obj) {
	if (!obj) return ENGINE_RESULT_INTERNAL_ERROR;
	jclass cls = env->GetObjectClass(obj);
	
	engine_frame_desc_t out_frame_desc = {sizeof(engine_frame_desc_t)};  
	engine_result_t result = engine_get_frame_desc((engine_handle_t)handle, &out_frame_desc);
	
	jfieldID structSize_fid = env->GetFieldID(cls, "structSize", "I");
    if (!structSize_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, structSize_fid, out_frame_desc.struct_size);
	
	jfieldID width_fid = env->GetFieldID(cls, "width", "I");
    if (!width_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, width_fid, out_frame_desc.width);

	jfieldID height_fid = env->GetFieldID(cls, "height", "I");
    if (!height_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, height_fid, out_frame_desc.height);
	
	jfieldID strideBytes_fid = env->GetFieldID(cls, "strideBytes", "I");
    if (!strideBytes_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, strideBytes_fid, out_frame_desc.stride_bytes);
	
	jfieldID pixelFormat_fid = env->GetFieldID(cls, "pixelFormat", "I");
    if (!pixelFormat_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, pixelFormat_fid, out_frame_desc.pixel_format);

	jfieldID frameSerial_fid = env->GetFieldID(cls, "pixelFormat", "I");
    if (!frameSerial_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetLongField(obj, frameSerial_fid, out_frame_desc.frame_serial);
	
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineReadFrameRgba
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jbyteArray out_buffer, jlong /*buffer_size*/) {
	if (out_buffer == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	jbyte* arrayElements = env->GetByteArrayElements(out_buffer, 0);
    if (arrayElements == 0) return ENGINE_RESULT_INTERNAL_ERROR;
    jsize arrayLength = env->GetArrayLength(out_buffer);	  
	  
	engine_result_t result = engine_read_frame_rgba((engine_handle_t)handle, arrayElements, arrayLength);
	
	env->ReleaseByteArrayElements(out_buffer, arrayElements, 0);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineSendInput
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jobject obj) {
	if (!obj) return ENGINE_RESULT_INTERNAL_ERROR;
	jclass cls = env->GetObjectClass(obj);  
	
	engine_input_event_t event = {sizeof(engine_input_event_t)};
	
	//jfieldID structSize_fid = env->GetFieldID(cls, "structSize", "I");
    //if (!structSize_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    //event.struct_size = env->GetIntField(obj, structSize_fid);

	jfieldID type_fid = env->GetFieldID(cls, "type", "I");
    if (!type_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    event.type = env->GetIntField(obj, type_fid);

	jfieldID timestampMicros_fid = env->GetFieldID(cls, "timestampMicros", "J");
    if (!timestampMicros_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    event.timestamp_micros = env->GetLongField(obj, timestampMicros_fid);

	jfieldID x_fid = env->GetFieldID(cls, "x", "D");
    if (!x_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    event.x = env->GetDoubleField(obj, x_fid);
	
	jfieldID y_fid = env->GetFieldID(cls, "y", "D");
    if (!y_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    event.y = env->GetDoubleField(obj, y_fid);
	
	jfieldID deltaX_fid = env->GetFieldID(cls, "deltaX", "D");
    if (!deltaX_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    event.delta_x = env->GetDoubleField(obj, deltaX_fid);

	jfieldID deltaY_fid = env->GetFieldID(cls, "deltaY", "D");
    if (!deltaY_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    event.delta_y = env->GetDoubleField(obj, deltaY_fid);
	
	jfieldID pointerId_fid = env->GetFieldID(cls, "pointerId", "I");
    if (!pointerId_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    event.pointer_id = env->GetIntField(obj, pointerId_fid);
	
	jfieldID button_fid = env->GetFieldID(cls, "button", "I");
    if (!button_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    event.button = env->GetIntField(obj, button_fid);
	
	jfieldID keyCode_fid = env->GetFieldID(cls, "keyCode", "I");
    if (!keyCode_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    event.key_code = env->GetIntField(obj, keyCode_fid);
	
	jfieldID modifiers_fid = env->GetFieldID(cls, "modifiers", "I");
    if (!modifiers_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    event.modifiers = env->GetIntField(obj, modifiers_fid);
	
	jfieldID unicodeCodepoint_fid = env->GetFieldID(cls, "unicodeCodepoint", "I");
    if (!unicodeCodepoint_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    event.unicode_codepoint = env->GetIntField(obj, unicodeCodepoint_fid);
	
	engine_result_t result = engine_send_input((engine_handle_t)handle, &event);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineSetRenderTargetIOSurface
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jint iosurface_id, jint width, jint height) {
   engine_result_t result = engine_set_render_target_iosurface((engine_handle_t)handle, iosurface_id, width, height);
   return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineSetRenderTargetSurface
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jobject native_window, jint width, jint height) {
	engine_result_t result = engine_set_render_target_surface((engine_handle_t)handle, native_window, width, height);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineGetFrameRenderedFlag
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jintArray out_) {
	if (out_ == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	jint* arrayElements = env->GetIntArrayElements(out_, 0);
	if (arrayElements == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	jsize arrayLength = env->GetArrayLength(out_);
	if (arrayLength < 1) return ENGINE_RESULT_INTERNAL_ERROR;
	engine_result_t result = engine_get_frame_rendered_flag((engine_handle_t)handle, (uint32_t*)arrayElements);
	env->ReleaseIntArrayElements(out_, arrayElements, 0);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineGetRendererInfo
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jbyteArray out_buffer, jint /*buffer_size*/) {
	if (out_buffer == 0) return ENGINE_RESULT_INTERNAL_ERROR;
	jbyte* arrayElements = env->GetByteArrayElements(out_buffer, 0);
    if (arrayElements == 0) return ENGINE_RESULT_INTERNAL_ERROR;
    jsize arrayLength = env->GetArrayLength(out_buffer);
	engine_result_t result = engine_get_renderer_info((engine_handle_t)handle, (char *)arrayElements, arrayLength);
    env->ReleaseByteArrayElements(out_buffer, arrayElements, 0);
	return result;
}

extern "C"
JNIEXPORT jint JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineGetMemoryStats
  (JNIEnv *env, jobject /*thiz*/, jlong handle, jobject obj) {
	if (!obj) return ENGINE_RESULT_INTERNAL_ERROR;
	jclass cls = env->GetObjectClass(obj);
	
	engine_memory_stats_t stats = {sizeof(engine_memory_stats_t)};
	engine_result_t result = engine_get_memory_stats((engine_handle_t)handle, &stats);
	
	jfieldID structSize_fid = env->GetFieldID(cls, "structSize", "I");
    if (!structSize_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, structSize_fid, stats.struct_size);

	jfieldID selfUsedMb_fid = env->GetFieldID(cls, "selfUsedMb", "I");
    if (!selfUsedMb_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, selfUsedMb_fid, stats.self_used_mb);	

	jfieldID systemFreeMb_fid = env->GetFieldID(cls, "systemFreeMb", "I");
    if (!systemFreeMb_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, systemFreeMb_fid, stats.system_free_mb);		

	jfieldID systemTotalMb_fid = env->GetFieldID(cls, "systemTotalMb", "I");
    if (!systemTotalMb_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, systemTotalMb_fid, stats.system_total_mb);
	
	jfieldID graphicCacheBytes_fid = env->GetFieldID(cls, "graphicCacheBytes", "J");
    if (!graphicCacheBytes_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetLongField(obj, graphicCacheBytes_fid, stats.graphic_cache_bytes);

	jfieldID graphicCacheLimitBytes_fid = env->GetFieldID(cls, "graphicCacheLimitBytes", "J");
    if (!graphicCacheLimitBytes_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetLongField(obj, graphicCacheLimitBytes_fid, stats.graphic_cache_limit_bytes);	

	jfieldID xp3SegmentCacheBytes_fid = env->GetFieldID(cls, "xp3SegmentCacheBytes", "J");
    if (!xp3SegmentCacheBytes_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetLongField(obj, xp3SegmentCacheBytes_fid, stats.xp3_segment_cache_bytes);	

	jfieldID psbCacheBytes_fid = env->GetFieldID(cls, "psbCacheBytes", "J");
    if (!psbCacheBytes_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetLongField(obj, psbCacheBytes_fid, stats.psb_cache_bytes);	
	
	jfieldID psbCacheEntries_fid = env->GetFieldID(cls, "psbCacheEntries", "I");
    if (!psbCacheEntries_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, psbCacheEntries_fid, stats.psb_cache_entries);
	
	jfieldID psbCacheEntryLimit_fid = env->GetFieldID(cls, "psbCacheEntryLimit", "I");
    if (!psbCacheEntryLimit_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, psbCacheEntryLimit_fid, stats.psb_cache_entry_limit);
	
	jfieldID psbCacheHits_fid = env->GetFieldID(cls, "psbCacheHits", "J");
    if (!psbCacheHits_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetLongField(obj, psbCacheHits_fid, stats.psb_cache_hits);	
	
	jfieldID psbCacheMisses_fid = env->GetFieldID(cls, "psbCacheMisses", "J");
    if (!psbCacheMisses_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetLongField(obj, psbCacheMisses_fid, stats.psb_cache_misses);	
	
	jfieldID archiveCacheEntries_fid = env->GetFieldID(cls, "archiveCacheEntries", "I");
    if (!archiveCacheEntries_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, archiveCacheEntries_fid, stats.archive_cache_entries);
	
	jfieldID archiveCacheLimit_fid = env->GetFieldID(cls, "archiveCacheLimit", "I");
    if (!archiveCacheLimit_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, archiveCacheLimit_fid, stats.archive_cache_limit);
	
	jfieldID autopathCacheEntries_fid = env->GetFieldID(cls, "autopathCacheEntries", "I");
    if (!autopathCacheEntries_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, autopathCacheEntries_fid, stats.autopath_cache_entries);
	
	jfieldID autopathCacheLimit_fid = env->GetFieldID(cls, "autopathCacheLimit", "I");
    if (!autopathCacheLimit_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, autopathCacheLimit_fid, stats.autopath_cache_limit);

	jfieldID autopathTableEntries_fid = env->GetFieldID(cls, "autopathTableEntries", "I");
    if (!autopathTableEntries_fid) return ENGINE_RESULT_INTERNAL_ERROR;
    env->SetIntField(obj, autopathTableEntries_fid, stats.autopath_table_entries);

	return result;
}

extern "C"
JNIEXPORT jstring JNICALL Java_org_github_krkr2_flutter_1engine_1bridge_EngineBindings_engineGetLastError
  (JNIEnv *env, jobject /*thiz*/, jlong handle) {
	return env->NewStringUTF(engine_get_last_error((engine_handle_t)handle));
}
  
 
 