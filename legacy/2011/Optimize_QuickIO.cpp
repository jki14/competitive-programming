//============================================================================
// Name        : QuickIO
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 快速读入输出模板
//============================================================================

#define LEN 11

char ch,cstr[LEN];

int readsigned(){
	int ret,neg;

	do{
		ch = getchar() ;
	}while(ch!='-' && ch<'0');

	if ( ch == '-' ){
		neg = 1 ;
                ret = 0 ;
	}else{
		neg=0;
		ret = ch - '0' ;
	}
	while((ch = getchar()) >= '0'){
		ret = ret * 10 + ch - '0' ;
	}
	if (neg)return -ret;
	return ret;
}

int readunsigned(){
	int ret;

	do{
		ch = getchar() ;
	}while(ch<'0');
	ret = ch - '0' ;

	while((ch = getchar()) >= '0'){
		ret = ret * 10 + ch - '0' ;
	}

	return ret;
}

void putsigned(const int &x){
	int k=(x<0)?-x:x,r=0;
	do{
		cstr[r++]=k%10+'0';
		k/=10;
	}while(k);
	if(x<0)putchar('-');
	while(r--){
		putchar(cstr[r]);
	}
	putchar('\n');
}

void putunsigned(const int &x){
	int k=x,r=0;
	do{
		cstr[r++]=k%10+'0';
		k/=10;
	}while(k);
	while(r--){
		putchar(cstr[r]);
	}
	putchar('\n');
}
