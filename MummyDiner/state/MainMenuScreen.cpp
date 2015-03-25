//
//  MainMenuScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "MainMenuScreen.h"

static FramesPerSecond fps;
static Thread fpsThread(&FramesPerSecond::startCounting, &fps);

MainMenuScreen::MainMenuScreen() {
	_title.set(QUICKSAND_REGULAR_FONT, 80, "MummyDiner", 60, 20, 200, 0, 250);
	_startButton.set(60, 300, 100, 100, 0, 255, 0, "Start", 0, 0, 0);
	_settingsButton.set(470, 300, 100, 100, 0, 255, 0, "Settings", 0, 0, 0);
	
	// initialise mouse position
	_mouseXPos = 0;
	_mouseYPos = 0;
	
#if DEBUG_MODE == 1
	_debug.set();
#endif
	
	fpsThread.launch();
}

void MainMenuScreen::handleEvent() {
	fps.hasReachedStartOfFrame();

	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			fps.stopCounting();
		
			cleanup();
			
			setState(EXIT);
		}

#if DEBUG_MODE == 1
		if (event.type == event.MouseMoved) {
			_debug.setMousePosition(MOUSE_X, MOUSE_Y);
		}
		
		if (event.type == event.KeyPressed) {
			if (event.key.code == Keyboard::Escape) {
				fps.stopCounting();
				
				cleanup();
				
				setState(EXIT);
			}
		}
#endif
		
		if (event.type == event.MouseButtonPressed) {
			if (MOUSE_X_CLICK >= _startButton.getLeftSide() && MOUSE_X_CLICK <= _startButton.getWidth()) {
				if (MOUSE_Y_CLICK >= _startButton.getTop() && MOUSE_Y_CLICK <= _startButton.getHeight()) {
					fps.stopCounting();
					
					cleanup();
					
					setState(LEVEL);
				}
			}
		}
	}
}

void MainMenuScreen::update() {
	window.clear(color.White);
	
	fps.hasReachedEndOfFrame();
	
#if DEBUG_MODE == 1
	_debug.setFPSValue(fps.getFPS());
#endif
}

void MainMenuScreen::render() {
	_title.render(window);
	_startButton.render(window);
	_settingsButton.render(window);
	
#if DEBUG_MODE == 1
	_debug.show(window);
#endif
	
	window.display();
}