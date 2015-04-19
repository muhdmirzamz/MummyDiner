//
//  SettingsScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "SettingsScreen.h"

SettingsScreen::SettingsScreen() {
	_backToMainMenuButton.setButtonUsingName("_backToMainMenuButton", "Back to\nmain menu");
	
	_settingsScreenTitle.setTextUsingName("_settingsScreenTitle", "Settings");
	
	_debugToggle.setToggle("Debug", 100, ToggleClass::DEBUG_TOGGLE);
	_controlToggle.setToggle("Use\nkeyboard", 150, ToggleClass::CONTROL_TOGGLE);
}

void SettingsScreen::handleEvent() {
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanupSettingsScreen(EXIT);
		}
		
		if (event.type == event.MouseButtonPressed) {
			if (_backToMainMenuButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
				cleanupSettingsScreen(MAIN_MENU);
			}
			
			_debugToggle.checkToggle(MOUSE_X_CLICK, MOUSE_Y_CLICK, ToggleClass::DEBUG_TOGGLE);
			if (_debugToggle.isDebugSwitchOn()) {
				Utility::debug = true;
			} else {
				Utility::debug = false;
			}
			
			_controlToggle.checkToggle(MOUSE_X_CLICK, MOUSE_Y_CLICK, ToggleClass::CONTROL_TOGGLE);
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
	
	_settingsScreenTitle.render(window);

	_debugToggle.render(window);
	_controlToggle.render(window);

	window.display();
}

void SettingsScreen::cleanupSettingsScreen(int state) {
	cleanup();
	
	setState(state);
}