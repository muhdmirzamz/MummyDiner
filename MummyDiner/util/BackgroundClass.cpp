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

void BackgroundClass::render(RenderWindow &window) {
	window.draw(_background);
}