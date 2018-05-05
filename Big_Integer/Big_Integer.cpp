#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 10000

using namespace std;

string s(MAX, '0');//save the results
bool flag = false;//exchange s1 and s2

void exchange(string &s1, string &s2)//s1 is larger than s2
{
	flag = false;//initial
	if (s1.length()<s2.length())
 	{
 		string temp;
 		temp = s1;
		s1 = s2;
		s2 = temp;
		flag = true;
 	}
 	if (s1.length()==s2.length())
 	{
		if (s1 < s2)
		{
			string temp;
			temp = s1;
			s1 = s2;
			s2 = temp;
			flag = true;
		}
 	}
 	return;
}

string add(string s1, string s2)//s1+s2 99+1
{
	string result;
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
	if (s[s2.length()] == '9')
	{
		for (int j = s2.length(); j <=s1.length(); j++)
		{
			if (s[j] >= '9')
			{
				s[j] = '0';
				s[j + 1] = s[j + 1] + carry;
			}
		}
	}
	else
		s[s2.length()]=s[s2.length()]+carry;
	reverse(s.begin(),s.end());
	result = s.substr(s.find_first_not_of('0'));
	return result;
}

string sub(string s1, string s2)//s1-s2
{
	int i,j;
	//int carry = 0;
	string result;
	s.resize(MAX,'0');//resize s
	s.assign(MAX,'0');//assign s
	exchange(s1, s2);//confirm s1 is larger
	if(s1 == s2)//result equals 0
	{
		s.resize(1,'0');//resize s
		s.assign(1,'0');//assign s
		return s;
	}
	else
	{
		reverse(s1.begin(), s1.end());//make the first char(s[0]) unit's digit
		reverse(s2.begin(), s2.end());
		for (i = 0; i < s1.length(); i++)
			s[i]=s1[i];
		for (i = 0; i < s2.length(); i++)//s1.length()>=s2.length()
		{
				if (s[i] >= s2[i])
					s[i] = s[i] - s2[i] + '0';
				else
				{
					if(s[i+1]=='0')
						for (j = i+1; j < s1.length()-1; j++)
						{
							if (s[j] <= '0')
							{
								s[j] = '9';
								s[j + 1] = s[j + 1] - 1;//brorrow
							}
						}
					else
						s[i + 1] = s[i + 1] - 1;//brorrow
	 				s[i] = s[i] + 10 - s2[i]  + '0';
				}
		}
		reverse(s.begin(), s.end());
		if(flag==true)//have exchanged
			s.insert(s.find_first_not_of('0'), "-");
	}
	result = s.substr(s.find_first_not_of('0'));
	return result;
}

string caculate(string s1, string s2)//s1*s2
{
	string result;
	s.resize(MAX, '0');//resize
	s.assign(MAX, '0');//assign s
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
	if (s.find_first_not_of('0') == string::npos)//until over
	{
		s.resize(1,'0');//resize s
		s.assign(1,'0');//assign s
		return s;
	}
	else
	{
		result = s.substr(s.find_first_not_of('0'));
		return result;
	}
}

string mul(string s1, string s2)//s1*s2
{
	string result;
	exchange(s1, s2);//confirm s1 is longer
	//int len = s1.length();
	if (s1.find_first_not_of('0') == string::npos || s2.find_first_not_of('0') == string::npos)//if s1 or s2 = 0
	{
		//int len = s1.length() + s2.length();
		result.resize(1, '0');
		result.assign(1, '0');
		return result;
	}
	if(s1.length()==1||s2.length()==1)//the end of recursion
	{
		result = caculate(s1, s2);
		return result;
	}
	else
	{
		string A = s1.substr(0, s1.length() /2);
        string B = s1.substr(s1.length() /2);
        string C = s2.substr(0, s2.length() /2);
        string D = s2.substr(s2.length() /2);
        string AC = mul(A, C);
        string AD = mul(A, D);
        string BC = mul(B, C);
        string BD = mul(B, D);

        string RAC=AC;
        for(int i=0;i<(s1.length()-s1.length()/2+s2.length()-s2.length()/2);i++)
        {
        	RAC += "0";
        }
        string RAD=AD;
        for(int i=0;i<(s1.length() - s1.length()/2);i++)
        {
        	RAD += "0";
        }
        string RBC=BC;
        for(int i=0;i<(s2.length() - s2.length()/2);i++)
        {
        	RBC += "0";
        }
        result = add(RAC,RAD);
        result = add(result,RBC);
        result = add(result,BD);
	}
		return result;
}

int main(void)
{
    string s1,s2,result;
    cout << "Please input the first integer: " ;
    cin>>s1;
    cout << "Please input the second integer: " ;
    cin>>s2;

	if (s1[0] != '-'&&s2[0] != '-')//both are positive integers
	{
		result = add(s1, s2);
		cout << "Addition result: " << result << endl;
		result = sub(s1, s2);
		cout << "Subtraction results: " << result << endl;
		result = mul(s1, s2);
		cout << "Multiplication results: " << result << endl;
	}
	if (s1[0] == '-'&&s2[0] != '-')//s1 is negative
	{
		s1.erase(0, 1);
		result = sub(s2, s1);
		cout << "Addition results: " << result << endl;

		result = add(s1, s2);
		result.insert(result.find_first_not_of('0'), "-");
		cout << "Subtraction results: " << result << endl;

		result = mul(s1, s2);
		if(result.find_first_not_of('0') == string::npos)
			cout << "Multiplication results: " << "0" << endl;
		else
		{
			result.insert(result.find_first_not_of('0'), "-");
			cout << "Multiplication results: " << result << endl;
		}
	}
	if (s1[0] != '-'&&s2[0] == '-')//s2 is negative
	{
		s2.erase(0, 1);
		result = sub(s1, s2);
		cout << "Addition results: " << result << endl;

		result = add(s1, s2);
		cout << "Subtraction results: " << result << endl;

		result = mul(s1, s2);
		if (result.find_first_not_of('0') == string::npos)
			cout << "Multiplication results: " << "0" << endl;
		else
		{
			result.insert(result.find_first_not_of('0'), "-");
			cout << "Multiplication results: " << result << endl;
		}
	}
	if (s1[0] == '-'&&s2[0] == '-')//both are negative integers
	{
		s1.erase(0, 1);
		s2.erase(0, 1);
		result = add(s1, s2);
		result.insert(result.find_first_not_of('0'), "-");
		cout << "Addition results: " << result << endl;

		result = sub(s2, s1);
		cout << "Subtraction results: " << result << endl;

		result = mul(s1, s2);
		cout << "Multiplication results: " << result << endl;
	}
	system("pause");
	return 0; 
}