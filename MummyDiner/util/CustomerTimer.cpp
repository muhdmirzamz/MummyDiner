//
//  CustomerTimer.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 23/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "CustomerTimer.h"

CustomerTimer::CustomerTimer() {
	restart();
}

void CustomerTimer::startCounting() {
	Lock lock(_mutex);
	
	_stillLooping = true;
	
	_clock.restart();
	
	while (_stillLooping) {
		if (_clock.getElapsedTime().asMilliseconds() >= _timeLimit) {
			_timerHasReachedLimit = true;
		} else {
			_timerHasReachedLimit = false;
			
			
			printf("Time: %d && Time Limit: %d\n", _timeLimit - _clock.getElapsedTime().asMilliseconds(), _timeLimit);
			// need more time?
			// have you added more time?
			
			// add more time
			// _needTime = true
			// _addedTime = false
			
			// dont add more time
			// _needTime = false
			// _addedTime = true
			if (_needTime) {
				// might want to add a variable for 5000, depending on difficulty level
				_timeLimit += 5000;
				_needTime = false;
				_addedTime = true; // to avoid multiple increases
			}
		}
	}
}

void CustomerTimer::restart() {
	_clock.restart();
	
	_timerHasReachedLimit = false;
	_needTime = false;
	_addedTime = false;
	
	_timeLimit = 10000;
}

// opens up the flags to enable adding of time
void CustomerTimer::addMoreTime() {
	_needTime = true;
	_addedTime = false;
}

// check if time has been increased to avoid multiple increases
bool CustomerTimer::hasAddedTime() {
	return _addedTime;
}

int CustomerTimer::getClockTime() {
	return _timeLimit - _clock.getElapsedTime().asMilliseconds();
}