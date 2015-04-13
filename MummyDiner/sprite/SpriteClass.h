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

#include "../util/Utility.h"
#include "../util/CustomerTimer.h"
#include "../util/ChefTimer.h"

#define SPRITE_X_POS _sprite.getPosition().x
#define SPRITE_Y_POS _sprite.getPosition().y
#define SPRITE_WIDTH (_sprite.getTextureRect().width * _sprite.getScale().x)
#define SPRITE_HEIGHT (_sprite.getTextureRect().height * _sprite.getScale().y)

using namespace sf;

class SpriteClass {
	public:
		SpriteClass();
	
		void set(const char *file, int cropX, int cropY, int cropW, int cropH, float x, float y, float scaleX = 0.1, float scaleY = 0.1);
		void positionSprite(float x, float y);
	
		// waitress and customer have different function bodies for these methods
		// hence function being virtual
		virtual void move();
		virtual void moveUp();
		virtual void moveDown();
		virtual void moveLeft();
		virtual void moveRight();
	
		void handleCollisionWithWindow();
		bool handleCollisionWith(SpriteClass &object);
	
		float getXPos();
		float getYPos();
		
		float getWidth();
		float getHeight();
	
		void render(RenderWindow &window);
	
	protected:
		Image _image;
		Texture _texture;
		IntRect _cropRect;
		Sprite _sprite;
	
		float _speed; // maybe good for future feature in speed variations
};

#endif /* defined(__MummyDiner__Sprite__) */
