//
//  MainMenuScreen.h
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__MainMenuScreen__
#define __MummyDiner__MainMenuScreen__

#include "GameState.h"

class MainMenuScreen: public GameState {
	public:
		MainMenuScreen();
	
		void handleEvent();
		void update();
		void render();
	
	private:
		TextClass _mainMenuTitle;

		ButtonClass _startButton;
		ButtonClass _howToPlayButton;
		ButtonClass _settingsButton;
	
		string _fontSize;
};

#endif /* defined(__MummyDiner__MainMenuScreen__) */
