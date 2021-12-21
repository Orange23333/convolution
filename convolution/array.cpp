// ARRAY

#include "array.h"

template<class T>
T* Array<T>::get_DataPointer(){
	return data;
}

template<class T>
int Array<T>::get_Size(){
	return size;
}
template<class T>
int Array<T>::set_Size(int Size, bool tryRealloc){
	if(tryRealloc){
		return _Realloc(size);
	}else{
		return _Malloc(size);
	}
}

template<class T>
int Array<T>::_Malloc(int size){
	free(data);
	data=(T*)malloc(size);
	if(T==NULL){
		return this->size=0;
	}
	return this->size=size;
}

template<class T>
int Array<T>::_Calloc(int n, int sizeOfElement){
	free(data);
	data=(T*)calloc(n, sizeOfElement);
	if(T==NULL){
		return this->size=0;
	}
	return this->size=n*sizeOfElement;
}

template<class T>
int Array<T>::_Realloc(int size){
	free(data);
	data=(T*)realloc(data, size);
	if(T==NULL){
		return this->size=0;
	}
	return this->size=size;
}

template<class T>
Array<T>::Array(){
	this->data=NULL;
	this->size=0;
}
template<class T>
Array<T>::Array(int size){
	_Malloc(size);
}
template<class T>
Array<T>::~Array(){
	free(data);
}