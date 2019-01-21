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

#define N 110
char name[N][40], func[N][N][40];
bool use[N][N];
int rt[N], cnt[N], cc;

void AppClass()
{
	char name1[100], *name2;
	int i;
	scanf("%s", name1);
	name2 = strchr(name1, ':');
	if (name2 != NULL) { name1[name2-name1] = '\0'; name2++; }
	for (i = 0; i < cc; ++i) if (!strcmp(name1, name[i])) { printf("oops!\n"); return; }
	if (name2 != NULL) {
		for (i = 0; i < cc; ++i) if (!strcmp(name2, name[i])) break;
		if (i == cc) { printf("oops!\n"); return; }
	}
	memset(use[cc], 0, sizeof(cc)); cnt[cc] = 0; if (name2 != NULL) rt[cc] = i; else rt[cc] = -1;
	strcpy(name[cc++], name1); 
	if (name2 != NULL) printf("class %s:%s\n", name1, name2); else printf("class %s\n", name1);
}

void AppMethod()
{
	char name1[100], *name2;
	int i, j;
	scanf("%s", name1);
	name2 = strchr(name1, '.'); name1[name2-name1] = '\0'; name2++;
	for (i = 0; i < cc; ++i) if (!strcmp(name1, name[i])) break;
	if (i == cc) {printf("oops!\n"); return; } j = i;
	for (i = 0; i < cnt[j]; ++i) if (use[j][i] && !strcmp(func[j][i], name2)) break;
	if (i < cnt[j]) { printf("redef %s.%s\n", name1, name2); return; }
	strcpy(func[j][cnt[j]], name2); use[j][cnt[j]] = true; cnt[j]++;
	printf("def %s.%s\n", name1, name2);
}

void ReleaseMethod()
{
	char name1[100], *name2;
	int i, j;
	scanf("%s", name1); name2 = strchr(name1, '.');
	name1[name2-name1] = '\0'; name2++;
	for (i = 0; i < cc; ++i) if (!strcmp(name1, name[i])) break;
	if (i == cc) { printf("oops!\n"); return; } j = i;
	for (i = 0; i < cnt[j]; ++i) if (use[j][i] && !strcmp(func[j][i], name2)) break;
	if (i == cnt[j]) { printf("oops!\n"); return; } use[j][i] = false;
	printf("undef %s.%s\n", name1, name2);
}

void CallMethod()
{
	char name1[100], *name2;
	int i, j;
	scanf("%s", name1); name2 = strchr(name1, '.');
	name1[name2-name1] = '\0'; name2++;
	for (i = 0; i < cc; ++i) if (!strcmp(name1, name[i])) break;
	if (i == cc) { printf("oops!\n"); return; } j = i;
	while (j >= 0) {
		for (i = 0; i < cnt[j]; ++i) if (use[j][i] && !strcmp(func[j][i], name2)) break;
		if (i < cnt[j]) { printf("invoke %s.%s\n", name[j], func[j][i]); return; }
		j = rt[j];
	} printf("oops!\n");
}

void conduct()
{
	char cmd[10];
	cc = 0;
	while (true) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "begin")) continue;
		else if (!strcmp(cmd, "end")) break;
		else if (!strcmp(cmd, "class")) AppClass();
		else if (!strcmp(cmd, "def")) AppMethod();
		else if (!strcmp(cmd, "undef")) ReleaseMethod();
		else CallMethod();
	} printf("\n");
}

int main()
{
	int time; scanf("%d", &time);
	while (time--) { conduct(); }
	return 0;
}
