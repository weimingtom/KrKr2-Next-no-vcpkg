package org.github.krkr2.flutter_engine_bridge;

public class EngineFrameInfo {
	public EngineFrameInfo(
			 int width,
			 int height,
			 int strideBytes,
			 int pixelFormat,
			 long frameSerial
			) {
		this.width = width;
		this.height = height;
		this.strideBytes = strideBytes;
		this.pixelFormat = pixelFormat;
		this.frameSerial = frameSerial;
	}
	
	public int width;
	public int height;
	public int strideBytes;
	public int pixelFormat;
	public long frameSerial;
}
