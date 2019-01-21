
//"XOOXOOOOOOXOXXNOXXOOOXXOOOXOXOO", "OXOXXXOOOXXXXOOXXOXOOOOXXXOXNOO", "OOXXOXXXNOXXXXOXXXXOOXOXXXOXXXX", "XXXXOOOOXXXXXXOXXXXXOOOOXOOOXOO", "OXOOXOOOXXOXXOXXXOXOXNXXXXXOXOX", "OXXOOXOXOOXOXXOXOOOOOOXXOXXOOOO", "OOXOOOXOXOOXOOOXNXOOXXOOXXXOOXX", "OOXOOXOXOXOOXOOXXOXOXXOXXOOXXXX", "OONXXOXOXXOOXXXOXXXOXXXOXXXXXXO", "OXOXXOOXXXXOXXXOOOXXOOXXXOXXXOX", "XXXXOXOOOXXXXOXXXOXOXOXOXXXOXOO", "OXXXXOXOOOXXXOXXXXXXXOXOXOXOXXX", "XXXXXXOXXXXXXXXXXOXOXOXXXXXOXXO", "XOXXOXOOXXOOXXXOXOXOOXXXXXXOOOX", "NOOOXOOOXXXXXXXOOXXOXOXOOXXXOOO", "OXXXXXXXOOXXXOOXXXXXOXOXXXXOXOX", "XXXXXONXXOXXXXOXXXOOXXXXXOXXOXX", "XOXXOOXOXOOXOOXXXXXOOXXOXXOOXXX", "OXXXXOOXXXXXXXXXOXXXXXOXOXOXXXX", "OOOXOOOOOXOXOOOXOOXXONXNXOXXOOO", "OOOOXOXXXOXXXOXOXOXOXXOOXOXOOOX", "XOXONOXXXOOOOXOXXXXNXXXOXOOXOOX", "XOOOXXOOXXXXXXXOXXOXOXXXXOOXXOX", "OXXOXXOXOXOOXXOXXOXNOOXXXOXXXOX", "OXXXXOXXXXXXXXOXXXOXXXXXXXXXXOX", "OXXOXXXOXOXOXXXXOXXOOOOOXXOXXXX", "XOOOXXXOXXXXXXXXXOOXXOOXXOXOXOX", "OXXOOOOXXXOOOOXOXOXXOXXXXXOXOOO", "XNXXXOOXXXXXXOOXOXXOOOXXXXXOXOX", "OOXOOOXXXOOXXOOOXXXOOOOOOXOOOXX", "OOXOXOXXOXOXOXOXXXXOXXXXXXXOXXX"

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define oo 200

class OldBridges {
public:
	int cap[60][60], cap__[60][60], n;
	int s, t, an, bn;
	int max_flow;
	int trace[60];
	int f[60][60];
	
	bool find_path() {
		queue<int> q;
		memset(trace, -1, sizeof(trace));
		q.push(s);
		trace[s] = s;
		
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			
			for (int v = 0; v < n; v++)
				if (trace[v] == -1 && cap[u][v] > f[u][v]) {
					trace[v] = u;
					q.push(v);
					if (v == t) return true;
				}
		}
		
		return false;
	}
	
	void increase_flow() {
		int u = t;
		int delta = oo;
		
		while (u != s) {
			delta = min(delta, cap[trace[u]][u] - f[trace[u]][u]);
			u = trace[u];
		}
		
		u = t;
		while (u != s) {
			f[trace[u]][u] += delta;
			f[u][trace[u]] -= delta;
			u = trace[u];
		}	
		
		max_flow += delta;
	}
	
	int flow(int s1, int s2, int t1, int t2) {
		memset(cap, 0, sizeof(cap));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cap[i][j] = cap__[i][j];
				
		s = n; 
		t = n + 1;

		n = n + 2; 		//for convenience
		
		cap[s][s1] = 2 * an;
		cap[s][s2] = 2 * bn;
		cap[t1][t] = 2 * an;
		cap[t2][t] = 2 * bn;
	
		memset(f, 0, sizeof(f));
		max_flow = 0;
		while (find_path()) increase_flow();
		
		//n should keep the original value of it
		n = n - 2;
		printf("max_flow=%d\n",max_flow);
		return max_flow;
	}
	
	string isPossible(vector <string> bridges, int a1, int a2, int an_, int b1, int b2, int bn_) {
		n = bridges.size();
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cap__[i][j] = bridges[i][j] == 'X' ? 0: bridges[i][j] == 'O' ? 2 : oo;
				
		an = an_;
		bn = bn_;

		return (flow(a1, b1, a2, b2) >= 2 * (an + bn)) && (flow(a1, b2, a2, b1) >= 2 * (an + bn))? "Yes" : "No";
	}
};


