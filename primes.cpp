#include<bits/stdc++.h>
using namespace std;

map<int,int> sieve(int n){
	map<int,int> primes;
	vector<int> p(1001,1);
	p[0] = p[1] = 0;
	for(int i = 2; i <= 1000; i++){
		if(p[i] == 0)
			continue;
		for(int j = i*i; j <= 1000; j += i){
			p[j] = 0;
		}
	}
	for(int i = 2; i < 1000; i++){
		if(p[i]){
			primes[i] = 1;
		}
	}
	return primes;
}

int solve(string &s, map<int,int> &prime){
	int n = s.size();
	int dp[n+1] = {0};	// dp[i] - number of ways to split till ith digit into primes
	dp[0] = 1;
	
	const int mod = 1e9 + 7;
	
	for(int i = 1; i <= n; i++){
		
		if(s[i-1] != '0' && prime[stoi(s.substr(i-1,1))])
			dp[i] = dp[i-1];
		
		if(i-2 >= 0 && s[i-2] != '0' && prime[stoi(s.substr(i-2,2))])
			dp[i] = (dp[i] + dp[i-2]) % mod;
			
		if(i-3 >= 0 && s[i-3] != '0' && prime[stoi(s.substr(i-3,3))])
			dp[i] = (dp[i] + dp[i-3]) % mod;
	
	}
	return dp[n];
}

int main(){
	
	// generate all primes till 1000
	map<int,int> prime = sieve(1000);		// since 1000 is small you could also have done n*sqrt(n)

	string s;
	cin >> s;
	
	cout << solve(s,prime) << endl;
	

	return 0;
}