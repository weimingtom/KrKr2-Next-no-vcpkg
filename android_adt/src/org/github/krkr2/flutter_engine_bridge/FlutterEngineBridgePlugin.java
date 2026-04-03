package org.github.krkr2.flutter_engine_bridge;

import android.content.Context;
import android.view.Surface;

public class FlutterEngineBridgePlugin {
	static {
		try {
            System.loadLibrary("engine_api");
        } catch (UnsatisfiedLinkError e) {
            android.util.Log.w("krkr2", "engine_api native lib not found: " + e.getMessage());
        }
	}
	
    // JNI bridge to C++ (krkr2_android.cpp)
    public native void nativeSetSurface(Surface surface, int width, int height);
    public native void nativeDetachSurface();
    public native void nativeSetApplicationContext(Context context);
}
