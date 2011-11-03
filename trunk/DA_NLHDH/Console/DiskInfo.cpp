#include <Windows.h>
#include <iostream>
#include "DiskInfo.h"
using namespace std;

#define  MAX_IDE_DRIVES  16
#define IOCTL_DISK_GET_DRIVE_GEOMETRY_EX CTL_CODE(IOCTL_DISK_BASE, 0x0028, METHOD_BUFFERED, FILE_ANY_ACCESS)

DiskInfo::DiskInfo(void)
{	    
}

void DiskInfo::ListAllLogicalPartitions()
{
    cout<<"*****************LOGICAL DISK INFO**********************"<<endl;
    for (unsigned int i = 0; i < listLogicalPartitionInfo.size(); i++)
    {        

        cout
            <<"Volume: "<<listLogicalPartitionInfo[i]->volumeName<<endl
            <<"Volume serial number: "<<listLogicalPartitionInfo[i]->volumeSerialNumber<<endl
            <<"File System: "<<listLogicalPartitionInfo[i]->fileSystemName<<endl
            <<"Path: "<<listLogicalPartitionInfo[i]->rootPathName<<endl
            <<"Bytes per sector: "<<listLogicalPartitionInfo[i]->bytesPerSector<<endl
            <<"Sector per cluster: "<<listLogicalPartitionInfo[i]->sectorsPerCluster<<endl
            <<"Number of free clusters: "<<listLogicalPartitionInfo[i]->numberOfFreeClusters<<endl
            <<"Total number of clusters: "<<listLogicalPartitionInfo[i]->totalNumberOfClusters<<endl
            ;        
        switch (listLogicalPartitionInfo[i]->driverType)
        {
        case DRIVE_NO_ROOT_DIR:
            cout<<"Driver Type: "<<"DRIVE_NO_ROOT_DIR"<<endl;
            break;
        case DRIVE_CDROM:
            cout<<"Driver Type: "<<"DRIVE_CDROM"<<endl;
            break;
        case DRIVE_FIXED:
            cout<<"Driver Type: "<<"DRIVE_FIXED"<<endl;
            break;
        case DRIVE_RAMDISK:
            cout<<"Driver Type: "<<"DRIVE_RAMDISK"<<endl;
            break;
        case DRIVE_REMOTE:
            cout<<"Driver Type: "<<"DRIVE_REMOTE"<<endl;
            break;
        case DRIVE_REMOVABLE:
            cout<<"Driver Type: "<<"DRIVE_REMOVABLE"<<endl;
            break;
        case DRIVE_UNKNOWN:
            cout<<"Driver Type: "<<"DRIVE_UNKNOWN"<<endl;
            break;
        }        
        if ( i < listLogicalPartitionInfo.size() - 1)
        cout<<"-------------------------&$$$&--------------------------"<<endl;
    }
    cout<<"***************END LOGICAL DISK INFO********************"<<endl;
}

char * DiskInfo::getString (const char * str, int pos, char * buf)
{
    buf [0] = 0;
    if (pos <= 0)
        return buf;

    int i = pos;
    int j = 1;
    int k = 0;    
    //Tach xau
    while (j && str[i] != 0)
    {
        char c = str[i];
        if ( ! isprint(c))
        {
            j = 0;
            break;
        }
        buf[k] = c;
        ++k;
        ++i;
    }        

    // Neu khong co ky tu nao in duoc
    if ( ! j )            
        k = 0;    

    buf[k] = 0;
    
    // Trim: Loai bo khoang trang dau va cuoi xau    
    while (isspace(buf[0]))
    {   
        i = 0;
        while ( buf[i] != 0)      
        {
            buf[i] = buf[i+1];
            i++;
        }
    }
    while (isspace(buf[strlen(buf) - 1]))
    {   
        buf[strlen(buf) - 1] = 0;
    }

    return buf;
}

