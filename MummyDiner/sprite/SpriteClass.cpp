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

void SpriteClass::move() {
	
}

void SpriteClass::stop() {
	
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

bool SpriteClass::handleCollisionWith(SpriteClass *customer) {
	return false;
}

void SpriteClass::pickOrderFromMenu() {
	
}

bool SpriteClass::hasPickedOrderFromMenu() {
	return false;
}

void SpriteClass::setCorrectOrderFlag() {
	
}

bool SpriteClass::gotCorrectOrder() {
	return false;
}

bool SpriteClass::isMovingUp() {
	return false;
}

bool SpriteClass::isMovingDown() {
	return false;
}

bool SpriteClass::isMovingRight() {
	return false;
}

bool SpriteClass::isMovingLeft() {
	return false;
}

void SpriteClass::takeFoodFromCounter() { // needs integration with order list system

}

void SpriteClass::serveANewCustomer() {
	
}

void SpriteClass::getReadyToCook() {
	
}

void SpriteClass::cook() {
	
}

void SpriteClass::renderSmoke(RenderWindow &window) {
	
}

bool SpriteClass::isCooking() {
	return false;
}

bool SpriteClass::isDoneCooking() {
	return false;
}

void SpriteClass::spawn() {
	
}

void SpriteClass::renderOrderPopup(RenderWindow &window) {
	
}

void SpriteClass::renderFoodOrderPopup(RenderWindow &window) {
	
}

void SpriteClass::startThread() {
	
}

void SpriteClass::renderFood(RenderWindow &window) {
	
}

void SpriteClass::renderThanksPopup(RenderWindow &window) {
	
}

void SpriteClass::setAsSuccessful() {
	
}

void SpriteClass::setAsFailure() {
	
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

int SpriteClass::getSpawnPosition() {
	return 0;
}

int SpriteClass::getOrderedFoodItem() {
	return false;
}

int SpriteClass::getSuccessful() {
	return 0;
}

int SpriteClass::getFailure() {
	return 0;
}

int SpriteClass::getTimeLeft() {
	return false;
}

int SpriteClass::getTimeLimit() {
	return false;
}

void SpriteClass::addTime() {
	
}

void SpriteClass::renderWrongOrderPopup(RenderWindow &window) {
	
}

void SpriteClass::getServed() {
	
}

void SpriteClass::order() {
	
}

void SpriteClass::resetForNewLevel() {
	
}

float SpriteClass::getXPos() {
	return _sprite.getPosition().x;
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