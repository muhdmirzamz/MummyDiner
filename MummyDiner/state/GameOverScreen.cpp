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
	
	window.display();
}