package org.github.krkr2.flutter_engine_bridge;

public enum EngineInputEventType {
	ENGINE_INPUT_EVENT_POINTER_DOWN(1),
	ENGINE_INPUT_EVENT_POINTER_MOVE(2),
	ENGINE_INPUT_EVENT_POINTER_UP(3),
	ENGINE_INPUT_EVENT_POINTER_SCROLL(4),
	ENGINE_INPUT_EVENT_KEY_DOWN(5),
	ENGINE_INPUT_EVENT_KEY_UP(6),
	ENGINE_INPUT_EVENT_TEXT_INPUT(7),
	ENGINE_INPUT_EVENT_BACK(8);
	
	private final int code;

    private EngineInputEventType(int code) {
        this.code = code;
    }

    public int getCode() {
        return code;
    }
    
	  public static final int pointerDown = 1;
	  public static final int pointerMove = 2;
	  public static final int pointerUp = 3;
	  public static final int pointerScroll = 4;
	  public static final int keyDown = 5;
	  public static final int keyUp = 6;
	  public static final int textInput = 7;
	  public static final int back = 8;
}
