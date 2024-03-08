/*                                   Linear Searching

                    Best Case: O(1)
                    Worst Case: O(n)
                    Average Case: O(n)

*/

#include<bits/stdc++.h>
using namespace std;

int Linear_Search(vector<int> ar, int k)
{
    int n=ar.size();

    for(int i=0;i<n;i++)
    {
        cout<<"in loop it"<<i<<"/"<<n<<endl;
        if(ar[i]== k)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> ar={1,2,3,4,32,54,32,5,444,66,7,8,77,888,666,566,77,999};
    int k;
    cin>>k;
    int found= Linear_Search(ar,k);
    if(found==-1)
    cout<< "not found"<<endl;
    else
    cout<< "found at "<<found+1<<endl;
}



