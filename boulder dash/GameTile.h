#pragma once

#include <iostream>
#include "Player.h"

using namespace sf;

class GameTile
{
protected:
	Name name;
	Texture texture;
	Sprite sprite;
	Vector2f position;

	std::string textureFile;
	const float tileSize = 80.f;
	float nextSpot = 0.f;
	float nextSpotSide = 0.f;

	void SetupSprite();
public:
	tilePos tilePosition;
	bool movable = 0; 
	bool isPassable = 0;
	bool isMoving = 0;
	virtual bool getIsMoving() = 0;
	virtual bool getIsMovingSideways() = 0;
	virtual void changeIsMoving() = 0;
	virtual bool fallDown() = 0;
	virtual bool fallLeft() = 0;
	virtual bool fallRight() = 0;
	virtual bool moveSideways(bool movesLeft, float speed) = 0;
	virtual ~GameTile() {};
	void setSpritePos(Vector2f);
	virtual Name getName();
	Vector2f getPos();
	float getTileSize();
	void render(RenderTarget* target);
};

