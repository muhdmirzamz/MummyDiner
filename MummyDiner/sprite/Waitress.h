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
#include "Customer.h"
#include "Chef.h"
#include "../gui/BackgroundClass.h"

class Waitress: public SpriteClass {
	public:
		Waitress();
	
		void serveANewCustomer();
	
		void move(int mouseXClick, int mouseYClick);
	
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
	
		bool isMovingUp();
		bool isMovingDown();
		bool isMovingRight();
		bool isMovingLeft();
	
		void stop();
	
		void takeFoodFromCounter(Chef &chef);
		bool hasTakenFoodFromCounter();
		void pickOrderFromMenu(Customer &customer, MenuSystem &menuSystem, int mouseXClick, int mouseYClick);
		bool hasPickedOrderFromMenu();
	
		bool handleCollisionWith(Customer &customer);
		bool isInBackground(BackgroundClass &background);
		void interactWithCustomerAtTable(Customer &customer, MenuSystem &menuSystem, BackgroundClass backgroundArr[]);
	
	private:
		void executeCustomerMechanism(Customer &customer, MenuSystem &menuSystem);
	
		bool _foodTakenFromCounter;
		bool _pickedOrderFromMenu;
	
		bool _movingLeft;
		bool _movingRight;
		bool _movingUp;
		bool _movingDown;
};

#endif /* defined(__MummyDiner__Waitress__) */
