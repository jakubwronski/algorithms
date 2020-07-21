//using latest common ancestor algorithm to calculate distance between nodes in a tree
//https://sio2.staszic.waw.pl/c/wwi-2018-grupa-2/p/slo/
/*
 *given weighted undirected graph, handle queries of this type:
 * -what is a distance between node a and b?
*/


#include <bits/stdc++.h>

using namespace std;

const int N = 500003;
const int P = 20;
int n;
int jumps[P][N];
long long dist[N], level[N];
vector<pair<int,long long>> G[N];
queue<int> process;

void bfs(int start){

    for (int i=0; i<N; i++){
        dist[i] = -1;
    }

    jumps[0][start] = start;
    dist[start]=0;
    level[start]=0;
    process.push(start);

    while (!process.empty()){

        int node = process.front();
        process.pop();

        for (pair<int,int>next:G[node]){

            int neighbour = next.first;
            int neighbour_dist = next.second;

            if (dist[neighbour] == -1){

                jumps[0][neighbour] = node;
                level[neighbour] = level[node]+1;
                dist[neighbour] = dist[node]+neighbour_dist;
                process.push(neighbour);
            }
        }
    }
}


void make_jumps(){

    for (int p=1; p<P; p++){

        for (int i=1; i<=n; i++){
            jumps[p][i] = jumps[p-1][jumps[p-1][i]];
        }
    }
}


long long lca(int a, int b){

    long long dist_a = dist[a];
    long long dist_b = dist[b];

    if (level[b] > level[a]){
        swap(a,b);
        swap(dist_a, dist_b);
    }


    for (int p=P-1; p>=0; p--){

        if (level[jumps[p][a]] >= level[b]){
            a = jumps[p][a];
        }
    }

    if (a == b){
        return dist_a - dist[a];
    }

    for (int p=P-1; p>=0; p--){

        if (jumps[p][a] != jumps[p][b]){
            a = jumps[p][a];
            b = jumps[p][b];
        }
    }

    a = jumps[0][a];

    return (dist_a - dist[a]) + (dist_b - dist[a]);
}



int main(){
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i=0; i<n-1; i++){

        int a, b;
        long long c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }

    bfs(1);
    make_jumps();
    
    int a,b;

    while (true){

        cin >> a >> b;
        if (a == -1) break;
        cout << lca(a,b) << "\n"; 
    }
}