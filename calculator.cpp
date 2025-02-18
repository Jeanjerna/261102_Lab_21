#include <windows.h>
#include <stdio.h>

HWND textfield , btn_add , btn_sub , btn_mul , btn_div ;
HWND textbox1 , textbox2 ;

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		//------------👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻------------//

		case WM_CREATE:
			
			textfield = CreateWindow("STATIC", "Please input two numbers", 
				WS_VISIBLE | WS_CHILD | SS_CENTER , 
				20, 20, 200, 25, 
				hwnd, NULL, NULL, NULL);
			
			btn_add = CreateWindow("BUTTON", "+", 
				WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , 
				50, 120, 25, 25, 
				hwnd, (HMENU) '+' , NULL, NULL);

			btn_sub = CreateWindow("BUTTON", "-", 
				WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , 
				80, 120, 25, 25, 
				hwnd, (HMENU) '-' , NULL, NULL);

			btn_mul = CreateWindow("BUTTON", "*", 
				WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , 
				110, 120, 25, 25, 
				hwnd, (HMENU) '*' , NULL, NULL);

			btn_div = CreateWindow("BUTTON", "/", 
				WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER , 
				140, 120, 25, 25, 
				hwnd, (HMENU) '/' , NULL, NULL);
			
			textbox1 = CreateWindow("EDIT", "",
				WS_VISIBLE | WS_CHILD | SS_CENTER , 
				40, 50, 150, 25, 
				hwnd, NULL, NULL, NULL);

			textbox2 = CreateWindow("EDIT", "",
				WS_VISIBLE | WS_CHILD | SS_CENTER , 
				40, 80, 150, 25, 
				hwnd, NULL, NULL, NULL);

			break;

		case WM_COMMAND:
				
				char text1[100] , text2[100] , result_text[100]; ;
				double result, num1 , num2;

				switch(LOWORD(wParam))
				{
					case '+':

						GetWindowText(textbox1 , &text1[0] , 100);
						GetWindowText(textbox2 , &text2[0] , 100);

						num1 = atof(text1);
						num2 = atof(text2);

						result = num1 + num2;

						sprintf(result_text, "%f", result);

						::MessageBeep(MB_ICONERROR);
						::MessageBox(hwnd , result_text , "Result" , MB_OK);
						break;

					case '-':

						GetWindowText(textbox1 , &text1[0] , 100);
						GetWindowText(textbox2 , &text2[0] , 100);

						num1 = atof(text1);
						num2 = atof(text2);

						result = num1 - num2;

						sprintf(result_text, "%f", result);

						::MessageBeep(MB_ICONERROR);
						::MessageBox(hwnd , result_text , "Result" , MB_OK);
						break;

					case '*':

						GetWindowText(textbox1 , &text1[0] , 100);
						GetWindowText(textbox2 , &text2[0] , 100);

						num1 = atof(text1);
						num2 = atof(text2);

						result = num1 * num2;

						sprintf(result_text, "%f", result);
						
						::MessageBeep(MB_ICONERROR);
						::MessageBox(hwnd , result_text , "Result" , MB_OK);
						break;

					case '/':

						GetWindowText(textbox1 , &text1[0] , 100);
						GetWindowText(textbox2 , &text2[0] , 100);

						num1 = atof(text1);
						num2 = atof(text2);

						result = num1 / num2;

						sprintf(result_text, "%f", result);

						::MessageBeep(MB_ICONERROR);
						::MessageBox(hwnd , result_text , "Result" , MB_OK);
						break;
				}

				break;
		
		//------------👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻👨‍💻------------//

		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize	 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor	 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_HOTLIGHT+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon	 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","My Calculator",WS_VISIBLE|WS_SYSMENU,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		250, /* width */
		200, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
