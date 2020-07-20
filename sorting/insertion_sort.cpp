//insertion sort; complexity: O(n^2)

#include <bits/stdc++.h>

using namespace std;


int n;
vector<int>tab;


void move(int a, int b){

    for (int i=b; i>=a; i--) tab[i+1] = tab[i];
}


void insertion(){

    for (int i=1; i<n; i++){
        
        int x = tab[i];
        
        if (tab[0] >= x){
            move(0,i-1);
            tab[0]=x;
        }

        else{
            
            for (int j=i-1; j>=0; j--){    
                if (tab[j] < x){
        
                    j++;
                    move(j, i-1);
                    tab[j]=x;
                    break;
                }
            }
        }
    }
}




int main(){

    cin >> n;

    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        tab.push_back(x);
    }

    insertion();

    for (auto i:tab) cout << i << "\n";

}