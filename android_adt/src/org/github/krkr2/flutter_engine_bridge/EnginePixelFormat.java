package org.github.krkr2.flutter_engine_bridge;

public enum EnginePixelFormat {
	ENGINE_PIXEL_FORMAT_UNKNOWN(0),
	ENGINE_PIXEL_FORMAT_RGBA8888(1);

	private final int code;

    private EnginePixelFormat(int code) {
        this.code = code;
    }

    public int getCode() {
        return code;
    }
}
