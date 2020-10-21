/*
If the first character is X, all permutations which had the first character less than X would come before this permutation when sorted lexicographically.
Number of permutation with a character C as the first character = number of permutation possible with remaining N-1 character = (N-1)! / (p1! * p2! * p3! ... ) where p1, p2, p3 are the number of occurrences of repeated characters.
For example, number of permutations possible with 3 ‘a’ and 3 ‘b’ is 6! / 3! 3! = 20
Hence,
rank = number of permutation possible with placing characters smaller than current first character in the first position + rank of permutation of string with the first character removed
So, we take a loop on the possibilities for the first character, and if that character is less than the current first character, we calculate the number of permutations using the formula given above (N-1)! / (p1! * p2! * p3! ... )
Now, there is a slight problem.
(N-1)! / (p1! * p2! * p3! ... ) does not necessarily fit in an integer. It is easy to calculate (N-1)! % MOD.
However, how do we handle divisions ? Modular_multiplicative_inverse is what you are looking for.
In short,
(1/A) % MOD = A ^ (MOD - 2) % MOD
*/

int mod = 1000003;
long long f[1000009], inv[1000009];
void pre(int n)
{
    f[0] = f[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] * i % mod;
        inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    }
    for (int i = 2; i <= n; i++)
        inv[i] = (inv[i - 1] * inv[i]) % mod;
}
int Solution::findRank(string A)
{
    pre(A.size());
    int rank = 1;
    for (int i = 0; i < A.size(); i++)
    {
        // int c=0;
        map<char, int> m;
        set<char> s;
        for (int j = i + 1; j < A.size(); j++)
        {
            m[A[j]] += 1;
            if (A[i] > A[j]) s.insert(A[j]);
        }
        int  c = s.size();
        int a = 0;
        m[A[i]] += 1;
        for (char se : s)
        {
            int b = f[A.size() - 1 - i];
            m[se]--;
            for (auto e : m)
            {
                if (e.second > 1)
                {
                    int d = e.second;
                    b = (b * inv[d]) % mod;
                }
            }
            m[se]++;
            a = (a + b) % mod;
        }
        a = (a + 1000003) % 1000003;
        rank = (rank + (a) % mod) % mod;
    }
    return rank;
}