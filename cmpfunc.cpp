#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
class cpuschedule
{  public:
    int n,Bu[20];
    float Twt,Awt,A[10],Wt[10],w;
public:
    void Getdata();
    };

class cpuschedule1: public cpuschedule
{
	public:
		void Fcfs();
	};

class cpuschedule2: public cpuschedule
{
/*	int n,Bu[20];
	float twtrr,awtrr,A[10],Wt[10],w;*/
	public:
		void RoundRobin();
	};
		
class cpuschedule3: public cpuschedule
{
	/*int n,Bu[20];
	float twtpr,awtpr,A[10],Wt[10],w;*/
	public:
		void Priority();
	};
		
		
void cpuschedule::Getdata()
{
	int i;
    cout<<"\nEnter the no of processes:";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"\nEnter The BurstTime for Process p"<<i<<"=	";
        cin>>Bu[i];
    }
}

void cpuschedule1::Fcfs()
{
  int i,B[10];
    Twt=0.0;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for process p"<<i<<"=	";
        cout<<B[i];
    }
    Wt[1]=0;
    for(i=2; i<=n; i++)
    {
        Wt[i]=B[i-1]+Wt[i-1];
    }

    for(i=1; i<=n; i++)
    {
        Twt=Twt+Wt[i];
    }
    Awt=Twt/n;
    cout<<"\n\nTotal   Waiting Time="<<Twt;
    cout<<"\n\nAverage Waiting Time="<<Awt<<""<<endl;

}

void cpuschedule3::Priority()
{
 int i,B[10],P[10],j;
    w=0.0;
    int max;
    Twt=0.0;
    max=1;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for process p"<<i<<"=	";
        cout<<B[i];
        cout<<"\nEnter the priority for process P"<<i<<"=	";
        cin>>P[i];
        if(max<P[i]){
            max=P[i];
        }
    }
    j=1;
    while(j<=max)
    {
        i=1;
        while(i<=n)
        {
            if(P[i]==j)
            {
                Wt[i]=w;
                w=w+B[i];
            }
            i++;
        }
        j++;
    }

    for(i=1; i<=n; i++){
        Twt=Twt+Wt[i];
    }
    Awt=Twt/n;
    cout<<"\nTotal   Waiting Time="<<Twt<<""<<endl;
    cout<<"\nAverage Waiting Time="<<Awt<<""<<endl;
	}

void cpuschedule2::RoundRobin()
{
    int i,j,tq,k,B[10],Rrobin[10][10],count[10];
    int max=0;
    int m;
    Twt=0.0;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for process p"<<i<<"=	";
        cout<<B[i];
        if(max<B[i])
            max=B[i];
        Wt[i]=0;
    }
    cout<<"\nEnter the Time Quantum=";
    cin>>tq;

    m=max/tq+1;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            Rrobin[i][j]=0;
        }
    }

    i=1;
    while(i<=n)
    {
        j=1;
        while(B[i]>0)
        {
            if(B[i]>=tq)
            {
                B[i]=B[i]-tq;
                Rrobin[i][j]=tq;
                j++;
            }
            else
            {
                Rrobin[i][j]=B[i];
                B[i]=0;
                j++;
            }
        }
        count[i]=j-1;
        i++;
    }

    cout<<"Display";
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            cout<<"Rr["<<i<<","<<j<<"]="<<Rrobin[i][j];
            cout<<"	";
        }
        cout<<"";
    }

    int x=1;
    i=1;
    while(x<=n)
    {
        for(int a=1; a<x; a++)
        {
            Wt[x]=Wt[x]+Rrobin[a][i];
        }
        i=1;
        int z=x;
        j=count[z];
        k=1;
        while(k<=j-1)
        {
            if(i==n+1)
            {
                i=1;
                k++;
            }
            else
            {
                if(i!=z)
                {
                    Wt[z]=Wt[z]+Rrobin[i][k];
                }
                i++;
            }
        }
        x++;
    }
    for(i=1; i<=n; i++) {
        cout<<"\nWaiting Time for process P"<<i<<"="<<Wt[i];
    }

    for(i=1; i<=n; i++) {
        Twt=Twt+Wt[i];
    }
    Awt=Twt/n;
    cout<<"\nTotal   Waiting Time="<<Twt<<endl;
    cout<<"\nAverage Waiting Time="<<Awt<<""<<endl;
}

int main()
{
    int ch;
    //cpuschedule c;
    cpuschedule1 c1;
    cpuschedule2 c2;
    cpuschedule3 c3;
    do
    {
    	 system("CLS");
        //cout<<endl<<"1.Getting BurstTime"<<endl;
        cout<<"1.FirstComeFirstServed"<<endl;
        cout<<"2.RoundRobin"<<endl;
        cout<<"3.Priority"<<endl;
        cout<<"4.Comparison Table"<<endl;
        cout<<"5.EXIT"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        	cout<<endl<<"Getting BurstTime"<<endl;
            c1.Getdata();
            cout<<"\nFIRST COME FIRST SERVED SCHEDULING"<<endl;
            c1.Fcfs();
            break;
       /* case 2:
            cout<<"\nFIRST COME FIRST SERVED SCHEDULING"<<endl;
            c1.Fcfs();
            break;*/
        case 2:
        	cout<<endl<<"Getting BurstTime"<<endl;
        	c2.Getdata();
            cout<<"\nROUND ROBIN SCHEDULING"<<endl;
            c2.RoundRobin();
            break;
        case 3:
        	cout<<endl<<"Getting BurstTime"<<endl;
        	c3.Getdata();
            cout<<"\nPRIORITY SCHEDULING"<<endl;
            c3.Priority();
            break;
        case 4:
            cout<<"\n           |TWT\t        |AWT\t\t    |"<<endl;
			cout<<"FCFS       |\t"<<c1.Twt<<"\t|"<<c1.Awt<<"\t    |\n";
			cout<<"ROUNDROBIN |\t"<<c2.Twt<<"\t|"<<c2.Awt<<"\t    |\n";
			cout<<"PRIORITY   |\t"<<c3.Twt<<"\t|"<<c3.Awt<<"\t    |\n";
            break;
       
        case 5:
            break;
        }
        system("pause");
    }
    while(ch<=4);
}
