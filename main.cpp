	// main.cpp - implements the managers
// Loading required stuff - the managers
#include "Win32Manager.h" // The Win32 C++ Manager header
#include "DxManager.h" // The DirectX C++ Manager header
#include "Sprites.h" // The DirectX Sprite C++ Manager header
#include "Physics.h" // Taking care of physics stuff
#include "main.h" // The main.cpp header - defining stuff


// Getting our message
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) // Basic messages structure
{
	switch (message) 
	{
		case WM_DESTROY:
			PostQuitMessage(0); //Quiting
			break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}



bool initWindow(HINSTANCE hInstance,LPCSTR name) // Basic window inizialization code
{
	// Setting screen height and width
	screen_height = 600;
	screen_width  = 800;

	WNDCLASSEX wcex;

	wcex.cbSize			= sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
    wcex.hIcon			= LoadIcon( hInstance, ( LPCTSTR )IDI_APPLICATION );
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= name;
	wcex.hIconSm		= 0;
	RegisterClassEx(&wcex);

	wndHandle = CreateWindow(name, 
							 name, 
							 WS_OVERLAPPEDWINDOW,
							 CW_USEDEFAULT, 
							 CW_USEDEFAULT, 
							 screen_width, 
							 screen_height, 
							 NULL, 
							 NULL, 
							 hInstance, 
							 NULL);
   if (!wndHandle)
   {
	  MessageBox(NULL, "Failed  to create the window!", "Error", MB_OK);
      return false;
   }
   
   ShowWindow(wndHandle, SW_SHOW);
   UpdateWindow(wndHandle);

   return true;
}


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,  
    LPSTR lpCmdLine, int nCmdShow )									// Basic main function sturcture
{
	if (!initWindow(hInstance))
		return false;

	// Main message loop:
	// Enter the message loop
    MSG msg; 
    ZeroMemory( &msg, sizeof(msg) );

    while( msg.message!=WM_QUIT )
    {
		// Check for messages
		if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
        {
			// Handling messages
			TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
		else 		// this is called when no messages are pending
		{
				// call our render function
			    // Calling our scene
		}
    }


  return (int) msg.wParam;
}

