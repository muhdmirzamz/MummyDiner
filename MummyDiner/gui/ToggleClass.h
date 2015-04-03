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
		ToggleClass();
	
		void setDebugToggle(float y, string text);
		void setControlToggle(float y, string text);
	
		void checkDebugToggle(int mouseClickXPos, int mouseClickYPos);
		void checkControlToggle(int mouseClickXPos, int mouseClickYPos);
	
		bool isDebugSwitchOn();
		bool isControlSwitchOn();
	
		void render(RenderWindow &window);
	
	private:
		TextClass _property;
		ButtonClass _propertyOffToggle;
		ButtonClass _propertyOnToggle;
	
		int _yPos;
};

#endif /* defined(__MummyDiner__ToggleClass__) */
