//
//  LevelScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include <math.h>
#include "LevelScreen.h"

//static Thread fpsThread(LevelScreen::startFPSTimer);
static Clock clockObj;
static Clock *clockPointer;
static Time startTime;
static Time endTime;
static float frames;
static float fps;
static bool timerStart;
static bool changeState;

// no need for gender booleans since
// both flags use the same variable
static bool isTopLeftCustomer;
static bool isTopRightCustomer;
static bool isBottomLeftCustomer;
static bool isBottomRightCustomer;

static bool topLeftCustomerDone;
static bool topRightCustomerDone;
static bool bottomLeftCustomerDone;
static bool bottomRightCustomerDone;

static bool customerTimerStart;

static Thread customerThread(LevelScreen::startCustomerTimer);

LevelScreen::LevelScreen() {
	srand((int)time(NULL));
	// rand() % 4 + 1
	
	_randomTable = 0;
	_randomCustomer = 0;
	clockPointer = &clockObj;
	
	// checks customer coordinates
	isTopLeftCustomer = false;
	isTopRightCustomer = false;
	isBottomLeftCustomer = false;
	isBottomRightCustomer = false;
	
	// handles customer spawning
	topLeftCustomerDone = true; // start off
	topRightCustomerDone = false;
	bottomLeftCustomerDone = false;
	bottomRightCustomerDone = false;

	// assign sprites
	_waitress = &_waitressObj;
	
	_topLeftTable = &_topLeftTableObj;
	_topLeftCustomer = &_topLeftCustomerObj;
	_topLeftCoordinate = &_topLeftCoordinateObj;
	
	_topRightTable = &_topRightTableObj;
	_topRightCustomer = &_topRightCustomerObj;
	_topRightCoordinate = &_topRightCoordinateObj;
	
	_bottomLeftTable = &_bottomLeftTableObj;
	_bottomLeftCustomer = &_bottomLeftCustomerObj;
	_bottomLeftCoordinate = &_bottomLeftCoordinateObj;
	
	_bottomRightTable = &_bottomRightTableObj;
	_bottomRightCustomer = &_bottomRightCustomerObj;
	_bottomRightCoordinate = &_bottomRightCoordinateObj;
	
	_counter = &_counterObj;
	_chef = &_chefObj;
	_stove = &_stoveObj;
	
	// load and position sprites
	_waitress->loadSprite("waitress.bmp");
	_waitress->cropSprite(450, 10, 400, 690, 0.1, 0.1);
	_waitress->positionSprite(10, 10); // position front sprite first since it appears first
	
	_topLeftTable->loadSprite("table.bmp"); // top left table
	_topLeftTable->cropSprite(300, 10, 600, 700, 0.1, 0.1);
	_topLeftTable->positionSprite(80, 50);
	
	_topRightTable->loadSprite("table.bmp"); // top right table
	_topRightTable->cropSprite(300, 10, 600, 700, 0.1, 0.1);
	_topRightTable->positionSprite(400, 50);
	
	_bottomLeftTable->loadSprite("table.bmp"); // bottom left table
	_bottomLeftTable->cropSprite(300, 10, 600, 700, 0.1, 0.1);
	_bottomLeftTable->positionSprite(80, 200);
	
	_bottomRightTable->loadSprite("table.bmp"); // bottom right table
	_bottomRightTable->cropSprite(300, 10, 600, 700, 0.1, 0.1);
	_bottomRightTable->positionSprite(400, 200);
	
	_counter->loadSprite("counter.bmp");
	_counter->cropSprite(0, 200, SCREEN_W, 50, 1.0, 1.0); // adjust counter height by 4th parameter
	_counter->positionSprite(0, 330);
	
	_chef->loadSprite("chef.bmp");
	_chef->cropSprite(450, 10, 400, 690, 0.15, 0.15);
	_chef->positionSprite(450, 380);
	_stove->loadSprite("stove.bmp");
	_stove->cropSprite(450, 10, 550, 650, 0.12, 0.12);
	_stove->positionSprite(SCREEN_W - _stove->getSpriteWidth() - 50, 400);
	
	// set mouse position to sprite position to initialise
	_mouseXPos = _waitress->getSpriteXPos();
	_mouseYPos = _waitress->getSpriteYPos();
	
#if DEBUG_MODE == 1
	_mouseXPosDebug = &_mouseXPosDebugObj;
	_mouseXPosDebug->setText("Mouse X-Pos: ", 15);
	_mouseXPosDebug->setTextPosition(10, 150, 10);
	
	_mouseYPosDebug = &_mouseYPosDebugObj;
	_mouseYPosDebug->setText("Mouse Y-Pos: ", 15);
	_mouseYPosDebug->setTextPosition(10, 150, 50);
	
	_fpsDebug = &_fpsDebugObj;
	_fpsDebug->setText("FPS: ", 15);
	_fpsDebug->setTextPosition(10, 150, 90);
	
	_topLeftBackground = &_topLeftBackgroundObj;
	_topLeftBackground->drawBackground(255, 0, 0);
	_topLeftBackground->setBackgroundPosition(0, 0, SCREEN_W / 2, 165);
	
	_topRightBackground = &_topRightBackgroundObj;
	_topRightBackground->drawBackground(0, 255, 0);
	_topRightBackground->setBackgroundPosition(SCREEN_W / 2, 0, SCREEN_W / 2, 165);
	
	_bottomLeftBackground = &_bottomLeftBackgroundObj;
	_bottomLeftBackground->drawBackground(0, 0, 255);
	_bottomLeftBackground->setBackgroundPosition(0, 165, SCREEN_W / 2, 165);
	
	_bottomRightBackground = &_bottomRightBackgroundObj;
	_bottomRightBackground->drawBackground(100, 100, 0);
	_bottomRightBackground->setBackgroundPosition(320, 165, SCREEN_W / 2, 165);
	
	_bottomBackground = &_bottomBackgroundObj;
	_bottomBackground->drawBackground(0, 100, 100);
	_bottomBackground->setBackgroundPosition(0, 330, SCREEN_W, 150);
	
	_spriteXPosDebug = &_spriteXPosDebugObj;
	_spriteXPosDebug->setText("Sprite X Pos: ", 15);
	_spriteXPosDebug->setTextPosition(10, 150, 130);
	
	_spriteYPosDebug = &_spriteYPosDebugObj;
	_spriteYPosDebug->setText("Sprite Y Pos: ", 15);
	_spriteYPosDebug->setTextPosition(10, 150, 160);
#endif

	//fpsThread.launch();
	
	customerTimerStart = false;
	customerThread.launch();
}

