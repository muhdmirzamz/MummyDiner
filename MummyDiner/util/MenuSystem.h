//
//  MenuSystem.h
//  MummyDiner
//
//  Created by Muhd Mirza on 25/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__MenuSystem__
#define __MummyDiner__MenuSystem__

#include <stdio.h>

#include "../sprite/SpriteClass.h"
#include "../gui/BackgroundClass.h"

class MenuSystem {
	public:
		enum coordinates {
			TOP_LEFT = 1,
			TOP_RIGHT = 2,
			BOTTOM_LEFT = 3,
			BOTTOM_RIGHT = 4
		};
	
		struct topLeft {
			int x = 140;
			int y = 40;
		} topLeftCoordinate;
		
		struct topRight {
			int x = 450;
			int y = 40;
		} topRightCoordinate;
		
		struct bottomLeft{
			int x = 140;
			int y = 190;
		} bottomLeftCoordinate;
		
		struct bottomRight {
			int x = 460;
			int y = 190;
		} bottomRightCoordinate;
	
		enum foodAndDrinks {
			HAMBURGER = 1,
			FRIES = 2,
			CHOCOLATE_SMOOTHIE = 3,
			LEMON_JUICE = 4
		};
	
		MenuSystem();
	
		void loadSpriteInPopup();
		void loadSpriteInTray();
	
		void positionSpriteInPopup(int x, int y);
	
		void renderFoodAndDrinks(int number, RenderWindow &window);
	
		bool itemIsChosen(int mouseXClick, int mouseYClick);
		int getFoodCode();
	
		void render(RenderWindow &window);
	
	private:
		BackgroundClass _menuSystemBackground;
	
		SpriteClass _hamburger;
		SpriteClass _fries;
		SpriteClass _chocolateSmoothie;
		SpriteClass _lemonJuice;
	
		SpriteClass _menuHamburger;
		SpriteClass _menuFries;
		SpriteClass _menuChocolateSmoothie;
		SpriteClass _menuLemonJuice;
	
		int _foodCode;
};

#endif /* defined(__MummyDiner__MenuSystem__) */
