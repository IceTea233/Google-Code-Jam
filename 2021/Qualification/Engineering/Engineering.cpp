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
const int maxn = 1e2 + 7;

int arr[maxn] = {};

int reverse(int l, int r) {
    vector<int> keep;
    for (int i=l; i<=r; i++) {
        keep.PB(arr[i]);
    }
    for (int i=l; i<=r; i++) {
        arr[i] = keep.back();
        keep.PP();
    }
    // printf("(%lld, %lld)\n", l, r);
    return r - l + 1;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        int N, C;
        cin >> N >> C;
        C -= N-1;
        for (int i=1; i<=N; i++) {
            arr[i] = i;
        }
        vector<int> keep;
        for (int i=1; i<=N; i++) {
            if (C >= N-i) {
                C -= (N-i);
                keep.PB(i);
            }
        }
        while (!keep.empty()) {
            reverse(keep.back(), N);
            keep.PP();
        }
        cout << "Case #" << t << ":";
        if (C != 0) {
            cout << " IMPOSSIBLE\n";
        } else {
            for (int i=1; i<=N; i++)
                cout << " " << arr[i];
            cout << "\n";
        }
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
