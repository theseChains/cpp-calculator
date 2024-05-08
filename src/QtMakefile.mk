#############################################################################
# Makefile for building: salsa
# Generated by qmake (3.1) (Qt 5.15.3)
# Project:  view/salsa.pro
# Template: app
# Command: /usr/lib/qt5/bin/qmake -o QtMakefile.mk view/salsa.pro
#############################################################################

MAKEFILE      = QtMakefile.mk

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_PRINTSUPPORT_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -std=gnu++1z -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -Iview -I. -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = salsa1.0.0
DISTDIR = /home/sublunary/repos/school/smart-salsa/src/.tmp/salsa1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5Core.so -lGL -lpthread   
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cc \
		controller/calculatorcontroller.cc \
		model/calculatorcore.cc \
		model/calculatormodel.cc \
		model/creditcalculator.cc \
		model/expressioncalculator.cc \
		model/expressionvalidator.cc \
		model/rpnconverter.cc \
		model/symbolclassifier.cc \
		model/tokenclassifier.cc \
		model/tokenizer.cc \
		view/qcustomplot.cc \
		view/calculatorview.cc \
		view/labelmanager.cc \
		view/plotmanager.cc \
		view/creditcalculatorwindow.cc moc_qcustomplot.cpp \
		moc_calculatorview.cpp \
		moc_labelmanager.cpp \
		moc_creditcalculatorwindow.cpp
OBJECTS       = main.o \
		calculatorcontroller.o \
		calculatorcore.o \
		calculatormodel.o \
		creditcalculator.o \
		expressioncalculator.o \
		expressionvalidator.o \
		rpnconverter.o \
		symbolclassifier.o \
		tokenclassifier.o \
		tokenizer.o \
		qcustomplot.o \
		calculatorview.o \
		labelmanager.o \
		plotmanager.o \
		creditcalculatorwindow.o \
		moc_qcustomplot.o \
		moc_calculatorview.o \
		moc_labelmanager.o \
		moc_creditcalculatorwindow.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		view/view/salsa.pro controller/calculatorcontroller.h \
		common/creditinput.h \
		common/monthlypaymenttype.h \
		common/expressionerrorcode.h \
		model/calculationresult.h \
		model/calculatorcore.h \
		model/calculatormodel.h \
		model/creditcalculator.h \
		model/expressioncalculator.h \
		../model/expressionerrorcode.h \
		model/expressionvalidator.h \
		model/modelconstants.h \
		model/rpnconverter.h \
		model/symbolclassifier.h \
		model/tokenclassifier.h \
		model/tokenizer.h \
		model/token.h \
		view/labeltype.h \
		view/qcustomplot.h \
		view/trigonometrycalculationtype.h \
		view/calculatorview.h \
		view/labelmanager.h \
		view/plotmanager.h \
		view/creditcalculatorwindow.h \
		view/viewconstants.h main.cc \
		controller/calculatorcontroller.cc \
		model/calculatorcore.cc \
		model/calculatormodel.cc \
		model/creditcalculator.cc \
		model/expressioncalculator.cc \
		model/expressionvalidator.cc \
		model/rpnconverter.cc \
		model/symbolclassifier.cc \
		model/tokenclassifier.cc \
		model/tokenizer.cc \
		view/qcustomplot.cc \
		view/calculatorview.cc \
		view/labelmanager.cc \
		view/plotmanager.cc \
		view/creditcalculatorwindow.cc
QMAKE_TARGET  = salsa
DESTDIR       = 
TARGET        = salsa


first: all
####### Build rules

salsa: ui_calculatorview.h ui_creditcalculatorwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

QtMakefile.mk: view/salsa.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		view/salsa.pro
	$(QMAKE) -o QtMakefile.mk view/salsa.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimedia.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
view/salsa.pro:
qmake: FORCE
	@$(QMAKE) -o QtMakefile.mk view/salsa.pro

qmake_all: FORCE


