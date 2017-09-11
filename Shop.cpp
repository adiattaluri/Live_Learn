#include<iostream>
#include<string.h>
int k=0;
using namespace std;
class book
{
	private:
		static int scount;
		static int fcount;
		static double sales;
		char author[20];
		int cost;
		char publisher[25];
		int stock;
		int details_edit();
	public:
		char title[20];
		void add_book();
		void details();
		void edit_stock();
		void authorised();
		void tran_stat();
		friend int search_book(char a,book A[]);
};
int book ::scount;
int book ::fcount;
double book ::sales;
void book ::add_book()
{
	cout<<"Enter the tite of the book: ";
	cin>>title;
	cout<<"Enter the author of the book: ";
	cin>>author;
	cout<<"Enter the cost of the book: ";
	cin>>cost;
	cout<<"Enter the publisher: ";
	cin>>publisher;
	cout<<"Enter the stock: ";
	cin>>stock;
}
void book ::details()
{
	cout<<"\nTitle: "<<title;
	cout<<"\nAuthor: "<<author;
	cout<<"\nCost: "<<cost;
	cout<<"\nPublisher: "<<publisher;
	cout<<"\nStock: "<<stock<<"\n";
}
int book ::details_edit()
{
	int c;
	cout<<"Edit choice\n1.Title\n2.Author\n3.Cost\n4.Publisher\n5.Stock\n6.Exit\n";
			while(1)
			{
			cout<<"Enter choice: ";
			cin>>c;
			switch(c)
			{
				case 1:
					cout<<"Enter the tite of the book: ";
	                cin>>title;
	            break;    
	            case 2:
				    cout<<"Enter the author of the book: ";
	                cin>>author;
	            break;
				case 3:    
					cout<<"Enter the cost of the book: ";
	                cin>>cost;
	            break;
				case 4:    
					cout<<"Enter the publisher: ";
	                cin>>publisher;
                break;
				case 5:	
					cout<<"Enter the stock: ";
	                cin>>stock;
				break;
				case 6:
					return 1;
				break;
				default:
				cout<<"Invalid choice!";	
		    }
		    }
}
void book ::edit_stock()
{
	int n;
	cout<<"\nEnter required copies: ";
	cin>>n;
	if(n>stock)
	{
	cout<<"\nRequired copies not in stock!";
    fcount++;
	}
	else
	{
		char c;
		cout<<"\nTotal cost is: "<<n*cost;
		cout<<"\nComplete the transaction?(Y/N): ";
		cin>>c;
		if(c=='Y')
		{
			cout<<"\nTransaction successfull!";
			stock-=n;
			scount++;
			sales+=(n*cost);
		}
		else
		{
			cout<<"\nTransaction cancelled!";
			fcount++;
		}
	}
}
void book ::authorised()
{
	int i,I=0;
	cout<<"Enter password: ";
	cin>>i;
	if(i==4183)
	{
		I=details_edit();
	}
	else
	{
	cout<<"Authorisation failure!";
    }
}
void book ::tran_stat()
{
	cout<<"Successfull Transactions: "<<scount;
	cout<<"\nTodays sales: "<<sales<<" INR";
	cout<<"\nFailed Transactions: "<<fcount;
}
int main()
{
	int c,f=0,i=0,n=0;
	book A[20];
	char a[30];
	while(1)
	{
	cout<<"\n1.Edit books\n2.Transaction\n3.Details\n4.Transaction Stats\n5.Exit\nEnter choice: ";
	cin>>c;
	switch(c)
	{
		case 1:
			int p;
			cout<<"\n1.Add new book\n2.Edit existing\nEnter choice: ";
			cin>>p;
			switch(p)
			{
				case 1:
					A[k].add_book();
			        k++;
		break;
		case 2:
				    cout<<"Enter book title: ";
				    cin>>a;
				    i=0;
				    while(i<k)
				    {
                	f=strcmp(a,(A[i].title));
				    if(f==0)
				    {
				   		break;
					}
				    i++;
				    }
			if(f==0)
			{
				A[i].authorised();
		    }
		    else
			{
				cout<<"Book not found";
		    }
		break;
		case 3:
				exit (1);
		break; 
		default:
				cout<<"Invalid choice!";   
		}
		break;
		case 2:	
		    i=0;
		    f=1;
			cout<<"Enter the name of the book: ";
			cin>>a;
			while(i<=k)
				    {
				    	f=strcmp(a,(A[i].title));
				    	if(f==0)
				    	{
				    		break;
						}
				        i++;
				    }
			if(f==0)
			{
				A[i].details();
				A[i].edit_stock();
		    }
		    else
			{
				cout<<"Book not found";
		    }
		break;
		case 3:
				n=0;
				while(n<k)
				{
				A[n].details();
			    n++;
			    }
		break;
		case 4:
			A[0].tran_stat();
		break;	
		case 5:
			exit(1);
		break;
		default:
				cout<<"Invalid choice!";	
	}
    }
    return 0;
}
