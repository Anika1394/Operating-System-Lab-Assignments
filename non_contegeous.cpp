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

void non_contiguous()
{
    int total_block, file_size, i, j, k, total_file;
    char file_name;
    map <char, int> mapper;

    cout<<"Enter the total number of File: ";
    cin>>total_file;
    cout << "Enter total number of blocks: ";
    cin >> total_block;
    cout << endl;

    int free = total_block, block[total_block];

    int random;


    for(i = 0; i < total_block; i++)
    {
         block[i] = -1;
    }


    for(i = 0; i < total_file; ++i)
    {
        cout << "Enter Filename: ";
        cin >> file_name;

        cout << "Enter File-Size: ";
        cin >> file_size;

        mapper[file_name] = i;
        random= rand()%10+3;

        if(file_size > free)
        {
            cout << "File " << file_name << " cannot be created (not enough free blocks)" <<endl;
        }

        else
        {
            if(free == total_block)
            {
                for(j = 0; j < total_block && file_size > 0; j += random)
                {
                    block[j] = i;
                    free--;
                    file_size--;
                    random= rand()%10+3;
                }
                if(file_size > 0)
                {
                    for(j = 0; j < total_block && file_size > 0; j++)
                    {
                        if(block[j] == -1)
                        {
                            file_size--;
                            free--;
                            block[j] = i;
                        }

                    }

                }
            }
            else
            {
               for(j = 0; j < total_block && file_size > 0; j++)
               {
                    if(block[j] == -1)
                    {
                        file_size--;
                        free--;
                        block[j] = i;
                    }

                }
            }

            cout << "File " << file_name << " created"<<endl;
        }

        cout << endl;
    }
    search_file(mapper,total_file,total_block,block);
}

int main(){

    non_contiguous();
    cout<<endl<<endl;
}
