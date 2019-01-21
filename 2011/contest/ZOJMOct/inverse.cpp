lld inverse(lld a, lld b)
{
	lld r=a%b,x0=1,y0=0,x1=0,y1=1;
	while(r){
		lld n=a/b;
		lld tx=x0-n*x1;
		lld ty=y0-n*y1;
		x0=x1,y0=y1,x1=tx,y1=ty;
		a=b,b=r,r=a%b;
	}
	return (x1+b)%b;
}
