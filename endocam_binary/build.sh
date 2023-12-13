#! /bin/bash
#
# define WARN_DEPRECATED nonblank to get warnings about deprecated
#
mkdir -p bin
rm -rf bin/*
set -e
export PKG_LIBS=`pkg-config gstreamer-app-1.0 gstreamer-1.0 gtk+-3.0 gstreamer-video-1.0 libudev blkid gtkmm-3.0 --cflags --libs`
export PKG_LIBS="-Iexternal/tut/include/ -Iexternal/../src/ -Iexternal/jansson/include/ -I/usr/include/glib-2.0 -I/usr/lib/aarch64-linux-gnu/glib-2.0/include -I/usr/include/gtk-3.0 -I/usr/include/pango-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/atk-1.0 -I/usr/include -I/usr/include/gstreamer-1.0 -L/usr/local/lib $PKG_LIBS -lasound -ljansson -lusb-1.0 -lJetsonGPIO -lpthread -lpulse-simple -li2c"
export OPTIMIZATION="-O3"
export CFLAGS= 
export CXXFLAGS=" -g -std=c++11 " 

if [[ "$WARN_DEPRECATED" == "" ]]
  then 
    warn_deprecated=" -Wno-deprecated-declarations "
  else
    warn_deprecated=""
fi

export GCC_COMPILE="gcc $OPTIMIZATION -Wall -Wno-unused-result $warn_deprecated $CFLAGS -c -o" 
export GPP_COMPILE="g++ $OPTIMIZATION -Wall -Wno-unused-result -Wno-reorder $warn_deprecated  $CXXFLAGS -c -o" 


$GPP_COMPILE bin/ispctrl.o src/ispctrl.cpp $PKG_LIBS
$GPP_COMPILE bin/Logger.o src/Logger.cpp $PKG_LIBS
$GPP_COMPILE bin/ButtonGroup.o src/ButtonGroup.cpp $PKG_LIBS
#$GPP_COMPILE bin/GPIO.o src/GPIO.cpp $PKG_LIBS
$GPP_COMPILE bin/WebCam.o src/WebCam.cpp $PKG_LIBS
$GPP_COMPILE bin/Results.o src/Results.cpp $PKG_LIBS
#$GCC_COMPILE bin/hummingboard.o src/hummingboard.c
$GCC_COMPILE bin/dosfs.o src/fatattr/dosfs.c
$GCC_COMPILE bin/fatattr.o src/fatattr/fatattr.c
# $GPP_COMPILE bin/i2cFunc.o src/i2cFunc.cpp
$GCC_COMPILE bin/wiringX.o src/wiringX.c 
$GPP_COMPILE bin/TextEditor.o src/TextEditor.cpp $PKG_LIBS
$GPP_COMPILE bin/SliderValueChangeListener.o src/SliderValueChangeListener.cpp 
$GPP_COMPILE bin/Slider.o src/Slider.cpp $PKG_LIBS
$GPP_COMPILE bin/ContentComponent.o src/ContentComponent.cpp $PKG_LIBS 
$GPP_COMPILE bin/Message.o src/Message.cpp $PKG_LIBS
$GPP_COMPILE bin/Synchronization.o src/Synchronization.cpp $PKG_LIBS
$GPP_COMPILE bin/LiveViewComponent.o src/LiveViewComponent.cpp $PKG_LIBS
$GPP_COMPILE bin/LiveViewGstPipeline.o src/LiveViewGstPipeline.cpp $PKG_LIBS 
$GPP_COMPILE bin/MainWindow.o src/MainWindow.cpp $PKG_LIBS
$GPP_COMPILE bin/Constants.o src/Constants.cpp $PKG_LIBS
$GPP_COMPILE bin/SystemSettings.o src/SystemSettings.cpp $PKG_LIBS 
#$GPP_COMPILE bin/I2CCom.o src/I2CCom.cpp $PKG_LIBS
# $GPP_COMPILE bin/I2CBus.o src/I2CBus.cpp $PKG_LIBS
$GPP_COMPILE bin/ChangeListeners.o src/ChangeListeners.cpp $PKG_LIBS 
$GPP_COMPILE bin/SettingScreenComponent.o src/SettingScreenComponent.cpp $PKG_LIBS
$GPP_COMPILE bin/Utility.o src/Utility.cpp $PKG_LIBS
$GPP_COMPILE bin/PressState.o src/PressState.cpp $PKG_LIBS
$GPP_COMPILE bin/ProcessInterruptThread.o src/ProcessInterruptThread.cpp $PKG_LIBS
#$GPP_COMPILE bin/ProcessShutDownFlag.o src/ProcessShutDownFlag.cpp $PKG_LIBS
$GPP_COMPILE bin/ReviewScreen.o src/ReviewScreen.cpp $PKG_LIBS
$GPP_COMPILE bin/ReviewGstPipeline.o src/ReviewGstPipeline.cpp $PKG_LIBS
$GPP_COMPILE bin/GalleryScreen.o src/GalleryScreen.cpp $PKG_LIBS
$GPP_COMPILE bin/UserSettingsScreen.o src/UserSettingsScreen.cpp $PKG_LIBS
$GPP_COMPILE bin/ThumbnailList.o src/ThumbnailList.cpp $PKG_LIBS
$GPP_COMPILE bin/UpDownCtrl.o src/UpDownCtrl.cpp $PKG_LIBS
$GPP_COMPILE bin/GUIUtils.o src/GUIUtils.cpp $PKG_LIBS
$GPP_COMPILE bin/DateUpDownCtrlModel.o src/DateUpDownCtrlModel.cpp $PKG_LIBS
$GPP_COMPILE bin/CountDownTimer.o src/CountDownTimer.cpp $PKG_LIBS
#$GPP_COMPILE bin/ProcessDirtyFlag.o src/ProcessDirtyFlag.cpp $PKG_LIBS
$GPP_COMPILE bin/CustomKeyboard.o src/CustomKeyboard.cpp $PKG_LIBS
$GCC_COMPILE bin/playAudioFile.o src/playAudioFile.c $PKG_LIBS
$GPP_COMPILE bin/CustomFileExplorer.o src/CustomFileExplorer.cpp $PKG_LIBS
$GPP_COMPILE bin/i2c.o src/i2c.cpp

export LINKLIB="bin/*.o $PKG_LIBS"

echo Build executable

g++ -Wall $CXXFLAGS src/endocam.cpp -o bin/endocam $LINKLIB

# Not using unit tests
exit

echo Build Unit Tests

export CXXFLAGS="-DENDOCAM_UT $CXXFLAGS"
export GPP_COMPILE="g++ $OPTIMIZATION -Wall -Wno-unused-result -Wno-reorder $CXXFLAGS -c -o" 

$GPP_COMPILE bin/UT_DateUpDownCtrlModel.o test/UT_DateUpDownCtrlModel.cpp $PKG_LIBS
$GPP_COMPILE bin/UT_Buttonpress.o test/UT_Buttonpress.cpp $PKG_LIBS
$GPP_COMPILE bin/UT_StringTest.o test/UT_StringTest.cpp $PKG_LIBS
$GPP_COMPILE bin/UT_LiveViewGSTPipeline.o test/UT_LiveViewGSTPipeline.cpp $PKG_LIBS
$GPP_COMPILE bin/UT_Gallery.o test/UT_Gallery.cpp $PKG_LIBS
$GPP_COMPILE bin/UT_GUI.o test/UT_GUI.cpp $PKG_LIBS
$GPP_COMPILE bin/UT_CountDownTimer.o test/UT_CountDownTimer.cpp $PKG_LIBS
$GPP_COMPILE bin/UT_I2cTest.o test/UT_I2cTest.cpp $PKG_LIBS
$GPP_COMPILE bin/UT_Log.o test/UT_Log.cpp $PKG_LIBS
$GPP_COMPILE bin/test_main.o test/test_main.cpp $PKG_LIBS

g++ -Wall $CXXFLAGS -o bin/UnitTest $LINKLIB  

echo Run unit Test

if [ -f ./bin/UnitTest ]
then
	./bin/UnitTest
else
	echo NO UNIT TEST
fi

