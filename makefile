CXX=g++

CFLAGS=-Wall -std=c++11 -c
LFLAGS=-Wall -g -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -o

COMPILE=$(CXX) $(CFLAGS) $^

VPATH=MummyDiner:MummyDiner/util:MummyDiner/sprite

UTIL_CLASSES=BackgroundClass.o ButtonClass.o DebugMode.o TextClass.o FramesPerSecond.o
SPRITE_CLASSES=SpriteClass.o Waitress.o Customer.o Chef.o
STATE_CLASSES=GameState.o MainMenuScreen.o SettingsScreen.o LevelScreen.o

Game: $(UTIL_CLASSES) $(SPRITE_CLASSES) $(STATE_CLASSES) main.o
	$(CXX) $(LFLAGS) $@ $^
	./Game

#state classes
LevelScreen.o: LevelScreen.cpp
	$(COMPILE)

SettingsScreen.o: SettingsScreen.cpp
	$(COMPILE)

MainMenuScreen.o: MainMenuScreen.cpp
	$(COMPILE)

GameState.o: GameState.cpp
	$(COMPILE)

main.o: main.cpp
	$(COMPILE)

#sprite
Chef.o: Chef.cpp
	$(COMPILE)

Customer.o: Customer.cpp
	$(COMPILE)

Waitress.o: Waitress.cpp
	$(COMPILE)

SpriteClass.o: SpriteClass.cpp
	$(COMPILE)

#util
FramesPerSecond.o: FramesPerSecond.cpp
	$(COMPILE)

TextClass.o: TextClass.cpp
	$(COMPILE)

DebugMode.o: DebugMode.cpp
	$(COMPILE)

ButtonClass.o: ButtonClass.cpp
	$(COMPILE)

BackgroundClass.o: BackgroundClass.cpp
	$(COMPILE)

clean:
	rm -rf *.o Game
