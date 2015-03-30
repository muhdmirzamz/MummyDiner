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
#include "GameOverScreen.h"

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
	
		SpriteClass *_chef;
		Chef _chefObj;
	
		SpriteClass _topLeftTable;
		SpriteClass _topRightTable;
		SpriteClass _bottomLeftTable;
		SpriteClass _bottomRightTable;
	
		SpriteClass _counter;
		SpriteClass _stove;
	
		BackgroundClass _topLeftBackground;
		BackgroundClass _topRightBackground;
		BackgroundClass _bottomLeftBackground;
		BackgroundClass _bottomRightBackground;
		BackgroundClass _foodPickupBackground;
	
		MenuSystem _menuSystem;
	
		int _mouseClickX;
		int _mouseClickY;
};

#endif /* defined(__MummyDiner__LevelScreen__) */
