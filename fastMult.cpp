#include<bits/stdc++.h>

using namespace std;

//Program to multiply large numbers using divide and conquer

string add(string a,string b) //adding two numbers represented as strings
{
    int x = a.length(),y = b.length();
    if(x<y)
    {
        for(int i = 1;i<=y-x;i++)
            a = "0"+a;
    }
    else
    {
        for(int i = 1;i<=x-y;i++)
            b = "0"+b;
    }
    string sum = "";
    int carry = 0,s = max(x,y);
    for(int i = s-1;i>=0;i--)
    {
        int c = a[i]+b[i]-96+carry;
        carry = c>9?c/10:0;
        sum = (char)((c>9?c%10:c)+48) + sum;
    }
    if(carry>0)
        sum = (char)(carry+48) + sum;
    return sum;
}

string subtract(string a,string b)//subtracting two numbers represented as strings
{
    bool flag = false;
    if(a.length()<b.length())
    {
        flag = true;
        string t = a;
        a = b;
        b = t;
    }
    int n = a.length();
    for(int i = 1;i<=n-b.length();i++)
        b = '0'+b;
    for(int i = 0;i<n;i++)
        b[i] = 105-b[i];
    b = add(b,"1");
    string diff = add(a,b);
    if(flag)
        return "-"+diff.substr(1,diff.length()-1);
    else
        return diff.substr(1,diff.length()-1);
}

string multiply(string a,string b)//multiplying two numbers represented as strings
{
    int x = a.length(),y = b.length();
    int n = max(x,y);
    if(n == 1)
    {
        int ans = (a[0]-48)*(b[0]-48);
        return to_string(ans);
    }
    else
    {
        string al = a.substr(0,floor(a.length()/2)),ar = a.substr(floor(a.length()/2),ceil(a.length()/2));
        string bl = b.substr(0,floor(b.length()/2)),br = b.substr(floor(b.length()/2),ceil(b.length()/2));
        string p1 = multiply(al,bl),p2 = multiply(ar,br),p3 = multiply(add(al,ar),add(bl,br));
        for(int i = 1;i<=n;i++)
            p1+="0";
        string t = subtract(p3,add(p1,p2));
        for(int i = 1;i<=n/2;i++)
            t+="0";
        return add(p1,add(t,p2));
    }
}

string randomNumber(int a,int b)//a to b digit number
{
    string n = "";
    int d = rand()%(b-a+1)+a;
    for(int i = 1;i<=d;i++)
        n+=(char)(rand()%10+48);
    return n;
}

int main()
{
    cout<<subtract("100","34")<<endl<<subtract("34","100000")<<endl;
    cout<<multiply("2","6")<<endl;
    srand(time(nullptr));
    string a = randomNumber(10,20);
    string b = randomNumber(10,20);
    cout<<a<<endl<<b<<endl;
    cout<<add(a,b)<<endl;
    cout<<subtract(a,b)<<endl;
    cout<<multiply("9","3")<<endl;
    return 0;
}

