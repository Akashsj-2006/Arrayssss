#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void brute_force_MaxOnes(vector<int> arr, int n)
{
    int ct=0,  maxi=0;
    int tempstart=0;
    int start=-1;
    int end=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            if(ct==0)
            {
                tempstart=i;
            }
            
            ct++;
            if(ct>maxi)
            {
                maxi = ct;
                start = tempstart;
                end = i;
                
            }
            
        }
        
        else
        {
            ct=0;
        }
    }
    
    cout<<"The maximum number of consecutive ones: "<<maxi<<endl;
    cout<<"Starting Index: "<<start<<endl;
    cout<<"Ending Index: "<<end;
}
int main()
{
    vector<int> arr= {1,1,1,0,0,1,1,0,1,1,1,1,1,0,1};
    int n = arr.size();
    brute_force_MaxOnes(arr, n);
    
}