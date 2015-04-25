//
//  Waitress.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Waitress.h"

Waitress::Waitress() {
	serveANewCustomer();
}

// resets properties
void Waitress::serveANewCustomer() {
	_foodTakenFromCounter = false;
	_pickedOrderFromMenu = false;
	
	_movingUp = false;
	_movingDown = false;
	_movingLeft = false;
	_movingRight = false;
}

void Waitress::move(int mouseXClick, int mouseYClick) {
	if (Utility::keyboardIsUsed) {
		if (_movingUp || _movingDown) {
			_sprite.move(0, _speed);
		}
		
		if (_movingLeft || _movingRight) {
			_sprite.move(_speed, 0);
		}
	} else {
		if (getXPos() >= mouseXClick) {
			_sprite.move(-_speed, 0);
		}
		
		if (getXPos() <= mouseXClick) {
			_sprite.move(_speed, 0);
		}
		
		if (getYPos() >= mouseYClick) {
			_sprite.move(0, -_speed);
		}
		
		if (getYPos() <= mouseYClick) {
			_sprite.move(0, _speed);
		}
	}
}

void Waitress::moveUp() {
	if (Utility::keyboardIsUsed) {
		_movingDown = false;
		_movingUp = true;
		_movingRight = false;
		_movingLeft = false;
		
		_speed = -1;
	}
}

void Waitress::moveDown() {
	if (Utility::keyboardIsUsed) {
		_movingDown = true;
		_movingUp = false;
		_movingRight = false;
		_movingLeft = false;
		
		_speed = 1;
	}
}

void Waitress::moveLeft() {
	if (Utility::keyboardIsUsed) {
		_movingLeft = true;
		_movingUp = false;
		_movingDown = false;
		_movingRight = false;
		
		_speed = -1;
	}
}

void Waitress::moveRight() {
	if (Utility::keyboardIsUsed) {
		_movingRight = true;
		_movingUp = false;
		_movingDown = false;
		_movingLeft = false;
		
		_speed = 1;
	}
}

bool Waitress::isMovingUp() {
	return _movingUp;
}

bool Waitress::isMovingDown() {
	return _movingDown;
}

bool Waitress::isMovingRight() {
	return _movingRight;
}

bool Waitress::isMovingLeft() {
	return _movingLeft;
}

void Waitress::stop() {
	_speed = 0;
}

void Waitress::takeFoodFromCounter(Chef &chef) {
	if (chef.isDoneCooking()) {
		_foodTakenFromCounter = true;
	}
}

bool Waitress::hasTakenFoodFromCounter() {
	return _foodTakenFromCounter;
}

void Waitress::pickOrderFromMenu(Customer &customer, MenuSystem &menuSystem, int mouseXClick, int mouseYClick) {
	if (customer.orderIsTaken() && !hasPickedOrderFromMenu()) {
		if (menuSystem.itemIsChosen(mouseXClick, mouseYClick)) {
			_pickedOrderFromMenu = true;
		}
	}
}

bool Waitress::hasPickedOrderFromMenu() {
	return _pickedOrderFromMenu;
}

bool Waitress::handleCollisionWith(Customer &customer) {
	if (getXEndPos() >= customer.getXPos() && getXPos() <= customer.getXEndPos()) {
		if (getYEndPos() >= customer.getYPos() && getYPos() <= customer.getYEndPos()) {
			return true;
		}
	}
	
	return false;
}

bool Waitress::isInBackground(BackgroundClass &background) {
	if (getXEndPos() >= background.getX() && getXPos() <= background.getXEndPoint()) {
		if (getYEndPos() >= background.getY() && getYPos() <= background.getYEndPoint()) {
			return true;
		}
	}
	
	return false;
}

void Waitress::interactWithCustomerAtTable(Customer &customer, MenuSystem &menuSystem, BackgroundClass backgroundArr[]) {
	int coord[] = {menuSystem.TOP_LEFT, menuSystem.TOP_RIGHT, menuSystem.BOTTOM_LEFT, menuSystem.BOTTOM_RIGHT};
	
	for (int i = 0; i < 4; i++) { // remember background has five elements but only first four is needed
		if (isInBackground(backgroundArr[i])) {
			if (customer.getSpawnPosition() == coord[i]) {
				executeCustomerMechanism(customer, menuSystem);
				break;
			}
		}
	}
}

void Waitress::executeCustomerMechanism(Customer &customer, MenuSystem &menuSystem) {
	if (customer.orderIsTaken()) {
		if (hasTakenFoodFromCounter()) {
			if (!customer.foodIsServed()) {
				customer.getServed();
				
				if (customer.getOrderedFoodItem() == menuSystem.getFoodCode()) {
					customer.setAsSuccessful();
				} else {
					customer.setAsFailure();
				}
			}
		}
	} else {
		customer.order();
	}
}