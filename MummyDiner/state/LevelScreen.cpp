//
//  LevelScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "LevelScreen.h"

bool LevelScreen::normalMode = false;

static FramesPerSecond fps;
static Timer *fpsPointer = &fps;
static Thread fpsThread(&FramesPerSecond::startCounting, &fps);

static LevelTimer levelTimer;
static Timer *levelTimerPointer = &levelTimer;
static Thread levelTimerThread(&LevelTimer::startCounting, &levelTimer);

LevelScreen::LevelScreen() {
	_waitress = &_waitressObj;
	_waitress->setSpriteUsingName("_waitress", 0.1, 0.1);
	
	_customer = &_customerObj; // loads menu system popups as well, not the menu system tray
	_customer->setSpriteUsingName("_customer");
	_customerObj.spawn();
	
	_topWalkingCustomer = &_topWalkingCustomerObj;
	_topWalkingCustomer->setSpriteUsingName("_topWalkingCustomer");
	_bottomWalkingCustomer = &_bottomWalkingCustomerObj;
	_bottomWalkingCustomer->setSpriteUsingName("_bottomWalkingCustomer");
	
	_chef = &_chefObj;
	_chef->setSpriteUsingName("_chef", 0.15, 0.15);
	
	_topLeftTable.setSpriteUsingName("_topLeftTable");
	_topRightTable.setSpriteUsingName("_topRightTable");
	_bottomLeftTable.setSpriteUsingName("_bottomLeftTable");
	_bottomRightTable.setSpriteUsingName("_bottomRightTable");
	
	_counter.setSpriteUsingName("_counter", 1.0, 1.0);
	_stove.setSpriteUsingName("_stove");
	
	_topLeftBackground.setBackgroundUsingName("_topLeftBackground");
	_topRightBackground.setBackgroundUsingName("_topRightBackground");
	_bottomLeftBackground.setBackgroundUsingName("_bottomLeftBackground");
	_bottomRightBackground.setBackgroundUsingName("_bottomRightBackground");
	_foodPickupBackground.setBackgroundUsingName("_foodPickupBackground");
	
	// background stays with array due to a waitress function
	_backgroundArr[0] = _topLeftBackground;
	_backgroundArr[1] = _topRightBackground;
	_backgroundArr[2] = _bottomLeftBackground;
	_backgroundArr[3] = _bottomRightBackground;
	_backgroundArr[4] = _foodPickupBackground;
	
	_menuSystem.loadSpriteInTray();
	
	_lsBackToMenuButton.setButtonUsingName("_lsBackToMenuButton", "Back to\nmain menu");
	
	// use different variables for setting sprite's next position
	// not using the variables used for tracking mouse position
	_mouseClickX = _waitress->getXPos();
	_mouseClickY = _waitress->getYPos();
	
	if (Utility::debug) {
		_debug.set();
	} else {
		_debug.setNonDebugFlags();
	}
	
	if (normalMode) {
		levelTimerThread.launch();
	}
	
	fpsThread.launch();
	_customerObj.startThread();
	_chefObj.startThread();
}

void LevelScreen::handleEvent() {
	fps.setFrameStartPoint();

	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanupLevelScreen(EXIT);
		}
		
		if (Utility::debug) {
			if (event.type == event.MouseMoved) {
				_debug.setMousePosition(MOUSE_X, MOUSE_Y);
			}
			
			if (event.type == event.KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					cleanupLevelScreen(EXIT);
				}
			}
		}
		
		if (event.type == event.KeyPressed) {
			if (event.key.code == Keyboard::A) {
				_waitress->moveLeft();
			}
			
			if (event.key.code == Keyboard::D) {
				_waitress->moveRight();
			}
			
			if (event.key.code == Keyboard::W) {
				_waitress->moveUp();
			}
			
			if (event.key.code == Keyboard::S) {
				_waitress->moveDown();
			}
		}
		
		if (event.type == event.KeyReleased) {
			if (event.key.code == Keyboard::A) {
				_waitressObj.stop();
			}
			
			if (event.key.code == Keyboard::D) {
				_waitressObj.stop();
			}
			
			if (event.key.code == Keyboard::W) {
				_waitressObj.stop();
			}
			
			if (event.key.code == Keyboard::S) {
				_waitressObj.stop();
			}
		}
		
		if (event.type == event.MouseButtonPressed) {
			// set sprite destination position
			_mouseClickX = MOUSE_X_CLICK;
			_mouseClickY = MOUSE_Y_CLICK;
			
			_waitressObj.pickOrderFromMenu(_customerObj, _menuSystem, MOUSE_X_CLICK, MOUSE_Y_CLICK);
			
			if (_lsBackToMenuButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
				cleanupLevelScreen(MAIN_MENU);
			}
		}
	}
}

