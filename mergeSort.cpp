//merge sort

//归并排序是通过将两个有序的数列合并成一个有序的数列的排序过程；
//具体流程可以看成一个树形结构，最底层是两个结点合并，往上合并的结点个数越多，所以时间复杂度为O（nlgn)；


#include<iostream>
#include<vector>

using namespace std;

//二路归并，当然也可以多路归并
template<class type>
void merge(vector<type>& vec,int start,int mid,int end)
{//合并过程，将[start,mid],[mid+1,end]两个有序的数列合并成一个有序数列，并放到[start,end]中
	vector<type> tmpVec(end-start+1,0);//临时数组，归并排序的时间复杂度为O（n）；
	int index=0;
	int i=start;
	int j=mid+1;
	
	while(i<=mid && j<=end)
	{
		if(vec[i]<vec[j])
			tmpVec[index++]=vec[i++];
		else
			tmpVec[index++]=vec[j++];
	}

	while(i<=mid)
		tmpVec[index++]=vec[i++];

	while(j<=end)
		tmpVec[index++]=vec[j++];

	for(int k=start;k<=end;++k)//将归并后的数列复杂回原数组
	{
		vec[k]=tmpVec[k-start];
	}
}

//循环方法
template<class type>
void mergeSort_l(vector<type>& vec)
{
	int gap=1;//初始gap
	int length=vec.size();

	while(gap<length)
	{
		int i;
		for(i=0;i+2*gap-1<length;i+=2*gap)
		{
			merge(vec,i,i+gap-1,i+2*gap-1);
		}

		if(i+gap-1<length)//最后还剩下两个未合并数列
		{
			merge(vec,i,i+gap-1,length-1);
		}
		gap*=2;//gap增加
	}	
}


//递归方法
template<class type>
void mSort(vector<type>& vec,int start,int mid,int end)
{
	if(start==end)
		return;
	else
	{
		mSort(vec,start,(start+mid)/2,mid);//先归并左半子区间
		mSort(vec,mid+1,(mid+end+1)/2,end);//再归并右半子区间
		merge(vec,start,mid,end);//最后将两个子区间合并为一个
	}
}

template<class type>
void mergeSort_r(vector<type>& vec)
{
	int length=vec.size();
	mSort(vec,0,length/2,length-1);
}

int main()
{
	int a[10]={5,8,9,6,7,2,1,3,0,4};
	vector<int> vec(a,a+10);

	mergeSort_r(vec);

	for(int i=0;i<vec.size();++i)
	{
		cout<<vec[i]<<"   ";
	}
	return 0;
}
