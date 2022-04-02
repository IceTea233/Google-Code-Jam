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
const int maxn = 1e5 + 7;
const int maxi = 43200000000000LL;

bool equal(vector<int> &a, vector<int> &b) {
    vector<pii> keep = {{b[0], 0}, {b[1], 1}, {b[2], 2}};
    sort(all(keep));
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {

        }
    }
    return 0;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        int A, B, C;
        cin >> A >> B >> C;

        bool flag = 0;
        int h = 0, m = 0, s = 0, ns = 0;
        for (int i=0; i<=11 && !flag; i++) {
            for (int j=0; j<=59 && !flag; j++) {
                for (int k=0; k<=59 && !flag; k++) {
                    vector<int> keep;
                    keep.PB(k * (maxi / 60));
                    keep.PB(j * (maxi / 60) + k * (maxi / 3600));
                    keep.PB(i * (maxi / 12) + j * (maxi / 720) + k * maxi / 43200);

                    if (equal(D, keep)) {
                        flag = 1;
                        h = i;
                        m = j;
                        s = k;
                        break;
                    }
                }
            }
        }

        printf("Case #%lld: %lld %lld %lld %lld\n", t, h, m, s, ns);
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
