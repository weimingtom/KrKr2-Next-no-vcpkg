package org.github.krkr2.flutter_app;

import java.util.concurrent.CopyOnWriteArrayList;

import org.github.krkr2.flutter_app_test2.R;
import org.github.krkr2.flutter_engine_bridge.EngineBindings;
import org.github.krkr2.flutter_engine_bridge.EngineFfiBridge;
import org.github.krkr2.flutter_engine_bridge.EngineInputEventData;
import org.github.krkr2.flutter_engine_bridge.EngineInputEventType;
import org.github.krkr2.flutter_engine_bridge.EngineMemoryStatsData;
import org.github.krkr2.flutter_engine_bridge.FlutterEngineBridgePlugin;
import org.github.krkr2.flutter_engine_bridge.PrefsKeys;
import org.tvp.kirikiri2.KR2Activity;

import com.foobnix.pdf.info.Android6;

import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.view.View.OnTouchListener;

//see apps\flutter_app\lib\pages\game_page.dart
//bridge\flutter_engine_bridge\lib\flutter_engine_bridge.dart
//await _bridge.engineTick
//await _bridge.engineCreate();
//await _bridge.engineSetOption(
//unawaited(_bridge.engineDestroy());
//await _bridge.engineOpenGameAsync(
//    final int result = await widget.bridge.engineSetSurfaceSize(
//
//final bool rendered = await _bridge.engineGetFrameRenderedFlag();
//_rendererInfo = _bridge.engineGetRendererInfo();


//final state = await _bridge.engineGetStartupState();
//await _drainStartupLogs();
// final stats = await _bridge.engineGetMemoryStats();
//_bridge.engineGetLastError()

//final int result = await _bridge.enginePause();
//final int result = await _bridge.engineResume();

// unawaited(_sendInputEvent(pending));
public class MainActivity extends KR2Activity implements SurfaceHolder.Callback, Runnable {
	private final String TAG = "krkr2";//MainActivity.class.getSimpleName();

//	private native int nativeInit();
//	private native void nativeSurfaceInit(Object surface);
//	private native void nativeSurfaceFinalize();
//	private native void nativeVideoPlay();
//	private native void nativeVideoStop();
	
	private FlutterEngineBridgePlugin plugin = new FlutterEngineBridgePlugin();
	private EngineFfiBridge _bridge = new EngineFfiBridge();

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
        try {
        	plugin.nativeSetApplicationContext(this.getApplicationContext());
        } catch (UnsatisfiedLinkError e) {
            android.util.Log.w("krkr2", "nativeSetApplicationContext not available: " + e.getMessage());
        }
		

