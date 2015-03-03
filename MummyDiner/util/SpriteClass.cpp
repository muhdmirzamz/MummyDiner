//
//  Sprite.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 11/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "SpriteClass.h"

static int SPRITE_SPEED = 1;

SpriteClass::SpriteClass() {
	_spriteImg = &_spriteImgObj;
	_spriteTexture = &_spriteTextureObj;
	_sprite = &_spriteObj;
}

void SpriteClass::loadSprite(const char *file) {
	_spriteImg->loadFromFile(file);
	_spriteImg->createMaskFromColor(_color.White);
	_spriteTexture->loadFromImage(*_spriteImg);
	_sprite->setTexture(*_spriteTexture);
}

void SpriteClass::cropSprite(int x, int y, int w, int h, float xScale, float yScale) {
	_spriteRect.left = x;
	_spriteRect.top = y;
	_spriteRect.width = w;
	_spriteRect.height = h;

	_sprite->scale(xScale, yScale);
	
	_sprite->setTextureRect(_spriteRect);
}

void SpriteClass::positionSprite(float x, float y) {
	_sprite->setPosition(x, y);
	
	_spriteXPos = x;
	_spriteYPos = y;
}

void SpriteClass::moveSpriteUp() {
	_sprite->move(0, -SPRITE_SPEED);
}

void SpriteClass::moveSpriteDown() {
	_sprite->move(0, SPRITE_SPEED);
}

void SpriteClass::moveSpriteLeft() {
	_sprite->move(-SPRITE_SPEED, 0);
}

void SpriteClass::moveSpriteRight() {
	_sprite->move(SPRITE_SPEED, 0);
}

float SpriteClass::getSpriteXPos() {
	return _sprite->getPosition().x;
}

float SpriteClass::getSpriteYPos() {
	return _sprite->getPosition().y;
}

float SpriteClass::getSpriteWidth() {
	// have to multiply the width with the scale
	// sprite will still take the original width when scaled down
	return _sprite->getTextureRect().width * _sprite->getScale().x;
}

float SpriteClass::getSpriteHeight() {
	return _sprite->getTextureRect().height * _sprite->getScale().y;
}

Sprite* SpriteClass::getSprite() {
	return _sprite;
}