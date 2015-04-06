//
//  HowToPlayScreen.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 29/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "HowToPlayScreen.h"

HowToPlayScreen::HowToPlayScreen() {
	_firstPage = true;
	_secondPage = false;
	_thirdPage = false;

	// load everything first
	_background.set(0, 0, SCREEN_W, SCREEN_H, 20, 200, 180);
	
	_title.set(QUICKSAND_REGULAR_FONT, 30, "HOW TO PLAY", SCREEN_W / 3, 30, 10, 100, 255);
	
	_customerOrder.setImage("images/customer_order.png");
	_customerOrder.setScale(0.6, 0.6);
	_customerOrder.setPosition(160, 150);
	_customerOrderText.set(LATO_LIGHT_FONT, 20, "Click on customer to take order", 380, 150, 0, 0, 0);
	
	_menuPick.setImage("images/menu_pick.png");
	_menuPick.setScale(0.6, 0.6);
	_menuPick.setPosition(160, 380);
	_menuPickText.set(LATO_LIGHT_FONT, 20, "Click on the food item \nbased on customer order", 380, 380, 0, 0, 0);
	
	
	_greyPatch.setImage("images/grey_patch.png");
	_greyPatch.setScale(0.6, 0.6);
	_greyPatch.setPosition(160, 150);
	_greyPatchText.set(LATO_LIGHT_FONT, 20, "Click on grey patch to go there\nand pass order to chef", 400, 150, 0, 0, 0);
	
	_chefCook.setImage("images/chef_cook.png");
	_chefCook.setScale(0.6, 0.6);
	_chefCook.setPosition(160, 380);
	_chefCookText.set(LATO_LIGHT_FONT, 20, "This smoke indicates chef is cooking\nWhen it disappears, chef is done cooking", 300, 380, 0, 0, 0);
	
	
	_serve.setImage("images/serve.png");
	_serve.setScale(0.6, 0.6);
	_serve.setPosition(160, 150);
	_serveText.set(LATO_LIGHT_FONT, 20, "Click on customer to serve food", 380, 150, 0, 0, 0);
	
	_customerThanks.setImage("images/customer_thanks.png");
	_customerThanks.setScale(0.6, 0.6);
	_customerThanks.setPosition(160, 380);
	_customerThanksText.set(LATO_LIGHT_FONT, 20, "You have successfully served the customer\nif this popup appears", 380, 380, 0, 0, 0);
	
	_nextButton.set(SCREEN_W - 100, SCREEN_H / 2, 100, 50, 255, 255, 255, "Next", 0, 0, 0);
	_prevButton.set(0, SCREEN_H / 2, 100, 50, 255, 255, 255, "Previous", 0, 0, 0);
	
	_backButton.set(10, 10, 150, 80, 0, 150, 255, "Back to \nmain menu", 0, 0, 0);
}

void HowToPlayScreen::handleEvent() {
	while (window.pollEvent(event)) {
		if (event.type == event.Closed) {
			cleanup();
			
			setState(EXIT);
		}
		
		if (Utility::debug) {
			if (event.type == event.KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					cleanup();
					
					setState(EXIT);
				}
			}
		}
		
		if (event.type == event.MouseButtonPressed) {
			if (MOUSE_X_CLICK >= _backButton.getLeftSide() && MOUSE_X_CLICK <= _backButton.getWidth()) {
				if (MOUSE_Y_CLICK >= _backButton.getTop() && MOUSE_Y_CLICK <= _backButton.getHeight()) {
					cleanup();
					
					setState(MAIN_MENU);
				}
			}
			
			if (MOUSE_X_CLICK >= _nextButton.getLeftSide() && MOUSE_X_CLICK <= _nextButton.getLeftSide() + _nextButton.getWidth()) {
				if (MOUSE_Y_CLICK >= _nextButton.getTop() && MOUSE_Y_CLICK <= _nextButton.getTop() + _nextButton.getHeight()) {
					if (_secondPage) {
						_firstPage = false;
						_secondPage = false;
						_thirdPage = true;
					} else {
						_firstPage = false;
						_secondPage = true;
						_thirdPage = false;
					}
				}
			}
			
			if (MOUSE_X_CLICK >= _prevButton.getLeftSide() && MOUSE_X_CLICK <= _prevButton.getLeftSide() + _prevButton.getWidth()) {
				if (MOUSE_Y_CLICK >= _prevButton.getTop() && MOUSE_Y_CLICK <= _prevButton.getTop() + _prevButton.getHeight()) {
					if (_thirdPage) {
						_firstPage = false;
						_secondPage = true;
						_thirdPage = false;
					} else {
						_firstPage = true;
						_secondPage = false;
						_thirdPage = false;
					}
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
	
	if (_firstPage) {
		_customerOrder.renderImage(window);
		_customerOrderText.render(window);
		_menuPick.renderImage(window);
		_menuPickText.render(window);
		
		_nextButton.render(window);
	}
	
	if (_secondPage) {
		_greyPatch.renderImage(window);
		_greyPatchText.render(window);
		_chefCook.renderImage(window);
		_chefCookText.render(window);
	
		_nextButton.render(window);
		_prevButton.render(window);
	}
	
	if (_thirdPage) {
		_serve.renderImage(window);
		_serveText.render(window);
		_customerThanks.renderImage(window);
		_customerThanksText.render(window);
	
		_prevButton.render(window);
	}
	
	_backButton.render(window);
	
	window.display();
}