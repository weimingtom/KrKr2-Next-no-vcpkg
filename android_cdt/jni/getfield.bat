@echo off
@set path=D:\jdk1.7.0_45\bin;%path%
@set path=D:\home\soft\jdk1.8.0_91_64bit\jdk1.8.0_91\bin;%path%

::D:\home\soft\adt-bundle-windows-x86-20140624\sdk\platforms\android-17\android.jar
@javap -s -p -classpath ../bin/classes;./android.jar org.github.krkr2.flutter_engine_bridge.EngineCreateDesc > EngineCreateDesc.txt
@javap -s -p -classpath ../bin/classes;./android.jar org.github.krkr2.flutter_engine_bridge.EngineOption > EngineOption.txt
@javap -s -p -classpath ../bin/classes;./android.jar org.github.krkr2.flutter_engine_bridge.EngineFrameDesc > EngineFrameDesc.txt
@javap -s -p -classpath ../bin/classes;./android.jar org.github.krkr2.flutter_engine_bridge.EngineInputEvent > EngineInputEvent.txt
@javap -s -p -classpath ../bin/classes;./android.jar org.github.krkr2.flutter_engine_bridge.EngineMemoryStats > EngineMemoryStats.txt
::javap -help

@pause
@echo on

