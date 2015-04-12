//
//  ButtonClass.h
//  MummyDiner
//
//  Created by Muhd Mirza on 8/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__ButtonClass__
#define __MummyDiner__ButtonClass__

#include <stdio.h>

#include <SFML/Graphics.hpp>

#include "TextClass.h" // make use of your own text wrapper class

class ButtonClass {
	public:
		ButtonClass();
	
		void setButtonUsingName(string name, string text);
	
		void setButton(string text, float x, float y, float w, float h);
		void setColour(Uint8 buttonRed, Uint8 buttonGreen, Uint8 buttonBlue);
	
		bool isClicked(int mouseXClick, int mouseYClick);
	
		void render(RenderWindow &window);
	
	private:
		TextClass _textClass;
		Font _font;
		Text _text;
	
		RectangleShape _button;
	
		string _tempFontFile;
		int _tempR;
		int _tempG;
		int _tempB;
		int _tempTextR;
		int _tempTextG;
		int _tempTextB;
		int _tempCharacterSize;
		float _tempX;
		float _tempY;
		float _tempW;
		float _tempH;
	
		bool _usingTextClass;
};

#endif /* defined(__MummyDiner__ButtonClass__) */
