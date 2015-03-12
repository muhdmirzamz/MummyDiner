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
	
		void set(const char *file, int fontSize, string text, float x, float y, Uint8 r, Uint8 g, Uint8 b);
		void render(RenderWindow &window);
	
	private:
		Font _font;
		Text _text;
};

#endif /* defined(__MummyDiner__TextClass__) */
