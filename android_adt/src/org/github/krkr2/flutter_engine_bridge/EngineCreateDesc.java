package org.github.krkr2.flutter_engine_bridge;

/*
byte‌ - 1byte
‌short‌ - 2bytes
‌int‌ - 4bytes
‌long‌ - 8bytes
‌float‌ - 4bytes
‌double‌ - 8bytes
 */
public class EngineCreateDesc {
	  //@Uint32()
	  public int structSize;

	  //@Uint32()
	  public int apiVersion;

	  //Pointer<Utf8>
	  public String writablePathUtf8;
	  //Pointer<Utf8>
	  public String cachePathUtf8;
	  //Pointer<Void>
	  public long userData;

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
