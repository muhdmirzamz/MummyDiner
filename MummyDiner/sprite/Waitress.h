//
//  Waitress.h
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__Waitress__
#define __MummyDiner__Waitress__

#include "SpriteClass.h"
#include "Chef.h"

class Waitress: public SpriteClass {
	public:
		Waitress();
	
		float getXPos();
		float getYPos();
	
		float getWidth();
		float getHeight();
	
		bool hasTakenFoodFromCounter();
	
		void move();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void stop();
	
		void handleCollisionWithWindow();
		void handleCollisionWith(SpriteClass &object);
		bool handleCollisionWith(SpriteClass *customer);
	
		void pickOrderFromMenu();
		bool hasPickedOrderFromMenu();
		void setCorrectOrderFlag();
		bool gotCorrectOrder();
	
		bool isMovingUp();
		bool isMovingDown();
		bool isMovingRight();
		bool isMovingLeft();
	
		void takeFoodFromCounter();
		void serveANewCustomer();
	
	private:
		bool _movingLeft;
		bool _movingRight;
		bool _movingUp;
		bool _movingDown;
	
		bool _foodTakenFromCounter;
		bool _pickedOrderFromMenu;
		bool _correctOrderFromMenu;
	
		Chef _chef;
};

#endif /* defined(__MummyDiner__Waitress__) */
