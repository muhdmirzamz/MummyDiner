//
//  Customer.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Customer.h"

static Timer timer;
static Thread customerTimer(&Timer::startCounting, &timer);

/*
	Treat this customer class as a "wrapper" class 
	for controlling the timer class
	
	Level class needs to go through this customer class
	to have access / control to the timer class
	
	Here's the hierarchy:
	Level class
	Customer class
	Timer class
*/

Customer::Customer() {
	_ordered = false;
}

void Customer::startThread() {
	customerTimer.launch(); // calls startCounting in Timer class
}

void Customer::spawn() {
	srand((int)time(NULL));
	int randomPosition = rand() % 4 + 1;
	printf("Random position: %d\n", randomPosition);
	
	if (randomPosition == TOP_LEFT) {
		positionSprite(topLeftCoordinate.x, topLeftCoordinate.y);
	}
	
	if (randomPosition == TOP_RIGHT) {
		positionSprite(topRightCoordinate.x, topRightCoordinate.y);
	}
	
	if (randomPosition == BOTTOM_LEFT) {
		positionSprite(bottomLeftCoordinate.x, bottomLeftCoordinate.y);
	}
	
	if (randomPosition == BOTTOM_RIGHT) {
		positionSprite(bottomRightCoordinate.x, bottomRightCoordinate.y);
	}
	

	timer.restart();
	_ordered = false;
}

void Customer::addTime() {
	timer.addMoreTime();
}

void Customer::stopThread() {
	timer.stopCounting();
}

bool Customer::timeIsUp() {
	return timer.hasReachedLimit();
}

bool Customer::orderIsTaken() {
	return _ordered;
}

bool Customer::timeIsAdded() {
	return timer.hasAddedTime();
}

int Customer::getTimeLeft() {
	return timer.getClockTime();
}

int Customer::getTimeLimit() {
	return timer.getLimit();
}

// use this to add more time
void Customer::order() {
	_ordered = true;
}