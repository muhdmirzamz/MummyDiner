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
	_title.set(QUICKSAND_REGULAR_FONT, 80, "MummyDiner", SCREEN_W / 6, 20, 200, 0, 250);
	
	_startButton.set(140, 400, 100, 100, 0, 255, 0, "Start", 0, 0, 0);
	_howToPlayButton.set(350, 400, 100, 100, 0, 255, 0, "How to \nplay", 0, 0, 0);
	_settingsButton.set(550, 400, 100, 100, 0, 255, 0, "Settings", 0, 0, 0);
	
	// initialise mouse position
	_mouseXPos = 0;
	_mouseYPos = 0;

	if (Utility::debug) {
		_debug.set();
	}
	
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

		if (Utility::debug) {
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
		}
		
		if (event.type == event.MouseButtonPressed) {
			if (MOUSE_X_CLICK >= _startButton.getLeftSide() && MOUSE_X_CLICK <= _startButton.getLeftSide() + _startButton.getWidth()) {
				if (MOUSE_Y_CLICK >= _startButton.getTop() && MOUSE_Y_CLICK <= _startButton.getTop() + _startButton.getHeight()) {
					fps.stopCounting();
					
					cleanup();
					
					setState(MODE_MENU);
				}
			}
			
			if (MOUSE_X_CLICK >= _howToPlayButton.getLeftSide() && MOUSE_X_CLICK <= _howToPlayButton.getLeftSide() + _howToPlayButton.getWidth()) {
				if (MOUSE_Y_CLICK >= _howToPlayButton.getTop() && MOUSE_Y_CLICK <= _howToPlayButton.getTop() + _howToPlayButton.getHeight()) {
					fps.stopCounting();
					
					cleanup();
					
					setState(HOW_TO_PLAY);
				}
			}
			
			if (MOUSE_X_CLICK >= _settingsButton.getLeftSide() && MOUSE_X_CLICK <= _settingsButton.getLeftSide() + _settingsButton.getWidth()) {
				if (MOUSE_Y_CLICK >= _settingsButton.getTop() && MOUSE_Y_CLICK <= _settingsButton.getTop() + _settingsButton.getHeight()) {
					fps.stopCounting();
					
					cleanup();
					
					setState(SETTINGS);
				}
			}
		}
	}
}

void MainMenuScreen::update() {
	window.clear(color.White);
	
	fps.hasReachedEndOfFrame();
	
	if (Utility::debug) {
		_debug.setFPSValue(fps.getFPS());
	}
}

void MainMenuScreen::render() {
	_title.render(window);
	
	_startButton.render(window);
	_howToPlayButton.render(window);
	_settingsButton.render(window);
	
	if (Utility::debug) {
		_debug.show(window);
	}
	
	window.display();
}