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

static LevelTimer levelTimer;
static Thread levelTimerThread(&LevelTimer::startCounting, &levelTimer);

#define TABLE_CROP_SETTINGS 300, 10, 600, 700

LevelScreen::LevelScreen() {
	_waitress = &_waitressObj;
	_waitress->set("images/waitress.bmp", 450, 10, 400, 690, 300, 10);
	
	_customer = &_customerObj;
	_customer->resetForNewLevel();
	_customer->set("images/boy_customer.bmp", 450, 10, 400, 690, 0, 0);
	_customer->spawn();
	_topWalkingCustomer = &_topWalkingCustomerObj;
	_topWalkingCustomer->resetForNewLevel();
	_topWalkingCustomer->set("images/boy_customer.bmp", 450, 10, 400, 690, 20, 100);
	_bottomWalkingCustomer = &_bottomWalkingCustomerObj;
	_bottomWalkingCustomer->resetForNewLevel();
	_bottomWalkingCustomer->set("images/boy_customer.bmp", 450, 10, 400, 690, SCREEN_W - 100, 300);
	
	_chef = &_chefObj;
	_chef->set("images/chef.bmp", 450, 10, 400, 700, 650, SCREEN_H - 100, 0.15, 0.15);
	
	_topLeftTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 80, 50);
	_topRightTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 400, 50);
	_bottomLeftTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 80, 200);
	_bottomRightTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 400, 200);
	
	_counter.set("images/counter.bmp", 0, 200, SCREEN_W, 40, 0, 450, 1.0, 1.0);
	_stove.set("images/stove.bmp", 450, 10, 550, 650, SCREEN_W - _stove.getWidth() - 70, SCREEN_H - 80);
	
	_topLeftBackground.set(50, 10, SCREEN_W / 3, SCREEN_H / 5, 0, 255, 0);
	_topRightBackground.set(140 + SCREEN_W / 3, 10, SCREEN_W / 3, SCREEN_H / 5, 255, 0, 0);
	_bottomLeftBackground.set(50, 50 + SCREEN_H / 4, SCREEN_W / 3, SCREEN_H / 5, 0, 0, 255);
	_bottomRightBackground.set(140 + SCREEN_W / 3, 50 + SCREEN_H / 4, SCREEN_W / 3, SCREEN_H / 5, 100, 100, 100);
	_foodPickupBackground.set(450, 400, 200, 50, 200, 200, 200);
	
	_backToMenuButton.set(320, SCREEN_H - 50, 150, 50, 0, 200, 50, "Back to\nmain menu", 0, 0, 0);
	
	// use different variables for setting sprite's next position
	// not using the variables used for tracking mouse position
	_mouseClickX = _waitress->getXPos();
	_mouseClickY = _waitress->getYPos();
	
	if (Utility::debug) {
		_debug.set();
	} else {
		_debug.setNonDebugFlags();
	}
	
	fpsThread.launch();
	
	levelTimerThread.launch();
	_customer->startThread();
	_chef->startThread();
}

