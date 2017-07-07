#include<iostream>
#include<string.h>
using namespace std;

void main()
{
		char s[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<strlen(s);j++)
			{
				char t=s[j];
				if(t+i>90)
				{
					t=t+i-26;
				}
				else
				{
					t=t+i;
				}
				t=t+32;
				cout<<t;
			}
		    cout<<endl;
		}
}	

