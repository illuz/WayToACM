#include <cstdio>  
#include <cstring>  
#include <string>  
#include <iostream>  
#include <map>  
using namespace std;  
map<string, string>m;  
int main()  
{  
	string s, ss;  
	cin >> s;  
	while(cin >> s)  
	{  
		if(s == "END")  
			break;  
		cin >> ss;  
		m[ss] = s;  
	}  
	cin >> s;  
	char tt[3017];  
	getchar();  
	while(gets(tt))  
	{  
		if(!strcmp(tt,"END"))  
			break;  
		ss="";  
		int len = strlen(tt);  
		for(int i = 0; i < len; i++)  
		{  
			if(!(tt[i]>='a'&&tt[i]<='z'))  
			{  
				if(m[ss]=="")  
					cout<<ss;  
				else  
					cout<<m[ss];  
				ss = "";  
				cout<<tt[i];  
			}  
			else  
				ss+=tt[i];  
		}  
		cout<<endl;  
	}  
	return 0;  
}  