void LevelScreen::handleEvent() {
	fps.hasReachedStartOfFrame();

	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			_customer->stopThread();
			_chef->stopThread();
			fps.stopCounting();
			levelTimer.stopCounting();
		
			cleanup();
		
			setState(EXIT);
		}
		
		if (Utility::debug) {
			if (event.type == event.MouseMoved) {
				_debug.setMousePosition(MOUSE_X, MOUSE_Y);
			}
			
			if (event.type == event.KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					_customer->stopThread();
					_chef->stopThread();
					fps.stopCounting();
					levelTimer.stopCounting();
					
					cleanup();
					
					setState(EXIT);
				}
			}
		}
		
		if (Utility::keyboardIsUsed) {
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
					_waitress->stop();
				}
				
				if (event.key.code == Keyboard::D) {
					_waitress->stop();
				}
				
				if (event.key.code == Keyboard::W) {
					_waitress->stop();
				}
				
				if (event.key.code == Keyboard::S) {
					_waitress->stop();
				}
			}
		}
		
		if (event.type == event.MouseButtonPressed) {
			// set sprite destination position
			_mouseClickX = MOUSE_X_CLICK;
			_mouseClickY = MOUSE_Y_CLICK;
			
			if (_customer->orderIsTaken() && !_waitress->hasPickedOrderFromMenu()) {
				if (_menuSystem.getMenuItemXAxis(MOUSE_X_CLICK)) {
					if (MOUSE_Y_CLICK >= 400 && MOUSE_Y_CLICK <= SCREEN_H) {
						if (Utility::debug) {
							printf("Food code: %d\n", _menuSystem.getFoodCode());
						}
						
						_waitress->pickOrderFromMenu();
					}
				}
			}
			
			if (MOUSE_X_CLICK >= _backToMenuButton.getLeftSide() && MOUSE_X_CLICK <= _backToMenuButton.getLeftSide()+_backToMenuButton.getWidth()) {
				if (MOUSE_Y_CLICK >= _backToMenuButton.getTop() && MOUSE_Y_CLICK <= _backToMenuButton.getTop() + _backToMenuButton.getHeight()) {
					_customer->stopThread();
					_chef->stopThread();
					fps.stopCounting();
					levelTimer.stopCounting();
					
					cleanup();
					
					setState(MAIN_MENU);
				}
			}
		}
	}
}

void LevelScreen::spawnCustomer() {
	if (levelTimer.hasReachedLimit()) {
		_customer->stopThread();
		_chef->stopThread();
		fps.stopCounting();
		levelTimer.stopCounting();
		
		cleanup();

		if (_customer->getSuccessful() == _customer->getFailure()) { // if it is equal, go to menu
			GameOverScreen::success = true;
			GameOverScreen::neutral = true;
		
			setState(GAME_OVER);
		} else if (_customer->getSuccessful() >= _customer->getFailure()) {
			GameOverScreen::success = true;
		
			setState(GAME_OVER);
		} else if (_customer->getSuccessful() <= _customer->getFailure()) {
			GameOverScreen::success = false;
			
			setState(GAME_OVER);
		}
	}

	if (_customer->timeIsUp()) {
		_customer->spawn();
		_topWalkingCustomer->positionSprite(20, 100);
		_waitress->serveANewCustomer();
		_chef->getReadyToCook();
	} else {
		if (_customer->orderIsTaken()) {
			if (!_customer->timeIsAdded()) {
				_customer->addTime();
			}
			
			if (_customer->getOrderedFoodItem() == _menuSystem.getFoodCode()) {
				if (_customer->foodIsServed()) { // true once the waitress has taken food from counter and served customer
					if (!_customer->timeIsAdded()) { // to avoid multiple increases
						_customer->addTime();
					}
				}
			}
		}
	}
	
	if (Utility::debug) {
		_debug.setTime(_customer->getTimeLeft());
		_debug.setTimeLimit(_customer->getTimeLimit());
		_debug.setCustomerSpawnPosition(_customer->getSpawnPosition());
		_debug.setCustomerOrderValue(_customer->getOrderedFoodItem());
		_debug.setLevelTimerValue(levelTimer.getClockTime());
	} else {
		_debug.setLevelTimerValue(levelTimer.getClockTime());
	}
}

