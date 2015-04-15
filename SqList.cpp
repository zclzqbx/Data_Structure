const int LIST_INIT_SIZE=100;
const int LISTINCREMENT=10;

template<typename T>
typedef struct{
	T *elem;
	int length;
	int listsize;
}SqList;

bool SqList_InitList_Sq(SqList &L)
{
	L.elem=new T[LIST_INIT_SIZE];
	if(!L.elem)return 
}
