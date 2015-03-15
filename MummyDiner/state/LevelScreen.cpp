//
//  LevelScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

// might need this later
//#include <math.h>
#include "LevelScreen.h"

static FramesPerSecond fps;
static Thread fpsThread(&FramesPerSecond::startCounting, &fps);

#define TABLE_CROP_SETTINGS 300, 10, 600, 700

LevelScreen::LevelScreen() {
	_waitress = &_waitressObj;
	_waitress->set("images/waitress.bmp", 450, 10, 400, 690, 300, 10);
	_customer = &_customerObj;
	_customer->set("images/boy_customer.bmp", 450, 10, 400, 690, _customer->topLeftCoordinate.x, _customer->topLeftCoordinate.y);
	_chef = &_chefObj;
	_chef->set("images/chef.bmp", 450, 10, 400, 700, 500, 375, 0.15, 0.15);
	
	_topLeftTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 80, 50);
	_topRightTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 400, 50);
	_bottomLeftTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 80, 200);
	_bottomRightTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 400, 200);
	_counter.set("images/counter.bmp", 0, 200, SCREEN_W, 40, 0, 330, 1.0, 1.0);
	_stove.set("images/stove.bmp", 450, 10, 550, 650, SCREEN_W - _stove.getWidth() - 70, 400);
	
	_topLeftBackground.set(10, 10, SCREEN_W / 3, SCREEN_H / 4, 0, 255, 0);
	_topRightBackground.set(100 + SCREEN_W / 3, 10, SCREEN_W / 3, SCREEN_H / 4, 255, 0, 0);
	_bottomLeftBackground.set(10, 50 + SCREEN_H / 4, SCREEN_W / 3, SCREEN_H / 4, 0, 0, 255);
	_bottomRightBackground.set(100 + SCREEN_W / 3, 50 + SCREEN_H / 4, SCREEN_W / 3, SCREEN_H / 4, 100, 100, 100);
	
	// use different variables for setting sprite's next position
	// not using the variables used for tracking mouse position
	_mouseClickX = _waitress->getXPos();
	_mouseClickY = _waitress->getYPos();
	
#if DEBUG_MODE == 1
	_debug.set();
#endif
	
	fpsThread.launch();
	_customer->startThread();
}

void LevelScreen::handleEvent() {
	fps.hasReachedStartOfFrame();

	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			_customer->stopThread();
			fps.stopCounting();
		
			cleanup();
		
			setState(EXIT);
		}
		
#if DEBUG_MODE == 1
		if (event.type == event.MouseMoved) {
			_debug.setMousePosition(MOUSE_X, MOUSE_Y);
		}
#endif
		
		if (event.type == event.MouseButtonPressed) {
			// set sprite destination position
			_mouseClickX = MOUSE_X_CLICK;
			_mouseClickY = MOUSE_Y_CLICK;
		}
	}
}

void LevelScreen::spawnCustomer() {
	if (_customer->timeIsUp()) {
		_customer->spawn();
	} else {
		if (_customer->orderIsTaken()) {
			if (!_customer->timeIsAdded()) { // to avoid multiple increases
				_customer->addTime();
			}
		}
	}
	
	/*
		 if (_customer->timeIsUp()) {
			 _customer->spawn();
		 } else {
			 if (_customer->orderIsTaken()) {
				 if (_customer->foodisServed()) {
					 if (!_customer->timeIsAdded()) {
						 _customer->addTime();
					 }
				 } else if (_customer->isDoneEating()) {
					 _customer->spawn();
				 } else if (!_customer->timeIsAdded()) {
					_customer->addTime();
				 }
			 }
		 }
	*/
	
#if DEBUG_MODE == 1
	_debug.setTime(_customer->getTimeLeft());
	_debug.setTimeLimit(_customer->getTimeLimit());
#endif
}

void LevelScreen::moveCharacter() {
	// use mouse variables as guides for sprite to reach destination position
	if (_waitress->getXPos() >= _mouseClickX) {
		_waitress->moveLeft();
	}

	if (_waitress->getXPos() <= _mouseClickX) {
		_waitress->moveRight();
	}
	
	if (_waitress->getYPos() >= _mouseClickY) {
		_waitress->moveUp();
	}

	if (_waitress->getYPos() <= _mouseClickY) {
		_waitress->moveDown();
	}
	
	// order testing
	if (_waitress->getXPos() + _waitress->getWidth() >= _topLeftBackground.getX() && _waitress->getXPos() <= _topLeftBackground.getX() + _topLeftBackground.getWidth()) {
		if (_waitress->getYPos() + _waitress->getHeight() >= _topLeftBackground.getY() && _waitress->getYPos() <= _topLeftBackground.getY() + _topLeftBackground.getHeight()) {
			if (!_customer->orderIsTaken()) {
				_customer->order();
			}
		}
	}
	
#if DEBUG_MODE == 1
	_debug.setSpritePosition(_waitress->getXPos(), _waitress->getYPos());
#endif
}

void LevelScreen::checkCollision() {
	_waitress->handleCollisionWithWindow();
	_waitress->handleCollisionWith(_counter);
}

void LevelScreen::update() {
	window.clear(color.White);
	
	fps.hasReachedEndOfFrame();

#if DEBUG_MODE == 1
	_debug.setFPSValue(fps.getFPS());
#endif
}

void LevelScreen::render() {
	_topLeftBackground.render(window);
	_topRightBackground.render(window);
	_bottomLeftBackground.render(window);
	_bottomRightBackground.render(window);
	
	_waitress->render(window);
	_customer->render(window);
	_chef->render(window);
	
	_topLeftTable.render(window);
	_topRightTable.render(window);
	_bottomLeftTable.render(window);
	_bottomRightTable.render(window);
	_counter.render(window);
	_stove.render(window);
	
#if DEBUG_MODE == 1
	_debug.show(window);
#endif
	
	window.display();
}