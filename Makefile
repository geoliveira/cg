CC			:= g++
FLAGS		:= -Wall
INCLUDE		:= include
SRC			:= src
EXECUTABLE	:= main

all: $(EXECUTABLE)

run: clean all
	./$(EXECUTABLE)
	# clear

$(EXECUTABLE): 
	$(CC) $(FLAGS) $(SRC)/*.cpp -I$(INCLUDE) -o $@

clean: rmppm
	-rm main

rmppm:
	-rm img/*