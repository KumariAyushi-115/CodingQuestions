/*
Problem Statement #
Design a class to calculate the median of a number stream. The class should have
the following two methods:
1. insertNum(int num) : stores the number in the class
2. findMedian() : returns the median of all numbers inserted in the class
If the count of numbers inserted in the class is even, the median will be the
average of the middle two numbers.
*/

#include <iostream>
using namespace std;
#include<queue>

class MedianOfAStream {
 public:
 
 priority_queue<int> maxheap;
 priority_queue<int,vector<int>, greater<int>> minheap;
 
 void insertNum(int num) {
    if(maxheap.empty() || maxheap.top()>= num){
        maxheap.push(num);
    }
    else{
        minheap.push(num);
    }
    
    if(maxheap.size() > minheap.size()+1){
        minheap.push(maxheap.top());
        maxheap.pop();
    }
  else if (maxheap.size() < minheap.size()){
        maxheap.push(minheap.top());
        minheap.pop();
    }
 
 }
 double findMedian() {
 if(maxheap.size() == minheap.size()){
     return (maxheap.top()+minheap.top())/2.0;
 }
 return maxheap.top();

 }
};
int main(int argc, char *argv[]) {
 MedianOfAStream medianOfAStream;
 medianOfAStream.insertNum(3);
 medianOfAStream.insertNum(1);
 cout << "The median is: " << medianOfAStream.findMedian() << endl;
 medianOfAStream.insertNum(5);
 cout << "The median is: " << medianOfAStream.findMedian() << endl;
 medianOfAStream.insertNum(4);
 cout << "The median is: " << medianOfAStream.findMedian() << endl;
}
