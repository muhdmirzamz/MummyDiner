//
//  FramesPerSecond.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 5/3/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "FramesPerSecond.h"

// declare this as static and not a private class member
// threads dont handle well with private class member outside of threads
// values dont change even if references are used
static float fps;

FramesPerSecond::FramesPerSecond() {
	_endOfFrameReached = false;
}

void FramesPerSecond::startCounting() {
	_stillLooping = true;

	while (_stillLooping) {
		// let this run
		// putting an if statement on this causes FPS to go haywire
		// issue fixed
		calculateStartTime();
		
		if (_endOfFrameReached) {
			calculateEndTime();
			
			incrementFrames();
			calculateFPS();
			capFPS();
		}
	}
}

void FramesPerSecond::stopCounting() {
	_stillLooping = false;
}

// using one private variable for two functions
// to determine if the start and/or end of the frame is reached
void FramesPerSecond::hasReachedStartOfFrame() {
	_endOfFrameReached = false;
}

void FramesPerSecond::hasReachedEndOfFrame() {
	_endOfFrameReached = true;
}

float FramesPerSecond::getFPS(){
	return fps;
}

void FramesPerSecond::calculateStartTime() {
	_startTime = _clock.getElapsedTime();
}

void FramesPerSecond::calculateEndTime() {
	_endTime = _clock.getElapsedTime();
}

void FramesPerSecond::incrementFrames() {
	++_frames;
}

void FramesPerSecond::calculateFPS() {
	fps = _frames / (_clock.getElapsedTime().asMilliseconds() / 1000);
}

void FramesPerSecond::capFPS() {
	// if frame finishes early
	if ((_endTime.asMilliseconds() - _startTime.asMilliseconds()) < (1000 / 60)) {
		sleep(milliseconds((1000 / 60) - (_endTime.asMilliseconds() - _startTime.asMilliseconds())));
	}
}