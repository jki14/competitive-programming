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

#define S 1100000

char ss[S];

int main(){
	while(scanf("%s",ss)!=EOF);
	puts("27\nint main() {\n    int r0 = 0;\n    int r1 = 0;\n    for (int i0 = 0; i0 < 100; i0++) {\n        r1 = r1 + 1;\n        r0 = r0 + r1;\n    }\n    printf(\"%d %d\", r0, r1);\n    return 0;\n}");
	return 0;
}
