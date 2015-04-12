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

void TextClass::setTextUsingName(string name, string text) {
	fstream _file;

	string line;

	_file.open("text_files/text_class.txt", ios::in);
	
	while (getline(_file, line)) {
		_file >> line;

		if (line == name) {
			_file >> _tempFontFile >> _tempR >> _tempG >> _tempB >> _tempCharacterSize >> _tempX >> _tempY;
			/*
			 printf("%s\n%d\n%d\n%d\n%s\n%d\n%f\n%f\n", _tempFontFile.c_str(), _tempR, _tempG, _tempB, _tempText.c_str(), _tempCharacterSize, _tempX, _tempY);
			 */
			 break;
		}
	}
	
	_file.close();
	
	_font.loadFromFile(_tempFontFile);
	
	_text.setFont(_font);
	_text.setString(text);
	_text.setCharacterSize(_tempCharacterSize);
	_text.setColor(Color(_tempR, _tempG, _tempB));
	_text.setPosition(_tempX, _tempY);
}

// needed to support ToggleClass
void TextClass::setTextClass(const char *fontFile, string text, float x, float y) {
	_font.loadFromFile(fontFile);
	
	_text.setFont(_font);
	
	// make these default, you can change them using the extra functions
	_text.setCharacterSize(12);
	_text.setColor(Color(0, 0, 0));
	
	_text.setString(text);
	
	_text.setPosition(x, y);
}

void TextClass::render(RenderWindow &window) {
	window.draw(_text);
}