void LevelScreen::spawnCustomer() {
	if (normalMode) {
		_debug.setLevelTimerValue(levelTimerPointer->getClockTime());
		
		if (levelTimerPointer->hasReachedLimit()) {
			if (_customerObj.getSuccessful() == _customerObj.getFailure()) {
				GameOverScreen::success = false;
				GameOverScreen::neutral = true;
			} else if (_customerObj.getSuccessful() >= _customerObj.getFailure()) {
				GameOverScreen::success = true;
			} else {
				GameOverScreen::success = false;
				GameOverScreen::neutral = false;
			}
		
			cleanupLevelScreen(GAME_OVER);
		}
	}

	if (_customerObj.timeIsUp()) {
		if (!_customerObj.orderIsTaken()) {
			_customerObj.setAsFailure();
		}
		
		_customerObj.spawn();
		_topWalkingCustomer->positionSprite(20, 100);
		_bottomWalkingCustomer->positionSprite(700, 300);
		_waitressObj.serveANewCustomer();
		_chefObj.getReadyToCook();
	} else {
		if (_customerObj.orderIsTaken()) {
			if (!_customerObj.timeIsAdded()) {
				_customerObj.addTime();
			}
		}
	}
	
	if (Utility::debug) {
		_debug.setTime(_customerObj.getTimeLeft());
		_debug.setTimeLimit(_customerObj.getTimeLimit());
		_debug.setCustomerSpawnPosition(_customerObj.getSpawnPosition());
		_debug.setCustomerOrderValue(_customerObj.getOrderedFoodItem());
	}
}

void LevelScreen::moveCharacter() {
	_waitressObj.move(_mouseClickX, _mouseClickY);

	if (_waitressObj.hasTakenFoodFromCounter()) {
		_topWalkingCustomerObj.move();
		_bottomWalkingCustomerObj.move();
	}
	
	_waitressObj.interactWithCustomerAtTable(_customerObj, _menuSystem, _backgroundArr);
	
	if (_waitressObj.isInBackground(_foodPickupBackground)) {
		if (_customerObj.orderIsTaken() && _waitressObj.hasPickedOrderFromMenu()) {
			_chefObj.cook();
			_waitressObj.takeFoodFromCounter(_chefObj);
		}
	}
	
	if (Utility::debug) {
		_debug.setSpritePosition(_waitress->getXPos(), _waitress->getYPos());
		_debug.setOrderFlag(_customerObj.orderIsTaken());
		_debug.setCookFlag(_chefObj.isCooking());
		_debug.setFoodTakenFlag(_waitressObj.hasTakenFoodFromCounter());
		_debug.setFoodServedFlag(_customerObj.foodIsServed());
		_debug.setChefTimeLimit(_chefObj.getTimeLeft());
		_debug.setCustomerSuccessValue(_customerObj.getSuccessful());
		_debug.setCustomerFailureValue(_customerObj.getFailure());
	} else {
		_debug.setCustomerSuccessValue(_customerObj.getSuccessful());
		_debug.setCustomerFailureValue(_customerObj.getFailure());
	}
}

void LevelScreen::checkCollision() {
	_waitress->handleCollisionWithWindow(_counter);
	
	if (_waitressObj.hasTakenFoodFromCounter() && !_customerObj.foodIsServed()) {
		if (_waitressObj.handleCollisionWith(_topWalkingCustomerObj) || _waitressObj.handleCollisionWith(_bottomWalkingCustomerObj)) {
			_customerObj.spawn();
			_topWalkingCustomer->positionSprite(20, 100);
			_bottomWalkingCustomer->positionSprite(700, 300);
			_waitressObj.serveANewCustomer();
			_chefObj.getReadyToCook();
			_customerObj.setAsFailure();
		}
	}
}

void LevelScreen::update() {
	window.clear(color.White);
	
	fps.setFrameEndPoint();

	if (Utility::debug) {
		_debug.setFPSValue(fps.getFPS());
	}
}

void LevelScreen::render() {
	for (int i = 0; i < 5; i++) {
		_backgroundArr[i].render(window);
	}
	
	_lsBackToMenuButton.render(window);
	
	_waitress->render(window);
	_customer->render(window);
	_chef->render(window);
	
	_customerObj.renderPopup(window);
	_chefObj.renderSmoke(window);
	
	if (_waitressObj.hasTakenFoodFromCounter() && _chefObj.isDoneCooking() && !_customerObj.foodIsServed()) {
		_topWalkingCustomer->render(window);
		_bottomWalkingCustomer->render(window);
	}
	
	_topLeftTable.render(window);
	_topRightTable.render(window);
	_bottomLeftTable.render(window);
	_bottomRightTable.render(window);
	_counter.render(window);
	_stove.render(window);
	
	_menuSystem.render(window);
	
	if (Utility::debug) {
		_debug.show(window);
	} else {
		_debug.showNonDebugFlags(window);
	}
	
	window.display();
}

void LevelScreen::cleanupLevelScreen(int state) {
	_customerObj.stopThread();
	_chefObj.stopThread();
	fpsPointer->stopCounting();
	
	if (normalMode) {
		levelTimerPointer->stopCounting();
	}
	
	cleanup();
	
	setState(state);
}