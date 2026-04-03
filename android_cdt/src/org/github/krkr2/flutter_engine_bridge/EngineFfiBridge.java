package org.github.krkr2.flutter_engine_bridge;

//see bridge\flutter_engine_bridge\lib\src\ffi\engine_ffi.dart
public class EngineFfiBridge {
	private EngineBindings _bindings = new EngineBindings();
	private long _handle = 0;
	
	private static String _lastCreateError = "";
	public static String getLastCreateError() {
		return _lastCreateError;
	}
	//see platforms/linux/main.cpp
	//it can be called after create()
	public String getLastError() {
		//if _handle is 0, it may also return something too.  
		return _bindings.engineGetLastError(_handle);
	}
	
	public boolean isCreated() {
		return _handle != 0;
	}
	
	public int runtimeApiVersion() {
	    int[] outVersion = new int[1];
	    try {
	    	int result = _bindings.engineGetRuntimeApiVersion(outVersion);
	    	if (result != EngineBindings.kEngineResultOk) {
	    		return result;
	    	}
	    	return outVersion[0];
	    } finally {
	    	//
	    }
	}
	
	public int create(String writablePath, String cachePath) {
	    if (_handle != 0) {
	    	return EngineBindings.kEngineResultOk;
	    }
	    EngineCreateDesc desc = new EngineCreateDesc();
	    long[] outHandle = new long[1];
	    try {
	    	desc.structSize = 0;
	    	desc.apiVersion = EngineBindings.kEngineApiVersion;
	    	desc.writablePathUtf8 = writablePath;
	    	desc.cachePathUtf8 = cachePath;
	    	desc.userData = 0;
	    	outHandle[0] = 0;
	    	int result = _bindings.engineCreate(desc, outHandle);
	    	if (result == EngineBindings.kEngineResultOk) {
	    		_handle = outHandle[0];
	    	}
	    	return result;
	    } finally {
	    	
	    }
	}
	
	public int destroy() {
		long current = _handle;
		if (current == 0) {
			return EngineBindings.kEngineResultOk;
		}

		int result = _bindings.engineDestroy(current);
		if (result == EngineBindings.kEngineResultOk) {
			_handle = 0;
		}
		return result;
	}
	
	public int openGame(String gameRootPath, String startupScript) {
	    try {
	    	return _bindings.engineOpenGame(_handle, gameRootPath, startupScript);
	    } finally {
	    	
	    }
	}
	
	public int openGameAsync(String gameRootPath, String startupScript) {
		try {
			return _bindings.engineOpenGameAsync(
						_handle,
						gameRootPath,
						startupScript
					);
	    } finally {
	    	
	    }
	}
	
	public Integer getStartupState() {
		if (_handle == 0) {
			return null;
		}
		int[] outState = new int[1];
		try {
			int result = _bindings.engineGetStartupState(_handle, outState);
			if (result != EngineBindings.kEngineResultOk) {
				return null;
			}
			return outState[0];
		} finally {
			
		}
	}
	
	public String drainStartupLogs() {
		if (_handle == 0) {
			return "";
		}	
		final int bufferSize = 65536;
		byte[] buffer = new byte[bufferSize];
		int[] outBytesWritten = new int[1];
		try {
			int result = _bindings.engineDrainStartupLogs(
					  	_handle,
					  	buffer,
					  	bufferSize,
					  	outBytesWritten
					);
			if (result != EngineBindings.kEngineResultOk) {
				return "";
			}
			int length = outBytesWritten[0];
			if (length == 0) {
				return "";
			}
			return new String(buffer, 0, length);
		} finally {
			
		}
	}
	
	public int tick() {
		return tick(16);
	}
	
	public int tick(int deltaMs) {
		return _bindings.engineTick(_handle, deltaMs);
	}
	
	public int pause() {
		return _bindings.enginePause(_handle);
	}

	public int resume() {
		return _bindings.engineResume(_handle);
	}

	public int setOption(String key, String value) {
		EngineOption option = new EngineOption();
	    try {
	    	option.keyUtf8 = key;
	    	option.valueUtf8 = value;
	    	return _bindings.engineSetOption(_handle, option);
	    } finally {
	    	
	    }
	}
	
	public int setSurfaceSize(int width, int height) {
		return _bindings.engineSetSurfaceSize(_handle, width, height);
	}
	
	public EngineFrameInfo getFrameDesc() {
		if (_handle == 0) {
			return null;
		}
		EngineFrameDesc desc = new EngineFrameDesc();
		try {
			desc.structSize = 0;
			int result = _bindings.engineGetFrameDesc(_handle, desc);
			if (result != EngineBindings.kEngineResultOk) {
				return null;
			}
			return new EngineFrameInfo(
					desc.width,
					desc.height,
					desc.strideBytes,
					desc.pixelFormat,
					desc.frameSerial
					);
		} finally {
		
		}
	}
	
	public byte[] readFrameRgba() {
		if (_handle == 0) {
			return null;
		}
		EngineFrameInfo frameDesc = getFrameDesc();
		if (frameDesc == null) {
			return null;
		}

		int bufferSize = frameDesc.strideBytes * frameDesc.height;
		if (bufferSize <= 0) {
			return new byte[0];
		}

		byte[] buffer = new byte[bufferSize];
		try {
			int result = _bindings.engineReadFrameRgba(
						_handle,
		        		buffer,
		        		bufferSize
					);
			if (result != EngineBindings.kEngineResultOk) {
				return null;
			}
			return buffer;
		} finally {
		
		}
	}
	
