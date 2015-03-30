//
//  BackgroundClass.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 11/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "BackgroundClass.h"

BackgroundClass::BackgroundClass() {

}

void BackgroundClass::set(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b) {
	_background.setPosition(x, y);
	_background.setSize(Vector2f(w, h));
	
	_background.setFillColor(Color(r, g, b));
}

void BackgroundClass::setImageBackground(const char *file, int x, int y, int w, int h) {
	// load file into image
	_image.loadFromFile(file);
	_image.createMaskFromColor(Color(255, 255, 255));
	
	// load image into texture
	_texture.loadFromImage(_image);
	
	_background.setTexture(&_texture);
	
	_background.setPosition(x, y);
	_background.setSize(Vector2f(w, h));
}

void BackgroundClass::render(RenderWindow &window) {
	window.draw(_background);
}

float BackgroundClass::getX() {
	return _background.getPosition().x;
}

float BackgroundClass::getY() {
	return _background.getPosition().x;
}

float BackgroundClass::getWidth() {
	return _background.getSize().x;
}

float BackgroundClass::getHeight() {
	return _background.getSize().y;
}