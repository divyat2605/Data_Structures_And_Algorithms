class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        // Approach: Greedy / Linear Scan
        // We iterate through the array and check every index.
        // Whenever nums[i] == target, compute distance from start.
        // Keep updating the minimum distance found.

        int ans = INT_MAX;  
        // Stores the minimum distance found so far.
        // Initialized with a very large value.

        int dist;  
        // Temporary variable to store distance
        // between current index and start.

        // Traverse the entire array
        for (int i = 0; i < nums.size(); i++) {

            // Check if current element equals target
            if (nums[i] == target) {

                // Compute absolute distance from start index
                dist = abs(i - start);

                // Update minimum distance
                ans = min(dist, ans);
            }
        }

        // Return the minimum distance found
        return ans;
    }
};
//
//Time Complexity

//O(n)

//We traverse the array once
//n = nums.size()
//Each operation inside loop is O(1)

//Space Complexity

//O(1)

//We only use:
//ans
//dist
//loop variable i
//No extra memory proportional to input size.