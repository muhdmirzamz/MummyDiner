//
//  Waitress.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Waitress.h"

Waitress::Waitress() {
	serveANewCustomer();
}

bool Waitress::hasTakenFoodFromCounter() {
	return _foodTakenFromCounter;
}

void Waitress::move() {
	if (_movingUp || _movingDown) {
		_sprite.move(0, _speed);
	}
	
	if (_movingLeft || _movingRight) {
		_sprite.move(_speed, 0);
	}
}

void Waitress::moveUp() {
	if (Utility::keyboardIsUsed) {
		_movingDown = false;
		_movingUp = true;
		_movingRight = false;
		_movingLeft = false;
	
		_speed = -1;
	} else {
		_sprite.move(0, -_speed);
	}
}

void Waitress::moveDown() {
	if (Utility::keyboardIsUsed) {
		_movingDown = true;
		_movingUp = false;
		_movingRight = false;
		_movingLeft = false;
		
		_speed = 1;
	} else {
		_sprite.move(0, _speed);
	}
}

void Waitress::moveLeft() {
	if (Utility::keyboardIsUsed) {
		_movingLeft = true;
		_movingUp = false;
		_movingDown = false;
		_movingRight = false;
		
		_speed = -1;
	} else {
		_sprite.move(-_speed, 0);
	}
}

void Waitress::moveRight() {
	if (Utility::keyboardIsUsed) {
		_movingRight = true;
		_movingUp = false;
		_movingDown = false;
		_movingLeft = false;
		
		_speed = 1;
	} else {
		_sprite.move(_speed, 0);
	}
}

void Waitress::stop() {
	_speed = 0;
}

bool Waitress::handleCollisionWith(SpriteClass *customer) {
	if (getXPos() + getWidth() >= customer->getXPos() && getXPos() <= customer->getXPos() + customer->getWidth()) {
		if (getYPos() + getHeight() >= customer->getYPos() && getYPos() <= customer->getYPos() + customer->getHeight()) {
			return true;
		}
	}
	
	return false;
}

void Waitress::pickOrderFromMenu() {
	_pickedOrderFromMenu = true;
}

bool Waitress::hasPickedOrderFromMenu() {
	return _pickedOrderFromMenu;
}

void Waitress::setCorrectOrderFlag() {
	_correctOrderFromMenu = true;
}

bool Waitress::gotCorrectOrder() {
	return _correctOrderFromMenu;
}

bool Waitress::isMovingUp() {
	return _movingUp;
}

bool Waitress::isMovingDown() {
	return _movingDown;
}

bool Waitress::isMovingRight() {
	return _movingRight;
}

bool Waitress::isMovingLeft() {
	return _movingLeft;
}

void Waitress::takeFoodFromCounter() {
	_foodTakenFromCounter = true;
}

// another way of declaring a function that resets properties
// did not want to make a virtual reset() function
// it will just mess things up
void Waitress::serveANewCustomer() {
	_foodTakenFromCounter = false;
	_pickedOrderFromMenu = false;
	_correctOrderFromMenu = false;
	
	_movingUp = false;
	_movingDown = false;
	_movingLeft = false;
	_movingRight = false;
}