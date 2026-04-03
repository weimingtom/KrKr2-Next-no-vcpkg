package org.github.krkr2.flutter_engine_bridge;

public class EngineMemoryStatsData {
	public EngineMemoryStatsData(
		  int selfUsedMb,
		  int systemFreeMb,
		  int systemTotalMb,
		  long graphicCacheBytes,
		  long graphicCacheLimitBytes,
		  long xp3SegmentCacheBytes,
		  long psbCacheBytes,
		  int psbCacheEntries,
		  int psbCacheEntryLimit,
		  long psbCacheHits,
		  long psbCacheMisses,
		  int archiveCacheEntries,
		  int archiveCacheLimit,
		  int autopathCacheEntries,
		  int autopathCacheLimit,
		  int autopathTableEntries) {
		this.selfUsedMb = selfUsedMb;
		this.systemFreeMb = systemFreeMb;
		this.systemTotalMb = systemTotalMb;
		this.graphicCacheBytes = graphicCacheBytes;
		this.graphicCacheLimitBytes = graphicCacheLimitBytes;
		this.xp3SegmentCacheBytes = xp3SegmentCacheBytes;
		this.psbCacheBytes = psbCacheBytes;
		this.psbCacheEntries = psbCacheEntries;
		this.psbCacheEntryLimit = psbCacheEntryLimit;
		this.psbCacheHits = psbCacheHits;
		this.psbCacheMisses = psbCacheMisses;
		this.archiveCacheEntries = archiveCacheEntries;
		this.archiveCacheLimit = archiveCacheLimit;
		this.autopathCacheEntries = autopathCacheEntries;
		this.autopathCacheLimit = autopathCacheLimit;
		this.autopathTableEntries = autopathTableEntries;
	}
	
	public int selfUsedMb;
	public int systemFreeMb;
	public int systemTotalMb;
	public long graphicCacheBytes;
	public long graphicCacheLimitBytes;
	public long xp3SegmentCacheBytes;
	public long psbCacheBytes;
	public int psbCacheEntries;
	public int psbCacheEntryLimit;
	public long psbCacheHits;
	public long psbCacheMisses;
	public int archiveCacheEntries;
	public int archiveCacheLimit;
	public int autopathCacheEntries;
	public int autopathCacheLimit;
	public int autopathTableEntries;
	
	@Override
	public String toString() {
		StringBuffer sb = new StringBuffer();
		sb.append("selfUsedMb == " + selfUsedMb).append("\n");
		sb.append("systemFreeMb == " + systemFreeMb).append("\n");
		sb.append("systemTotalMb == " + systemTotalMb).append("\n");
		sb.append("graphicCacheBytes == " + graphicCacheBytes).append("\n");
		sb.append("graphicCacheLimitBytes == " + graphicCacheLimitBytes).append("\n");
		sb.append("xp3SegmentCacheBytes == " + xp3SegmentCacheBytes).append("\n");
		sb.append("psbCacheBytes == " + psbCacheBytes).append("\n");
		sb.append("psbCacheEntries == " + psbCacheEntries).append("\n");
		sb.append("psbCacheEntryLimit == " + psbCacheEntryLimit).append("\n");
		sb.append("psbCacheHits == " + psbCacheHits).append("\n");
		sb.append("psbCacheMisses == " + psbCacheMisses).append("\n");
		sb.append("archiveCacheEntries == " + archiveCacheEntries).append("\n");
		sb.append("archiveCacheLimit == " + archiveCacheLimit).append("\n");
		sb.append("autopathCacheEntries == " + autopathCacheEntries).append("\n");
		sb.append("autopathCacheLimit == " + autopathCacheLimit).append("\n");
		sb.append("autopathTableEntries == " + autopathTableEntries).append("\n");
		return sb.toString();
	}
}
