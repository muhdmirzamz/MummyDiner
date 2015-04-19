CXX=g++

CFLAGS=-Wall -std=c++11 -c
LFLAGS=-Wall -g -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -o

COMPILE=$(CXX) $(CFLAGS) $^

GUI_CLASSES=BackgroundClass.o ImageClass.o ToggleClass.o ButtonClass.o TextClass.o
UTIL_CLASSES=Utility.o Timer.o LevelTimer.o CustomerTimer.o ChefTimer.o FramesPerSecond.o MenuSystem.o
SPRITE_CLASSES=SpriteClass.o Waitress.o Customer.o Chef.o
STATE_CLASSES=GameState.o MainMenuScreen.o ModeMenuScreen.o HowToPlayScreen.o SettingsScreen.o LevelScreen.o GameOverScreen.o

Game: $(GUI_CLASSES) $(UTIL_CLASSES) $(SPRITE_CLASSES) $(STATE_CLASSES) main.o
	$(CXX) $(LFLAGS) $@ $^
	./Game

#state classes

%.o: MummyDiner/state/%.cpp
	@$(COMPILE)

main.o: MummyDiner/main.cpp
	$(COMPILE)

#sprite
%.o: MummyDiner/sprite/%.cpp
	$(COMPILE)

#gui
%.o: MummyDiner/gui/%.cpp
	$(COMPILE)

#util
%.o: MummyDiner/util/%.cpp
	$(COMPILE)

clean:
	rm -rf *.o Game
