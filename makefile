CC = g++
CC_FLAGS = -std=c++20 -Wall -Wextra -Werror

EXEC = achess
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

$|(EXEC): $(OBJECTS)
	$(CC) $(CC_FLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm -f $(EXEC) $(OBJECTS)