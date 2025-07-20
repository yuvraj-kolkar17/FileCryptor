# Makefile for FileCryptor

CXX = g++
CXXFLAGS = -Wall -std=c++17
SRCDIR = src
BUILDDIR = build
TARGET = $(BUILDDIR)/filecryptor

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(SRCFILES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

all: $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(BUILDDIR)/*.o $(TARGET)
