/*
295. Find Median from Data Stream
Hard

2605

49

Add to List

Share
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
*/


//Simple solution using multiset

class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> s;
    int size=0;
     multiset<int>::iterator mid;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(s.empty()){
            mid=s.insert(num);
            size++;
            return;            
        }
        s.insert(num);
        
        if((size%2)==1 &&num<*mid)
            mid--;
        else if((size%2)==0 &&num>=*mid)
            mid++;
        size++;
            
    }
    
    double findMedian() {
        if(size%2==1)
            return (double)*mid;
        else
            return (0.5*(*mid+*next(mid)));
    }
};


//Using max heap and min heap. 
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int> >minheap;
    bool even=true;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(even){
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else{
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        even=!even;
    }
    
    double findMedian() {
        if(even){
            return (.5*(maxheap.top()+minheap.top()));
        }
        else{
            return (double)maxheap.top();
        }
    }
};

