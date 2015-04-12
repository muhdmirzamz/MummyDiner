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

#include "../util/Utility.h"

using namespace sf;

class BackgroundClass {
	public:
		BackgroundClass();
	
		void setBackgroundUsingName(string name);
	
		float getX();
		float getY();
		float getXEndPoint();
		float getYEndPoint();
	
		void render(RenderWindow &window);
	
	private:
		RectangleShape _background;
	
		Image _image;
		Texture _texture;
	
		string _tempImageFile;
		float _tempX;
		float _tempY;
		float _tempW;
		float _tempH;
		int _tempR;
		int _tempG;
		int _tempB;
};

#endif /* defined(__MummyDiner__BackgroundClass__) */