double test0() {
	string t0[] = {"XOXX","OXOX","XOXO","XXOX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	int p3 = 1;
	int p4 = 2;
	int p5 = 3;
	int p6 = 1;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"XOXX","OXOX","XOXO","XXOX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 2;
	int p3 = 1;
	int p4 = 1;
	int p5 = 3;
	int p6 = 1;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "No";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"XOXO","OXOX","XOXO","OXOX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 2;
	int p3 = 1;
	int p4 = 1;
	int p5 = 3;
	int p6 = 1;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"XNXO","NXOX","XOXO","OXOX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 2;
	int p3 = 1;
	int p4 = 1;
	int p5 = 3;
	int p6 = 2;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "No";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"XOXOO","OXOXO","XOXOO","OXOXO","OOOOX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 2;
	int p3 = 2;
	int p4 = 1;
	int p5 = 3;
	int p6 = 2;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"XOOXOOOOOOXOXXNOXXOOOXXOOOXOXOO", "OXOXXXOOOXXXXOOXXOXOOOOXXXOXNOO", "OOXXOXXXNOXXXXOXXXXOOXOXXXOXXXX", "XXXXOOOOXXXXXXOXXXXXOOOOXOOOXOO", "OXOOXOOOXXOXXOXXXOXOXNXXXXXOXOX", "OXXOOXOXOOXOXXOXOOOOOOXXOXXOOOO", "OOXOOOXOXOOXOOOXNXOOXXOOXXXOOXX", "OOXOOXOXOXOOXOOXXOXOXXOXXOOXXXX", "OONXXOXOXXOOXXXOXXXOXXXOXXXXXXO", "OXOXXOOXXXXOXXXOOOXXOOXXXOXXXOX", "XXXXOXOOOXXXXOXXXOXOXOXOXXXOXOO", "OXXXXOXOOOXXXOXXXXXXXOXOXOXOXXX", "XXXXXXOXXXXXXXXXXOXOXOXXXXXOXXO", "XOXXOXOOXXOOXXXOXOXOOXXXXXXOOOX", "NOOOXOOOXXXXXXXOOXXOXOXOOXXXOOO", "OXXXXXXXOOXXXOOXXXXXOXOXXXXOXOX", "XXXXXONXXOXXXXOXXXOOXXXXXOXXOXX", "XOXXOOXOXOOXOOXXXXXOOXXOXXOOXXX", "OXXXXOOXXXXXXXXXOXXXXXOXOXOXXXX", "OOOXOOOOOXOXOOOXOOXXONXNXOXXOOO", "OOOOXOXXXOXXXOXOXOXOXXOOXOXOOOX", "XOXONOXXXOOOOXOXXXXNXXXOXOOXOOX", "XOOOXXOOXXXXXXXOXXOXOXXXXOOXXOX", "OXXOXXOXOXOOXXOXXOXNOOXXXOXXXOX", "OXXXXOXXXXXXXXOXXXOXXXXXXXXXXOX", "OXXOXXXOXOXOXXXXOXXOOOOOXXOXXXX", "XOOOXXXOXXXXXXXXXOOXXOOXXOXOXOX", "OXXOOOOXXXOOOOXOXOXXOXXXXXOXOOO", "XNXXXOOXXXXXXOOXOXXOOOXXXXXOXOX", "OOXOOOXXXOOXXOOOXXXOOOOOOXOOOXX", "OOXOXOXXOXOXOXOXXXXOXXXXXXXOXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10;
	int p2 = 26;
	int p3 = 11;
	int p4 = 28;
	int p5 = 16;
	int p6 = 23;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
