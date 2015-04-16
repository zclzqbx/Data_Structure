#include"AbstractList.h"
template<class T>
class LinearList:AbstractList<T>{
	public:
		LinearList(int MaxListSize=10);
		~LinearList(){delete [] elem;}
		bool isEmpty()const{return length==0};
		int length()const{return length;}
		bool find(int k,T&x)const;
		int search(const T&x)const;
		AbstractList<T>& Delete(int k,T& x);
		AbstractList<T>& insert(int k,const T &x);

		void Output(ostream & out)const;
	private:
		int length;
		int MaxSize;
		T *elem;

};
