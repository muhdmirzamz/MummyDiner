//
//  ModeMenu.h
//  MummyDiner
//
//  Created by Muhd Mirza on 5/4/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__ModeMenu__
#define __MummyDiner__ModeMenu__

#include <stdio.h>

#include "GameState.h"
#include "LevelScreen.h"

class ModeMenuScreen: public GameState {
	public:
		ModeMenuScreen();
	
		void handleEvent();
		void update();
		void render();
		void cleanupModeMenuScreen(int state);
	
	private:
		TextClass _modeMenuScreenTitle;
	
		ButtonClass _normalModeButton;
		ButtonClass _practiceModeButton;
};

#endif /* defined(__MummyDiner__ModeMenu__) */
