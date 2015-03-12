//
//  TextClass.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 8/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "TextClass.h"

TextClass::TextClass() {

}

void TextClass::set(const char *file, int fontSize, string text, float x, float y, Uint8 r, Uint8 g, Uint8 b) {
	_font.loadFromFile(file);
	_text.setFont(_font);
	_text.setCharacterSize(fontSize);
	_text.setString(text);
	_text.setPosition(x, y);
	_text.setColor(Color(r, g, b));
}

void TextClass::render(RenderWindow &window) {
	window.draw(_text);
}

