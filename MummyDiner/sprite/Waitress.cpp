//
//  Waitress.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Waitress.h"

Waitress::Waitress() {
	_rightOfWindow = 640;
	_bottomOfWindow = 480;
	
	_leftOfWaitress = getXPos();
	_rightOfWaitress = getXPos() + getWidth();
	_topOfWaitress = getYPos();
	_bottomOfWaitress = getYPos() + getHeight();
}

void Waitress::moveUp() {
	_sprite.move(0, -_speed);
}

void Waitress::moveDown() {
	_sprite.move(0, _speed);
}

void Waitress::moveLeft() {
	_sprite.move(-_speed, 0);
}

void Waitress::moveRight() {
	_sprite.move(_speed, 0);
}

void Waitress::handleWindowCollision() {
	if (_rightOfWaitress >= _rightOfWindow) {
		// make sure sprite stays in frame
		positionSprite(_rightOfWindow - getWidth(), getYPos());
	}
	
	if (_leftOfWaitress <= 0) {
		positionSprite(0, getYPos());
	}
	
	if (_topOfWaitress <= 0) {
		positionSprite(getXPos(), 0);
	}
	
	if (_bottomOfWaitress >= _bottomOfWindow) {
		positionSprite(getXPos(), _bottomOfWindow - getHeight());
	}
}

void Waitress::takeOrder() {
	
}