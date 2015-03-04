//
//  ButtonClass.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 8/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "ButtonClass.h"

ButtonClass::ButtonClass() {

}

void ButtonClass::setButton(float x, float y, float w, float h) {
	_button.setPosition(x, y);
	_button.setSize(Vector2f(w, h));
	
	_leftOfButton = _button.getPosition().x;
	_rightOfButton = _leftOfButton + w;
	_topOfButton = _button.getPosition().y;
	_bottomOfButton = _topOfButton + h;
}

void ButtonClass::setColor(Uint8 r, Uint8 g, Uint8 b) {
	_color.r = r;
	_color.g = g;
	_color.b = b;

	_button.setFillColor(_color);
}

float ButtonClass::getLeftOfButton() {
	return _leftOfButton;
}

float ButtonClass::getRightOfButton() {
	return _rightOfButton;
}

float ButtonClass::getTopOfButton() {
	return _topOfButton;
}

float ButtonClass::getBottomOfButton() {
	return _bottomOfButton;
}

void ButtonClass::render(RenderWindow &window) {
	window.draw(_button);
}