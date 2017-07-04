#include <bits/stdc++.h>
using namespace std;

typedef struct ST
{
	int low;
	int high;
	int sum;
}ST;

queue<ST>makeSegTree;
void assignment(vector<ST>& segTree, vector<int> a, int index)
{
	if(segTree[index].low==segTree[index].high)
	{
		segTree[index].sum=a[segTree[index].low];
	}	
	else
	{
		assignment(segTree,a,2*index+1);
		segTree[index].sum=segTree[2*index+1].sum;
		if(2*index+2<segTree.size())
		{		
			assignment(segTree,a,2*index+2);
			segTree[index].sum+=segTree[2*index+2].sum;
		}	
	}	
}

int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	vector<ST>segTree;
	ST temp;
	temp.low=0;
	temp.high=n-1;
	makeSegTree.push(temp);
	while(!makeSegTree.empty())
	{
		temp=makeSegTree.front();
		segTree.push_back(temp);
		if(temp.low!=temp.high)
		{
			ST temp2;
			temp2.low=temp.low;
			temp2.high=(temp.low+temp.high)/2;
			makeSegTree.push(temp2);
			temp2.low=(temp.low+temp.high+2)/2;
			temp2.high=temp.high;
			makeSegTree.push(temp2);
		}	
		makeSegTree.pop();
	}	
	assignment(segTree,a,0);
	for (ST i: segTree)
	{
		printf("(%d,%d,%d)\n",i.low,i.high,i.sum);
	}	
	return 0;
}