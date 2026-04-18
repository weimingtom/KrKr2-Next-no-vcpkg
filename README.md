# KrKr2-Next-no-vcpkg
[Very WIP and NOT RECOMMENDED] My KrKr2-Next fork for Android, without vcpkg, flutter, ffmpeg and boost

## References  
* https://github.com/reAAAq/KrKr2-Next  
* https://github.com/reAAAq/KrKr2-Next/tree/9b4d67e71498f87fda8718903763b6b8a792ed6a  
* https://github.com/panreyes/pixtudio/tree/master/3rdparty  
* https://github.com/weimingtom/eriri/blob/master/myjnistudy/doc/jniexamples.zip
* Spring Days.rar, https://code.google.com/archive/p/godxq1986/downloads  
* Spring Days.rar, https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/godxq1986/Spring%20Days.rar  

## How to build non-flutter apk with Android ADT under Windows
* cd android_adt/jni 
* Double click console.bat (modify the path %PATH% points to your Android NDK path in console.bat by yourself)  
```
::@set PATH=D:\android-ndk-r9c;%PATH%
::@set PATH=D:\android-ndk-r10e;%PATH%
@set PATH=D:\home\soft\android_studio_sdk\ndk\25.2.9519653;%PATH%
@set NDK_MODULE_PATH=%CD%\..\..\cpp
@cmd
```
* ndk-build clean
* ndk-build -j8 (or ndk-build NDK_DEBUG=1 -j8, see adb_logcat_and_debug_crash.txt)
* Get libengine_api.so under android_adt/libs/arm64-v8a/libengine_api.so
* Use Android ADT to load android_adt/.project
* Put https://github.com/weimingtom/KrKr2-Next-no-vcpkg/blob/master/_testdata/data.xp3 to "/storage/emulated/0/Download/Spring Days/Data.xp3" in the ARM64 Android device  
```
_bridge.openGameAsync("/storage/emulated/0/Download/Spring Days/Data.xp3", null); //this should be a tail call
```
see also https://github.com/weimingtom/KrKr2-Next-no-vcpkg/blob/master/android_adt/src/org/github/krkr2/flutter_app/MainActivity.java  
* Compile the non-flutter apk file and install it to the Android device, **Now only support ARM64 Android device**   

