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

void SpriteClass::set(const char *file, int cropX, int cropY, int cropW, int cropH, float x, float y) {
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
	_sprite.scale(0.1, 0.1);
	
	// apply rectangle to texture
	_sprite.setTextureRect(_cropRect);
	
	_sprite.setPosition(x, y);
}

void SpriteClass::positionSprite(float x, float y) {
	_sprite.setPosition(x, y);
}

void SpriteClass::moveUp() {
	
}

void SpriteClass::moveDown() {
	
}

void SpriteClass::moveLeft() {
	
}

void SpriteClass::moveRight() {
	
}

void SpriteClass::handleWindowCollision() {
	
}

void SpriteClass::takeOrder() { // needs integration with order list system

}

void SpriteClass::cook() {
	
}

void SpriteClass::startCooking() {
	
}

void SpriteClass::spawn() {
	
}

void SpriteClass::startWaiting() {
	
}

void SpriteClass::order() {
	
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