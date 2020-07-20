//using strongly connected components to slove this problem:
//https://sio2.staszic.waw.pl/c/wwi-2018-grupa-2/p/nie/

#include <bits/stdc++.h>

using namespace std;

const int N = 500002;
int n, m;
vector<int>G[N];
vector<int>F[N];    //transposed graph
stack<int> post;    //post order
int components[N];
bool visited[N];


void dfs(int start, vector<int>G[], int count){

    visited[start] = true;
    components[start] = count;

    for (int next:G[start]){

        if (!visited[next]) dfs(next, G, count);
    }

    post.push(start);
}


int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){

        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        F[b].push_back(a);
    }
 
    for (int i=1; i<=n; i++){
        
        if (!visited[i]) dfs(i,G,0);
    }

    for (int i=0; i<N; i++) visited[i] = 0;

    int count = 1;

    while (!post.empty()){

        while (!post.empty() && visited[post.top()]){
            post.pop();
        }

        if (!post.empty()) dfs(post.top(), F, count);
        count++;
    }
    
    int quer;
    cin >> quer;

    for (int i=0; i<quer; i++){

        int a, b;
        cin >> a >> b;

        if (components[a] == components[b]) {cout << "Tak\n";}
        else cout << "Nie\n";
    } 
}