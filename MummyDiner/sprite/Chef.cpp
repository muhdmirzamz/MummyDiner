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
	_smoke.set("images/smoke.bmp", 500, 10, 300, 600, SCREEN_W - 50, 350);

	getReadyToCook();
}

void Chef::startThread() {
	chefThread.launch();
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

void Chef::renderSmoke(RenderWindow &window) {
	_smoke.render(window); // using SpriteClass render function FYI
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