// ARRAY

#ifndef __ARRAY_H_
	#define __ARRAY_H_
	
	#include <cstdlib>

template<class T>
class Array{
private:
	T* data;
	int size;
	
	int _Malloc(int size);
	int _Calloc(int n, int sizeOfElement);
	int _Realloc(int size);
public:
	T* get_DataPointer();
	int get_Size();
	int set_Size(int Size, bool tryRealloc);
	
	Array();
	Array(int size);
	~Array();
};
	
#endif