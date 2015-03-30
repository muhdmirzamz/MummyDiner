//
//  GameState.h
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__GameState__
#define __MummyDiner__GameState__

#include "../util/FramesPerSecond.h"
#include "../util/CustomerTimer.h" // includes timer class
#include "../util/ChefTimer.h"
#include "../util/LevelTimer.h"

#include "../gui/ButtonClass.h" // includes text class.. also the utility class
#include "../gui/BackgroundClass.h"

// each of these classes includes the SpriteClass class, debug class and timer class
#include "../sprite/Waitress.h"
#include "../sprite/Customer.h" // includes menu system class
#include "../sprite/Chef.h"

#define MOUSE_X event.mouseMove.x
#define MOUSE_Y event.mouseMove.y
#define MOUSE_X_CLICK event.mouseButton.x
#define MOUSE_Y_CLICK event.mouseButton.y

enum state {
	NO_STATE,
	EXIT,
	MAIN_MENU,
	HOW_TO_PLAY,
	SETTINGS,
	LEVEL,
	GAME_OVER
};

class GameState {
	public:
		GameState();
		virtual ~GameState();
	
		virtual void createWindow();
	
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
	
		Utility _debug;
	
		int _mouseXPos;
		int _mouseYPos;
	
	private:
		int _tempState;
};

#endif /* defined(__MummyDiner__GameState__) */
