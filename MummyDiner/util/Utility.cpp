//
//  DebugMode.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 13/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Utility.h"

bool Utility::debug = false;
bool Utility::keyboardIsUsed = false;

Utility::Utility() {
	_font.loadFromFile(LATO_LIGHT_FONT);
	_fontSize = 15;
	
	_valuePositionOffset = 200;
}

// add debug properties here
void Utility::set() {
	// debug flags that are still showing when debug is off
	setTextAndPosition(_levelTimer, "Level timer:", 380, 50, _levelTimerValue);
	
	// next column
	setTextAndPosition(_customerSuccess, "Customer success: ", 380 , 10, _customerSuccessValue);
	setTextAndPosition(_customerFailure, "Customer failure: ", 380, 30, _customerFailureValue);
	
	// normal debug flags
	setTextAndPosition(_fps, "FPS: ", 10, 10, _fpsValue);
	
	setTextAndPosition(_mouseXPos, "Mouse X Pos: ", 10, 30, _mouseXPosValue);
	setTextAndPosition(_mouseYPos, "Mouse Y Pos: ", 10, 50, _mouseYPosValue);
	
	setTextAndPosition(_spriteXPos, "Sprite X Pos: ", 10, 70, _spriteXPosValue);
	setTextAndPosition(_spriteYPos, "Sprite Y Pos: ", 10, 90, _spriteYPosValue);
	
	setTextAndPosition(_timeLimit, "Customer time limit: ", 10, 110, _timeLimitValue);
	setTextAndPosition(_time, "Customer time: ", 10, 130, _timeValue);
	
	setTextAndPosition(_chefTimeLimit, "Chef time limit: ", 10, 150, _chefTimeLimitValue);
	
	setTextAndPosition(_order, "Order: ", 10, 170, _orderFlag);
	setTextAndPosition(_chefCook, "Cooking: ", 10 ,190, _chefCookValue);
	setTextAndPosition(_foodTaken, "Food taken: ", 10, 210, _foodTakenFlag);
	setTextAndPosition(_foodServed, "Food served: ", 10, 230, _foodServedFlag);
	
	setTextAndPosition(_customerSpawnPos, "Sprite spawn position: ", 10, 250, _customerSpawnPosValue);
	
	setTextAndPosition(_customerOrder, "Customer order: ", 10, 270, _customerOrderValue);
}

void Utility::setNonDebugFlags() {
	// debug flags that are still showing when debug is off
	setTextAndPosition(_levelTimer, "Level timer:", 380, 50, _levelTimerValue);
	
	// next column
	setTextAndPosition(_customerSuccess, "Customer success: ", 380 , 10, _customerSuccessValue);
	setTextAndPosition(_customerFailure, "Customer failure: ", 380, 30, _customerFailureValue);
}

// set the value of any changing / dynamic debug properties
// one example: FPS
void Utility::setFPSValue(int value) {
	_fpsValue.setString(to_string((int)value)); // change numeric value to string
}

void Utility::setMousePosition(int x, int y) {
	_mouseXPosValue.setString(to_string(x));
	_mouseYPosValue.setString(to_string(y));
}

void Utility::setSpritePosition(int x, int y) {
	_spriteXPosValue.setString(to_string(x));
	_spriteYPosValue.setString(to_string(y));
}

void Utility::setTimeLimit(int time) {
	_timeLimitValue.setString(to_string(time));
}

void Utility::setTime(int time) {
	_timeValue.setString(to_string(time));
}

void Utility::setOrderFlag(bool order) {
	_orderFlag.setString(to_string(order));
}

void Utility::setCookFlag(bool cook) {
	_chefCookValue.setString(to_string(cook));
}

void Utility::setFoodServedFlag(bool food) {
	_foodServedFlag.setString(to_string(food));
}

void Utility::setFoodTakenFlag(bool foodIsTaken) {
	_foodTakenFlag.setString(to_string(foodIsTaken));
}

void Utility::setCustomerSpawnPosition(int position) {
	_customerSpawnPosValue.setString(to_string(position));
}

void Utility::setCustomerOrderValue(int order) {
	_customerOrderValue.setString(to_string(order));
}

void Utility::setCustomerSuccessValue(int customer) {
	_customerSuccessValue.setString(to_string(customer));
}

void Utility::setCustomerFailureValue(int customer) {
	_customerFailureValue.setString(to_string(customer));
}

void Utility::setLevelTimerValue(int time) {
	_levelTimerValue.setString(to_string(time));
}

void Utility::setChefTimeLimit(int time) {
	_chefTimeLimitValue.setString(to_string(time));
}

void Utility::show(RenderWindow &window) {
	window.draw(_fps);
	window.draw(_fpsValue);
	
	window.draw(_mouseXPos);
	window.draw(_mouseXPosValue);
	window.draw(_mouseYPos);
	window.draw(_mouseYPosValue);
	
	window.draw(_spriteXPos);
	window.draw(_spriteXPosValue);
	window.draw(_spriteYPos);
	window.draw(_spriteYPosValue);
	
	window.draw(_timeLimit);
	window.draw(_timeLimitValue);
	window.draw(_time);
	window.draw(_timeValue);
	window.draw(_chefTimeLimit);
	window.draw(_chefTimeLimitValue);
	
	window.draw(_order);
	window.draw(_orderFlag);
	window.draw(_chefCook);
	window.draw(_chefCookValue);
	window.draw(_foodTaken);
	window.draw(_foodTakenFlag);
	window.draw(_foodServed);
	window.draw(_foodServedFlag);
	
	window.draw(_customerSpawnPos);
	window.draw(_customerSpawnPosValue);
	
	window.draw(_customerOrder);
	window.draw(_customerOrderValue);
	
	window.draw(_customerSuccess);
	window.draw(_customerSuccessValue);
	window.draw(_customerFailure);
	window.draw(_customerFailureValue);
	
	window.draw(_levelTimer);
	window.draw(_levelTimerValue);
}

void Utility::showNonDebugFlags(RenderWindow &window) {
	window.draw(_customerSuccess);
	window.draw(_customerSuccessValue);
	window.draw(_customerFailure);
	window.draw(_customerFailureValue);

	window.draw(_levelTimer);
	window.draw(_levelTimerValue);
}

// dealing with two things
// the text and the value side by side
void Utility::setTextAndPosition(Text &variableLabel, string label, float variableX, float variableY, Text &variableValue) {
	setText(variableLabel);
	setText(variableValue); // no need to set string for value first
	
	variableLabel.setString(label);
	variableValue.setString(to_string(0)); // preset values to 0
	
	variableLabel.setPosition(variableX, variableY);
	variableValue.setPosition(variableX + _valuePositionOffset, variableY); // set the value a bit to the right side, same y position though
}

void Utility::setText(Text &variable) {
	variable.setFont(_font);
	variable.setCharacterSize(_fontSize);
	variable.setStyle(Text::Bold);
	variable.setColor(Color(0, 0, 0));
}