//heap sort implemented with pointers; complexity: O(n*logn)
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+2;
int input[N];
int n;
vector<int>sorted;


struct node{

    int val;    
    node* L;
    node* R;

    node(int x){    
        val = x;   
        L = NULL;
        R = NULL;
    }
};

node* root;


void put(node* nod, int x){

    if (x < nod->val){

        if (nod -> L == NULL){
            nod -> L = new node(x);
            return;
        }
        else put(nod ->L, x);
    }

    else{

        if (nod->R == NULL){
            nod -> R = new node(x);
            return;
        }
        else put(nod->R,x);
    }
}



void pull(node* nod){

    if (nod -> L != NULL) pull(nod->L);
    sorted.push_back(nod->val);
    if (nod ->R != NULL) pull(nod->R);
    return;
}


void create_tree(){
    root= new node(input[0]);
}

void heapsort(){
    
    create_tree();
    for (int i=1; i<n; i++) put(root,input[i]); // po kolei wstawiam rzeczy z tablicy do drzewa
    pull(root);
}


int main(){
    
    cin >> n;
    for (int i=0; i<n; i++) cin >> input[i];    
    heapsort();
    for (auto i : sorted) cout << i << "\n";
}