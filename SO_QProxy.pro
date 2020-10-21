QT += gui widgets

CONFIG += c++11

SOURCES += \
    Backend.cpp \
    GraphicsView.cpp \
    ListView.cpp \
    ResizableWidget.cpp \
    arrow.cpp \
    diagramitem.cpp \
    main.cpp \
    MovableItem.cpp \
    MainWindow.cpp

HEADERS += \
    AppGlobals.h \
    Backend.h \
    GraphicsView.h \
    ListView.h \
    ResizableWidget.h \
    arrow.h \
    diagramitem.h \
    MovableItem.h \
    MainWindow.h

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

