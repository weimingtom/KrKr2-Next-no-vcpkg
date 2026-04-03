package org.github.krkr2.flutter_engine_bridge;

//\apps\flutter_app\lib\constants\prefs_keys.dart
//\bridge\engine_api\include\engine_options.h
public class PrefsKeys {
		// ── SharedPreferences keys ──────────────────────────────────────
		public final static String dylibPath = "krkr2_dylib_path";
		public final static String engineMode = "krkr2_engine_mode";
		public final static String perfOverlay = "krkr2_perf_overlay";
		public final static String fpsLimitEnabled = "krkr2_fps_limit_enabled";
		public final static String targetFps = "krkr2_target_fps";
		public final static String renderer = "krkr2_renderer";
		public final static String angleBackend = "krkr2_angle_backend";
		public final static String locale = "krkr2_locale";
		public final static String themeMode = "krkr2_theme_mode";
		public final static String forceLandscape = "krkr2_force_landscape";
		
		/// Pending play session: JSON { "path": "...", "startTime": "ISO8601" }. Cleared on normal exit or applied on next launch.
		public final static String pendingPlaySession = "krkr2_pending_play_session";
		
		/// Recently settled play session IDs. Used to avoid duplicate crediting.
		public final static String settledPlaySessionIds = "krkr2_settled_play_session_ids";
		
		// ── Engine option keys (must match C++ ENGINE_OPTION_* constants) ─
		public final static String optionAngleBackend = "angle_backend"; //ENGINE_OPTION_ANGLE_BACKEND
		public final static String optionFpsLimit = "fps_limit";
		public final static String optionRenderer = "renderer"; //ENGINE_OPTION_RENDERER
		public final static String optionMemoryProfile = "memory_profile";
		public final static String optionMemoryBudgetMb = "memory_budget_mb";
		public final static String optionMemoryLogIntervalMs = "memory_log_interval_ms";
		public final static String optionPsbCacheMb = "psb_cache_mb";
		public final static String optionPsbCacheEntries = "psb_cache_entries";
		public final static String optionArchiveCacheCount = "archive_cache_count";
		public final static String optionAutoPathCacheCount = "autopath_cache_count";
		
		// ── Engine option values ────────────────────────────────────────
		//see bridge\engine_api\include\engine_options.h
		//@see optionAngleBackend, ENGINE_OPTION_ANGLE_BACKEND
		public final static String angleBackendGles = "gles"; //ENGINE_ANGLE_BACKEND_GLES
		public final static String angleBackendVulkan = "vulkan"; //ENGINE_ANGLE_BACKEND_VULKAN
		
		//@see optionRenderer, ENGINE_OPTION_RENDERER
		public final static String rendererOpengl = "opengl"; //ENGINE_RENDERER_OPENGL
		public final static String rendererSoftware = "software"; //ENGINE_RENDERER_SOFTWARE
		
		public final static String memoryProfileBalanced = "balanced";
		public final static String memoryProfileAggressive = "aggressive";
		
		// ── Engine mode values ──────────────────────────────────────────
		public final static String engineModeBuiltIn = "builtIn";
		public final static String engineModeCustom = "custom";
		
		// ── Default values ──────────────────────────────────────────────
		public final static int defaultFps = 60;
		public final static int[] fpsOptions = new int[]{30, 60, 120};
		  
  
	  	//============================================
	  

		/* ── Option Keys ────────────────────────────────────────────────── */
		
		/** ANGLE EGL backend selection (Android only; other platforms ignore). */
		public final static String ENGINE_OPTION_ANGLE_BACKEND       = "angle_backend";
		
		/** Frame rate limit (0 = unlimited / follow vsync). */
		public final static String ENGINE_OPTION_FPS_LIMIT           = "fps_limit";
		
		/** Render pipeline selection ("opengl" or "software"). */
		public final static String ENGINE_OPTION_RENDERER            = "renderer";
		
		/** Memory profile ("balanced" / "aggressive").
		 *  Consumed by the C++ memory governor via TVPGetCommandLine(). */
		public final static String ENGINE_OPTION_MEMORY_PROFILE      = "memory_profile";
		
		/** Runtime memory budget in MB (0 = auto).
		 *  Consumed by the C++ memory governor via TVPGetCommandLine(). */
		public final static String ENGINE_OPTION_MEMORY_BUDGET_MB    = "memory_budget_mb";
		
		/** Memory governor log interval in milliseconds.
		 *  Consumed by the C++ memory governor via TVPGetCommandLine(). */
		public final static String ENGINE_OPTION_MEMORY_LOG_INTERVAL_MS = "memory_log_interval_ms";
		
		/** PSB resource cache budget in MB. */
		public final static String ENGINE_OPTION_PSB_CACHE_MB        = "psb_cache_mb";
		
		/** PSB resource cache max entry count. */
		public final static String ENGINE_OPTION_PSB_CACHE_ENTRIES   = "psb_cache_entries";
		
		/** Archive cache max entry count. */
		public final static String ENGINE_OPTION_ARCHIVE_CACHE_COUNT = "archive_cache_count";
		
		/** Auto path cache max entry count. */
		public final static String ENGINE_OPTION_AUTOPATH_CACHE_COUNT = "autopath_cache_count";
		
		/* ── ANGLE Backend Values ───────────────────────────────────────── */
		
		/** Use ANGLE's OpenGL ES backend (default). */
		public final static String ENGINE_ANGLE_BACKEND_GLES         = "gles";
		
		/** Use ANGLE's Vulkan backend. */
		public final static String ENGINE_ANGLE_BACKEND_VULKAN       = "vulkan";
		
		/* ── Renderer Values ────────────────────────────────────────────── */
		
		public final static String ENGINE_RENDERER_OPENGL            =  "opengl";
		public final static String ENGINE_RENDERER_SOFTWARE          = "software";
		
		public final static String ENGINE_MEMORY_PROFILE_BALANCED    = "balanced";
		public final static String ENGINE_MEMORY_PROFILE_AGGRESSIVE  = "aggressive";

	  
	  
	  
	  
	  
	  
}
