//using binary search on graph to solve this problem:
//https://sio2.staszic.waw.pl/c/wwi-2018-grupa-2/s/8269/source/
#include <bits/stdc++.h>

using namespace std;


const int N = 100003;
int n,m;
int height[N];
bool visited[N];
int maxn;
vector<int>G[N];


void dfs(int start, int m){

    visited[start] = 1;


    for (int next:G[start]){

        if (!visited[next] && height[next] <= m){
            dfs(next,m);
        }
    }
}


bool check (int x){
    
    for (int i=0; i<N; i++){
        visited[i] = 0;
    }

    dfs(1, x);
    if (visited[n]) return true;
    else return false;
}



int binsearch(){

    int p=0, k = maxn;
    int s;

    while(p < k){

        s = (p+k)/2;

        if (check(s)) k = s;
        else p = s+1; 
    }

    return k;
}


int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i=1; i<=n; i++){

        cin >> height[i];
        maxn = max(maxn, height[i]);
    }

    for (int i=0; i<m; i++){

        int a, b;
        cin >> a >>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cout << binsearch();
}