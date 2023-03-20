//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}

//brute force   T.C->O(N*N) S.C->O(1)
int missingNumber(int A[], int N)
{
    for(int i =1 ;i<=N;i++){
      int flag =0;
      for(int j =0;j<N-1;i++){
          if(A[j]==i){
            flag = 1;
            break;
          }
      }
      if(flag==0)
          return i;
    }
}

//Better solution   T.C->O(2N) S.C=O(N)
int missingNumber(int A[], int N)
{
    int hash[N+1];
    for(int i =0;i<N+1;i++){
      hash[A[i]] =1;
    }
    for(int i =1;i<N;i++){
      if(hash[A[i]] ==0){
        return i;
      }
    }
}

//Optimal solution using sum in T.C->O(N)  S.C=O(1)
int missingNumber(int A[], int N)
{
    int sum = N*(N+1)/2;
    int s =0;
    for(int i =0;i<N-1;i++){
      s+=A[i];
    }
    return sum-s;
}


//Best optimal solution in T.C->O(N) using xor S.C=O(1)
/*
  XOR a^a=0;
      a^0=a;
*/
int missingNumber(int A[], int N)
{
    // Your code goes here
    int xor1 =0;
    int xor2 = 0;
    
    for(int i =0;i<N-1;i++){
        xor2 ^=A[i];
        xor1 ^=(i+1);
    }
    xor1^=N;
    return xor1^xor2;
}