void LevelScreen::handleEvent() {
	timerStart = true;
	
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			changeState = true;
		
			cleanup();
		
			setState(EXIT);
		}
		
		if (event.type == event.MouseMoved) {
#if DEBUG_MODE == 1
			_mouseXPosDebug->setValue(event.mouseMove.x, 15);
			_mouseYPosDebug->setValue(event.mouseMove.y, 15);
#endif
		}
		
		if (event.type == event.MouseButtonPressed) {
			_mouseXPos = event.mouseButton.x;
			_mouseYPos = event.mouseButton.y;
#if DEBUG_MODE == 1
			_spriteXPosDebug->setValue(_mouseXPos, 15);
			_spriteYPosDebug->setValue(_mouseYPos, 15);
#endif
		}
	}
}

void LevelScreen::spawnCustomer() {
	// if customer is done
	// generate again to spawn a new customer
	if (!customerTimerStart) {
		if (topLeftCustomerDone || topRightCustomerDone || bottomLeftCustomerDone || bottomRightCustomerDone) {
			customerTimerStart = true;
		
			_randomTable = rand() % 4 + 1;
			_randomCustomer = rand() % 2 + 1;
			printf("Random table: %d\n", _randomTable);
			printf("Random customer: %d\n", _randomCustomer);
			
			if (_randomTable == TOP_LEFT_COORDINATE) {
				// flags to keep from repeating code in render
				isTopLeftCustomer = true;
				isTopRightCustomer = false;
				isBottomLeftCustomer = false;
				isBottomRightCustomer = false;
				
				if (_randomCustomer == BOY_CUSTOMER) {
					_topLeftCustomer->loadSprite("boy_customer.bmp");
					_topLeftCustomer->cropSprite(450, 10, 400, 690, 0.13, 0.13);
					_topLeftCustomer->positionSprite(_topLeftCoordinate->x, _topLeftCoordinate->y);
				}
				
				if (_randomCustomer == GIRL_CUSTOMER) {
					_topLeftCustomer->loadSprite("girl_customer.bmp");
					_topLeftCustomer->cropSprite(450, 10, 400, 690, 0.13, 0.13);
					_topLeftCustomer->positionSprite(_topLeftCoordinate->x, _topLeftCoordinate->y);
				}
			}
			
			if (_randomTable == TOP_RIGHT_COORDINATE) {
				isTopLeftCustomer = false;
				isTopRightCustomer = true;
				isBottomLeftCustomer = false;
				isBottomRightCustomer = false;
				
				if (_randomCustomer == BOY_CUSTOMER) {
					_topRightCustomer->loadSprite("boy_customer.bmp");
					_topRightCustomer->cropSprite(450, 10, 400, 690, 0.13, 0.13);
					_topRightCustomer->positionSprite(_topRightCoordinate->x, _topRightCoordinate->y);
				}
				
				if (_randomCustomer == GIRL_CUSTOMER) {
					_topRightCustomer->loadSprite("girl_customer.bmp");
					_topRightCustomer->cropSprite(450, 10, 400, 690, 0.13, 0.13);
					_topRightCustomer->positionSprite(_topRightCoordinate->x, _topRightCoordinate->y);
				}
			}
			
			if (_randomTable == BOTTOM_LEFT_COORDINATE) {
				isTopLeftCustomer = false;
				isTopRightCustomer = false;
				isBottomLeftCustomer = true;
				isBottomRightCustomer = false;
			
				if (_randomCustomer == BOY_CUSTOMER) {
					_bottomLeftCustomer->loadSprite("boy_customer.bmp");
					_bottomLeftCustomer->cropSprite(450, 10, 400, 690, 0.13, 0.13);
					_bottomLeftCustomer->positionSprite(_bottomLeftCoordinate->x, _bottomLeftCoordinate->y);
				}
				
				if (_randomCustomer == GIRL_CUSTOMER) {
					_bottomLeftCustomer->loadSprite("girl_customer.bmp");
					_bottomLeftCustomer->cropSprite(450, 10, 400, 690, 0.13, 0.13);
					_bottomLeftCustomer->positionSprite(_bottomLeftCoordinate->x, _bottomLeftCoordinate->y);
				}
			}
			
			if (_randomTable == BOTTOM_RIGHT_COORDINATE) {
				isTopLeftCustomer = false;
				isTopRightCustomer = false;
				isBottomLeftCustomer = false;
				isBottomRightCustomer = true;
			
				if (_randomCustomer == BOY_CUSTOMER) {
					_bottomRightCustomer->loadSprite("boy_customer.bmp");
					_bottomRightCustomer->cropSprite(450, 10, 400, 690, 0.13, 0.13);
					_bottomRightCustomer->positionSprite(_bottomRightCoordinate->x, _bottomRightCoordinate->y);
				}
				
				if (_randomCustomer == GIRL_CUSTOMER) {
					_bottomRightCustomer->loadSprite("girl_customer.bmp");
					_bottomRightCustomer->cropSprite(450, 10, 400, 690, 0.13, 0.13);
					_bottomRightCustomer->positionSprite(_bottomRightCoordinate->x, _bottomRightCoordinate->y);
				}
			}
		}
	}
}

