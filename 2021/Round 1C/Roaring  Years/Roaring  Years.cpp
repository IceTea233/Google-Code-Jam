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



int cht[maxn] = {};

int digit(int x, int idx) {
    return x / cht[idx] % 10;
}

bool flag = 0;
vector<int> nums;
bool conti() {
    for (int i=1; i<nums.size(); i++) {
        if (nums[i] - nums[i-1]  != 1)
            return 0;
    }
    return 1;
}
void guess(int x, int idx) {
    if (idx < 0) {
        if (nums.size() <= 1)
            return;
        if (!conti())
            return;
        // for (auto it : nums)
        //     printf("%lld ", it);
        // printf("\n");
        flag = 1;
        return;
    }

    if (conti() && digit(x, idx) != 0) {
        nums.PB(digit(x, idx));
        guess(x, idx-1);
        if (flag)
            return;
        nums.PP();
    }
    nums.back() = nums.back() * 10 + digit(x, idx);
    guess(x, idx-1);
    if (flag)
        return;
    nums.back() /= 10;
}

bool chk(int x) {
    flag = 0;
    int i;
    for (i=0; cht[i+1] <= x; i++);
    nums = {0};
    guess(x, i);
    return flag;
}

vector<int> keep;

void prepare() {
    cht[0] = 1;
    for (int i=1; i<=18; i++) {
        cht[i] = cht[i-1] * 10;
    }

    for (int i=1; i<=2000000; i++) {
        if (chk(i))
            keep.PB(i);
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int T;

    cin >> T;
    prepare();

    for (int t=1; t<=T; t++) {
        int Y;
        cin >> Y;
        int ans = *upper_bound(all(keep), Y);
        printf("Case #%lld: %lld\n", t, ans);
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
