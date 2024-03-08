/*                                      Merge   Sort


                    Worst and Average case: O(n x log2(n))
*/

#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>&A, int low, int mid, int hi)
{
    int m = mid-low +1;
    int n = hi-mid;
    int L[m+1],R[n+1];
    for(int i=0;i<m;i++)
    {
        L[i] = A[low+i];
    }
    for(int j=0;j<m;j++)
    {
        R[j] = A[mid +1 +j];
    }
    L[m] = 99999999;
    R[n] = 99999999;
    int i=0;
    int j=0;
    for(int k=low;k<=hi;k++)
    {
        if(L[i]<R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void Merge_Sort(vector<int>&A,int low, int hi)
{
    if(low<hi)
    {
        int mid = (low+hi)/2;
        Merge_Sort(A,low,mid);
        Merge_Sort(A,mid+1,hi);
        Merge(A,low,mid,hi);
    }
}

int main()
{
    vector<int>A = {99,88,77,66,55,44,33,22,11};
    Merge_Sort(A,0,A.size()-1);
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" "<<endl;
    }
}
