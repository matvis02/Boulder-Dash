#pragma once
#include <filesystem>
#include <string>
#include <regex>
#include <sstream>
#include <fstream>
//#include "Player.h"
#include "GameTile.h"
#include "Wall.h"
#include "Ground.h"
#include "Rock.h"
#include "Diamond.h"
#include "EndLvl.h"
#include "Enemy.h"
#include "functions.h"

namespace fs = std::filesystem;
using namespace std;

class Level
{

public:
	int mapSizeX = 0;
	int mapSizeY = 0;
	tilePos playerStartingPos;

	fs::path levelsPath = "./levels/";
	vector<fs::path> allPaths;

	vector <std::vector<std::shared_ptr<GameTile>>> tiles;
	vector <std::shared_ptr<GameTile>> allFallable;
	vector <std::shared_ptr<Enemy>> enemies;
	int diamondsRequired = 1;
	int diamondsCollected = 0;

	int currentLevel = 0;
	int howManyLevels = 0;

	Level();
	~Level();

	void setupLevel();

	void renderEnemies(RenderTarget* target);
	void updateEnemies();
	bool enemyCanGoUp(int i);
	bool enemyCanGoDown(int i);
	bool enemyCanGoLeft(int i);
	bool enemyCanGoRight(int i);

	void render(RenderTarget* target);
	void clearLevel();
};

