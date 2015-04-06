//
//  ModeMenu.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/4/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "ModeMenu.h"

ModeMenu::ModeMenu() {
	_title.set(LATO_LIGHT_FONT, 40, "Mode Select Menu", 250, 20, 0, 0, 0);

	_normalMode.set(100, 300, 200, 100, 0, 100, 0, "Normal", 255, 255, 255);
	_practiceMode.set(500, 300, 200, 100, 0, 100, 0, "Practice", 255, 255, 255);
}

void ModeMenu::handleEvent() {
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanup();
			
			setState(EXIT);
		}
		
		if (event.type == event.MouseButtonPressed) {
			if (MOUSE_X_CLICK >= _normalMode.getLeftSide() && MOUSE_X_CLICK <= _normalMode.getLeftSide() + _normalMode.getWidth()) {
				if (MOUSE_Y_CLICK >= _normalMode.getTop() && MOUSE_Y_CLICK <= _normalMode.getTop() + _normalMode.getHeight()) {
					cleanup();
				
					LevelScreen::normalMode = true;
					
					setState(LEVEL);
				}
			}
			
			if (MOUSE_X_CLICK >= _practiceMode.getLeftSide() && MOUSE_X_CLICK <= _practiceMode.getLeftSide() + _practiceMode.getWidth()) {
				if (MOUSE_Y_CLICK >= _practiceMode.getTop() && MOUSE_Y_CLICK <= _practiceMode.getTop() + _practiceMode.getHeight()) {
					cleanup();
					
					LevelScreen::normalMode = false;
					
					setState(LEVEL);
				}
			}
		}
	}
}

void ModeMenu::update() {
	window.clear(color.White);
}

void ModeMenu::render() {
	_title.render(window);

	_normalMode.render(window);
	_practiceMode.render(window);

	window.display();
}