//
//  Sprite.h
//  MummyDiner
//
//  Created by Muhd Mirza on 11/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__Sprite__
#define __MummyDiner__Sprite__

#include <stdio.h>

#include <SFML/Graphics.hpp>

#include "../util/Utility.h"
#include "../util/CustomerTimer.h"
#include "../util/ChefTimer.h"

using namespace sf;

class SpriteClass {
	public:
		SpriteClass();
	
		void setSpriteUsingName(string name, float scaleX = 0.1, float scaleY = 0.1);
		void positionSprite(float x, float y);
	
		// waitress and customer have different function bodies for these methods
		// hence function being virtual
		virtual void moveUp();
		virtual void moveDown();
		virtual void moveLeft();
		virtual void moveRight();
	
		void handleCollisionWithWindow(SpriteClass &counter); // and counter
	
		float getXPos();
		float getYPos();
		
		float getWidth();
		float getHeight();
	
		float getXEndPos();
		float getYEndPos();
	
		void render(RenderWindow &window);
	
	protected:
		Sprite _sprite;
	
		float _speed; // maybe good for future feature in speed variations
	
	private:
		Image _image;
		Texture _texture;
		IntRect _cropRect;
	
		string _tempImageFile;
	
		int _tempCropX;
		int _tempCropY;
		int _tempCropW;
		int _tempCropH;
	
		float _tempX;
		float _tempY;
};

#endif /* defined(__MummyDiner__Sprite__) */
