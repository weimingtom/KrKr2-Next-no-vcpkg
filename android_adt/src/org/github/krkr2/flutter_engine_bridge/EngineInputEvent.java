package org.github.krkr2.flutter_engine_bridge;

public class EngineInputEvent {
	  //@Uint32()
	  public int structSize;

	  //@Uint32()
	  public int type;

	  //@Uint64()
	  public long timestampMicros;

	  //@Double()
	  public double x;

	  //@Double()
	  public double y;

	  //@Double()
	  public double deltaX;

	  //@Double()
	  public double deltaY;

	  //@Int32()
	  public int pointerId;

	  //@Int32()
	  public int button;

	  //@Int32()
	  public int keyCode;

	  //@Int32()
	  public int modifiers;

	  //@Uint32()
	  public int unicodeCodepoint;

	  //@Uint32()
	  public int reservedU32;

	  //@Uint64()
	  public long reservedU640;

	  //@Uint64()
	  public long reservedU641;

	  //Pointer<Void>
	  public long reservedPtr0;
	  public long reservedPtr1;
}
