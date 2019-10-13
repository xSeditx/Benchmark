#pragma once
#define SDL_MAIN_HANDLED

#include"SDL.h"
#include"SDL2_main.h"

class Window
{
	Window(int _w, int _h, std::string _name);
	std::string Name;
	int x, y, w, h;

	
};