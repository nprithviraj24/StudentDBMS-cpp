#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int n,i=0;

class management
{
public:
    char rn[10];
    char branch[3];
    int marks;
    char result[2];
    char name[25];
    int ranker;

}*record[100], *rec;

void insert_it(){
record[i]=new management();

cout<<"\n Roll no: ";
cin>>record[i]->rn;

cout<<" \n Name: ";
cin>>record[i]->name;

cout<<"\n Branch: ";
cin>>record[i]->branch;

cout<<"\n Total marks: ";
cin>>record[i]->marks;

cout<<"\n Result: ";
cin>>record[i]->result;

cout<<"\n Rank: ";
cin>>record[i]->ranker;

cout<<"\n\nRoll no\tName\tBranch  Total Marks  Rank";
cout<<"\n__________________________________________________________";
cout<<"\n"<<record[i]->rn<<"  "<<record[i]->name<<"  "<<record[i]->branch<<"\t"<<record[i]->marks<<"\t"<<record[i]->result<<"  "<<record[i]->ranker;
i++;
}

void del()
{
    for(int n=0;n<i;n++)
    {   cout<<"\n\nRoll no\tName";
        cout<<"\n________________________________ _____________";
        cout<<"\n"<<record[n]->rn<<"  "<<record[n]->name;
    }
    char roll[10];
    cout<<"\nEnter the roll number of that record ";
    cin>>roll[10];
     for(int n=0;n<i;n++)
       {
            if(roll==record[n]->rn)
            {
                delete record[n];
                i--;
                break;
            }
        }
     if(n==i+1)
     cout<<"Sorry roll number not found ";
}

void modify()
{
     for(int n=0;n<i;n++)
    {   cout<<"\n\nRoll no\tName";
        cout<<"\n______________________________________________";
        cout<<"\n"<<record[n]->rn<<"  "<<record[n]->name;
    }

    cout<<"\n\nEnter the roll no of the record you want to modify: ";

    char roll[10];
    cin>>roll[10];
     for(int n=0;n<=i;n++)
       {
           if(roll==record[n]->rn)
          break;
      }
     if(n==i+1)
     cout<<"Sorry, roll number not found ";
    else
     {  int j;
        cout<<"\nField you want to modify 1.RollNumber\n2.Name\n3.Branch\n4.TotalMarks\n.5Rank\n6.ResultStatus\n.7EXIT\n";
       cin>>j;
       cout<<"\nEnter the modified version ";
         switch(j)
          {
             case 1: cout<<"Enter the modified version: ";
                     cin>>record[n]->rn;
                     break;
             case 2:  cout<<" \n Modified Name: ";
                     cin>>record[n]->name;
                     break;
            case 3: cout<<"\n Modified branch: ";
                    cin>>record[n]->branch;
                    break;

            case 4: cout<<"\nModified Total marks: ";
                   cin>>record[n]->marks;
                   break;
            case 5: cout<<"\nModified Result: ";
                    cin>>record[n]->result;
                    break;
            case 6: cout<<"\nModified Rank: ";
                    cin>>record[n]->ranker;
                    break;
            default: break;
        }
     }
}

void display(){
char ro[10];
int numb;
  cout<<"Enter 0 if it is a single record that you want, else 1 for full record";
  cin>>numb;
  if(numb==0)
     {
          for(n=0;n<i;n++)
         {  cout<<"\n\nRoll no\tName";
            cout<<"\n______________________________________________";
            cout<<"\n"<<record[n]->rn<<"  "<<record[n]->name;
         }
      cout<<"\nSelect the desired roll number: ";
      cin>>ro;
      cin>>ro[10];
         for(int n=0;n<=i;n++)
         {
           if(ro==record[n]->rn)
           break;
         }
              if(n==i+1)
                 cout<<"\n\t\tSorry, roll number not found ";
             else{
                 cout<<"\n\nRoll no\tName\tBranch  Total Marks  Rank";
                 cout<<"\n__________________________________________________________";
                 cout<<"\n"<<record[n]->rn<<"  "<<record[n]->name<<"  "<<record[n]->branch<<"\t"<<record[n]->marks<<"\t"<<record[n]->result<<"  "<<record[n]->ranker;
         }

      }

  else{
         for(int n=0;n<i;n++)
       {         cout<<"\n\nRoll no\tName\tBranch  Total Marks  Rank";
                 cout<<"\n__________________________________________________________";
                 cout<<"\n"<<record[n]->rn<<"  "<<record[n]->name<<"  "<<record[n]->branch<<"\t"<<record[n]->marks<<"\t"<<record[n]->result<<"  "<<record[n]->ranker;

       }

    }

}

