// Rabin-Karp Algorithm

// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void rabinKarpSearchAlgo(string S, string P) {
    int x = S.length(), y = P.length(), primeNum = 31, mod = 1e9 + 9;
    vector<long long> pPow(x); pPow[0] = 1;
    for (int i = 1; i < x; i++) pPow[i] = (pPow[i - 1] * primeNum) % mod;

    vector<long long> h(x + 1, 0);
    for (int i = 0; i < x; i++) h[i + 1] = (h[i] + (S[i] - 'a' + 1) * pPow[i]) % mod;
    long long hashP = 0;
    for (int i = 0; i < y; i++) hashP = (hashP + (P[i] - 'a' + 1) * pPow[i]) % mod;

    for (int i = 0; i + y - 1 < x; i++) {
        long long currHash = (h[i + y] + mod - h[i]) % mod;
        if (currHash == hashP * pPow[i] % mod) cout << "Pattern found at index: " << i << endl;
    }
}

int main() {
    string S = "pabcasfabcasdfabcaaf", P = "abc";
    rabinKarpSearchAlgo(S, P);
    return 0;
}