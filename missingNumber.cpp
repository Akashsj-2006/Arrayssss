#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void bruteForce_Missingnumber(vector<int> arr, int n)
{
    cout<<"\nThe bruteForce solution"<<endl;
    for(int i=1;i<=n;i++)
        {
            int flag=0;
            for(int j=0;j<n-1;j++)
                {
                    if(arr[j] == i)
                    {
                        flag=1;
                        break;
                    }
                }
            if(flag==0)
            {
                cout<<i<<" is missing."<<endl;
            }
        }
}

void better_MissingNumber(vector<int> arr, int n)
{
    unordered_map<int, int> umap;
    for(int i=0;i<n-1;i++)
        {
            umap[arr[i]] = i;
        }
    cout<<"\nThe better solution: "<<endl;
    for(int i=1;i<=n;i++)
        {
            if(umap.find(i) == umap.end())
            {
                cout<<i<<" is missing from the array."<<endl;
            }
        }
}

void optimal_MissingNumber(vector<int>arr, int n)
{
    int sum =0;
    for(int i=0;i<n;i++)
        {
            sum+= arr[i];
        }
    int origSum = ((n+1)*(n+2))/2;
    int missingVal = origSum - sum;
    cout<<"\nThe optimal solution"<<endl;
    cout<<"\nThe missing value: "<<missingVal;
}
int main()
{
    vector<int>arr = {1,2,3,5,6};
    int n = arr.size();
    bruteForce_Missingnumber(arr, n) ;
    better_MissingNumber(arr, n);
    optimal_MissingNumber(arr, n);
    return 0;
}