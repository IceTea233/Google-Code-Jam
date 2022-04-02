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
#define cin   file

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e2 + 7;
const double e = 2.718281828;

string table[maxn];
double err[maxn] = {};
double pp[maxn] = {};

double normal(double x) {
    return -3 + 6 * x;
}

double f(double x) {
    return 1 / (1 + pow(e, -x));
}

int val(char c) {
    return c == '1' ? 1 : 0;
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
        memset(pp, 0, sizeof(pp));
        for (int i=1; i<=100; i++)
            cin >> table[i];
        vector<pair<double, int>> S;
        for (int i=1; i<=100; i++) {
            int cnt = 0;
            for (int j=0; j<10000; j++) {
                if (table[i][j] == '1')
                    cnt++;
            }
            pp[i] = f(normal(cnt / 10000.0));
            S.PB({pp[i], i});
        }
        sort(all(S));
        de(1) {
            for (auto it : S) {
                printf("#%2lld. acc = %4.2f\n", it.S, it.F);
            }
        }

        vector<pair<double, int>> P;
        for (int i=0; i<10000; i++) {
            int cnt = 0;
            for (int j=1; j<=100; j++) {
                if (table[j][i] == '1')
                    cnt++;
            }
            double dif = 1 - cnt / 100.0;
            P.PB({dif, i});
        }
        sort(all(P));
        for (int i=0; i<10000; i++) {
            if (500 < i && i < 9500)
                continue;
            int p = P[i].S;
            for (int j=0; j<100; j++) {
                if (j == 0) {
                    err[S[j].S] += abs(table[S[j].S][p] - table[S[j+1].S][p]);
                } else if (j == 99) {
                    err[S[j].S] += abs(table[S[j].S][p] - table[S[j-1].S][p]);
                } else {
                    err[S[j].S] += ( abs(table[S[j].S][p] - table[S[j+1].S][p]) + abs(table[S[j].S][p] - table[S[j-1].S][p]) ) / 2.0;
                }
            }
        }

        int ans = 0;
        vector<pair<double,int>> keep;
        for (int i=1; i<=100; i++) {
            keep.PB({err[i], i});
            if (err[i] > err[ans])
                ans = i;
        }
        sort(all(keep));
        de(1) {
            for (auto it : keep) {
                cout << "#" << it.S << ": " << it.F << "\n";
            }
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
