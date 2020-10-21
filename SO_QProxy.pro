QT += gui widgets

CONFIG += c++11

SOURCES += \
    ArrowItem.cpp \
    Backend.cpp \
    GraphicsView.cpp \
    ListView.cpp \
    ResizableWidget.cpp \
    main.cpp \
    MovableItem.cpp \
    MainWindow.cpp

HEADERS += \
    AppGlobals.h \
    ArrowItem.h \
    Backend.h \
    GraphicsView.h \
    ListView.h \
    ResizableWidget.h \
    MovableItem.h \
    MainWindow.h

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

