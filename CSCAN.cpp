#include <bits/stdc++.h>
using namespace std;

int n;
int no_of_heads;
int current_head;
vector<int> smallest, largest;
vector<int> serving_order;

void CSCAN()
{

    int positions[no_of_heads];
    cout<<"Cylinder requests:"<<endl;

    for(int i=0; i<n; i++)
    {
        cin>>positions[i];
    }
    cout<<endl;
    int movement = 0;

    smallest.push_back(0);
    largest.push_back(no_of_heads - 1);


    for (int i = 0; i < n; i++) {
        if (positions[i] < current_head){
            smallest.push_back(positions[i]);
        }

        if (positions[i] > current_head){
            largest.push_back(positions[i]);
        }

    }


    sort(smallest.begin(), smallest.end());
    sort(largest.begin(), largest.end());


    for (int i = 0; i < largest.size(); i++) {

        serving_order.push_back(largest[i]);
        movement += abs(largest[i] - current_head);

        current_head = largest[i];
    }

    current_head = 0;


    for (int i = 0; i < smallest.size(); i++) {

        serving_order.push_back(smallest[i]);
        movement += abs(smallest[i] - current_head);

        current_head = smallest[i];
    }

    cout << "Total Cylinder movement: " << movement << endl<<endl;

    cout << "Cylinder Serving Order: " << endl;

    for (int i = 0; i < serving_order.size(); i++) {
        cout << serving_order[i];
        if(i < serving_order.size()-1)
            cout<<"-->";
    }
    cout<<endl;
}


int main()
{

    cout<<"Number of heads: ";
    cin>>no_of_heads;

    cout<<"Number of requests: ";
    cin>>n;

    cout<<"Current Head Position: ";
    cin>>current_head;

    CSCAN();

    return 0;
}
