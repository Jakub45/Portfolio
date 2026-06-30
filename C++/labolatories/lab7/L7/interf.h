//////////////////////////////////////////////////////////////////
//    interf.h

#pragma once

#include "stdafx.h"
#include "my_vect.h"
#include "coord.h"

#define MAX_INTERF_CHAR  512 

enum MY_INTERF
{
	MY_INTERF_PUSH,
	MY_INTERF_POP,
	MY_INTERF_DISP,
	MY_INTERF_FIND,
	MY_INTERF_SAVE,
	MY_INTERF_READ,
	MY_INTERF_SAVE_BIN,
	MY_INTERF_READ_BIN,
	MY_INTERF_EXP_EXCL,
	MY_INTERF_FINISH,
	MY_INTERF_TOT	
};

class my_interf
{
	static const char *str_interf[];
	my_vect<coord> vect;

public:
	bool run;
	my_interf(size_t dim, const char *f_name_bin);
	void menu();
	void push();
	void pop();
	void disp();
	void find();
	void save();
	void read();
	void save_bin();
	void read_bin();
	void exptoexcel();
	void finish();
	void defaul();
};