#include <iostream>
#include <cstring>
#include <map>
#include <math.h>
using namespace std;

map <int, string> m;

int main(void){
    // Your code here!
    string s;
    cin >> s;
    long n = 0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='X') {
            if(s[i+1]=='L' || s[i+1]=='C' || s[i+1]=='D' || s[i+1]=='M')
                n -= 10;
            else
                n += 10;
        }
        else if(s[i]=='V')
            n += 5;
        else if(s[i]=='L') {
            if(s[i+1]=='C' || s[i+1]=='D' || s[i+1]=='M')
                n -= 50;
            else
                n += 50;
        }
        else if(s[i]=='C') {
            if(s[i+1]=='D' || s[i+1]=='M')
                n -= 100;
            else
                n += 100;
        }
        else if(s[i]=='D') {
            if(s[i+1]=='M')
                n -= 500;
            else
                n += 500;
        }
        else if(s[i]=='M')
            n += 1000;
        else if(s[i]=='I') {
            if(s[i+1]=='X' || s[i+1]=='V')
                n -= 1;
            else
                n += 1;
        }
            
    }
    cout << n << endl;
//----------------------------------------------------------------------
    m[1]="I"; m[2]="II"; m[3]="III"; m[4]="IV"; m[5]="V"; m[6]="VI"; m[7]="VII"; m[8]="VIII"; m[9]="IX"; m[10]="X";
    m[20]="XX"; m[30]="XXX"; m[40]="XL"; m[50]="L"; m[60]="LX"; m[70]="LXX"; m[80]="LXXX"; m[90]="XC"; m[100]="C";
    m[200]="CC"; m[300]="CCC"; m[400]="CD"; m[500]="D"; m[600]="DC"; m[700]="DCC"; m[800]="DCCC"; m[900]="CM"; m[1000]="M";
    m[2000]="MM"; m[3000]="MMM";
//----------------------------------------------------------------------
    long x = n;
    int r = 0;
    int i = 0;
    int d = 0;
    string roman = "";
    while(x>0) {
        r = x%10;
        x = x/10;
        d = r*pow(10,i);
        if(d!=0)
            roman.insert(0,m[d]);
        i++;
    }
    
    cout << roman;
    
    return 0;
    
}
