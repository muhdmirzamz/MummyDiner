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

void BackgroundClass::setBackgroundUsingName(string name) {
	fstream _file;
	
	string line;
	
	_file.open("text_files/background_class.txt", ios::in);
	
	while (getline(_file, line)) {
		_file >> line;
		
		if (line == name) {
			_file >> _tempImageFile >> _tempX >> _tempY >> _tempW >> _tempH >> _tempR >> _tempG >> _tempB;
			break;
		}
	}
	
	_file.close();
	
	if (_tempImageFile != "none") { // if image background exists
		_image.loadFromFile(_tempImageFile);
		_texture.loadFromImage(_image);
		_background.setTexture(&_texture);
	} else {
		_background.setFillColor(Color(_tempR, _tempG, _tempB));
	}
	
	_background.setPosition(_tempX, _tempY);
	_background.setSize(Vector2f(_tempW, _tempH));
}

float BackgroundClass::getX() {
	return _background.getPosition().x;
}

float BackgroundClass::getY() {
	return _background.getPosition().y;
}

float BackgroundClass::getXEndPoint() {
	//return _background.getSize().x;
	return _background.getPosition().x + _background.getSize().x;
}

float BackgroundClass::getYEndPoint() {
	//return _background.getSize().y;
	return _background.getPosition().y + _background.getSize().y;
}

void BackgroundClass::render(RenderWindow &window) {
	window.draw(_background);
}