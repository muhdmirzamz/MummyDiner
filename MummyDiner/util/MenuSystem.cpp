//
//  MenuSystem.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 25/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "MenuSystem.h"

MenuSystem::MenuSystem() {

}

void MenuSystem::loadSpriteInPopup() {
	_hamburger.setSpriteUsingName("_hamburger");
	_fries.setSpriteUsingName("_fries");
	_chocolateSmoothie.setSpriteUsingName("_chocolateSmoothie");
	_lemonJuice.setSpriteUsingName("_lemonJuice");
	
	_foodCode = 0;
}

void MenuSystem::loadSpriteInTray() {
	_menuSystemBackground.setBackgroundUsingName("_menuSystemBackground");

	_menuHamburger.setSpriteUsingName("_menuHamburger");
	_menuFries.setSpriteUsingName("_menuFries");
	_menuChocolateSmoothie.setSpriteUsingName("_menuChocolateSmoothie");
	_menuLemonJuice.setSpriteUsingName("_menuLemonJuice");
}

void MenuSystem::positionSpriteInPopup(int x, int y) {
	_hamburger.positionSprite(x, y);
	_fries.positionSprite(x, y);
	_chocolateSmoothie.positionSprite(x, y);
	_lemonJuice.positionSprite(x, y);
}

void MenuSystem::renderFoodAndDrinks(int number, RenderWindow &window) {
	if (number == HAMBURGER) {
		_hamburger.render(window);
	}
	
	if (number == FRIES) {
		_fries.render(window);
	}
	
	if (number == CHOCOLATE_SMOOTHIE) {
		_chocolateSmoothie.render(window);
	}
	
	if (number == LEMON_JUICE) {
		_lemonJuice.render(window);
	}
}

// this is for menu ones, dont confuse them
// TAKE NOTE OF THE VARIABLE NAME
bool MenuSystem::itemIsChosen(int mouseXClick, int mouseYClick) {
	if (mouseYClick >= 400 && mouseYClick <= SCREEN_H) {
		if (mouseXClick >= _menuHamburger.getXPos() && mouseXClick <= _menuHamburger.getXEndPos()) {
			_foodCode = HAMBURGER;
			return true;
		}
		
		if (mouseXClick >= _menuFries.getXPos() && mouseXClick <= _menuFries.getXEndPos()) {
			_foodCode = FRIES;
			return true;
		}
		
		if (mouseXClick >= _menuChocolateSmoothie.getXPos() && mouseXClick <= _menuChocolateSmoothie.getXEndPos()) {
			_foodCode = CHOCOLATE_SMOOTHIE;
			return true;
		}
		
		if (mouseXClick >= _menuLemonJuice.getXPos() && mouseXClick <= _menuLemonJuice.getXEndPos()) {
			_foodCode = LEMON_JUICE;
			return true;
		}
	}

	return false;
}

int MenuSystem::getFoodCode() {
	return _foodCode;
}

void MenuSystem::render(RenderWindow &window) {
	_menuSystemBackground.render(window);
	
	_menuHamburger.render(window);
	_menuFries.render(window);
	_menuChocolateSmoothie.render(window);
	_menuLemonJuice.render(window);
}