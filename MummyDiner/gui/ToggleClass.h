//
//  ToggleClass.h
//  MummyDiner
//
//  Created by Muhd Mirza on 31/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__ToggleClass__
#define __MummyDiner__ToggleClass__

#include <stdio.h>

#include "ButtonClass.h"

class ToggleClass {
	public:
		enum toggles {
			DEBUG_TOGGLE,
			CONTROL_TOGGLE
		};
	
		ToggleClass();
	
		void setToggle(string text, float y, int toggle);
		void checkToggle(int mouseClickXPos, int mouseClickYPos, int toggle);
	
		bool isDebugSwitchOn();
		bool isControlSwitchOn();
	
		void render(RenderWindow &window);
	
	private:	
		TextClass _property;

		ButtonClass _offToggle;
		ButtonClass _onToggle;
	
		int _yPos;
};

#endif /* defined(__MummyDiner__ToggleClass__) */
