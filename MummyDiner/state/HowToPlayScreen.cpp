//
//  HowToPlayScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 29/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "HowToPlayScreen.h"

HowToPlayScreen::HowToPlayScreen() {
	_background.set(0, 0, SCREEN_W, SCREEN_H, 20, 200, 180);
	
	_title.set(QUICKSAND_REGULAR_FONT, 30, "HOW TO PLAY", SCREEN_W / 3, 30, 10, 100, 255);
	
	_instruction.set(LATO_LIGHT_FONT, 20,
					"Click on a customer to take their order\n\nChoose the customer's order at the bottom left of screen\n\nGo to the grey patch for the chef to cook\n\nA smoke icon indicates he is cooking\n\nWait for the smoke to disappear\n\nClick on customer to serve food",
					 30, 150, 255, 255, 255);
	
	_backButton.set(10, 10, 150, 80, 0, 150, 255, "Back to \nmain menu", 0, 0, 0);
}

void HowToPlayScreen::handleEvent() {
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanup();
			
			setState(EXIT);
		}
		
		if (event.type == event.KeyPressed) {
			if (event.key.code == Keyboard::Escape) {
				cleanup();
				
				setState(EXIT);
			}
		}
		
		if (event.type == event.MouseButtonPressed) {
			if (MOUSE_X_CLICK >= _backButton.getLeftSide() && MOUSE_X_CLICK <= _backButton.getWidth()) {
				if (MOUSE_Y_CLICK >= _backButton.getTop() && MOUSE_Y_CLICK <= _backButton.getHeight()) {
					cleanup();
					
					setState(MAIN_MENU);
				}
			}
		}
	}
}

void HowToPlayScreen::update() {
	window.clear();
}

void HowToPlayScreen::render() {
	_background.render(window);
	
	_title.render(window);
	_instruction.render(window);
	
	_backButton.render(window);
	
	window.display();
}