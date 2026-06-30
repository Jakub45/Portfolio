// L7.cpp : Defines the entry point for the console application.
//          Praca laboratoryjna 7

#include "stdafx.h"
#include <iostream>
#include "coord.h"
#include "interf.h"
#include "my_vect.h"
#include "my_mess.h"

#include <crtdbg.h>
using namespace std;

namespace MY_DATA_GLOBAL {
	coord ob;
	coord *ptr;
};

int _tmain(int argc, _TCHAR* argv[])
{
	try 
	{
		//check of message system
		//my_mess exc(ERR_ALLOC_MEM);
		//my_mess exc1(WARN_NOT_REALIZE);

		int op;  //operacja
		my_interf ifc(2, "filedat.bin");

		while (ifc.run)
		{
			ifc.menu();
			cin >> op;
			system("cls");
			switch (op)
			{
			case MY_INTERF_PUSH: //push
				ifc.push();
				break;
			case MY_INTERF_POP:
				ifc.pop();
				break;
			case MY_INTERF_DISP:
				ifc.disp();
				break;
			case MY_INTERF_FIND:
				ifc.find();
				break;
			case MY_INTERF_SAVE:
				ifc.save();
				break;
			case MY_INTERF_READ:
				ifc.read();
				break;
			case MY_INTERF_SAVE_BIN:
				ifc.save_bin();
				break;
			case MY_INTERF_READ_BIN:
				ifc.read_bin();
				break;
			case MY_INTERF_FINISH:
				ifc.finish();
				break;
			case MY_INTERF_EXP_EXCL:
				ifc.exptoexcel();
				break;
			default:
				ifc.defaul();
			};
		}
	}
	catch (my_mess exc)
	{
		exc.mess();
	}

	return 0;
}

