#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10000

using namespace std;

string s(MAX, '0');//save the results
bool flag = false;//exchange s1 and s2

void exchange(string &s1, string &s2)//s1 is longer than s2
{
	if (s1.length()<s2.length())
 	{
 		string temp;
 		temp = s1;
		s1 = s2;
		s2 = temp;
		flag = true;
 	}
 	if (s1.length()==s2.length())//
 	{
 		string temp;
 		temp = s1;
		s1 = s2;
		s2 = temp;
		flag = true;
 	}
 	return;
}

void add(string s1, string s2)//s1+s2
{
	int carry = 0;
	s.resize(MAX,'0');//resize
	s.assign(MAX,'0');//assign s
	exchange(s1, s2);//confirm s1 is longer
	reverse(s1.begin(),s1.end());//make the first char(s[0]) unit's digit
	reverse(s2.begin(),s2.end());
	for(int i=0;i<s1.length();i++)//s1.length()>=s2.length()
	{
		if(i<s2.length())
		{
			carry=s1[i]-'0'+s2[i]-'0'+carry;//two addends and one from low carry
			if(carry>9)
			{
				s[i]=carry%10+'0';
				carry = carry/10;
			}
			else
			{
				s[i]=carry+'0';
				carry = 0;
			}
		}
		else
			s[i]=s1[i];
	}
	s[s2.length()]=s[s2.length()]+carry;
	reverse(s.begin(),s.end());
	return;
}

void sub(string s1, string s2)//s1-s2
{
	int i,j;
	int carry = 0;
	s.resize(MAX,'0');//resize s
	s.assign(MAX,'0');//assign s
	exchange(s1, s2);//confirm s1 is longer
	if(s1 == s2)//result equals 0
	{
		s.resize(1,'0');//resize s
		s.assign(1,'0');//assign s
		return;
	}
	else
	{
		reverse(s1.begin(), s1.end());//make the first char(s[0]) unit's digit
		reverse(s2.begin(), s2.end());
		for (int i = 0; i < s1.length(); i++)//s1.length()>=s2.length()
		{
			if(i<s2.length())
			{
				if (s1[i] >= s2[i])
					s[i] = s1[i] - s2[i] + '0';
				else
				{
					s[i + 1] = s[i + 1]- 1;
	 				s[i] = s[i] + 10 - s2[i]  + '0';
				}
			}
			else
				s[i]=s1[i];
		}
	}
	reverse(s.begin(), s.end());
	return;
}



// string sub(string s1, string s2)
// {
// 	string s(10000, '0');
// 	bool fgEx = true;
// 	if (strComp(s1, s2) == 1)
// 	{
// 		string temp;
// 		temp = s1;
// 		s1 = s2;
// 		s2 = temp;
// 		fgEx = false;
// 	}
// 	if (s1 == s2)
// 	{
// 		return 0;
// 	}
// 	reverse(s1.begin(), s1.end());
// 	reverse(s2.begin(), s2.end());
// 	for (int i = 0; i<s1.length(); i++)
// 		s[i] = s1[i];
// 	for (int i = 0; i<s2.length(); i++)
// 	{
// 		if (s[i] >= s2[i])
// 			s[i] = s[i] - '0' - (s2[i] - '0') + '0';
// 		else {
// 			s[i + 1] = s[i + 1] - '0' - 1 + '0';
// 			s[i] = s[i] - '0' + 10 - (s2[i] - '0') + '0';
// 		}
// 	}
// 	if (fgEx == false)
// 	{
// 		reverse(s.begin(), s.end());
// 		return s;
// 	}
// 	else
// 	{
// 		reverse(s.begin(), s.end());
// 		return s;
// 	}
// }
// int strComp(string &s1, string &s2)
// {
// 	int len1 = s1.length();
// 	int len2 = s2.length();
// 	if (len1>len2)
// 		return 0;
// 	else if (len1<len2)
// 		return 1;
// 	else {
// 		if (s1 >= s2)
// 			return 0;
// 		else
// 			return 1;
// 	}
// }
// string mul(string s1, string s2)
// {
// 	string s(1000, '0');
// 	reverse(s1.begin(), s1.end());
// 	reverse(s2.begin(), s2.end());
// 	for (int i = 0; i<s1.length(); i++)
// 		for (int j = 0; j<s2.length(); j++)
// 		{
// 			int temp = (s1[i] - '0')*(s2[j] - '0');
// 			s[i + j + 1] = s[i + j + 1] - '0' + (s[i + j] - '0' + temp) / 10 + '0';
// 			s[i + j] = (s[i + j] - '0' + temp) % 10 + '0';
// 		}
// 	reverse(s.begin(), s.end());
// 	if (s.find_first_not_of('0') == string::npos)
// 		return ss;
// 	else
// 		return s;
// }

int main(void)
{
    string s1,s2;
    cout << "Please input the first integer: " ;
    cin>>s1;
    cout << "Please input the second integer: " ;
    cin>>s2;

	if (s1[0] != '-'&&s2[0] != '-')//both are positive integers
	{
		add(s1, s2);
		cout << "Addition result: " << s.substr(s.find_first_not_of('0')) << endl;
		sub(s1, s2);
		if(s.size()==1)
			cout << "Subtraction results: " << "0" << endl;
		else
			cout << "Subtraction results: " << s.substr(s.find_first_not_of('0')) << endl;
		// cout << "Multiplication result: " << (mul(s1, s2)).substr((mul(s1, s2)).find_first_not_of('0')) << endl;
	}
	if (s1[0] == '-'&&s2[0] != '-')//s1 is negative
	{
		s1.erase(0, 1);
		//cout << "Addition result: " << (add(s1, s2)).substr((add(s1, s2)).find_first_not_of('0')) << endl;
		// cout << "?????? " << (sub(s1, s2)).substr((sub(s1, s2)).find_first_not_of('0')) << endl;
		// cout << "?˷??? " << (mul(s1, s2)).substr((mul(s1, s2)).find_first_not_of('0')) << endl;
	}
	if (s1[0] != '-'&&s2[0] == '-')//s2 is negative
	{
		s2.erase(0, 1);
		//cout << "Addition result: " << (add(s1, s2)).substr((add(s1, s2)).find_first_not_of('0')) << endl;
		// cout << "?????? " << (sub(s1, s2)).substr((sub(s1, s2)).find_first_not_of('0')) << endl;
		// cout << "?˷??? " << (mul(s1, s2)).substr((mul(s1, s2)).find_first_not_of('0')) << endl;
	}
	if (s1[0] == '-'&&s2[0] == '-')//both are negative integers
	{
		s1.erase(0, 1);
		s2.erase(0, 1);
	}
    return 0; 
}