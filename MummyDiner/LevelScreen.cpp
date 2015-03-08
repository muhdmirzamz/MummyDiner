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

static FramesPerSecond _fps;

#define TABLE_CROP_SETTINGS 300, 10, 600, 700

LevelScreen::LevelScreen() {
	_waitress = &_waitressObj;
	_waitress->set("images/waitress.bmp", 450, 10, 400, 690, 10, 10);
	_chef = &_chefObj;
	_chef->set("images/chef.bmp", 450, 10, 400, 690, 450, 380);
	
	_topLeftTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 80, 50);
	_topRightTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 400, 50);
	_bottomLeftTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 80, 200);
	_bottomRightTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 400, 200);
	_counter.set("images/counter.bmp", 0, 200, SCREEN_W, 50, 0, 330);
	_stove.set("images/stove.bmp", 450, 10, 550, 650, SCREEN_W - _stove.getWidth() - 50, 400);
	
	// set mouse position to waitress position to initialise
	_mouseXPos = _waitress->getXPos();
	_mouseYPos = _waitress->getYPos();
	
#if DEBUG_MODE == 1
	_debug.set();
#endif
}

void LevelScreen::handleEvent() {
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanup();
		
			setState(EXIT);
		}
		
		if (event.type == event.MouseMoved) {
#if DEBUG_MODE == 1
			// mouse position
#endif
		}
		
		if (event.type == event.MouseButtonPressed) {
			
			_mouseXPos = event.mouseButton.x;
			_mouseYPos = event.mouseButton.y;
#if DEBUG_MODE == 1
		// sprite position
#endif
		}
	}
}

void LevelScreen::spawnCustomer() {

}

void LevelScreen::moveCharacter() {
	if (_waitress->getXPos() >= _mouseXPos) {
		_waitress->moveLeft();
	}

	if (_waitress->getXPos() <= _mouseXPos) {
		_waitress->moveRight();
	}
	
	if (_waitress->getYPos() >= _mouseYPos) {
		_waitress->moveUp();
	}

	if (_waitress->getYPos() <= _mouseYPos) {
		_waitress->moveDown();
	}
}

void LevelScreen::checkCollision() {
	_waitress->handleWindowCollision();
}

void LevelScreen::update() {
#if DEBUG_MODE == 1
	_debug.setFPSValue(_fps.getFPS());
#endif

	window.clear(color.White);
}

void LevelScreen::render() {
#if DEBUG_MODE == 1
	_debug.show(window);
#endif

	_waitress->render(window);
	// render customer
	_chef->render(window);
	
	_topLeftTable.render(window);
	_topRightTable.render(window);
	_bottomLeftTable.render(window);
	_bottomRightTable.render(window);
	_counter.render(window);
	_stove.render(window);

	window.display();
}