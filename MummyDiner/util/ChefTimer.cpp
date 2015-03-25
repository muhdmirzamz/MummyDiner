//
//  ChefTimer.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 23/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "ChefTimer.h"

#define CHEF_TIME_LIMIT 2000

ChefTimer::ChefTimer() {
	restart();
}

void ChefTimer::launchTimerThread() {
	Lock lock(_mutex);
	
	_stillLooping = true;
	
	_timeLimit = CHEF_TIME_LIMIT;
	
	while (_stillLooping) {
		if (_timerIsStarted) {
			if (_clock.getElapsedTime().asMilliseconds() >= _timeLimit) {
				_timerHasReachedLimit = true;
			} else {
				_timerHasReachedLimit = false;
			}
		}
	}
}

void ChefTimer::startCounting() {
	_clock.restart();
	_timerIsStarted = true; // start the actual counting
}

void ChefTimer::stopCounting() {
	_stillLooping = false; // stop the whole thread
}

bool ChefTimer::hasReachedLimit() {
	return _timerHasReachedLimit;
}

int ChefTimer::getClockTime() {
	return (int)_clock.getElapsedTime().asMilliseconds();
}

int ChefTimer::getLimit() {
	return _timeLimit;
}

void ChefTimer::restart() {
	_timerHasReachedLimit = false;
	_timerIsStarted = false;
	
	_timeLimit = CHEF_TIME_LIMIT;
	
	_clock.restart();
}