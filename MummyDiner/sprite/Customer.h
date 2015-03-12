//
//  Customer.h
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__Customer__
#define __MummyDiner__Customer__

#include "SpriteClass.h"

class Customer: public SpriteClass {
	public:
		Customer();
	
		void spawn();
		void startWaiting();
		void order();
	
	private:
};

#endif /* defined(__MummyDiner__Customer__) */
