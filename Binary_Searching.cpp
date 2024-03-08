/*                                  Binary Search

            Best case: O(1)
            Worst case: O(log2(n))
            Average case: O(log2(n))
*/

#include<bits/stdc++.h>
using namespace std;

int Binary_Search(vector<int> numbers, int k)
{
    int n= numbers.size();
    int lo=0, hi= n-1;
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(numbers[mid] == k)
        {
            return mid;
        }
        else if(numbers[mid]<k)
        {
            lo=mid+1;

        }
        else
        {
            hi = mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> numbers={1,2,3,4,5,6,7,8,9,10,33,44,66,77,88,99};
    int k;
    cin>>k;
    int found = Binary_Search(numbers,k);
    if(found==-1)
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<"found at "<<found<<endl;
    }

}
