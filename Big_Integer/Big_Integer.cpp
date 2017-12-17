#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
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
	exchange(s1, s2);//confirm s1 is larger
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
		for (i = 0; i < s1.length(); i++)
			s[i]=s1[i];
		for (i = 0; i < s2.length(); i++)//s1.length()>=s2.length()
		{
				if (s[i] >= s2[i])
					s[i] = s[i] - s2[i] + '0';
				else
				{
					for (j = i+1; j < s1.length()-1; j++)
					{
						if (s[j] <= '0')
						{
							s[j] = '9';
							s[j + 1] = s[j + 1] - 1;//brorrow
						}
					}
	 				s[i] = s[i] + 10 - s2[i]  + '0';
				}
		}
		reverse(s.begin(), s.end());
		if(flag==true)//have exchanged
			s.insert(s.find_first_not_of('0'), "-");
	}
	return;
}

// string mul(string s1, string s2)//s1*s2
// {
// 	String result = "";
//         if (a.length() == 1 || b.length() == 1)// 递归结束的条件
//             result = "" + Long.valueOf(a) * Long.valueOf(b);
//         else// 如果2个字符串的长度都 >= 2
//         {
//             //1.分割成  a1  a0  b1  b0
//             int lengthA0 = a.length() / 2;
//             int lengthA1=a.length()-lengthA0;
//             String a1 = a.substring(0, lengthA1); // 截取前一半的字符串(较短的一半)
//             String a0 = a.substring(lengthA1, a.length()); // 截取后一半的字符串

//             int lengthB0 = b.length() / 2;
//             int lengthB1=b.length()-lengthB0;
//             String b1 = b.substring(0, lengthB1);
//             String b0 = b.substring(lengthB1, b.length());
//             // * a*b=
//             // * (a1*b1)* 10^[(n1+n2)/2 ]
//             // * +(a1*b0)*10^(n1/2)
//             // * +(a0*b1)*10^(n2/2)
//             // * +(a0*b0)
//             //2.计算展开式中的乘法
//             String a1b1 = Mutiply1(a1, b1);
//             String a1b0 = Mutiply1(a1, b0);
//             String a0b1 = Mutiply1(a0, b1);
//             String a0b0 = Mutiply1(a0, b0);

//             //3.模拟移位
//             String resulta1b1 = a1b1;
//             for (int i = 0; i < lengthA0+lengthB0; i++) {
//                 resulta1b1 += "0";
//             }
//             String resulta1b0 = a1b0;
//             for (int i = 0; i <lengthA0; i++) {
//                 resulta1b0 += "0";
//             }
//             String resulta0b1 = a0b1;
//             for (int i = 0; i < lengthB0; i++) {
//                 resulta0b1 += "0";
//             }   
//             //4.大数相加
//             result = MyBigAdd.add(resulta1b1, resulta1b0);
//             result = MyBigAdd.add(result, resulta0b1);
//             result = MyBigAdd.add(result, a0b0);
//         }
//         return result;
// }

string mul(string s1, string s2)//s1*s2
{
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
		return s;
}




// string mul(string s1, string s2)//s1*s2
// {
// 	string result = "";
// 	// string ss(MAX, '0');
// 	 exchange(s1, s2);//confirm s1 is longer
// 	// int len = s1.length();
// 	// s1 = formatNumber(s1, len);
//  //    s2 = formatNumber(s2, len);

// 	if(s2.length()==1)//the end of recursion
// 	{
// 		reverse(s1.begin(), s1.end());
// 		reverse(s2.begin(), s2.end());
// 		for (int i = 0; i<s1.length(); i++)
// 			int temp = (s1[i] - '0')*(s2[0] - '0');
// 			s[i + 1] = s[i + 1] - '0' + (s[i] - '0' + temp) / 10 + '0';
// 			s[i ] = (s[i] - '0' + temp) % 10 + '0';
// 		reverse(s.begin(), s.end());
// 		return s;
// 	}
// 	else
// 	{
// 	// 	int len1 = len/2;
// 	// 	int len2 = len - len1;
// 	// 	int lenm = len1>len2?len1:len2;
// 	// 	String A = s1.substring(0, len1);
//  //        String B = s1.substring(len1);
//  //        String C = s2.substring(0, len1);
//  //        String D = s2.substring(len1);
//  //        String AC = mul(A, C);
//  //        String AD = mul(A, D);
//  //        String BC = mul(B, C);
//  //        String BD = mul(B, D);
// 	}
// 	// if (s.find_first_not_of('0') == string::npos)//until over
//  // 		return;
//  // 	else
// 	// 	return;
// 	//return result;
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

		mul(s1, s2);
		if(s.size()==1)
			cout << "Multiplication results: " << "0" << endl;
		else
			cout << "Multiplication results: " << s.substr(s.find_first_not_of('0')) << endl;
	}
	if (s1[0] == '-'&&s2[0] != '-')//s1 is negative
	{
		s1.erase(0, 1);
		sub(s2, s1);
		if (s.size() == 1)
			cout << "Addition results: " << "0" << endl;
		else
			cout << "Addition results: " << s.substr(s.find_first_not_of('0')) << endl;
		add(s1, s2);
		s.insert(s.find_first_not_of('0'), "-");
		cout << "Subtraction results: " << s.substr(s.find_first_not_of('0')) << endl;

		mul(s1, s2);
		if(s.size()==1)
			cout << "Multiplication results: " << "0" << endl;
		else
		{
			s.insert(s.find_first_not_of('0'), "-");
			cout << "Multiplication results: " << s.substr(s.find_first_not_of('0')) << endl;
		}
	}
	if (s1[0] != '-'&&s2[0] == '-')//s2 is negative
	{
		s2.erase(0, 1);
		sub(s1, s2);
		if (s.size() == 1)
			cout << "Addition results: " << "0" << endl;
		else
			cout << "Addition results: " << s.substr(s.find_first_not_of('0')) << endl;
		add(s1, s2);
		cout << "Subtraction results: " << s.substr(s.find_first_not_of('0')) << endl;

		mul(s1, s2);
		if(s.size()==1)
			cout << "Multiplication results: " << "0" << endl;
		else
		{
			s.insert(s.find_first_not_of('0'), "-");
			cout << "Multiplication results: " << s.substr(s.find_first_not_of('0')) << endl;
		}
	}
	if (s1[0] == '-'&&s2[0] == '-')//both are negative integers
	{
		s1.erase(0, 1);
		s2.erase(0, 1);
		add(s1, s2);
		s.insert(s.find_first_not_of('0'), "-");
		cout << "Addition results: " << s.substr(s.find_first_not_of('0')) << endl;
		sub(s2, s1);
		if (s.size() == 1)
			cout << "Subtraction results: " << "0" << endl;
		else
			cout << "Subtraction results: " << s.substr(s.find_first_not_of('0')) << endl;

		mul(s1, s2);
		if(s.size()==1)
			cout << "Multiplication results: " << "0" << endl;
		else
			cout << "Multiplication results: " << s.substr(s.find_first_not_of('0')) << endl;
	}
    return 0; 
}