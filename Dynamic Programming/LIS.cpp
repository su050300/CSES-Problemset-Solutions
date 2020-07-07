#include <bits/stdc++.h>
using namespace std;

int main() {
     int n;
     cin>>n;
     vector<int>dp;
     for(int i=0;i<n;i++)
     {
         int x;
         cin>>x;
         auto it=lower_bound(dp.begin(),dp.end(),x);
         if(it==dp.end())
         {
             dp.push_back(x);
         }
         else
         {
             *it=x;
         }
        //  for(int d:dp)
        //  {
        //      cout<<d<<" ";
        //  }
        //  cout<<endl;
     }
     cout<<dp.size()<<endl;
     return 0;
}
/*
 when we are inserting a value for it to be part of the increasing subsequence it must be greater than the previous
 value.else we can find the position of this value in the dp array and change the value at position to x.since the 
 values does not matter this helps in extension of the longest increasing subsequence for the upcoming values.
*/