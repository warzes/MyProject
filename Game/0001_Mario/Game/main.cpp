#include "stdafx.h"
#include "App.h"
//-----------------------------------------------------------------------------
#ifdef _WIN32
#	pragma comment(lib, "x86/SDL2.lib")
#	pragma comment(lib, "x86/SDL2main.lib")
#	pragma comment(lib, "x86/SDL2_mixer.lib")
#endif
//-----------------------------------------------------------------------------
int main(int, char*[])
{
	// Enable run-time memory leak check for debug builds
#if defined(_MSC_VER) && defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	srand((unsigned)time(nullptr));

	try
	{
		App app;
		app.Run();
	}
	catch ( const std::string &err )
	{
		std::cout << "ERROR: " << err << std::endl;
		system("PAUSE");
	}
	catch ( ... )
	{
		std::cout << "ERROR: unknown error" << std::endl;
		system("PAUSE");
	}
	
	return 0;
}
//-----------------------------------------------------------------------------