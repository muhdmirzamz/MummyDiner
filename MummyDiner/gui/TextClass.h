//
//  TextClass.h
//  MummyDiner
//
//  Created by Muhd Mirza on 8/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__TextClass__
#define __MummyDiner__TextClass__

#include <stdio.h>

#include <SFML/Graphics.hpp>

#include "../util/Utility.h"

class TextClass {
	public:
		TextClass();
	
		void setTextUsingName(string name, string text);
	
		void setTextClass(const char *fontFile, string text, float x, float y);
		
		void render(RenderWindow &window);
	
	private:
		Font _font;
		Text _text;
	
		string _tempFontFile;
		int _tempR;
		int _tempG;
		int _tempB;
		int _tempCharacterSize;
		float _tempX;
		float _tempY;
};

#endif /* defined(__MummyDiner__TextClass__) */
