//medium


class Solution {
public:
    int kthLargest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store top k largest sums
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j]; // Compute subarray sum
                if (minHeap.size() < k) {
                    minHeap.push(sum);
                } else if (sum > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }

        return minHeap.top(); // K-th largest sum
    }
};