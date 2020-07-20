//using hashing technique to check if word is a "double subword" in this problem:
//https://sio2.staszic.waw.pl/c/wwi-2018-grupa-2/p/slo1/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int P = 997;
const ll MOD = (ll) 1e9+9;
const int N = 1000003;
ll word[N];
ll power[N];

ll hash_func(int a, int b){

    ll h =(word[b] - (word[a-1]*power[b-a+1])%MOD)%MOD;

    if (h < 0){
        h+= MOD;
    }

    return h;
}



int main(){
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    word[0] = '#';
    power[0] = 1;

    for (int i=1; i<=n; i++){

        char a;
        cin >> a;
        power[i] = (power[i-1] * P) % MOD;
        word[i] =  ((word[i-1]*P)%MOD + a)%MOD;
    }

    int m;
    cin >> m;

    for (int i=0; i<m; i++){

        int a, b;
        cin >> a >> b;
        int c = (a+b)/2;

        if (hash_func(a,c) == hash_func(c+1, b)){
            cout << "TAK" << "\n";
        }
        else cout << "NIE" << "\n";        
    }
}