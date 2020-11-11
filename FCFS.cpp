#include <bits/stdc++.h>
using namespace std;


int n;
int no_of_heads;
int current_head;


void FCFS()
{

    int positions[no_of_heads];
    cout<<"Cylinder requests:"<<endl;

    for(int i=0; i<n; i++)
    {
        cin>>positions[i];
    }
    cout<<endl;
    int movement=0;

    cout<<"Cylinder Serving Order: "<<current_head;

    for(int i=0; i<n; i++)
    {
        cout<<"-->";

        movement += abs(current_head - positions[i]);
        current_head = positions[i];
        cout<<current_head;
    }

    cout<<endl<<endl;;
    cout<<"Total cylinder movement: "<<movement<<endl;
    return;
}

int main()
{


    cout<<"Number of heads: ";
    cin>>no_of_heads;

    cout<<"Number of requests: ";
    cin>>n;

    cout<<"Current Head Position: ";
    cin>>current_head;

    FCFS();

    return 0;
}
