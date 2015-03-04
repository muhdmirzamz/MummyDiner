//
//  MainMenuScreen.h
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__MainMenuScreen__
#define __MummyDiner__MainMenuScreen__

#include <stdio.h>

#include "GameState.h"

class MainMenuScreen: public GameState {
	public:
		MainMenuScreen();
	
		void handleEvent();
		void update();
		void render();
	
		static void startFPSTimer();
	
	private:
		TextClass _title;

		ButtonClass _startButton;
		ButtonClass _settingsButton;
};

#endif /* defined(__MummyDiner__MainMenuScreen__) */
