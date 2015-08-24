//shell sort
//希尔排序是一种对直接插入排序的改进方法，
//使用直接插入排序对于一个基本有序的数列进行排序时，内部循环的次数会明显减少，因此可以减小时间复杂度；
//希尔排序就是先使数列基本有序，然后再直接插入排序，减小插入排序的时间复杂度；
//希尔排序首先按一定增量进行插入排序，再逐步缩减增量，当这一增量缩减至1时，希尔排序变为直接插入排序；
//所以这一增量的选取很关键，且这一增量最后必须缩减至1；
//直接插入排序是一种稳定的排序方法，但希尔排序不是，因为它是跳跃着排序；
//希尔排序虽然是一种比O（n^2)高效的排序算法，但复杂度仍比快速排序、堆排序等恶劣；

#include<vector>
#include<iostream>

using namespace std;

template<class type>
void shellSort(vector<type>& vec)
{
	int length=vec.size();

	int increment=length;
	while(increment>1)//增量最后必须缩减至1，否则无法保证有序
	{
		increment=increment/3+1;//增量缩减
		for(int i=increment;i<length;i++)
		{//按增量进行插入排序
			int key=vec[i];
			int j=i-increment;
			for(;j>=0;j-=increment)
			{//寻找key的正确插入位置
				if(vec[j]>key)//元素后移
					vec[j+increment]=vec[j];
				else
				{
					break;
				}
			}
			vec[j+increment]=key;//插入key
		}
	}
}

int main()
{
	int a[10]={1,5,6,0,2,8,3,7,9,4};
	vector<int> vec(a,a+10);
	shellSort(vec);

	for(int i=0;i<vec.size();++i)
	{
		cout<<vec[i]<<"   ";
	}
	cout<<endl;	
	return 0;
}
