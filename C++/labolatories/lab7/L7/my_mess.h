/////////////////////////////////////////////////////////////////////////
//   my_mess.h

#pragma once

#define MAX_CHARS 512

enum MY_MESSAGE
{
	ERR_ALLOC_MEM,
	ERR_OPEN_FILE,
	ERR_WRITE_FILE,
	ERR_READ_FILE,
	WARN_ARR_FULL,
	WARN_ARR_EMPTY,
	WARN_START_EXCEL,
	WARN_ARR_UNKNOP,
	WARN_NOT_REALIZE,
	TOT_NUMB
};

class my_mess
{
	static const char *strtab[];

public:
	my_mess(enum MY_MESSAGE ms);
	void mess();	
};