void LevelScreen::moveCharacter() {
	if (_waitress->getSpriteXPos() >= _mouseXPos) {
		_waitress->moveSpriteLeft();
	}

	if (_waitress->getSpriteXPos() <= _mouseXPos) {
		_waitress->moveSpriteRight();
	}
	
	if (_waitress->getSpriteYPos() >= _mouseYPos) {
		_waitress->moveSpriteUp();
	}

	if (_waitress->getSpriteYPos() <= _mouseYPos) {
		_waitress->moveSpriteDown();
	}
}

void LevelScreen::checkCollision() {
	// check collision with window
	if (_waitress->getSpriteXPos() + _waitress->getSpriteWidth() >= SCREEN_W) {
		_waitress->positionSprite(SCREEN_W - _waitress->getSpriteWidth(), _waitress->getSpriteYPos());
	}

	if (_waitress->getSpriteYPos() + _waitress->getSpriteHeight() >= _counter->getSpriteYPos()) {
		_waitress->positionSprite(_waitress->getSpriteXPos(), _counter->getSpriteYPos() - _waitress->getSpriteHeight());
	}
}

void LevelScreen::update() {
#if DEBUG_MODE == 1
	window.clear();
#else
	window.clear(color.White);
#endif

	timerStart = false;
	
#if DEBUG_MODE == 1
	_fpsDebug->setValue(fps, 15);
#endif
}

