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
