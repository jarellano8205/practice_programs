MAIN = main.cpp
SOURCE = telem.cpp \
			parser.cpp

SOURCE_OBJS = $(SOURCE:.cpp=.o)

TESTS = tests/main.cpp \
        tests/telemTest.cpp \
		  tests/parseTest.cpp \
        telem.cpp \
        parser.cpp

TESTS_OBJS = $(TESTS:.cpp=.o)
 
all : main

main: $(SOURCE_OBJS) $(MAIN)
	g++ -o $@ -Wall -O3 -std=c++17 -I. $^

tests: $(TESTS_OBJS)
	g++ -o test -Wall -O3 -std=c++17 -I. $^

clean:
	rm -rf *.o *.d core main
	rm -rf tests/*.o tests/*.d test

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: main

tar: clean
	tar zcvf main.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make main  - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "  make tests - builds the test target"
	@echo "	make clean - remove .o .d core main"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"
