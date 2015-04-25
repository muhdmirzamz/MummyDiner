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
	_mainMenuTitle.setTextUsingName("_mainMenuTitle", "MummyDiner");

	_startButton.setButtonUsingName("_startButton", "Start");
	_howToPlayButton.setButtonUsingName("_howToPlayButton", "How To\nPlay");
	_settingsButton.setButtonUsingName("_settingsButton", "Settings");

	if (Utility::debug) {
		_debug.set();
	}
	
	fpsThread.launch();
}

void MainMenuScreen::handleEvent() {
	fps.setFrameStartPoint();

	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanupMainMenuScreen(EXIT);
		}

		if (Utility::debug) {
			if (event.type == event.MouseMoved) {
				_debug.setMousePosition(MOUSE_X, MOUSE_Y);
			}
			
			if (event.type == event.KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					cleanupMainMenuScreen(EXIT);
				}
			}
		}
		
		if (event.type == event.MouseButtonPressed) {
			if (_startButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
				cleanupMainMenuScreen(MODE_MENU);
			}
			
			if (_howToPlayButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
				cleanupMainMenuScreen(HOW_TO_PLAY);
			}
			
			if (_settingsButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
				cleanupMainMenuScreen(SETTINGS);
			}
		}
	}
}

void MainMenuScreen::update() {
	window.clear(color.White);
	
	fps.setFrameEndPoint();
	
	if (Utility::debug) {
		_debug.setFPSValue(fps.getFPS());
	}
}

void MainMenuScreen::render() {
	_mainMenuTitle.render(window);
	
	_startButton.render(window);
	_howToPlayButton.render(window);
	_settingsButton.render(window);
	
	if (Utility::debug) {
		_debug.show(window);
	}
	
	window.display();
}

void MainMenuScreen::cleanupMainMenuScreen(int state) {
	fps.stopCounting();
	
	cleanup();
	
	setState(state);
}