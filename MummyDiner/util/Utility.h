//
//  DebugMode.h
//  MummyDiner
//	contains most macros and constants
//
//  Created by Muhd Mirza on 13/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__DebugMode__
#define __MummyDiner__DebugMode__

#include <stdio.h>
#include <fstream>
#include <string>

#include <SFML/Graphics.hpp>

#define QUICKSAND_REGULAR_FONT "fonts/Quicksand-Regular.ttf"
#define LATO_LIGHT_FONT "fonts/Lato-Light.ttf"

const int SCREEN_W = 800; 
const int SCREEN_H = 600;

using namespace sf;
using namespace std;

class Utility {
	public:
		static bool debug;
		static bool keyboardIsUsed;
	
		Utility();
	
		void set();
		void setNonDebugFlags();
	
		void setFPSValue(int value);
		void setMousePosition(int x, int y);
		void setSpritePosition(int x, int y);
	
		void setTimeLimit(int time);
		void setTime(int time);
	
		void setOrderFlag(bool order);
		void setCookFlag(bool cook);
		void setFoodServedFlag(bool food);
		void setFoodTakenFlag(bool foodIsTaken);
	
		void setCustomerSpawnPosition(int position);
	
		void setCustomerOrderValue(int order);
	
		void setCustomerSuccessValue(int customer);
		void setCustomerFailureValue(int customer);
	
		void setLevelTimerValue(int time);
	
		void setChefTimeLimit(int time);

		void show(RenderWindow &window);
		void showNonDebugFlags(RenderWindow &window);
	
	private:
		void setTextAndPosition(Text &variableLabel, string label, float variableX, float variableY, Text &variableValue);
		void setText(Text &variable);
	
		Font _font;
		int _fontSize;
	
		Text _fps;
		Text _fpsValue;
	
		Text _mouseXPos;
		Text _mouseXPosValue;
		Text _mouseYPos;
		Text _mouseYPosValue;
	
		Text _spriteXPos;
		Text _spriteXPosValue;
		Text _spriteYPos;
		Text _spriteYPosValue;
	
		Text _timeLimit;
		Text _timeLimitValue;
	
		Text _time;
		Text _timeValue;
	
		Text _order;
		Text _orderFlag;
	
		Text _foodServed;
		Text _foodServedFlag;
	
		Text _foodTaken;
		Text _foodTakenFlag;
	
		Text _chefCook;
		Text _chefCookValue;
	
		Text _chefTimeLimit;
		Text _chefTimeLimitValue;
	
		Text _customerSpawnPos;
		Text _customerSpawnPosValue;
	
		Text _customerOrder;
		Text _customerOrderValue;
	
		Text _customerSuccess;
		Text _customerSuccessValue;
	
		Text _customerFailure;
		Text _customerFailureValue;
	
		Text _levelTimer;
		Text _levelTimerValue;
	
		int _valuePositionOffset;
};

#endif /* defined(__MummyDiner__DebugMode__) */
