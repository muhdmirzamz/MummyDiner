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

void ButtonClass::chooseButton(ButtonType button) {
	_buttonType = button;
	
	switch (_buttonType) {
		case RECTANGLE:
			_rectangleButton = &_rectangleButtonObj;
			break;
		
		case CIRCLE:
			_circleButton = &_circleButtonObj;
			break;

		default:
			break;
	}
}

void ButtonClass::setButton(float x, float y, float w, float h) {
	if (_buttonType == RECTANGLE) {
		_rectangleButton->setPosition(x, y);
		_rectangleButton->setSize(Vector2f(w, h));
		
		_leftOfButton = _rectangleButton->getPosition().x;
		_rightOfButton = _leftOfButton + w;
		_topOfButton = _rectangleButton->getPosition().y;
		_bottomOfButton = _topOfButton + h;
	} else {
		printf("Your button type is CIRCLE. Check your function arguments and return types");
	}
}

void ButtonClass::setButton(float x, float y, float radius) {
	if (_buttonType == CIRCLE) {
		_circleButton->setPosition(x, y);
		_circleButton->setRadius(radius);
				
		_radius = radius;
		
		_leftOfButton = _circleButton->getPosition().x;
		_rightOfButton = _leftOfButton + _radius;
		_topOfButton = _circleButton->getPosition().y;
		_bottomOfButton = _topOfButton + radius;
	} else {
		printf("Your button type is RECTANGLE. Check your function arguments and return types");
	}
}

void ButtonClass::setColor(Uint8 r, Uint8 g, Uint8 b) {
	_color.r = r;
	_color.g = g;
	_color.b = b;

	switch (_buttonType) {
		case RECTANGLE:
			_rectangleButton->setFillColor(_color);
			break;
			
		case CIRCLE:
			_circleButton->setFillColor(_color);
			break;
			
		default:
			break;
	}
}

float ButtonClass::getRadius() {
	return _radius;
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

RectangleShape* ButtonClass::getButton() {
	return _rectangleButton;
}

CircleShape* ButtonClass::getCircleButton() {
	return _circleButton;
}