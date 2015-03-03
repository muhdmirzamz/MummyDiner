//
//  MainMenuScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "MainMenuScreen.h"

const float BUTTON_Y_AXIS = 200;
const float BUTTON_RATIO = 100;
const float TEXT_SIZE = 30;

static Thread fpsThread(MainMenuScreen::startFPSTimer);
static Clock clockObj;
static Clock *clockPointer;
static Time startTime;
static Time endTime;
static float frames;
static float fps;
static bool timerStart;
static bool stateChange;

MainMenuScreen::MainMenuScreen() {
	// title
	_title = &_titleObj;
	_title->setText("Quicksand-Regular.ttf", 80, "MummyDiner", 60, 20);
	_title->setColor(200, 0, 250);

	// start button
	_startButton = &_startButtonObj;
	_startButton->chooseButton(CIRCLE);
	_startButton->setButton(50, BUTTON_Y_AXIS, BUTTON_RATIO);
	_startButton->setColor(200, 0, 0);
	
	// finding out center of start button to place start text
	_horizontalCenterOfButton = _startButton->getLeftOfButton() + (_startButton->getRadius() / 2) + 15;
	_verticalCenterOfButton = _startButton->getTopOfButton() + (_startButton->getRadius() / 2) + 20;
	
	// start text
	_startText = &_startTextObj;
	_startText->setText("Lato-Light.ttf", TEXT_SIZE, "Start", _horizontalCenterOfButton, _verticalCenterOfButton);
	_startText->setColor(255, 255, 255);
	
	// settings button
	_settingsButton = &_settingsButtonObj;
	_settingsButton->chooseButton(CIRCLE);
	_settingsButton->setButton(400, BUTTON_Y_AXIS, BUTTON_RATIO);
	_settingsButton->setColor(200, 0, 0);
	
	// redefine variables to position "settings text"
	_horizontalCenterOfButton = _settingsButton->getLeftOfButton() + (_settingsButton->getRadius() / 2);
	_verticalCenterOfButton = _settingsButton->getTopOfButton() + (_settingsButton->getRadius() / 2) + 20;
	
	// settings text
	_settingsText = &_settingsTextObj;
	_settingsText->setText("Lato-Light.ttf", TEXT_SIZE, "Settings", _horizontalCenterOfButton, _verticalCenterOfButton);
	_settingsText->setColor(255, 255, 255);
	
	//clockPointer = &clockObj;
	clockPointer = &clockObj;
	fps = 0;
	
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
#endif
	
	fpsThread.launch();
}

void MainMenuScreen::handleEvent() {
	timerStart = true;

	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			stateChange = true;
		
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
			if (event.mouseButton.x >= _startButton->getLeftOfButton() && event.mouseButton.x <= _startButton->getRightOfButton()) {
				if (event.mouseButton.y >= _startButton->getTopOfButton() && event.mouseButton.y <= _startButton->getBottomOfButton()) {
					stateChange = true;
				
					cleanup();
					
					setState(LEVEL);
				}
			}
		
			if (event.mouseButton.x >= _settingsButton->getLeftOfButton() && event.mouseButton.x <= _settingsButton->getRightOfButton()) {
				if (event.mouseButton.y >= _settingsButton->getTopOfButton() && event.mouseButton.y <= _settingsButton->getBottomOfButton()) {
					stateChange = true;
				
					cleanup();
				
					setState(SETTINGS);
				}
			}
		}
	}
}

void MainMenuScreen::update() {
	window.clear(color.White);

	timerStart = false;
	
#if DEBUG_MODE == 1
	_fpsDebug->setValue(fps, 15);
#endif
}

void MainMenuScreen::render() {
	window.draw(*_title->getText());
	
	window.draw(*_startButton->getCircleButton());
	window.draw(*_startText->getText());
	
	window.draw(*_settingsButton->getCircleButton());
	window.draw(*_settingsText->getText());
	
#if DEBUG_MODE == 1
	window.draw(*_mouseXPosDebug->getText());
	window.draw(*_mouseXPosDebug->getValue());
	
	window.draw(*_mouseYPosDebug->getText());
	window.draw(*_mouseYPosDebug->getValue());
	
	window.draw(*_fpsDebug->getText());
	window.draw(*_fpsDebug->getValue());
#endif
	
	window.display();
}

void MainMenuScreen::startFPSTimer() {
#if DEBUG_MODE == 1
	int i = 0;
#endif

	while (!stateChange) {
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
		++i;
		printf("%d\n", i);
#endif
	}
}