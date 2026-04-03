@set PUB_HOSTED_URL=https://pub.flutter-io.cn
@set FLUTTER_STORAGE_BASE_URL=https://storage.flutter-io.cn
@set ANDROID_HOME=D:\home\soft\android_studio_sdk
@set PATH=D:\flutter_windows_3.41.4-stable\flutter\bin;C:\Program Files\Git\bin;%PATH%
@cmd

::flutter --version
::cd xxx\apps\flutter_app
::(not need) flutter pub get
::flutter build apk --verbose
