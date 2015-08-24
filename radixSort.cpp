//radix sort
//基数排序也是基于一种假设，假设所有数都是非负的整数
//基数排序的基本思路是从低位至高位依次比较每个数的对应位，并排序；对应位的比较采用计数排序也可以采用桶排序；
//基数排序是一种稳定的排序方法，不稳定的话也没法排序，因为某一位相同并不代表两个数相同；


#include<iostream>
#include<vector>

using namespace std;

void countSort(vector<int>& vec,int exp)
{//计数排序
	vector<int> range(10,0);

	int length=vec.size();
	vector<int> tmpVec(length,0);

	for(int i=0;i<length;++i)
	{
		range[(vec[i]/exp)%10]++;
	}

	for(int i=1;i<range.size();++i)
	{
		range[i]+=range[i-1];
	}

	for(int i=length-1;i>=0;--i)
	{
		tmpVec[range[(vec[i]/exp)%10]-1]=vec[i];
		range[(vec[i]/exp)%10]--;
	}
	vec=tmpVec;
}

void radixSort(vector<int>& vec)
{
	int length=vec.size();
	int max=-1;
	for(int i=0;i<length;++i)
	{//提取出最大值
		if(vec[i]>max)
			max=vec[i];
	}
	
	//提取每一位并进行比较，位数不足的高位补0
	for(int exp=1;max/exp>0;exp*=10)
		countSort(vec,exp);
}

int main()
{
	int a[10]={53,3,542,748,14,214,154,63,616,589};

	vector<int> vec(a,a+10);
	radixSort(vec);

	for(int i=0;i<vec.size();++i)
	{
		cout<<vec[i]<<"   ";
	}
	
	cout<<endl;
	return 0;
}
