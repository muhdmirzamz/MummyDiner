//
//  DebugMode.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 13/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "DebugMode.h"

#define LABEL_X_POS 10
#define VALUE_X_POS (LABEL_X_POS + _valuePositionOffset)

DebugMode::DebugMode() {
	_font.loadFromFile("fonts/Lato-Light.ttf");
	_fontSize = 15;
	
	_valuePositionOffset = 100;
}

// add debug properties here
void DebugMode::set() {
	setTextAndPosition(_fps, "FPS: ", 10, _fpsValue);
	setTextAndPosition(_mouseXPos, "Mouse X Pos: ", 30, _mouseXPosValue);
	setTextAndPosition(_mouseYPos, "Mouse Y Pos: ", 50, _mouseYPosValue);
}

// set the value of any changing / dynamic debug properties
// one example: FPS
void DebugMode::setFPSValue(float value) {
	_fpsValue.setString(to_string((int)value)); // change numeric value to string
}

void DebugMode::setMousePosition(int x, int y) {
	_mouseXPosValue.setString(to_string(x));
	_mouseYPosValue.setString(to_string(y));
}

void DebugMode::show(RenderWindow &window) {
	window.draw(_fps);
	window.draw(_fpsValue);
	
	window.draw(_mouseXPos);
	window.draw(_mouseXPosValue);
	window.draw(_mouseYPos);
	window.draw(_mouseYPosValue);
}

// dealing with two things
// the text and the value side by side
void DebugMode::setTextAndPosition(Text &variableLabel, string label, float variableY, Text &variableValue) {
	setText(variableLabel);
	setText(variableValue); // no need to set string for value first
	
	variableLabel.setString(label);
	
	variableLabel.setPosition(LABEL_X_POS, variableY);
	variableValue.setPosition(VALUE_X_POS, variableY); // set the value a bit to the right side, same y position though
}

void DebugMode::setText(Text &variable) {
	variable.setFont(_font);
	variable.setCharacterSize(_fontSize);
	variable.setStyle(Text::Bold);
	variable.setColor(Color(0, 0, 0));
}