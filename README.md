# warrior

For Hamming Distance
A straightforward way to solve the problem is to go through all pairs of strings
and calculate their Hamming distances, which yields an O(n2k) time algorithm.

The following function can be used to calculate distances:

int hamming(string a, string b) {
int d = 0;
for (int i = 0; i < k; i++) {
if (a[i] != b[i]) d++;
}
return d;
}

However, if k is small, we can optimize the code by storing the bit strings
as integers and calculating the Hamming distances using bit operations. In
particular, if k <= 32, we can just store the strings as int values and use the
following function to calculate distances:

int hamming(int a, int b) {
return __builtin_popcount(a^b);
}
