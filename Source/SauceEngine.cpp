// SauceEngine.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
//#include "../Lib/DirectX/d3dApp.h"
#include "HardwareChecks.cpp"
#include <iostream>
#include "windows.h"
using namespace std;


int main()
{
	HANDLE ghMutex;
	ghMutex = CreateMutex(NULL,
		FALSE, L"pName");

	if (ghMutex == NULL)
	{
		printf("CreateMutex error: %d\n", GetLastError());
		return 1;
	}
	
	//main code here    
	CheckRAM();
	ReadCPUSpeed();
	mikeCheckHardware();
	cout << "Code ends and infinite loop begins" << endl;



	while (true)
	{

	}

	//system("PAUSE");
	CloseHandle(ghMutex);
	
    return 0;
}

