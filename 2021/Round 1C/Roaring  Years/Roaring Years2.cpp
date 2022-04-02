#include<bits/stdc++.h>
#define int unsigned long long
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


int cht[maxn] = {};

vector<int> keep;

int len(int x) {
    int i;
    for (i=0; cht[i] <= x; i++);
    return i;
}

void produce(int now, int x, bool first = 1) {
    // printf("(%llu, %llu)\n", now, x);
    if (!first)
        keep.PB(now);

    if (len(now) + len(x+1) > 19)
        return;
    produce(now * cht[len(x+1)] + (x+1), x+1, 0);
}

void prepare() {
    cht[0] = 1;
    for (int i=1; i<=18; i++) {
        cht[i] = cht[i-1] * 10;
    }

    for (int i=1; i<=999997; i++) {
        // printf("now = %lld\n", i);
        produce(i, i);
    }
}

int twin(int x) {
    return x * cht[len(x+1)] + (x+1);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    prepare();
    sort(all(keep));

    cout << keep.back();

    for (int t=1; t<=T; t++) {
        int Y;
        cin >> Y;

        int ans = *upper_bound(all(keep), Y);

        for (int i=0; i<=len(Y); i++) {
            int cut = Y / cht[i];
            if (len(cut) + len(cut+1) > 19)
                continue;

            int x = twin(cut);
            printf("x = %llu\n", x);
            if (x > Y)
                ans = min(ans, x);

            if (len(cut+1) + len(cut+2) > 19)
                continue;

            x = twin(cut+1);
            printf("x2 = %llu\n", x);
            if (x > Y)
                ans = min(ans, x);
        }

        printf("Case #%llu: %llu\n", t, ans);
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
