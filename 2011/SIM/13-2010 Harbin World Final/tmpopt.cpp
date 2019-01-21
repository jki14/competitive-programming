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
#include<set>
#include<map>
using namespace std;

#define L 1100000

char s[L];

int main(){
    freopen("TReplay.csv","r",stdin);freopen("Replay.csv","w",stdout);
    for(int i=0;gets(s);i++){
            if(i&1)puts(s);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
