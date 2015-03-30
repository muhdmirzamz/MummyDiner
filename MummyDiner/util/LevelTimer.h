//
//  LevelTimer.h
//  MummyDiner
//
//  Created by Muhd Mirza on 28/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__LevelTimer__
#define __MummyDiner__LevelTimer__

#include <stdio.h>

#include "Timer.h"

class LevelTimer: public Timer {
	public:
		LevelTimer();
	
		void startCounting();
		void stopCounting();
	
		bool hasReachedLimit();
	
		int getClockTime();
		int getLimit();
};

#endif /* defined(__MummyDiner__LevelTimer__) */
