ALL = game;

OBJ = main.o objects.o game.o hero.o map.o slime.o skeleton.o bulet.o
CXXFLAGS += -std=c++17 -Wall -g 


all: $(ALL)

game: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ -lsfml-graphics -lsfml-window -lsfml-system $^

clean: 
	$(RM) $(OBJ) $(ALL) .depend *~ * .bak *stackdump core*

depend:
	$(CXX) $(CXXFLAGS) -MM $(OBJ:.o=.cpp) >.depend

-include .depend