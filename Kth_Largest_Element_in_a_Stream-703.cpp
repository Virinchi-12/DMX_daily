/*
703. Kth Largest Element in a Stream
Easy

742

390

Add to List

Share
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.

Example:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
Note:
You may assume that nums' length ≥ k-1 and k ≥ 1.
*/

/*Our main goal is to make the kth largest element at the top of the heap so extraction takes o(1)time excluding the heapify time.

We would build the heap by storing the largest k numbers in the heap with the smallest of them at the top yielding the kth 
largest number.
             
        |  4  |
        |  5  | <---------as 10 was greater than the top of the heap (i.e 3) we popped it and stored 10 in it.
        |__10_|   
 Remember Our Goal here is the store the k largest elements into the heap.

        |  4  |
        |  5  | <---------as 2 wasnt greater than heap.top() we just dont do anything.
        |__10_| 
        
 */
 class KthLargest {
public:
    priority_queue<int, vector<int>,greater<int>> minheap;
    int K;
    KthLargest(int k, vector<int>& nums) {
         K=k;
        for(auto x:nums)
            add(x);
    }
    
    int add(int val) {
        if(minheap.size()<K){
            minheap.push(val);
        }
        else
        {
            if(minheap.top()<val){
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
