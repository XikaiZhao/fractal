CC = g++ -std=c++11 -Ofast -march=native
CFLAGS  = -Wall
#LIBS = -fopenmp

SOURCES = main.cpp ColoringMethods.cpp Fractal.cpp Grid2D.cpp Params.cpp Color.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = fractal

all: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< $(LIBS) 

.PHONY:
clean:
	rm -rf *o fractal
