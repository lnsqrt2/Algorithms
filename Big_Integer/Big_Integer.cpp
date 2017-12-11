#include <iostream>
#include <string>
#include <cstring>  
#include <vector> 
#include <algorithm>

using namespace std;
string ss(10000, '0');

string add(string s1, string s2)//加法
{
	string s(10000, '0');
	reverse(s1.begin(),s1.end());  
    reverse(s2.begin(),s2.end());  
    for(int j=0;j<s1.length();j++)  
    s[j]=s1[j];  
    int temp=0;  
    for(int k=0;k<s2.length();k++)  
    {  
        temp+=s[k]-48+s2[k]-48;
        s[k]=temp%10+'0';  
        temp/=10;          
    }  
    s[s2.length()]=s[s2.length()]-48+temp+48;   
    reverse(s.begin(),s.end());  
    reverse(s1.begin(),s1.end());  
    reverse(s2.begin(),s2.end());
	return s;
}

int strComp(string &s1, string &s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1>len2)
		return 0;
	else if (len1<len2)
		return 1;
	else {
		if (s1 >= s2)
			return 0;
		else
			return 1;
	}
}

string sub(string s1, string s2)
{
	string s(10000, '0');
	bool fgEx = true;
	if (strComp(s1, s2) == 1)
	{
		string temp;
		temp = s1;
		s1 = s2;
		s2 = temp;
		fgEx = false;
	}
	if (s1 == s2)
	{
		return 0;
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	for (int i = 0; i<s1.length(); i++)
		s[i] = s1[i];
	for (int i = 0; i<s2.length(); i++)
	{
		if (s[i] >= s2[i])
			s[i] = s[i] - '0' - (s2[i] - '0') + '0';
		else {
			s[i + 1] = s[i + 1] - '0' - 1 + '0';
			s[i] = s[i] - '0' + 10 - (s2[i] - '0') + '0';
		}
	}
	if (fgEx == false)
	{
		reverse(s.begin(), s.end());
		return s;
	}
	else
	{
		reverse(s.begin(), s.end());
		return s;
	}
}

string mul(string s1, string s2)
{
	string s(1000, '0');
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	for (int i = 0; i<s1.length(); i++)
		for (int j = 0; j<s2.length(); j++)
		{
			int temp = (s1[i] - '0')*(s2[j] - '0');
			s[i + j + 1] = s[i + j + 1] - '0' + (s[i + j] - '0' + temp) / 10 + '0';
			s[i + j] = (s[i + j] - '0' + temp) % 10 + '0';
		}
	reverse(s.begin(), s.end());
	if (s.find_first_not_of('0') == string::npos)
		return ss;
	else
		return s;
}

int main(void)
{
    string s1,s2;
    cin>>s1>>s2;
	if (s1[0] != '-'&&s2[0] != '-')
	{
		cout << "加法结果 " << (add(s1, s2)).substr((add(s1, s2)).find_first_not_of('0')) << endl;
		cout << "减法结果 " << (sub(s1, s2)).substr((sub(s1, s2)).find_first_not_of('0')) << endl;
		cout << "乘法结果 " << (mul(s1, s2)).substr((mul(s1, s2)).find_first_not_of('0')) << endl;
	}
	if (s1[0] == '-'&&s2[0] != '-')
	{
		s1.erase(0, 1);
		cout << "加法结果 " << (add(s1, s2)).substr((add(s1, s2)).find_first_not_of('0')) << endl;
		cout << "减法结果 " << (sub(s1, s2)).substr((sub(s1, s2)).find_first_not_of('0')) << endl;
		cout << "乘法结果 " << (mul(s1, s2)).substr((mul(s1, s2)).find_first_not_of('0')) << endl;
	}
	if (s1[0] != '-'&&s2[0] == '-')
	{
		s2.erase(0, 1);
		cout << "加法结果 " << (add(s1, s2)).substr((add(s1, s2)).find_first_not_of('0')) << endl;
		cout << "减法结果 " << (sub(s1, s2)).substr((sub(s1, s2)).find_first_not_of('0')) << endl;
		cout << "乘法结果 " << (mul(s1, s2)).substr((mul(s1, s2)).find_first_not_of('0')) << endl;
	}
	if (s1[0] == '-'&&s2[0] == '-')
	{
		s1.erase(0, 1);
		s2.erase(0, 1);
	}
	
    return 0; 
}