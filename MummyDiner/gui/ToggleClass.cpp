//
//  ToggleClass.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 31/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "ToggleClass.h"

#define PROPERTY_X_POS 10

#define TOGGLE_W 50
#define TOGGLE_H 50

#define OFF_TOGGLE_X_POS PROPERTY_X_POS + 100
#define ON_TOGGLE_X_POS OFF_TOGGLE_X_POS + TOGGLE_W

static bool debugSwitchOn = false;
static bool controlSwitchOn = false;

ToggleClass::ToggleClass() {
	
}

void ToggleClass::setDebugToggle(float y, string text) {
	_property.set(QUICKSAND_REGULAR_FONT, 15, text, PROPERTY_X_POS, y, 0, 0, 0);
	
	if (!debugSwitchOn) {
		_propertyOffToggle.set(OFF_TOGGLE_X_POS, y, TOGGLE_W, TOGGLE_H, 255, 0, 0, "OFF", 255, 255, 255); // start as switched off
		_propertyOnToggle.set(ON_TOGGLE_X_POS, y, TOGGLE_W, TOGGLE_H, 0, 100, 0, "ON", 255, 255, 255);
	} else {
		_propertyOffToggle.set(OFF_TOGGLE_X_POS, y, TOGGLE_W, TOGGLE_H, 100, 0, 0, "OFF", 255, 255, 255);
		_propertyOnToggle.set(ON_TOGGLE_X_POS, y, TOGGLE_W, TOGGLE_H, 0, 255, 0, "ON", 255, 255, 255);
	}
	
	_yPos = y;
}

void ToggleClass::setControlToggle(float y, string text) {
	_property.set(QUICKSAND_REGULAR_FONT, 15, text, PROPERTY_X_POS, y, 0, 0, 0);

	if (!controlSwitchOn) {
		_propertyOffToggle.set(OFF_TOGGLE_X_POS, y, TOGGLE_W, TOGGLE_H, 255, 0, 0, "OFF", 255, 255, 255); // start as switched off
		_propertyOnToggle.set(ON_TOGGLE_X_POS, y, TOGGLE_W, TOGGLE_H, 0, 100, 0, "ON", 255, 255, 255);
	} else {
		_propertyOffToggle.set(OFF_TOGGLE_X_POS, y, TOGGLE_W, TOGGLE_H, 100, 0, 0, "OFF", 255, 255, 255);
		_propertyOnToggle.set(ON_TOGGLE_X_POS, y, TOGGLE_W, TOGGLE_H, 0, 255, 0, "ON", 255, 255, 255);
	}
	
	_yPos = y;
}

void ToggleClass::checkDebugToggle(int mouseClickXPos, int mouseClickYPos) {
	if (mouseClickXPos >= _propertyOffToggle.getLeftSide() && mouseClickXPos <= _propertyOffToggle.getLeftSide() + _propertyOffToggle.getWidth()) {
		if (mouseClickYPos >= _propertyOffToggle.getTop() && mouseClickYPos <= _propertyOffToggle.getTop() + _propertyOffToggle.getHeight()) {
			if (debugSwitchOn) { // switch toggle to off
				_propertyOffToggle.setColour(255, 0, 0);
				_propertyOnToggle.setColour(0, 100, 0);
				
				debugSwitchOn = false;
			} else {
				_propertyOffToggle.setColour(255, 0, 0);
				_propertyOnToggle.setColour(0, 100, 0);
			}
		}
	}
	
	if (mouseClickXPos >= _propertyOnToggle.getLeftSide() && mouseClickXPos <= _propertyOnToggle.getLeftSide() + _propertyOnToggle.getWidth()) {
		if (mouseClickYPos >= _propertyOnToggle.getTop() && mouseClickYPos <= _propertyOnToggle.getTop() + _propertyOnToggle.getHeight()) {
			if (!debugSwitchOn) {
				_propertyOffToggle.setColour(100, 0, 0);
				_propertyOnToggle.setColour(0, 255, 0);
				
				debugSwitchOn = true;
			} else {
				_propertyOffToggle.setColour(100, 0, 0);
				_propertyOnToggle.setColour(0, 255, 0);
			}
		}
	}
}

void ToggleClass::checkControlToggle(int mouseClickXPos, int mouseClickYPos) {
	if (mouseClickXPos >= _propertyOffToggle.getLeftSide() && mouseClickXPos <= _propertyOffToggle.getLeftSide() + _propertyOffToggle.getWidth()) {
		if (mouseClickYPos >= _propertyOffToggle.getTop() && mouseClickYPos <= _propertyOffToggle.getTop() + _propertyOffToggle.getHeight()) {
			if (controlSwitchOn) { // switch toggle to off
				_propertyOffToggle.setColour(255, 0, 0);
				_propertyOnToggle.setColour(0, 100, 0);
				
				controlSwitchOn = false;
			} else {
				_propertyOffToggle.setColour(255, 0, 0);
				_propertyOnToggle.setColour(0, 100, 0);
			}
		}
	}
	
	if (mouseClickXPos >= _propertyOnToggle.getLeftSide() && mouseClickXPos <= _propertyOnToggle.getLeftSide() + _propertyOnToggle.getWidth()) {
		if (mouseClickYPos >= _propertyOnToggle.getTop() && mouseClickYPos <= _propertyOnToggle.getTop() + _propertyOnToggle.getHeight()) {
			if (!controlSwitchOn) {
				_propertyOffToggle.setColour(100, 0, 0);
				_propertyOnToggle.setColour(0, 255, 0);
				
				controlSwitchOn = true;
			} else {
				_propertyOffToggle.setColour(100, 0, 0);
				_propertyOnToggle.setColour(0, 255, 0);
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
	
	_propertyOffToggle.render(window);
	_propertyOnToggle.render(window);
}