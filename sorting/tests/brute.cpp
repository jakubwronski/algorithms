#include <bits/stdc++.h>
using namespace std;

vector<int> tab;


int main(){
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        tab.push_back(x);
    }

    sort(tab.begin(), tab.end());
    for(auto i: tab) cout << i << "\n";
}