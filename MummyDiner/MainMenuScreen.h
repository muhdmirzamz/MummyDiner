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
		TextClass _titleObj;
		TextClass *_title;
	
		float _horizontalCenterOfButton;
		float _verticalCenterOfButton;
		ButtonClass _startButtonObj;
		ButtonClass *_startButton;
		TextClass _startTextObj;
		TextClass *_startText;
	
		ButtonClass _settingsButtonObj;
		ButtonClass *_settingsButton;
		TextClass _settingsTextObj;
		TextClass *_settingsText;
};

#endif /* defined(__MummyDiner__MainMenuScreen__) */
