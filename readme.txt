D:\work_kk3\KrKr2-Next\apps\flutter_app\lib\engine\engine_bridge.dart
 bool get isFfiAvailable;
  String get ffiInitializationError;

  Future<String?> getPlatformVersion();
  Future<String> getBackendDescription();

  Future<int> engineCreate({String? writablePath, String? cachePath});
  Future<int> engineDestroy();
  Future<int> engineOpenGame(String gameRootPath, {String? startupScript});
  Future<int> engineOpenGameAsync(String gameRootPath, {String? startupScript});
  Future<EngineStartupState?> engineGetStartupState();
  Future<String> engineDrainStartupLogs();
  Future<int> engineTick({int deltaMs = 16});
  Future<int> enginePause();
  Future<int> engineResume();
  Future<int> engineSetOption({required String key, required String value});
  Future<int> engineSetSurfaceSize({required int width, required int height});
  Future<EngineFrameInfo?> engineGetFrameDesc();
  Future<Uint8List?> engineReadFrameRgba();
  Future<EngineFrameData?> engineReadFrame();
  Future<int> engineSendInput(EngineInputEventData event);
  Future<int?> createTexture({required int width, required int height});
  Future<bool> updateTextureRgba({
    required int textureId,
    required Uint8List rgba,
    required int width,
    required int height,
    required int rowBytes,
  });
  Future<void> disposeTexture({required int textureId});
  Future<int> engineRuntimeApiVersion();

  // IOSurface zero-copy rendering
  Future<int> engineSetRenderTargetIOSurface({
    required int iosurfaceId,
    required int width,
    required int height,
  });
  Future<bool> engineGetFrameRenderedFlag();
  Future<Map<String, dynamic>?> createIOSurfaceTexture({
    required int width,
    required int height,
  });
  Future<void> notifyFrameAvailable({required int textureId});
  Future<Map<String, dynamic>?> resizeIOSurfaceTexture({
    required int textureId,
    required int width,
    required int height,
  });
  Future<void> disposeIOSurfaceTexture({required int textureId});

  // SurfaceTexture zero-copy rendering (Android)
  Future<Map<String, dynamic>?> createSurfaceTexture({
    required int width,
    required int height,
  });
  Future<Map<String, dynamic>?> resizeSurfaceTexture({
    required int textureId,
    required int width,
    required int height,
  });
  Future<void> disposeSurfaceTexture({required int textureId});

  String engineGetRendererInfo();
  Future<EngineMemoryStats?> engineGetMemoryStats();
  String engineGetLastError();
  
  
-----------------------------

D:\work_kk3\KrKr2-Next\apps\flutter_app\lib\pages\game_page.dart


