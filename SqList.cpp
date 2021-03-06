#include"SqList.h"
template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize=MaxListSize;
	elem=new T[MaxSize];
	length=0;
}
template<class T>
bool LinearList<T>::find(int k,T& x)const
{
	if(k<1 || k>length)return false;
	x=elem[k-1];
	return true;
}
template<class T>
int LinearList<T>::search(T& x)const
{
	for(int i=0;i<length;++i)
	{
		if(elem[i]==x)return++i;
	}
	return 0;
}
template<class T>
AbstractList<T> & LinearList<T>::Delete(int k,T& x)
{
	if(find(k,x))
	{
		for(int i=k-1;i<length-1;++i)
		{
			elem[i]=elem[i+1];
		}
		length--;
		return *this;
	}
	else throw OutOfBounds();
}
template<class T>
AbstractList<T> & LinearList<T>::insert(int k,T& x)//在第k个元素之前插入数据
{
	if(k<1 || k>length+1)
		throw OutOfBounds();
	if(length==MaxSize)
		throw NoMem();

	for(int i=length-1;i>=k-1;--i)
	{
		elem[i+1]=elem[i];
	}
	elem[k-1]=x;
	length++;
	return *this;
}
