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

#define POPUP_POS(X_POS, Y_POS) X_POS + 50, Y_POS - 50
#define FOOD_POS_LEFT_COLUMN(X_POS, Y_POS) X_POS - 50, Y_POS // different positions because of scaling
#define FOOD_POS_RIGHT_COLUMN(X_POS, Y_POS) X_POS - 50, Y_POS

/*
	Treat this customer class as a "wrapper" class 
	for controlling the timer class
	
	Level class needs to go through this customer class
	to have access / control to the timer class
	
	Here's the hierarchy:
	Level class
	Customer class
	Timer class(consists of two separate classes)
*/

Customer::Customer() {
	srand((int)time(NULL));
	reset();
	
	// load images first to avoid rendering problems later
	_orderPopup.set("images/customer_order_popup.bmp", 100, 30, 1100, 600, 0, 0);
	_thanksPopup.set("images/customer_thanks_popup.bmp", 100, 30, 1100, 600, 0, 0);
	_food.set("images/food.bmp", 100, 30, 900, 600, 0, 0, 0.05, 0.05);
}

void Customer::startThread() {
	customerThread.launch();
}

void Customer::spawn() {
	customerTimerObject.restart();
	reset();
	
	int randomPosition = rand() % 4 + 1;
	printf("Random position: %d\n", randomPosition);
	
	if (randomPosition == TOP_LEFT) {
		positionSprite(topLeftCoordinate.x, topLeftCoordinate.y);
		_orderPopup.positionSprite(POPUP_POS(topLeftCoordinate.x, topLeftCoordinate.y));
		_thanksPopup.positionSprite(POPUP_POS(topLeftCoordinate.x, topLeftCoordinate.y));
		_food.positionSprite(FOOD_POS_LEFT_COLUMN(topLeftCoordinate.x, topLeftCoordinate.y));
	}
	
	if (randomPosition == TOP_RIGHT) {
		positionSprite(topRightCoordinate.x, topRightCoordinate.y);
		_orderPopup.positionSprite(POPUP_POS(topRightCoordinate.x, topRightCoordinate.y));
		_thanksPopup.positionSprite(POPUP_POS(topRightCoordinate.x, topRightCoordinate.y));
		_food.positionSprite(FOOD_POS_RIGHT_COLUMN(topRightCoordinate.x, topRightCoordinate.y));
	}
	
	if (randomPosition == BOTTOM_LEFT) {
		positionSprite(bottomLeftCoordinate.x, bottomLeftCoordinate.y);
		_orderPopup.positionSprite(POPUP_POS(bottomLeftCoordinate.x, bottomLeftCoordinate.y));
		_thanksPopup.positionSprite(POPUP_POS(bottomLeftCoordinate.x, bottomLeftCoordinate.y));
		_food.positionSprite(FOOD_POS_LEFT_COLUMN(bottomLeftCoordinate.x, bottomLeftCoordinate.y));
	}
	
	if (randomPosition == BOTTOM_RIGHT) {
		positionSprite(bottomRightCoordinate.x, bottomRightCoordinate.y);
		_orderPopup.positionSprite(POPUP_POS(bottomRightCoordinate.x, bottomRightCoordinate.y));
		_thanksPopup.positionSprite(POPUP_POS(bottomRightCoordinate.x, bottomRightCoordinate.y));
		_food.positionSprite(FOOD_POS_RIGHT_COLUMN(bottomRightCoordinate.x, bottomRightCoordinate.y));
	}
}

void Customer::renderOrderPopup(RenderWindow &window) {
	_orderPopup.render(window);
}

void Customer::renderFood(RenderWindow &window) {
	_food.render(window);
}

void Customer::renderThanksPopup(RenderWindow &window) {
	_thanksPopup.render(window);
}

void Customer::stopThread() {
	customerTimerObject.stopCounting();
}

// use this to add more time
void Customer::order() {
	_ordered = true;
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