#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

#include "../Modules/Module.h"
#include "../../Libraries/SDL/include/SDL.h"

class Application;

class ModuleWindow : public Module
{
public:

	ModuleWindow();

	// Destructor
	virtual ~ModuleWindow();

	// Called before quitting
	bool Init();

	// Called before quitting
	bool CleanUp();

public:
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	//The surface contained by the window
	SDL_Surface* screen_surface = NULL;
	// Element of the size of the window
	int width;
	int height;
	bool sizeChanged;
};

#endif // __ModuleWindow_H__