//============================================================================
// Name        : driverlinx.cpp
// Author      : FrancescoDiSalesGithub
// Version     :
// Copyright   : GNU General Public License
// Description : Device Enumerator
//============================================================================

#include <iostream>
#include<string>

#include<cstring>
#include<mntent.h>

#define MAX_DEVICES 10

using namespace std;

int main()
{

	FILE* mountTable = setmntent("/etc/mtab","r");
	char* dev = "dev";
  
	string devices[MAX_DEVICES];
	int iteratorDevice=0;

	while(fgetc(mountTable)!=EOF)
	{
		   struct mntent* mountTableMemory = getmntent(mountTable);

		   if(strstr(mountTableMemory->mnt_fsname,dev))
		   {
			   if(strlen(mountTableMemory->mnt_fsname)>4)
			   {
  				   string mypath (mountTableMemory->mnt_fsname);
	  			   devices[iteratorDevice] = mypath;
		  		   iteratorDevice++;
			    }
		   }

		}


		for(int i=0;i<iteratorDevice;j++)
		{
			cout<<devices[i]<<endl;
		}


	return 0;
}
