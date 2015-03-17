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

class Customer: public SpriteClass {
	public:
		Customer();
	
		void startThread();
		void spawn();
		void addTime();
		void getServed();
		void stopThread();
	
		bool timeIsUp();
		bool orderIsTaken();
		bool foodIsServed();
		bool timeIsAdded();
	
		int getTimeLeft();
		int getTimeLimit();
	
		void order();
	
	private:
		void reset();
	
		bool _ordered;
		bool _foodServed;
};

#endif /* defined(__MummyDiner__Customer__) */
