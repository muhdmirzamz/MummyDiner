//
//  LevelScreen.h
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__LevelScreen__
#define __MummyDiner__LevelScreen__

#include "GameState.h"

/*
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
*/

class LevelScreen: public GameState {
	public:
		LevelScreen();
		
		void handleEvent();
		void spawnCustomer();
		void moveCharacter();
		void checkCollision();
		void update();
		void render();
	
	private:
		SpriteClass *_waitress;
		Waitress _waitressObj;
	
		SpriteClass *_customer;
		Customer _customerObj;
	
		SpriteClass _chefObj;
		SpriteClass *_chef;
	
		SpriteClass _topLeftTable;
		SpriteClass _topRightTable;
		SpriteClass _bottomLeftTable;
		SpriteClass _bottomRightTable;
		SpriteClass _counter;
		SpriteClass _stove;
	
		int _mouseClickX;
		int _mouseClickY;
};

#endif /* defined(__MummyDiner__LevelScreen__) */
