//
//  Sprite.h
//  MummyDiner
//
//  Created by Muhd Mirza on 11/1/15.
//  Copyright (c) 2015 Muhd Mirza. All rights reserved.
//

#ifndef __MummyDiner__Sprite__
#define __MummyDiner__Sprite__

#include <stdio.h>

#include <SFML/Graphics.hpp>

using namespace sf;

class SpriteClass {
	public:
		SpriteClass();
	
		void loadSprite(const char *file);
		void cropSprite(int x, int y, int w, int h, float xScale, float yScale);
		void positionSprite(float x, float y);
	
		void moveSpriteUp();
		void moveSpriteDown();
		void moveSpriteLeft();
		void moveSpriteRight();
	
		float getSpriteXPos();
		float getSpriteYPos();
	
		float getSpriteWidth();
		float getSpriteHeight();
	
		Sprite* getSprite();
	
	private:
		Image _spriteImgObj;
		Image *_spriteImg;
	
		Texture _spriteTextureObj;
		Texture *_spriteTexture;
	
		Sprite _spriteObj;
		Sprite *_sprite;
	
		IntRect _spriteRect;
	
		Color _color;
	
		float _spriteXPos;
		float _spriteYPos;
	
		bool spriteMovedUp;
		bool spriteMovedDown;
		bool spriteMovedLeft;
		bool spriteMovedRight;
};

#endif /* defined(__MummyDiner__Sprite__) */
