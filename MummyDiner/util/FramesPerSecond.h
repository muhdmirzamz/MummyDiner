//
//  FramesPerSecond.h
//  MummyDiner
//
//  Created by Muhd Mirza on 5/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__FramesPerSecond__
#define __MummyDiner__FramesPerSecond__

#include <stdio.h>

#include <SFML/System.hpp>

#include "Timer.h"

using namespace sf;

class FramesPerSecond: public Timer {
	public:
		FramesPerSecond();
	
		void startCounting();
	
		void setFrameStartPoint();
		void setFrameEndPoint();
	
		float getFPS();
	
	private:
		float _frames;
		
		Time _startTime;
		Time _endTime;
	
		bool _endOfFrameReached;
};

#endif /* defined(__MummyDiner__FramesPerSecond__) */
