//
//  Customer.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Customer.h"

// macros here since both menu system and customer class use them
#define POPUP_POS(X_POS, Y_POS) X_POS + 50, Y_POS - 50
#define FOOD_POS(X_POS, Y_POS) X_POS - 50, Y_POS // different positions because of scaling

static CustomerTimer customerTimer;
static Timer *customerTimerPointer = &customerTimer;
static Thread customerThread(&CustomerTimer::startCounting, &customerTimer);

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
	
	_customerSuccess = 0;
	_customerFailure = 0;
	
	// load images first to avoid rendering problems later
	_orderPopup.setSpriteUsingName("_orderPopup");
	_thanksPopup.setSpriteUsingName("_thanksPopup");
	_wrongOrderPopup.setSpriteUsingName("_wrongOrderPopup");
	
	_food.setSpriteUsingName("_food", 0.05, 0.05); // food on table
	
	_menuSystem.loadSpriteInPopup();
}

void Customer::startThread() {
	customerThread.launch();
}

void Customer::stopThread() {
	customerTimerPointer->stopCounting();
}

void Customer::spawn() {
	customerTimer.restart();
	reset();
	
	_randomPosition = rand() % 4 + 1;
	_randomFoodAndDrinks = rand() % 4 + 1;
	
	int menuSystemEnumArr[] = {_menuSystem.TOP_LEFT, _menuSystem.TOP_RIGHT, _menuSystem.BOTTOM_LEFT, _menuSystem.BOTTOM_RIGHT};
	int menuSystemXCoord[] = {_menuSystem.topLeftCoordinate.x, _menuSystem.topRightCoordinate.x, _menuSystem.bottomLeftCoordinate.x, _menuSystem.bottomRightCoordinate.x};
	int menuSystemYCoord[] = {_menuSystem.topLeftCoordinate.y, _menuSystem.topRightCoordinate.y, _menuSystem.bottomLeftCoordinate.y, _menuSystem.bottomRightCoordinate.y};
	
	for (int i = 0; i < 4; i++) {
		if (_randomPosition == menuSystemEnumArr[i]) {
			positionSprite(menuSystemXCoord[i], menuSystemYCoord[i]);
			_orderPopup.positionSprite(POPUP_POS(menuSystemXCoord[i], menuSystemYCoord[i]));
			_thanksPopup.positionSprite(POPUP_POS(menuSystemXCoord[i], menuSystemYCoord[i]));
			_wrongOrderPopup.positionSprite(POPUP_POS(menuSystemXCoord[i], menuSystemYCoord[i]));
			
			_food.positionSprite(FOOD_POS(menuSystemXCoord[i], menuSystemYCoord[i]));
			
			_menuSystem.positionSpriteInPopup(POPUP_POS(menuSystemXCoord[i], menuSystemYCoord[i]));
			
			break;
		}
	}
}

void Customer::move() {
	_sprite.move(_customerSpeed, 0);
	
	if (getXPos() <= 0) {
		_customerSpeed = 0.5;
	}
	
	if (getXEndPos() >= SCREEN_W) {
		_customerSpeed = -0.5;
	}
}

void Customer::order() {
	_ordered = true;
}

bool Customer::orderIsTaken() {
	return _ordered;
}

void Customer::getServed() {
	_foodServed = true;
}

bool Customer::foodIsServed() {
	return _foodServed;
}

void Customer::setAsSuccessful() {
	_correctOrder = true;
	++_customerSuccess;
}

int Customer::getSuccessful() {
	return _customerSuccess;
}

void Customer::setAsFailure() {
	++_customerFailure;
}

int Customer::getFailure() {
	return _customerFailure;
}

int Customer::getSpawnPosition() {
	return _randomPosition;
}

int Customer::getOrderedFoodItem() {
	return _randomFoodAndDrinks;
}

bool Customer::didGetCorrectFood(int foodCode) {
	return (_randomFoodAndDrinks == foodCode);
}

void Customer::renderPopup(RenderWindow &window) {
	if (!orderIsTaken()) {
		_orderPopup.render(window);
	} else {
		if (foodIsServed()) {
			if (_correctOrder) {
				_food.render(window);
				_thanksPopup.render(window);
			} else {
				_wrongOrderPopup.render(window);
			}
		} else {
			int menuSystemPopupArr[] = {_menuSystem.HAMBURGER, _menuSystem.FRIES, _menuSystem.CHOCOLATE_SMOOTHIE, _menuSystem.LEMON_JUICE};
			
			for (int i = 0; i < 4; i++) {
				if (_randomFoodAndDrinks == menuSystemPopupArr[i]) {
					_menuSystem.renderFoodAndDrinks(menuSystemPopupArr[i], window);
					break;
				}
			}
		}
	}
}

void Customer::addTime() {
	customerTimer.addMoreTime();
}

bool Customer::timeIsAdded() {
	return customerTimer.hasAddedTime();
}

bool Customer::timeIsUp() {
	return customerTimerPointer->hasReachedLimit();
}

int Customer::getTimeLeft() {
	return customerTimerPointer->getClockTime();
}

int Customer::getTimeLimit() {
	return customerTimerPointer->getLimit();
}

// this class resets only when there's a new customer
void Customer::reset() {
	_customerSpeed = 0.5;

	_ordered = false;
	_foodServed = false;
	_correctOrder = false; // this flag has no specific functions, used in this class only
}