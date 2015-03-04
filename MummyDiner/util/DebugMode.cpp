//
//  DebugMode.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 13/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "DebugMode.h"

DebugMode::DebugMode() {
	_color.r = 0;
	_color.g = 0;
	_color.b = 0;
	
	_font.loadFromFile("fonts/Lato-Light.ttf");
	_fontSize = 15;
	
	_valuePositionOffset = 10;
}

// add debug properties here
void DebugMode::setDebugMode() {
	setTextAndPosition(_fps, "FPS: ", 10, 10, _fpsValue);
}

void DebugMode::setTextAndPosition(Text variable, string text, float variableX, float variableY, Text variableValue) {
	// the text
	variable.setFont(_font);
	variable.setString(text);
	variable.setCharacterSize(_fontSize);
	variable.setStyle(Text::Bold);
	variable.setColor(_color);
	
	// the value, except the value
	variableValue.setFont(_font);
	variableValue.setCharacterSize(_fontSize);
	variableValue.setStyle(Text::Bold);
	variableValue.setColor(_color);
	
	variable.setPosition(variableX, variableY);
	variableValue.setPosition(POSITION_VALUE, variableY); // set the value a bit to the right side, same y position though
}

// set the value of any changing / dynamic debug properties
// one example: FPS
void DebugMode::setFPSValue(int value) {
	_fpsValue.setString(to_string(value)); // change numeric value to string
}

void DebugMode::showDebugMode(RenderWindow &window) {
	window.draw(_fps);
	window.draw(_fpsValue);
}

