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
	
		void set(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b);
		void setImageBackground(const char *file, int x, int y, int w, int h);
		
		void render(RenderWindow &window);
	
		float getX();
		float getY();
		float getWidth();
		float getHeight();
	
	private:
		RectangleShape _background;
	
		Image _image;
		Texture _texture;
};

#endif /* defined(__MummyDiner__BackgroundClass__) */
