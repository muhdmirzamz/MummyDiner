//
//  GameState.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "GameState.h"

GameState::GameState() {
	// check to see if it is the special game over screen state
	if (_tempState != GAME_OVER) {
		window.create(VideoMode(SCREEN_W, SCREEN_H), "MummyDiner");
	}

	_tempState = NO_STATE;
}

GameState::~GameState() {

}

void GameState::createWindow() {
	// manually create a window to avoid creating two windows(every constructor call creates a window)
	// since you already declared an object of GameOverScreen in LevelScreen
	// to access a public variable for passing data
	window.create(VideoMode(SCREEN_W, SCREEN_H), "MummyDiner");
}

void GameState::setState(int state) {
	_tempState = state;
}

int GameState::getState() {
	return _tempState;
}

void GameState::handleEvent() {

}

void GameState::spawnCustomer() {
	
}

void GameState::moveCharacter() {
	
}

void GameState::checkCollision() {
	
}

void GameState::update() {

}

void GameState::render() {

}

void GameState::cleanup() {
	window.close();
}