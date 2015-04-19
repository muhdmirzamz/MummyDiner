//
//  Sprite.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 11/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "SpriteClass.h"

#define SPRITE_X_POS _sprite.getPosition().x
#define SPRITE_Y_POS _sprite.getPosition().y
#define SPRITE_WIDTH (_sprite.getTextureRect().width * _sprite.getScale().x)
#define SPRITE_HEIGHT (_sprite.getTextureRect().height * _sprite.getScale().y)

SpriteClass::SpriteClass() {

}

void SpriteClass::setSpriteUsingName(string name, float scaleX, float scaleY) {
	fstream _file;
	
	string line;
	
	_file.open("text_files/sprite_class.txt", ios::in);
	
	while (getline(_file, line)) {
		_file >> line;
	
		if (line == name) {
			_file >> _tempImageFile >> _tempCropX >> _tempCropY >> _tempCropW >> _tempCropH >> _tempX >> _tempY;
			break;
		}
	}
	
	_file.close();
	
	_speed = 1;
	
	// load file into image
	_image.loadFromFile(_tempImageFile);
	_image.createMaskFromColor(Color(255, 255, 255));
	
	// load image into texture
	_texture.loadFromImage(_image);
	
	// load texture to sprite
	_sprite.setTexture(_texture);
	
	// crop and scale sprite using rectangle
	_cropRect.left = _tempCropX;
	_cropRect.top = _tempCropY;
	_cropRect.width = _tempCropW;
	_cropRect.height = _tempCropH;
	_sprite.scale(scaleX, scaleY); // use default perimeters for sprites which does not use 0.1 as scale(in header)
	
	// apply rectangle to texture
	_sprite.setTextureRect(_cropRect);
	
	_sprite.setPosition(_tempX, _tempY);
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

void SpriteClass::handleCollisionWithWindow(SpriteClass &counter) {
	if (SPRITE_X_POS + SPRITE_WIDTH >= SCREEN_W) {
		_sprite.setPosition(SCREEN_W - SPRITE_WIDTH, SPRITE_Y_POS);
	}
	
	if (SPRITE_X_POS <= 0) {
		_sprite.setPosition(0, SPRITE_Y_POS);
	}
	
	if (SPRITE_Y_POS <= 0) {
		_sprite.setPosition(SPRITE_X_POS, 0);
	}
	
	// window height limit is the counter
	if (SPRITE_Y_POS + SPRITE_HEIGHT >= counter.getYPos()) {
		_sprite.setPosition(SPRITE_X_POS, counter.getYPos() - SPRITE_HEIGHT);
	}
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

float SpriteClass::getXEndPos() {
	return _sprite.getPosition().x + (_sprite.getTextureRect().width * _sprite.getScale().x);
}

float SpriteClass::getYEndPos() {
	return _sprite.getPosition().y + (_sprite.getTextureRect().height * _sprite.getScale().y);
}

void SpriteClass::render(RenderWindow &window) {
	window.draw(_sprite);
}