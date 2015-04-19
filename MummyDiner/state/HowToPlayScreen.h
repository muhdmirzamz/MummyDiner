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
		void cleanupHowToPlayScreen(int state);
	
	private:
		bool _firstPage;
		bool _secondPage;
		bool _thirdPage;
	
		BackgroundClass _howToPlayBackground;
	
		TextClass _howToPlayScreenTitle;
	
		ImageClass _customerOrderImage;
		TextClass _customerOrderText;
		ImageClass _menuPickImage;
		TextClass _menuPickText;
	
		ImageClass _greyPatchImage;
		TextClass _greyPatchText;
		ImageClass _chefCookImage;
		TextClass _chefCookText;
	
		ImageClass _serveImage;
		TextClass _serveText;
		ImageClass _customerThanksImage;
		TextClass _customerThanksText;
	
		ButtonClass _nextButton;
		ButtonClass _prevButton;
	
		ButtonClass _backButton;
};

#endif /* defined(__MummyDiner__HowToPlayScreen__) */
