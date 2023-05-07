#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "Sprite.h"
#include "HLSLProgram.h"
#include "Window.h"
#include <vector>

enum class GameState {
	PLAY,EXIT
};

class MainGame
{
private:
	int max_sprites;
	float time;
	int width;
	int height;
	Window window;
	HLSLProgram program;
	std::vector < Sprite*> sprites;
	void init();
	void processInput();
	void initShaders();
	void spritesGenerate();

public:
	MainGame();
	~MainGame();
	GameState gameState;
	
	
	void run();
	void draw();
	void update();
};

