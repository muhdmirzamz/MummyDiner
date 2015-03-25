//
//  Waitress.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Waitress.h"

// readability for this class
#define SPRITE_X_POS _sprite.getPosition().x
#define SPRITE_Y_POS _sprite.getPosition().y
#define SPRITE_WIDTH (_sprite.getTextureRect().width * _sprite.getScale().x)
#define SPRITE_HEIGHT (_sprite.getTextureRect().height * _sprite.getScale().y)

Waitress::Waitress() {
	serveANewCustomer();
}

// function names mainly for readability in level class
float Waitress::getXPos() {
	return SPRITE_X_POS;
}

float Waitress::getYPos() {
	return SPRITE_Y_POS;
}

float Waitress::getWidth() {
	// have to multiply the width with the scale
	// sprite will still take the original width when scaled down
	return SPRITE_WIDTH;
}

float Waitress::getHeight() {
	return SPRITE_HEIGHT;
}

bool Waitress::hasTakenFoodFromCounter() {
	return _foodTakenFromCounter;
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

void Waitress::handleCollisionWithWindow() {
	if (SPRITE_X_POS + SPRITE_WIDTH >= SCREEN_W) {
		// make sure sprite stays in frame
		positionSprite(SCREEN_W - SPRITE_WIDTH, SPRITE_Y_POS);
	}
	
	if (SPRITE_X_POS <= 0) {
		positionSprite(0, SPRITE_Y_POS);
	}
	
	if (SPRITE_Y_POS <= 0) {
		positionSprite(SPRITE_X_POS, 0);
	}
	
	if (SPRITE_Y_POS + SPRITE_HEIGHT >= SCREEN_H) {
		positionSprite(SPRITE_X_POS, SCREEN_H - SPRITE_HEIGHT);
	}
}

void Waitress::handleCollisionWith(SpriteClass &object) {
	// other collision sides to be implemented later
	if (SPRITE_Y_POS + SPRITE_HEIGHT >= object.getYPos()) {
		positionSprite(SPRITE_X_POS, object.getYPos() - SPRITE_HEIGHT);
	}
}

void Waitress::takeFoodFromCounter() {
	_foodTakenFromCounter = true;
}

// another way of declaring a function that resets properties
// did not want to make a virtual reset() function
// it will just mess things up
void Waitress::serveANewCustomer() {
	_foodTakenFromCounter = false;
}