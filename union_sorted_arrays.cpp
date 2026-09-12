#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void BruteForce_union(vector<int> arr1, vector<int> arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    set <int> s;
    for(int i=0;i<n1;i++)
        {
            s.insert(arr1[i]);
        }
    for(int i=0;i<n2;i++)
        {
            s.insert(arr2[i]);
        }

    cout<<"\nThe Brute force solution: ";
    for(auto i: s)
        {
            cout<<i<<" ";
        }
    cout<<endl;
}

void Optimal_union(vector<int>arr1, vector<int> arr2)
{
    vector<int> UnionArr;
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i=0, j=0;
    while(i<n1 && j<n2)
        {
            if(arr1[i] <= arr2[j])
            {
                if(UnionArr.size()==0||UnionArr.back() != arr1[i])
                {
                    UnionArr.push_back(arr1[i]);
                }
                i++;
            }

            else
            {
                if(UnionArr.size()==0 || UnionArr.back() != arr2[j])
                {
                    UnionArr.push_back(arr2[j]);
                    
                }
                j++;
            }
        }

    while(i<n1)
        {
            if(UnionArr.size() ==0 || UnionArr.back() != arr1[i])
                UnionArr.push_back(arr1[i]);
            i++;
        }
    while(j<n2)
        {
            if(UnionArr.size() ==0 || UnionArr.back() != arr2[j])
                UnionArr.push_back(arr2[j]);
            j++;
        }

    cout<<"\nThe Optimal solution: ";
    for(int i=0;i<UnionArr.size();i++)
        {
            cout<<UnionArr[i]<<" ";
        }
    cout<<endl;
}

int main()
{
    vector<int> arr1 = {1,1,2,3,4,4,5,67,78};
    vector<int> arr2 = {3,3,4,5,6,7,8,78};
    BruteForce_union(arr1, arr2);//O(nlogn)
    Optimal_union(arr1, arr2);//O(n)
    return 0;
    
}