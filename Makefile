CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

NETWORKING_SRC_PATH := src/Networking/Servers src/Networking/Servers/HTTPServer src/Networking/Sockets/ServerSocket src/Networking/Sockets/SimpleSocket src/Networking/Sockets/TCPSocket

# Source files for Networking
NETWORKING_SRCS := $(foreach dir, $(NETWORKING_SRC_PATH), $(wildcard $(dir)/*.cpp))
# Binary files
BIN := bin
# Header Files
INCLUDE := include
# Libraries
LIBRARIES   :=
# Output binary
EXECUTEABLE := test

all: $(BIN)/$(EXECUTEABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTEABLE)

$(BIN)/$(EXECUTEABLE): $(NETWORKING_SRCS)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*