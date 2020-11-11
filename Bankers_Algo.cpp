#include<bits/stdc++.h>
using namespace std;

int allocation[100][10],need[100][10],Max[100][10],available[10];
int no_of_process,no_of_resource;
int resources[10];
int current[10];
int check;
bool executed[100],no_deadlock;



void Initial(){
	no_deadlock=false;
	for (int i = 0; i < no_of_process; ++i)
	{
		executed[i]=false;
	}
}

void Bankers_Algorithm(){
	Initial();
	int j;
	for (int i = 0; i < no_of_process; i++)
	{

		for (j = 0; j < no_of_process; j++)
		{
			while(executed[j] && j<no_of_process-1){
				j++;
			}

			check = 1;

			for(int k = 0; k < no_of_resource; k++)
            {
                if(need[j][k] > current[k]){
                    check = 0;
                    break;
                }

            }

            if (check == 1)
            {
                if (!executed[j])
                {
                    executed[j]=true;

                    for(int k=0; k < no_of_resource; k++){
                        current[k]+=allocation[j][k];
                    }
                    cout<<"Process P"<<j+1<<"  ";

                    no_deadlock=true;
                    break;

                    }
                }

		}
		if (!no_deadlock)
		{
			cout<<endl;
			cout<<"Dead lock occurred";
			break;
		}else{
			no_deadlock=false;
		}
	}
	cout<<endl<<endl;
}



int main (){

	cout<<"Enter the no. of processes: ";
	cin>>no_of_process;

	cout<<"Enter the no. of resources: ";
	cin>>no_of_resource;

	cout<<"Enter total value of resources:"<<endl;
	for(int i=0; i<no_of_resource; i++)
    {
        cout<<"resource "<<i+1<<": ";
        cin>>resources[i];

    }
    cout<<endl;
	for (int i = 0; i < no_of_process; i++)
	{

	    cout<<"Process "<<i+1<<endl;
		cout<<"Enter maximum value for each resource :"<<endl;
		for(int j = 0; j < no_of_resource; j++)
        {
            cin>>Max[i][j];
        }

		cout<<"Enter Allocation from each resource : "<<endl;;
		for(int j = 0; j < no_of_resource; j++)
        {
            cin>>allocation[i][j];
            available[j] += allocation[i][j];

        }

        cout<<"Need: ";
        for(int j = 0; j < no_of_resource; j++)
        {
            need[i][j]=Max[i][j]-allocation[i][j];
            cout<<"  "<<need[i][j]<<"  ";
        }
        cout<<endl<<endl;

	}

	cout<<"Initial Resources: ";
	for(int i=0; i<no_of_resource;i++){
        current[i]=resources[i]-available[i];
        cout<<"  "<<current[i]<<"  ";
	}

    cout<<endl<<endl;
	Bankers_Algorithm();

	return 0;
}

