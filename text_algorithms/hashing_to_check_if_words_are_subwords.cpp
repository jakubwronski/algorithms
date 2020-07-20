//using double hashing technique to check if words are subwords of another word in this problem:
//https://sio2.staszic.waw.pl/c/wwi-2018-grupa-2/p/prz2/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int P = 997;
const int R = 313;
const long long MOD = 179426549;
const ll MOD2 = (ll)1e9 +9;
const int N = 100003;
ll text[N], text2[N];
ll p[N];    //array for powers of primes P and R
ll r[N];


inline ll hash1(int a, int b){ 

    ll temp = (text[b] - (text[a-1]*p[b-a+1])%MOD)%MOD;

    if (temp < 0){
        temp+=MOD;
    }
    return temp;
}

inline ll hash2(int a, int b){

    ll temp = (text2[b] - (text2[a-1]*r[b-a+1])%MOD2)%MOD2;

    if (temp < 0){
        temp+=MOD2;
    }
    return temp;
}


int main(){
    ios_base::sync_with_stdio(0);

    string word;
    cin >> word;
    p[0]=1;
    r[0] = 1;
    word = '#'+word;
    text[0] = '#';
    text2[0] = '#';

    for (int i=1; i<word.size(); i++){  //hashing the big, main word

        p[i] = (p[i-1]*P)%MOD;
        text[i] = ((text[i-1]*P)%MOD + word[i])%MOD;
    }

    for (int i=1; i<word.size(); i++){     //hashing the big, main word with second hash function

        r[i] = (r[i-1]*R)%MOD2;
        text2[i] = ((text2[i-1]*R)%MOD2 + word[i])%MOD2;
    }


    int people;
    cin >> people;


    for (int j=0; j<people; j++){

        int how_many;
        cin >> how_many;
        string first_word;
        cin >> first_word;
        set<ll>result1;
        set<ll>result2;

        ll h1 = first_word[0];
        ll h2 = first_word[0];

        for (int i=first_word.size(); i<word.size(); i++){   //hashing big word using smaller's length
            
            result1.insert(hash1((i - first_word.size())+1, i));
        }

        for (int i=first_word.size(); i<word.size(); i++){   //same with second hashing function
            
            result2.insert(hash2((i - first_word.size())+1, i));
        }



        for (int i=1; i < first_word.size(); i++){    //hashing first word

            h1 = ((h1*P)%MOD + first_word[i])%MOD;
        }

        for (int i=1; i < first_word.size(); i++){    //same with second hashing function

            h2 = ((h2*R)%MOD2 + first_word[i])%MOD2;
        }


        auto it = result1.find(h1);
        auto it2 = result2.find(h2);

        if (it != result1.end() && it2 != result2.end()) cout << "OK\n";   //if found in both hashes
        else cout << "NIE\n";


        for (int k=1; k<how_many; k++){  //same for rest of the words

            string zap;
            cin >> zap;
            h1 = zap[0];    
            h2 = zap[0];    

            for (int i=1; i < zap.size(); i++){

                h1 = ((h1*P)%MOD + zap[i])%MOD;
            }

            for (int i=1; i < zap.size(); i++){

                h2 = ((h2*R)%MOD2 + zap[i])%MOD2;
            }

            auto it = result1.find(h1); 
            auto it2 = result2.find(h2);

            if (it != result1.end() && it2 != result2.end()) cout << "OK\n";
            else cout << "NIE\n";
        }
    }
}