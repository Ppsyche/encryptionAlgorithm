#include<iostream>
#include<string.h>
using namespace std;

char JiaMiDan(int miyao1,int miyao2,char ming)
{
	int shu=ming-65;
	shu*=miyao1;
	shu+=miyao2;
	shu%=26;
	shu+=65;
	char miwen=shu;
	return miwen;
}

void JiaMi()
{
	int miyao1,miyao2,mingchang;
	char mingwen[20],miwen[20];
	cout<<"请输入密钥:";
	cin>>miyao1>>miyao2;
	cout<<"请输入明文(大写字母):";
	cin>>mingwen;
	mingchang=strlen(mingwen);
	cout<<"密文为：";
	for(int i=0;i<mingchang;i++)
	{
		miwen[i]=JiaMiDan(miyao1,miyao2,mingwen[i]);
		cout<<miwen[i];
	}
	cout<<endl<<endl;
}

int MiYaoNi(int a)
{
	int i,j;
	int q[50],c[50],b[50];
	q[0]=26/a;
	c[0]=26%a;
	q[1]=a/c[0];
	c[1]=a%c[0];
	for(i=2;i<50;i++)
	{
		q[i]=c[i-2]/c[i-1];
		c[i]=c[i-2]%c[i-1];
		if(c[i]==1)
			break;
	}
	b[0]=0;
	b[1]=1;
	for(j=0;j<=i;j++)
	{
		b[j+2]=(-1)*b[j+1];
		b[j+2]*=q[j];
		b[j+2]+=b[j];
	}
/*	for(j=0;j<=i;j++)
	{
		cout<<"q"<<j<<":"<<q[j]<<endl;
		cout<<"c"<<j<<":"<<c[j]<<endl;
		cout<<"b"<<j<<":"<<b[j]<<endl;
	}
	cout<<"b"<<j<<":"<<b[j]<<endl;*/
	if(b[j+1]<0)
		b[j+1]=26+b[j+1];
	return b[j+1];
}

char JieMiDan(int miyaoni,int miyao2,char mi)
{
	int shu=mi-65;
	shu-=miyao2;
	shu*=miyaoni;
	shu%=26;
	if(shu<0)
		shu+=26;
	shu+=65;
	char mingwen=shu;
	return mingwen;
}

void JieMi()
{
	int miyao1,miyao2,miyaoni,michang;
	char mingwen[20],miwen[20];
	cout<<"请输入密钥:";
	cin>>miyao1>>miyao2;
	cout<<"请输入密文(大写字母):";
	cin>>miwen;
	michang=strlen(miwen);
	miyaoni=MiYaoNi(miyao1);
	cout<<"明文为：";
	for(int i=0;i<michang;i++)
	{
		mingwen[i]=JieMiDan(miyaoni,miyao2,miwen[i]);
		cout<<mingwen[i];
	}
	cout<<endl<<endl;



}

main()
{
	int xuan;
	while(1)
	{
		cout<<"请选择："<<endl;
		cout<<"1.加密"<<endl;
		cout<<"2.解密"<<endl;
		cin>>xuan;
		if(xuan==1)
		{
			JiaMi();
		}
		else if(xuan==2)
		{
			JieMi();
		}
	}
}