void sortit()
{
   cout<<"\nEnter 0 if you want record in rank sorted, else any other number for roll number record: ";
   int o;
   char st[10];

   cin>>o;
   if(o==1)
   {
       for(int m=0;m<=i;m++)
        {
         for(int k=m+1;k<=i;k++)
            {
              if(record[k]->ranker < record[m]->ranker)
                {
                    rec=new management();
                    rec=record[m];
                    record[m]=record[k];
                    record[k]=record[m];  //if it is wrong, also check else condition
                }
            }
        }

   }
else
   {
     for(int m=0;m<=i;m++)
     {
         for(int k=m+1;k<=i;k++)
            {
              if( strcmp(record[k]->rn,record[m]->rn)<0 )   //strncmp or strcmp???
               {
                   rec=new management();
                    rec=record[m];
                    record[m]=record[k];
                   record[k]=record[m];
               }
            }
     }
   }
for(int n=0;n<i;n++)
            {    cout<<"\n\nRoll no\tName\tBranch  Total Marks  Rank";
                 cout<<"\n__________________________________________________________";
                 cout<<"\n"<<record[n]->rn<<"  "<<record[n]->name<<"  "<<record[n]->branch<<"\t"<<record[n]->marks<<"\t"<<record[n]->result<<"  "<<record[n]->ranker;
            }

}

void analytics()
{
int a[3][3]={0};
for(int b=0;b<=i;b++)
  {

if(strcmp(record[b]->branch,"EC")==0|| strcmp(record[b]->branch,"ec")==0)
      {      if(strcmp(record[b]->result,"P")==0||strcmp(record[b]->result,"p")==0)
                    a[0][0]++;
    else if(strcmp(record[b]->result,"W")==0|| strcmp(record[b]->result,"w")==0)
                   a[0][1]++;
    else
                  a[0][2]++;
      }
else if(strcmp(record[b]->branch,"CS")==0||strcmp(record[b]->branch,"cs")==0)
   {
        if(strcmp(record[b]->result,"P")==0||strcmp(record[b]->result,"p")==0)
                    a[1][0]++;
    else if(strcmp(record[b]->result,"W")==0|| strcmp(record[b]->result,"w")==0)
                   a[1][1]++;
    else
                  a[1][2]++;
   }

else{
   if(strcmp(record[b]->result,"P")==0||strcmp(record[b]->result,"p")==0)
                    a[2][0]++;
    else if(strcmp(record[b]->result,"W")==0|| strcmp(record[b]->result,"w")==0)
                   a[2][1]++;
    else
                  a[2][2]++;
}
}

cout<<"\n\n\t  PASS\tWITHHELD\tFAIL\n";
cout<<"\nEC\t"<<a[0][0]<<"\t"<<a[0][1]<<"\t"<<a[0][2];
cout<<"\nCS\t"<<a[1][0]<<"\t"<<a[1][1]<<"\t"<<a[1][2];
cout<<"\nIT\t"<<a[2][0]<<"\t"<<a[2][1]<<"\t"<<a[3][2];
}


int main()
{
    int j;
    char ch;
        cout<<"\t\tSTUDENT DATABASE MANAGEMENT SYSTEM\n\n";

      do
       {
          cout<<"\n\t1.Insert record\n\t2.Delete record\n\t3.Modify record\n\t4.Display Record\n\t5.Sort student records\n\t6.Analytics\n\t7.Exit\n\t";
          cout<<"\nEnter the number: ";
          cin>>j;

           switch(j)
            {
             case 1: insert_it();
                     break;
             case 2: del();
                     break;
             case 3: modify();
                    break;
             case 4: display();
                   break;
             case 5:sortit();
                    break;
             case 6: analytics();
                    break;
             case 7: break;
             default: j=0;
            }
            cout<<"\n \t Do you want to continue? Y or N. ";
           cin>>ch;
           }while(ch=='y'||ch=='Y');
    return 0;
}

