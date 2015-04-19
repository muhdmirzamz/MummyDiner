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
	_smoke.setSpriteUsingName("_smoke");
	
	getReadyToCook();
}

void Chef::startThread() {
	chefThread.launch();
}

void Chef::stopThread() {
	chefTimerObject.stopCounting();
}

// reset properties
void Chef::getReadyToCook() {
	_cooking = false;
	chefTimerObject.restart();
}

void Chef::cook() {
	_cooking = true;
	chefTimerObject.startCounting();
}

bool Chef::isDoneCooking() {
	return chefTimerObject.hasReachedLimit();
}

bool Chef::isCooking() {
	return _cooking;
}

void Chef::renderSmoke(RenderWindow &window) {
	if (isCooking() && !isDoneCooking()) {
		_smoke.render(window); // using SpriteClass render function FYI
	}
}

int Chef::getTimeLeft() {
	return chefTimerObject.getClockTime();
}