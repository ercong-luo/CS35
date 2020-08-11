# Configure compiler settings
CXX=clang++
CXXFLAGS=-g -std=c++11 -Werror
# The object files for the program.
OFILES = \
	directedGraph.o \
	undirectedGraph.o \
	graphAlgorithms.o \

# The header files for the program
HFILES = $(shell ls -1 *.h)

# UnitTest++ keeps its object files in this library.
UNITTEST_LIB = -lUnitTest++

all: tests manualTests reachable communication outbreak

# This builds your reachable program.
reachable: reachable.o $(OFILES) $(HFILES)
	$(CXX) $(CXXFLAGS) -o $@ reachable.o $(OFILES) $(UNITTEST_LIB)

# This builds your reachable program.
communication: communication.o $(OFILES) $(HFILES)
	$(CXX) $(CXXFLAGS) -o $@ communication.o $(OFILES) $(UNITTEST_LIB)

# This builds your reachable program.
outbreak: outbreak.o $(OFILES) $(HFILES)
	$(CXX) $(CXXFLAGS) -o $@ outbreak.o $(OFILES) $(UNITTEST_LIB)

# This target builds your tests.
tests: tests.o $(OFILES) $(HFILES)
	$(CXX) $(CXXFLAGS) -o $@ tests.o $(OFILES) $(UNITTEST_LIB)

# This target builds your manual testing program.
manualTests: manualTests.o $(HFILES) $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ manualTests.o $(OFILES)

# This target describes how to compile a .o file from a .cpp file.
%.o: %.cpp $(HFILES)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# This target deletes the temporary files we have built.
.PHONY: clean
clean:
	rm -f *.o
	rm -f tests
	rm -f manualTests
	rm -f reachable
	rm -f communication
	rm -f outbreak
