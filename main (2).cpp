#include <bits/stdc++.h>
#include "Stack.h"
using namespace std;
//doubt
int findprecedence(char ch)
{
    switch (ch)
    {
    case'+':
    case'-':
        return 1;
    case'*':
    case'/':
        return 2;
    case'^':
        return 3;
    }
}

Stack s1;

char ch;
char infix[100],postfix[100],prefix[100],post[100],pre[100];

string in_to_post()
{
    int i=0,j=0;
    while(infix[i++]!='\0');
    infix[i+1]='\0';
    infix[i--]=')';

    while(i>0)
    {
        infix[i]=infix[i-1];
        i--;
    }

    infix[i]='(';


    i=0;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')//step 1
        {
            s1.push(infix[i]);
        }
        else if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='0'&&infix[i]<='9'))//step 2
        {
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')//step 3
        {
            if(s1.tip()=='+'||s1.tip()=='-'||s1.tip()=='*'||s1.tip()=='/'||s1.tip()=='^')
            {
                if(findprecedence(s1.tip())>=findprecedence(infix[i]) && s1.tip()!='^')
                {
                    postfix[j++]=s1.tip();
                    s1.pop();
                }

            }
            s1.push(infix[i]);
        }
        else if(infix[i]==')')//step 4
        {
            while(s1.tip()!='(')
            {

                postfix[j++]=s1.tip();
                s1.pop();
            }
            s1.pop();
        }
        i++;
    }
    postfix[j]='\0';
    return postfix;
}

int post_eval(char inf[])
{

     int i=0,x,a,b,c;
    // char post[100];
     Stack s1;
    while(post[i]!='\0')
    {
        if(post[i]>='0'&&post[i]<='9')
        {
            x=post[i]-48;
            s1.push(x);
        }
        else if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/')
        {
            a=s1.pop();
            b=s1.pop();
            switch(post[i])
            {
            case '+':
                c=b+a;
                s1.push(c);
                break;
            case '-':
                c=b-a;
                s1.push(c);
                break;
            case '*':
                c=b*a;
                s1.push(c);
                break;
            case '/':
                c=b/a;
                s1.push(c);
                break;
            }
        }
        i++;
    }
    post[i]='\0';
    return s1.pop();
}

int main()
{

    string cho;

    while(1)
    {
//        system("cls");
        cout<<"\n\n############################################################\n\n";
        cout<<"1 => Infix to postfix\n2 => Infix to prefix\n3 => Postfix to infix\n4 => Prefix to infix\n5 => Exit\n";
        cout<<"Enter your choice: ";
        cin>>cho;
         cout<<"\n\n############################################################\n\n";
        string in;
        if(cho == "1"){
            cout<<"Enter an expression: ";
            cin>>infix;
            cout<<"\n\n############################################################\n\n";
            cout << in_to_post() << endl;
        }
        else if(cho == "2"){
            cout<<"Enter an expression: ";
            cin>>infix;
            in = infix;
            reverse(in.begin(), in.end());
            for(int ii=0;ii<in.size(); ++ii) infix[ii] = in[ii];
            in =in_to_post();
            reverse(in.begin(), in.end());
            cout<<"\n\n############################################################\n\n";
            cout<<in<<endl;
        }
        else if(cho=="3")
        {
            cout<<"Enter postfix expression: ";
            cin>>post;
            cout<<post_eval(post)<<endl;
        }
        else if(cho=="4")
        {
            cout<<"Enter prefix expression: ";
            cin>>pre;
            in = infix;
            reverse(in.begin(), in.end());
            cout<<in<<endl;
            for(int p=0;p<in.size(); ++p) pre[p] = in[p];
            int ans=post_eval(pre);
            cout<<ans<<endl;
        }
        else if(cho=="5")
            break;
        else
            cout<<"Enter Valid number\n";

    }


    return 0;
}
