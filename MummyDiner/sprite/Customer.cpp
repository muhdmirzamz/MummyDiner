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
<<<<<<< HEAD
*/

Customer::Customer() {

}

void Customer::startThread() {
	customerTimer.launch();
=======
	
	Here's the hierarchy:
	Level class
	Customer class
	Timer class
*/

Customer::Customer() {
	reset();
}

void Customer::startThread() {
	customerTimer.launch(); // calls startCounting in Timer class
>>>>>>> mummydiner/v0.6.0-alpha
}

void Customer::spawn() {
	srand((int)time(NULL));
<<<<<<< HEAD
	_randomTable = rand() % 4 + 1;
*/

	timer.restart();
}

void Customer::stopThread() {
	timer.stopCounting();
}

bool Customer::hasWaited() {
	return timer.hasReachedLimit();
}

// use this to add more time
void Customer::order() {
	timer.addTime();
=======
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
	reset();
}

void Customer::addTime() {
	timer.addMoreTime();
}

void Customer::getServed() {
	_foodServed = true;
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

bool Customer::foodIsServed() {
	return _foodServed;
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

// this class resets only when there's a new customer
void Customer::reset() {
	_ordered = false;
	_foodServed = false;
>>>>>>> mummydiner/v0.6.0-alpha
}