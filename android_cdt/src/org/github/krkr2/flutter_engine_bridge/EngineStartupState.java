package org.github.krkr2.flutter_engine_bridge;

public enum EngineStartupState {
	ENGINE_STARTUP_STATE_IDLE(0),
	ENGINE_STARTUP_STATE_RUNNING(1),
	ENGINE_STARTUP_STATE_SUCCEEDED(2),
	ENGINE_STARTUP_STATE_FAILED(3);
	
	private final int code;

    private EngineStartupState(int code) {
        this.code = code;
    }

    public int getCode() {
        return code;
    }
}
