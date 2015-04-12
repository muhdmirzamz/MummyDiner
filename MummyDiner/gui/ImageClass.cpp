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

void ImageClass::setImageUsingName(string name) {
	fstream _file;
	
	string line;
	
	_file.open("text_files/image_class.txt", ios::in);
	
	while (getline(_file, line)) {
		_file >> line;
	
		if (line == name) {
			_file >> _tempImageFile >> _tempX >> _tempY >> _tempScaleX >> _tempScaleY;
			break;
		}
	}
	
	_file.close();
	
	_image.loadFromFile(_tempImageFile.c_str());
	_texture.loadFromImage(_image);
	_sprite.setTexture(_texture);
	
	_sprite.setScale(_tempScaleX, _tempScaleY);
	_sprite.setPosition(_tempX, _tempY);
}

void ImageClass::setImage(const char *file, float x, float y) {
	_image.loadFromFile(file);
	_texture.loadFromImage(_image);
	_sprite.setTexture(_texture);
	
	_sprite.setScale(0.1, 0.1);
	_sprite.setPosition(x, y);
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