#include <Windows.h>
#include <process.h>
#include <stdio.h>

using namespace std;


int setupSystem();

int main()
{
	HANDLE setupSystem;
	
	//Declare some variables
	int hello
	
	setupSystem = (HANDLE)_beginthreadex(0, 0, &setupSystem, 0, 0, 0);
	WaitForSingleObject(setupSystem, INFINITE);
	CloseHandle(setupSystem);
	
	
	return 0;
}

int setupSystem()
{
	