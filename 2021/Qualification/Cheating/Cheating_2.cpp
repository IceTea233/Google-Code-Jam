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
#define cin file

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e2 + 7;

string table[maxn];
double p[maxn];
double err[maxn][2] = {};
bool removed[maxn] = {};

int val(char c) {
    return c == '1' ? 1 : -1;
}

int32_t main() {
    // cin.tie(0);
    int i,j;
    int T, P;
    fstream file;
    file.open("sample.txt");

    cin >> T;
    cin >> P;
    for (int t=1; t<=T; t++) {
        memset(err, 0, sizeof(err));
        for (int i=1; i<=100; i++)
            cin >> table[i];
        for (int i=0; i<10000; i++) {
            int cnt = 0;
            for (int j=1; j<=100; j++) {
                if (removed[j])
                    continue;
                if (table[j][i] == '1')
                    cnt++;
            }
            double p = (cnt / 100.0 - 0.5) * 2;
            
            // printf("p = %5.2f\n", p);
            for (int j=1; j<=100; j++) {
                double e;
                if (p < 0) {
                    e = max( 0.0,  -p * (table[j][i] == '1'));
                    err[j][0] += e * e;
                } else {
                    e = max( 0.0, p * (table[j][i] == '0'));
                    err[j][1] += e * e;
                }
            }
        }

        int ans = 0;
        vector<pair<double,int>> keep;
        for (int i=1; i<=100; i++) {
            if (removed[i])
                continue;
            keep.PB({err[i][0] * err[i][1], i});
            if (err[i][0] * err[i][1] > err[ans][0] * err[ans][1])
                ans = i;
        }
        sort(all(keep));
        for (auto it : keep) {
            printf("#%lld : (%.2f, %.2f)\n", it.S, err[it.S][0], err[it.S][1]);
        }
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
