#include <cstdio>
#include <Windows.h>
#include <string>
#include "DiskInfo.h"
using namespace std;

int main()
{	
	DiskInfo disk;
    disk.ReadHardisksInfo();
    disk.ListAllHardisks();
    disk.ReadLogicalPartitionsInfo();
    disk.ListAllLogicalPartitions();
	getchar();
	return 0;
}