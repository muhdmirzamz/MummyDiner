//
//  GameState.h
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__GameState__
#define __MummyDiner__GameState__

#include <stdio.h>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "util/DebugMode.h"
#include "util/FramesPerSecond.h"
#include "util/TextClass.h"
#include "util/ButtonClass.h"
#include "util/BackgroundClass.h"

#include "sprite/SpriteClass.h"
#include "sprite/Waitress.h"
#include "sprite/Customer.h"
#include "sprite/Chef.h"

#define DEBUG_MODE 1

#define QUICKSAND_REGULAR_FONT "fonts/Quicksand-Regular.ttf"
#define LATO_LIGHT_FONT "fonts/Lato-Light.ttf"

#define MOUSE_X event.mouseMove.x
#define MOUSE_Y event.mouseMove.y
#define MOUSE_X_CLICK event.mouseButton.x
#define MOUSE_Y_CLICK event.mouseButton.y

enum state {
	NO_STATE,
	EXIT,
	MAIN_MENU,
	SETTINGS,
	LEVEL
};

const int SCREEN_W = 640;
const int SCREEN_H = 480;

using namespace sf;

class GameState {
	public:
		GameState();
		virtual ~GameState();
	
		void setState(int state);
		int getState();

		virtual	void handleEvent();
		virtual void spawnCustomer();
		virtual	void moveCharacter();
		virtual	void checkCollision();
		virtual void update();
		virtual void render();
		void cleanup();
	
	protected:
		RenderWindow window;
		Event event;
		Color color;
	
		DebugMode _debug;
	
		int _mouseXPos;
		int _mouseYPos;
	
	private:
		int _tempState;
};

#endif /* defined(__MummyDiner__GameState__) */
