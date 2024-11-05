// Knuth-Morris-Pratt (KMP) Algorithm
#include <iostream>
#include <vector>
using namespace std;

void computeLPSArray(string& pat, int M, vector<int>& lps) {
    int len = 0, i = 1; lps[0] = 0;
    while (i < M) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
}

vector<int> KMPSearch(string& pat, string& txt) {
    int M = pat.length(), N = txt.length(), i = 0, j = 0;
    vector<int> lps(M), result; computeLPSArray(pat, M, lps);
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) { j++; i++; }
        if (j == M) { result.push_back(i - j); j = lps[j - 1]; }
        else if (i < N && pat[j] != txt[i]) j ? j = lps[j - 1] : i++;
    }
    return result;
}

int main() {
    string txt = "ekanshandsumit", pat = "ekansh";
    vector<int> result = KMPSearch(pat, txt);
    for (int idx : result) cout << idx << " ";
    return 0;
}
// Output: 0