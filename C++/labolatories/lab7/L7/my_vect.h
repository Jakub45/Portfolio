////////////////////////////////////////////////////////////////////
//    my_vect.h
#ifndef MY_VECT_13243657_INCLUDE__H
#define MY_VECT_13243657_INCLUDE__H

#pragma once

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "windows.h"
#include "my_mess.h"
#include "interf.h"
using namespace std;

#define USE_EXTRACT_INSERT_OPERATORS

template <class T> class my_vect
{
	T *dat;        //array of the generic type
	size_t ndim;   //dimension of array, on which memory is allocated
	size_t last;   //indeks of the first empty position in array
	fstream flbin;    //stream for binary file to be store/restore data
	char filenamebin[MAX_PATH];  //name of binary file

public:
	my_vect() : dat(NULL), ndim(0), last(0) { }
	~my_vect();
	void init(size_t dm, const char *f_name_bin);      //if dat == NULL, allocates memory on dm elements
	T *get_begin() { return dat; }
	T *get_end(); 
	size_t my_size() { return last; }
	void push(const T &ob); //add element of type T to the first empty position (last)
	T *pop();               //returns pointer to the last filled element, or returns NULL, if an array is empty.

	void exptoexcel();

	T& operator [] (const size_t ind)
	{
		return dat[ind];
	}
	
#ifdef USE_EXTRACT_INSERT_OPERATORS
	fstream & get_file() { return flbin; }
	template<class T> friend ostream & operator << (ostream& strm,  const my_vect<T> & ob);
	template<class T> friend fstream & operator << (fstream& flbin, const my_vect<T> & ob);
	template<class T> friend fstream & operator >> (fstream& flbin,       my_vect<T> & ob);
#else
	void disp();            //display an array
	void save_bin();
	void read_bin();
#endif
	
private:
	void realloc();
};

template <class T>
void my_vect<T>::init(size_t dm, const char *f_name_bin)
{
	if(dat)
		return;

	ndim = dm;
	try
	{
		dat = new T [ndim];
	}
	catch(std::bad_alloc)
	{
		my_mess exc(ERR_ALLOC_MEM);		
	}

	//Open file. if file exists, their content does not lose.
	//If file does not exists, its length will be 0 (new job).
	sprintf_s(filenamebin, sizeof(filenamebin), f_name_bin);
	
	//Does file exists?
	char pathbuffer[_MAX_PATH];
	_searchenv(filenamebin, "PATH", pathbuffer);
	if(pathbuffer[0] == '\0')
	{
		//file does not exists, creates a new file for stream ofstream and closes it.
		ofstream tmpfl(filenamebin);
		tmpfl.close();
	}

	//File must be opened
	flbin.open(filenamebin, ios_base::in | ios_base::out);
	if(!flbin.is_open())
		my_mess exc(ERR_OPEN_FILE);
}

template <class T>
my_vect<T>::~my_vect()
{
	if(dat)
		delete [] dat;
	dat = NULL;
	
	//close file
	flbin.close();
}

template <class T>
inline T * my_vect<T>::get_end()
{
	if(dat)
		return &dat[last];
	else
		return NULL;
}


template <class T>
void my_vect<T>::push(const T &ob)
{
	//if(last >= ndim)
	//{
	//	my_mess exc(WARN_ARR_FULL);
	//	return;
	//}
	realloc();
	dat[last] = ob;
	last++;
}

template <class T>
T *my_vect<T>::pop()
{
	if(last > 0)
	{
		last--;
		return &dat[last];
	}
	return NULL;	
}

template <class T>
void my_vect<T>::realloc()
{
	try
	{
		if (last >= ndim)
		{
			T * new_dat = new T[2 * ndim];
			std::copy(get_begin(), get_end(), new_dat);  //OK, operator = class of data is called.
			//memcpy(new_dat, dat, ndim * sizeof(T));    //Improper use for objects C++ !!! Operator = for class of data is not called !!!
			delete[] dat;
			dat = new_dat;
			ndim *= 2;
		}
	}
	catch (std::bad_alloc)
	{
		my_mess ms(ERR_ALLOC_MEM);
	}	
}

