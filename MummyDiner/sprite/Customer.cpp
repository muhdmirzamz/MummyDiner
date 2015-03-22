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
*/

Customer::Customer() {

}

void Customer::startThread() {
	customerTimer.launch();
}

void Customer::spawn() {
/*
	srand((int)time(NULL));
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
}