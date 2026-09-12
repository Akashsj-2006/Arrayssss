#include<iostream>
#include<vector>
using namespace std;

void bruteforce_movezeros(vector<int> arr, int n)
{
    vector<int> temp;
    int k = 0;
    for(int i=0;i<n;i++)
        {
            if(arr[i] != 0)
            {
                temp.push_back(arr[i]);
                k++;
            }
            
        }

    for(int i=k;i<n;i++)
        {
            temp[i] = 0;
        }

    for(int i=0;i<n;i++)
        {
            cout<<temp[i]<<" ";
        }
}


void optimal_movezeros(vector<int> arr, int n)
{
  //find the first zero
    int j = -1;
    for(int i=0;i<n;i++)
        {
            if(arr[i] == 0)
            {
                j=i; 
                break;
            }
        }

    for(int i = j+1;i<n;i++)
        {
            if(arr[i] !=0)
            {
                swap(arr[i] , arr[j]);
                j++;
            }
        }
    for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    
}

int main()
{
    vector<int> arr = {1,2,0,0,5,6};
    int n = arr.size();

    //brute force: creating another temporaary array and storing it there.

    bruteforce_movezeros(arr, n);
    optimal_movezeros(arr, n);
}