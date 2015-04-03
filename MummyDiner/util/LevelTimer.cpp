//
//  LevelTimer.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 28/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "LevelTimer.h"

LevelTimer::LevelTimer() {

}

void LevelTimer::startCounting() {
	Lock lock(_mutex);
	
	_stillLooping = true;

	_timeLimit = 30000; // try 5 min, this is 15s
	
	_clock.restart();
	
	while (_stillLooping) {
		if (_clock.getElapsedTime().asMilliseconds() >= _timeLimit) {
			_timerHasReachedLimit = true;
		} else {
			_timerHasReachedLimit = false;
		}
	}
}

void LevelTimer::stopCounting() {
	_stillLooping = false;
}

bool LevelTimer::hasReachedLimit() {
	return _timerHasReachedLimit;
}

int LevelTimer::getClockTime() {
	return _timeLimit - _clock.getElapsedTime().asMilliseconds();
}

int LevelTimer::getLimit() {
	return _timeLimit;
}