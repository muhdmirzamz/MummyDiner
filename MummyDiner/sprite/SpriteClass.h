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
	
		// normal sprite
		virtual void set(const char *file, int cropX, int cropY, int cropW, int cropH, float x, float y, float scaleX = 0.1, float scaleY = 0.1);
		virtual void positionSprite(float x, float y);
		virtual void move();
		virtual void stop();
	
		// waitress
		virtual bool hasTakenFoodFromCounter();
	
		virtual void moveUp();
		virtual void moveDown();
		virtual void moveLeft();
		virtual void moveRight();
	
		virtual void handleCollisionWithWindow();
		virtual void handleCollisionWith(SpriteClass &object);
		virtual bool handleCollisionWith(SpriteClass *customer);
	
		virtual void pickOrderFromMenu();
		virtual bool hasPickedOrderFromMenu();
		virtual void setCorrectOrderFlag();
		virtual bool gotCorrectOrder();
	
		virtual bool isMovingUp();
		virtual bool isMovingDown();
		virtual bool isMovingRight();
		virtual bool isMovingLeft();
	
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
		virtual void renderFoodOrderPopup(RenderWindow &window);
		virtual void startThread();
		virtual void renderFood(RenderWindow &window);
		virtual void renderThanksPopup(RenderWindow &window);
		virtual void setAsSuccessful();
		virtual void setAsFailure();
		virtual void stopThread();

		virtual bool timeIsUp();
		virtual bool orderIsTaken();
		virtual bool foodIsServed();
		virtual bool timeIsAdded();
		virtual int getSpawnPosition();
		virtual int getOrderedFoodItem();
		virtual int getSuccessful();
		virtual int getFailure();
		virtual int getTimeLeft();
		virtual int getTimeLimit();
		virtual void addTime();
		virtual void renderWrongOrderPopup(RenderWindow &window);
		virtual void getServed();
		virtual void order();
		virtual void resetForNewLevel();
	
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
