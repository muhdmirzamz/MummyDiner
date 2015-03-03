//
//  GameState.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "GameState.h"

GameState::GameState() {
	window.create(VideoMode(SCREEN_W, SCREEN_H), "MummyDiner");
	
	_tempState = NO_STATE;
}

GameState::~GameState() {

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