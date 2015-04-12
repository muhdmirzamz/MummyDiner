//
//  ModeMenu.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/4/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "ModeMenu.h"

ModeMenu::ModeMenu() {
	_modeMenuTitle.setTextUsingName("_modeMenuTitle", "Mode Select Menu");

	_normalModeButton.setButtonUsingName("_normalMode", "Normal");
	_practiceModeButton.setButtonUsingName("_practiceMode", "Practice");
}

void ModeMenu::handleEvent() {
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanup();
			
			setState(EXIT);
		}
		
		if (event.type == event.MouseButtonPressed) {
			if (_normalModeButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
				cleanup();
			
				LevelScreen::normalMode = true;
				
				setState(LEVEL);
			}
			
			if (_practiceModeButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
				cleanup();
				
				LevelScreen::normalMode = false;
				
				setState(LEVEL);
			}
		}
	}
}

void ModeMenu::update() {
	window.clear(color.White);
}

void ModeMenu::render() {
	_modeMenuTitle.render(window);

	_normalModeButton.render(window);
	_practiceModeButton.render(window);

	window.display();
}