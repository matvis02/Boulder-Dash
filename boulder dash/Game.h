#pragma once

#include "Level.h"
#include "HUD.h"
#include "Menu.h"
#include "SoundBoard.h"

using namespace sf;
using namespace std;

class Game
{
	RenderWindow* window;
	View view;
	View hudView;
	VideoMode videoMode;
	Event sfmlEvent;

	SoundBoard sound;

	bool viewIsMoving;
	float viewNextSpotx, viewNextSpoty;
	bool viewMoveDirection[4];
	

	Player player;
	Level level;
	HUD hud;

	vector<Menu*> menus;
	void setupMenus();
	int whichMenu;
	void chooseFirstScreen();

	Clock clock;
	atomic <bool> canPush = false;
	atomic <bool> waiting = false;
	void canPushtoTrue();
	Thread threadToTrue{ &Game::canPushtoTrue,this };
	void CantPushAfterStop();

	bool canMoveLeft();
	bool canMoveRight();
	bool canMoveUp();
	bool canMoveDown();

	void initVariables();
	void initWindow();

	void initViews();
	void tryViewMove();
	void moveView();

	void playerOnGameTile();
	void loadCurrentLevel();

	void playerHit(int x, int y);
	void findFallable();
	bool lastFellLeft;
	void tryMoveRockSideways();

	void updateEnemies();

public:
	Game();
	~Game();


	void pollEvents();

	const bool running() const;
	void update();
	void render();

};

