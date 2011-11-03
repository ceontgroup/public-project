#ifndef Disk_Info_h_
#define Disk_Info_h_
#include <vector>
#include <string>
using std::vector;
using std::string;
struct LogicalPartitionInfo
{
    string rootPathName, volumeName, fileSystemName;
    unsigned long sectorsPerCluster, bytesPerSector, numberOfFreeClusters, totalNumberOfClusters;
    unsigned long volumeSerialNumber, maximumComponentLength, fileSystemFlags;
    int driverType;
};
struct HardiskInfo 
{
    string vendorId, productId, productRevision, serialNumber;
    unsigned long bytePerSector, sectorsPerTrack, tracksPerCylinder;
    long long diskSize, cylinders;
    int driverType; 
};
typedef vector<LogicalPartitionInfo *> ListLogicalPartitionInfo;
typedef vector<HardiskInfo *> ListHardiskInfo;
class DiskInfo
{
private:
	ListLogicalPartitionInfo listLogicalPartitionInfo;
    ListHardiskInfo listHardiskInfo;
    char* getString (const char * str, int pos, char * buf);    
    void DestroyListLogicalPartitions();
    void DestroyListHardisks();
public:
    void ListAllLogicalPartitions();
    void ListAllHardisks();
    int ReadHardisksInfo();
    int ReadLogicalPartitionsInfo();
    void DestroyAll();
	DiskInfo();
	virtual ~DiskInfo();
};

#endif