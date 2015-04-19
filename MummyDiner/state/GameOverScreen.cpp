//
//  GameOverScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 28/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "GameOverScreen.h"

bool GameOverScreen::success = false;
bool GameOverScreen::neutral = false;

GameOverScreen::GameOverScreen() {
	if (success) {
		_successGameOverBackground.setBackgroundUsingName("_successGameOverBackground");
	} else if (neutral) {
		_neutralGameOverBackground.setBackgroundUsingName("_neutralGameOverBackground");
	} else {
		_failGameOverBackground.setBackgroundUsingName("_failGameOverBackground");
	}
	
	if (Utility::debug) {
		_debug.set();
	}
}

void GameOverScreen::handleEvent() {
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanupGameOverScreen(EXIT);
		}
		
		if (event.type == event.KeyPressed) {
			if (event.key.code == Keyboard::C) {
				cleanupGameOverScreen(MAIN_MENU);
			}
		}
		
		if (Utility::debug) {
			if (event.type == event.MouseMoved) {
				_debug.setMousePosition(MOUSE_X, MOUSE_Y);
			}
		}
		
		if (event.type == event.MouseButtonPressed) {
			if (MOUSE_Y_CLICK >= 340 && MOUSE_Y_CLICK <= 590) {
				if (MOUSE_X_CLICK >= 10 && MOUSE_X_CLICK <= 330) {
					cleanupGameOverScreen(MAIN_MENU);
				}
				
				if (MOUSE_X_CLICK >= 430 && MOUSE_X_CLICK <= 780) {
					cleanupGameOverScreen(LEVEL);
				}
			}
		}
	}
}

void GameOverScreen::update() {
	window.clear();
}

void GameOverScreen::render() {
	if (success) {
		_successGameOverBackground.render(window);
	} else if (neutral) {
		_neutralGameOverBackground.render(window);
	} else {
		_failGameOverBackground.render(window);
	}

	if (Utility::debug) {
		_debug.show(window);
	}
	
	window.display();
}

void GameOverScreen::cleanupGameOverScreen(int state) {
	cleanup();
	
	setState(state);
}