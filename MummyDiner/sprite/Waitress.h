//
//  Waitress.h
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__Waitress__
#define __MummyDiner__Waitress__

#include <stdio.h>

#include "SpriteClass.h"

class Waitress: public SpriteClass {
	public:
		Waitress();
	
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
	
		void handleWindowCollision();
		void takeOrder(); // needs integration with order list system
	
	private:
		int _rightOfWindow; // AKA window width
		int _bottomOfWindow; // AKA window height
	
		int _leftOfWaitress;
		int _rightOfWaitress;
		int _topOfWaitress;
		int _bottomOfWaitress;
};

#endif /* defined(__MummyDiner__Waitress__) */
