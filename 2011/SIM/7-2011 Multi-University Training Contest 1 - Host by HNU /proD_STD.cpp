#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXN 505

char sor[MAXN], des[MAXN];
int f[MAXN][MAXN][55];
int leni, lenj;

int imin(int a, int b){
	return a < b ? a : b;
}

int dfs(int i, int j, int k){
	int p;
	if (i >= leni) return lenj - j;
	if (j >= lenj) return leni - i;
	if (f[i][j][k] >= 0) return f[i][j][k];
	f[i][j][k] = 0x7fffffff;

	f[i + 1][j + 1][des[j + 1]] = dfs(i + 1, j + 1, des[j + 1]);	

	
	f[i + 1][j + 1][52] = dfs(i + 1, j + 1, 52);
	f[i + 1][j + 1][k] = dfs(i + 1, j + 1, k);
	f[i + 1][j][des[j]] = dfs(i + 1, j, des[j]);
	f[i + 1][j][k] = dfs(i + 1, j, k);
	f[i][j + 1][des[j + 1]] = dfs(i, j + 1, des[j + 1]);
	f[i][j + 1][k] = dfs(i, j + 1, k);
//change
	if (k == 52){
		p = imin(f[i + 1][j + 1][52] + 1, f[i + 1][j + 1][des[j 

+ 1]] + 1 + 1);
		if (sor[i] == des[j]) p--;
		f[i][j][k] = imin(f[i][j][k], p);
	}else{
		p = imin(f[i + 1][j + 1][k] + 1, f[i + 1][j + 1][des[j 

+ 1]] + 1 + 1 - (k == des[j + 1]));
		if (k == des[j]) p--;
		f[i][j][k] = imin(f[i][j][k], p);
	}
//del
	f[i][j][k] = imin(f[i][j][k], f[i + 1][j][des[j]] + 1 + 1 - (k 

== des[j]));
	f[i][j][k] = imin(f[i][j][k], f[i + 1][j][k] + 1);
//insert	
	f[i][j][k] = imin(f[i][j][k], f[i][j + 1][des[j + 1]] + 1 + 1 - 

(k == des[j + 1]));						
	f[i][j][k] = imin(f[i][j][k], f[i][j + 1][k] + 1);		

						
	return f[i][j][k];
}

int main(){
	int i, j, k, p;
//	freopen("DICS.in","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%s", sor), sor[0] != '#'){
		scanf("%s", des);
		leni = strlen(sor);
		lenj = strlen(des);
		memset(f, -1, sizeof(f));
		for (i = 0; i < leni; i++){
			if (sor[i] >= 'a' && sor[i] <= 'z') sor[i] = 

sor[i] - 'a' + 26;
			else sor[i] = sor[i] - 'A';
		}
		for (i = 0; i < lenj; i++){
			if (des[i] >= 'a' && des[i] <= 'z') des[i] = 

des[i] - 'a' + 26;
			else des[i] = des[i] - 'A';
		}
		
		p = imin(dfs(0, 0, 52), dfs(0, 0, des[0]) + 1);
		printf("%d\n", p);
	}
//    system("pause");
    return 0;
}

/***************
其实状态和方程都不难想，就是写起来有点乱...思路不清晰吧...
f[i][j][k] 原串后i个字符，与目标后j个字符做匹配，在这之前最近一次发生的

置后缀操作为“置k”，k=52时表示不置后缀

change
f[i][j][k] = f[i + 1][j + 1][k1] (sor[i] == des[j])
             f[i + 1][j + 1][k1] + 1
注意，若k != 52 则要看 k == des[j]
      若k1 != k， 说明发生了置后缀操作 再 + 1
      （下同，不再赘述）
del
f[i][j][k] = f[i + 1][j][k1] + 1
insert
f[i][j][k] = f[i][j + 1][k1] + 1

实际k1 只可能取 k, des[j](或des[j + 1])，取其他不是添乱么...
用记忆化搜索，想减少不必要的状态，但没写好，跑起来极慢...

场上脑残，把样例看错了，一直以为自己错了，在那里调啊调, 后来自己给了组

数据，答案算错了，又在那里调啊调...结束后，跑了遍数据竟然A了...
这世上，什么事都有= =
***************/
