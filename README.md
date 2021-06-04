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
1. ![image](https://user-images.githubusercontent.com/31109284/120796125-111f7400-c558-11eb-8eef-c5d96160ab73.png)
2. ![image](https://user-images.githubusercontent.com/31109284/120796191-25637100-c558-11eb-8aa0-5d15b6dd86ef.png)
3. ![image](https://user-images.githubusercontent.com/31109284/120796060-f4833c00-c557-11eb-88d7-a6d84639c81d.png)

