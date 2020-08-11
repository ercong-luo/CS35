# Configure compiler settings
CXX=clang++
CXXFLAGS=-g -std=c++11 -Werror -D_GLIBCXX_DEBUG
# The object files for the crypto program.
OFILES = caesar.o enigma.o rotation.o stream.o substitution.o
# UnitTest++ library needed for linking
UNITTEST_LIB = -lUnitTest++

all: crypto tests

# This target builds your crypto program.
crypto: $(OFILES) crypto.o
	$(CXX) $(CXXFLAGS) -o $@ crypto.o $(OFILES)

# This target describes how to compile a .o file from a .cpp file.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# This target builds the tests.
tests: tests.o $(OFILES) test_utils.o
	$(CXX) $(CXXFLAGS) -o $@ tests.o $(OFILES) test_utils.o $(UNITTEST_LIB)

# This target deletes the temporary files we have built.
.PHONY: clean
clean:
	rm -f $(OFILES)
	rm -f ./crypto
	rm -f ./tests
	rm -f crypto.o
	rm -f tests.o
	rm -f test_utils.o

