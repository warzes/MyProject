#include "stdafx.h"
#include "App.h"

#ifdef _WIN32
#	pragma comment(lib, "x86/SDL2.lib")
#	pragma comment(lib, "x86/SDL2main.lib")
#	pragma comment(lib, "x86/SDL2_image.lib")
#	pragma comment(lib, "x86/SDL2_mixer.lib")
#	pragma comment(lib, "x86/SDL2_ttf.lib")
#endif

int main(int, char*[])
{
	// Enable run-time memory leak check for debug builds
#if defined(_MSC_VER) && defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif	
		
	App app;
	app.MainLoop();
	return 0;
}