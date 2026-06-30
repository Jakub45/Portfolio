///////////////////////////////////////////////////////////////////
//   interf.cpp

#include "stdafx.h"
#include <iostream>
#include "interf.h"
#include "my_vect.h"

using namespace std;

namespace MY_DATA_GLOBAL {
	extern coord ob;
	extern coord *ptr;
};

using namespace MY_DATA_GLOBAL;

//text row array
const char* my_interf::str_interf[] = {
	"0 - push",							//MY_INTERF_PUSH
	"1 - pop", 							//MY_INTERF_POP
	"2 - disp", 						//MY_INTERF_DISP
	"3 - find", 						//MY_INTERF_FIND
	"4 - save", 						//MY_INTERF_SAVE
	"5 - read", 						//MY_INTERF_READ
	"6 - save binary", 					//MY_INTERF_SAVE_BIN
	"7 - read binary", 					//MY_INTERF_READ_BIN
	"8 - export to excel",				//MY_INTERF_EXP_EXCL
	"9 - finish"						//MY_INTERF_FINISH
};

my_interf::my_interf(size_t dim, const char *f_name_bin)
{
	vect.init(dim, f_name_bin);
	run = true;
}

void my_interf::menu()
{
	int i;
	for(i=0; i<MY_INTERF_TOT; i++)
	{
		cout << str_interf[i] << endl;
	}
}

void my_interf::push()
{
	cin >> ob;
	vect.push(ob);
}

void my_interf::pop()
{
	ptr = vect.pop();
	if(ptr)
		cout << *ptr;
	else
	{
		my_mess exc(WARN_ARR_EMPTY);
		cout << endl;
	}
}

void my_interf::disp()
{
	//vect.disp();
	for (size_t it = 0; it < vect.my_size(); ++it)
		cout << vect[it];
}

void my_interf::find()
{
	cout << "input x, y - object for search\n";
	cin >> ob;
	ptr = vect.get_begin();
	size_t dist;
	while(ptr)
	{
		ptr = Find(ptr, vect.get_end(), ob);
		if(ptr)
		{
			dist = ptr-vect.get_begin();
			cout << "it = " << dist << " " << *ptr;
			ptr++;
		}
		else
			cout << "search end\n";
	}
}

void my_interf::save()
{
#ifdef USE_EXTRACT_INSERT_OPERATORS
	ofstream file_text_in("file_text.txt");
	if (!file_text_in)
		my_mess ms(ERR_OPEN_FILE);

	file_text_in << vect;

	file_text_in.close();

	system("notepad.exe file_text.txt");
#else
	my_mess exc(WARN_NOT_REALIZE);
#endif
}

void my_interf::read()
{
	my_mess exc(WARN_NOT_REALIZE);
}

void my_interf::save_bin()
{
#ifdef USE_EXTRACT_INSERT_OPERATORS
	vect.get_file() << vect;
#else
	vect.save_bin();
#endif
}

void my_interf::read_bin()
{
#ifdef USE_EXTRACT_INSERT_OPERATORS
	vect.get_file() >> vect;
#else
	vect.read_bin();
#endif	
}

void my_interf::exptoexcel()
{
	vect.exptoexcel();
}

void my_interf::finish()
{
	run = false;
}

void my_interf::defaul()
{
	my_mess exc(WARN_ARR_UNKNOP);
}

