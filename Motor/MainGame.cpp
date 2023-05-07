#include "MainGame.h"
#include <iostream>
#include "Error.h"
#include <windows.h>
using namespace std;

MainGame::MainGame() {
	width = 800;
	height = 600;
	gameState = GameState::PLAY;
	time = 0;
	max_sprites=20;
}

MainGame::~MainGame() {

}
void MainGame::processInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
			case SDL_QUIT:
				gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				//cout << event.motion.x << " , " << event.motion.y << endl;
				break;
		}
	}
}

void MainGame::initShaders()
{
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAtribute("vertexPosition");
	program.addAtribute("vertexColor");
	program.addAtribute("vertexUV");
	program.linkShader();
}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window.create("relibrana", width, height,0);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Glew not initialized");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	initShaders();
}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	glActiveTexture(GL_TEXTURE0);
	GLuint timeLocation = program.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	time += 0.002;
	GLuint imageLocation = program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	for (int i = 0; i < sprites.size(); ++i)
	{
		sprites[i]->draw();
	}
	
	program.unuse();
	window.swapWindow();
}

void MainGame::spritesGenerate() {


	/*if (sprites.size() < max_sprites) {
		sprites.resize(sprites.size() + 1);

	}*/
	if (sprites.size()==max_sprites)return;
	/*for (size_t i = 0; i < 0; i++)
	{
		sprites[i]->init(-1, -1, 1, 1, "Textures/imagen.png");
	}*/
	cout << "cuadradito";
	float x = rand() ;
	float y = rand() ;
	Sprite* sprite=new Sprite();
	sprite->init(-1, -1, 1, 1, "Textures/imagen.png");
	sprites.push_back(sprite);
	Sleep(20);
}
void MainGame::run() {
	init();
	update();

	
}



void MainGame::update() {
	while (gameState != GameState::EXIT) {
		draw();
		spritesGenerate();
		processInput();
	}
}