//
//  ToggleClass.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 31/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "ToggleClass.h"

#define PROPERTY_X_POS 10

#define TOGGLE_SIZE 50

#define OFF_TOGGLE_X_POS PROPERTY_X_POS + 100
#define ON_TOGGLE_X_POS OFF_TOGGLE_X_POS + TOGGLE_SIZE

static bool debugSwitchOn = false;
static bool controlSwitchOn = false;

ToggleClass::ToggleClass() {
	
}

void ToggleClass::setToggle(string text, float y, int toggle) {
	_property.setTextClass(QUICKSAND_REGULAR_FONT, text, PROPERTY_X_POS, y);
	
	_offToggle.setButton("OFF", OFF_TOGGLE_X_POS, y, TOGGLE_SIZE, TOGGLE_SIZE);
	_onToggle.setButton("ON", ON_TOGGLE_X_POS, y, TOGGLE_SIZE, TOGGLE_SIZE);
	
	if (toggle == DEBUG_TOGGLE) {
		if (!debugSwitchOn) {
			_offToggle.setColour(255, 0, 0);
			_onToggle.setColour(0, 100, 0);
		} else {
			_offToggle.setColour(100, 0, 0);
			_onToggle.setColour(0, 255, 0);
		}
	}
	
	if (toggle == CONTROL_TOGGLE) {
		if (!controlSwitchOn) {
			_offToggle.setColour(255, 0, 0);
			_onToggle.setColour(0, 100, 0);
		} else {
			_offToggle.setColour(100, 0, 0);
			_onToggle.setColour(0, 255, 0);
		}
	}
	
	_yPos = y;
}

void ToggleClass::checkToggle(int mouseClickXPos, int mouseClickYPos, int toggle) {
	if (_offToggle.isClicked(mouseClickXPos, mouseClickYPos)) {
		if (toggle == DEBUG_TOGGLE) {
			if (debugSwitchOn) { // switch toggle to off
				_offToggle.setColour(255, 0, 0);
				_onToggle.setColour(0, 100, 0);
				
				debugSwitchOn = false;
			}
		}
		
		if (toggle == CONTROL_TOGGLE) {
			if (controlSwitchOn) { // switch toggle to off
				_offToggle.setColour(255, 0, 0);
				_onToggle.setColour(0, 100, 0);
				
				controlSwitchOn = false;
			}
		}
	}
	
	if (_onToggle.isClicked(mouseClickXPos, mouseClickYPos)) {
		if (toggle == DEBUG_TOGGLE) {
			if (!debugSwitchOn) {
				_offToggle.setColour(100, 0, 0);
				_onToggle.setColour(0, 255, 0);
				
				debugSwitchOn = true;
			}
		}
		
		if (toggle == CONTROL_TOGGLE) {
			if (!controlSwitchOn) {
				_offToggle.setColour(100, 0, 0);
				_onToggle.setColour(0, 255, 0);
				
				controlSwitchOn = true;
			}
		}
	}
}

bool ToggleClass::isDebugSwitchOn() {
	return debugSwitchOn;
}

bool ToggleClass::isControlSwitchOn() {
	return controlSwitchOn;
}

void ToggleClass::render(RenderWindow &window) {
	_property.render(window);
	
	_offToggle.render(window);
	_onToggle.render(window);
}