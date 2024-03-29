#pragma once
#define SDL_MAIN_HANDLED
#include<string>
#include"SDL.h"
#include"SDL_main.h"

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib" )



#define Gridsize         10
#define GRID_COLOR      55,55,55,55
#define COLOR_BLACK      0, 0, 0,255
#define BOARDER         10



class Renderer;

struct Window
{
	Window() = default;
	Window(int _w, int _h, std::string _name);

	int x, y, width, height;
	std::string name;

	
	SDL_Renderer* Context;
	SDL_Window* Handle;
	SDL_Surface* Surface;

	void Sync();
	void CLS();
	static Window g_Window();

	bool Initialized = false;

	void s_Position(int _x, int _y);
private:
	static Window* MainWindow;
};



void DrawGraph(Window* _win);