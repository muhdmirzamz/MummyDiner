//
//  Timer.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 12/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Timer.h"

Timer::Timer() {
	_timerHasReachedLimit = false;
	_addedTimeNeeded = false;
	
	// might want to look out for this, buffer overflow may occur
	_timeLimit = 5000; // 5s
}

void Timer::startCounting() {
	Lock lock(_mutex);

	_stillLooping = true;
	
	// test loop
	while (_stillLooping) {
		// might wanna put debug texts for this
		printf("Customer time: %d\n", _clock.getElapsedTime().asMilliseconds());
		
		// if it is more than 5s, restart
		if (_clock.getElapsedTime().asMilliseconds() >= _timeLimit) {
			_timerHasReachedLimit = true;
		
			restart();
		} else {
			_timerHasReachedLimit = false;
			
			if (_addedTimeNeeded) {
				addTimeLimit(3000); // time limit may need a variable for different difficulty levels, 3s
			}
		}
	}
}

// might wanna put this function as inline
// since the code is short and always called often
void Timer::restart() {
	_clock.restart();
}

void Timer::addTime() {
	_addedTimeNeeded = true;
}

void Timer::addTimeLimit(int timeAdded) {
	_timeLimit += timeAdded;
	
	_addedTimeNeeded = false; // do not forget to set this to false
}

void Timer::stopCounting() {
	_stillLooping = false;
}

bool Timer::hasReachedLimit() {
	return _timerHasReachedLimit;
}