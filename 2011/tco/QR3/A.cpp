int gcd(const int &x,const int &y){
	if (!y) return x;
	return gcd(y,x%y);
}

int AllButOneDivisor::getMinimum(vector <int> a) { n=a.size();
	int i,j;
	int val,ans,tot,gcdval;
	tot=1;
	for (i=0;i< divisors.size(); ++i) tot *= divisors[i];
	ans = 1000000000;
	for (i = 0; i < divisors.size(); ++i){
		val = 1;
		for (j = 0; j < divisors.size(); ++j) if (i != j) {
			gcdval = gcd(val, divisors[j]); val = val * divisors[j] / gcdval;
		}
		if (val % divisors[i] != 0 && val < ans) ans = val;
	}
	if (ans == 1000000000) return -1;
	else return ans;
}
