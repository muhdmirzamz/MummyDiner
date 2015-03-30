//
//  HowToPlayScreen.h
//  MummyDiner
//
//  Created by Muhd Mirza on 29/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__HowToPlayScreen__
#define __MummyDiner__HowToPlayScreen__

#include <stdio.h>

#include "GameState.h"

class HowToPlayScreen: public GameState {
	public:
		HowToPlayScreen();
		
		void handleEvent();
		void update();
		void render();
	
	private:
		BackgroundClass _background;
	
		TextClass _title;
		TextClass _instruction;
	
		ButtonClass _backButton;
};

#endif /* defined(__MummyDiner__HowToPlayScreen__) */
