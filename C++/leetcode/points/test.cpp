#include<iostream>
#include<string.h>
using namespace std;
int main()
{
   int num, datax, datay ;
    int t=0;
    int flag = 0;
   int data_[50000][2];
   int dat[50000][2];
   
   int dat_end[50000][2];
    cout << "Enter an integer, a double, and a character: ";
    cin >> num ;
    cout << "\n";
    for(int i=0;i<num;i++)
    {
        cin >> datax >> datay;
        cout << "\n";
        data_[i][0] = datax;
        data_[i][1] = datay;
    } 
     cout << "Hellow...\n";
    int tem[1][2];
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)//本身&当i为最后一个时，不用比较
        {
            memset(tem[0],0x00,sizeof(tem[0]));
            if(data_[i][0]>data_[j][0])
            {
                memcpy(tem[0],data_[i],sizeof(data_[i]));
                memcpy(data_[i],data_[j],sizeof(data_[i]));
                memcpy(data_[j],tem[0],sizeof(data_[i]));                
            }
        }        
        
    }
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(data_[j][1]>=data_[i][1])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            dat_end[t][0]= data_[i][0];
            dat_end[t][1]= data_[i][1];
            t++;
        }
        else
        {
            flag = 0;
        }
    }
       
    for(int i=0;i<t;i++)
    {        
        cout << dat_end[i][0] << " " << dat_end[i][1] << "\n";
    }
    return 0;
}