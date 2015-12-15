CXX=g++

CFLAGS=-Wall -std=c++11 -I./include -c
LFLAGS=-Wall -g -F./ -framework sfml-system -framework sfml-window -framework sfml-graphics -o

COMPILE=$(CXX) $(CFLAGS) $^

GUI_CLASSES=BackgroundClass.o ImageClass.o ToggleClass.o ButtonClass.o TextClass.o
UTIL_CLASSES=Utility.o Timer.o LevelTimer.o CustomerTimer.o ChefTimer.o FramesPerSecond.o MenuSystem.o
SPRITE_CLASSES=SpriteClass.o Waitress.o Customer.o Chef.o
STATE_CLASSES=GameState.o MainMenuScreen.o ModeMenuScreen.o HowToPlayScreen.o SettingsScreen.o LevelScreen.o GameOverScreen.o

Game: $(GUI_CLASSES) $(UTIL_CLASSES) $(SPRITE_CLASSES) $(STATE_CLASSES) main.o
	@#copy dependency frameworks into system directory
	@#regardless of whether they already exist
	cp -r freetype.framework /Library/Frameworks
	cp -r sndfile.framework /Library/Frameworks  

	$(CXX) $(LFLAGS) $@ $^

	#change the location of where make searches for the required frameworks
	#by default, make searches at the system directory
	install_name_tool -change @rpath/sfml-system.framework/Versions/2.3.2/sfml-system @loader_path/sfml-system.framework/Versions/2.3.2/sfml-system Game
	install_name_tool -change @rpath/sfml-window.framework/Versions/2.3.2/sfml-window @loader_path/sfml-window.framework/Versions/2.3.2/sfml-window Game
	install_name_tool -change @rpath/sfml-graphics.framework/Versions/2.3.2/sfml-graphics @loader_path/sfml-graphics.framework/Versions/2.3.2/sfml-graphics Game
	install_name_tool -change @rpath/SFML.framework/Versions/2.3.2/SFML @loader_path/SFML.framework/Versions/2.3.2/SFML Game
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
	rm -r /Library/Frameworks/freetype.framework
	rm -r /Library/Frameworks/sndfile.framework 
	rm -r *.o Game
