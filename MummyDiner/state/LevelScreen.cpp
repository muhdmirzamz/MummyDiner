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
	_waitress->set("images/waitress.bmp", 450, 10, 400, 690, 10, 10);
	_chef = &_chefObj;
	_chef->set("images/chef.bmp", 450, 10, 400, 700, 500, 375, 0.15, 0.15);
	
	_topLeftTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 80, 50);
	_topRightTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 400, 50);
	_bottomLeftTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 80, 200);
	_bottomRightTable.set("images/table.bmp", TABLE_CROP_SETTINGS, 400, 200);
	_counter.set("images/counter.bmp", 0, 200, SCREEN_W, 40, 0, 330, 1.0, 1.0);
	_stove.set("images/stove.bmp", 450, 10, 550, 650, SCREEN_W - _stove.getWidth() - 70, 400);
	
	// use different variables for setting sprite's next position
	// not using the variables used for tracking mouse position
	_mouseClickX = _waitress->getXPos();
	_mouseClickY = _waitress->getYPos();
	
#if DEBUG_MODE == 1
	_debug.set();
#endif
	
	fpsThread.launch();
}

void LevelScreen::handleEvent() {
	fps.hasReachedStartOfFrame();

	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
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
			
#if DEBUG_MODE == 1
			_debug.setSpritePosition(_mouseClickX, _mouseClickY);
#endif
		}
	}
}

void LevelScreen::spawnCustomer() {
	
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