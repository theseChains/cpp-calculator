CXX = gcc
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra -Wshadow
CCOV = --coverage
OS := $(shell uname -s)

SOURCES = model/tokenizer.cc \
		  model/rpnconverter.cc \
		  model/expressionvalidator.cc \
		  model/expressioncalculator.cc \
		  model/calculatorcore.cc \
		  model/calculatormodel.cc \
		  model/symbolclassifier.cc \
		  model/tokenclassifier.cc \
		  model/creditcalculator.cc \
		  tests/calculation_tests.cc \
		  tests/tests.cc
OBJECTS = $(LIB_SOURCES:.c=.o)

VIEW_DIRECTORY = view
QT_MAKEFILE_NAME = QtMakefile.mk
DISTRIBUTION_DIRECTORY = distribution

all: dvi clean test install open_app

dvi:
	open ../dvi/README.html

open_app:
ifeq ($(OS), Linux)
	./salsa
else
	salsa.app/Contents/MacOS/salsa
endif

uninstall: clean
ifeq ($(OS), Linux)
	rm -rf salsa
else
	rm -rf salsa.app
endif

install: uninstall
	qmake -o $(QT_MAKEFILE_NAME) $(VIEW_DIRECTORY)/salsa.pro
	make -f $(QT_MAKEFILE_NAME)
	make -f $(QT_MAKEFILE_NAME) clean --silent

dist:
	mkdir ${DISTRIBUTION_DIRECTORY}
	cp -rf $(VIEW_DIRECTORY) ${DISTRIBUTION_DIRECTORY}
	cp -rf model ${DISTRIBUTION_DIRECTORY}
	cp -rf common ${DISTRIBUTION_DIRECTORY}
	cp -rf controller ${DISTRIBUTION_DIRECTORY}
	cp -rf tests ${DISTRIBUTION_DIRECTORY}
	cp -rf main.cc ${DISTRIBUTION_DIRECTORY}
	cp -rf Makefile ${DISTRIBUTION_DIRECTORY}
	tar -zcvf calculator_archive.tar.gz ${DISTRIBUTION_DIRECTORY}
	rm -rf ${DISTRIBUTION_DIRECTORY}

test:
	$(CXX) $(CXXFLAGS) $(SOURCES) -lm -lstdc++ -lgtest -o app
	./app

clean:
	rm -rf app app_cov *.o $(VIEW_DIRECTORY)/*.o $(VIEW_DIRECTORY)/*.pro.user *.gcda *.gcno *.info *.a
	rm -rf archive.tar.gz
	rm -rf .qmake.stash
	rm -rf $(VIEW_DIRECTORY)/.qmake.stash
	rm -rf $(VIEW_DIRECTORY)/.qtc_clangd
	rm -rf ui_*.h
	rm -rf $(VIEW_DIRECTORY)/ui_*.h
	rm -rf report/
	rm -f $(VIEW_DIRECTORY)/salsa
	rm -rf salsa.app
	rm -rf salsa
	rm -rf $(VIEW_DIRECTORY)/moc_predefs.h
	rm -rf $(VIEW_DIRECTORY)/moc_*
	rm -rf moc_*
	rm -rf *.tar.gz
	rm -rf $(QT_MAKEFILE_NAME)
	rm -rf build-*

rebuild:
	make clean
	make all
