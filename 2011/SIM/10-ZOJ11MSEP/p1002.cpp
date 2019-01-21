#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

long long N,F,W,G,D,Wood,Framer,myG;
long long mA[1100],mG[1100],minleftGold[1100];

long long max(long long x, long long y) {
	return x>y?x:y;
}
void buyFramer(long long X) {
	while(G >= (X+F) && G >= 0) {
		int Del = (G-X) / F;
		int Avg = Del + Framer + W;
		int Mod = (Avg) % 2;
		Avg = Avg / 2;
		if(Avg < W) Framer += Del;
		else {
			if(Mod == 0) {
				Framer = Avg;
				W = Avg;
			} else {
				Framer = Avg;
				W = Avg + 1;
			}
		}	
		G -= F * Del;
	}
}

bool prefightMonsters() {
	long long Ddel;
	int j;
	for(int i =0; i < N; i++) {
		minleftGold[i] = mA[i]-D;
		if(D < mA[i]) {
			G -= mA[i]-D;
			if(G < 0) return false;
			Ddel = minleftGold[i];
			j = i-1;
			while(j > 0 && Ddel > mG[j]) {
				minleftGold[j] = max(minleftGold[j], Ddel-mG[j]);
				Ddel -= mG[j];
				j--;
			}
			D = mA[i];
		}
		//printf("left[%d]:%lld\n", i, minleftGold[i]);
		G += mG[i];	
	}
	return true;
}

void fightMonsters() {
	for(int i =0; i < N; i++) {
		buyFramer(minleftGold[i]);
		//printf("Round %d: %lld %lld %lld %lld  mA:%lld mG:%lld left:%lld\n", i, Framer, W, D, G, mA[i], mG[i], minleftGold[i]);
		Wood += Framer * W;
		if(D < mA[i]) {
			G -= mA[i]-D;
			D = mA[i];
		}
		G += mG[i];	
	}
}

int main() {
	while(scanf("%lld %lld %lld %lld", &N, &F, &W, &G) != EOF) {
		D = 0;
		myG = G;
		Wood = 0;
		Framer = 0;
		for(int i = 0; i < N; i++)
			scanf("%lld %lld", &mA[i], &mG[i]);
		if(prefightMonsters()) {
			D = 0;
			G = myG;
			fightMonsters();
			printf("%lld\n", Wood);
		} else printf("It's useless to collect wood.\n");
	}
	return 0;
}
