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

string X[maxn];
string Y[maxn];

bool cmp(string a, string b) {
    if (a.size() < b.size())
        return 1;
    else if (a.size() > b.size())
        return 0;
    else
        return a < b;
}

string gen(string& now, string& prev) {
    if (cmp(prev, now))
        return now;

    string S = now;
    int flag = 0;

    for (int i=0; i<S.size(); i++) {
        if (prev[i] < S[i]) {
            flag = -1;
            break;
        }
        if (prev[i] > S[i]) {
            flag = 1;
            break;
        }
    }

    if (flag == -1) {
        while (S.size() != prev.size()) {
            S.PB('0');
        }
    } else if (flag == 1) {
        while (S.size() != prev.size() + 1) {
            S.PB('0');
        }
    } else {
        S = prev;
        int i;
        for (i=prev.size()-1; i >= now.size(); i--) {
            if (prev[i] == '9') {
                S[i] = '0';
            } else {
                S[i] = prev[i] + 1;
                flag = 1;
                break;
            }
        }

        if (flag) {
            //
        } else {
            S = now;
            while (S.size() != prev.size() + 1) {
                S.PB('0');
            }
        }
    }
    return S;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        int N;
        cin >> N;
        for (int i=1; i<=N; i++) {
            cin >> X[i];
        }
        Y[1] = X[1];
        for (int i=2; i<=N; i++) {
            Y[i] = gen(X[i], Y[i-1]);
            // cout << X[i] << ", " << Y[i] << "\n";
        }
        int ans = 0;
        for (int i=1; i<=N; i++) {
            ans += Y[i].size() - X[i].size();
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
