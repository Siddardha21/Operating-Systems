#include<iostream>
#include<cmath>
using namespace std;

int a, pagenumber, pagesize, maxpages, PTBR, PTLR;
double b;

int main() {
    cout<<"\nEnter the starting address of the process. i.e. the value of PTBR: ";
    cin>>PTBR;
    cout<<"\nEnter the length/limit of the process in bytes. i.e. the value of PTLR: ";
    cin>>PTLR;
    cout<<"\nEnter the Page size in KB: ";
    cin>>pagesize;

    b = (double) PTLR/(pagesize*1024);
    maxpages = ceil(b); //returns the integer value that is bigger than or equal to a number.
    cout<<"\nEnter the page number to be accessed: ";
    cin>>pagenumber;

    if(pagenumber>0 && pagenumber<maxpages) {
        cout<<"\nV bit is set, It is a valid request\n";
    } else {
        cout<<"\nI bit is set, It is an invalid request\n";
    }

    return 0;
}