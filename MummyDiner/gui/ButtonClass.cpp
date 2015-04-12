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
#define CENTER_OF_BUTTON_X_AXIS2 (_leftOfButton + (_widthOfButton / 4))
#define CENTER_OF_BUTTON_Y_AXIS2 (_topOfButton + (_heightOfButton / 4))

#define CENTER_OF_BUTTON_X_AXIS (_button.getPosition().x + (_button.getSize().x / 4))
#define CENTER_OF_BUTTON_Y_AXIS (_button.getPosition().y + (_button.getSize().y / 4))
#define FONT_SIZE 15

ButtonClass::ButtonClass() {
	
}

void ButtonClass::setButtonUsingName(string name, string text) {
	_usingTextClass = false;

	fstream _file;
	
	string line;
	
	_file.open("text_files/button_class.txt");
	
	while (getline(_file, line)) {
		_file >> line;
	
		if (line == name) {
			_file >> _tempFontFile >> _tempR >> _tempG >> _tempB >> _tempTextR >> _tempTextG >> _tempTextB >>
			_tempCharacterSize >> _tempX >> _tempY >> _tempW >> _tempH;
			break;
		}
	}
	
	_file.close();
	
	_button.setPosition(_tempX, _tempY);
	_button.setSize(Vector2f(_tempW, _tempH));
	_button.setFillColor(Color(_tempR, _tempG, _tempB));
	
	_font.loadFromFile(_tempFontFile);
	
	_text.setFont(_font);
	_text.setString(text);
	_text.setCharacterSize(_tempCharacterSize);
	_text.setColor(Color(_tempTextR, _tempTextG, _tempTextB));
	_text.setPosition(CENTER_OF_BUTTON_X_AXIS, CENTER_OF_BUTTON_Y_AXIS);
}

void ButtonClass::setButton(string text, float x, float y, float w, float h) {
	_usingTextClass = true;

	_button.setPosition(x, y);
	_button.setSize(Vector2f(w, h));
	
	_textClass.setTextClass(QUICKSAND_REGULAR_FONT, text, CENTER_OF_BUTTON_X_AXIS, CENTER_OF_BUTTON_Y_AXIS);
}

void ButtonClass::setColour(Uint8 buttonRed, Uint8 buttonGreen, Uint8 buttonBlue) {
	_button.setFillColor(Color(buttonRed, buttonGreen, buttonBlue));
}

bool ButtonClass::isClicked(int mouseXClick, int mouseYClick) {
	if (mouseXClick >= _button.getPosition().x && mouseXClick <= _button.getPosition().x + _button.getSize().x) {
		if (mouseYClick >= _button.getPosition().y && mouseYClick <= _button.getPosition().y + _button.getSize().y) {
			return true;
		}
	}
	
	return false;
}

// dont forget to render text too
void ButtonClass::render(RenderWindow &window) {
	window.draw(_button);
	
	if (_usingTextClass) {
		_textClass.render(window);
	} else {
		window.draw(_text);
	}
}