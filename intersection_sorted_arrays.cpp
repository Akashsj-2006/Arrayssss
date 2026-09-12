#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void BruteForce_Intersection(vector<int> arr1, vector<int> arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> visited(n2, 0);
    vector<int>InterSectionArr;
    for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
                {
                    if(arr1[i] == arr2[j] && visited[j]==0)
                    {
                        InterSectionArr.push_back(arr1[i]);
                        visited[j] =1;
                        break;
                    }
                }
        }

    for(int i=0;i<InterSectionArr.size();i++)
        {
            cout<<InterSectionArr[i]<<" ";
        }

    cout<<endl;
}


void Optimal_Intersection(vector<int>arr1, vector<int> arr2)
{
    int n1= arr1.size();
    int n2 = arr2.size();
    int i=0;
    int j=0;
    vector<int> InterSectionArr;
    while(i<n1 && j<n2)
        {
            if(arr1[i]==arr2[j])
            {
                InterSectionArr.push_back(arr1[i]);
                i++;
                j++;
            }
                

            else if(arr1[i]<arr2[j])
                i++;
            else
                j++;
        }

    for(int i=0;i<InterSectionArr.size();i++)
        {
            cout<<InterSectionArr[i]<<" ";
        }

    cout<<endl;
}
int main()
{
    vector<int> arr1 = {1,1,2,3,4,4,5,67};
    vector<int> arr2 = {1,3,3,5,6,7,8,78};
    BruteForce_Intersection(arr1, arr2);//O(n1*n2)
    Optimal_Intersection(arr1, arr2);//array needs to be sorted
    return 0;
    
}