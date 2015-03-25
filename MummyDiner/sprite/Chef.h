//
//  Chef.h
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__Chef__
#define __MummyDiner__Chef__

#include "SpriteClass.h"

using namespace sf;

class Chef: public SpriteClass {
	public:
		Chef();
	
		void startThread();
		void getReadyToCook();
		void cook();
		void renderSmoke(RenderWindow &window);
		void stopThread();
	
		bool isDoneCooking();
		bool isCooking();
	
		int getTimeLeft();
	
	private:
		bool _cooking;
	
		SpriteClass _smoke;
};

#endif /* defined(__MummyDiner__Chef__) */
