//
//  FramesPerSecond.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "FramesPerSecond.h"

// threads dont handle well with private class member outside of threads
// values dont change even if references are used
static float fps;

FramesPerSecond::FramesPerSecond() {
	_endOfFrameReached = false;
}

void FramesPerSecond::startCounting() {
	Lock lock(_mutex);

	_stillLooping = true;

	while (_stillLooping) {
		// let this run
		// putting an if statement on this causes FPS to go haywire
		// issue fixed
		
		// calculate time, reference for start time
		_startTime = _clock.getElapsedTime();
		
		if (_endOfFrameReached) {
			// calculate end time
			_endTime = _clock.getElapsedTime();
			
			// increment frames
			++_frames;
			
			// calculate fps
			fps = _frames / (_clock.getElapsedTime().asMilliseconds() / 1000);
			
			// if frame finishes early, cap fps
			if ((_endTime.asMilliseconds() - _startTime.asMilliseconds()) < (1000 / 60)) {
				sleep(milliseconds((1000 / 60) - (_endTime.asMilliseconds() - _startTime.asMilliseconds())));
			}
		}
	}
}

// using one private variable for two functions
// to determine if the start and/or end of the frame is reached
void FramesPerSecond::setFrameStartPoint() {
	_endOfFrameReached = false;
}

void FramesPerSecond::setFrameEndPoint() {
	_endOfFrameReached = true;
}

float FramesPerSecond::getFPS(){
	return fps;
}