//using linear time text searching Z algorithm to solve this problem:
//https://sio2.staszic.waw.pl/c/maly-preoi-2018/p/suf/
/*
 *for every sufix of word a, check how many times it appears in word b 
*/
#include<bits/stdc++.h>

using namespace std;

string a,b;
const int N = 1e6+2;

vector<long long>ret;
int Z[2*N+1];
long long sumy[N];


void makez(string str, int m){

    int n=str.length();
    int k,p=0,l=0;

    for (int i=1; i<n; i++){

        if (i > p){
            l=p=i;
            while (p < n && str[p-l] == str[p]) p++;
            Z[i]=p-l;
            p--;
        }

        else {
            k=i-l;
            if (p-i+1 > Z[k]) Z[i] = Z[k];

            else {
                l=i;
                while (p<n && str[p-l] == str[p]) p++;
                Z[i] = p-l;
                p--;
            }
        }
        if (i>m)sumy[Z[i]]++;
    }
}



int main(){
    ios_base::sync_with_stdio(0);

    cin >> b >> a;

    int n=a.size();
    int m=b.size();

    string ta = a, tb=b;
    for (int i=0; i<n; i++){
        ta[n-1-i] = a[i];
    }
    a = ta;

    for (int i=0; i<m; i++){
        tb[m-1-i] = b[i];
    }
    b = tb;

    string str = b+'#'+a;

    makez(str, m);

    long long temp=0;
    for (int i=m; i>0; i--){

        ret.push_back(sumy[i] + temp);
        temp+=sumy[i];
    }
    
    for (int i=m-1; i>=0; i--) cout << ret[i] << " ";

}