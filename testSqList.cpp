#include<iostream>
#include"SqList.h"

using namespace std;

int main()
{
	try
	{
		LinearList<int> L(5);
		cout<<"Length="<<L.length()<<endl;
		cout<<"isEmpty="<<L.isEmpty()<<endl;
		L.insert(0,2).insert(1,6);
		cout<<"List is"<<L<<endl;
		cout<<"isEmpty="L.isEmpty()<<endl;
		int z;
		L.find(1,z);
		cout<<"first element is"<<z<<endl;
		L.Delete(1,z);
		cout<<"Deleted element is "<<z<<endl;
		cout<<"List is "<<L<<endl;
	}
	catch(...)
	{
		cerr<<"An Exception has occured!"<<endl;
	}
	return 0;
}
