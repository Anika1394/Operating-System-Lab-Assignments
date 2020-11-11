#include <bits/stdc++.h>
using namespace std;

#define arr 100000

int n;
int frame_size;
int page_no;
int sequence[arr];


void FIFO_Page_Replacement()
{
    queue<int> Q;
    int page_faults=0;
    int present[page_no]={0};

    for(int i=0; i<n; i++)
    {
        if(present[sequence[i]]== 1)
        {
            cout<<"Reference to page "<<sequence[i]<<" is not responsible for a page fault"<<endl;
        }
        else
        {
            Q.push(sequence[i]);
            present[sequence[i]]= 1;
            if(Q.size()>frame_size)
            {
                int p= Q.front();
                present[p]= 0;
                Q.pop();
            }
            page_faults++;
            cout<<"Reference to page "<<sequence[i]<<" is responsible for a page fault"<<endl;
        }

    }
    cout<<"\nTotal Page Faults: "<<page_faults<<endl;
    cout<<"Page Fault Ratio: "<<((double)page_faults / (double)n) * 100.0<<" %";

}

int main()
{


    cout<<"Number of Pages: ";
    cin>>page_no;


    cout<<"Number of Page References: ";
    cin>>n;

    cout<<"Reference String:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>sequence[i];
    }

    cout<<"Number of Frames in memory: ";
    cin>>frame_size;

    FIFO_Page_Replacement();






    return 0;
}
