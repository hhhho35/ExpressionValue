// ExpressionEvaluation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

char compare(char ch, char top);

int main()
{
	/*char s = '9';
	int i = s-48; 
	cout << i;*/
	char n = 'y';
	while (n == 'y')
	{
		cout << "������ʽ���� #�� ��β" << endl;
		stack<char> optr;
		optr.push('#');
		stack<double> opnu;
		int i = 0;
		char ch;
		double op;
		bool flag = false;
		cin >> ch;
		while (optr.top() != '#' || ch != '#')
		{
			if (flag == true)
			{
				flag = false;
				while (!opnu.empty())
					opnu.pop();
				break;
			}
			if (ch >= '0'&&ch <= '9')
			{
				cin.putback(ch);
				cin >> op;
				opnu.push(op);
				cin >> ch;
			}
			else
			{
				switch (compare(ch, optr.top()))
				{
				case '<':
				{
					double a, b, c;
					char c1 = optr.top();
					if (opnu.empty())
					{
						optr.push('#');
						cout << "���ʽ����û���㹻�Ĳ�����" << endl;
						flag = true;
						break; 
					}
					b = opnu.top();
					opnu.pop();
					if (opnu.empty())
					{
						optr.push('#');
						cout << "���ʽ����û���㹻�Ĳ�����" << endl;
						flag = true;
						break;
					}
					a = opnu.top();
					opnu.pop();
					optr.pop();
					switch (c1)
					{
					case '+':
						c = a + b;
						opnu.push(c);
						break;
					case '-':
						c = a - b;
						opnu.push(c);
						break;
					case '*':
						c = a * b;
						opnu.push(c);
						break;
					case '/':
						if (b == 0)
						{
							cout << "���ʽ���󣬳�������Ϊ0" << endl;
							flag = true;
							break;
						}
						c = a / b;
						opnu.push(c);
						break;
					}

					break;
				}
				case '>':
					optr.push(ch);
					cin >> ch;
					break;
				case '=':
					optr.pop();
					cin >> ch;
					break;
				default:
					optr.push('#');
					cout << "���ʽ�������Ų�ƥ��" << endl;
					cin.clear();
					flag = true;
					break;
				}
			}
		}
		if(!opnu.empty())
		    cout << "���ʽ��ֵΪ:" << opnu.top() << endl;
		
		cout << "������������ y �������������˳�" << endl;
		cin.clear();
		cin >> n;
		while (!optr.empty())
			optr.pop();
		optr.push('#');
	}
    return 0;
}


char compare(char ch, char top)
{
	switch (ch) {
	case '+':
	case '-':
		if (top == '+' || top == '-' || top == '*' || top == '/')
			return '<';  //ɨ���С��ջ��  
		else
			return '>';  //ɨ��Ĵ���ջ��  
		break;
	case '*':
	case '/':
		if (top == '*' || top == '/')
			return '<';
		else
			return '>';
		break;
	case '(':
		if (top == ')') {
			return '0';
		}
		return '>';
		break;
	case ')':
		if (top == '(')
			return '=';
		else if (top == '#') {
			return '0';
		}
		else {
			return '<';
		}
		break;
	case '#':
		return '<';
	default:
		return '0';
	}
}