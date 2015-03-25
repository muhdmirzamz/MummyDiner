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
				_timeLimit = (_timeLimit - _clock.getElapsedTime().asMilliseconds()) + 5000;
				_needTime = false;
				_addedTime = true; // signals to level class that time has been added to avoid multiple adding
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
// the only two flags that do not require a new customer to be switched back and forth
void CustomerTimer::addMoreTime() {
	_needTime = true;
	_addedTime = false;
}

void CustomerTimer::stopCounting() {
	_stillLooping = false;
}

bool CustomerTimer::hasReachedLimit() {
	return _timerHasReachedLimit;
}

// entry point
// check if time has been increased to avoid multiple increases - this is a key variable
bool CustomerTimer::hasAddedTime() {
	return _addedTime;
}

int CustomerTimer::getClockTime() {
	return _timeLimit - _clock.getElapsedTime().asMilliseconds();
}

int CustomerTimer::getLimit() {
	return _timeLimit;
}