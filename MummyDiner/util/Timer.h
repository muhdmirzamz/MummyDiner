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
		void addTime();
		void addTimeLimit(int timeAdded);
		void stopCounting();
	
		bool hasReachedLimit();
		
	private:
		int _stillLooping;
		bool _timerHasReachedLimit;
		int _timeLimit;
		Clock _clock;
	
		Mutex _mutex;
	
		bool _addedTimeNeeded;
};

#endif /* defined(__MummyDiner__Timer__) */
