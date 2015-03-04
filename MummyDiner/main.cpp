//
//  main.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "MainMenuScreen.h"
#include "SettingsScreen.h"
#include "LevelScreen.h"

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
					case MAIN_MENU:
						gameState = new MainMenuScreen();
						break;
				
					case SETTINGS: {
						gameState = new SettingsScreen();
						break;
					}
						
					case LEVEL: {
						gameState = new LevelScreen();
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
