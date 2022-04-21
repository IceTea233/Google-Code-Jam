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

int E, W;
int X[107][107] = {};
int cnt[107] = {};

int ans = INF;
vector<int> stk;

int chk(int exer) {
    bool flag = false;
    for (int i=1; i<=W; i++) {
        if (cnt[i] > X[exer][i])
            return 2;
        if (cnt[i] < X[exer][i])
            flag = true;
    }
    return flag;
}

void show() {
    cout << ">>> ";
    for (auto it : stk) {
        cout << it << " ";
    }
    cout << "\n";
}

void solve(int exer, int cost) {
    // printf("cur = (%lld, %lld)\n", exer, cost);
    // show();

    if (cost > 100)
        return;
    if (exer > E) {
        ans = min(ans, cost);
        return;
    }
    vector<int> keep;
    if (chk(exer) == 0) {
        while (chk(exer + 1) == 2) {
            cost ++;
            cnt[stk.back()]--;
            keep.PB(stk.back());
            stk.PP();
        }
        solve(exer + 1, cost);
        while (keep.size()) {
            cost --;
            cnt[keep.back()]++;
            stk.PB(keep.back());
            keep.PP();
        }
        return;
    }

    keep.clear();
    while (stk.size() >= 0) {
        for (int i=W; i>=1; i--) {
            if (keep.size() && i == keep.back())
                continue;
            if (cnt[i] < X[exer][i]) {
                stk.PB(i);
                cnt[i]++;
                solve(exer, cost + 1);
                stk.PP();
                cnt[i]--;
            }
        }

        if (stk.size() == 0) {
            break;
        }
        // printf("PB %lld\n", stk.back());
        keep.PB(stk.back());
        cnt[stk.back()]--;
        stk.PP();
        cost ++;
    }

    while (keep.size()) {
        cost --;
        cnt[keep.back()]++;
        stk.PB(keep.back());
        keep.PP();
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> E >> W;
        memset(X, 0, sizeof(X));
        for (int i=1; i<=E; i++) {
            for (int j=1; j<=W; j++) {
                cin >> X[i][j];
            }
        }

        ans = INF;
        solve(1, 0);
        for (int i=1; i<=W; i++) {
            if (cnt[i] != 0) {
                printf("ERR\n");
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
