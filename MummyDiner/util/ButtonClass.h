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

using namespace sf;

class ButtonClass {
	public:
		ButtonClass();
	
		void setButton(float x, float y, float w, float h);
		void setColor(Uint8 r, Uint8 g, Uint8 b);
	
		float getLeftOfButton();
		float getRightOfButton();
		float getTopOfButton();
		float getBottomOfButton();
	
		void render(RenderWindow &window);
	
	private:
		RectangleShape _button;
	
		Color _color;
	
		float _leftOfButton;
		float _rightOfButton;
		float _topOfButton;
		float _bottomOfButton;
};

#endif /* defined(__MummyDiner__ButtonClass__) */
