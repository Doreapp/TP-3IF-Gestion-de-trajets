CFLAGS = -ansi -pedantic -Wall -std=c++11

SRCS=main.cpp
MAIN=$(SRCS:.cpp=)

$(MAIN) : $(SRCS)
	g++ $(SRCS) -o $(MAIN)

clean:
	rm $(MAIN)
