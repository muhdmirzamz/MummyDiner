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

#include "../util/Utility.h"
#include "TextClass.h" // make use of your own text wrapper class

using namespace sf;

class ButtonClass {
	public:
		ButtonClass();
	
		void set(float x, float y, float w, float h, Uint8 buttonRed, Uint8 buttonGreen, Uint8 buttonBlue, string text, Uint8 textRed, Uint8 textGreen, Uint8 textBlue);
		void setColour(Uint8 buttonRed, Uint8 buttonGreen, Uint8 buttonBlue);
	
		float getLeftSide();
		float getWidth();
		float getTop();
		float getHeight();
	
		void render(RenderWindow &window);
	
	private:
		TextClass _text;
	
		RectangleShape _button;
	
		float _leftOfButton;
		float _widthOfButton;
		float _topOfButton;
		float _heightOfButton;
};

#endif /* defined(__MummyDiner__ButtonClass__) */