## How to build for Flutter under Windows (NOT RECOMMENDED)  
* Build android_adt/libs/arm64-v8a/libengine_api.so through ndk-build in 【How to build non-flutter apk with Android ADT under Windows】 
* Copy android_adt/libs/arm64-v8a/libengine_api.so to apps/flutter_app/android/app/libs/arm64-v8a/libengine_api.so
* Double click apps/flutter_app/console.bat (modify the paths %ANDROID_HOME% and %PATH% point to your Android SDK and Flutter SDK and Git in console.bat by yourself)  
```
@set PUB_HOSTED_URL=https://pub.flutter-io.cn
@set FLUTTER_STORAGE_BASE_URL=https://storage.flutter-io.cn
@set ANDROID_HOME=D:\home\soft\android_studio_sdk
@set PATH=D:\flutter_windows_3.41.4-stable\flutter\bin;C:\Program Files\Git\bin;%PATH%
@cmd

::flutter --version
::cd xxx\apps\flutter_app
::(not need) flutter pub get
::flutter build apk --verbose
```
* flutter build apk (no need to run flutter pub get)
* Get apk file, install it to the Android device, **Now only support ARM64 Android device**        
* Put https://github.com/weimingtom/KrKr2-Next-no-vcpkg/blob/master/_testdata/data.xp3 to "/storage/emulated/0/Download/Spring Days/Data.xp3" in the ARM64 Android device, then open it with this installed flutter apk    
* NOT RECOMMENDED, because you should build the apk with original code, 
https://github.com/reAAAq/KrKr2-Next  
Also, you can try to modify this code here to directly call "display = eglGetDisplay(EGL_DEFAULT_DISPLAY);" without any fallback, if you get a black EGL screen   
https://github.com/reAAAq/KrKr2-Next/blob/9b4d67e71498f87fda8718903763b6b8a792ed6a/cpp/core/visual/ogl/krkr_egl_context.cpp    
```
EGLDisplay EGLContextManager::AcquireAngleDisplay(AngleBackend& backend) {
#if defined(__ANDROID__)
...
    EGLDisplay display = EGL_NO_DISPLAY;
#if 1 //MY_USE_MINLIB
//android skip here
#else
    if (eglGetPlatformDisplayEXT_) {
        const EGLint displayAttribs[] = {
            EGL_PLATFORM_ANGLE_TYPE_ANGLE,
            angleType,
            EGL_NONE
        };
        display = eglGetPlatformDisplayEXT_(
            EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, displayAttribs);
        EGL_LOGI("AcquireAngleDisplay: eglGetPlatformDisplayEXT returned %p", display);
    }
    // Fallback: if Vulkan backend failed, retry with OpenGL ES
    if (display == EGL_NO_DISPLAY && backend == AngleBackend::Vulkan && eglGetPlatformDisplayEXT_) {
        EGL_LOGI("AcquireAngleDisplay: Vulkan backend failed, falling back to OpenGL ES");
        backend = AngleBackend::OpenGLES;
        const EGLint fallbackAttribs[] = {
            EGL_PLATFORM_ANGLE_TYPE_ANGLE,
            EGL_PLATFORM_ANGLE_TYPE_OPENGLES_ANGLE,
            EGL_NONE
        };
        display = eglGetPlatformDisplayEXT_(
            EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, fallbackAttribs);
        EGL_LOGI("AcquireAngleDisplay: fallback eglGetPlatformDisplayEXT returned %p", display);
    }
#endif
    if (display == EGL_NO_DISPLAY) {
        EGL_LOGI("AcquireAngleDisplay: fallback to eglGetDisplay(EGL_DEFAULT_DISPLAY)");
        display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    }
    return display;
```

