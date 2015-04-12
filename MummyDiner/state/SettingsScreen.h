//
//  SettingsScreen.h
//  MummyDiner
//
//  Created by Muhd Mirza on 5/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__SettingsScreen__
#define __MummyDiner__SettingsScreen__

#include "GameState.h"

class SettingsScreen: public GameState {
	public:
		SettingsScreen();
	
		void handleEvent();
		void update();
		void render();
	
	private:
		ButtonClass _backToMainMenuButton;
	
		TextClass _settingsScreenTitle;
	
		ToggleClass _debugToggle;
		ToggleClass _controlToggle;
};

#endif /* defined(__MummyDiner__SettingsScreen__) */
