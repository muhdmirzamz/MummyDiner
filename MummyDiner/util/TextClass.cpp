//
//  TextClass.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 8/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "TextClass.h"

TextClass::TextClass() {
	_font = &_fontObj;
	_text = &_textObj;
}

void TextClass::setText(const char *file, int charaterSize, string text, float x, float y) {
	_font->loadFromFile(file);
	_text->setFont(*_font);
	_text->setCharacterSize(charaterSize);
	_text->setString(text);
	_text->setPosition(x, y);
}

void TextClass::setColor(Uint8 r, Uint8 g, Uint8 b) {
	_color.r = r;
	_color.g = g;
	_color.b = b;

	_text->setColor(_color);
}

Text* TextClass::getText() {
	return _text;
}

