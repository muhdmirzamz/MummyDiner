//
//  ImageClass.h
//  MummyDiner
//
//  Created by Muhd Mirza on 3/4/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__ImageClass__
#define __MummyDiner__ImageClass__

#include <stdio.h>

#include <SFML/Graphics.hpp>

using namespace sf;

class ImageClass {
	public:
		ImageClass();
	
		void setImage(const char *file);
		void setScale(float x, float y);
		void setPosition(float x, float y);
		void renderImage(RenderWindow &window);
	
	private:
		Image _image;
		Texture _texture;
		Sprite _sprite;
};

#endif /* defined(__MummyDiner__ImageClass__) */
