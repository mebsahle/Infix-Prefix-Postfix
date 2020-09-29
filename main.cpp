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
    case'%':
        return 2;
    case'^':
        return 3;
    }
}

Stack s1;

char ch;
char infix[100],postfix[100],prefix[100];

string in_to_post()
{
    int i=0,j=0,l,k;
    while(infix[i++]!='\0');//to get to the null character
    infix[i+1]='\0';//to shift
    infix[i--]=')';//at the end add closing bracket

    while(i>0)//traverse from right to left
    {
        infix[i]=infix[i-1];
        i--;
    }

    infix[i]='(';

//input fully parenthesized
    i=0;
    while(infix[i]!='\0')//scan infix of i char by char
    {
        if(infix[i]=='(')//step 1
        {
            s1.push(infix[i]);
        }
        else if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='0'&&infix[i]<='9'))//step 2
        {
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='%'||infix[i]=='^')//step 3
        {
            if(s1.tip()=='+'||s1.tip()=='-'||s1.tip()=='*'||s1.tip()=='/'||s1.tip()=='%'||s1.tip()=='^')
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
        else if(cho=="5")
            break;
        else
            cout<<"Enter Valid number\n";





    }


    return 0;
}