## weibo record
```
2026-2-27
另外我还发现一个新项目reAAAq/KrKr2-Next，也是完成度比较高的，它的介绍说是：
《基于 Flutter + ANGLE 重构的 KiriKiri2 跨平台视觉小说模拟器，
支持 Metal Vulkan D3D11 现代图形后端》，我可能考虑编译它的安卓版，
但目前完全没有头绪。我知道Flutter是可以用来开发安卓的，
也编译打包过flutter安卓代码，但这个开源项目能不能编译和跑起来，目前还不确定。
主要是因为它可能也是用vcpkg编译的（可能），我电脑的硬盘可能不够，
当然我可以试试，也许编译不会很难——当然这种东西99的可能都是巨难编译的，
能编译出来算我输

我尝试在windows下编译reAAAq/KrKr2-Next（因为我的安卓sdk在windows下），结果失败。
其实还有其他可能的办法，但我暂时没试，可能等过几个星期再试。
失败的原因可能是vcpkg检出代码库时失败了（不知道为什么）。
如果要解决这个问题，有两种办法，一种是完全用Linux编译，
另一种是只在Linux下执行cmake编译（cmake参数在gradle文件中）。
另外这个开源项目的vcpkg是固定的相对路径，这个相对路径也写在gradle文件中。
如果是windows下安装vcpkg，只需要把一个exe放在目录里面就可以完成安装，
可能比Linux安装vcpkg还容易，然后导出VCPKG_ROOT全局环境变量指向exe所在的目录即可

我好像找到方法在xubuntu 25.04上单独用cmake编译reAAAq/KrKr2-Next的安卓动态库，
但坏消息是——这个代码要编译的vcpkg库也是多得吓人，我等周末有时间再试试，没时间不敢玩这个玩意 ​​​

测试了很多次，好像还是没办法运行我自己编译的KrKr2-Next。我打算先把Android.mk写好，
看有没有其他方法跑起来。实际上它对接C++代码的方法并不复杂，
是通过Flutter插件的方式加载JNI动态库的，所以应该可以另外模拟一个Surface的环境，
看能不能调用到JNI动态库 ​​​

我开始研究Android.mk和ndk-build编译reAAAq/KrKr2-Next，大概可能要一个月时间才能编译出来，
至于能否运行，还不确定。为什么不能编译linux版？因为它好像也不是用SDL跑的，
它的安卓版可能是通过Surface或gles输出显示内容。为什么要编译它？因为它里面有一些修改，
去掉了cocos2d-x的依赖编译，可能以后方便用来移植到SDL2（当然，我只是推测，也可能还是不可以）。
简单说，我不确定我能把它从flutter上移出来，用其他方式显示。目前只是想把它编译出来，
但不使用cmake和vcpkg

KrKr2-Next研究，今天大概把Android.mk写好，分静态库编译，把cmake verbose输出的所有cpp代码
都用ndk-build编译一遍，vcpkg第三方库只用头文件编译，如果库可以跳过，则在代码中注释掉
（例如ffmpeg），可以多线程ndk-build编译（8线程大概需要10到15分钟左右），但链接失败，
接下来看能不能把第三方库也ndk-build编译一下，看有一些库能不能也去掉，
例如体积最庞大的boost库

KrKr2-Next研究。移除boost，主要用于locale字符串转换和多个插件，插件的话只能无情移除，
如果是字符串转换可以用我以前修改的代码，实在没有办法只能用std::codecvt_utf8_utf16和
std::wstring_convert来硬着转换了（我不知道是否正确，只是编译是通过的），
而且原版是带字符编码的，所以我这样改显然是不对的，先不管

KrKr2-Next研究。把opencv4降级到opencv2（换回我自己用的版本），这样方便我用ndk-build
编译第三方的静态库——虽然，这个模块只能用c++11编译，用c++17编译不了，不过也没关系，
原版opencv较新，但我不想研究，节省时间，其他第三方库也会尽量这样处理，
或者等后面如果最终链接失败再回过头来修改。目前所有代码还能编译成功，就是链接不了

KrKr2-Next研究。把SDL-2.32.10降级到SDL2-2.0.10，并且编译成动态库。为什么不编译成静态库？
因为它有些地方需要jni native调用，可以减少对它源代码的修改，
因为它可能需要动态库加载时执行一些方法。其实理论上应该没用到SDL，
但播放声音时会用到，不知道为什么，所以暂时保留，后面如果需要显示，
SDL也可能会用到，但总体而言这个项目多半不是通过SDL来显示的

KrKr2-Next研究。把opusfile和opus降级到我原来用的Android.mk库。这样改下去是不是很顺利？
不一定，因为有20多个外部库，其中只有一半左右是可以换以前用过的，
但有一半需要自己改，会花很多时间研究。另外有一些库即便以前用过也要研究，
例如libjpeg-turbo这个库，我要用它原版的才行，用旧版会有一些地方编译错误，
缺少符号，我只是不想改，只能说有一些库的API是不稳定的，不能切换回旧版本代码

KrKr2-Next研究。整理glm和oboe，glm是纯头文件，oboe是播放声音的库，
虽然oboe是cmake编译，不过因为cmake文件比较简单，可以很容易复制到Android.mk编译。
其实KrKr2-Next底层有三个播放声音的库，这只是其中一个，
其他就完全是按顺序如果前面失败了就用下一个，次序是oboe->sdl2->openal-soft，
不过sdl2其实可能压根就不会调用到

KrKr2-Next研究。现在可以用ndk-build编译出来了，8进程大概要5-10分钟左右
（具体我还没测试，但不会很慢），我甚至把SDL2动态库改代码移除，
但放入flutter内运行还是没有输出。后面就是最难的过程，自己想一个调用方法出来 ​​​

KrKr2-Next研究。(1）火星，spdlog好像也是纯头文件的
（2）准备自己写一个Android Java类去加载libengine_api.so这个动态库。
其实它的安卓版的显示也是基于Surface类的（和SurfaceView有关），
具体的绑定是在ANativeWindow_fromSurface和nativeSetSurface，
而这个接口有公式代码可以抄，我手头上就有一份代码是用这个api去显示FFMPEG的，
我打算抄过来，试试能不能看到输出。另外，大部分的动态库调用是通过flutter/dart的
ffi（字符串函数名调用动态库），具体位置是在engine_bindings.dart，而启动入口是
在_bridge.engineOpenGameAsync，传入xp3路径作为参数

KrKr2-Next研究。现在研究速度会变慢，我主要是以看代码为主，至于能不能跑起来，
我也没把握，总之就是现在也没跑起来，就算放到flutter里面跑也是看不到图像输出。
上次把动态库so编译出来（我顺便改成c++static，并且去掉SDL2的动态库，
所以现在只需要一个so文件）。这次把android adt工程搭建好，
自己写一个Java类去调用这个libengine_api.so文件，可以看到C代码里面的日志。
接下来，我打算尝试调用engine_api.h里面的函数，看能不能简单跑起来（不需要看到图像输出）

KrKr2-Next研究。JNI对接了一半，还差初始化c结构体和读取c结构体的代码。原版的对接是通过
flutter/dart ffi实现的，我这里是纯手写jni代码（因为我这里的c语言绑定的是java而不是绑定dart），
等JNI对接完就可以开始写逻辑了，如果只是运行可能只需要使用其中少数几个接口，
所以可以一边运行一边写逻辑，但目前还不能运行

KrKr2-Next研究。JNI对接完了（我也不知道对不对，乱写），接下来可以尝试照着dart代码把启动代码
的Java版写出来（原版不是Java写的，是用dart和ffi库写的，所以我相当于另外写一个新的启动代码出来），
顺便看看一些接口是怎么用的。其实我之前用flutter跑过，虽然我编译的libengine_api.so没有图像输出，
但可以看到日志，所以我现在的目标是能看到这些进入时的日志，就算没图像也无所谓

KrKr2-Next研究。感觉现在是给engine_api的接口做单元测试。把Android6的读写存储权限请求Java代码加上去
（原版不是这样写）。目前可以看到一些PushStartupLog的内容（或者说是spdlog::info和
spdlog::debug之类日志输出，重定向到adb logcat，但似乎漏了一些没输出。
原版是输出到手机界面上但不会输出到adb），不过还是crash了，原因不明。
另外千万不能在engine_open_game_async之后立刻调用engine_destroy，
因为engine_open_game_async会启动c++线程std::thread，立刻销毁的话相当
于c++线程就会crash，应该永远都不调用engine_destroy或者放在onDestroy()时调用。
另外我感觉我编译的libengine_api.so放在flutter上没有显示输出，很可能是
因为egl初始化失败了，至于为什么会出现这个日志错误，还不清楚，有可能我解决了
这个问题，flutter版就能用了（当然，我只是猜测）

KrKr2-Next研究。为了看清楚crash的后退堆栈位置，我把原版代码里的InstallCrashSignalHandlers()
去掉，这样的话adb logcat可以显示出crash的代码位置，用ndk-stack看到是crash在
(const char *)glGetString(GL_EXTENSIONS)这里。为什么会在这里crash？想不通，
有可能是因为前面的eglInitializeImpl:304 error 3008 (EGL_BAD_DISPLAY)错误导致的，
我需要在engine_open_game_async前调用engine_tick才行。有时间再试试

KrKr2-Next研究。改了一下，现在可以不crash运行engine_open_game_async了，
而且不需要提前调用engine_tick（代码里面其实限制了必须在open_game之后才能
调用engine_tick，参考engine_tick里面的!g_runtime_active）。我的修改是
在krkr_egl_context.cpp，里面有个EGLContextManager::AcquireAngleDisplay的函数，
里面有一段代码是通过Vulkan和OpenGLES的fallback写法来获取EGL display对象，
但这种写法有问题，也许在某些手机设备上是正常的，但在我的手机上这段代码会
导致libEGL 3008错误，然后后面就不会有输出了，最简单的做法应该改成直接
调用eglGetDisplay(EGL_DEFAULT_DISPLAY)获取EGLDisplay对象而不是fallback，
因为原来的代码虽然也这样做但fallback失败了——没有判断到这样获取的display虽然
不是EGL_NO_DISPLAY(0)但也是不能用的，至于要怎么改比较好，待考，
我是直接注释掉前面的操作只保留最后的eglGetDisplay(EGL_DEFAULT_DISPLAY)。
我有时间看看能不能用flutter运行我修改了这个问题之后的动态库

2026-3-26
KrKr2-Next研究。Flutter版跑通了，其实就是改一下eglGetDisplay的代码，
跳过fallback代码，然后用默认gles渲染就可以正常跑起来。不过我魔改了很多地方，
导致声音有问题（需要把SDL2代码重新加回去），我还把c++shared改成c++static。
由于只编译arm6的动态库没有32位支持，所以旧手机也跑不了，我测试运行的是红米12C手机。
另外日志输出是乱字，因为我去掉boost，也因为这个原因大部分plugin dll的
代码都没有编译进来，所以建议等官方正式版，我这个缺了很多插件支持。
后面还要继续研究jni方式运行（我自己写Java和JNI代码去调用这个动态库）

KrKr2-Next研究。把SDL2的代码加回去编译，flutter android版的声音卡的问题就解决了，
仍然只编译出一个so动态库，把libSDL2改成静态库——把里面的JNI_OnLoad去掉，
这里我已经不需要用SDL2在安卓上显示，所以类似的回调可以忽略，其他SDL2的
安卓JNI函数也可以忽略不管（只用到SDL2的几个声音处理函数）。
至于其他平台，也有可能不用SDL2显示了，这个以后再说。

KrKr2-Next研究。加上engine_tick函数调用后，Java版现在可以看到输出了，
但鼠标输入还没对接，所以目前没办法交互；似乎只能横屏，如果旋转屏幕的
话图像输出有问题（变成一个小的窗口，待考）；另外暂停和恢复也没对接。
这个版本的接口是我自己想的，原版没有对接到Java的JNI接口代码 ​​​

KrKr2-Next研究。今天研究的差不多了，我打算下个月4月底前把我的修改版fork放到gh上，
在放上去之前我尝试把它移植到linux，这样更容易编译和编译得更快
（直接apt install），如果不行就算了。其实现在就可以放上去，
最好等原作者发布正式版之后。这个开源项目的意义在于，
我可以参考它的思路把我的kirikiroid2lite的cocos2d-x换成gles或者SDL2，
当然这只是我的猜测，如果真做起来可能还是比较麻烦，
但至少理论上是可行的，KrKr2-Next就相当于去掉了cocos2d-x的kirikiroid2

KrKr2-Next研究。Java安卓版可以对接到触碰输入了，当然我只对接了三个鼠标事件，
左键按下、拖动和弹起，通过motionevent来转换（SurfaceView的setOnTouchListener）
——不过我没想到这里有个问题，就是不能直接发送事件到JNI，
而是要在engine_create所在的线程发送才能成功（别问为什么，我也想知道），
所以我在发送输入事件时先把事件对象压入一个队列数据结构，
然后在event_tick循环的时候读取和清空这个队列，这样就能确保在
同一个线程发送消息了，所以写出来很像消息泵，当然这里是发送而
不是接收事件

KrKr2-Next研究。用Ubuntu 25.04和makefile编译一下Linux版，大部分代码都能编译，
只有少数几个看上去不重要的文件编译不了，只能暂时跳过。目前Linux版还不能运行，
因为原版最新代码也是没有完整移植到Linux。我可以参考Android版的移植方法移植，
但我不是用flutter的思路，而是大概会用glfw3的方式显示gles，至于作者说的ANGLE，
虽然也可以，但在Linux下肯定是优先用mesa模拟的gles而不是ANGLE，当然也可以
试试用ANGLE——当然这些目前是还没开始移植，只是想想

KrKr2-Next研究。开始研究Linux版的编译（原版没有真的移植到Linux，要自己想），
把glfw3+gles环境的测试代码的脚手架嵌入到代码中，切换到xubuntu 20.04，
并且把engine_api的接口调用封装方法写到main.cpp中。当然目前是跑不了的，
在engine_create()就返回错误了，未调试，可能还需要比较长时间研究，
当然我没把握一定能跑通

KrKr2-Next研究。今天看了，Linux版移植搞不定，可能会放弃，等原作者有没有
移植到Linux的方法。也可能试试软件绘画方式，但我还没看。所以大概率下个月
开源到gh时只实现Android版的OpenGL方式，其他的话暂时搞不定

KrKr2-Next研究。看了一下，似乎软件render也不支持，就是说原版有很大部分的开关是没实现的——当然，
也有可能我看错。既然软件render未实现，也就是说我也没办法绕过opengles，但我可以尝试改一下，
自己加这个功能，就算实现不了，我也会开源的，放在gh上继续改，我是无所谓的

KrKr2-Next研究。我下定决心了，这个星期六或者星期日就把我的修改版放到gh上，技术有限，实在改不下去。
原作者应该对gles很熟悉，但对于我来说不太行，不过如果不限制时间，让我慢慢想，
一两年内应该也能把缺少的功能也想出来（如果能想出来的话，移植到SDL2也不困难了），
不过短时间我是想不出的，趁着现在心情还好，我还是早点把fork代码放到gh，
等以后有时间再改（我最近比较忙）。至于另外一个sdl3的代码，我可能会晚一些，
也许周末也会一起放到gh上，后续慢慢改了

KrKr2-Next研究。我可能今天或者晚上就把我的fork版本提交上去gh，心累，改不下去
（技术水平有限，我没原作者那么强）。其实这项目没什么整活的亮点，也就是代码重构罢了，
但可以做扩展，例如集成到flutter、写插件、移植SDL2、修改脚本引擎、添加新功能
——虽然对于我来说只是方便跑通一些我以前没跑通的内容，例如opengl的绘画
（我以前是软件绘画，opengl代码跳过了）

我尝试用vcpkg编译wamsoft/krkrz的安卓版，可以编译，但最终链接会失败——
反正我只是想拿到编译参数。其实即便能编译出安卓版的动态库也没用，
可能会缺少java代码，所以很大可能是原版都还没弄好的。这个vcpkg和
KrKr2-Next的vcpkg好像有点区别，这个的vcpkg不是直接指向ndk的工具链文件，
而是指向vcpkg的android工具链文件，再通过环境变量去查找NDK路径，
其实也就是绕了一下。导出SDL3仓库时候要等很长一段时间

wamsoft/krkrz研究。今天通过逆向vcpkg的编译参数输出把Android.mk写出来了，
可以用ndk-build编译出libSDL3.so和libkrkrz.so，但目前还不能在安卓上运行，
因为缺少Java代码，后面会补。另外，还需要简化一下external目录，
我基本把krkr2-next的ndk模块搬过来用，所以有一些其实是不需要的；
我还没测试ndk-build -j8，如果不行的话还需要在Android.mk里面拆分静态库编译；
目前看上去编译出来的so文件比krkr2-next要小；不知道为什么vcpkg用的
是common/sound/AudioStream.cpp，我需要换成common/sound/MiniAudioEngine.cpp
才能链接成功，可能这里是个坑

wamsoft/krkrz研究。测试过可以-j8编译，然后现在简化到只有15个外部库（其中只有10个需要编译），
这样编译出来的动态库可以大幅度缩小，比krkr2-next的动态库小一半左右
——当然这么小的代价是它几乎没有编译插件，如果编译插件和加上一些功能的话
动态库也会变得很大 ​​​
```

