# Define the compiler to use
CXX = g++

# Define any compile-time flags
CXXFLAGS = -Wall -std=c++11 -fPIC $(shell pkg-config --cflags Qt5Widgets)

# Define any directories containing header files other than /usr/include
INCLUDES =

# Define library paths in addition to /usr/lib
LFLAGS = $(shell pkg-config --libs Qt5Widgets)

# Define the C++ source files
SRCS = main.cpp mainwindow.cpp moc_mainwindow.cpp

# Define the C++ object files
OBJS = $(SRCS:.cpp=.o)

# Define the executable file
MAIN = qt_example

all:    $(MAIN)
	@echo Simple compiler named qt_example has been compiled

$(MAIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS)

# this is a suffix replacement rule for building .o's from .cpp's
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

moc_mainwindow.cpp: mainwindow.hpp
	moc mainwindow.hpp -o moc_mainwindow.cpp

clean:
	$(RM) *.o *~ $(MAIN) moc_mainwindow.cpp

depend: $(SRCS)
	makedepend $(INCLUDES) $^
