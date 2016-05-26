################################################################
# Qwt Widget Library
# Copyright (C) 1997   Josef Wilgen
# Copyright (C) 2002   Uwe Rathmann
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the Qwt License, Version 1.0
################################################################

include( $${PWD}/../examples.pri )
include ( C:/qwt-6.1.2/qwt.prf)

TARGET       = simpleplot

SOURCES = \
    simpleplot.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-qwt-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-qwt-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/lib/ -lqwtd
else:unix: LIBS += -L$$PWD/../../../build-qwt-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../build-qwt-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug
DEPENDPATH += $$PWD/../../../build-qwt-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-qwt-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-qwt-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/lib/ -lqwtd
else:unix: LIBS += -L$$PWD/../../../build-qwt-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../build-qwt-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug
DEPENDPATH += $$PWD/../../../build-qwt-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug

unix|win32: LIBS += -L$$PWD/./ -lqwt

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

CONFIG += console
