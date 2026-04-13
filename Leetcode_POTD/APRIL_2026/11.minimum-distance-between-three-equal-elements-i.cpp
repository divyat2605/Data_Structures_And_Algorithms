class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int ans = INT_MAX;
        for(int i =0;i<nums.size();i++){
            int x = nums[i];
            pos[x].push_back(i);
            if (pos[x].size()>3){
                pos[x].erase(pos[x].begin());
            }
            if (pos[x].size() == 3){
                int a = pos[x][0];
                int c = pos[x][2];
                ans = min(ans, c-a);
            }
        }
        if (ans == INT_MAX) return -1;
        return 2*ans;
    }
};