/*
                                        QUICK SORT

                            Best and average case: O(nlog2(n))
                            worst case: O(n2)

*/

#include<bits/stdc++.h>
using namespace std;

int Partition(vector<int>&numbers,int low, int hi)
{
    int pivot = numbers[low];
    int i=low;
    int j=hi;
    while(i<j)
    {
        while(numbers[i]<=pivot)
        {
            i++;
        }
        while(numbers[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(numbers[i],numbers[j]);

        }
    }
    swap(numbers[low],numbers[j]);
    return j;
}

void Quick_Sort(vector<int>&numbers,int low, int hi)
{
    if(low<hi)
    {
        int p = Partition(numbers,low ,hi);
        Quick_Sort(numbers,low,p-1);
        Quick_Sort(numbers,p+1,hi);

    }

}

int main()
{
    vector<int> numbers = {2,3,1,99,88,77,66,55,44,33,32,22,11};
    int s = numbers.size();
    Quick_Sort(numbers,0,s-1);
    for(int i=0;i<numbers.size();i++)
    {
        cout<<numbers[i]<<" ";
    }


}
