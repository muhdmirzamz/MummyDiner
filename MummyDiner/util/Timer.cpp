//
//  Timer.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 12/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Timer.h"

Timer::Timer() {

}

void Timer::startCounting() {

}

void Timer::stopCounting() {
	_stillLooping = false;
}

void Timer::restart() {

}

bool Timer::hasReachedLimit() {
	return _timerHasReachedLimit;
}

int Timer::getClockTime() {
	return 0;
}

int Timer::getLimit() {
	return _timeLimit;
}