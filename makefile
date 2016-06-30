CXXFLAGS=-g -O0 -Wall -Wextra -std=c++11 -I. -MD

CXXFLAGS+=-Iextern/rapidxml-1.13

SRC=\
	main.cpp\
	core/component.cpp\
	core/event.cpp\
	core/object.cpp\
	core/property.cpp\
	components/dummy.cpp\
	components/living.cpp\
	components/damagereductioneffect.cpp\

OBJ=$(SRC:.cpp=.o)

default: game

core/global.h.gch: core/global.h
	$(CXX) $(CXXFLAGS) -c -o core/global.h.gch core/global.h

game: $(OBJ) core/global.h.gch
	$(CXX) $(CXXFLAGS) -o game $(OBJ)

clean:
	-rm -f $(OBJ) $(OBJ:.o=.d) game core/global.h.gch core/global.h.d

-include $(OBJ:.o=.d)
-include core/global.h.d
