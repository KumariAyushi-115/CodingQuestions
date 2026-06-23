/*

Problem Statement #
Given a set of numbers that might contain duplicates, find all of its distinct subsets.
Example 1:
Input: [1, 3, 3]
Output: [], [1], [3], [1,3], [3,3], [1,3,3]

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> findSubsets(vector<int> num) {
    vector<vector<int>> subset;
    sort(num.begin(), num.end());
    subset.push_back({});
    
    int prev_size = 0; // Initialize to 0
    
    for (int i = 0; i < num.size(); i++) {
        int n = subset.size();
        int start_j = 0; 
        
        if (i > 0 && num[i] == num[i - 1]) {
            start_j = prev_size;
        }
        
        prev_size = n;
        
        for (int j = start_j; j < n; j++) {
            vector<int> set = subset[j];
            set.push_back(num[i]);
            subset.push_back(set);
        }
        
    }
    
    return subset;
}


int main(int argc, char* argv[]) { 
  vector<vector<int>> result = findSubsets(vector{1, 3,3}); 
  cout << "Here is the list of subsets: " << endl; 
  for (auto vec : result) { 
    for (auto num : vec) { 
      cout << num << " "; 
    } 
    cout << endl; 
  } 
  result = findSubsets(vector{1, 5, 3,3}); 
  cout << "Here is the list of subsets: " << endl; 
  for (auto vec : result) { 
    for (auto num : vec) { 
      cout << num << " "; 
    } 
    cout << endl; 
  } 
}
