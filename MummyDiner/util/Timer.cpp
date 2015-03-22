//
//  Timer.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 12/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Timer.h"

Timer::Timer() {
<<<<<<< HEAD
	_timerHasReachedLimit = false;
	_addedTimeNeeded = false;
	
	// might want to look out for this, buffer overflow may occur
	_timeLimit = 5000; // 5s
=======
	reset();
>>>>>>> mummydiner/v0.6.0-alpha
}

void Timer::startCounting() {
	Lock lock(_mutex);
<<<<<<< HEAD

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
=======
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
>>>>>>> mummydiner/v0.6.0-alpha
			}
		}
	}
}

<<<<<<< HEAD
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
=======
void Timer::restart() {
	_clock.restart();
	
	reset();
}

// opens up the flags to enable adding of time
// the only two flags that do not require a new customer to be switched back and forth
void Timer::addMoreTime() {
	_needTime = true;
	_addedTime = false;
>>>>>>> mummydiner/v0.6.0-alpha
}

void Timer::stopCounting() {
	_stillLooping = false;
}

<<<<<<< HEAD
bool Timer::hasReachedLimit() {
	return _timerHasReachedLimit;
=======
// resets when there is a new customer
void Timer::reset() {
	_timerHasReachedLimit = false;
	_needTime = false;
	_addedTime = false;
	
	_timeLimit = 10000; // 5s
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
>>>>>>> mummydiner/v0.6.0-alpha
}