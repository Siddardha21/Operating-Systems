#include<iostream>
using namespace std;

int pid, allocation[10][3], need[10][3], Max[10][3], available[10][3], current[3];
bool executed[10],value;
void evaluate();
void check();
int main () {

	cout<<"Enter the number of processes: ";
	cin>>pid;
	cout<<"\n";
	cout<<"Enter the number of instances of resources: ";
	cin>>current[0]>>current[1]>>current[2];
	for (int i = 0; i < pid; ++i)
	{
		cout<<"\n\nFor Process P"<<i+1<<" \n";
		cout<<"Enter the current Allocation : ";
		cin>>allocation[i][0]>>allocation[i][1]>>allocation[i][2];
		cout<<"Enter the Max demand of Resource :";
		cin>>Max[i][0]>>Max[i][1]>>Max[i][2];
		need[i][0]=Max[i][0]-allocation[i][0];need[i][1]=Max[i][1]-allocation[i][1];need[i][2]=Max[i][2]-allocation[i][2];
	}

	cout<<"Initial Resources: "<<current[0]<<" "<<current[1]<<" "<<current[2]<<"\n\n";
	cout<<"PId      Allocation   Max       Need\n";
	for (int i = 0; i < pid; ++i)
	{
		cout<<"  P"<<i+1<<"    ";
		cout<<" "<<allocation[i][0]<<" "<<allocation[i][1]<<" "<<allocation[i][2]<<"     ";
		cout<<"  "<<Max[i][0]<<" "<<Max[i][1]<<" "<<Max[i][2]<<"     ";
		cout<<" "<<need[i][0]<<" "<<need[i][1]<<" "<<need[i][2];
		cout<<"\n";
	}
	cout<<"\n\n";
	evaluate();
	int optionloop=1;
	while(optionloop){
		int val,pro;
		cout<<"\n\nWould you like to modify anything?:\n\n";
		cout<<"1. Change the Initial Resources\n";
		cout<<"2. Exit\n\n";
		cin>>val;
		if (val==1)
		{
			cout<<"\nRe-Enter the Resources: ";
			cin>>current[0]>>current[1]>>current[2];
		}
		else{
			break;
		}
		evaluate();
	}

	return 0;
}

void evaluate(){
	check();
	int i,j;
	for (i = 0; i < pid; ++i)
	{
		for (j = 0; j < pid; ++j)
		{
			while(executed[j] && j<pid-1){
				j++;
			}
			if (need[j][0]<=current[0]&&need[j][1]<=current[1]&&need[j][2]<=current[2])
			{
				if (!executed[j])
				{
					executed[j]=true;
					current[0]+=allocation[j][0];current[1]+=allocation[j][1];current[2]+=allocation[j][2];
					//cout<<"\nProcess P"<<j+1;
					//cout<<"\nAvailable: "<<current[0]<<" "<<current[1]<<" "<<current[2]<<"\n";

					cout<<"\n\n";

					value=true;
					break;
				}
			}
		}
		if (!value)
		{
			cout<<"\nWarning! The process has exceeded its maximum claim.\n\n";
			break;
		} else {
			value=false;
		}
	}
}

void check(){
	value=false;
	for (int i = 0; i < 10; ++i)
	{
		executed[i]=false;
	}
}
