//using range sweeping technique to solve this problem:
//https://sio2.staszic.waw.pl/c/preoi-2019/p/pod/
/*
 *For given set of points with coordinates (x,y,z) return indexes of those, that 
 *are smallest -> don't have any smaller points (p1 < p2 <==> p.1x < p2.x && p1.y < p2.y && p1.z < p2.z)
*/

/*
 *simple explaination of code as I recognise it should be refactored...
 * 1.re-scale data (if data is of big range and we cannot hold array this big, we can "compress data" fe. {5,77,1<<31} -> {1,2,3})
 * 2.Build a range tree (we will treat x as an array, z as values and y as iterable values)
 * 3.Beginning with smallest ys, and with biggest xs in those ys, add z values to range tree
 * 4.If just added value is smallest on range (1,x-1) then the point is also the smallest (all smaller ys were already processed, and all smaller xs don't have any smaller value) 
 */

#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+3;
const int P = 1<<17;
const long long INF = 1e9+2;


struct node{

    int index;
    long long x,y,z;

    bool operator<(const node& n) const{

        if (x < n.x) return 1;
        else if (x > n.x) return 0;
        else if (x == n.x){

            if (y < n.y) return 1;
            else if (y > n.y) return 0;
            else if (y == n.y){

                if (z <= n.z) return 1;
                else if (z > n.z) return 0;
            }
        }
    }
};


long long tree[2*P+1];
int m;
vector<node>tab;
map <long long, int> some_map;
map <long long, int>scale; 
vector<node>ys[N];
set<long long>set_of_ys;


void put(long long what, int where){

    where+=P;
    tree[where] = min(tree[where], what);

    while (where > 1){

        where/=2;
        tree[where] = min(tree[where*2], tree[where*2+1]);
    }
}


long long query (int L, int R, int actl, int actr, int node){

    if (L <= actl && R >= actr) return tree[node];

    int mid = (actl+actr)/2;
    int retr = INF, retl = INF;

    if (L <= mid) retl = query(L,R,actl,mid,node*2);
    if (R > mid) retr = query (L,R,mid+1,actr,node*2+1);

    return min (retr, retl);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> m;

    long long a,b,c;
    for (int i=0; i<m; i++){

        cin >> a >> b >> c;

        node n; n.x = a; n.y = b; n.z = c; n.index = i+1;
        set_of_ys.insert(b);
        tab.push_back(n);
    }

    //scaling (we have big max size but only 1e5 queries)
    int it = 0;
    for (auto i:set_of_ys){
        scale[i] = it;
        it++;
    }
    it = 0;
    
    sort(tab.begin(), tab.end());

    for (int i=0; i<2*P+1; i++) tree[i] = INF;

    for (auto n:tab){

        if(some_map[n.x] == 0){
            
            it ++;
            some_map[n.x] = it;
        } 

        n.x = some_map[n.x];
        n.y = scale[n.y];
        ys[n.y].push_back(n);
    }



    vector<int>ret;

    for(int i=0; i<set_of_ys.size(); i++){

        sort(ys[i].begin(),ys[i].end());
        reverse(ys[i].begin(),ys[i].end());

        for (auto next:ys[i]){

            put(next.z, next.x);

            if (next.z <= query(0,next.x-1,0,P-1,1)){
                
                ret.push_back(next.index);
            }
        }
    }

    sort(ret.begin(),ret.end());

    cout << ret.size() << "\n";

    for (auto i:ret) cout << i << " ";
}