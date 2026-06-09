/*
Next Interval (hard) #
Given an array of intervals, find the next interval of each interval. In a list of
intervals, for an interval ‘i’ its next interval ‘j’ will have the smallest ‘start’ greater
than or equal to the ‘end’ of ‘i’.
Write a function to return an array containing indices of the next interval of each
input interval. If there is no next interval of a given interval, return -1. It is given
that none of the intervals have the same start point
*/

#include <iostream>
#include<queue>
#include <utility> 
#include<vector>
using namespace std;
class Interval{
    
    public:
    int start=0;
    int end=0;
    
    Interval(int start,int end){
        this->start = start;
        this->end = end;
    }
    
};

struct startComp{
    bool operator()(const pair<Interval,int> &x,const pair<Interval,int> &y){
        return x.first.start < y.first.start;
    }
};

struct endComp{
    bool operator ()(const pair<Interval,int> &x,const pair<Interval,int> &y){
        return x.first.end <y.first.end;
    }
};

vector<int> func(vector<Interval> intervals){
    int n = intervals.size();
    vector<int> res(n);
    
    priority_queue<pair<Interval,int>, vector<pair<Interval,int>>, startComp> maxStart;
    priority_queue<pair<Interval,int>, vector<pair<Interval,int>>, endComp> maxEnd;
    
    for(int i = 0;i< intervals.size(); i++){
        maxStart.push(make_pair(intervals[i],i));
        maxEnd.push(make_pair(intervals[i],i));
    }
    
    for(int i=0;i<n;i++){
        
        auto topEnd = maxEnd.top();
        maxEnd.pop();
        
        res[topEnd.second] = -1;
        if(maxStart.top().first.start >= topEnd.first.end){
            auto topStart= maxStart.top();
            maxStart.pop();
            
            while(!maxStart.empty() && maxStart.top().first.start >= topEnd.first.end){
                topStart= maxStart.top();
                 maxStart.pop();
            }
            
          res[topEnd.second] = topStart.second;
          maxStart.push(topStart);
        }
        
    }
    
    return res;
    
}

int main() {
    // Write C++. code here
 vector<Interval> intervals = { {3, 4},{2, 3}, {5, 6}};
 
 vector<int> res = func(intervals);
 for(int k : res){
     cout<<k<<" ";
 }

    return 0;
}
