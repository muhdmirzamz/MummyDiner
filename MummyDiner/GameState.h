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

#include <util/DebugMode.h>

#include <util/TextClass.h>
#include <util/ButtonClass.h>
#include <util/BackgroundClass.h>
#include <util/SpriteClass.h>

#define DEBUG_MODE 1

#define QUICKSAND_REGULAR_FONT "fonts/Quicksand-Regular.ttf"
#define LATO_LIGHT_FONT "fonts/Lato-Light.ttf"

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
	
		// debugging symbols
		DebugMode _mouseXPosDebugObj;
		DebugMode *_mouseXPosDebug;
		DebugMode _mouseYPosDebugObj;
		DebugMode *_mouseYPosDebug;
		DebugMode _fpsDebugObj;
		DebugMode *_fpsDebug;
	
	private:
		int _tempState;
};

#endif /* defined(__MummyDiner__GameState__) */
