//
//  SettingsScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "SettingsScreen.h"

SettingsScreen::SettingsScreen() {
	_backToMainMenuButton.set(10, 10, 150, 80, 0, 200, 255, "Back to\nmain menu", 0, 0, 0);
	
	_title.set(LATO_LIGHT_FONT, 50, "Settings", 260, 20, 100, 100, 100);
	
	_debugToggle.setDebugToggle(100, "Debug");
	_controlToggle.setControlToggle(150, "Use\nkeyboard");
}

void SettingsScreen::handleEvent() {
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanup();
			
			setState(EXIT);
		}
		
		if (event.type == event.MouseButtonPressed) {
			if (MOUSE_X_CLICK >= _backToMainMenuButton.getLeftSide() && MOUSE_X_CLICK <= _backToMainMenuButton.getLeftSide()+_backToMainMenuButton.getWidth()) {
				if (MOUSE_Y_CLICK >= _backToMainMenuButton.getTop() && MOUSE_Y_CLICK <= _backToMainMenuButton.getTop() + _backToMainMenuButton.getHeight()) {
					cleanup();
					
					setState(MAIN_MENU);
				}
			}
			
			_debugToggle.checkDebugToggle(MOUSE_X_CLICK, MOUSE_Y_CLICK);
			if (_debugToggle.isDebugSwitchOn()) {
				Utility::debug = true;
			} else {
				Utility::debug = false;
			}
			
			_controlToggle.checkControlToggle(MOUSE_X_CLICK, MOUSE_Y_CLICK);
			if (_controlToggle.isControlSwitchOn()) {
				Utility::keyboardIsUsed = true;
			} else {
				Utility::keyboardIsUsed = false;
			}
		}
	}
}

void SettingsScreen::update() {
	window.clear(color.White);
}

void SettingsScreen::render() {
	_backToMainMenuButton.render(window);
	
	_title.render(window);

	_debugToggle.render(window);
	_controlToggle.render(window);

	window.display();
}