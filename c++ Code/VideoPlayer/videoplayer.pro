#-------------------------------------------------
#
# Project created by QtCreator 2014-07-15T19:38:24
#
#-------------------------------------------------

QT       += core gui widgets



TARGET = VideoPlayer
TEMPLATE = app


SOURCES += main.cpp\
        videoplayer.cpp \
    copyprocessor.cpp \
    brightnessprocessor.cpp \
    colorprocessor.cpp \
    winmidioutput.cpp

HEADERS  += videoplayer.h \
    copyprocessor.h \
    brightnessprocessor.h \
    colorprocessor.h \
    midioutput.h

FORMS    += videoplayer.ui
LIBS += -lwinmm
include(../opencv/videoengine.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/ -lopencv_world310
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/ -lopencv_world310d
else:unix: LIBS += -L$$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/ -lopencv_world310

INCLUDEPATH += $$PWD/../../../../../../opencv/opencv/build/x64/vc14
DEPENDPATH += $$PWD/../../../../../../opencv/opencv/build/x64/vc14

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/libopencv_world310.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/libopencv_world310d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/opencv_world310.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/opencv_world310d.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/libopencv_world310.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/ -lopencv_world310
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/ -lopencv_world310d
else:unix: LIBS += -L$$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/ -lopencv_world310

INCLUDEPATH += $$PWD/../../../../../../opencv/opencv/build/x64/vc14
DEPENDPATH += $$PWD/../../../../../../opencv/opencv/build/x64/vc14

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/libopencv_world310.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/libopencv_world310d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/opencv_world310.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/opencv_world310d.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../opencv/opencv/build/x64/vc14/lib/libopencv_world310.a