template <class T>
void my_vect<T>::exptoexcel()
{
	//creates a file
	ofstream flexcl("filedat.csv");  //to be export to EXCEL
	if (!flexcl.is_open())
		my_mess exc(ERR_OPEN_FILE);

	size_t it;
	for (it = 0; it < last; it++)
	{
		flexcl << &dat[it];
		if (flexcl.bad())
			my_mess exc(ERR_WRITE_FILE);
	}
	flexcl.close();

	//starts excel
	char wstr[] = "start EXCEL.EXE filedat.csv";
	//char wstr[] = "start C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe filedat.csv";
	system(wstr);
}

#ifdef USE_EXTRACT_INSERT_OPERATORS

template <class T>
ostream& operator << (ostream& strm, const my_vect<T>& ob)
{
	for (size_t it = 0; it < ob.last; ++it)
		strm << ob.dat[it];

	return strm;
}

template <class T>
fstream& operator << (fstream& flbin, const my_vect<T>& ob)
{
	size_t it;
	flbin.clear();
	flbin.close();
	flbin.open(ob.filenamebin, ios_base::in | ios_base::out | ios_base::trunc);
	if (!flbin.is_open())
		my_mess exc(ERR_OPEN_FILE);

	for (it = 0; it < ob.last; it++)
	{
		flbin << &ob.dat[it];
		if (flbin.bad() || flbin.fail())
			my_mess exc(ERR_WRITE_FILE);
	}

	return flbin;
}

template <class T>
fstream& operator >> (fstream& flbin, my_vect<T>& ob)
{
	ob.last = 0;
	T tmp;
	flbin.clear();
	flbin.seekg(0);

	while (!flbin.eof())
	{
		flbin >> &tmp;
		if (flbin.bad())
			my_mess exc(ERR_READ_FILE);
		if (flbin.eof())
			break;
		ob.push(tmp);
	}

	return flbin;
}

#else
template <class T>
void my_vect<T>::disp()
{
	size_t it;
	for (it = 0; it < last; it++)
	{
		cout << "it = " << it << " " << dat[it] << endl;
	}
}

template <class T>
void my_vect<T>::read_bin()
/*===============================================================
read data from binary file
================================================================*/
{
	last = 0;
	flbin.clear();
	flbin.seekg(0);
	T tmp;

	while (!flbin.eof())
	{
		flbin >> &tmp;

		if (flbin.bad() /*|| numbytestoread != flbin.gcount()*/)
			my_mess exc(ERR_READ_FILE);

		if (flbin.eof())
			break;

		push(tmp);
	}
}

template <class T>
void my_vect<T>::save_bin()
/*===============================================================
save data to binary file
================================================================*/
{
	size_t it;
	flbin.clear();
	flbin.close();
	flbin.open(filenamebin, ios_base::in | ios_base::out | ios_base::trunc);
	if(!flbin.is_open())
		my_mess exc(ERR_OPEN_FILE);
	
	for (it = 0; it < last; it++)
	{
		flbin << &dat[it];
		if (flbin.bad() || flbin.fail())
			my_mess exc(ERR_WRITE_FILE);
	}
}
#endif


template <class T, class Key>
T * Find(const T *p_begin, const T *p_end, const Key &k)
/*======================================================
Find element of array T *dat
Start from T *p_begin - pointer to the element to be started
Key k - key of search
There is necessary to overload operator == for class T
according with type of Key
1. First search: p_begin = &dat[0]
2. Second search: p_begin = &(result of previous search++)
=======================================================*/
{
	//size_t it;
	if(p_begin > p_end)
		return NULL;
	const T *p_tmp = p_begin;
	for(; p_tmp != p_end; p_tmp++)
	{
		if(*p_tmp == k)
			return const_cast<T *>(p_tmp);
	}

	return NULL;
}


#endif