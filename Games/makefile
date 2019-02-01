CC            = clang
CXX           = clang++
DEFINES       = -DQT_NO_DEBUG
CFLAGS        = -pipe -mmacosx-version-min=10.7 -O2 -arch x86_64 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -stdlib=libstdc++ -mmacosx-version-min=10.7 -O2 -arch x86_64 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Cellar/qt/4.8.6/mkspecs/unsupported/macx-clang-libc++ -I. -I/usr/local/Cellar/qt/4.8.6/include -I.
LINK          = clang++
LFLAGS        = -headerpad_max_install_names -stdlib=libstdc++ -mmacosx-version-min=10.7 -arch x86_64

CC = g++
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
OPTIONS = -Wall

all : main

main: $(OBJECTS)
	$(CC) ${OPTIONS} -o main $(OBJECTS) 

%.o: %.c
	$(CC) -Wall -o $@ -c $<

clean:
	rm -f main $(OBJECTS)