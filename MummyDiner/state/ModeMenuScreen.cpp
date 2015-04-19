//
//  ModeMenu.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/4/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "ModeMenuScreen.h"

ModeMenuScreen::ModeMenuScreen() {
	_modeMenuScreenTitle.setTextUsingName("_modeMenuScreenTitle", "Mode Select Menu");

	_normalModeButton.setButtonUsingName("_normalMode", "Normal");
	_practiceModeButton.setButtonUsingName("_practiceMode", "Practice");
}

void ModeMenuScreen::handleEvent() {
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanupModeMenuScreen(EXIT);
		}
		
		if (event.type == event.MouseButtonPressed) {
			if (_normalModeButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
				LevelScreen::normalMode = true;
				
				cleanupModeMenuScreen(LEVEL);
			}
			
			if (_practiceModeButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
				LevelScreen::normalMode = false;
				
				cleanupModeMenuScreen(LEVEL);
			}
		}
	}
}

void ModeMenuScreen::update() {
	window.clear(color.White);
}

void ModeMenuScreen::render() {
	_modeMenuScreenTitle.render(window);

	_normalModeButton.render(window);
	_practiceModeButton.render(window);

	window.display();
}

void ModeMenuScreen::cleanupModeMenuScreen(int state) {
	cleanup();
	
	setState(state);
}