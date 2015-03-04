//
//  BackgroundClass.h
//  MummyDiner
//
//  Created by Muhd Mirza on 11/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__BackgroundClass__
#define __MummyDiner__BackgroundClass__

#include <stdio.h>

#include <SFML/Graphics.hpp>

using namespace sf;

class BackgroundClass {
	public:
		BackgroundClass();
	
		void setBackground(float x, float y, float w, float h);
		void setColor(Uint8 r, Uint8 g, Uint8 b);
		void render(RenderWindow &window);
	
	private:
		RectangleShape _rectangleBackground;
	
		Color _color;
};

#endif /* defined(__MummyDiner__BackgroundClass__) */
