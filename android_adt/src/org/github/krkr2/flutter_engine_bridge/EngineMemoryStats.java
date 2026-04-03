package org.github.krkr2.flutter_engine_bridge;

public class EngineMemoryStats {
	  //@Uint32()
	  public int structSize;

	  //@Uint32()
	  public int selfUsedMb;

	  //@Uint32()
	  public int systemFreeMb;

	  //@Uint32()
	  public int systemTotalMb;

	  //@Uint64()
	  public long graphicCacheBytes;

	  //@Uint64()
	  public long graphicCacheLimitBytes;

	  //@Uint64()
	  public long xp3SegmentCacheBytes;

	  //@Uint64()
	  public long psbCacheBytes;

	  //@Uint32()
	  public int psbCacheEntries;

	  //@Uint32()
	  public int psbCacheEntryLimit;

	  //@Uint64()
	  public long psbCacheHits;

	  //@Uint64()
	  public long psbCacheMisses;

	  //@Uint32()
	  public int archiveCacheEntries;

	  //@Uint32()
	  public int archiveCacheLimit;

	  //@Uint32()
	  public int autopathCacheEntries;

	  //@Uint32()
	  public int autopathCacheLimit;

	  //@Uint32()
	  public int autopathTableEntries;

	  //@Uint32()
	  public int reservedU32;

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
