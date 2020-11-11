#include<bits/stdc++.h>
using namespace std;

int no_of_holes;
int no_of_requests;
int memory_holes[1000];
int memory_requests[1000];
int allocation[1000];

void First_Fit()
{
    int external_fragmentation = 0;
    int cnt = 0;

    for(int i=0;i<no_of_requests;i++)
    {
        int j;
        for(j=0;j<no_of_holes;j++)
        {
            if(memory_requests[i]<=memory_holes[j])
            {
                allocation[i]=j;
                memory_holes[j] -= memory_requests[i];

                break;
            }

        }
        if(j == no_of_holes){
           cnt++;
           break;
        }

    }



    cout<<endl;
    cout<<"First fit memory allocation:"<<endl;
    cout<<endl;

    if(cnt > 0){
        for(int i=0; i < no_of_holes; i++)
        {
            external_fragmentation += memory_holes[i];
        }
        cout<<"External Fragmentation: "<<external_fragmentation<<endl;
    }

    else{
        cout<<"No External Fragmentation. "<<endl;
    }

    cout<<endl;
    cout<<"Request No.     "<<"Request Size     "<<"Allocated Block"<<endl;

    for(int i=0;i<no_of_requests;i++)
    {
        if(allocation[i] >= 0)
            cout<<i+1<<"\t\t"<<memory_requests[i]<<"\t\t\t"<<allocation[i]+1<<endl;
        else
            cout<<i+1<<"\t\t"<<memory_requests[i]<<"\t\t"<<" No Allocation"<<endl;
    }
    cout<<endl;
}



int main()
{

    cout<<"Number of Memory Holes: ";
    cin>>no_of_holes;

    cout<<endl;

    cout<<"Memory holes: "<<endl;
    for(int i=0; i<no_of_holes; i++)
    {
        cin>>memory_holes[i];
    }

    cout<<endl;

    cout<<"Number of Requests: ";
    cin>>no_of_requests;

    cout<<endl;

    cout<<"Memory Requests: "<<endl;
    for(int i=0; i<no_of_requests; i++)
    {
        cin>>memory_requests[i];
        allocation[i] = -1;
    }

    First_Fit();
}
