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

using namespace sf;

class FramesPerSecond {
	public:
		FramesPerSecond();
	
		void startCounting();
		void stopCounting();
	
		void hasReachedStartOfFrame();
		void hasReachedEndOfFrame();
	
		float getFPS();
	
	private:
		void calculateStartTime();
		void calculateEndTime();
		void incrementFrames();
		void calculateFPS();
		void capFPS();
	
		int _stillLooping;
		Clock _clock;
	
		float _frames;
		Time _startTime;
		Time _endTime;
	
		bool _endOfFrameReached;
};

#endif /* defined(__MummyDiner__FramesPerSecond__) */
