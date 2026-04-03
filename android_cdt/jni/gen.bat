@echo off
@set path=D:\jdk1.7.0_45\bin;%path%
@set path=D:\home\soft\jdk1.8.0_91_64bit\jdk1.8.0_91\bin;%path%

::D:\home\soft\adt-bundle-windows-x86-20140624\sdk\platforms\android-17\android.jar
@javah -jni -classpath ../bin/classes;./android.jar org.github.krkr2.flutter_engine_bridge.FlutterEngineBridgePlugin
@javah -jni -classpath ../bin/classes;./android.jar org.github.krkr2.flutter_engine_bridge.EngineBindings

@pause
@echo on
