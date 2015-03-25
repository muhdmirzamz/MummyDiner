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
		struct topLeft {
			int x = 140;
			int y = 40;
		} topLeftCoordinate;
	
		struct topRight {
			int x = 450;
			int y = 40;
		} topRightCoordinate;
		
		struct bottomLeft{
			int x = 140;
			int y = 190;
		} bottomLeftCoordinate;
		
		struct bottomRight {
			int x = 460;
			int y = 190;
		} bottomRightCoordinate;
	
		enum coordinates {
			TOP_LEFT = 1,
			TOP_RIGHT = 2,
			BOTTOM_LEFT = 3,
			BOTTOM_RIGHT = 4
		};
	
		SpriteClass();
	
		// normal sprite
		virtual void set(const char *file, int cropX, int cropY, int cropW, int cropH, float x, float y, float scaleX = 0.1, float scaleY = 0.1);
		virtual void positionSprite(float x, float y);
		// waitress
		virtual bool hasTakenFoodFromCounter();
	
		virtual void moveUp();
		virtual void moveDown();
		virtual void moveLeft();
		virtual void moveRight();
	
		virtual void handleCollisionWithWindow();
		virtual void handleCollisionWith(SpriteClass &object);
	
		virtual void takeFoodFromCounter(); // needs integration with order list system
		virtual void serveANewCustomer();
	
		// chef
		virtual void getReadyToCook();
		virtual void cook();
		virtual void renderSmoke(RenderWindow &window);
		
		virtual bool isCooking();
		virtual bool isDoneCooking();
	
		// customer
		virtual void spawn();
		virtual void renderOrderPopup(RenderWindow &window);
		virtual void startThread();
		virtual void renderFood(RenderWindow &window);
		virtual void renderThanksPopup(RenderWindow &window);
		virtual void stopThread();

		virtual bool timeIsUp();
		virtual bool orderIsTaken();
		virtual bool foodIsServed();
		virtual bool timeIsAdded();
		virtual int getTimeLeft();
		virtual int getTimeLimit();
		virtual void addTime();
		virtual void getServed();
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
};

#endif /* defined(__MummyDiner__Sprite__) */
