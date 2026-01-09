CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lpqxx -lpq

TARGET = okul_sistemi
SRC = src/main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
