//selection sort; complexity: O(n^2)
#include<bits/stdc++.h>

using namespace std;

vector<int>nums;
int n;

void selection(){

    for (int i=0; i<n-1; i++){

        int mini=nums[i+1];
        int index = i+1;

        for (int j=i+1; j<n;j++){
            if(nums[j]<mini){
                mini=nums[j];
                index = j;
            }
        }

        int x = nums[i];
        if (mini < x){
            nums[i]=mini;
            nums[index] = x;
        }
    }
}


int main(){

    cin >> n;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }   

    selection();

    cout <<"\n";
    for (int i:nums) cout << i << "\n";
}
