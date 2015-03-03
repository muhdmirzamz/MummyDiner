//
//  DebugMode.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 13/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "DebugMode.h"

DebugMode::DebugMode() {
	_font = &_fontObj;
	
	_variableName = &_variableNameObj;
	_variableValue = &_variableValueObj;
	
	_background = &_backgroundObj;
}

void DebugMode::setText(string text, int size) {
	_color.r = 0;
	_color.g = 0;
	_color.b = 0;

	_font->loadFromFile("Lato-Light.ttf");
	
	_variableName->setFont(*_font);
	_variableName->setString(text);
	_variableName->setCharacterSize(size);
	_variableName->setStyle(Text::Bold);
	_variableName->setColor(_color);
}

void DebugMode::setTextPosition(float textX, float valueX, float y) {
	_variableName->setPosition(textX, y);
	_variableValue->setPosition(valueX, y);
}

void DebugMode::setValue(int value, int size) {
	_variableValue->setFont(*_font);
	_variableValue->setString(to_string(value));
	_variableValue->setCharacterSize(size);
	_variableValue->setStyle(Text::Bold);

	_variableValue->setColor(_color);
}

Text* DebugMode::getText() {
	return _variableName;
}

Text* DebugMode::getValue() {
	return _variableValue;
}

void DebugMode::setBackgroundPosition(int x, int y, int w, int h) {
	_background->setBackground(x, y, w, h);
}

void DebugMode::drawBackground(Uint8 r, Uint8 g, Uint8 b) {
	_background->setColor(r, g, b);
}

RectangleShape* DebugMode::getBackground() {
	// get the rectangle
	// not the Background object
	return _background->getBackground();
}