# Original README.md

<p align="center">
  <h1 align="center">KrKr2 Next</h1>
  <p align="center">基于 Flutter 重构的下一代 KiriKiri2 跨平台模拟器</p>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/status-In%20Development-orange" alt="Status">
  <img src="https://img.shields.io/badge/engine-KiriKiri2-blue" alt="Engine">
  <img src="https://img.shields.io/badge/framework-Flutter-02569B" alt="Flutter">
  <img src="https://img.shields.io/badge/graphics-ANGLE-red" alt="ANGLE">
  <img src="https://img.shields.io/badge/license-GPL--3.0-blue" alt="License">
</p>

---

**语言 / Language**: 中文 | [English](README_EN.md)

> 🙏 本项目基于 [krkr2](https://github.com/2468785842/krkr2) 重构，感谢原作者的贡献。

## 简介

**KrKr2 Next** 是 [KiriKiri2 (吉里吉里2)](https://zh.wikipedia.org/wiki/%E5%90%89%E9%87%8C%E5%90%89%E9%87%8C2) 视觉小说引擎的现代化跨平台运行环境。它完全兼容原版游戏脚本，使用现代图形接口进行硬件加速渲染，并在渲染性能和脚本执行效率上做了大量优化。基于 Flutter 构建统一的跨平台界面，支持 macOS · iOS · Windows · Linux · Android 五大平台。

下图为当前在 macOS 上通过 Metal 后端运行的实际效果：

<p align="center">
  <img src="doc/1.png" alt="macOS Metal 后端运行截图" width="800">
</p>

## 架构

<p align="center">
  <img src="doc/architecture.png" alt="技术架构图" width="700">
</p>

**渲染管线**：引擎通过 ANGLE 的 EGL Pbuffer Surface 进行离屏渲染（OpenGL ES 2.0），渲染结果通过平台原生纹理共享机制（macOS → IOSurface、Windows → D3D11 Texture、Linux → DMA-BUF）零拷贝传递给 Flutter Texture Widget 显示。


## 开发进度

> ⚠️ 本项目处于活跃开发阶段，尚未发布稳定版本。macOS 平台进度领先。

| 模块 | 状态 | 说明 |
|------|------|------|
| C++ 引擎核心编译 | ✅ 完成 | KiriKiri2 核心引擎全平台可编译 |
| ANGLE 渲染层迁移 | ✅ 基本完成 | 替代原 Cocos2d-x + GLFW 渲染管线，使用 EGL/GLES 离屏渲染 |
| engine_api 桥接层 | ✅ 完成 | 导出 `engine_create` / `engine_tick` / `engine_destroy` 等 C API |
| Flutter Plugin | ✅ 基本完成 | Platform Channel 通信、Texture 纹理桥接 |
| Texture 零拷贝渲染 | ✅ 基本完成 | 通过平台原生纹理共享机制零拷贝传递引擎渲染帧到 Flutter |
| Flutter 调试 UI | ✅ 基本完成 | FPS 控制、引擎生命周期管理、渲染状态监控 |
| 输入事件转发 | ✅ 基本完成 | 鼠标 / 触控事件坐标映射转发到引擎 |
| 引擎性能优化 | 🔨 进行中 | SIMD 像素混合、GPU 合成管线、VM 解释器优化等 |
| 游戏兼容性优化 | 🔨 进行中 | 补全解析引擎、添加插件，阶段目标与 Z 大闭源版兼容性持平 |
| 原有 krkr2 模拟器功能移植 | 📋 规划中 | 将原有 krkr2 模拟器功能逐步移植到新架构 |

## 平台支持状态

| 平台 | 状态 | 图形后端 | 纹理共享机制 |
|------|------|----------|-------------|
| macOS | ✅ 基本完成 | Metal | IOSurface |
| iOS | 🔨 流程打通，正在优化和修复 OpenGL 渲染 | Metal | IOSurface |
| Windows | 📋 计划中 | Direct3D 11 | D3D11 Texture |
| Linux | 📋 计划中 | Vulkan / Desktop GL | DMA-BUF |
| Android | 🔨 流程跑通，优化中 | OpenGL ES / Vulkan | HardwareBuffer |

## 引擎性能优化

| 优先级 | 任务 | 状态 |
|--------|------|------|
| P0 | 像素混合 SIMD 化 ([Highway](https://github.com/google/highway)) | ✅ 完成 |
| P0 | 全 GPU 合成渲染管线 | 🔨 进行中 |
| P0 | TJS2 VM 解释器优化 (computed goto) | 📋 计划中 |
## 许可证

本项目基于 GNU General Public License v3.0 (GPL-3.0) 开源，详见 [LICENSE](./LICENSE)。
