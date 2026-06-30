/////////////////////////////////////////////////////////////////
//   my_mess.cpp

#include "stdafx.h"
#include <iostream>
#include "my_mess.h"
using namespace std;

//text row array:
const char* my_mess::strtab[] =
{
	"E memory allocation error",		//ERR_ALLOC_MEM 
	"E open file error",				//ERR_OPEN_FILE
	"E write file error",				//ERR_WRITE_FILE
	"E read file error",				//ERR_READ_FILE
	"W array is full",					//WARN_ARR_FULL 
	"W array is empty",					//WARN_ARR_EMPTY
	"W excel call error",				//WARN_START_EXCEL
	"W unknown operation",				//WARN_ARR_UNKNOP
	"W not realize in current version"	//WARN_NOT_REALIZE
};

my_mess::my_mess(enum MY_MESSAGE ms)
{
	cout << &strtab[ms][1] << endl;

	if (strtab[ms][0] == 'E')
	{
		throw* this;
	}	
}

void my_mess::mess()
{
	system("pause");
}