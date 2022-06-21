#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    vector<int> v = {0,90,0,120};
    int max = *max_element(v.begin(), v.end());
    auto it = find(v.begin(), v.end(), max);

    if (it != v.end()) 
    {
        int index = it - v.begin();
        cout << index << endl;
    }

}