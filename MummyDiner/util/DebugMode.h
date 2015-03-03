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

#include <util/BackgroundClass.h>

using namespace sf;
using namespace std;

class DebugMode {
	public:
		DebugMode();
	
		void setText(string text, int size);
		void setTextPosition(float textX, float valueX, float y);
		void setValue(int value, int size);
		Text* getText();
		Text* getValue();
	
		void setBackgroundPosition(int x, int y, int w, int h);
		void drawBackground(Uint8 r, Uint8 g, Uint8 b);
		RectangleShape* getBackground();
	
	private:
		Font _fontObj;
		Font *_font;
	
		/*
			This file contains several components
			one for debug name
			one for debug value
			one for debug background position
			usage of this class can be used with only one object
			
			took a little help from background class
		*/
		Text _variableNameObj;
		Text *_variableName;
	
		Text _variableValueObj;
		Text *_variableValue;
	
		BackgroundClass _backgroundObj;
		BackgroundClass *_background;
	
		Color _color;
};

#endif /* defined(__MummyDiner__DebugMode__) */