Future<void> _autoStart() async {
->

--------------------------
_bridge.engineCreate()
_bridge.engineGetLastError()

    final int createResult = await _bridge.engineCreate();
    if (createResult != _engineResultOk) {
      _fail(
        'engine_create failed: result=$createResult, '
        'error=${_bridge.engineGetLastError()}',
      );
      return;
    }
    _log('engine_create => OK');

-------------------------
_bridge.engineSetOption()

    // Set ANGLE backend (gles / vulkan) — Android only, others ignore
    if (Platform.isAndroid) {
      final angleBackend =
          prefs.getString(PrefsKeys.angleBackend) ?? PrefsKeys.angleBackendGles;
      _log('Setting angle_backend=$angleBackend');
      await _bridge.engineSetOption(
        key: PrefsKeys.optionAngleBackend,
        value: angleBackend,
      );
    }
----------------------
_bridge.engineOpenGameAsync()


    _log('engine_open_game($normalizedGamePath)...');
    _log('Starting application — this may take a moment...');

    final int openResult = await _bridge.engineOpenGameAsync(
      normalizedGamePath,
    );
    if (openResult != _engineResultOk) {
      _fail(
        'engine_open_game_async failed: result=$openResult, '
        'error=${_bridge.engineGetLastError()}',
      );
      return;
    }
    _log('engine_open_game_async => queued');
    _startStartupPolling();
	
-----------------------
underlying

D:\work_kk3\KrKr2-Next\bridge\flutter_engine_bridge\lib\src\ffi\engine_bindings.dart

21 functions

engineGetRuntimeApiVersion = engine_get_runtime_api_version
engineCreate = engine_create
engineDestroy = engine_destroy
engineOpenGame = engine_open_game
engineOpenGameAsync = engine_open_game_async
engineGetStartupState = engine_get_startup_state
engineDrainStartupLogs = engine_drain_startup_logs
engineTick = engine_tick
enginePause = engine_pause
engineResume = engine_resume
engineSetOption = engine_set_option
engineSetSurfaceSize = engine_set_surface_size
engineGetFrameDesc = engine_get_frame_desc
engineReadFrameRgba = engine_read_frame_rgba
engineSendInput = engine_send_input
engineSetRenderTargetIOSurface = engine_set_render_target_iosurface
engineSetRenderTargetSurface = engine_set_render_target_surface
engineGetFrameRenderedFlag = engine_get_frame_rendered_flag
engineGetRendererInfo = engine_get_renderer_info
engineGetMemoryStats = engine_get_memory_stats
engineGetLastError = engine_get_last_error

-----------------------


#if defined(__ANDROID__)
  // Auto-attach pending ANativeWindow from JNI bridge.
  // The Kotlin plugin calls nativeSetSurface() which stores the
  // ANativeWindow in a global variable. Here we detect it and
  // attach it as the EGL WindowSurface render target so that
  // eglSwapBuffers delivers frames to Flutter's SurfaceTexture.
  if (!impl->render.native_window_attached) {
    ANativeWindow* pending_window = krkr_GetNativeWindow();
    if (pending_window) {
      uint32_t win_w = 0, win_h = 0;

	  

	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
krkr_GetNativeWindow

D:\work_kk3\KrKr2-Next\platforms\android\cpp\krkr2_android.cpp

extern "C" JNIEXPORT void JNICALL
Java_org_github_krkr2_flutter_1engine_1bridge_FlutterEngineBridgePlugin_nativeSetSurface(




------------------------------



D:\work_kk3\KrKr2-Next\bridge\flutter_engine_bridge\android\src\main\kotlin\org\github\krkr2\flutter_engine_bridge\FlutterEngineBridgePlugin.kt



    // JNI bridge to C++ (krkr2_android.cpp)
    private external fun nativeSetSurface(surface: Surface?, width: Int, height: Int)
    private external fun nativeDetachSurface()
    private external fun nativeSetApplicationContext(context: android.content.Context)

	
	
android.view.Surface


android 创建Surface对象
SurfaceView surfaceView = findViewById(R.id.surface_view);
SurfaceHolder surfaceHolder = surfaceView.getHolder();
Surface surface = surfaceHolder.getSurface();


******************
see VideoProject_v2_play_audio_success.7z
******************
ANativeWindow_fromSurface:
    if (surface) {
        g_native_window = ANativeWindow_fromSurface(env, surface);
        if (g_native_window) {
            g_surface_width = static_cast<uint32_t>(width);
            g_surface_height = static_cast<uint32_t>(height);
            LOGI("nativeSetSurface: ANativeWindow acquired (%dx%d)", width, height);
        } else {
            LOGE("nativeSetSurface: ANativeWindow_fromSurface failed");
        }
    } else {
        LOGI("nativeSetSurface: Surface detached (null)");
    }

-------------------------


    override fun onAttachedToEngine(flutterPluginBinding: FlutterPlugin.FlutterPluginBinding) {
        binding = flutterPluginBinding
        textureRegistry = flutterPluginBinding.textureRegistry
        engineAttached = true
        channel = MethodChannel(flutterPluginBinding.binaryMessenger, "flutter_engine_bridge")
        channel.setMethodCallHandler(this)

        // Pass Application Context to the native engine so that C++ code
        // (AndroidUtils.cpp) can call Context methods like getExternalFilesDirs,
        // getFilesDir, etc. without depending on KR2Activity.
        try {
            nativeSetApplicationContext(flutterPluginBinding.applicationContext)
        } catch (e: UnsatisfiedLinkError) {
            android.util.Log.w("krkr2", "nativeSetApplicationContext not available: ${e.message}")
        }
    }
	
	
