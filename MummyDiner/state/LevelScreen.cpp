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

bool LevelScreen::normalMode = false;

static FramesPerSecond fps;
static Thread fpsThread(&FramesPerSecond::startCounting, &fps);

static LevelTimer levelTimer;
static Thread levelTimerThread(&LevelTimer::startCounting, &levelTimer);

#define TABLE_CROP_SETTINGS 300, 10, 600, 700

LevelScreen::LevelScreen() {
	_waitress = &_waitressObj;
	_waitress->set("images/waitress.bmp", 450, 10, 400, 690, 300, 10);
	
	_customer = &_customerObj; // loads menu system as well
	_customerObj.resetForNewLevel();
	_customer->set("images/boy_customer.bmp", 450, 10, 400, 690, 0, 0);
	_customerObj.spawn();
	
	_topWalkingCustomer = &_topWalkingCustomerObj;
	_topWalkingCustomerObj.resetForNewLevel();
	_topWalkingCustomer->set("images/boy_customer.bmp", 450, 10, 400, 690, 20, 100);
	_bottomWalkingCustomer = &_bottomWalkingCustomerObj;
	_bottomWalkingCustomerObj.resetForNewLevel();
	_bottomWalkingCustomer->set("images/boy_customer.bmp", 450, 10, 400, 690, SCREEN_W - 100, 300);
	
	_chef = &_chefObj;
	_chef->set("images/chef.bmp", 450, 10, 400, 700, 650, SCREEN_H - 100, 0.15, 0.15);
	
	_topLeftTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 80, 50);
	_topRightTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 400, 50);
	_bottomLeftTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 80, 200);
	_bottomRightTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 400, 200);
	
	_counter.set("images/counter.bmp", 0, 200, SCREEN_W, 40, 0, 450, 1.0, 1.0);
	_stove.set("images/stove.bmp", 450, 10, 550, 650, SCREEN_W - _stove.getWidth() - 70, SCREEN_H - 80);
	
	_topLeftBackground.setBackgroundUsingName("_topLeftBackground");
	_topRightBackground.setBackgroundUsingName("_topRightBackground");
	_bottomLeftBackground.setBackgroundUsingName("_bottomLeftBackground");
	_bottomRightBackground.setBackgroundUsingName("_bottomRightBackground");
	_foodPickupBackground.setBackgroundUsingName("_foodPickupBackground");
	
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
	fps.hasReachedStartOfFrame();

	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			_customerObj.stopThread();
			_chefObj.stopThread();
			fps.stopCounting();
			
			if (normalMode) {
				levelTimer.stopCounting();
			}
		
			cleanup();
		
			setState(EXIT);
		}
		
		if (Utility::debug) {
			if (event.type == event.MouseMoved) {
				_debug.setMousePosition(MOUSE_X, MOUSE_Y);
			}
			
			if (event.type == event.KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					_customerObj.stopThread();
					_chefObj.stopThread();
					fps.stopCounting();
					
					if (normalMode) {
						levelTimer.stopCounting();
					}
					
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
		}
		
		if (event.type == event.MouseButtonPressed) {
			// set sprite destination position
			_mouseClickX = MOUSE_X_CLICK;
			_mouseClickY = MOUSE_Y_CLICK;
			
			if (_customerObj.orderIsTaken() && !_waitressObj.hasPickedOrderFromMenu()) {
				if (_menuSystem.getMenuItemXAxis(MOUSE_X_CLICK)) {
					if (MOUSE_Y_CLICK >= 400 && MOUSE_Y_CLICK <= SCREEN_H) {
						if (Utility::debug) {
							printf("Food code: %d\n", _menuSystem.getFoodCode());
						}
						
						_waitressObj.pickOrderFromMenu();
					}
				}
			}
			
			if (_lsBackToMenuButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
				_customerObj.stopThread();
				_chefObj.stopThread();
				fps.stopCounting();
				
				if (normalMode) {
					levelTimer.stopCounting();
				}
				
				cleanup();
				
				setState(MAIN_MENU);
			}
		}
	}
}

