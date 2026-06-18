/*
Problem Statement #
Given a set with distinct elements, find all of its distinct subsets
*/

#include <iostream>
#include <vector>
using namespace std;

void helper(int index, vector<int>&num, vector<int> &cur,vector<vector<int>> &res){
    if(index == num.size()){
       res.push_back(cur);
       return;
    }
    
    cur.push_back(num[index]);
    helper(index+1, num, cur,res);
    
    cur.pop_back();
    helper(index+1,num,cur,res);
}

vector<vector<int>> findSubsets(vector<int> num ){
    vector<vector<int>> res;
    vector<int> cur;
    helper(0,num,cur,res);
    return res;
}

//iterative approach
/*

vector<vector<int>> findSubsets(vector<int> num ){
    vector<vector<int>> subset;
    subset.push_back({});
    
    for(auto curNum : num){
        int n = subset.size();
        
        for(int i=0;i<n;i++){
            vector<int> set = subset[i];
            
            set.push_back(curNum);
            
            subset.push_back(set);
        }
    }
    
    return subset;
}

    */
int main(int argc, char* argv[]) { 
  vector<vector<int>> result = findSubsets(vector{1, 3}); 
  cout << "Here is the list of subsets: " << endl; 
  for (auto vec : result) { 
    for (auto num : vec) { 
      cout << num << " "; 
    } 
    cout << endl; 
  } 
  result = findSubsets(vector{1, 5, 3}); 
  cout << "Here is the list of subsets: " << endl; 
  for (auto vec : result) { 
    for (auto num : vec) { 
      cout << num << " "; 
    } 
    cout << endl; 
  } 
}
