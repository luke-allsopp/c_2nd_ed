//3.1 - rewrite binsearch with 1 test inside loop.
//
#include <stdio.h>

int binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n-1;
	while(low<high)	{
		mid = (low+high) / 2;	//set mid
		if(x<=v[mid]) {			
			high = mid;			//narrow scope down to low if < mid
		}
		else {
			low = mid +1;		//narrow scope up to low if > mid
		}
	}
	if(x == v[low]) {
		return low;
	}
	return -1;				//no match
}

int main()
{
	int test[] ={14,1,2,3,4,5,6,7,8,9,10,11,12,13};
	int n = 13;
	
	printf("OUTPUT:\t%d\n", binsearch(20,test,n));
}
