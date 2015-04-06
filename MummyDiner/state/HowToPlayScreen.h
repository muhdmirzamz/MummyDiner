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
		bool _firstPage;
		bool _secondPage;
		bool _thirdPage;
	
		BackgroundClass _background;
	
		TextClass _title;
	
		ImageClass _customerOrder;
		TextClass _customerOrderText;
		ImageClass _menuPick;
		TextClass _menuPickText;
	
		ImageClass _greyPatch;
		TextClass _greyPatchText;
		ImageClass _chefCook;
		TextClass _chefCookText;
	
		ImageClass _serve;
		TextClass _serveText;
		ImageClass _customerThanks;
		TextClass _customerThanksText;
	
		ButtonClass _nextButton;
		ButtonClass _prevButton;
	
		ButtonClass _backButton;
};

#endif /* defined(__MummyDiner__HowToPlayScreen__) */
