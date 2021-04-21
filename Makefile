CC			:= g++
FLAGS		:= -Wall
INCLUDE		:= include
SRC			:= src
EXECUTABLE	:= main

all: $(EXECUTABLE)

run: clean all
	clear
	./$(EXECUTABLE)

$(EXECUTABLE): 
	$(CC) $(FLAGS) $(SRC)/*.cpp -I$(INCLUDE) -o $@

clean:
	-rm main

rmppm:
	-rm img/*