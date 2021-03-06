//
//  GameOverScreen.h
//  MummyDiner
//
//  Created by Muhd Mirza on 28/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__GameOverScreen__
#define __MummyDiner__GameOverScreen__

#include <stdio.h>

#include "GameState.h"

class GameOverScreen: public GameState {
	public:
		static bool success;
		static bool neutral;
	
		GameOverScreen();
		
		void handleEvent();
		void update();
		void render();
		void cleanupGameOverScreen(int state);
	
	private:
		BackgroundClass _successGameOverBackground;
		BackgroundClass _failGameOverBackground;
		BackgroundClass _neutralGameOverBackground;
};

#endif /* defined(__MummyDiner__GameOverScreen__) */
