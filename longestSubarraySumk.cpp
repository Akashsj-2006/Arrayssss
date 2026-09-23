#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bruteForce_LongestSubArray(vector<int> arr, int k)
{
    int n = arr.size();
    int maxi = 0;
    int len = 0;
    for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
                {
                   sum+= arr[j];
                    if(sum==k)
                        len = max(len, j-i+1);
                }
            
        }

        cout<<"Brute Force Solution: "<<len<<endl;
    
}




void better_LongestSubArray(vector<int> arr, long long k)
{
   unordered_map <long long, int> umap;
    long long sum =0;
    int maxLen = 0;
    int n = arr.size();
    for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum==k)
            {
                maxLen = max(maxLen, i+1);
            }

            long long rem = sum-k;
            if(umap.find(rem) != umap.end())
            {
                maxLen = max(maxLen, i-umap[rem]);
            }

            if(umap.find(sum) == umap.end())
            {
                umap[sum] = i;
            }
        }
    cout<<"Better Solution: "<<maxLen<<endl;

}


void optimal_LongestSubArray(vector<int> arr, int k)
{
    int l = 0;
    int sum = 0;
    int len = 0;

    for(int r = 0; r < arr.size(); r++)
    {
        sum += arr[r];

        while(sum > k)
        {
            sum -= arr[l];
            l++;
        }

        if(sum == k)
        {
            len = max(len, r - l + 1);
        }
    }

    cout << "Optimal Solution: " << len << endl;
}
int main()
{
    vector<int> arr = {1,1,2,3,1,1};
    int k = 3;
    bruteForce_LongestSubArray(arr, k);
    better_LongestSubArray(arr, k);
    optimal_LongestSubArray(arr, k);
    return 0;
}