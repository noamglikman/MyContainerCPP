C = g++
CFLAGS = -c -Wall -std=c++17 -g -I$(HPP)

TARGET = demo
TEST_TARGET = tests

CPP = CPP/
HPP = HPP/
OBJ = OBJ/


SOURCES = demo.cpp tests.cpp


OBJS = $(patsubst %.cpp,$(OBJ)%.o,$(notdir $(SOURCES)))

$(OBJ):
	mkdir -p $(OBJ)

all: $(TARGET)

$(TARGET): $(filter-out $(OBJ)tests.o,$(OBJS))
	$(C) -Wall -std=c++17 -g -o $(TARGET) $(filter-out $(OBJ)tests.o,$(OBJS))

$(TEST_TARGET): $(filter-out $(OBJ)demo.o,$(OBJS))
	$(C) -Wall -std=c++17 -g -o $(TEST_TARGET) $(filter-out $(OBJ)demo.o,$(OBJS))


$(OBJ)%.o: $(CPP)%.cpp | $(OBJ)
	$(C) $(CFLAGS) $< -o $@


$(OBJ)demo.o: demo.cpp | $(OBJ)
	$(C) $(CFLAGS) demo.cpp -o $(OBJ)demo.o

$(OBJ)tests.o: tests.cpp | $(OBJ)
	$(C) $(CFLAGS) tests.cpp -o $(OBJ)tests.o
##make run      
#make demo_run   
#make test_run   
run: $(TARGET)
	./$(TARGET)

demo_run: $(TARGET)
	./$(TARGET)

test_run: $(TEST_TARGET)
	./$(TEST_TARGET)
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

valgrind_test: $(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_TARGET)

clean:
	rm -rf $(OBJ) *.o $(TARGET) $(TEST_TARGET)

.PHONY: all clean
