//using Dijkstra's algorithm and concept of graph's dissection to solve this problem:
//https://sio2.staszic.waw.pl/c/wwi-2018-grupa-2/p/pod/
//doubling nodes of the graph at posutions [i+n] in G array
#include <bits/stdc++.h>

using namespace std;

const int N = 2000004;
const long long INF = 1e18;


int time_array[N];
long long dist[N];

int n, m, a, b;


vector<pair<long long, int>> G[N];
priority_queue<pair<long long,int>> process;


void dijkstra(int start){

    for (int i=0; i<=n*2+1; i++){
        dist[i] = INF;
    }

    dist[start] = 0;

    process.push(make_pair(0, start));

    while (!process.empty()){

        int node = process.top().second;
        long long dist_from_node = -process.top().first;
        process.pop();
        
        if (dist_from_node > dist[node]) continue;

        for (pair<long long,int>next:G[node]){

            int neighbour = next.second;
            long long dist_from_neighbour = next.first;

            
            if (dist[node]+ dist_from_neighbour < dist[neighbour]){            
                
                dist[neighbour] = dist[node]+dist_from_neighbour;
                process.push(make_pair(-dist[neighbour], neighbour));
            } 
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> a >> b;

    for (int i=1; i<=n; i++){

        cin >> time_array[i];
    }

    for (int i=0; i<m; i++){

        int d,e,f;
        cin >> d >> e >>f;

        G[d].push_back(make_pair(f,e+n));
        G[e].push_back(make_pair(f,d+n));

        G[d].push_back(make_pair(f+time_array[d],e));
        G[e].push_back(make_pair(f+time_array[e],d));

        G[d+n].push_back(make_pair(f+time_array[d],e+n));
        G[e+n].push_back(make_pair(f+time_array[e],d+n));
    }

    dijkstra(a);

    cout << dist[b+n];
}