void LevelScreen::moveCharacter() {
	if (Utility::keyboardIsUsed) {
		_waitress->move();
	} else {
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
	}

	if (_waitress->hasTakenFoodFromCounter()) {
		_topWalkingCustomer->move();
		_bottomWalkingCustomer->move();
	
		if (_topWalkingCustomer->getXPos() <= 0) {
			_topWalkingCustomer->moveRight();
		}
		
		if (_topWalkingCustomer->getXPos() + _topWalkingCustomer->getWidth() >= SCREEN_W) {
			_topWalkingCustomer->moveLeft();
		}
		
		if (_bottomWalkingCustomer->getXPos() <= 0) {
			_bottomWalkingCustomer->moveRight();
		}
		
		if (_bottomWalkingCustomer->getXPos() + _bottomWalkingCustomer->getWidth() >= SCREEN_W) {
			_bottomWalkingCustomer->moveLeft();
		}
	}
	
	
	if (_customer->getSpawnPosition() == _menuSystem.TOP_LEFT) {
		if (_waitress->getXPos() + _waitress->getWidth() >= _topLeftBackground.getX() && _waitress->getXPos() <= _topLeftBackground.getX() + _topLeftBackground.getWidth()) {
			if (_waitress->getYPos() + _waitress->getHeight() >= _topLeftBackground.getY() && _waitress->getYPos() <= _topLeftBackground.getY() + _topLeftBackground.getHeight()) {
				if (_customer->orderIsTaken()) {
					if (_waitress->hasTakenFoodFromCounter()) {
						if (!_customer->foodIsServed()) {
							_customer->getServed();
							
							if (_customer->getOrderedFoodItem() == _menuSystem.getFoodCode()) {
								_waitress->setCorrectOrderFlag();
								_customer->setAsSuccessful();
							} else {
								_customer->setAsFailure();
							}
						}
					}
				} else {
					_customer->order();
				}
			}
		}
	}
	
	if (_customer->getSpawnPosition() == _menuSystem.TOP_RIGHT) {
		if (_waitress->getXPos() + _waitress->getWidth() >= _topRightBackground.getX() && _waitress->getXPos() <= _topRightBackground.getX() + _topRightBackground.getWidth()) {
			if (_waitress->getYPos() + _waitress->getHeight() >= _topRightBackground.getY() && _waitress->getYPos() <= _topRightBackground.getY() + _topRightBackground.getHeight()) {
				printf("test\n");
				if (_customer->orderIsTaken()) {
					if (_waitress->hasTakenFoodFromCounter()) {
						if (!_customer->foodIsServed()) {
							_customer->getServed();
							
							if (_customer->getOrderedFoodItem() == _menuSystem.getFoodCode()) {
								_waitress->setCorrectOrderFlag();
								_customer->setAsSuccessful();
							} else {
								_customer->setAsFailure();
							}
						}
					}
				} else {
					_customer->order();
				}
			}
		}
	}
	
	if (_customer->getSpawnPosition() == _menuSystem.BOTTOM_LEFT) {
		if (_waitress->getXPos() + _waitress->getWidth() >= _bottomLeftBackground.getX() && _waitress->getXPos() <= _bottomLeftBackground.getX() + _bottomLeftBackground.getWidth()) {
			if (_waitress->getYPos() + _waitress->getHeight() >= _bottomLeftBackground.getY() && _waitress->getYPos() <= _bottomLeftBackground.getY() + _bottomLeftBackground.getHeight()) {
				if (_customer->orderIsTaken()) {
					if (_waitress->hasTakenFoodFromCounter()) {
						if (!_customer->foodIsServed()) {
							_customer->getServed();
							
							if (_customer->getOrderedFoodItem() == _menuSystem.getFoodCode()) {
								_waitress->setCorrectOrderFlag();
								_customer->setAsSuccessful();
							} else {
								_customer->setAsFailure();
							}
						}
					}
				} else {
					_customer->order();
				}
			}
		}
	}
	
	if (_customer->getSpawnPosition() == _menuSystem.BOTTOM_RIGHT) {
		if (_waitress->getXPos() + _waitress->getWidth() >= _bottomRightBackground.getX() && _waitress->getXPos() <= _bottomRightBackground.getX() + _bottomRightBackground.getWidth()) {
			if (_waitress->getYPos() + _waitress->getHeight() >= _bottomRightBackground.getY() && _waitress->getYPos() <= _bottomRightBackground.getY() + _bottomRightBackground.getHeight()) {
				if (_customer->orderIsTaken()) {
					if (_waitress->hasTakenFoodFromCounter()) {
						if (!_customer->foodIsServed()) {
							_customer->getServed();
							
							if (_customer->getOrderedFoodItem() == _menuSystem.getFoodCode()) {
								_waitress->setCorrectOrderFlag();
								_customer->setAsSuccessful();
							} else {
								_customer->setAsFailure();
							}
						}
					}
				} else {
					_customer->order();
				}
			}
		}
	}

	
	// food pickup mechanism
	if (_waitress->getXPos() + _waitress->getWidth() >= _foodPickupBackground.getX() && _waitress->getXPos() <= _foodPickupBackground.getX() + _foodPickupBackground.getWidth()) {
		if (_waitress->getYPos() + _waitress->getHeight() >= _counter.getYPos()) { // using counter is way more effective than food pickup background
			if (_customer->orderIsTaken() && _waitress->hasPickedOrderFromMenu()) {
				if (!_chef->isCooking()) {
					_chef->cook();
				} else if (_chef->isDoneCooking()) {
					_waitress->takeFoodFromCounter();
				}
			}
		}
	}
	
	if (Utility::debug) {
		_debug.setSpritePosition(_waitress->getXPos(), _waitress->getYPos());
		_debug.setOrderFlag(_customer->orderIsTaken());
		_debug.setCookFlag(_chef->isCooking());
		_debug.setFoodTakenFlag(_waitress->hasTakenFoodFromCounter());
		_debug.setFoodServedFlag(_customer->foodIsServed());
		_debug.setChefTimeLimit(_chef->getTimeLeft());
		_debug.setCustomerSuccessValue(_customer->getSuccessful());
		_debug.setCustomerFailureValue(_customer->getFailure());
	} else {
		_debug.setCustomerSuccessValue(_customer->getSuccessful());
		_debug.setCustomerFailureValue(_customer->getFailure());
	}
}

