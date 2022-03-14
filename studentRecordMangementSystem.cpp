// C++ Implementation of Student Records Management System
#include<bits/stdc++.h>
using namespace std;

//Class Representing the Node of Linked List
class Node
{
	public:
		int rollNo;
		string Name;
		string Branch;
		int Marks;
		Node *next;
};

Node *head= new Node();

//Function to check if record
//already exist
bool check(int x)
{
	
	if(head==NULL)
	return false;
	
	Node *temp=new Node;
	temp=head;
	
	//Traversing the Linked List
	while(temp!=NULL)
	{
		if(temp->rollNo==x)
		return true;
		temp=temp->next;
	}
	//In case it not exist
	return false;
}

//Function to insert a new Record
void Insert_Record(int rollNo,string Name,
                    string Branch, int Marks)
    {
    	//checking if record already exist
    	if(check(rollNo))
    	{
    		cout<<"Record of this"
    		    <<"Student already exists";
    		return;
		}
		
		//Inserting new Record
		Node *temp=new Node();
		temp->rollNo=rollNo;
		temp->Name=Name;
		temp->Branch=Branch;
		temp->Marks=Marks;
		temp->next=NULL;
		
		//Inserting at Begin
		if(head==NULL ||
		    (head->rollNo >=temp->rollNo))
		{
			temp->next=head;
			head=temp;
		}
		
		//Insert at middle or End
		else
		{
			Node *c=head;
			while(c->next!=NULL
			      && c->next->rollNo < temp->rollNo)
			      {
			      	c=c->next;
				  }
				  temp->next=c->next;
				  c->next=temp;
		}
		cout<<"Record Successfully Inserted \n";	
	}
	
	//Function to Search Record of
	//any Student Using Roll Number
	
	void Search_Record(int rollNo)
	{
		if(!head)
		{
			cout<<"No Record Found\n";
			return;
		}
		
		else
		{
			Node *p=head;
			while(p)
			{
				if(p->rollNo==rollNo)
				{
					cout<<"Roll Number\t"
					    <<p->rollNo<<endl;
					    
					cout<<"Name:\t"
					    <<p->Name<<endl;
					
					cout<<"Branch:\t"
					    <<p->Branch<<endl;
					    
					cout<<"Marks:\t"
					    <<p->Marks<<endl;
					    
					return;
				}
				p=p->next;
			}
			
			if(p==NULL)
			cout<<"No Such Records Available\n";
		}
	}
	
	//Function to delete record of a student
	//with given Roll No
	
	int Delete_Record(int rollNo)
	{
		
		Node *temp=head;
		Node *p=NULL;
		
		//Deletion at Begin
		if(temp!=NULL 
		   && temp->rollNo==rollNo)
		   {
		   	head=temp->next;
		   	delete temp;
		   	
		   	cout<<"Record Successfully Deleted\n";
		   	return 0;
		   }
	
	//Deletion other than Beginning
	
	while(temp!=NULL && temp->rollNo!=rollNo)
	{
		p=temp;
		temp=temp->next;
	}
	
	if(temp==NULL)
	{
		cout<<"Record does not exist\n";
		return -1;
		p->next=temp->next;
		
		delete temp;
		cout<<"Record Successfully Deleted\n";
		return 0;
	}
}

    //Fuction to Display 
    //Student's Record
    
    void Show_Record()
    {
    	Node *p=head;
    	
    	if(p==NULL)
    	{
    		cout<<"No Record Available\n";
		}
		
		else
		{
			cout<<"RollNo\tName\tCourse"
			<<"\tMarks\n";
			
			//until p is not NULL
			while(p!=NULL)
			{
				cout<<p->rollNo<<"\t"
				    <<p->Name <<"\t"
				    <<p->Branch <<"\t"
				    <<p->Marks <<endl;
				p=p->next;
			}
		}
	}

//  Main Code

    int main()
    {
    	head=NULL;
    	string Name, Course;
    	int rollNo, Marks;
    	
    	while(true)
    	{
    		cout << "\n\t\tWelcome to Student Record "
                <<"Management System\n\n\tPress\n\t1 to "
                <<"create a new Record\n\t2 to delete a "
                <<"student record\n\t3 to Search a Student "
                <<"Record\n\t4 to view all students "
                <<"record\n\t5 to Exit\n";
        cout<< "\nEnter your Choice\n";
        
        int Choice;
        cin>>Choice;
        
        if (Choice == 1) {
            cout << "Enter Name of Student\n";
            cin >> Name;
            cout << "Enter Roll Number of Student\n";
            cin >> rollNo;
            cout << "Enter Course of Student \n";
            cin >> Course;
            cout << "Enter Total Marks of Student\n";
            cin >> Marks;
            Insert_Record(rollNo, Name, Course, Marks);
        }
        
        else if (Choice == 2) {
            cout << "Enter Roll Number of Student whose "
                    "record is to be deleted\n";
            cin >> rollNo;
            Delete_Record(rollNo);
        }
        
        else if (Choice == 3) {
            cout << "Enter Roll Number of Student whose "
                    "record you want to Search\n";
            cin >> rollNo;
            Search_Record(rollNo);
        }
        
        else if (Choice == 4) {
            Show_Record();
        }
        
        else if (Choice == 5) {
            exit(0);
        }
        
        else {
            cout << "Invalid Choice "
                 << "Try Again\n";
        }
    }
    return 0;
}
