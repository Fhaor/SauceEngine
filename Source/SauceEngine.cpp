// SauceEngine.cpp : Defines the entry point for the console application.
//

/*##############################################################################
#                                                                             #                                                                                                                                                                    #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                   #
#                                                                             #                                                                                                                                                                  #
##############################################################################*/

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
		FALSE, L"SauceEngine");

	if (ghMutex == NULL)
	{
		printf("CreateMutex error: %d\n", GetLastError());
		return 1;
	}


	DWORD result = WaitForSingleObject(ghMutex, 0);

	if (result == WAIT_OBJECT_0)
	{
		//main code here    
		CheckRAM();
		ReadCPUSpeed();
		cout << "Code ends" << endl;
		system("PAUSE");
	}
	else
	{
		cout << "Apps already opened." << endl;
		return 1;
	}


	CloseHandle(ghMutex);

	return 0;
}

