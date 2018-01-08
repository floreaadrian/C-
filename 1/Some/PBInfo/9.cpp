int cmmnr(int n)
{
	int c=0,l;
	l=n;
	for(int i=0;i<=9;i++)
	{
		while(n>0)
		{
			if(n%10==i)
			c=c*10+i;
			n=n/10;
		}
		n=l;
	}
	return c;
}
