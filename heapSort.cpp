//heap sort
//堆排序可以分为两个过程，其一是建堆，其二是出堆

//堆是一种完全二叉树，所以它可以用数组进行存储；
//堆可分为最大堆和最小堆，最大堆指任一节点的值都大于其左右孩子节点的值，最小堆自不必说；

//STL中有一套完整的堆排序算法，其相关函数包括make_heap\push_heap\pop_heap\sort-heap
//四个函数都是接受一对迭代器作为参数，其作用分别如下：
//push_heap是将新值放入到最后一个迭代器的位置后，进行堆调整；
//pop_heap是将当前堆的最大值放到最后一个迭代器位置，然后进行堆调整；
//make_heap是建堆过程
//sort_heap是堆排序过程
//堆排序需要对迭代器进行大小比较及相减等工作，所以两个迭代器必须是随机存取迭代器；
//priority_queue即是以堆排序为基础的配接器容器，其底层默认以vector实现

#include<vector>
#include<iostream>

using namespace std;

template<class type>
void heapAdjust(vector<type>& vec,int index,int length)
{//堆排序的核心算法：堆调整
	int i=index;
	int j=2*i;

	for(;j<=length;j=j*2)
	{
		if(j+1<=length && vec[j]<vec[j+1])
			j++;//使j指向较大值
		if(vec[i]>vec[j])
			break;
		else
		{//使较大值上浮
			type tmp=vec[i];
			vec[i]=vec[j];
			vec[j]=tmp;
			i=j;
		}
	}
}

template<class type>
void heapSort(vector<type>& vec)
{
	int length=vec.size();
	for(int i=(length-1)>>1;i>=1;--i)
	{//建堆的过程是一个上浮的过程，从底层逐层上浮
		heapAdjust(vec,i,length-1);
	}

	for(int i=length-1;i>1;--i)
	{//出堆过程是一个下沉的过程，从堆底一直沉到底部
		type tmp=vec[1];
		vec[1]=vec[i];
		vec[i]=tmp;
		heapAdjust(vec,1,i-1);
	}
}

int main()
{
	int a[11]={0,1,4,8,5,9,6,3,0,2,7};
	vector<int> vec(a,a+11);

	heapSort(vec);

	for(int i=1;i<vec.size();++i)
	{
		cout<<vec[i]<<"   ";
	}
	cout<<endl;

	return 0;
}
