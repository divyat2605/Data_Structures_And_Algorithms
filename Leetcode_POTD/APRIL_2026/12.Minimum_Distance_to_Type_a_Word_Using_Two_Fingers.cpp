class Solution {
public:

    // Convert a linear index (0–25) into a 2D grid position (row, col)
    // We assume keyboard layout is 6 columns wide
    pair<int, int> getPos(int idx){
        return {idx/6, idx%6};  // row = idx/6, col = idx%6
    }

    // Calculate Manhattan distance between two keys (a and b)
    int getDist(int a, int b){

        // If finger is not placed yet (26 = "empty finger state"), cost is 0
        if (a == 26) return 0;

        // Convert both indices into (row, col)
        auto [x1,y1] = getPos(a);
        auto [x2,y2] = getPos(b);

        // Manhattan distance = vertical + horizontal moves
        return abs(x1-x2) + abs(y1-y2);
    }

    int minimumDistance(string word) {

        // dp[i][j] = minimum cost when:
        // finger1 is on letter i, finger2 is on letter j
        int dp[27][27];

        // Initialize DP table with a very large value (infinity)
        for (int i =0;i<27;i++){
            for(int j =0;j<27;j++){
                dp[i][j] = 1e9;
            }
        }

        // Starting state: both fingers are not placed yet (26 = "free state")
        dp[26][26] = 0;

        // Process each character in the input word one by one
        for (char c : word){

            // Convert character to index (A -> 0, B -> 1, ..., Z -> 25)
            int curr = c - 'A';

            // Temporary DP for next state
            int newdp[27][27];

            // Initialize new DP table with infinity
            for (int i =0;i<27;i++){
                for(int j =0;j<27;j++){
                    newdp[i][j] = 1e9;
                }
            }

            // Try all previous finger positions
            for(int f1 =0; f1<27; f1++){
                for(int f2 =0; f2<27; f2++){

                    // Skip unreachable states
                    if(dp[f1][f2] == 1e9) continue;

                    // Current cost of this state
                    int cost = dp[f1][f2];

                    // OPTION 1: Move finger 1 to current character
                    // Finger 2 stays where it is
                    newdp[curr][f2] =
                        min(newdp[curr][f2],
                            cost + getDist(f1, curr));

                    // OPTION 2: Move finger 2 to current character
                    // Finger 1 stays where it is
                    newdp[f1][curr] =
                        min(newdp[f1][curr],
                            cost + getDist(f2, curr));
                }
            }

            // Copy new DP into old DP for next iteration
            memcpy(dp, newdp, sizeof(dp));
        }

        // After processing all characters, find minimum cost over all states
        int ans = 1e9;

        for(int i =0;i<27;i++){
            for(int j =0;j<27;j++){
                ans = min(ans, dp[i][j]);
            }
        }

        // Return final minimum cost
        return ans;
    }
};