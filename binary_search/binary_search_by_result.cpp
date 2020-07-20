//using binary search by result and game theory to solve this problem:
//https://sio2.staszic.waw.pl/c/wwi-2018-grupa-2/p/rob/

#include <bits/stdc++.h>

using namespace std;


const long long N = (long long) 1e12+3;
const int K = 1000004;
int n, k;
long long trees[K];
long long growing[K];
int days[K];

bool check(long long height){

    for (int i=0; i<=k; i++){
        days[i] = 0;
    }

    for (int i=1; i<=n; i++){

        if (trees[i] > height){

            if (k*growing[i] <= height) days[1]++; 
            else {

                int x = height/growing[i];
                if (k-x > 0) days[k-x]++;
            }
        } 

        else if (trees[i]+(k*growing[i]) > height){

            if (growing [i] != 0){
                
                int x = height/growing[i];
                
                if (k-x > 0) days[k-x]++;
                else days[1]++;
            }
        }
    }

    
    for (int i=1; i<=k; i++){
        
        days[i]+=days[i-1];

        if (days[i] > 0){
            days[i]--;
        }
    }

    if (days[k] == 0) return true;
    else return false;
}


long long binsearch(){

    long long start = 0, stop = N, mid;

    while(start < stop){

        mid = (start+stop)/2;

        if (check(mid)) stop = mid;
        else start = mid+1;
    }

    return stop;
}



int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    for (int i=1; i<=n; i++){

        int a,b;
        cin >> a >> b;

        trees[i] = b;
        growing[i] = a;
    }

    cout << binsearch();    
}