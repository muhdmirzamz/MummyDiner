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
		void spawn();
		void renderOrderPopup(RenderWindow &window);
		void renderFoodOrderPopup(RenderWindow &window);
		void addTime();
		void renderWrongOrderPopup(RenderWindow &window);
		void getServed();
		void renderFood(RenderWindow &window);
		void renderThanksPopup(RenderWindow &window);
		void setAsSuccessful();
		void setAsFailure();
		void stopThread();
	
		bool timeIsUp();
		bool orderIsTaken();
		bool foodIsServed();
		bool timeIsAdded();
	
		int getSpawnPosition();
		int getOrderedFoodItem();
	
		int getSuccessful();
		int getFailure();
	
		int getTimeLeft();
		int getTimeLimit();
	
		void order();
	
		void resetForNewLevel();
	
	private:
		void reset();
	
		bool _ordered;
		bool _foodServed;
	
		SpriteClass _food;
	
		SpriteClass _orderPopup;
		SpriteClass _thanksPopup;
		SpriteClass _wrongOrderPopup;
	
		MenuSystem _menuSystem;
	
		int _randomPosition;
		int _randomFoodAndDrinks;
	
		int _customerSuccess;
		int _customerFailure;
};

#endif /* defined(__MummyDiner__Customer__) */