void LevelScreen::checkCollision() {
	_waitress->handleCollisionWithWindow();
	_waitress->handleCollisionWith(_counter);
	
	if (_waitress->hasTakenFoodFromCounter() && _waitress->handleCollisionWith(_topWalkingCustomer)) {
		_customer->spawn();
		_topWalkingCustomer->positionSprite(20, 100);
		_waitress->serveANewCustomer();
		_chef->getReadyToCook();
	}
}

void LevelScreen::update() {
	window.clear(color.White);
	
	fps.hasReachedEndOfFrame();

	if (Utility::debug) {
		_debug.setFPSValue(fps.getFPS());
	}
}

void LevelScreen::render() {
	_topLeftBackground.render(window);
	_topRightBackground.render(window);
	_bottomLeftBackground.render(window);
	_bottomRightBackground.render(window);
	_foodPickupBackground.render(window);
	
	_backToMenuButton.render(window);
	
	_waitress->render(window);
	_customer->render(window);
	
	if (_waitress->hasTakenFoodFromCounter()) {
		_topWalkingCustomer->render(window);
		_bottomWalkingCustomer->render(window);
	}
	
	_chef->render(window);
	
	_topLeftTable.render(window);
	_topRightTable.render(window);
	_bottomLeftTable.render(window);
	_bottomRightTable.render(window);
	_counter.render(window);
	_stove.render(window);
	
	if (!_customer->orderIsTaken()) {
		_customer->renderOrderPopup(window);
	} else {
		if (_customer->foodIsServed()) {
			if (_waitress->gotCorrectOrder()) {
				_customer->renderFood(window);
				_customer->renderThanksPopup(window);
			} else {
				_customer->renderWrongOrderPopup(window);
			}
		} else {
			_customer->renderFoodOrderPopup(window);
		}
	}
	
	if (_chef->isCooking() && !_chef->isDoneCooking()) {
		_chef->renderSmoke(window);
	}
	
	_menuSystem.render(window);
	
	if (Utility::debug) {
		_debug.show(window);
	} else {
		_debug.showNonDebugFlags(window);
	}
	
	window.display();
}