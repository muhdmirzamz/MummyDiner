//
//  Timer.h
//  MummyDiner
//
//  Created by Muhd Mirza on 12/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__Timer__
#define __MummyDiner__Timer__

#include <stdio.h>

#include <SFML/System.hpp>

using namespace sf;

class Timer {
	public:
		Timer();
	
		virtual void startCounting();
		void stopCounting();
		virtual void restart();
	
		bool hasReachedLimit();
	
		virtual int getClockTime();
		int getLimit();
		
	protected:	
		Clock _clock;
		Mutex _mutex;
	
		int _stillLooping;
		bool _timerHasReachedLimit;
		int _timeLimit;
};

#endif /* defined(__MummyDiner__Timer__) */
