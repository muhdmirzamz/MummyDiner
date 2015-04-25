//
//  Chef.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Chef.h"

static ChefTimer chefTimer;
static Timer *chefTimerPointer = &chefTimer;
static Thread chefThread(&ChefTimer::launchTimerThread, &chefTimer);

Chef::Chef() {
	_smoke.setSpriteUsingName("_smoke");
	
	getReadyToCook();
}

void Chef::startThread() {
	chefThread.launch();
}

void Chef::stopThread() {
	chefTimerPointer->stopCounting();
}

// reset properties
void Chef::getReadyToCook() {
	_cooking = false;
	
	chefTimer.restart();
}

void Chef::cook() {
	if (!_cooking) {
		_cooking = true;
		
		chefTimerPointer->startCounting();
	}
}

bool Chef::isDoneCooking() {
	return chefTimerPointer->hasReachedLimit();
}

bool Chef::isCooking() {
	return _cooking;
}

void Chef::renderSmoke(RenderWindow &window) {
	if (_cooking && !isDoneCooking()) {
		_smoke.render(window); // using SpriteClass render function FYI
	}
}

int Chef::getTimeLeft() {
	return chefTimerPointer->getClockTime();
}