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
	
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
	
		void handleCollisionWithWindow();
		void handleCollisionWith(SpriteClass &object);
	
		void takeOrder(); // needs integration with order list system
};

#endif /* defined(__MummyDiner__Waitress__) */
