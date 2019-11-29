CFLAGS = -ansi -pedantic -Wall -std=c++11

SRCS=main.cpp
INCLUDE=Catalogue.cpp Catalogue.h Trajet.cpp Trajet.h TrajetCompose.cpp TrajetCompose.h TrajetListe.cpp TrajetListe.h TrajetSimple.cpp TrajetSimple.h
MAIN=$(SRCS:.cpp=)

all : $(SRCS)
	g++ $(CFLAGS)  $(SRCS) $(INCLUDE)  -o $(MAIN)

clean:
	rm $(MAIN)

debug : CFLAGS += -DMAP

debug : all
