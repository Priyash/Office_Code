#ifndef GRAPHICS_H
#define GRAPHICS_H
#include<iostream>
#include<windows.h>
#include<string>
#include<GL\glut.h>
#include"graphics.h"
#include"loader.h"
#include"graphics.h"
#include<fstream>
class graphics
{
	HDC hdc;
	HWND mhwnd;
	HGLRC renderContext;
	Loader* loader;
	string file;
public:
	graphics()
	{
		loader = Model::getPLYLoader();
	}
	~graphics()
	{

	}
	void Init(HWND hwnd);
	//void Update();
	void Render();
	void clean();
};




#endif
