# Makefile for DSA Group Assignment
# ITS60504 Data Structures and Algorithms
# Compile with: make
# Run with: make run
# Clean with: make clean

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = dsa_app

# Source files
SRCS = main.cpp \
       data_generator.cpp \
       selection_sort.cpp \
       quick_sort.cpp \
       merge_sort.cpp \
       binary_search.cpp \
       interpolation_search.cpp

# Object files (derived from source files)
OBJS = $(SRCS:.cpp=.o)

# Default target: build the application
all: $(TARGET)

# Link all object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each .cpp file into a .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the application
run: $(TARGET)
	./$(TARGET)

# Remove compiled files
clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).exe

.PHONY: all run clean
