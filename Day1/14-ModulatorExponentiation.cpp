#include <bits/stdc++.h>
//   long long myP(double x,long long n){
//         if(n==0)return 1;
//         if(n==1)return x;
//         if(n%2==0)return myP(x*x,n/2);
//         return x*myP(x,n-1);
//         //return 1.0;
//     }
// int modularExponentiation(int x, int n, int m) {
// 	// Write your code here.
// 	int flag=0;
//         long long temp=n;
//         if(n<0){
//             flag=1;
//             temp*=-1;
//         }
//         long long mul=myP(x,temp);
// 		int ans=(int)(mul%m);
//         if(flag)return 1/ans;
//         return ans;
// }
//i don't know why the above solution is giving wrong answer. Please understand again and solve it correctly.
//After understanding fom codestudio solutions.
int modularExponentiation(int x, int n, int m) {
	if (n == 0) {
		return 1;
	}
	int ans = modularExponentiation(x, n / 2, m);
	if (n % 2 == 0) {
		return (1LL * ans * ans) % m;
	}
	else {
		return (1LL * (1LL * ans * ans) % m * x % m) % m;
	}
}
