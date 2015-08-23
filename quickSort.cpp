//quick sort
//STL中也有现成的快速排序算法，内部实现采用了以下技巧
//1）枢轴的选择采取三数取中的方式
//2）后半段采取循环的方式实现
//3）快速排序与插入排序结合
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

//这一版本是最简单实现版本，对于快速排序的优化主要有以下几个方面：
//1）枢轴的选择，若枢轴选取不全适，比如，若每次递归时，两个子区间中的一个为空，则快速排序将退化为冒泡排序
//关于枢轴的选择有多种：取最后一个元素、取第一个元素、三数取中、九数取中、随机值等
//2）另一方面是对迭代过程的优化，减少交换次数，减少递归深度等；
template<class type>
int partion1(vector<type>& vec,int start,int end)
{//快速排序的核心部分
	//取最后一个作为枢轴和第一个作为枢轴程序类似，以下是取最后一个元素作为枢轴
	int key=vec[end];
	int fast,slow;
	fast=slow=start;

	//用两个指针的移动实现
	for(;fast<end;++fast)
	{
		if(vec[fast]<key)
		{
			if(fast!=slow)
			{
				int tmp=vec[slow];
				vec[slow]=vec[fast];
				vec[fast]=tmp;
			}
			slow++;
		}
	}
	int tmp=vec[slow];
	vec[slow]=vec[end];
	vec[end]=tmp;
	return slow;
}

//三数取中
template<class type>
int midNumber(type a,type b,type c)
{
	int big1=max(a,b);
	int big2=max(a,c);
	int big3=max(b,c);

	return min(big1,min(big2,big3));
}

template<class type>
int partion2(vector<type>& vec,int start,int end)
{
	//3数取中和9数取中的方式，保证了一定随机性，以下是3数取中的方式
	int key=midNumber(vec[start],vec[(start+end)/2],vec[end]);

	int midNumPos=0;
	if(key==vec[start])
		midNumPos=start;
	else if(key==vec[end])
		midNumPos=end;
	else
		midNumPos=(start+end)/2;

	vec[midNumPos]=vec[end];
	vec[end]=key;

	//现在采用一种和上一种方案不同的交换方式
	while(start<end)
	{//枢轴的位置一直在改变
		while(start<end && vec[start]<=key)
			start++;

		int tmp=vec[start];
		vec[start]=vec[end];
		vec[end]=tmp;

		while(start<end && vec[end]>=key)
			end--;

		tmp=vec[start];
		vec[start]=vec[end];
		vec[end]=tmp;
	}

	return start;
}

template<class type>
int partion3(vector<type>& vec,int start,int end)
{//取随机数的方法
	int keyNumPos=start+rand()%(end-start);
	int tmp=vec[keyNumPos];
	vec[keyNumPos]=vec[end];
	vec[end]=tmp;

	int key=vec[end];
	while(start<end)
	{//枢轴的位置一直在改变
		while(start<end && vec[start]<=key)
			start++;

		tmp=vec[start];
		vec[start]=vec[end];
		vec[end]=tmp;

		while(start<end && vec[end]>=key)
			end--;

		tmp=vec[start];
		vec[start]=vec[end];
		vec[end]=tmp;
	}
	return start;
}
//以上是三种对枢轴的优化方法，无非就是避免快速排序恶化
//以下是避免不必要的交换过程
template<class type>
int partion4(vector<type>& vec,int start,int end)
{//取随机数的方法
	int keyNumPos=start+rand()%(end-start);
	int tmp=vec[keyNumPos];
	vec[keyNumPos]=vec[end];
	vec[end]=tmp;

	int key=vec[end];
	while(start<end)
	{//观察可知，交换的过程中，总有一个数是key，所以当需要赋key值时可以直接跳过，于是可以减少赋值操作
		while(start<end && vec[start]<=key)
			start++;

		vec[end]=vec[start];//end以start覆盖

		while(start<end && vec[end]>=key)
			end--;

		vec[start]=vec[end];//start以end覆盖
	}
	vec[start]=key;
	return start;
}


template<class type>
void qSort1(vector<type>& vec,int start,int end)
{
	if(start>=end)return;
	int index=partion4(vec,start,end);//key
	qSort1(vec,start,index-1);
	qSort1(vec,index+1,end);
}

//递归过程需要出栈入栈，成本较高，而且可能栈溢出，如果可能的话最好以循环方式代替递归
template<class type>
void qSort2(vector<type>& vec,int start,int end)
{
	if(start>=end)return;
	
	int index;//key
	while(start<end)
	{//后半段的递归过程以循环代替，相当于减小了递归深度
		index=partion4(vec,start,end);//key
		qSort2(vec,start,index-1);
		start=index+1;
	}
}


//当处理的数据量比较小时，插入排序的成本可能比快速排序成本更低，所以考虑在数据量较小时采用插入排序

/*template<class type>
void qSort3(vector<type>& vec,int start,int end)
{
	if(start>=end)return;
	
	int index;//key
	if(end-start>VALUE)
	{	
		while(start<end)
		{//后半段的递归过程以循环代替，相当于减小了递归深度
			index=partion4(vec,start,end);//key
			qSort3(vec,start,index-1);
			start=index+1;
		}
	}
	else
	{
		insertSort(vec,start,end);
	}
}*/

template<class type>
void quickSort(vector<type>& vec)
{
	int length=vec.size();
	qSort2(vec,0,length-1);
}

int main()
{
	int a[10]={1,5,9,0,6,3,2,7,8,4};
	vector<int> vec(a,a+10);

	quickSort(vec);

	for(int i=0;i<vec.size();++i)
		cout<<vec[i]<<"  ";
	cout<<endl;
	return 0;
}
