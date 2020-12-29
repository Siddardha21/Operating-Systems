#include<iostream>
#include<cmath>
using namespace std;

int a, pagenumber, pages, pagesize, logicalmemory, logicaladd, offset, address, framenum[20];

int main() {
    cout<<"\nEnter the size of Logical Memory in Bytes: ";
    cin>>logicalmemory;
    cout<<"\nEnter the page size in Bytes: ";
    cin>>pagesize;
    pages=logicalmemory/pagesize;

    for(a=0;a<pages;a++) {
        cout<<"\nEnter the Frame number corresponding to Page "<<a<<": ";
        cin>>framenum[a];
    }
    cout<<"\n";
    cout<<"-------PAGE TABLE-------\n";
    cout<<"\nPage No \tFrame No\n";
    for(a=0;a<pages;a++) {
        cout<<" "<<a<<"\t\t"<<framenum[a];
        cout<<"\n";
    }
           
    cout<<"\n\nEnter the Logical Address: ";
    cin>>logicaladd;
    pagenumber=logicaladd/pagesize;
    offset=logicaladd%pagesize;
    address=framenum[pagenumber]*pagesize+offset;
    cout<<"\nPage no = "<<pagenumber<<"\tOffset = "<<offset<<"\tPhysical Address = "<<address;
    cout<<"\n";
  
}