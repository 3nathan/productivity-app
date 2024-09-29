CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

SRCDIR = src
BUILDDIR = build
BINDIR = bin

TARGET = $(BINDIR)/app

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRC))

# rules
all: $(TARGET)

# link obj files to create exe
$(TARGET): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CXX) $(OBJ) -o $(TARGET)

# compile source files into object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean build files
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

# phony targets
.PHONY: all clean