void LevelScreen::render() {
#if DEBUG_MODE == 1
	window.draw(*_topLeftBackground->getBackground());
	window.draw(*_topRightBackground->getBackground());
	window.draw(*_bottomLeftBackground->getBackground());
	window.draw(*_bottomRightBackground->getBackground());
	window.draw(*_bottomBackground->getBackground());

	window.draw(*_mouseXPosDebug->getText());
	window.draw(*_mouseXPosDebug->getValue());
	
	window.draw(*_mouseYPosDebug->getText());
	window.draw(*_mouseYPosDebug->getValue());
	
	window.draw(*_fpsDebug->getText());
	window.draw(*_fpsDebug->getValue());
	
	window.draw(*_spriteXPosDebug->getText());
	window.draw(*_spriteXPosDebug->getValue());
	
	window.draw(*_spriteYPosDebug->getText());
	window.draw(*_spriteYPosDebug->getValue());
#endif

	window.draw(*_waitress->getSprite());
	
	window.draw(*_topLeftTable->getSprite());
	if (isTopLeftCustomer) {
		window.draw(*_topLeftCustomer->getSprite());
	}
	
	window.draw(*_topRightTable->getSprite());
	if (isTopRightCustomer) {
		window.draw(*_topRightCustomer->getSprite());
	}
	
	window.draw(*_bottomLeftTable->getSprite());
	if (isBottomLeftCustomer) {
		window.draw(*_bottomLeftCustomer->getSprite());
	}
	
	window.draw(*_bottomRightTable->getSprite());
	if (isBottomRightCustomer) {
		window.draw(*_bottomRightCustomer->getSprite());
	}
	
	window.draw(*_counter->getSprite());
	window.draw(*_chef->getSprite());
	window.draw(*_stove->getSprite());

	window.display();
}
/*
void LevelScreen::startFPSTimer() {
#if DEBUG_MODE == 1
	//int i = 0;
#endif

	while (!changeState) {
		// let this run
		// putting an if statement on this causes FPS to go haywire
		// issue fixed
		startTime = clockPointer->getElapsedTime();
		
		if (!timerStart) {
			endTime = clockPointer->getElapsedTime();
			++frames;
			
			fps = frames / (clockPointer->getElapsedTime().asMilliseconds() / 1000);
			
			// if frame finishes early
			if ((endTime.asMilliseconds() - startTime.asMilliseconds()) < (1000 / 60)) {
				sleep(milliseconds((1000 / 60) - (endTime.asMilliseconds() - startTime.asMilliseconds())));
			}
		}
#if DEBUG_MODE == 1
		//++i;
		//printf("%d\n", i);
#endif
	}
}
*/

void LevelScreen::startCustomerTimer() {
	Clock clock;
	
	while (!changeState) {
		// 10s
		while (customerTimerStart) {
			if (changeState) {
				break;
			}
		
			//printf("%d\n", clock.getElapsedTime().asMilliseconds());
		
			if (clock.getElapsedTime().asMilliseconds() >= 10000) {
				customerTimerStart = false;
			}
		}
		
		while (!customerTimerStart) {
			clock.restart();
		
			if (isTopLeftCustomer) {
				topLeftCustomerDone = true;
				topRightCustomerDone = false;
				bottomLeftCustomerDone = false;
				bottomRightCustomerDone = false;
				break;
			}
			
			if (isTopRightCustomer) {
				topLeftCustomerDone = false;
				topRightCustomerDone = true;
				bottomLeftCustomerDone = false;
				bottomRightCustomerDone = false;
				break;
			}
			
			if (isBottomLeftCustomer) {
				topLeftCustomerDone = false;
				topRightCustomerDone = false;
				bottomLeftCustomerDone = true;
				bottomRightCustomerDone = false;
				break;
			}
			
			if (isBottomRightCustomer) {
				topLeftCustomerDone = false;
				topRightCustomerDone = false;
				bottomLeftCustomerDone = false;
				bottomRightCustomerDone = true;
				break;
			}
		}
	}
}