/*
Problem Statement #
Given a set of investment projects with their respective profits, we need to find the
most profitable projects. We are given an initial capital and are allowed to invest
only in a fixed number of projects. Our goal is to choose projects that give us the
maximum profit. Write a function that returns the maximum total capital after
selecting the most profitable projects.
We can start an investment project only when we have the required capital. Once
a project is selected, we can assume that its profit has become our capital.
Example 1:
Input: Project Capitals=[0,1,2], Project Profits=[1,2,3], Initial Capital=1, Number of
Projects=2
Output: 6
Explanation
*/

#include <iostream>
#include<queue>
#include <utility> 
#include<vector>
using namespace std;

struct compCapital{
    bool operator()(const pair<int,int> &x, const pair<int,int>&y){
        return x.first > y.first;
    }
    
};

struct compProfit{
    bool operator()(const pair<int,int> &x, const pair<int,int>&y){
        return x.first < y.first;
    }
    
};

 int maxTotalCapital(vector<int> capital,vector<int> profit,const int ic,const int np ){
     
     priority_queue<pair<int,int>, vector<pair<int,int>>, compCapital> minCapital;
     priority_queue<pair<int,int>, vector<pair<int,int>>, compProfit> maxProfit;
     
     for(int i=0;i< profit.size();i++){
         minCapital.push(make_pair(capital[i],i));
     }
     
     int avail= ic;
     
     
         for(int i = 0;i< np;i++){
             while(!minCapital.empty() && minCapital.top().first <= avail){
            
             maxProfit.push(make_pair(profit[minCapital.top().second],minCapital.top().second));
             minCapital.pop();
         }
         
         if(maxProfit.empty()){
             break;
         }
         avail += maxProfit.top().first;
         maxProfit.pop();
         
         }
     
     return avail;
 }



int main() {
    // Write C++. code here

vector<int> c = {0, 1, 2,3};
vector<int> p ={1, 2, 3,5};
cout<<maxTotalCapital(c,p ,0, 3); 



    return 0;
}
