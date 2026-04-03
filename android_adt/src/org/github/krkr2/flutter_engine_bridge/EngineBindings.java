package org.github.krkr2.flutter_engine_bridge;

//from bridge\flutter_engine_bridge\lib\src\ffi\engine_bindings.dart
public class EngineBindings {
	static {
		try {
            System.loadLibrary("engine_api");
        } catch (UnsatisfiedLinkError e) {
            android.util.Log.w("krkr2", "engine_api native lib not found: " + e.getMessage());
        }
	}
	
	/*
	 * @see #engineGetRuntimeApiVersion(int[] out_api_version)
	 */
	public final static int kEngineApiVersion = 0x01000000; //ENGINE_API_VERSION
	
	/*
	 * bridge\engine_api\include\engine_api.h
	 * Most return value
	 */
	public final static int kEngineResultOk = 0; //ENGINE_RESULT_OK
	public final static int kEngineResultInvalidArgument = -1; //ENGINE_RESULT_INVALID_ARGUMENT
	public final static int kEngineResultInvalidState = -2; //ENGINE_RESULT_INVALID_STATE
	public final static int kEngineResultNotSupported = -3; //ENGINE_RESULT_NOT_SUPPORTED
	public final static int kEngineResultIOError = -4; //ENGINE_RESULT_IO_ERROR
	public final static int kEngineResultInternalError = -5; //ENGINE_RESULT_INTERNAL_ERROR
	
	/*
	 * @see #engineGetStartupState(long handle, int[] out_state)
	 * Not return value, see the second parameter
	 */
	public final static int kEngineStartupStateIdle = 0; //ENGINE_STARTUP_STATE_IDLE
	public final static int kEngineStartupStateRunning = 1; //ENGINE_STARTUP_STATE_RUNNING
	public final static int kEngineStartupStateSucceeded = 2; //ENGINE_STARTUP_STATE_SUCCEEDED
	public final static int kEngineStartupStateFailed = 3; //ENGINE_STARTUP_STATE_FAILED
	
	/*
	 * @see EngineFrameDesc#pixelFormat
	 * @see EngineFrameInfo#pixelFormat
	 * @see #engineGetFrameDesc(long handle, EngineFrameDesc desc)
	 */
	public final static int kEnginePixelFormatUnknown = 0; //ENGINE_PIXEL_FORMAT_UNKNOWN
	public final static int kEnginePixelFormatRgba8888 = 1; //ENGINE_PIXEL_FORMAT_RGBA8888

	/*
	 * @see EngineInputEvent#type
	 * @see #engineSendInput(long handle, EngineInputEvent event)
	 */
	public final static int kEngineInputEventPointerDown = 1; //ENGINE_INPUT_EVENT_POINTER_DOWN
	public final static int kEngineInputEventPointerMove = 2; //ENGINE_INPUT_EVENT_POINTER_MOVE
	public final static int kEngineInputEventPointerUp = 3; //ENGINE_INPUT_EVENT_POINTER_UP
	public final static int kEngineInputEventPointerScroll = 4; //ENGINE_INPUT_EVENT_POINTER_SCROLL
	public final static int kEngineInputEventKeyDown = 5; //ENGINE_INPUT_EVENT_KEY_DOWN
	public final static int kEngineInputEventKeyUp = 6; //ENGINE_INPUT_EVENT_KEY_UP
	public final static int kEngineInputEventTextInput = 7; //ENGINE_INPUT_EVENT_TEXT_INPUT
	public final static int kEngineInputEventBack = 8; //ENGINE_INPUT_EVENT_BACK
	
	/*
	 * Returns runtime API version in out_api_version.
	 * out_api_version must be non-null.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_get_runtime_api_version(
//    uint32_t* out_api_version);
	//
	//engine_get_runtime_api_version
	//return ENGINE_API_VERSION
	/* ABI version: major(8bit), minor(8bit), patch(16bit). */
	//#define ENGINE_API_VERSION 0x01000000u
	public native int engineGetRuntimeApiVersion(int[] out_api_version);
	