all: QtMakefile.mk salsa

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents controller/calculatorcontroller.h common/creditinput.h common/monthlypaymenttype.h common/expressionerrorcode.h model/calculationresult.h model/calculatorcore.h model/calculatormodel.h model/creditcalculator.h model/expressioncalculator.h ../model/expressionerrorcode.h model/expressionvalidator.h model/modelconstants.h model/rpnconverter.h model/symbolclassifier.h model/tokenclassifier.h model/tokenizer.h model/token.h view/labeltype.h view/qcustomplot.h view/trigonometrycalculationtype.h view/calculatorview.h view/labelmanager.h view/plotmanager.h view/creditcalculatorwindow.h view/viewconstants.h $(DISTDIR)/
	$(COPY_FILE) --parents main.cc controller/calculatorcontroller.cc model/calculatorcore.cc model/calculatormodel.cc model/creditcalculator.cc model/expressioncalculator.cc model/expressionvalidator.cc model/rpnconverter.cc model/symbolclassifier.cc model/tokenclassifier.cc model/tokenizer.cc view/qcustomplot.cc view/calculatorview.cc view/labelmanager.cc view/plotmanager.cc view/creditcalculatorwindow.cc $(DISTDIR)/
	$(COPY_FILE) --parents view/calculatorview.ui view/creditcalculatorwindow.ui $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) QtMakefile.mk


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -std=gnu++1z -Wall -Wextra -dM -E -o moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_qcustomplot.cpp moc_calculatorview.cpp moc_labelmanager.cpp moc_creditcalculatorwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_qcustomplot.cpp moc_calculatorview.cpp moc_labelmanager.cpp moc_creditcalculatorwindow.cpp
moc_qcustomplot.cpp: view/qcustomplot.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/sublunary/repos/school/smart-salsa/src/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/sublunary/repos/school/smart-salsa/src/view -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I/usr/include/c++/12 -I/usr/include/x86_64-linux-gnu/c++/12 -I/usr/include/c++/12/backward -I/usr/lib/gcc/x86_64-linux-gnu/12/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include view/qcustomplot.h -o moc_qcustomplot.cpp

moc_calculatorview.cpp: view/calculatorview.h \
		controller/calculatorcontroller.h \
		common/monthlypaymenttype.h \
		model/calculationresult.h \
		common/expressionerrorcode.h \
		model/calculatormodel.h \
		common/creditinput.h \
		model/calculatorcore.h \
		model/expressioncalculator.h \
		model/token.h \
		model/tokenizer.h \
		model/creditcalculator.h \
		view/creditcalculatorwindow.h \
		view/labelmanager.h \
		view/labeltype.h \
		ui_calculatorview.h \
		view/plotmanager.h \
		view/trigonometrycalculationtype.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/sublunary/repos/school/smart-salsa/src/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/sublunary/repos/school/smart-salsa/src/view -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I/usr/include/c++/12 -I/usr/include/x86_64-linux-gnu/c++/12 -I/usr/include/c++/12/backward -I/usr/lib/gcc/x86_64-linux-gnu/12/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include view/calculatorview.h -o moc_calculatorview.cpp

moc_labelmanager.cpp: view/labelmanager.h \
		common/expressionerrorcode.h \
		view/labeltype.h \
		ui_calculatorview.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/sublunary/repos/school/smart-salsa/src/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/sublunary/repos/school/smart-salsa/src/view -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I/usr/include/c++/12 -I/usr/include/x86_64-linux-gnu/c++/12 -I/usr/include/c++/12/backward -I/usr/lib/gcc/x86_64-linux-gnu/12/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include view/labelmanager.h -o moc_labelmanager.cpp

