//
//  ImageClass.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 3/4/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "ImageClass.h"

ImageClass::ImageClass() {
	
}

void ImageClass::setImage(const char *file) {
	_image.loadFromFile(file);
	_texture.loadFromImage(_image);
	_sprite.setTexture(_texture);
	_sprite.setScale(0.1, 0.1);
}

void ImageClass::setScale(float x, float y) {
	_sprite.setScale(x, y);
}

void ImageClass::setPosition(float x, float y) {
	_sprite.setPosition(x, y);
}

void ImageClass::renderImage(RenderWindow &window) {
	window.draw(_sprite);
}