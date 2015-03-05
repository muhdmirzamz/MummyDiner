//
//  LevelScreen.h
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__LevelScreen__
#define __MummyDiner__LevelScreen__

#include <stdio.h>

#include "GameState.h"

typedef struct {
	int x = 140;
	int y = 40;
} customerTopLeftCoordinate;

typedef struct {
	int x = 450;
	int y = 40;
} customerTopRightCoordinate;

typedef struct
	int x = 140;
	int y = 190;
} customerBottomLeftCoordinate;

typedef struct {
	int x = 460;
	int y = 190;
} customerBottomRightCoordinate;

enum {
	TOP_LEFT_COORDINATE = 1,
	TOP_RIGHT_COORDINATE = 2,
	BOTTOM_LEFT_COORDINATE = 3,
	BOTTOM_RIGHT_COORDINATE = 4
};

enum {
	BOY_CUSTOMER = 1,
	GIRL_CUSTOMER = 2
};

class LevelScreen: public GameState {
	public:
		LevelScreen();
		
		void handleEvent();
		void spawnCustomer();
		void moveCharacter();
		void checkCollision();
		void update();
		void render();
	
		//static void startFPSTimer();
		static void startCustomerTimer();
	
	private:
		SpriteClass _waitressObj;
		SpriteClass *_waitress;
	
		SpriteClass _topLeftTableObj;
		SpriteClass *_topLeftTable;
		SpriteClass _topLeftCustomerObj;
		SpriteClass *_topLeftCustomer;
		customerTopLeftCoordinate _topLeftCoordinateObj;
		customerTopLeftCoordinate *_topLeftCoordinate;
	
		SpriteClass _topRightTableObj;
		SpriteClass *_topRightTable;
		SpriteClass _topRightCustomerObj;
		SpriteClass *_topRightCustomer;
		customerTopRightCoordinate _topRightCoordinateObj;
		customerTopRightCoordinate *_topRightCoordinate;
	
		SpriteClass _bottomLeftTableObj;
		SpriteClass *_bottomLeftTable;
		SpriteClass _bottomLeftCustomerObj;
		SpriteClass *_bottomLeftCustomer;
		customerBottomLeftCoordinate _bottomLeftCoordinateObj;
		customerBottomLeftCoordinate *_bottomLeftCoordinate;
	
		SpriteClass _bottomRightTableObj;
		SpriteClass *_bottomRightTable;
		SpriteClass _bottomRightCustomerObj;
		SpriteClass *_bottomRightCustomer;
		customerBottomRightCoordinate _bottomRightCoordinateObj;
		customerBottomRightCoordinate *_bottomRightCoordinate;
	
		SpriteClass _counterObj;
		SpriteClass *_counter;
	
		SpriteClass _chefObj;
		SpriteClass *_chef;
	
		SpriteClass _stoveObj;
		SpriteClass *_stove;
	
		int _mouseXPos;
		int _mouseYPos;
	
		int _randomTable;
		int _randomCustomer;

		// level class gets special debug backgrounds
		DebugMode _topLeftBackgroundObj;
		DebugMode *_topLeftBackground;
	
		DebugMode _topRightBackgroundObj;
		DebugMode *_topRightBackground;
	
		DebugMode _bottomLeftBackgroundObj;
		DebugMode *_bottomLeftBackground;
	
		DebugMode _bottomRightBackgroundObj;
		DebugMode *_bottomRightBackground;
	
		DebugMode _bottomBackgroundObj;
		DebugMode *_bottomBackground;
	
		DebugMode _spriteXPosDebugObj;
		DebugMode *_spriteXPosDebug;
	
		DebugMode _spriteYPosDebugObj;
		DebugMode *_spriteYPosDebug;
};

#endif /* defined(__MummyDiner__LevelScreen__) */
