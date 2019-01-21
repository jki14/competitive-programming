// Sample input 3, in CPP.
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include "message.h"

static int isthenodebroken = 0;
//static int testvs[] = {1, 0, 1, 0, 1};

class Task{
    private:
    int *value;
    int qod;
    public:
    Task(){
        this->value=(int*)malloc(sizeof(int)*10000);
        srand(10086);
        for(int i=0; i<10000; i++)
            this->value[i]=rand()&1;
        this->qod=666;
    }
    ~Task(){
        free(this->value);
    }
    int getValue(const int pos){
        return this->value[pos];
    }
    int getQod(){
        return this->qod;
    }
};

static Task *task=NULL;

long long GetLength() {
  return 10000LL;
}

int GetValue(long long i) {
  if (i < 0LL || i >= GetLength())
    assert(0);
  if(task==NULL){
    task=new Task();
  }
  int val = (int)(task->getValue(i)^(rand() % (isthenodebroken + 1)));
  if (i == task->getQod())
    isthenodebroken = 1;
  return val;
}
