/*
Problem Statement #
Given an array of numbers and a number ‘k’, find the median of all the ‘k’ sized
sub-arrays (or windows) of the array.
Example 1:
Input: nums=[1, 2, -1, 3, 5], k = 2
Output: [1.5, 0.5, 1.0, 4.0]
*/


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> 
using namespace std;


template <typename T, typename Container = vector<T>, typename Compare = less<typename Container::value_type>>
class priority_queue1 : public priority_queue<T, Container, Compare> {
public:
    bool remove(const T& value) {
      
        auto it = find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        return false;
    }
};

class SlidingWindowMedian {
public:
    void rebalance(priority_queue1<int>& maxheap, priority_queue1<int, vector<int>, greater<int>>& minheap) {
        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (maxheap.size() < minheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

   
    vector<double> findSlidingWindowMedian(const vector<int>& nums, int k) {
        vector<double> result; 
        
        priority_queue1<int> maxheap;
        priority_queue1<int, vector<int>, greater<int>> minheap;

        for (int i = 0; i < nums.size(); i++) {
            if (maxheap.empty() || maxheap.top() >= nums[i]) {
                maxheap.push(nums[i]);
            } else {
                minheap.push(nums[i]);
            }
            rebalance(maxheap, minheap);

            if (i - k + 1 >= 0) {
                if (maxheap.size() == minheap.size()) {
                    result.push_back((minheap.top() + maxheap.top()) / 2.0);
                } else {
                    result.push_back(maxheap.top());
                }

                int elementToBeRemoved = nums[i - k + 1];
                if (elementToBeRemoved <= maxheap.top()) {
                    maxheap.remove(elementToBeRemoved);
                } else {
                    minheap.remove(elementToBeRemoved);
                }
                rebalance(maxheap, minheap);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    SlidingWindowMedian slidingWindowMedian;
    
     vector<double> result = slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 2);
    cout << "Sliding window medians (k=2) are: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    result = slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 3);
    cout << "Sliding window medians (k=3) are: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
