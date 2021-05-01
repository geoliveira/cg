CC			:= g++
FLAGS		:= -Wall
INCLUDE		:= include
SRC			:= src
EXECUTABLE	:= main

all: $(EXECUTABLE)

run: rmmain all
	./$(EXECUTABLE)
	# clear

$(EXECUTABLE): 
	$(CC) $(FLAGS) $(SRC)/*.cpp -I$(INCLUDE) -o $@

rmmain:
	-rm main

clean: rmppm
	-rm main

rmppm:
	-rm img/*