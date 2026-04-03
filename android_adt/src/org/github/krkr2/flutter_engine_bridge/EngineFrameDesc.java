package org.github.krkr2.flutter_engine_bridge;

public class EngineFrameDesc {
	  //@Uint32()
	  public int structSize;

	  //@Uint32()
	  public int width;

	  //@Uint32()
	  public int height;

	  //@Uint32()
	  public int strideBytes;

	  //@Uint32()
	  public int pixelFormat;

	  //@Uint64()
	  public long frameSerial;

	  //@Uint64()
	  public long reservedU640;

	  //@Uint64()
	  public long reservedU641;

	  //@Uint64()
	  public long reservedU642;

	  //@Uint64()
	  public long reservedU643;

	  //Pointer<Void>
	  public long reservedPtr0;
	  public long reservedPtr1;
	  public long reservedPtr2;
	  public long reservedPtr3;
}