	public EngineFrameData readFrameRgbaWithDesc() {
		return readFrameRgbaWithDesc(1);
	}
	
	public EngineFrameData readFrameRgbaWithDesc(int maxRetries) {
		if (_handle == 0) {
			return null;
		}
	    for (int attempt = 0; attempt <= maxRetries; attempt++) {
	    	EngineFrameInfo frameDesc = getFrameDesc();
	    	if (frameDesc == null) {
	    		return null;
	    	}

	    	final int bufferSize = frameDesc.strideBytes * frameDesc.height;
	    	if (bufferSize <= 0) {
	    		return new EngineFrameData(frameDesc, new byte[0]);
	    	}

	    	final byte[] buffer = new byte[bufferSize];
	    	try {
	    		final int result = _bindings.engineReadFrameRgba(
		    				_handle,
		    				buffer,
		    				bufferSize
	    				);
		        if (result == EngineBindings.kEngineResultOk) {
		        	return new EngineFrameData(
		        			frameDesc,
		        			buffer
		        			);
		        }
		        // Surface size can race with frame read; retry once with fresh desc.
		        if (result == EngineBindings.kEngineResultInvalidArgument && attempt < maxRetries) {
		        	continue;
		        }
		        return null;
	    	} finally {
	    		
	    	}
	    }
	    return null;
	}
	
	public int sendInput(EngineInputEventData event) {
		EngineInputEvent nativeEvent = new EngineInputEvent();
		try {
			nativeEvent.structSize = 0; 
		    nativeEvent.type = event.type;
		    nativeEvent.timestampMicros = event.timestampMicros;
		    nativeEvent.x = event.x;
		    nativeEvent.y = event.y;
		    nativeEvent.deltaX = event.deltaX;
		    nativeEvent.deltaY = event.deltaY;
		    nativeEvent.pointerId = event.pointerId;
		    nativeEvent.button = event.button;
		    nativeEvent.keyCode = event.keyCode;
		    nativeEvent.modifiers = event.modifiers;
		    nativeEvent.unicodeCodepoint = event.unicodeCodepoint;
			return _bindings.engineSendInput(_handle, nativeEvent);
		} finally {
		
		}
	}
	
	public int setRenderTargetIOSurface(
		   	int iosurfaceId,
		    int width,
		    int height
		    ) {
		return _bindings.engineSetRenderTargetIOSurface(
				_handle,
				iosurfaceId,
				width,
				height
			);
	}
	
	  /// Android: set render target surface.
	  /// On Android, the surface is set via JNI (nativeSetSurface) from the
	  /// Kotlin plugin. This FFI call is used to explicitly detach (pass nullptr).
	public int setRenderTargetSurface(int width, int height) {
	    // Pass nullptr to detach the surface render target
	    return _bindings.engineSetRenderTargetSurface(
			      _handle,
			      null,
			      width,
			      height
	    		);
	}

	public boolean getFrameRenderedFlag() {
		int[] outFlag = new int[1];
		try {
			int result = _bindings.engineGetFrameRenderedFlag(_handle, outFlag);
			if (result != EngineBindings.kEngineResultOk) {
				return false;
			}
			return outFlag[0] != 0;
		} finally {
		
		}
	}
	
	public String getRendererInfo() {
		if (_handle == 0) {
			return "";
		}
		final int bufferSize = 512;
		byte[] buffer = new byte[bufferSize];
		try {
			int result = _bindings.engineGetRendererInfo(
					_handle,
					buffer,
					bufferSize
					);
			if (result != EngineBindings.kEngineResultOk) {
				return "";
			}
			return new String(buffer);
		} finally {
		
		}
	}
	
	public EngineMemoryStatsData getMemoryStats() {
		if (_handle == 0) {
			return null;
		}
		EngineMemoryStats stats = new EngineMemoryStats();
	    try {
	    	int result = _bindings.engineGetMemoryStats(_handle, stats);
	    	if (result != EngineBindings.kEngineResultOk) {
	    		return null;
	    	}
	    	return new EngineMemoryStatsData(
	    			stats.selfUsedMb,
	    			stats.systemFreeMb,
	    			stats.systemTotalMb,
	    			stats.graphicCacheBytes,
	    			stats.graphicCacheLimitBytes,
	    			stats.xp3SegmentCacheBytes,
	    			stats.psbCacheBytes,
	    			stats.psbCacheEntries,
	    			stats.psbCacheEntryLimit,
	    			stats.psbCacheHits,
	    			stats.psbCacheMisses,
	    			stats.archiveCacheEntries,
	    			stats.archiveCacheLimit,
	    			stats.autopathCacheEntries,
	    			stats.autopathCacheLimit,
	    			stats.autopathTableEntries
	    			);
	    } finally {
	    
	    }
	}
	
	public String lastError() {
		String errorPtr = _bindings.engineGetLastError(_handle);
		if (errorPtr == null) {
		      return "";
		}
		return errorPtr;
	}
}
