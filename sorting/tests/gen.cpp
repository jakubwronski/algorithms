#include <bits/stdc++.h>
using namespace std;

int randomize(int a, int b, int seed){

    mt19937 gen(seed);
    uniform_int_distribution<int> dis(a,b);
    return dis(gen);
}

int v = 1e3;
int v2 = 1e4;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(0);
    
    int seed = atoi(argv[1]);

    int n = v;
    cout << n << "\n";

    for(int i = 0 ; i < n; i++){

        cout << randomize(-v2,v2,seed+i) << " ";
    }
}