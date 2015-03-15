//
//  Timer.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 12/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Timer.h"

Timer::Timer() {
	reset();
}

void Timer::startCounting() {
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

void Timer::restart() {
	_clock.restart();
	
	reset();
}

// opens up the flags to enable adding of time
// renamed this function so as to avoid function name conflict with customer class
void Timer::addMoreTime() {
	_needTime = true;
	_addedTime = false;
}

void Timer::stopCounting() {
	_stillLooping = false;
}

void Timer::reset() {
	_timerHasReachedLimit = false;
	_needTime = false;
	_addedTime = false;
	
	_timeLimit = 5000; // 5s
}

bool Timer::hasReachedLimit() {
	return _timerHasReachedLimit;
}

// entry point
// check if time has been increased to avoid multiple increases - this is a key variable
bool Timer::hasAddedTime() {
	return _addedTime;
}

int Timer::getClockTime() {
	return _timeLimit - _clock.getElapsedTime().asMilliseconds();
}

int Timer::getLimit() {
	return _timeLimit;
}