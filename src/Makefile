CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -Werror
LIBS =  -lgtest -lgcov
LINUX = -lrt -lpthread -lm -lsubunit 
LFLAGS = -fprofile-arcs -ftest-coverage 	
OS = $(shell uname -s)

all: install gcov_report

install: 
	doxygen
	mkdir -p build && cd build && qmake ..
	cd build && make
	open ./READ.md

uninstall:
	rm -rf build

dvi:
	cd doxygen/html && open ./index.html

dist: 
	mkdir -p dist
	tar cf dist/SmartCalc_v2.0.tar build doxygen


test:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) Model.cc unit_tests.cc -o unit_tests $(LIBS) 
else
	$(CC) $(CFLAGS) Model.cc unit_tests.cc -o unit_tests $(LIBS) $(LINUX) 
endif
	./unit_tests

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LFLAGS) Model.cc unit_tests.cc -o test.out $(LIBS)
else
	$(CC) $(CFLAGS) $(LFLAGS) Model.cc unit_tests.cc -o test.out $(LIBS) $(LINUX)
endif
	./test.out
	mkdir report
	gcovr *.gcda
	gcovr -b
	gcovr
	gcovr --html-details -o ./report/report.html
	open ./report/report.html




style:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -i *.h *.cc *.cpp
	clang-format -n *.h *.cc *.cpp
	rm -rf .clang-format


valgrind: test
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./unit_tests


clean:
	rm -rf  *.o *.a
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf *.gcov
	rm -rf report
	rm -rf gcov_test
	rm -rf test.out
	rm -rf build
	rm -rf unit_tests
	rm -rf doxygen
	rm -rf dist