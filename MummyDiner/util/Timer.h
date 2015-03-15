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
	
		void startCounting();
		void restart();
		void addMoreTime();
		void stopCounting();
	
		bool hasReachedLimit();
		bool hasAddedTime();
	
		int getClockTime();
		int getLimit();
		
	private:
		void reset();
	
		Clock _clock;
		Mutex _mutex;
	
		int _stillLooping;
		bool _timerHasReachedLimit;
		int _timeLimit;
	
		bool _needTime;
		bool _addedTime;
};

#endif /* defined(__MummyDiner__Timer__) */
