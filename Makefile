PROJECT = main

TESTPROJECT = test-$(PROJECT)

LIBPROJECT = $(PROJECT).a

SRC_DIR = src

INCLUDE_DIR = include

OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, %.o, $(wildcard $(SRC_DIR)/*.cpp))

TEST-OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, %.o, $(wildcard $(SRC_DIR)/test_*.cpp))

DEPS = $(wildcard $(INCLUDE_DIR)/*.h)

A = ar

AFLAGS = rsv

CXX = g++

CXXFLAGS = -I$(INCLUDE_DIR) -std=c++17 -Werror -Wpedantic -Wall -g -fPIC

LDXXFLAGS = $(CXXFLAGS) -L. -l:$(LIBPROJECT)

LDGTESTFLAGS = $(LDXXFLAGS) -lgtest_main -lgtest -lpthread

.PHONY: default

default: all;

obj/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	@mkdir -p obj
	$(CXX) -c -o $@ $< $(CXXFLAGS)
	
$(LIBPROJECT): $(addprefix obj/, $(OBJECTS))
	$(A) $(AFLAGS) $@ $^

$(PROJECT): obj/main.o $(LIBPROJECT)
	$(CXX) -o $@ $< $(LDXXFLAGS)

$(TESTPROJECT): $(LIBPROJECT) $(addprefix obj/, $(TEST_OBJECTS))
	$(CXX) -o $@ $(addprefix obj/, $(TEST_OBJECTS)) $(LDGTESTFLAGS)
	
test: $(TESTPROJECT)
	./$(TESTPROJECT)

all: $(PROJECT)

.PHONY: clean

clean:
	rm -f obj/*.o

cleanall: clean
	rm -f $(PROJECT)
	rm -f $(LIBPROJECT)
	rm -f $(TESTPROJECT)
