//
//  Chef.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Chef.h"

static ChefTimer chefTimerObject;
static Thread chefThread(&ChefTimer::launchTimerThread, &chefTimerObject);

Chef::Chef() {
	getReadyToCook();
}

void Chef::startThread() {
	chefThread.launch();
}

// reset properties
void Chef::getReadyToCook() {
	chefTimerObject.restart();
	_cooking = false;
}

void Chef::cook() {
	_cooking = true;
	chefTimerObject.startCounting();
}

void Chef::stopThread() {
	chefTimerObject.stopCounting();
}

bool Chef::isDoneCooking() {
	return chefTimerObject.hasReachedLimit();
}

bool Chef::isCooking() {
	return _cooking;
}

int Chef::getTimeLeft() {
	return chefTimerObject.getClockTime();
}