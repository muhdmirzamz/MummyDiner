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
	_howToPlayBackground.setBackgroundUsingName("_howToPlayBackground");
	
	_howToPlayScreenTitle.setTextUsingName("_howToPlayScreenTitle", "How To Play");
	
	_customerOrderImage.setImageUsingName("_customerOrderImage");
	_customerOrderText.setTextUsingName("_customerOrderText", "Click on customer to take order");
	
	_menuPickImage.setImageUsingName("_menuPickImage");
	_menuPickText.setTextUsingName("_menuPickText", "Click on the food item \nbased on customer order");
	
	_greyPatchImage.setImageUsingName("_greyPatchImage");
	_greyPatchText.setTextUsingName("_greyPatchText", "Click on grey patch to go there\nand pass order to chef");
	
	_chefCookImage.setImageUsingName("_chefCookImage");
	_chefCookText.setTextUsingName("_chefCookText", "This smoke indicates chef is cooking\nWhen it disappears, chef is done cooking");
	
	_serveImage.setImageUsingName("_serveImage");
	_serveText.setTextUsingName("_serveText", "Click on customer to serve food");
	
	_customerThanksImage.setImageUsingName("_customerThanksImage");
	_customerThanksText.setTextUsingName("_customerThanksText", "You have successfully served the customer\nif this popup appears");
	
	_nextButton.setButtonUsingName("_nextButton", "Next");
	_prevButton.setButtonUsingName("_prevButton", "Previous");
	_backButton.setButtonUsingName("_backButton", "Back to \nmain menu");
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
			if (_backButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
				cleanup();
				
				setState(MAIN_MENU);
			}
			
			if (_nextButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
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
			
			if (_prevButton.isClicked(MOUSE_X_CLICK, MOUSE_Y_CLICK)) {
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

void HowToPlayScreen::update() {
	window.clear();
}

void HowToPlayScreen::render() {
	_howToPlayBackground.render(window);
	
	_howToPlayScreenTitle.render(window);
	
	if (_firstPage) {
		_customerOrderImage.renderImage(window);
		_customerOrderText.render(window);
		_menuPickImage.renderImage(window);
		_menuPickText.render(window);
		
		_nextButton.render(window);
	}
	
	if (_secondPage) {
		_greyPatchImage.renderImage(window);
		_greyPatchText.render(window);
		_chefCookImage.renderImage(window);
		_chefCookText.render(window);
	
		_nextButton.render(window);
		_prevButton.render(window);
	}
	
	if (_thirdPage) {
		_serveImage.renderImage(window);
		_serveText.render(window);
		_customerThanksImage.renderImage(window);
		_customerThanksText.render(window);
	
		_prevButton.render(window);
	}
	
	_backButton.render(window);
	
	window.display();
}