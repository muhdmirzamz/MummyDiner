//
//  Chef.cpp
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#include "Chef.h"

static Thread cookThread(Chef::startCooking);

Chef::Chef() {

}

void Chef::cook() {
	// use a boolean flag to check if thread is running,
	// that might help you think of something
	// the next time you try to solve this problem
}

void Chef::startCooking() {
	Clock clock;
	
	while (clock.getElapsedTime().asMilliseconds() <= 5000) {
		printf("%d\n", clock.getElapsedTime().asMilliseconds());
	}
}