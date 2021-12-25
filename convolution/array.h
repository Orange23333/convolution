// ARRAY

#ifndef __ARRAY_H_
	#define __ARRAY_H_
	
	#include <cstdlib>

template<class T>
class Array{
private:
	T* data;
	int size;
	
	int _Malloc(int size){
		free(data);
		data=(T*)malloc(size);
		if(data==NULL){
			return this->size=0;
		}
		return this->size=size;
	}
	int _Calloc(int n, int sizeOfElement){
		free(data);
		data=(T*)calloc(n, sizeOfElement);
		if(T==NULL){
			return this->size=0;
		}
		return this->size=n*sizeOfElement;
	}
	int _Realloc(int size){
		free(data);
		data=(T*)realloc(data, size);
		if(T==NULL){
			return this->size=0;
		}
		return this->size=size;
	}
	void _Free(){
		free(data);
		size=0;
	}
public:
	T* get_DataPointer(){
		return data;
	}
	int get_Size(){
		return size;
	}
	int set_Size(int Size, bool tryRealloc){
		if(tryRealloc){
			return _Realloc(size);
		}else{
			return _Malloc(size);
		}
	}
	void Free(){
		_Free();
	}
	
	Array(){
		this->data=NULL;
		this->size=0;
	}
	Array(int size){
		_Malloc(size);
	}
	~Array(){
		_Free();
	}
};

#endif