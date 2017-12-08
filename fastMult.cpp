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
	int i=0;
	while(i<a.length()&&a[i]=='0') i++;
	if (i==a.length())i--;
	a=a.substr(i,a.length()-i);
	
	i=0;
	while(i<b.length()&&b[i]=='0') i++;
	if (i==b.length()) i--;
	b=b.substr(i,b.length()-i);
	
	if (a=="0") return b;
	if (b=="0") return a;
	//cout << a << ' ' << b << '\n';
	
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
    if (x!=y) {
    	string lencorrect="";
    	while(x<y) {
    		lencorrect+="0";
    		x++;
		}
		while(x>y) {
			lencorrect+="0";
			y++;
		}
		if (a.length()<b.length()) a=lencorrect+a;
		else b=lencorrect+b;
	}
    int n = x;
    if(n == 1)
    {
        int ans = (a[0]-48)*(b[0]-48);
        return to_string(ans);
    }
    else
    {
		string al=a.substr(0,x/2),ar=a.substr(x/2,x-x/2);
		string bl=b.substr(0,x/2),br=b.substr(x/2,x-x/2);
        string p1 = multiply(al,bl),p2 = multiply(ar,br),p3 = multiply(add(al,ar),add(bl,br));
        
        
        string t = subtract(p3,add(p1,p2));
        string tt;
        if (t[0]!='-') {
        	for(int i = 1;i<=n-n/2;i++)
            	t+="0";
        	tt= add(t,p2);
        }
        else {
        	t=subtract(add(p1,p2),p3);
        	for(int i = 1;i<=n/2;i++)
            	t+="0";
        	tt= subtract(p2,t);
		}
        for(int i = 1;i<=2*(n-n/2);i++)
            p1+="0";
        return add(tt,p1);
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

void display(string num) {
	int i=0;
	while(i<num.length()&&num[i]=='0') i++;
	if (i==num.length()) i--;
	cout << num.substr(i,num.length()-i);
}

int main()
{
	
	int n,a,b;
	cin >> n;
	while(n--) {
		cin >> a >> b;
		display(multiply(to_string(a),to_string(b)));
		cout << '\n';
	}
    return 0;
}
