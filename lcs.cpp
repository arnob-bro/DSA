// Dynamic Programming C++ implementation

#include <bits/stdc++.h>
using namespace std;


// Returns length of LCS for X[0..m-1],
// Y[0..n-1]
void lcs(string X, string Y, int m, int n)
{

    // Initializing a matrix of size
    // (m+1)*(n+1)
    int L[m + 1][n + 1];


    // Following steps build L[m+1][n+1]
    // in bottom up fashion. Note that
    // L[i][j] contains length of LCS of
    // X[0..i-1] and Y[0..j-1]
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }



    //LCS STRING OUTPUT
    int index = L[m][n];
    int i=m,j=n;
    char lcs_str[index];

    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            lcs_str[index]=Y[j-1];
            i--;
            j--;
            index--;
        }
        else if(L[i][j-1] > L[i-1][j]){
            j--;
        }
        else {
            i--;
        }

    }


    //debug
    /*for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout<<L[i][j]<<"    ";
        }
        cout<<endl;
    }*/

    cout << "Length of LCS is " << L[m][n]<<endl;
    cout << "LCS string is " << lcs_str<<endl;
}




// Driver code
int main()
{
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int m = S1.size();
    int n = S2.size();

    lcs(S1, S2, m, n);


    return 0;
}

