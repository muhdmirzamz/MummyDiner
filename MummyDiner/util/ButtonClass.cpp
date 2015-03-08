//
//  ButtonClass.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 8/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "ButtonClass.h"

// place text more to the left side of the center to make it look centralised
// name just helps with readability and abstraction 
#define CENTER_OF_BUTTON_X_AXIS (_leftOfButton + (_widthOfButton / 4))
#define CENTER_OF_BUTTON_Y_AXIS (_topOfButton + (_heightOfButton / 4))
#define FONT_SIZE 15

ButtonClass::ButtonClass() {
	
}

void ButtonClass::set(float x, float y, float w, float h, Uint8 buttonRed, Uint8 buttonGreen, Uint8 buttonBlue, string text, Uint8 textRed, Uint8 textGreen, Uint8 textBlue) {
	_button.setPosition(x, y);
	_button.setSize(Vector2f(w, h));
	
	_leftOfButton = x;
	_widthOfButton = w;
	_topOfButton = y;
	_heightOfButton = h;
	
	_button.setFillColor(Color(buttonRed, buttonGreen, buttonBlue));
	
	_text.set("fonts/Quicksand-Regular.ttf", FONT_SIZE, text, CENTER_OF_BUTTON_X_AXIS, CENTER_OF_BUTTON_Y_AXIS, textRed, textGreen, textBlue);
}

float ButtonClass::getLeftSide() {
	return _leftOfButton;
}

float ButtonClass::getWidth() {
	return _leftOfButton + _widthOfButton;
}

float ButtonClass::getTop() {
	return _topOfButton;
}

float ButtonClass::getHeight() {
	return _topOfButton + _heightOfButton;
}

// dont forget to render text too
void ButtonClass::render(RenderWindow &window) {
	window.draw(_button);
	_text.render(window);
}