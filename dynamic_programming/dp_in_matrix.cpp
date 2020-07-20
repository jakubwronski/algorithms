//using dyanmic programming to solve this problem:
//https://sio2.staszic.waw.pl/c/wwi-2018-grupa-2/p/zep/

#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    int limit = n+m-2;
    long long tab[n+3][m+3];

    for (int i=0; i<n+1; i++){
        tab[i][0] = -1000000002;
    }

    for (int i=0; i<m+1; i++){
        tab[0][i] = -1000000002;
    }


    for (int i=1; i<n+1; i++){

        for (int j=1;j<m+1;j++){

            cin >> tab[i][j];
        }
    }

    for (int i=2; i<n+1; i++){

        tab[i][1] += tab[i-1][1];
    }

    for (int i=1; i<n+1; i++){

        for (int j=2; j<m+1; j++){
            
            tab[i][j] = max(tab[i-1][j], tab[i][j-1]) + tab[i][j];
        }
    }


    if (tab[n][m] < 0) tab[n][m] = 0;
    cout << tab[n][m];

}