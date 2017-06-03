#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>

class Window
{
public:
	Window();
	~Window();
	int start();
	
	void addOperation(std::pair <int, double> operation);
	
private:

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	double xPosition = SCREEN_WIDTH/2;
	double yPosition = SCREEN_HEIGHT/2;
	bool isActive = true;
	int r = 0;
	int g = 0;
	int b = 0;
	int angle = 0;
	bool isSet = false;
	
	std::vector<std::pair<int, double> > operations;

	bool init();

	//Loads media
	bool loadMedia();

	//Frees media and shuts down SDL
	void close();
	SDL_Texture* loadTexture( std::string path );
	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;
	

};

#endif // WINDOW_H