void LevelScreen::spawnCustomer() {
	if (normalMode) {
		if (levelTimer.hasReachedLimit()) {
			_customerObj.stopThread();
			_chefObj.stopThread();
			fps.stopCounting();
			levelTimer.stopCounting();
			
			cleanup();

			if (_customerObj.getSuccessful() == _customerObj.getFailure()) {
				GameOverScreen::success = true;
				GameOverScreen::neutral = true;
			
				setState(GAME_OVER);
			} else if (_customerObj.getSuccessful() >= _customerObj.getFailure()) {
				GameOverScreen::success = true;
			
				setState(GAME_OVER);
			} else if (_customerObj.getSuccessful() <= _customerObj.getFailure()) {
				GameOverScreen::success = false;
				
				setState(GAME_OVER);
			}
		}
	}

	if (_customerObj.timeIsUp()) {
		_customerObj.spawn();
		_topWalkingCustomer->positionSprite(20, 100);
		_waitressObj.serveANewCustomer();
		_chefObj.getReadyToCook();
	} else {
		if (_customerObj.orderIsTaken()) {
			if (!_customerObj.timeIsAdded()) {
				_customerObj.addTime();
			}
			
			if (_customerObj.getOrderedFoodItem() == _menuSystem.getFoodCode()) {
				if (_customerObj.foodIsServed()) { // true once the waitress has taken food from counter and served customer
					if (!_customerObj.timeIsAdded()) { // to avoid multiple increases
						_customerObj.addTime();
					}
				}
			}
		}
	}
	
	if (Utility::debug) {
		_debug.setTime(_customerObj.getTimeLeft());
		_debug.setTimeLimit(_customerObj.getTimeLimit());
		_debug.setCustomerSpawnPosition(_customerObj.getSpawnPosition());
		_debug.setCustomerOrderValue(_customerObj.getOrderedFoodItem());
		
		if (normalMode) {
			_debug.setLevelTimerValue(levelTimer.getClockTime());
		}
	} else {
		if (normalMode) {
			_debug.setLevelTimerValue(levelTimer.getClockTime());
		}
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

	if (_waitressObj.hasTakenFoodFromCounter()) {
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
	
	
	if (_customerObj.getSpawnPosition() == _menuSystem.TOP_LEFT) {
		if (_waitress->getXPos() + _waitress->getWidth() >= _topLeftBackground.getX() && _waitress->getXPos() <= _topLeftBackground.getX() + _topLeftBackground.getXEndPoint()) {
			if (_waitress->getYPos() + _waitress->getHeight() >= _topLeftBackground.getY() && _waitress->getYPos() <= _topLeftBackground.getY() + _topLeftBackground.getYEndPoint()) {
				if (_customerObj.orderIsTaken()) {
					if (_waitressObj.hasTakenFoodFromCounter()) {
						if (!_customerObj.foodIsServed()) {
							_customerObj.getServed();
							
							if (_customerObj.getOrderedFoodItem() == _menuSystem.getFoodCode()) {
								_waitressObj.setCorrectOrderFlag();
								_customerObj.setAsSuccessful();
							} else {
								_customerObj.setAsFailure();
							}
						}
					}
				} else {
					_customerObj.order();
				}
			}
		}
	}
	
	if (_customerObj.getSpawnPosition() == _menuSystem.TOP_RIGHT) {
		if (_waitress->getXPos() + _waitress->getWidth() >= _topRightBackground.getX() && _waitress->getXPos() <= _topRightBackground.getX() + _topRightBackground.getXEndPoint()) {
			if (_waitress->getYPos() + _waitress->getHeight() >= _topRightBackground.getY() && _waitress->getYPos() <= _topRightBackground.getY() + _topRightBackground.getYEndPoint()) {
				printf("test\n");
				if (_customerObj.orderIsTaken()) {
					if (_waitressObj.hasTakenFoodFromCounter()) {
						if (!_customerObj.foodIsServed()) {
							_customerObj.getServed();
							
							if (_customerObj.getOrderedFoodItem() == _menuSystem.getFoodCode()) {
								_waitressObj.setCorrectOrderFlag();
								_customerObj.setAsSuccessful();
							} else {
								_customerObj.setAsFailure();
							}
						}
					}
				} else {
					_customerObj.order();
				}
			}
		}
	}
	
	if (_customerObj.getSpawnPosition() == _menuSystem.BOTTOM_LEFT) {
		if (_waitress->getXPos() + _waitress->getWidth() >= _bottomLeftBackground.getX() && _waitress->getXPos() <= _bottomLeftBackground.getX() + _bottomLeftBackground.getXEndPoint()) {
			if (_waitress->getYPos() + _waitress->getHeight() >= _bottomLeftBackground.getY() && _waitress->getYPos() <= _bottomLeftBackground.getY() + _bottomLeftBackground.getYEndPoint()) {
				if (_customerObj.orderIsTaken()) {
					if (_waitressObj.hasTakenFoodFromCounter()) {
						if (!_customerObj.foodIsServed()) {
							_customerObj.getServed();
							
							if (_customerObj.getOrderedFoodItem() == _menuSystem.getFoodCode()) {
								_waitressObj.setCorrectOrderFlag();
								_customerObj.setAsSuccessful();
							} else {
								_customerObj.setAsFailure();
							}
						}
					}
				} else {
					_customerObj.order();
				}
			}
		}
	}
	
	if (_customerObj.getSpawnPosition() == _menuSystem.BOTTOM_RIGHT) {
		if (_waitress->getXPos() + _waitress->getWidth() >= _bottomRightBackground.getX() && _waitress->getXPos() <= _bottomRightBackground.getX() + _bottomRightBackground.getXEndPoint()) {
			if (_waitress->getYPos() + _waitress->getHeight() >= _bottomRightBackground.getY() && _waitress->getYPos() <= _bottomRightBackground.getY() + _bottomRightBackground.getYEndPoint()) {
				if (_customerObj.orderIsTaken()) {
					if (_waitressObj.hasTakenFoodFromCounter()) {
						if (!_customerObj.foodIsServed()) {
							_customerObj.getServed();
							
							if (_customerObj.getOrderedFoodItem() == _menuSystem.getFoodCode()) {
								_waitressObj.setCorrectOrderFlag();
								_customerObj.setAsSuccessful();
							} else {
								_customerObj.setAsFailure();
							}
						}
					}
				} else {
					_customerObj.order();
				}
			}
		}
	}

	
	// food pickup mechanism
	if (_waitress->getXPos() + _waitress->getWidth() >= _foodPickupBackground.getX() && _waitress->getXPos() <= _foodPickupBackground.getX() + _foodPickupBackground.getXEndPoint()) {
		if (_waitress->getYPos() + _waitress->getHeight() >= _counter.getYPos()) { // using counter is way more effective than food pickup background
			if (_customerObj.orderIsTaken() && _waitressObj.hasPickedOrderFromMenu()) {
				if (!_chefObj.isCooking()) {
					_chefObj.cook();
				} else if (_chefObj.isDoneCooking()) {
					_waitressObj.takeFoodFromCounter();
				}
			}
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
	_waitress->handleCollisionWithWindow();
	_waitress->handleCollisionWith(_counter);
	
	if (_waitressObj.hasTakenFoodFromCounter() && !_waitressObj.gotCorrectOrder()) {
		if (_waitress->handleCollisionWith(_topWalkingCustomerObj) || _waitress->handleCollisionWith(_bottomWalkingCustomerObj)) {
			_customerObj.spawn();
			_topWalkingCustomer->positionSprite(20, 100);
			_waitressObj.serveANewCustomer();
			_chefObj.getReadyToCook();
			_customerObj.setAsFailure();
		}
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
	
	_lsBackToMenuButton.render(window);
	
	_waitress->render(window);
	_customer->render(window);
	
	if (_waitressObj.hasTakenFoodFromCounter() && !_customerObj.foodIsServed()) {
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
	
	if (!_customerObj.orderIsTaken()) {
		_customerObj.renderOrderPopup(window);
	} else {
		if (_customerObj.foodIsServed()) {
			if (_waitressObj.gotCorrectOrder()) {
				_customerObj.renderFood(window);
				_customerObj.renderThanksPopup(window);
			} else {
				_customerObj.renderWrongOrderPopup(window);
			}
		} else {
			_customerObj.renderFoodOrderPopup(window);
		}
	}
	
	if (_chefObj.isCooking() && !_chefObj.isDoneCooking()) {
		_chefObj.renderSmoke(window);
	}
	
	_menuSystem.render(window);
	
	if (Utility::debug) {
		_debug.show(window);
	} else {
		_debug.showNonDebugFlags(window);
	}
	
	window.display();
}