moc_creditcalculatorwindow.cpp: view/creditcalculatorwindow.h \
		common/creditinput.h \
		common/monthlypaymenttype.h \
		controller/calculatorcontroller.h \
		model/calculationresult.h \
		common/expressionerrorcode.h \
		model/calculatormodel.h \
		model/calculatorcore.h \
		model/expressioncalculator.h \
		model/token.h \
		model/tokenizer.h \
		model/creditcalculator.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/sublunary/repos/school/smart-salsa/src/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/sublunary/repos/school/smart-salsa/src/view -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I/usr/include/c++/12 -I/usr/include/x86_64-linux-gnu/c++/12 -I/usr/include/c++/12/backward -I/usr/lib/gcc/x86_64-linux-gnu/12/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include view/creditcalculatorwindow.h -o moc_creditcalculatorwindow.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_calculatorview.h ui_creditcalculatorwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_calculatorview.h ui_creditcalculatorwindow.h
ui_calculatorview.h: view/calculatorview.ui \
		/usr/lib/qt5/bin/uic \
		view/qcustomplot.h
	/usr/lib/qt5/bin/uic view/calculatorview.ui -o ui_calculatorview.h

ui_creditcalculatorwindow.h: view/creditcalculatorwindow.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic view/creditcalculatorwindow.ui -o ui_creditcalculatorwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cc controller/calculatorcontroller.h \
		common/monthlypaymenttype.h \
		model/calculationresult.h \
		common/expressionerrorcode.h \
		model/calculatormodel.h \
		common/creditinput.h \
		model/calculatorcore.h \
		model/expressioncalculator.h \
		model/token.h \
		model/tokenizer.h \
		model/creditcalculator.h \
		view/calculatorview.h \
		view/creditcalculatorwindow.h \
		view/labelmanager.h \
		view/labeltype.h \
		ui_calculatorview.h \
		view/plotmanager.h \
		view/trigonometrycalculationtype.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cc

calculatorcontroller.o: controller/calculatorcontroller.cc controller/calculatorcontroller.h \
		common/monthlypaymenttype.h \
		model/calculationresult.h \
		common/expressionerrorcode.h \
		model/calculatormodel.h \
		common/creditinput.h \
		model/calculatorcore.h \
		model/expressioncalculator.h \
		model/token.h \
		model/tokenizer.h \
		model/creditcalculator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o calculatorcontroller.o controller/calculatorcontroller.cc

calculatorcore.o: model/calculatorcore.cc model/calculatorcore.h \
		model/calculationresult.h \
		common/expressionerrorcode.h \
		model/expressioncalculator.h \
		model/token.h \
		model/tokenizer.h \
		model/expressionvalidator.h \
		model/modelconstants.h \
		model/rpnconverter.h \
		model/tokenclassifier.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o calculatorcore.o model/calculatorcore.cc

calculatormodel.o: model/calculatormodel.cc model/calculatormodel.h \
		common/creditinput.h \
		model/calculationresult.h \
		common/expressionerrorcode.h \
		model/calculatorcore.h \
		model/expressioncalculator.h \
		model/token.h \
		model/tokenizer.h \
		model/creditcalculator.h \
		common/monthlypaymenttype.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o calculatormodel.o model/calculatormodel.cc

creditcalculator.o: model/creditcalculator.cc model/creditcalculator.h \
		common/creditinput.h \
		common/monthlypaymenttype.h \
		model/calculationresult.h \
		common/expressionerrorcode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o creditcalculator.o model/creditcalculator.cc

expressioncalculator.o: model/expressioncalculator.cc model/expressioncalculator.h \
		common/expressionerrorcode.h \
		model/token.h \
		model/modelconstants.h \
		model/tokenclassifier.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o expressioncalculator.o model/expressioncalculator.cc

expressionvalidator.o: model/expressionvalidator.cc model/expressionvalidator.h \
		model/calculationresult.h \
		common/expressionerrorcode.h \
		model/modelconstants.h \
		model/token.h \
		model/symbolclassifier.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o expressionvalidator.o model/expressionvalidator.cc

rpnconverter.o: model/rpnconverter.cc model/rpnconverter.h \
		common/expressionerrorcode.h \
		model/token.h \
		model/tokenclassifier.h \
		model/modelconstants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o rpnconverter.o model/rpnconverter.cc

symbolclassifier.o: model/symbolclassifier.cc model/symbolclassifier.h \
		model/modelconstants.h \
		model/token.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o symbolclassifier.o model/symbolclassifier.cc

