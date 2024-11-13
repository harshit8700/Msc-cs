#include <iostream>
#include<vector>
using namespace std;

int longest_increase_seq(int* A,int n, int curr, int prev,vector<vector<int>> &dp)
{
  if(curr >= n){
    return 0;
  }
  if(dp[curr][prev+1] != -1)
    return dp[curr][prev+1];
  
  // take
  int pick = 0;
  if(prev == -1 || A[curr] > A[prev]){
    pick = 1 + longest_increase_seq(A,n,curr+1,curr,dp);
  }
  //leave
  int skip = 0;
  skip = 0 + longest_increase_seq(A,n,curr+1,prev,dp);
  return dp[curr][prev+1] = max(pick,skip);
}

int main() 
{
    cout << "Hello, World!";
    int arr[] = {0,1,0,3,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>> dp(n,vector<int> (n+1,-1));
    int ans = longest_increase_seq(arr,n,0,-1,dp);
    cout<<"\n"<<ans<<endl;
    return 0;
}
