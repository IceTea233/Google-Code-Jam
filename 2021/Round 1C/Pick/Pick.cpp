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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;


int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        int N, K;
        cin >> N >> K;
        vector<int> keep;
        for (int i=1; i<=N; i++) {
            int x;
            cin >> x;
            keep.PB(x);
        }
        sort(all(keep));
        vector<int> cand;
        for (int i=1; i<keep.size(); i++) {
            cand.PB((keep[i] - keep[i-1]));
        }
        sort(all(cand), greater<int>());
        int lead = keep.front()-1;
        int back = K - keep.back();

        int ans1 = cand.size() >= 2 ? cand[0] / 2 + cand[1] / 2 : 0;
        int ans2 = cand.size() >= 1 ? cand[0] / 2 + max(lead, back) : 0;
        int ans3 = lead + back;
        int ans4 = cand.size() >= 1 ? cand[0] - 1 : 0;
        de(1) printf("%lld %lld %lld %lld\n", ans1, ans2, ans3, ans4);
        int ans = max({ans1, ans2, ans3, ans4});
        double p = (double) ans / K;
        printf("Case #%lld: %.7f\n", t, p);
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