tokenclassifier.o: model/tokenclassifier.cc model/tokenclassifier.h \
		model/token.h \
		model/modelconstants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tokenclassifier.o model/tokenclassifier.cc

tokenizer.o: model/tokenizer.cc model/tokenizer.h \
		common/expressionerrorcode.h \
		model/token.h \
		model/modelconstants.h \
		model/symbolclassifier.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tokenizer.o model/tokenizer.cc

qcustomplot.o: view/qcustomplot.cc view/qcustomplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qcustomplot.o view/qcustomplot.cc

calculatorview.o: view/calculatorview.cc view/calculatorview.h \
		controller/calculatorcontroller.h \
		common/monthlypaymenttype.h \
		model/calculationresult.h \
		common/expressionerrorcode.h \
		model/calculatormodel.h \
		common/creditinput.h \
		model/calculatorcore.h \
		model/expressioncalculator.h \
		model/token.h \
		model/tokenizer.h \
		model/creditcalculator.h \
		view/creditcalculatorwindow.h \
		view/labelmanager.h \
		view/labeltype.h \
		ui_calculatorview.h \
		view/plotmanager.h \
		view/trigonometrycalculationtype.h \
		view/viewconstants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o calculatorview.o view/calculatorview.cc

labelmanager.o: view/labelmanager.cc view/labelmanager.h \
		common/expressionerrorcode.h \
		view/labeltype.h \
		ui_calculatorview.h \
		view/viewconstants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o labelmanager.o view/labelmanager.cc

plotmanager.o: view/plotmanager.cc view/plotmanager.h \
		controller/calculatorcontroller.h \
		common/monthlypaymenttype.h \
		model/calculationresult.h \
		common/expressionerrorcode.h \
		model/calculatormodel.h \
		common/creditinput.h \
		model/calculatorcore.h \
		model/expressioncalculator.h \
		model/token.h \
		model/tokenizer.h \
		model/creditcalculator.h \
		view/trigonometrycalculationtype.h \
		ui_calculatorview.h \
		view/viewconstants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o plotmanager.o view/plotmanager.cc

creditcalculatorwindow.o: view/creditcalculatorwindow.cc view/creditcalculatorwindow.h \
		common/creditinput.h \
		common/monthlypaymenttype.h \
		controller/calculatorcontroller.h \
		model/calculationresult.h \
		common/expressionerrorcode.h \
		model/calculatormodel.h \
		model/calculatorcore.h \
		model/expressioncalculator.h \
		model/token.h \
		model/tokenizer.h \
		model/creditcalculator.h \
		ui_creditcalculatorwindow.h \
		view/viewconstants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o creditcalculatorwindow.o view/creditcalculatorwindow.cc

moc_qcustomplot.o: moc_qcustomplot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qcustomplot.o moc_qcustomplot.cpp

moc_calculatorview.o: moc_calculatorview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_calculatorview.o moc_calculatorview.cpp

moc_labelmanager.o: moc_labelmanager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_labelmanager.o moc_labelmanager.cpp

moc_creditcalculatorwindow.o: moc_creditcalculatorwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_creditcalculatorwindow.o moc_creditcalculatorwindow.cpp

####### Install

install_target: first FORCE
	@test -d $(INSTALL_ROOT)/opt/salsa/bin || mkdir -p $(INSTALL_ROOT)/opt/salsa/bin
	$(QINSTALL_PROGRAM) $(QMAKE_TARGET) $(INSTALL_ROOT)/opt/salsa/bin/$(QMAKE_TARGET)
	-$(STRIP) $(INSTALL_ROOT)/opt/salsa/bin/$(QMAKE_TARGET)

uninstall_target: FORCE
	-$(DEL_FILE) $(INSTALL_ROOT)/opt/salsa/bin/$(QMAKE_TARGET)
	-$(DEL_DIR) $(INSTALL_ROOT)/opt/salsa/bin/ 


install: install_target  FORCE

uninstall: uninstall_target  FORCE

FORCE:

