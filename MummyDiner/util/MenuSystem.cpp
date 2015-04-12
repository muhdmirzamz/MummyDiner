//
//  MenuSystem.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 25/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "MenuSystem.h"

MenuSystem::MenuSystem() {
	_menuSystemBackground.setBackgroundUsingName("_menuSystemBackground");
	
	_menuHamburger.set("images/hamburger.bmp", 400, 10, 500, 500, 10, MENU_ITEM_Y_POS);
	_menuFries.set("images/fries.bmp", 300, 10, 600, 670, 80, MENU_ITEM_Y_POS);
	_menuChocolateSmoothie.set("images/chocolate_smoothie.bmp", 400, 10, 500, 677, 170, MENU_ITEM_Y_POS);
	_menuLemonJuice.set("images/lemon_juice.bmp", 400, 10, 400, 600, 250, MENU_ITEM_Y_POS);
	
	_foodCode = 0;
}

// middle functions are for popup renders
void MenuSystem::loadSpriteInPopup() {
	_hamburger.set("images/hamburger.bmp", 400, 10, 500, 500, 0, 0);
	_fries.set("images/fries.bmp", 300, 10, 600, 670, 0, 0);
	_chocolateSmoothie.set("images/chocolate_smoothie.bmp", 400, 10, 500, 677, 0, 0);
	_lemonJuice.set("images/lemon_juice.bmp", 400, 10, 400, 600, 0, 0);
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
bool MenuSystem::getMenuItemXAxis(int x) {
	if (x >= _menuHamburger.getXPos() && x <= _menuHamburger.getXPos() + _menuHamburger.getWidth()) {
		_foodCode = HAMBURGER;
		return true;
	}
	
	if (x >= _menuFries.getXPos() && x <= _menuFries.getXPos() + _menuFries.getWidth()) {
		_foodCode = FRIES;
		return true;
	}
	
	if (x >= _menuChocolateSmoothie.getXPos() && x <= _menuChocolateSmoothie.getXPos() + _menuChocolateSmoothie.getWidth()) {
		_foodCode = CHOCOLATE_SMOOTHIE;
		return true;
	}
	
	if (x >= _menuLemonJuice.getXPos() && x <= _menuLemonJuice.getXPos() + _menuLemonJuice.getWidth()) {
		_foodCode = LEMON_JUICE;
		return true;
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