CXX=g++

CFLAGS=-Wall -std=c++11 -c
LFLAGS=-Wall -g -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -o

COMPILE=$(CXX) $(CFLAGS) $^

VPATH=MummyDiner:MummyDiner/state:MummyDiner/util:MummyDiner/sprite:MummyDiner/gui

GUI_CLASSES=BackgroundClass.o ImageClass.o ToggleClass.o ButtonClass.o TextClass.o
UTIL_CLASSES=Utility.o Timer.o LevelTimer.o CustomerTimer.o ChefTimer.o FramesPerSecond.o MenuSystem.o
SPRITE_CLASSES=SpriteClass.o Waitress.o Customer.o Chef.o
STATE_CLASSES=GameState.o MainMenuScreen.o ModeMenu.o HowToPlayScreen.o SettingsScreen.o LevelScreen.o GameOverScreen.o

Game: $(GUI_CLASSES) $(UTIL_CLASSES) $(SPRITE_CLASSES) $(STATE_CLASSES) main.o
	$(CXX) $(LFLAGS) $@ $^
	./Game

#state classes
GameOverScreen.o: GameOverScreen.cpp
	$(COMPILE)

LevelScreen.o: LevelScreen.cpp
	$(COMPILE)

HowToPlayScreen.o: HowToPlayScreen.cpp
	$(COMPILE)

SettingsScreen.o: SettingsScreen.cpp
	$(COMPILE)

ModeMenu.o: ModeMenu.cpp
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

#gui
TextClass.o: TextClass.cpp
	$(COMPILE)

ToggleClass.o: ToggleClass.cpp
	$(COMPILE)

ButtonClass.o: ButtonClass.cpp
	$(COMPILE)

BackgroundClass.o: BackgroundClass.cpp
	$(COMPILE)

ImageClass.o: ImageClass.cpp
	$(COMPILE)

#util
FramesPerSecond.o: FramesPerSecond.cpp
	$(COMPILE)

Timer.o: Timer.cpp
	$(COMPILE)

LevelTimer.o: LevelTimer.cpp
	$(COMPILE)

CustomerTimer.o: CustomerTimer.cpp
	$(COMPILE)

ChefTimer.o: ChefTimer.cpp
	$(COMPILE)

Utility.o: Utility.cpp
	$(COMPILE)

MenuSystem.o: MenuSystem.cpp
	$(COMPILE)

clean:
	rm -rf *.o Game
