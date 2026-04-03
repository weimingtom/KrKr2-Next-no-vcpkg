package org.github.krkr2.flutter_engine_bridge;

public enum EngineResult {
	ENGINE_RESULT_OK(0),
	ENGINE_RESULT_INVALID_ARGUMENT(-1),
	ENGINE_RESULT_INVALID_STATE(-2),
	ENGINE_RESULT_NOT_SUPPORTED(-3),
	ENGINE_RESULT_IO_ERROR(-4),
	ENGINE_RESULT_INTERNAL_ERROR(-5);
	  
	private final int code;

    private EngineResult(int code) {
        this.code = code;
    }

    public int getCode() {
        return code;
    }
}
