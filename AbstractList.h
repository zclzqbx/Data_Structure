template<class t>
class AbstractList{
	public:
		virtual bool isEmpty()const=0;
		virtual int length()const=0;
		virtual bool find(int k,T &x)const=0;
		virtual int search(const T &x)const=0;
		virtual AbstractList<T>& Delete(int k,const T& x)=0;
		virtual AbstractList<T>& insert(int k,const T& x)=0;
		virtual void Output(ostream& out)const=0;
};
