//
//  main.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include <iostream>

#include <SFML/Graphics.hpp>

// game state class already included 
#include "state/MainMenuScreen.h"
#include "state/ModeMenuScreen.h"
#include "state/HowToPlayScreen.h"
#include "state/SettingsScreen.h"
#include "state/LevelScreen.h"
#include "state/GameOverScreen.h"

int main(int argc, const char * argv[]) {
	// state variables declared locally
	int stateID = MAIN_MENU; // set state to main menu
	int nextState = NO_STATE; // set state to NO_STATE
	
	GameState *gameState = new MainMenuScreen();
	
	// while current state is not EXIT, continue looping
	while (stateID != EXIT) {
		gameState->handleEvent();
		
		// if the user wants to change state and not exit
		if (nextState != EXIT) {
			// set next state by fetching it from gameState->getState()
			nextState = gameState->getState();
		}
		
		if (nextState != NO_STATE) {
			if (nextState != EXIT) {
				delete gameState;
			
				switch (nextState) {
					case MAIN_MENU: {
						gameState = new MainMenuScreen();
						break;
					}
					
					case MODE_MENU: {
						gameState = new ModeMenuScreen();
						break;
					}
				
					case HOW_TO_PLAY: {
						gameState = new HowToPlayScreen();
						break;
					}
				
					case SETTINGS: {
						gameState = new SettingsScreen();
						break;
					}
						
					case LEVEL: {
						gameState = new LevelScreen();
						break;
					}
					
					case GAME_OVER: {
						gameState = new GameOverScreen();
						break;
					}
						
					default:
						break;
				}
				
				stateID = nextState;
				nextState = NO_STATE;
			} else {
				// if user wants to exit
				stateID = EXIT;
				nextState = NO_STATE;
			}
		}
		
		gameState->spawnCustomer();
		gameState->moveCharacter();
		gameState->checkCollision();
		
		gameState->update();
		gameState->render();
	}
	
	delete gameState;
	gameState = NULL;
	
    return 0;
}
