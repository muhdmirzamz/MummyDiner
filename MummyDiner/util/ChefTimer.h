//
//  ChefTimer.h
//  MummyDiner
//
//  Created by Muhd Mirza on 23/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__ChefTimer__
#define __MummyDiner__ChefTimer__

#include <stdio.h>

#include "Timer.h"

class ChefTimer: public Timer {
	public:
		ChefTimer();
	
		void launchTimerThread();
		void startCounting();
		void stopCounting();
		
		bool hasReachedLimit();
		
		int getClockTime();
		int getLimit();
	
		void restart();
	
	private:
		bool _timerIsStarted;
};

#endif /* defined(__MummyDiner__ChefTimer__) */
