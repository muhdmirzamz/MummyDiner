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

#include "../util/Utility.h"

class ImageClass {
	public:
		ImageClass();
	
		void setImageUsingName(string name);
		void setImage(const char *file, float x, float y);
		void setScale(float x, float y);
		void setPosition(float x, float y);
		
		void renderImage(RenderWindow &window);
	
	private:
		Image _image;
		Texture _texture;
		Sprite _sprite;
	
		string _tempImageFile;
		float _tempX;
		float _tempY;
		float _tempScaleX;
		float _tempScaleY;
};

#endif /* defined(__MummyDiner__ImageClass__) */
