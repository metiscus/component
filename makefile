CXXFLAGS=-g -O0 -Wall -Wextra -std=c++11 -I. -MD

CXXFLAGS+=-Iextern/rapidxml-1.13 -Iextern

CXXFLAGS+=-fno-omit-frame-pointer -fsanitize=address

default: game

LIB_CORE_SRC=\
	core/component.cpp\
	core/event.cpp\
	core/object.cpp\
	core/property.cpp\
	core/world.cpp\
	core/system.cpp\
	components/dummy.cpp\
	components/living.cpp\
	components/damagereductioneffect.cpp\
	components/healingeffect.cpp\

LIB_CORE_OBJ=$(LIB_CORE_SRC:.cpp=.o)

core/global.h.gch: core/global.h
	$(CXX) $(CXXFLAGS) -c -o core/global.h.gch core/global.h

libcore.a: $(LIB_CORE_OBJ) core/global.h.gch
	ar -rcs libcore.a $(LIB_CORE_OBJ)

libglad.a: $(LIB_GLAD_OBJ)
	$(CXX) $(CXXFLAGS) -o glad.o -c extern/glad/glad.c
	ar -rcs libglad.a glad.o

GAME_SRC=\
	example/main.cpp\
	example/rendersystem.cpp\
	example/render/window.cpp\
	example/rendercomponent.cpp

SDL_INCLUDE := `pkg-config sdl2 --cflags`
CXXFLAGS += $(SDL_INCLUDE)
GAME_OBJ=$(GAME_SRC:.cpp=.o)
LDFLAGS := `pkg-config sdl2 --libs` -ldl

game: $(GAME_OBJ) libcore.a libglad.a
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o game $(GAME_OBJ) -L. -lcore -lglad

clean:
	-rm -f $(LIB_CORE_OBJ) $(LIB_CORE_OBJ:.o=.d) core/global.h.gch core/global.h.d libcore.a
	-rm -f $(GAME_OBJ) $(GAME_OBJ:.o=.d) game
	-rm -f rm -f glad.o libglad.a

-include $(LIB_CORE_OBJ:.o=.d)
-include $(GAME_OBJ:.o=.d)
-include core/global.h.d
