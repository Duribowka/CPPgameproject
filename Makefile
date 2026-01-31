CXX = g++
CXXFLAGS = -std=c++17 -Wall -IHeaders
SRC = src/main.cpp src/employee.cpp src/pet.cpp src/shelter.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)