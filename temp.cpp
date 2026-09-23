#include<iostream>
using namespace std;

class Array_sorting
{
    private:
    int Array[100];
    int n,temp,minn,high,low,mid,i,j,k;


    public:
    void get_array()
    {
        cout<<"Enter the number of elements: ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>Array[i];
        }
    }
    void display()
    {
        cout<<"\t";
        for(int i=0;i<n;i++)
        {
            cout<<Array[i]<<" ";
        }
        cout<<endl;
    }


    void bubble_sort()
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(Array[j]>Array[j+1])
                {
                    temp=Array[j];
                    Array[j]=Array[j+1];
                    Array[j+1]=temp;
                }
            }
        }
        display();
    }


    void selection_sort()
    {
        for(int i=0;i<n-1;i++)
        {
            minn=i;
            for(int j=i+1;j<n;j++)
            {
                if(Array[minn]>Array[j])
                {
                    minn=j;
                }

            }
            temp=Array[i];
            Array[i]=Array[minn];
            Array[minn]=temp;
        }
        display();
    }

    void mergee(int low,int mid,int high)
    {
        int i=low;
        int j=mid+1;
        int k=0;
        int temp[100];
        while(i<=mid && j<=high)
        {
            if(Array[i]<Array[j])
            {
                temp[k]=Array[i];
                i++;
            }
            else{
                temp[k]=Array[j];
                j++;
            }
            k++;
        }
        while(i<=mid)
        {
            temp[k]=Array[i];
            i++;
            k++;
        }
        while(j<=high)
        {
            temp[k]=Array[j];
            j++;
            k++;
        }
        for(i=low,k=0;i<=high;i++,k++)
        {
            Array[i]=temp[k];
        }

    }


    void merge_sort(int low,int high)
    {
        if(low<high)
        {
            int mid=(low+high)/2;


            merge_sort(low,mid);
            merge_sort(mid+1,high);
            mergee(low,mid,high);
        }
    }
    void display_merge_sort()
    {
        merge_sort(0,n-1);
        display();
    }


};


int main()
{   Array_sorting Ab;
    int choice;
    do{
             cout<<"choose:\n1.Bubble sort\n2.Selection sort\n3.Merge sort\n";
    cin>>choice;
        switch(choice)
        {
            case 1:
            Ab.get_array();
            cout<<"\tUnsorted Array "<<endl;
            Ab.display();
            cout<<"\t Sorted Array(using bubble sort)"<<endl;
            Ab.bubble_sort();
            break;
            case 2:
            Ab.get_array();
             cout<<"\tUnsorted Array "<<endl;
            Ab.display();
            cout<<"\t Sorted Array(using selection sort)"<<endl;
            Ab.selection_sort();
            break;
            case 3:
            Ab.get_array();
             cout<<"\tUnsorted Array "<<endl;
            Ab.display();
            cout<<"\t Sorted Array(using merge sort)"<<endl;
            Ab.display_merge_sort();
            break;
            default:
                cout<<"Exiting!!!";
                exit(0);
                break;
        }
    }while(0<choice<4);
    return 0;
}

