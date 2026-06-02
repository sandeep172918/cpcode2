#include <iostream>
#include <string>

using namespace std;

void solve() {
    long long n_in, x_in, s_in;
    cin >> n_in >> x_in >> s_in;
    string u;
    cin >> u;

    __int128 eia = 0;
    __int128 E_tables = x_in;
    __int128 P_seats = 0;
    __int128 A_P = 0;
    __int128 ans = 0;
    __int128 s = s_in;

    for (char c : u) {
        if (c == 'I') {
            if (E_tables > 0) {
                E_tables--;
                P_seats += s - 1;
                ans++;
                eia++;
            }
        } else if (c == 'E') {
            if (P_seats > 0) {
                P_seats--;
                ans++;
                eia++;
            } else if (A_P > 0 && E_tables > 0) {
                A_P--;
                E_tables--;
                P_seats += s - 1;
                ans++;
                eia++;
            }
        } else if (c == 'A') {
            if (P_seats > 0) {
                P_seats--;
                A_P++;
                ans++;
                eia++;
            } else if (E_tables > 0) {
                E_tables--;
                P_seats += s - 1;
                ans++;
                eia++;
            }
        }
    }

    cout << (long long)ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}