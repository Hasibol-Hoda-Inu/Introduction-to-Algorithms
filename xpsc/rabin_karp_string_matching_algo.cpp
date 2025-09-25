#include<bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet (e.g., 256 for ASCII)
#define d 256

void search(const string& pat, const std::string& txt, int q) {
    int M = pat.length();
    int N = txt.length();
    int i, j;
    long long p = 0; // hash value for pattern
    long long t = 0; // hash value for text window
    long long h = 1; // d^(M-1) % q

    // Calculate h = d^(M-1) % q
    for (i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value of pattern and the first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // If hash values match, then check for characters one by one
        if (p == t) {
            bool match = true;
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "yes" << endl;
            }
        }

        // Calculate hash value for the next window of text:
        // Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // Handle negative hash values (result of modulo with negative intermediate)
            if (t < 0) {
                t = (t + q);
            }
        }
    }
}

int main() {
    string txt = "GEEKSFORGEEKS";
    string pat = "GEEK";
    int q = 101; // A prime number for modulo operation

    search(pat, txt, q);

    return 0;
}