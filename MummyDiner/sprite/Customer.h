//
//  Customer.h
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__Customer__
#define __MummyDiner__Customer__

#include "SpriteClass.h"
#include "../util/MenuSystem.h" // macros are here

class Customer: public SpriteClass {
	public:
		Customer();
	
		void startThread();
		void stopThread();
		void spawn();
	
		void move();
	
		void order();
		bool orderIsTaken();
	
		void getServed();
		bool foodIsServed();
	
		void setAsSuccessful();
		int getSuccessful();
		void setAsFailure();
		int getFailure();
	
		int getSpawnPosition();
		int getOrderedFoodItem();
		bool didGetCorrectFood(int foodCode);
	
		void renderPopup(RenderWindow &window);
	
		void addTime();
		bool timeIsAdded();
		bool timeIsUp();
	
		int getTimeLeft();
		int getTimeLimit();
	
	private:
		void reset();

		bool _ordered;
		bool _foodServed;
		bool _correctOrder;
	
		int _customerSuccess;
		int _customerFailure;
	
		SpriteClass _food;
	
		SpriteClass _orderPopup;
		SpriteClass _thanksPopup;
		SpriteClass _wrongOrderPopup;
	
		MenuSystem _menuSystem;
	
		float _customerSpeed;
		int _randomPosition;
		int _randomFoodAndDrinks;
};

#endif /* defined(__MummyDiner__Customer__) */
