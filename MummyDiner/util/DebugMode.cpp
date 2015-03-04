//
//  DebugMode.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 13/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "DebugMode.h"

DebugMode::DebugMode() {
	_font.loadFromFile("fonts/Lato-Light.ttf");
	_fontSize = 15;
	
	_valuePositionOffset = 10;
}

// add debug properties here
void DebugMode::set() {
	setTextAndPosition(_fps, "FPS: ", 10, 10, _fpsValue);
}

// set the value of any changing / dynamic debug properties
// one example: FPS
void DebugMode::setFPSValue(float value) {
	_fpsValue.setString(to_string(value)); // change numeric value to string
}

void DebugMode::show(RenderWindow &window) {
	window.draw(_fps);
	window.draw(_fpsValue);
}

// dealing with two things
// the text and the value side by side
void DebugMode::setTextAndPosition(Text variableLabel, string label, float variableX, float variableY, Text variableValue) {
	setText(variableLabel);
	variableLabel.setString(label);
	
	setText(variableValue);
	
	variableLabel.setPosition(variableX, variableY);
	variableValue.setPosition(VALUE_X_POS, variableY); // set the value a bit to the right side, same y position though
}

void DebugMode::setText(Text variable) {
	variable.setFont(_font);
	variable.setCharacterSize(_fontSize);
	variable.setStyle(Text::Bold);
	variable.setColor(Color(0, 0, 0));
}