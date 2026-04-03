::@echo off
@rmdir /s /q android_adt\libs
@rmdir /s /q android_adt\bin
@rmdir /s /q android_adt\gen
@rmdir /s /q apps\flutter_app\.dart_tool
@rmdir /s /q apps\flutter_app\android\.gradle
@rmdir /s /q apps\flutter_app\android\.kotlin
@rmdir /s /q apps\flutter_app\android\app\libs
@rmdir /s /q apps\flutter_app\ios\Flutter\ephemeral
@rmdir /s /q apps\flutter_app\linux\flutter\ephemeral
@rmdir /s /q apps\flutter_app\macos\Flutter\ephemeral
@rmdir /s /q apps\flutter_app\windows\flutter\ephemeral
@pause

