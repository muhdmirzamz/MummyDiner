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

class Waitress: public SpriteClass {
	public:
		Waitress();
	
		float getXPos();
		float getYPos();
	
		float getWidth();
		float getHeight();
	
		bool hasTakenFoodFromCounter();
	
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
	
		void handleCollisionWithWindow();
		void handleCollisionWith(SpriteClass &object);
	
		void takeFoodFromCounter(); // needs integration with order list system
		void serveANewCustomer();
	
	private:
		bool _foodTakenFromCounter;
};

#endif /* defined(__MummyDiner__Waitress__) */
