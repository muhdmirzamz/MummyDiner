//
//  Sprite.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 11/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "SpriteClass.h"

SpriteClass::SpriteClass() {

}

// coordinates in float
// special case scenario since it is declared at the library level
void SpriteClass::set(const char *file, int cropX, int cropY, int cropW, int cropH, float x, float y, float scaleX, float scaleY) {
	_speed = 1;

	// load file into image
	_image.loadFromFile(file);
	_image.createMaskFromColor(Color(255, 255, 255));
	
	// load image into texture
	_texture.loadFromImage(_image);
	
	// load texture to sprite
	_sprite.setTexture(_texture);
	
	// crop and scale sprite using rectangle
	_cropRect.left = cropX;
	_cropRect.top = cropY;
	_cropRect.width = cropW;
	_cropRect.height = cropH;
	_sprite.scale(scaleX, scaleY); // use default perimeters for sprites which does not use 0.1 as scale(in header)
	
	// apply rectangle to texture
	_sprite.setTextureRect(_cropRect);
	
	_sprite.setPosition(x, y);
}

void SpriteClass::positionSprite(float x, float y) {
	_sprite.setPosition(x, y);
}

bool SpriteClass::hasTakenFoodFromCounter() {
	return false;
}

void SpriteClass::moveUp() {
	
}

void SpriteClass::moveDown() {
	
}

void SpriteClass::moveLeft() {
	
}

void SpriteClass::moveRight() {
	
}

void SpriteClass::handleCollisionWithWindow() {
	
}

void SpriteClass::handleCollisionWith(SpriteClass &object) {
	
}

void SpriteClass::takeFoodFromCounter() { // needs integration with order list system

}

void SpriteClass::serveANewCustomer() {
	
}

void SpriteClass::cook() {
	
}

void SpriteClass::startCooking() {
	
}

void SpriteClass::spawn() {
	
}

void SpriteClass::startThread() {
<<<<<<< HEAD
=======
	
}

void SpriteClass::stopThread() {
	
}

bool SpriteClass::timeIsUp() {
	return false;
}

bool SpriteClass::orderIsTaken() {
	return false;
}

bool SpriteClass::foodIsServed() {
	return false;
}

bool SpriteClass::timeIsAdded() {
	return false;
}

int SpriteClass::getTimeLeft() {
	return false;
}

int SpriteClass::getTimeLimit() {
	return false;
}

void SpriteClass::addTime() {
	
}

void SpriteClass::getServed() {
>>>>>>> mummydiner/v0.6.0-alpha
	
}

void SpriteClass::stopThread() {
	
}

bool SpriteClass::hasWaited() {
	return false;
}

void SpriteClass::order() {
	
}

float SpriteClass::getXPos() {
	return _sprite.getPosition().y;
}

float SpriteClass::getYPos() {
	return _sprite.getPosition().y;
}

float SpriteClass::getWidth() {
	// have to multiply the width with the scale
	// sprite will still take the original width when scaled down
	return _sprite.getTextureRect().width * _sprite.getScale().x;
}

float SpriteClass::getHeight() {
	return _sprite.getTextureRect().height * _sprite.getScale().y;
}

void SpriteClass::render(RenderWindow &window) {
	window.draw(_sprite);
}