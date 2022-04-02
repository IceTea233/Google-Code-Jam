#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define PP pop_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e3 + 7;

int dp[maxn][2] = {};
// 0 for 'C' and '1' for 'J'

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        memset(dp, 0, sizeof(dp));
        int X, Y;
        string S;
        cin >> X >> Y >> S;
        if (S[0] == 'C') {
            dp[0][0] = 0;
            dp[0][1] = INF;
        } else if (S[0] == 'J') {
            dp[0][0] = INF;
            dp[0][1] = 0;
        } else {
            dp[0][0] = 0;
            dp[0][1] = 0;
        }
        for (int i=1; i<S.size(); i++) {
            if (S[i] == 'C') {
                dp[i][0] = min( dp[i-1][0], dp[i-1][1] + Y);
                dp[i][1] = INF;
            } else if (S[i] == 'J') {
                dp[i][0] = INF;
                dp[i][1] = min( dp[i-1][1], dp[i-1][0] + X);
            } else {
                dp[i][0] = min( dp[i-1][0], dp[i-1][1] + Y);
                dp[i][1] = min( dp[i-1][1], dp[i-1][0] + X);
            }
        }
        int ans = min(dp[S.size()-1][0], dp[S.size()-1][1]);
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}

//
//          ___ ___  __________  __________
//         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
//        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
//       ////   \ \  \ \  \      \ \\\\\\\\\\\
//      ////__   \ \  \ \  \      \ \\\\_____/
//     ///////\   \ \  \ \  \______\ \\\\_______   ________
//    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
//   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
//                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
// ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
//   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
//                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
//                               \/__/    \/________/\/__/   \/__/
//
