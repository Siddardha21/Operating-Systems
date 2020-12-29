#include<iostream>
#include<cmath>
using namespace std;

int number_of_users, code_space, data_space, with_shared_pages, without_sp;

int main() {
    cout<<"\n";
    cout<<"Enter the number of users: ";
    cin>>number_of_users;
    cout<<"\n";
    cout<<"Enter the code space of Reentrant code in Kilobytes: ";
    cin>>code_space;
    cout<<"\n";
    cout<<"Enter the data space of the Reentrant code in  Kilobytes: ";
    cin>>data_space;
    cout<<"\n";
    with_shared_pages=(number_of_users*data_space) + code_space;
    without_sp=number_of_users*(code_space+data_space);
    cout<<("\n");
    cout<<"Memory requirement with Shared Pages is "<<with_shared_pages<<" KB";
    cout<<("\n");
    cout<<"Memory requirement without shared Pages is "<<without_sp<<" KB";
    cout<<("\n\n");
    return 0;
}