//bubble sort; complexity: O(n^2)
#include <bits/stdc++.h>

using namespace std;


vector<int> nums;
int n;

void bubble(){

    for (int i=1; i<n; i++){

        for (int j=i;j>=1; j--){
            int x = nums[j];
            int y = nums[j-1];
            if(x < y){

                nums[j]=y;
                nums[j-1]=x;
            }
            else break;
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

    bubble();

    cout <<"\n";
    for (int i:nums) cout << i << "\n";

}
