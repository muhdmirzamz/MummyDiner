//
//  SettingsScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "SettingsScreen.h"

SettingsScreen::SettingsScreen() {
	_rect = &_rectObj;

	_rect->chooseButton(RECTANGLE);
	_rect->setButton(200, 200, 200, 200);
	_rect->setColor(0, 0, 255);
}

void SettingsScreen::handleEvent() {
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanup();
			
			setState(EXIT);
		}
		
		if (event.type == event.KeyPressed) {
			if (event.key.code == Keyboard::C) {
				cleanup();
			
				setState(MAIN_MENU);
			}
		}
	}
}

void SettingsScreen::update() {
	window.clear(color.Red);
}

void SettingsScreen::render() {
	window.draw(*_rect->getButton());

	window.display();
}