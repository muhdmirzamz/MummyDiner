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
	_wrongOrderPopup.set("images/customer_wrong_order_popup.bmp", 100, 30, 1100, 600, 0, 0);
	
	_food.set("images/food.bmp", 100, 30, 900, 600, 0, 0, 0.05, 0.05);
	
	_menuSystem.loadSpriteInPopup();
}

void Customer::startThread() {
	customerThread.launch();
}

void Customer::spawn() {
	customerTimerObject.restart();
	reset();
	
	_randomPosition = rand() % 4 + 1;
	_randomFoodAndDrinks = rand() % 4 + 1;
	
	if (_randomPosition == _menuSystem.TOP_LEFT) {
		positionSprite(_menuSystem.topLeftCoordinate.x, _menuSystem.topLeftCoordinate.y);
		_orderPopup.positionSprite(POPUP_POS(_menuSystem.topLeftCoordinate.x, _menuSystem.topLeftCoordinate.y));
		_thanksPopup.positionSprite(POPUP_POS(_menuSystem.topLeftCoordinate.x, _menuSystem.topLeftCoordinate.y));
		_wrongOrderPopup.positionSprite(POPUP_POS(_menuSystem.topLeftCoordinate.x, _menuSystem.topLeftCoordinate.y));
		
		_food.positionSprite(FOOD_POS_LEFT_COLUMN(_menuSystem.topLeftCoordinate.x, _menuSystem.topLeftCoordinate.y));
		
		_menuSystem.positionSpriteInPopup(POPUP_POS(_menuSystem.topLeftCoordinate.x, _menuSystem.topLeftCoordinate.y));
	}
	
	if (_randomPosition == _menuSystem.TOP_RIGHT) {
		positionSprite(_menuSystem.topRightCoordinate.x, _menuSystem.topRightCoordinate.y);
		_orderPopup.positionSprite(POPUP_POS(_menuSystem.topRightCoordinate.x, _menuSystem.topRightCoordinate.y));
		_thanksPopup.positionSprite(POPUP_POS(_menuSystem.topRightCoordinate.x, _menuSystem.topRightCoordinate.y));
		_wrongOrderPopup.positionSprite(POPUP_POS(_menuSystem.topRightCoordinate.x, _menuSystem.topRightCoordinate.y));
		
		_food.positionSprite(FOOD_POS_RIGHT_COLUMN(_menuSystem.topRightCoordinate.x, _menuSystem.topRightCoordinate.y));
		
		_menuSystem.positionSpriteInPopup(POPUP_POS(_menuSystem.topRightCoordinate.x, _menuSystem.topRightCoordinate.y));
	}
	
	if (_randomPosition == _menuSystem.BOTTOM_LEFT) {
		positionSprite(_menuSystem.bottomLeftCoordinate.x, _menuSystem.bottomLeftCoordinate.y);
		_orderPopup.positionSprite(POPUP_POS(_menuSystem.bottomLeftCoordinate.x, _menuSystem.bottomLeftCoordinate.y));
		_thanksPopup.positionSprite(POPUP_POS(_menuSystem.bottomLeftCoordinate.x, _menuSystem.bottomLeftCoordinate.y));
		_wrongOrderPopup.positionSprite(POPUP_POS(_menuSystem.bottomLeftCoordinate.x, _menuSystem.bottomLeftCoordinate.y));
		
		_food.positionSprite(FOOD_POS_LEFT_COLUMN(_menuSystem.bottomLeftCoordinate.x, _menuSystem.bottomLeftCoordinate.y));
		
		_menuSystem.positionSpriteInPopup(POPUP_POS(_menuSystem.bottomLeftCoordinate.x, _menuSystem.bottomLeftCoordinate.y));
	}
	
	if (_randomPosition == _menuSystem.BOTTOM_RIGHT) {
		positionSprite(_menuSystem.bottomRightCoordinate.x, _menuSystem.bottomRightCoordinate.y);
		_orderPopup.positionSprite(POPUP_POS(_menuSystem.bottomRightCoordinate.x, _menuSystem.bottomRightCoordinate.y));
		_thanksPopup.positionSprite(POPUP_POS(_menuSystem.bottomRightCoordinate.x, _menuSystem.bottomRightCoordinate.y));
		_wrongOrderPopup.positionSprite(POPUP_POS(_menuSystem.bottomRightCoordinate.x, _menuSystem.bottomRightCoordinate.y));
		
		_food.positionSprite(FOOD_POS_RIGHT_COLUMN(_menuSystem.bottomRightCoordinate.x, _menuSystem.bottomRightCoordinate.y));
		
		_menuSystem.positionSpriteInPopup(POPUP_POS(_menuSystem.bottomRightCoordinate.x, _menuSystem.bottomRightCoordinate.y));
	}
}

void Customer::move() {
	_sprite.move(_customerSpeed, 0);
}

void Customer::moveLeft() {
	_customerSpeed = -0.5;
}

void Customer::moveRight() {
	_customerSpeed = 0.5;
}

void Customer::renderOrderPopup(RenderWindow &window) {
	_orderPopup.render(window);
}

void Customer::renderFoodOrderPopup(RenderWindow &window) {
	if (_randomFoodAndDrinks == _menuSystem.HAMBURGER) {
		_menuSystem.renderFoodAndDrinks(_menuSystem.HAMBURGER, window);
	}
	
	if (_randomFoodAndDrinks == _menuSystem.FRIES) {
		_menuSystem.renderFoodAndDrinks(_menuSystem.FRIES, window);
	}
	
	if (_randomFoodAndDrinks == _menuSystem.CHOCOLATE_SMOOTHIE) {
		_menuSystem.renderFoodAndDrinks(_menuSystem.CHOCOLATE_SMOOTHIE, window);
	}
	
	if (_randomFoodAndDrinks == _menuSystem.LEMON_JUICE) {
		_menuSystem.renderFoodAndDrinks(_menuSystem.LEMON_JUICE, window);
	}
}

void Customer::renderFood(RenderWindow &window) {
	_food.render(window);
}

void Customer::renderThanksPopup(RenderWindow &window) {
	_thanksPopup.render(window);
}

void Customer::setAsSuccessful() {
	++_customerSuccess;
}

void Customer::setAsFailure() {
	++_customerFailure;
}

void Customer::stopThread() {
	customerTimerObject.stopCounting();
}

// use this to add more time
void Customer::order() {
	_ordered = true;
}

void Customer::resetForNewLevel() {
	reset();
	
	_customerSuccess = 0;
	_customerFailure = 0;
}

void Customer::addTime() {
	customerTimerObject.addMoreTime();
}

void Customer::renderWrongOrderPopup(RenderWindow &window) {
	_wrongOrderPopup.render(window);
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

int Customer::getSpawnPosition() {
	return _randomPosition;
}

int Customer::getOrderedFoodItem() {
	return _randomFoodAndDrinks;
}

int Customer::getSuccessful() {
	return _customerSuccess;
}

int Customer::getFailure() {
	return _customerFailure;
}

int Customer::getTimeLeft() {
	return customerTimerObject.getClockTime();
}

int Customer::getTimeLimit() {
	return customerTimerObject.getLimit();
}

// this class resets only when there's a new customer
void Customer::reset() {
	_customerSpeed = 0.5;

	_ordered = false;
	_foodServed = false;
}