int DiskInfo::ReadHardisksInfo ()
{    
    this->DestroyListHardisks();
    int drive = 0;
    HardiskInfo *hardiskInfo;    
    for (drive = 0; drive < MAX_IDE_DRIVES; drive++)
    {
        HANDLE hPhysicalDrive = 0;                
        char driveName [256];
        sprintf_s(driveName, "\\\\.\\PhysicalDrive%d", drive);
         //Google xem CreateFile       
        hPhysicalDrive = CreateFile (driveName, 0,
            FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
            OPEN_EXISTING, 0, NULL);

        if (hPhysicalDrive != INVALID_HANDLE_VALUE)
        {
            ////google xem struct STORAGE_PROPERTY_QUERY
            STORAGE_PROPERTY_QUERY query;
            DWORD cbBytesReturned = 0;
            char buffer[10000];
            memset ((void *) &query, 0, sizeof(query));
            query.PropertyId = StorageDeviceProperty;
            query.QueryType = PropertyStandardQuery;
            memset (buffer, 0, sizeof (buffer));
            //Google xem DeviceIoControl
            if ( DeviceIoControl (hPhysicalDrive, IOCTL_STORAGE_QUERY_PROPERTY,
                &query,
                sizeof(query),
                &buffer,
                sizeof(buffer),
                &cbBytesReturned, NULL) )
            {         
                //google xem struct STORAGE_DEVICE_DESCRIPTOR
                STORAGE_DEVICE_DESCRIPTOR * descrip = (STORAGE_DEVICE_DESCRIPTOR *) & buffer;
                char serialNumber[1000];
                char modelNumber[1000];
                char vendorId[1000];
                char productRevision[1000];
                //Lay cac thong tin mo ta cua o cung
                getString (buffer, descrip -> VendorIdOffset, vendorId );
                getString (buffer, descrip -> ProductIdOffset, modelNumber );
                getString (buffer, descrip -> ProductRevisionOffset, productRevision );
                getString (buffer, descrip -> SerialNumberOffset, serialNumber );                
                //Them mot doi tuong o cung vao danh sach voi cac thong tin mo ta
                hardiskInfo = new HardiskInfo;
                hardiskInfo->vendorId = string(vendorId);
                hardiskInfo->productId = string(modelNumber);
                hardiskInfo->productRevision = string(productRevision);
                hardiskInfo->serialNumber = string(serialNumber);
                hardiskInfo->bytePerSector = 0;
                hardiskInfo->cylinders = 0;
                hardiskInfo->diskSize = 0;
                hardiskInfo->tracksPerCylinder = 0;
                hardiskInfo->sectorsPerTrack = 0;
                hardiskInfo->driverType = -1;
                listHardiskInfo.push_back(hardiskInfo);

                // Lay thong tin chi tiet cua o cung
                memset (buffer, 0, sizeof(buffer));
                if ( DeviceIoControl (hPhysicalDrive,
                    IOCTL_DISK_GET_DRIVE_GEOMETRY_EX,
                    NULL,
                    0,
                    &buffer,
                    sizeof(buffer),
                    &cbBytesReturned,
                    NULL))
                {
                    //google xem struct DISK_GEOMETRY_EX
                    DISK_GEOMETRY_EX* geom = (DISK_GEOMETRY_EX*) &buffer;
                    int fixed = (geom->Geometry.MediaType == FixedMedia);
                    __int64 size = geom->DiskSize.QuadPart;				     
                    //Cap nhap thong tin chi tiet
                    hardiskInfo->bytePerSector = geom->Geometry.BytesPerSector;                    
                    hardiskInfo->diskSize = geom->DiskSize.QuadPart;
                    hardiskInfo->tracksPerCylinder = geom->Geometry.TracksPerCylinder;
                    hardiskInfo->sectorsPerTrack = geom->Geometry.SectorsPerTrack;
                    hardiskInfo->driverType = geom->Geometry.MediaType;
                    hardiskInfo->cylinders = geom->Geometry.Cylinders.QuadPart;                    
                }                 
            }            
            CloseHandle (hPhysicalDrive);
        }        
    }    
    return drive;
}

