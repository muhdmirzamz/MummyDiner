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
		if (neutral) {
			_neutralGameOverBackground.setImageBackground("images/neutral_game_over.bmp", 0, 0, SCREEN_W, SCREEN_H);
		} else {
			_successGameOverBackground.setImageBackground("images/success_game_over.bmp", 0, 0, SCREEN_W, SCREEN_H);
		}
	} else {
		_failGameOverBackground.setImageBackground("images/fail_game_over.bmp", 0, 0, SCREEN_W, SCREEN_H);
	}
	
	if (Utility::debug) {
		_debug.set();
	}
}

void GameOverScreen::handleEvent() {
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanup();
			
			setState(EXIT);
		}
		
		if (event.type == event.KeyPressed) {
			if (event.key.code == Keyboard::C) {
				cleanup();
				
				setState(MAIN_MENU);
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
					cleanup();
					
					setState(MAIN_MENU);
				}
				
				if (MOUSE_X_CLICK >= 430 && MOUSE_X_CLICK <= 780) {
					cleanup();
					
					setState(LEVEL);
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
		if (neutral) {
			_neutralGameOverBackground.render(window);
		} else {
			_successGameOverBackground.render(window);
		}
	} else {
		_failGameOverBackground.render(window);
	}

	if (Utility::debug) {
		_debug.show(window);
	}
	
	window.display();
}