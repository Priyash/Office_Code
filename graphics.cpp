#include"graphics.h"

void graphics::Init(HWND hwnd)
{
	mhwnd = hwnd;
	hdc = GetDC(mhwnd);
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(pfd));
	pfd.nSize = sizeof(&pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;
	int format = ChoosePixelFormat(hdc, &pfd);
	SetPixelFormat(hdc, format, &pfd);

	//Creating render context
	renderContext = wglCreateContext(hdc);
	wglMakeCurrent(hdc, renderContext);
	loader->load("C:\\Users\\admin\\Desktop\\ReconstructMe_Output\\Software_Results\\airplane.ply");
}


void graphics::Render()
{
	float theta = 0.0f;
	glShadeModel(GL_SHADE_MODEL);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(220, 220, 640, 480);
	gluLookAt(10, 10, 10, 0, 0, 0, 0, 1, 0);
	loader->render();
	//call the draw function 
	
	SwapBuffers(hdc);
}



void graphics::clean()
{
	loader->clean();
	if (renderContext)
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(renderContext);
	}

	if (mhwnd&&hdc)
	{
		ReleaseDC(mhwnd, hdc);
	}
	mhwnd = NULL;
	hdc = NULL;
	renderContext = NULL;
}
