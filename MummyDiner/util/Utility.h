//
//  DebugMode.h
//  MummyDiner
//	contains most macros and constants
//
//  Created by Muhd Mirza on 13/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__DebugMode__
#define __MummyDiner__DebugMode__

#include <stdio.h>

#include <SFML/Graphics.hpp>

#define DEBUG_MODE 1

#define QUICKSAND_REGULAR_FONT "fonts/Quicksand-Regular.ttf"
#define LATO_LIGHT_FONT "fonts/Lato-Light.ttf"

const int SCREEN_W = 640;
const int SCREEN_H = 480;

using namespace sf;
using namespace std;

class Utility {
	public:
		Utility();
	
		void set();
	
		void setFPSValue(int value);
		void setMousePosition(int x, int y);
		void setSpritePosition(int x, int y);
		void setTimeLimit(int time);
		void setTime(int time);

		void show(RenderWindow &window);
	
	private:
		void setTextAndPosition(Text &variable, string label, float variableY, Text &variableValue);
		void setText(Text &variable);
	
		Font _font;
		int _fontSize;
	
		Text _fps;
		Text _fpsValue;
	
		Text _mouseXPos;
		Text _mouseXPosValue;
		Text _mouseYPos;
		Text _mouseYPosValue;
	
		Text _spriteXPos;
		Text _spriteXPosValue;
		Text _spriteYPos;
		Text _spriteYPosValue;
	
		Text _timeLimit;
		Text _timeLimitValue;
	
		Text _time;
		Text _timeValue;
	
		int _valuePositionOffset;
};

#endif /* defined(__MummyDiner__DebugMode__) */
