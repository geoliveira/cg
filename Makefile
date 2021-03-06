CC			:= g++
FLAGS		:= -Wall
INCLUDE		:= include
SRC			:= src
OBJS		:= $(patsubst $(SRC)/%.cpp, $(SRC)/%.o, $(wildcard $(SRC)/*.cpp))
EXECUTABLE	:= main

all: $(EXECUTABLE)

run: all
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

$(SRC)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) -c -I$(INCLUDE) -o $@ $<

clean:
	-rm main
	-rm $(SRC)/*.o

rmppm:
	-rm img/*