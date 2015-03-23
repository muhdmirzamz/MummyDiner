//
//  Customer.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Customer.h"

static CustomerTimer customerTimerObject;
static Thread customerThread(&CustomerTimer::startCounting, &customerTimerObject);

/*
	Treat this customer class as a "wrapper" class 
	for controlling the timer class
	
	Level class needs to go through this customer class
	to have access / control to the timer class
*/

Customer::Customer() {
	reset();
}

void Customer::startThread() {
/*
	Here's the hierarchy:
	Level class
	Customer class
	Timer class
*/
	customerThread.launch();
}

void Customer::spawn() {
	customerTimerObject.restart();
	reset();
	
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
}

void Customer::stopThread() {
	customerTimerObject.stopCounting();
}

// use this to add more time
void Customer::order() {
	_ordered = true;
	customerTimerObject.addMoreTime();
}

void Customer::addTime() {
	customerTimerObject.addMoreTime();
}

void Customer::getServed() {
	_foodServed = true;
}

bool Customer::timeIsUp() {
	return customerTimerObject.hasReachedLimit();
}

bool Customer::orderIsTaken() {
	return _ordered;
}

bool Customer::foodIsServed() {
	return _foodServed;
}

bool Customer::timeIsAdded() {
	return customerTimerObject.hasAddedTime();
}

int Customer::getTimeLeft() {
	return customerTimerObject.getClockTime();
}

int Customer::getTimeLimit() {
	return customerTimerObject.getLimit();
}

// this class resets only when there's a new customer
void Customer::reset() {
	_ordered = false;
	_foodServed = false;
}