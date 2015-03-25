//
//  CustomerTimer.h
//  MummyDiner
//
//  Created by Muhd Mirza on 23/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__CustomerTimer__
#define __MummyDiner__CustomerTimer__

#include <stdio.h>

#include "Timer.h"

class CustomerTimer: public Timer {
	public:
		CustomerTimer();
	
		void startCounting();
		void restart();
		
		void addMoreTime();
		void stopCounting();
		
		bool hasReachedLimit();
		bool hasAddedTime();
		
		int getClockTime();
		int getLimit();
	
	private:
		bool _needTime;
		bool _addedTime;
};

#endif /* defined(__MummyDiner__CustomerTimer__) */
