//using Dijkstra's algorithm and concept of graph's dissection to solve this problem:
//https://sio2.staszic.waw.pl/c/wwi-2018-grupa-2/p/prz1/
//doubling nodes of the graph at posutions [i+n] in G array

#include <bits/stdc++.h>

using namespace std;

const long long INF = 100000000000004;
const long long N = 10005;

int n, m;
long long dist[N];
long long price[N];

vector<pair<long long, int>> G[N];

priority_queue<pair<long long, int>> process;


void dijkstra(int start){

    for (int i=0; i<N; i++){
        dist[i] = INF;
    }

    dist[start] = 0;

    process.push(make_pair(0,start));

    while (!process.empty()){

        int node = process.top().second;
        long long dist_from_node = -process.top().first;
        

        process.pop();

        if (dist_from_node > dist[node]) continue;


        for (pair<long long, int> next:G[node]){
        
            int neighbour = next.second;
            long long neighbour_dist = next.first;

            if (dist[neighbour] > dist[node]+neighbour_dist){

                dist[neighbour] = dist[node]+neighbour_dist;
                process.push(make_pair(-dist[neighbour], neighbour));
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i=1; i<=n; i++){ 
        
        cin >> price[i];
        price[i]/=2;
    }

    cin >> m;

    for (int i=0; i<m; i++){
        
        int a, b;
        long long c;
        cin >> a >> b >> c;

        G[a].push_back(make_pair(c,b));
        G[a+n].push_back(make_pair(c,b+n));
        G[a].push_back(make_pair(c+price[a],b+n));
    }

    G[1].push_back(make_pair(price[1], 1+n));

    dijkstra(1);

    if (dist[1+n] == INF) {cout << price[1];}

    else {cout << dist[1+n];}

    return 0;
}