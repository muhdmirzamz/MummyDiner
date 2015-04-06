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

class ModeMenu: public GameState {
	public:
		ModeMenu();
	
		void handleEvent();
		void update();
		void render();
	
	private:
		TextClass _title;
	
		ButtonClass _normalMode;
		ButtonClass _practiceMode;
};

#endif /* defined(__MummyDiner__ModeMenu__) */
