/*                                      Selection Sort

                    Best case: O(n2)
                    Worst case: O(n2)
                    Average case: O(n2)
*/

#include<bits/stdc++.h>
using namespace std;
void Selection_Sort(vector<int>&numbers)
{
    int n = numbers.size();

    for(int i=0;i<n-1;i++)
    {
       int min = numbers[i];
       int minpos=i;
       for(int j=i+1;j<n;j++)
       {
           if(numbers[j]<numbers[minpos])
           {
               minpos = j;
           }
       }
       int temp = numbers[i];
       numbers[i] = numbers[minpos];
       numbers[minpos] = temp;
    }
}

int main()
{
    vector<int> numbers={2,3,4,1,3,6,5,4,7,9,88,77,66,55};
    Selection_Sort(numbers);
    for(int i= 0;i<numbers.size();i++)
    {
        cout<<numbers[i]<<endl;
    }
}
