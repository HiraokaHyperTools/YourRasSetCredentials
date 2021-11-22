// YourRasSetCredentials.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <ras.h>
#include <tchar.h>

#pragma comment(lib, "rasapi32")

int _tmain(int argc, TCHAR** argv)
{
	if (argc < 4) {
		_tprintf(_T("YourRasSetCredentials vpnName vpnUser vpnPass \n"));
		return 1;
	}

	RASCREDENTIALS rasCred = {
		sizeof(RASCREDENTIALS),
		RASCM_UserName | RASCM_Password,
	};

	_tcscpy_s(rasCred.szUserName, argv[2]);
	_tcscpy_s(rasCred.szPassword, argv[3]);

	DWORD res = RasSetCredentials(
		NULL,
		argv[1],
		&rasCred,
		false
	);
	if (res != ERROR_SUCCESS) {
		_tprintf(_T("Error %u.\n"), res);
		return 1;
	}
	_tprintf(_T("Success.\n"));
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
