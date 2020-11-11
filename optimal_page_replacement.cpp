#include <bits/stdc++.h>
using namespace std;
#define arr 100000

int n;
int frame_size;
int sequence[arr];

void optimal_page_replacement()
{
    vector<int> frame;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < frame.size(); j++)
        {
            if (frame[j] == sequence[i])
                break;
        }

        if (j==frame.size())
        {
            if (frame.size() < frame_size)
            {
                frame.push_back(sequence[i]);
            }

            else
            {
                int index=i+1;
                int f, farthest = index;
                for (int m = 0; m < frame.size(); m++)
                {
                    int k;
                    for (k = index; k < n; k++)
                    {
                        if (frame[m] == sequence[k])
                        {
                            if (k > farthest)
                            {
                                farthest = k;
                                f = m;
                            }
                            break;
                        }
                    }
                    if (k == n)
                    {
                        f=m;
                        break;
                    }
                }
                frame[f] = sequence[i];
            }
            page_faults++;
            cout<<"Reference to page "<<sequence[i]<<" is responsible for a page fault"<<endl;
        }
        else
        {
            cout<<"Reference to page "<<sequence[i]<<" is not responsible for a page fault"<<endl;
        }
    }
    cout<<"\nTotal Page Faults: "<<page_faults<<endl;
    cout<<"Page Fault Ratio: "<<((double)page_faults / (double)n) * 100.0<<" %";
}

int main()
{
    cout<<"Number of Frames: ";
    cin>>frame_size;

    cout<<"Number of Page References: ";
    cin>>n;

    cout<<"Reference String:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>sequence[i];
    }

    optimal_page_replacement();
    return 0;
}
