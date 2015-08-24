#include<iostream>
#include<vector>

using namespace std;

template<class type>
void mergeSort(vector<type>& vec,int start,int mid,int end)
{
	vector<type> tmpVec(end-start+1,0);
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

	for(int k=start;k<=end;++k)
	{
		vec[k]=tmpVec[k-start];
	}
}

template<class type>
void mergeSort(vector<type>& vec)
{
	int gap=1;
	int length=vec.size();

	while(gap<length)
	{
		int i;
		for(i=0;i+2*gap-1<length;i+=2*gap)
		{
			merge(vec,i,i+gap-1,i+2*gap-1);
		}
		if(i+gap-1<length)
		{
			merge(vec,i,i+gap-1,length-1);
		}
		gap*=2;
	}	
}

int main()
{
	int a[10]={5,8,9,6,7,2,1,3,0,4};
	vector<int> vec(a,a+10);

	mergeSort(vec);

	for(int i=0;i<vec.size();++i)
	{
		cout<<vec[i]<<"   ";
	}
	return 0;
}
