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
#include "../util/Timer.h"

using namespace sf;

class SpriteClass {
	public:
		SpriteClass();
	
		// normal sprite
		virtual void set(const char *file, int cropX, int cropY, int cropW, int cropH, float x, float y, float scaleX = 0.1, float scaleY = 0.1);
		virtual void positionSprite(float x, float y);
		// waitress
		virtual void moveUp();
		virtual void moveDown();
		virtual void moveLeft();
		virtual void moveRight();
		
		virtual void handleCollisionWithWindow();
		virtual void handleCollisionWith(SpriteClass &object);
	
		virtual void takeOrder(); // needs integration with order list system
	
		// chef
		virtual void cook();
		virtual void startCooking();
	
		// customer
		virtual void spawn();
		virtual void startThread();
		virtual void stopThread();
		virtual bool hasWaited();
		virtual void order();
	
		// normal sprite
		virtual float getXPos();
		virtual float getYPos();
	
		virtual float getWidth();
		virtual float getHeight();
	
		virtual void render(RenderWindow &window);
	
	protected:
		Image _image;
		Texture _texture;
		IntRect _cropRect;
		Sprite _sprite;
	
		float _speed; // maybe good for future feature in speed variations
	
		/*
		bool spriteMovedUp;
		bool spriteMovedDown;
		bool spriteMovedLeft;
		bool spriteMovedRight;
		*/
};

#endif /* defined(__MummyDiner__Sprite__) */
