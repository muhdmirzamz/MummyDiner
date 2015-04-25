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

// reason for this function
// chef sprite is unlike any other
// they dont start counting straight away
// they wait for the input from other sprites
// example: they wait for waitress to give them the orders
//			before cooking, which starts the timer
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

// this function does things different from the other sprite classes
// simply because of the launchTimerThread function
// and the nature of the chef sprite
void ChefTimer::startCounting() {
	_clock.restart();
	_timerIsStarted = true; // start the actual counting
}

int ChefTimer::getClockTime() {
	return (int)_clock.getElapsedTime().asMilliseconds();
}

void ChefTimer::restart() {
	_timerHasReachedLimit = false;
	_timerIsStarted = false;
	
	_timeLimit = CHEF_TIME_LIMIT;
	
	_clock.restart();
}