		findViewById(R.id.btn_play).setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				new Thread(MainActivity.this).start();
			}
		});
		
		findViewById(R.id.btn_stop).setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				//nativeVideoStop();
			}
		});
	
		
		if (!Android6.canWrite(this)) {
            Android6.checkPermissions(this, true);
            return;
        } else{
    		SurfaceView sv = (SurfaceView) this.findViewById(R.id.video_view);
    		SurfaceHolder sh = sv.getHolder();
    		sh.addCallback(this);
    		sv.setFocusable(true);
    		sv.setFocusableInTouchMode(true);
    		sv.setOnTouchListener(new OnTouchListener() {
				@Override
				public boolean onTouch(View view, MotionEvent event) {
					switch (event.getAction()) {
					case MotionEvent.ACTION_DOWN:
						_sendPointer(EngineInputEventType.pointerDown, event, null, null);
		                return true;
		            
					case MotionEvent.ACTION_MOVE:
						_sendPointer(EngineInputEventType.pointerMove, event, null, null);
		                return true;
		            
					case MotionEvent.ACTION_UP:
						_sendPointer(EngineInputEventType.pointerUp, event, null, null);
						return true;
		            
					case MotionEvent.ACTION_CANCEL:
		                return true;
					}
		            return true;
				}
    		});
    		
        }
	}
	
    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        Android6.onRequestPermissionsResult(this, requestCode, permissions, grantResults);
    }

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public void surfaceChanged(SurfaceHolder holder, int format, int width,
			int height) {
		Log.i(TAG, "surfaceChanged");
		//nativeSurfaceInit(holder.getSurface());
		
		
        // Pass the Surface to the C++ engine via JNI
        try {
        	plugin.nativeSetSurface(holder.getSurface(), width, height);
            Log.i("krkr2", "plugin.nativeSetSurface: size=" + width + "x" + height);
        } catch (UnsatisfiedLinkError e) {
            android.util.Log.e("krkr2", "nativeSetSurface not available: " + e.getMessage());
        }
        
		//int init = nativeInit();
		//Log.i(TAG, "init result " + init);
	}

	private Thread mainThread = null;
	@Override
	public void surfaceCreated(SurfaceHolder holder) {
		//FIXME:surfaceCreated not run only once
		if (true) {
			if (mainThread == null) {
				mainThread = new Thread(this);
				mainThread.start();
			}
		} else {
			run();
		}
	}


	@Override
	protected void onPause() {
		super.onPause();
		if (_bridge != null) {
//			_bridge.pause();
			plugin.nativeDetachSurface();
            _bridge.setRenderTargetSurface(0, 0);
		}
		
	}

	@Override
	protected void onResume() {
		super.onResume();
		if (_bridge != null) {
//			_bridge.resume();
		}
	}



	private boolean isDestroyed = false;
	@Override
	public void surfaceDestroyed(SurfaceHolder holder) {
		//FIXME: surfaceDestroyed() not execute once
		Log.i(TAG, "surfaceDestroyed");
		//nativeSurfaceFinalize();
		
		if (false) {
	        // Detach from the C++ engine
			isDestroyed = true;
	    	try {
	        	plugin.nativeDetachSurface();
	            Log.i("krkr2", "plugin.nativeDetachSurface");
	        } catch (UnsatisfiedLinkError e) {
	            android.util.Log.e("krkr2", "nativeDetachSurface not available: " + e.getMessage());
	        }
		}
	}
	
	public void log(String str) {
		Log.i(TAG, "log : " + str);
	}
	
	//adb logcat -s krkr2:D *:E
	@Override
	public void run() {
		//nativeVideoPlay();
		int result = _bridge.create(null, null);
		if (result != EngineBindings.kEngineResultOk) {
			Log.e("krkr2", "create() failed, result== " + result + ": " + _bridge.getLastError());
			return;
		}
		
		int api_version = _bridge.runtimeApiVersion();
		Log.i("krkr2", "api_version == " + Integer.toHexString(api_version));
		//api_version == 1000000
		
		EngineMemoryStatsData stats = _bridge.getMemoryStats();
		Log.i("krkr2", "stats == " + stats);
		
		//don't execute tick() before openGame() or openGameAsync()
		//int tick_result = _bridge.tick();
		//Log.i("krkr2", "_bridge.tick() == " + tick_result);

		//bridge\engine_api\include\engine_options.h
		_bridge.setOption(PrefsKeys.angleBackend, PrefsKeys.angleBackendGles);
		if (false) {
			_bridge.setOption(PrefsKeys.renderer, PrefsKeys.rendererOpengl);
		} else {
			_bridge.setOption(PrefsKeys.renderer, PrefsKeys.rendererSoftware);	
		}
		
		_bridge.openGameAsync("/storage/emulated/0/Download/Spring Days/Data.xp3", null); //this should be a tail call
		while (!isDestroyed) {
			int tick_result = _bridge.tick();
			if (tick_result != EngineBindings.kEngineResultOk && tick_result != EngineBindings.kEngineResultInvalidState) { //-2) {
				Log.i("krkr2", "_bridge.tick() == " + tick_result);
			}
			synchronized (lock) {
				int size = eventList.size();
				for (int i = 0; i < size; ++i) {
					_sendInputEvent(eventList.get(i));
				}
				eventList.clear();
			}
		}
		
		//FIXME: openGameAsync will startup a std::thread, don't call destroy() here
		//_bridge.destroy();
	}

	@Override
	protected void onDestroy() {
		if (_bridge != null) {
			_bridge.destroy();
			_bridge = null;
		}
		super.onDestroy();
	}
	
	private void _sendInputEvent(EngineInputEventData event) {
	    final int result = _bridge.sendInput(event);
	    if (result != 0) {
	    	Log.i("krkr2", "engine_send_input failed: result=" + result + ", error=" + _bridge.getLastCreateError());
	    }
	}
	
	
	private CopyOnWriteArrayList<EngineInputEventData> eventList = new CopyOnWriteArrayList<EngineInputEventData>();
	private Object lock = new Object();
	private void _sendInputQueue(EngineInputEventData event) {
		synchronized (lock) {
			eventList.add(event);
		}
	}
	
	private void _sendPointer(
	    int type,
	    MotionEvent event,
	    Double deltaX,
	    Double deltaY
	  ) {
//	    if (!widget.active) {
//	      return;
//	    }
		_sendInputQueue(//_sendInputEvent(
	    	getEngineInputEventData(
	          type,
	          event,
	          deltaX,
	          deltaY
	        )
	     );
	  };
	
	private EngineInputEventData getEngineInputEventData(
		    int type,
		    MotionEvent event,
		    Double deltaX,
		    Double deltaY
		  ) {
		    // Map pointer position from Listener's logical coordinate space
		    // to the engine surface's physical pixel coordinates.
		    //
		    // Listener's localPosition is in logical pixels. The engine's
		    // EGL surface is sized in physical pixels (logical * dpr), so
		    // multiply by dpr to get surface coordinates.
		    //
		    // The C++ side (DrawDevice::TransformToPrimaryLayerManager)
		    // then maps these surface coordinates → primary layer coordinates.
		    final double dpr = 1.0;//_devicePixelRatio > 0 ? _devicePixelRatio : 1.0;
		    EngineInputEventData result = new EngineInputEventData();
		    result.type = type;
		    result.timestampMicros = event.getEventTime();
		    result.x = event.getX() * dpr;
		    result.y = event.getY() * dpr;
		    result.deltaX = (deltaX != null ? deltaX : 0/*event.delta.dx*/) * dpr;
		    result.deltaY = (deltaY != null ? deltaY : 0/*event.delta.dy*/) * dpr;
		    result.pointerId = event.getPointerId(0);
		    result.button = 0;//_flutterButtonsToEngineButton(event.button);
		    return result;
	}
	
//	  static int _flutterButtonsToEngineButton(int buttons) {
//		    if (buttons & kSecondaryButton != 0) return 1; // right
//		    if (buttons & kMiddleMouseButton != 0) return 2; // middle
//		    return 0; // left (default)
//		  }

	
}