void DiskInfo::ListAllHardisks()
{
    cout<<"*********************DISK INFO**************************"<<endl;
    for (unsigned int drive = 0; drive < listHardiskInfo.size(); drive++)
    {
            cout
            <<"Disk Info for drive "<< drive <<" : "<<endl
            <<"Vendor Id: "<<listHardiskInfo[drive]->vendorId<<endl
            <<"Product Id: "<<listHardiskInfo[drive]->productId<<endl
            <<"Product revision: "<<listHardiskInfo[drive]->productRevision<<endl
            <<"Serial number: "<<listHardiskInfo[drive]->serialNumber<<endl
            <<"Disk size: "<<listHardiskInfo[drive]->diskSize<<endl
            <<"Byte per sector: "<<listHardiskInfo[drive]->bytePerSector<<endl
            <<"Cylinders: "<<listHardiskInfo[drive]->cylinders<<endl
            <<"Sector per track: "<<listHardiskInfo[drive]->sectorsPerTrack<<endl
            <<"Track per cylinder: "<<listHardiskInfo[drive]->tracksPerCylinder<<endl
            <<"Driver type: "<<listHardiskInfo[drive]->driverType<<endl
            ;        
            if (drive < listHardiskInfo.size() - 1)
                cout<<"------------------------&$$$&------------------------"<<endl;
    }
    cout<<"******************END DISK INFO*************************"<<endl;
}

int DiskInfo::ReadLogicalPartitionsInfo()
{
    this->DestroyListLogicalPartitions();
    const int lenght = 255;
    char buffer[lenght + 1];
    //Lay danh sach cac o dia logical
    ::GetLogicalDriveStrings(lenght, buffer);
    char* s = buffer;
    //Khoi tao danh sach cac o dia logical
    while (*s)
    {
        LogicalPartitionInfo *volumeInfo = new LogicalPartitionInfo;
        volumeInfo->rootPathName = s;
        listLogicalPartitionInfo.push_back(volumeInfo);
        s += strlen(s) + 1;
    }    		
    //Lay thong tin chi tiet cua moi o dia logical
    char VolumeNameBuffer[256], FileSystemBuffer[256];
    for (unsigned int i = 0; i < listLogicalPartitionInfo.size(); i++)
    {        
        memset( VolumeNameBuffer, 0, 256);
        memset( FileSystemBuffer, 0, 256);
        //Google xem GetDiskFreeSpace
        ::GetDiskFreeSpace(
            listLogicalPartitionInfo[i]->rootPathName.data(), 
            &listLogicalPartitionInfo[i]->sectorsPerCluster, 
            &listLogicalPartitionInfo[i]->bytesPerSector, 
            &listLogicalPartitionInfo[i]->numberOfFreeClusters, 
            &listLogicalPartitionInfo[i]->totalNumberOfClusters
            );
            //Google xem VolumeInfomation
        ::GetVolumeInformation(
            listLogicalPartitionInfo[i]->rootPathName.data(),
            VolumeNameBuffer,
            256,
            &listLogicalPartitionInfo[i]->volumeSerialNumber,
            &listLogicalPartitionInfo[i]->maximumComponentLength,
            &listLogicalPartitionInfo[i]->fileSystemFlags,
            FileSystemBuffer,
            256                
            );
        listLogicalPartitionInfo[i]->volumeName = string(VolumeNameBuffer);
        listLogicalPartitionInfo[i]->fileSystemName = string(FileSystemBuffer);
        listLogicalPartitionInfo[i]->driverType =  ::GetDriveType(listLogicalPartitionInfo[i]->rootPathName.data());        
    }
    return this->listLogicalPartitionInfo.size();
}

void DiskInfo::DestroyListLogicalPartitions()
{
    while (!listLogicalPartitionInfo.empty())
    {
        delete listLogicalPartitionInfo.back();
        listLogicalPartitionInfo.pop_back();
    }
}

void DiskInfo::DestroyListHardisks()
{
    while (!listHardiskInfo.empty())
    {
        delete listHardiskInfo.back();
        listHardiskInfo.pop_back();
    }
}

void DiskInfo::DestroyAll()
{
    this->DestroyListHardisks();
    this->DestroyListLogicalPartitions();
}

DiskInfo::~DiskInfo()
{
   this->DestroyAll();
}


