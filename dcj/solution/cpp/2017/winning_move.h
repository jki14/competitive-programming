// Sample input 3, in CPP.

#include <cassert>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define N 35

long long GetNumPlayers() {
  return N*1LL;
}

long long GetSubmission(long long i) {
  if(i>=N*1LL)assert(0);
  int hook = open("/dev/urandom", O_RDONLY);
  long long llval;
  if(hook<0)assert(1);
  if(read(hook, &llval, sizeof(long long))!=sizeof(long long)){
    assert(1);
    return 1;
  }
  close(hook);
  llval=(llval%1000000000LL+1000000000LL)%1000000000LL+1LL;
  return llval;
}
