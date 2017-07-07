#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int PanDuan(int m)
{
    if(m==1) return 0;
	int i;
	for(i=2;i<m;i++)
		if(m % i==0)
			return 0;
	return 1;
}

int MiYaoNi(int a,int n)
{
	int i,j;
	int q[50],c[50],b[50];
	q[0]=n/a;
	c[0]=n%a;
	if(c[0]==1)
	{
		i=0;
		goto GT;
	}
	q[1]=a/c[0];
	c[1]=a%c[0];
	if(c[1]==1)
	{
		i=1;
		goto GT;
	}
	for(i=2;i<50;i++)
	{
		q[i]=c[i-2]/c[i-1];
		c[i]=c[i-2]%c[i-1];
		if(c[i]==1)
			break;
	}
GT:	b[0]=0;
	b[1]=1;
	for(j=0;j<=i;j++)
	{
		b[j+2]=(-1)*b[j+1];
		b[j+2]*=q[j];
		b[j+2]+=b[j];
	}
	if(b[j+1]<0)
		b[j+1]=n+b[j+1];
	return b[j+1];
}

long Mi(long m,int e,int n)
{
	long t=1,s;
	for(int i=1;i<=e;i++)
    {
        s=t*m;
        t=s%n;
    }

	return t;
}

int SuiJi(int N)
{
	srand(time(0));
    return rand()%N+1;
}

int HuZhi(int a,int b)
{
    return b?HuZhi(b,a%b):a;
}


main()
{
	int p,q,n,e,d,N,x,z;
	long M,C;
	int pp=0,pq=0;
	while(!pp)
	{
		//cout<<"请输入p:";
		//cin>>p;
		p=SuiJi(20);
		pp=PanDuan(p);
	}
	cout<<"p="<<p<<endl;
	while(!pq)
	{
		//cout<<"请输入q:";
		//cin>>q;
		q=SuiJi(20);
		pq=PanDuan(q);
		if(p==q)
			pq=0;
	}
	cout<<"q="<<q<<endl;
	n=p*q;
	N=(p-1)*(q-1);
	while(e<=1||e>=N||z!=1)
	{
		//cout<<"请输入e:";
		//cin>>e;
		e=SuiJi(N);
		z=HuZhi(e,N);
	}
	cout<<"e="<<e<<endl;
	d=MiYaoNi(e,N);
    cout<<"d="<<d<<endl;
	while(1)
	{
	    x=0;
		cout<<"请选择："<<endl;
		cout<<"1.加密"<<endl;
		cout<<"2.解密"<<endl;
		cin>>x;
		switch(x)
		{
        case 1:
		    do
            {
                cout<<"请输入明文：";
			    cin>>M;
            }while(M>=n);
			C=Mi(M,e,n);
			cout<<"密文为："<<C<<endl;
			break;
		case 2:
			cout<<"请输入密文：";
			cin>>C;
			M=Mi(C,d,n);
			cout<<"明文为："<<M<<endl;
			break;
		}
	}

}
