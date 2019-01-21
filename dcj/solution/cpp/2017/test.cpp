#include <stdio.h>
#include <unistd.h>

#include "message.h"

int main(){
    if(MyNodeId()!=0){
        PutChar(0, '0');
        PutChar(0, 'a');
        Send(0);
        PutChar(0, '2');
        PutChar(0, 'b');
        Send(0);
        usleep(2000000);
        PutChar(0, '3');
        PutChar(0, 'c');
        Send(0);
    }else{
        usleep(3000000);
        for(int i=0; i<3; i++){
            int k=Receive(1);
            printf("k=%d\n", k);
            for(int k=0; k<2; k++){
                char c=GetChar(1);
                putchar(c);
            }
            putchar('\n');
        }
    }
    return 0;
}
