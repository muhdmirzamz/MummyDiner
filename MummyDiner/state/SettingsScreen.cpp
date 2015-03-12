//
//  SettingsScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "SettingsScreen.h"

SettingsScreen::SettingsScreen() {
	_button.set(200, 200, 200, 200, 0, 0, 255, "This is a button", 255, 0, 100);
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
	_button.render(window);

	window.display();
}