#include<bits/stdc++.h>
using namespace std;

void search_file(map<char,int> &mapper,int total_file,int total_block,int block[]){
    int j,k;
    char file_name;
    for(int i = 0; i < total_file; i++)
    {
        cout << "Search Filefname: ";
        cin >> file_name;

        for(j = 0; j < total_block; j++)
        {
            if(mapper.find(file_name) == mapper.end())
                continue;
            if(block[j] == mapper[file_name])
            {
                cout << "File Found in the blocks: " << j;

                for(k = j+1; k < total_block; k++){
                    if(block[k] == block[j])
                        cout << " " << k;
                }

                j = total_block+1;
            }
        }

        if(j > total_block)
            cout << endl;
        else
            cout << "File not Found." << endl;


    }
}

void contiguous()
{
    int total_block, file_size, i, j, k, total_file;
    char file_name;
    map <char, int> mapper;

    cout<<"Enter the total number of File: ";
    cin>>total_file;
    cout << "Enter total number of blocks: ";
    cin >> total_block;
    cout << endl;

    int block[total_block];

    for(i = 0; i < total_block; i++)
    {
       block[i] = -1;
    }

    for(i = 0; i < total_file; i++)
    {
        cout << "Enter Filename: ";
        cin >> file_name;

        cout << "Enter File-Size: ";
        cin >> file_size;

        mapper[file_name] = i;

        for(j = 0; j+file_size < total_block; j++)
        {
            if(block[j] == -1)
            {
                for(k = 0; k < file_size; k++)
                {
                    block[k+j] = i;
                }

                break;
            }

        }

        if(j+file_size >= total_block)
            cout << "File " << file_name << " cannot be created (not enough free blocks)"<<endl;
        else
            cout << "File " << file_name << " created"<<endl;
        cout << endl;
    }
    search_file(mapper,total_file,total_block,block);
}



int main(){

    contiguous();

    cout<<endl<<endl;


}
