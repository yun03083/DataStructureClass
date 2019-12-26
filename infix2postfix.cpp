#include<iostream>
#include <fstream>
#include "mystack.h"


using namespace std;

/*
������ �켱����
1: ���̳ʽ�, !
2: *, /, %
3: +, -
(: 8 (isp priority)
*/
int prec(char c)
{
    if(c == '!')
        return 1;
    else if(c == '*' || c == '/'|| c=='%')
        return 2;
    else if(c == '+' || c == '-')
        return 3;
    else if(c == '(')
        return 8;
    else
        return 9;

}


/*
����ǥ����� ����ǥ������� �ٲٴ� �Լ�
*/
string infix2Postfix(string s)
{
    Stack<char> *st=new Stack<char>;

    st->push('$');

    int l = s.length();
    string postfix_str;

    for(int i = 0; i < l; i++)
    {
        // �۷��� �ǿ�����(operand)�̸� �ٷ� ����Ѵ�.
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
            postfix_str+=s[i];

        // �Է��� '(' ���� ��ȣ�̸� ���ÿ� �ִ´�.
        else if(s[i] == '(')
            st->push('(');

        // �Է¹��ڰ� ')'������ ��ȣ�̸� ���þ��� �����ڸ� ���ʰ�ȣ�� ���� �� ���� ����Ѵ�.
        else if(s[i] == ')')
        {
            while(st->top() != '$' && st->top() != '(')
            {
                char c = st->top();
                st->pop();
                postfix_str += c;
            }
            if(st->top() == '(')
            {
                char c = st->top();
                st->pop();
            }
        }

        //�ӷ��� ������(operator)�̸�
        else{
            //������ �켱 ������ ���Ͽ� �Է� ������ �켱������ ������ ������ ���ÿ� ����.
            // �Է� ������ �켱������ ������ ���þ��� ������ ����� �Է� ������ ����.
            ////////////////////////////////////////////////////
            if(prec(st->top()) > prec(s[i]))
            {
				int t = prec(s[i - 1]);
            	st->push(s[i]);
			}
			else
			{
				char c = st->top();
				st->pop();
				postfix_str += c;
				st->push(s[i]);
				
			}
            ////////////////////////////////////////////////////

        }

    }
    //�Է� ������ ������ ���� ���� ��� ������ �����
    while(st->top() != '$')
    {
        char c = st->top();
        st->pop();
        postfix_str += c;
    }

    //cout << postfix_str << endl;
    return postfix_str;

}

int main()
{
    ifstream infile("input1.txt");

    string infix_str;
    getline(infile, infix_str);

    string postfix_str = infix2Postfix(infix_str);

    cout << "infix : " << infix_str <<endl;
    cout << "postfix : "<<postfix_str<<endl;
    return 0;
}

