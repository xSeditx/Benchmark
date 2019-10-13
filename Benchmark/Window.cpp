#include"Window.h"

Window* Window::MainWindow;

Window::Window(int _w, int _h, std::string _name)
	:
	x(NULL),
	y(NULL),
	width(_w),
	height(_h),
	name(_name),
	Surface(nullptr),
	Initialized(true)
{
	Handle = SDL_CreateWindow(_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _w, _h, SDL_WINDOW_RESIZABLE);//  SDL_WINDOW_BORDERLESS
	Context = SDL_CreateRenderer(Handle, -1, SDL_RENDERER_ACCELERATED);          //new Renderer(Handle, SDL_RENDERER_ACCELERATED); /// Not sure bout this one yet | SDL_RENDERER_TARGETTEXTURE);
	MainWindow = this;
}
void Window::Sync()
{
	//Context->Display();
	SDL_RenderPresent(Context);
}
void Window::CLS()
{
	SDL_RenderClear(Context);
}
Window Window::g_Window()
{
	return *MainWindow;
}

void Window::s_Position(int _x, int _y)
{
	SDL_SetWindowPosition(Handle, _x, _y);
}



int Gridsize = 10;
#define GRID_COLOR   155,155,155,255
#define BOARDER 100
void DrawGraph(Window* _win)
{
	SDL_SetRenderDrawColor(_win->Context, GRID_COLOR);
	{// Render grid
		for (int y{ BOARDER }; y < _win->height- BOARDER + Gridsize; y += Gridsize)
		{
			SDL_RenderDrawLine(_win->Context, BOARDER, y, _win->width - BOARDER, y);
		}
		for (int x{ BOARDER }; x < _win->width - BOARDER + Gridsize; x += Gridsize)
		{
			SDL_RenderDrawLine(_win->Context, x, BOARDER, x, _win->height - BOARDER);
		}
	}// End Render grid

	SDL_SetRenderDrawColor(_win->Context,
		0,
		0,
		0,
		255);
}
