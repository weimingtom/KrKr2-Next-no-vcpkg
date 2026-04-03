package org.github.krkr2.flutter_engine_bridge;

public class EngineFrameData {
	  public EngineFrameData(EngineFrameInfo info, byte[] pixels) {
		  this.info = info; 
		  this.pixels = pixels;
	  }

	  public EngineFrameInfo info;
	  public byte[] pixels;
}
