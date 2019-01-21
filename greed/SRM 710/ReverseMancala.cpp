#include "bits/stdc++.h"
using namespace std;

class ReverseMancala {
    private:
    void processA(vector<int> &arr, const unsigned int pos){
        assert(pos<arr.size());
        int foo=arr[pos];
        arr[pos]=0;
        for(unsigned int i=0; i<arr.size(); i++){
            arr[i]+=foo/arr.size();
        }
        for(unsigned int i=1; i<=foo%arr.size(); i++){
            arr[(pos+i)%arr.size()]++;
        }
    }
    int toLast(vector<int> &arr, int *last=NULL){
        for(unsigned int i=0; i<arr.size()-1; i++){
            if(arr[i]>0){
                if(last!=NULL){
                    *last=(i+arr[i])%arr.size();
                }
                this->processA(arr, i);
                return i;
            }
        }
        return -1;
    }
    public:
    vector<int> findMoves(vector<int> start, vector<int> target){
        vector<int> ans;
        while(true){
            int foo=this->toLast(start);
            if(!~foo)break;
            ans.push_back(foo);
        }
        stack<int> seq;
        while(true){
            int last;
            int foo=this->toLast(target, &last);
            if(!~foo)break;
            seq.push(last);
        }
        for(; !seq.empty(); seq.pop()){
            ans.push_back(start.size()+seq.top());
        }
        return ans;
    }
};
