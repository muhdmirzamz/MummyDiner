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

enum ButtonType {
	RECTANGLE,
	CIRCLE
};

class ButtonClass {
	public:
		ButtonClass();
	
		void chooseButton(ButtonType button);
		void setButton(float x, float y, float w, float h);
		void setButton(float x, float y, float radius);
		void setColor(Uint8 r, Uint8 g, Uint8 b);
	
		float getRadius();
		float getLeftOfButton();
		float getRightOfButton();
		float getTopOfButton();
		float getBottomOfButton();
	
		RectangleShape* getButton();
		CircleShape* getCircleButton();
	
	private:
		ButtonType _buttonType;
	
		RectangleShape _rectangleButtonObj;
		RectangleShape *_rectangleButton;
	
		CircleShape _circleButtonObj;
		CircleShape *_circleButton;
	
		Color _color;
	
		float _radius;
	
		float _leftOfButton;
		float _rightOfButton;
		float _topOfButton;
		float _bottomOfButton;
};

#endif /* defined(__MummyDiner__ButtonClass__) */
