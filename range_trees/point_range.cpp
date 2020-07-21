//using range tree point-range data structure to solve this problem:
//https://sio2.staszic.waw.pl/c/wwi-2018-grupa-2/p/sli/

/*
 *given initially empy array of integers handle queries of this type:
 * -add x to n cell of the array
 * -how many cells between a and b contain number divisible by k?
 */

#include <bits/stdc++.h>

using namespace std;

int n, q;
const int N = 1<<17;
int tree[6][N*2+1];


int read(int l, int r, int x, int L, int R, int div) {

    if(L <= l && r <= R) {  //czy jestem w całości w divytaniu
        return tree[div][x];
    }

    int ret = 0;
    int mid = (l+r)/2;
    
    if(L <= mid) {ret += read(l,mid,x*2,L,R, div); }
    if(mid < R) {ret += read(mid+1,r,x*2+1,L,R, div); }
    
    return ret;
}


void add(int what, int where){

    where += N;

    tree[0][where] += what;

    for (int i=1; i<6; i++){    //update for all dividers
        
        if (tree[0][where]%i != 0) tree[i][where] = 0;
    
        else tree[i][where] = 1;    
    }
    
    where/=2;
    
    while (where > 0){  //we update up

        for (int i=0; i<6; i++){    //for all dividers

            tree[i][where] = tree[i][where*2] + tree[i][2*where + 1];
        }
    
        where/=2;
    } 
}



int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> q;

    for (int i=0; i<2*N +1; i++){

        tree[0][i] = 0;
    }

    for (int i=0; i<N; i++){    //zeros are divisable by everything

        add(0, i);
    }

    for (int i=0; i<q; i++){

        string query;
        cin >> query;

        if (query == "DODAJ"){

            int p, c;
            cin >> p >>c;
            add(c, p);
        }

        else {

            int l, r, k;
            cin >> l >> r >> k;
            cout << read(0 ,N-1, 1, l, r, k) << "\n";
        }
    }
}