//using find and union algorithm to solve this problem:
//https://sio2.staszic.waw.pl/c/wwi-2018-grupa-2/p/cho/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define x first
#define y second

map<pair<ll,ll>, pair<ll,ll>> leader;
map<pair<ll, ll>, int> the_map;


pair<ll, ll> Find(pair<ll, ll> a){

    if (leader[a] != a){
        leader[a] = Find(leader[a]);
    }
    return leader[a];
}

void Union(pair<ll, ll> a){

    pair<ll, ll> current_leader = Find(a);
    pair<ll, ll> check = a; check.x-=1;

    if (the_map.find(check) != the_map.end()){
        pair<ll, ll> e = Find(check);
        leader[e] = current_leader;
    }
    check.x+=2;
    if (the_map.find(check) != the_map.end()){
        pair<ll, ll> e = Find(check);
        leader[e] = current_leader;
    }
    check.x-=1; check.y+=1;
    if (the_map.find(check) != the_map.end()){
        pair<ll, ll> e = Find(check);
        leader[e] = current_leader;
    }
    check.y-=2;
    if (the_map.find(check) != the_map.end()){
        pair<ll, ll> e = Find(check);
        leader[e] = current_leader;
    }
}



int main(){
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    for (int i=0; i<q; i++){

        char a;
        cin >> a;

        if (a == 'B'){

            long long a,b;
            cin >> a >> b;
            pair<ll, ll> p;    
            p.x = a; p.y = b;
            
            if (!the_map[p]){
                the_map[p] = 1;
                leader[p] = p;
            
                Union(p);
            }
        }

        else if (a == 'M'){
            
            long long a, b, q, z;
            cin >> a >> b >> q >> z;

            pair<ll, ll> p1, p2;
            p1.x = a; p1.y = b;
            p2.x = q; p2.y = z;

            pair<ll, ll> o1 = Find(p1);
            pair<ll, ll> o2 = Find(p2);
            
            if(o1.x==o2.x && o1.y == o2.y){
                cout << "Tak\n"; 
            }

            else cout << "Niestety\n";
        }
    }
}