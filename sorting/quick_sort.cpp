//quick sort; complexity: O(n*logn) average, O(n^2) worst case
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+2;
int n;
int tab[N];


void quick(int a, int b){

    if (a == b) return;

    int pivot = tab[(a+b)/2];
    int j = b;
    int i = a;

    while (i<=j){

        if (tab[i] >= pivot &&  tab[j] <= pivot) swap(tab[i],tab[j]);
        if (tab[i] <= pivot) i++;
        if (tab[j] >= pivot) j--;
    }

    quick(a,j);
    quick(i,b);
}


int main(){
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> tab[i];

    quick(1,n);

    for (int i=1; i<=n; i++) cout << tab[i] << "\n";
} 