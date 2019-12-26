#include<iostream>
#include <fstream>
#include "mystack.h"


using namespace std;

/*
연산자 우선순위
1: 마이너스, !
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
중위표기법을 후위표기법으로 바꾸는 함수
*/
string infix2Postfix(string s)
{
    Stack<char> *st=new Stack<char>;

    st->push('$');

    int l = s.length();
    string postfix_str;

    for(int i = 0; i < l; i++)
    {
        // 앱력이 피연산자(operand)이면 바로 출력한다.
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
            postfix_str+=s[i];

        // 입력이 '(' 왼쪽 괄호이면 스택에 넣는다.
        else if(s[i] == '(')
            st->push('(');

        // 입력문자가 ')'오른쪽 괄호이면 스택안의 연산자를 왼쪽괄호가 있을 때 까지 출력한다.
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

        //임력이 연산자(operator)이면
        else{
            //연산자 우선 순위를 비교하여 입력 연산자 우선순위가 우위에 있으면 스택에 저장.
            // 입력 연산자 우선순위가 낮으면 스택안의 연산자 출력후 입력 연산자 저장.
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
    //입력 수식이 끝나면 스택 안의 모든 연산자 출력함
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

