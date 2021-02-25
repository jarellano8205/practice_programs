MAIN = main.cpp
SOURCE = callbacks.cpp \
		   event.cpp \
		   telemDisplay.cpp \
         main.cpp \
         util.cpp \
	      graphics.cpp \
         telem.cpp \
         twoSum.cpp
SOURCE_OBJS = $(SOURCE:.cpp=.o)

TESTS = tests/main.cpp \
      tests/fpTests.cpp \
      telem.cpp

TESTS_OBJS = $(TESTS:.cpp=.o)

LIBS = -lglut -lGL -lGLU -lpthread

all : main

main: $(SOURCE_OBJS) $(MAIN)
	g++ -o $(LIBS) $@ $^

tests: $(TESTS_OBJS)
	g++ -o test $^

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
