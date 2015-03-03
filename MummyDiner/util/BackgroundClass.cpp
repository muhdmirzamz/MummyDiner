//
//  BackgroundClass.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 11/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "BackgroundClass.h"

BackgroundClass::BackgroundClass() {
	_rectangleBackground = &_rectangleBackgroundObj;
}

void BackgroundClass::setBackground(float x, float y, float w, float h) {
	_rectangleBackground->setPosition(x, y);
	_rectangleBackground->setSize(Vector2f(w, h));
}

void BackgroundClass::setColor(Uint8 r, Uint8 g, Uint8 b) {
	_color.r = r;
	_color.g = g;
	_color.b = b;

	_rectangleBackground->setFillColor(_color);
}

RectangleShape* BackgroundClass::getBackground() {
	return _rectangleBackground;
}