	/*
	 * Creates an engine handle.
	 * desc and out_handle must be non-null.
	 * out_handle is set only when ENGINE_RESULT_OK is returned.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_create(const engine_create_desc_t* desc,
//    engine_handle_t* out_handle);
	public native int engineCreate(EngineCreateDesc desc, long[] out_handle);
	
	/*
	 * Destroys engine handle and releases all resources.
	 * Idempotent: passing a null handle returns ENGINE_RESULT_OK.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_destroy(engine_handle_t handle);
	public native int engineDestroy(long handle);
	
	/*
	 * Opens a game package/root directory.
	 * handle and game_root_path_utf8 must be non-null.
	 * startup_script_utf8 may be null to use default startup script.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_open_game(
//	    engine_handle_t handle, const char* game_root_path_utf8,
//	    const char* startup_script_utf8);
	public native int engineOpenGame(long handle, String game_root_path_utf8, String startup_script_utf8);

	
/*
FlutterWindowLayer, cpp/core/environ/stubs/ui_stubs.cpp
03-25 10:27:57.355  4641  4727 I krkr2   : [PushStartupLog] [core] [info] FlutterWindowLayer created: 1280x720
03-25 10:27:57.355  4641  4727 I krkr2   : [PushStartupLog] [core] [info] TVPCreateAndAddWindow: created FlutterWindowLayer (1280x720)
03-25 10:27:57.369  4641  4727 I krkr2   : [PushStartupLog] [core] [critical] FATAL SIGNAL 11 received!
03-25 10:27:57.369  4641  4727 I krkr2   : [PushStartupLog] [core] [critical] FATAL SIGNAL 6 received!
require disable InstallCrashSignalHandlers() to see backtrace in adb logcat

cpp\core\visual\ogl\RenderManager_ogl.cpp
line 2915
InitGL()
crash_002.txt, crash_002_stack.txt
static void TVPInitGLExtensionInfo() {
    if(TVPGLExtensionInfoInited)
        return;
    TVPGLExtensionInfoInited = true;
***crash here***----->    const char *ext_str = (const char *)glGetString(GL_EXTENSIONS);
    if(!ext_str) return; // No GL context (e.g. Flutter mode without EGL surface)
    std::string gl_extensions = ext_str;
*/
	/*
	 * Starts game opening asynchronously on a background worker.
	 * Returns immediately when the startup task is scheduled.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_open_game_async(
//	    engine_handle_t handle, const char* game_root_path_utf8,
//	    const char* startup_script_utf8);
	//FIXME: this function will startup a std::thread, don't call engineDestroy after it
	public native int engineOpenGameAsync(long handle, String game_root_path_utf8, String startup_script_utf8);
	
	/*
	 * Gets async startup state.
	 * out_state must be non-null.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_get_startup_state(
//	    engine_handle_t handle, uint32_t* out_state);
	public native int engineGetStartupState(long handle, int[] out_state);
	
	/*
	 * Drains startup logs into caller buffer as UTF-8 text.
	 * Each log line is terminated by '\n'.
	 * Returns bytes written in out_bytes_written.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_drain_startup_logs(
//	    engine_handle_t handle, char* out_buffer, uint32_t buffer_size,
//	    uint32_t* out_bytes_written);
	public native int engineDrainStartupLogs(long handle, byte[] out_buffer, int buffer_size, int[] out_bytes_written);
	
	/*
	 * Ticks engine main loop once.
	 * handle must be non-null.
	 * delta_ms is caller-provided elapsed milliseconds.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_tick(engine_handle_t handle,
//	                                              uint32_t delta_ms);
	//FIXME:engine_tick must be called after engineOpenGame() and engineOpenGameAsync()
	public native int engineTick(long handle, int delta_ms);
	
	/*
	 * Pauses runtime execution.
	 * Idempotent: calling pause on a paused engine returns ENGINE_RESULT_OK.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_pause(engine_handle_t handle);
	public native int enginePause(long handle);
	
	/*
	 * Resumes runtime execution.
	 * Idempotent: calling resume on a running engine returns ENGINE_RESULT_OK.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_resume(engine_handle_t handle);
	public native int engineResume(long handle);
	
	/*
	 * Sets runtime option by UTF-8 key/value pair.
	 * handle and option must be non-null.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_set_option(engine_handle_t handle,
//	                                                    const engine_option_t* option);
	public native int engineSetOption(long handle, EngineOption option);
	
	/*
	 * Sets logical render surface size in pixels.
	 * width and height must be greater than zero.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_set_surface_size(engine_handle_t handle,
//	                                                          uint32_t width,
//	                                                          uint32_t height);
	public native int engineSetSurfaceSize(long handle, int width, int height);
	
	/*
	 * Gets current frame descriptor.
	 * out_frame_desc->struct_size must be initialized by caller.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_get_frame_desc(
//	    engine_handle_t handle, engine_frame_desc_t* out_frame_desc);
	public native int engineGetFrameDesc(long handle, EngineFrameDesc desc);
	
	/*
	 * Reads current frame into caller-provided RGBA8888 buffer.
	 * out_pixels_size must be >= stride_bytes * height from engine_get_frame_desc.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_read_frame_rgba(
//	    engine_handle_t handle, void* out_pixels, size_t out_pixels_size);
	public native int engineReadFrameRgba(long handle, byte[] out_pixels, long out_pixels_size);
	
	/*
	 * Gets host-native render window handle.
	 * On macOS runtime build this is NSWindow*.
	 * Returns ENGINE_RESULT_NOT_SUPPORTED on unsupported platforms/builds.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_get_host_native_window(
//	    engine_handle_t handle, void** out_window_handle);
	
	/*
	 * Gets host-native render view handle.
	 * On macOS runtime build this is NSView* (typically the GLFW content view).
	 * Returns ENGINE_RESULT_NOT_SUPPORTED on unsupported platforms/builds.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_get_host_native_view(
//	    engine_handle_t handle, void** out_view_handle);
	
	/*
	 * Sends one input event to the runtime.
	 * event->struct_size must be initialized by caller.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_send_input(engine_handle_t handle,
//	                                                    const engine_input_event_t* event);
	//FIXME:engine handle(engineSendInput) must be used on the thread where engine_create was called
	public native int engineSendInput(long handle, EngineInputEvent event);
	
	/*
	 * Sets an IOSurface as the render target for the engine.
	 * When set, engine_tick renders directly to this IOSurface (zero-copy),
	 * bypassing the glReadPixels path used by engine_read_frame_rgba.
	 *
	 * iosurface_id: The IOSurfaceID obtained from IOSurfaceGetID().
	 *               Pass 0 to detach and revert to the default Pbuffer mode.
	 * width/height: Dimensions of the IOSurface in pixels.
	 *
	 * Platform: macOS only. Returns ENGINE_RESULT_NOT_SUPPORTED on other platforms.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_set_render_target_iosurface(
//	    engine_handle_t handle, uint32_t iosurface_id,
//	    uint32_t width, uint32_t height);
	public native int engineSetRenderTargetIOSurface(long handle, int iosurface_id, int width, int height);
	
	/*
	 * Sets an Android Surface (from SurfaceTexture) as the render target.
	 * When set, engine_tick renders to an EGL WindowSurface created from the
	 * ANativeWindow. eglSwapBuffers() delivers frames directly to Flutter's
	 * SurfaceTexture (GPU zero-copy).
	 *
	 * native_window: ANativeWindow* obtained from ANativeWindow_fromSurface().
	 *                Pass NULL to detach and revert to the default Pbuffer mode.
	 * width/height: Dimensions in pixels.
	 *
	 * Platform: Android only. Returns ENGINE_RESULT_NOT_SUPPORTED on other platforms.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_set_render_target_surface(
//	    engine_handle_t handle, void* native_window,
//	    uint32_t width, uint32_t height);
	public native int engineSetRenderTargetSurface(long handle, Object native_window, int width, int height);
	
	/*
	 * Queries whether the last engine_tick produced a new rendered frame.
	 * out_
	 *
	 * out_
	 *   - 0: no new frame since last query
	 *   - 1: a new frame was rendered
	 *
	 * This is useful in IOSurface mode to know when to call
	 * textureFrameAvailable() on the Flutter side.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_get_frame_rendered_flag(
//	    engine_handle_t handle, uint32_t* out_
//	);
	public native int engineGetFrameRenderedFlag(long handle, int[] out_);
	
	/*
	 * Queries the graphics renderer information string.
	 * Writes a null-terminated UTF-8 string into out_buffer describing
	 * the active graphics backend (e.g. "Metal", "OpenGL ES", "D3D11").
	 *
	 * out_buffer and buffer_size must be non-null / > 0.
	 * If the buffer is too small the string is truncated.
	 * Returns ENGINE_RESULT_INVALID_STATE if the runtime is not active.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_get_renderer_info(
//	    engine_handle_t handle, char* out_buffer, uint32_t buffer_size);
	public native int engineGetRendererInfo(long handle, byte[] out_buffer, int buffer_size);
	
	/*
	 * Gets runtime memory/cache statistics snapshot.
	 * out_stats->struct_size must be initialized by caller.
	 */
//	ENGINE_API_EXPORT engine_result_t engine_get_memory_stats(
//	    engine_handle_t handle, engine_memory_stats_t* out_stats);
	//Require KR2Activity, if KR2Activity does not exist, it will warn
	public native int engineGetMemoryStats(long handle, EngineMemoryStats out_stats);
	
	/*
	 * Returns last error message as UTF-8 null-terminated string.
	 * The returned pointer remains valid until next API call on the same handle.
	 * Returns empty string when no error is recorded.
	 */
//	ENGINE_API_EXPORT const char* engine_get_last_error(engine_handle_t handle);
	public native String engineGetLastError(long handle);
}
