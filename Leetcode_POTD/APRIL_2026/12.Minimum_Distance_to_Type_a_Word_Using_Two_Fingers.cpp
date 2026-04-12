class Solution {
public:

    pair<int, int> getPos(int idx){
        return {idx/6, idx%6};
    }

    int getDist(int a, int b){
        if (a == 26) return 0;

        auto [x1,y1] = getPos(a);
        auto [x2,y2] = getPos(b);

        return abs(x1-x2) + abs(y1-y2);
    }

    int minimumDistance(string word) {

        int dp[27][27];

        for (int i =0;i<27;i++){
            for(int j =0;j<27;j++){
                dp[i][j] = 1e9;
            }
        }

        dp[26][26] = 0;

        //loop over characters
        for (char c : word){

            int curr = c - 'A';

            int newdp[27][27];

            for (int i =0;i<27;i++){
                for(int j =0;j<27;j++){
                    newdp[i][j] = 1e9;
                }
            }

            // try all previous states
            for(int f1 =0; f1<27; f1++){
                for(int f2 =0; f2<27; f2++){

                    if(dp[f1][f2] == 1e9) continue;

                    int cost = dp[f1][f2];

                    // move finger 1
                    newdp[curr][f2] =
                        min(newdp[curr][f2],
                            cost + getDist(f1, curr));

                    // move finger 2
                    newdp[f1][curr] =
                        min(newdp[f1][curr],
                            cost + getDist(f2, curr));
                }
            }

            memcpy(dp, newdp, sizeof(dp));
        }

        int ans = 1e9;

        for(int i =0;i<27;i++){
            for(int j =0;j<27;j++){
                ans = min(ans, dp[i][j]);
            }
        }

        return ans;
    }
};