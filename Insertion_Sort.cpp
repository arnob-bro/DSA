/*                                      Insertion Sort

                    Best case: O(n)
                    Worst case: O(n2)
                    Average case: O(n2)
*/

#include<bits/stdc++.h>
using namespace std;
void Insertion_Sort(vector<int>&numbers)
{
    int s=numbers.size();

    for(int i = 1;i<s;i++)
    {
        int j = i-1,k=numbers[i];
        while(j>=0 && numbers[j]>k)
        {
            numbers[j+1]=numbers[j];
            j--;
        }
        numbers[j+1] = k;
    }
}

int main()
{
    vector<int> a={2,4,3,1,5,6,7,5,4,3,5,7,8,9,6,4,3};
    Insertion_Sort(a);
    for(int i = 0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}
