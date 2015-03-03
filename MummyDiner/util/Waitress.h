//
//  Waitress.h
//  MummyDiner
//
//  Created by Muhd Mirza on 19/2/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__Waitress__
#define __MummyDiner__Waitress__

#include <stdio.h>
#include "SpriteClass.h"

class Waitress: public SpriteClass {
	public:
		Waitress();
	
	private:
		SpriteClass _spriteClass;
};

#endif /* defined(__MummyDiner__Waitress__) */
