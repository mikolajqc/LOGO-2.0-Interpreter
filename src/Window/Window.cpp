#include "Window.h"
#include "iostream"

Window::Window()
{
}

Window::~Window()
{
}

bool Window::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool Window::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Nothing to load
	return success;
}

void Window::close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Window::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

int Window::start()
{
	this->operations = operations;
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
				
				for(unsigned int i = 0; i < operations.size(); ++i)
				{
					if(operations[i].first == 0 || operations[i].first == 1)
					{
						int d = (operations[i].first == 0) ? operations[i].second : -operations[i].second;
						
						int newX = xPosition + d * cos(angle * 3.14 / 180.0);
						int newY = yPosition + d * sin(angle * 3.14 / 180.0);

						SDL_SetRenderDrawColor( gRenderer, r, g, b, 0xFF );		
						if(isActive)SDL_RenderDrawLine( gRenderer, xPosition, yPosition, newX , newY);
						
						xPosition = newX;
						yPosition = newY;
						
					}
					
					if(operations[i].first == 2 || operations[i].first == 3)
					{
						angle += (operations[i].first == 2) ? operations[i].second : -operations[i].second;
					}
					
					if(operations[i].first == 4)
					{
						isActive = false;
					}
					
					if(operations[i].first == 5)
					{
						isActive = true;
					}
					if(operations[i].first == 6)
					{
						r = operations[i].second;
					}
					if(operations[i].first == 7)
					{
						g = operations[i].second;
					}
					if(operations[i].first == 8)
					{
						b = operations[i].second;
					}
				}
					 
				
				xPosition = SCREEN_WIDTH/2;
				yPosition = SCREEN_HEIGHT/2;
				angle = 0;
				isActive = true;
				r = g = b = 0;
				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

void Window::addOperation(std::pair<int, int> operation)
{
	operations.push_back(operation);
}
