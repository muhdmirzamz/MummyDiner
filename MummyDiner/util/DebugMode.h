//
//  DebugMode.h
//  MummyDiner
//
//  Created by Muhd Mirza on 13/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__DebugMode__
#define __MummyDiner__DebugMode__

#include <stdio.h>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class DebugMode {
	public:
		DebugMode();
	
		void set();
	
		void setFPSValue(float value);
		void setMousePosition(int x, int y);

		void show(RenderWindow &window);
	
	private:
		void setTextAndPosition(Text &variable, string label, float variableY, Text &variableValue); // might be a private function
		void setText(Text &variable);
	
		Font _font;
		int _fontSize;
	
		Text _fps;
		Text _fpsValue;
	
		Text _mouseXPos;
		Text _mouseXPosValue;
		Text _mouseYPos;
		Text _mouseYPosValue;
	
		// player position
		// mouse position
	
		int _valuePositionOffset;
};

#endif /* defined(__MummyDiner__DebugMode__) */
