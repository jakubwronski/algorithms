//using binary search to solve this task:
//https://sio2.staszic.waw.pl/c/algorytmika-od-podstaw-20182019/p/kra/1063/
#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> pipe, rings;


int bs(int x, int k){

    int p=0;
    int mid=(p+k)/2;

    while(p<k){

        if (pipe[mid]>=x) p=mid+1;
        else k=mid;
        mid=(p+k)/2;
    }

    if (mid == 0) return mid;
    if (pipe[mid] < x)return mid-1;
    if (pipe[mid] >= x) return mid;
}



int main(){
    ios_base::sync_with_stdio(0);


    cin >> n >> m;

    pipe.push_back(1e9+2);

    int a;
    for (int i=1; i<=n; i++){

        cin >> a;
        if (a > pipe[i-1]) pipe.push_back(pipe[i-1]);
        else pipe.push_back(a);
    }
    
    for (int i=0; i<m; i++){
        
        cin >> a;
        rings.push_back(a);
    }


    int last = n+1;
    for (int ring:rings){

        last=bs(ring,last-1); 
    }

    cout << last;
}