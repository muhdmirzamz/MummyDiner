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

using namespace sf;
using namespace std;

class TextClass {
	public:
		TextClass();
	
		void setText(const char *file, int charaterSize, string text, float x, float y);
		void setColor(Uint8 r, Uint8 g, Uint8 b);
		Text* getText();
	
	private:
		Font _fontObj;
		Font *_font;
	
		Text _textObj;
		Text *_text;
	
		Color _color;
};

#endif /* defined(__MummyDiner__TextClass__) */
