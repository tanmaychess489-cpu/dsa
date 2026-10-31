#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestGroup(vector<int>& stress, int K) { 
    int n = stress.size(); 
    int best = 0; 
    for (int i = 0; i < n; i++) { 
        int mx = stress[i]; 
        int mn = stress[i]; 
        for (int j = i; j < n; j++) { 
            mx = max(mx, stress[j]); 
            mn = min(mn, stress[j]); 
            if (mx - mn <= K) 
                best = max(best, j - i + 1); 
            else 
                break; 
        } 
    } 
    return best; 
} 

int main() { 
    vector<int> s1 = {8, 2, 4, 7}; 
    cout << longestGroup(s1, 4) << endl; 
    
    vector<int> s2 = {10, 1, 2, 4, 7, 2}; 
    cout << longestGroup(s2, 5) << endl; 
    
    return 0;
}
