#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
#include <cstdio>
using namespace std;
class manager{
    public:
    string mid;
    string pw;
    void show_all_records(){
        ifstream in;
        string st,st2;
        in.open("AllMemberDetails.txt");
        while(in.eof()==0){
        getline(in,st);
        cout<<st<<endl;
        }
    in.close(); 
    }
    int serial_num()
    {
        ifstream fin("AllMemberDetails.txt");
        int word=1; 
        char ch;
        fin.seekg(0,ios::beg); 
        while(fin)
        {
        fin.get(ch);
        if(ch==' '||ch=='\n')
        word++;
        }
        fin.close();
        return word;
    }
    int pwd()
    {
        cout<<"\nEnter password : ";
        cin>>pw;
        ifstream mypw("managerpw.txt");
        string chp;
        while(getline(mypw,chp))
        {
            if(chp==pw){
                return 1;
            }
        }
        return 0;
    }
    
   
    int edit()
    {
        string mem;
        string line;
        int nk=0;
        cout<<"Enter Membership Number\n";
        cin>>mem;
        ifstream in("AllMemberDetails.txt");
        ofstream out("outfile.txt");
        int c=0;
        while( getline(in,line) )
        {
        if(line != mem && c<=0)
           { out << line << "\n";
            c--;}
        else if(line==mem){
            c=3;
            nk=1;
        }
        else{
            c--;
        }    
        }
        in.close();
        out.close();    
        remove("AllMemberDetails.txt");
        rename("outfile.txt","AllMemberDetails.txt");
        if(nk==1){
            string name;
        int age;
        string a;
        cout<<"\nEnter Your Name : ";
        cin>>name;
        cout<<"\nEnter Your Age : ";
        cin>>age;
        cout<<"\nPreffered Membership choice (a. Gold/ b.Platinum) :";
        cin>>a;

        int num=serial_num();  
        stringstream ss;  
        ss<<num;  
        string s;  
        ss>>s;  
        ofstream out;
        out.open("AllMemberDetails.txt",ios::app);
        out<<s<<"\n";
        out<<name<<endl;
        out<<age<<endl;
        out<<a<<endl;
        out<<endl;
        out.close();
        cout<<"Gym Membership Number Alotted is : "<<num<<"\n";
        return 1;
        }
        else {cout<<"No member Found ";
        return 0;}
    }
    void delete_member(){
        string mem;
        string line;
        int n=0;
        cout<<"Enter Membership Number\n";
        cin>>mem;
        ifstream in("AllMemberDetails.txt");
        ofstream out("outfile.txt");
        int c=0;
        while( getline(in,line) )
        {
        if(line != mem && c<=0)
           { out << line << "\n";
            c--;}
        else if(line==mem){
            c=3;
            n=1;
        }
        else{
            c--;
        }    
        }
        in.close();
        out.close();    
        remove("AllMemberDetails.txt");
        rename("outfile.txt","AllMemberDetails.txt");
        if(n==1){
            cout<<"Member Deleted\n";
        }    
        else cout<<"Member Not Found Try Again\n";
    }
    int login(){
        system("cls");
        cout<<"--------------- GYM MANAGEMENT SYSTEM---------------\n";
        cout<<"\nEnter manager user id : ";
        cin>>mid;
        ifstream myid("managerid.txt");
        string chi;
        while(getline(myid,chi))
        {
            if(chi==mid){
                int r=pwd();
                if(r==1){
                    return 1;
                    cout<<"Correct\n";
                }
                else{
                    cout<<"\nWrong Password!! \nRetry!!!";
                    system("pause");
                    login();
                }
            }
        }
        cout<<"\nWrong Id!! \nPress 1 to Retry!!!";
        int n;
        cin>>n;
        if(n!=1)return 0;
        else login();
    }
    void new_mem(){
        string name;
        int age;
        string a;
        cout<<"\nEnter Your Name : ";
        cin>>name;
        cout<<"\nEnter Your Age : ";
        cin>>age;
        cout<<"\nPreffered Membership choice (a. Gold/ b.Platinum) :";
        cin>>a;
        int num=serial_num();  
        stringstream ss;  
        ss<<num;  
        string s;  
        ss>>s;  
        ofstream out;
        out.open("AllMemberDetails.txt",ios::app);
        out<<s<<"\n";
        out<<name<<endl;
        out<<age<<endl;
        out<<a<<endl;
        out<<endl;
        out.close();
        cout<<"Gym Membership Number Alotted is : "<<num<<"\n";
        
    }
    void display_record(string num){
        ifstream in;
        string st,st2;
        int nop=0;
        in.open("AllMemberDetails.txt");
        while(in.eof()==0){
        getline(in,st);
        if(st==num){
            cout<<st<<endl;
            getline(in,st);
            cout<<st<<endl;
            getline(in,st);
            cout<<st<<endl;
            getline(in,st);
            cout<<st<<endl;
            nop=1;
        }
        }
        if(nop!=1){
            cout<<"Member Not Found Try Again\n";
        }
    in.close();         
    }
    void func(){
        while(1)
    	{
    	int opt;
        system("cls");
        cout<<"---------------SRM GYM MANAGEMENT SYSTEM---------------\n";
        cout<<"\t\nMANAGER CONTROLS MENU\n";
    	cout<<"\n1 -> Display all records";
    	cout<<"\n2 -> Create a new gym member";
    	cout<<"\n3 -> Edit details of a member";
    	cout<<"\n4 -> Delete a member";
    	cout<<"\n5 -> Search for a record ";
    	cout<<"\n6 -> To return to the previous screen";
    	cout<<"\n\nEnter Your choice : ";
    	cin>>opt;
    	switch(opt)
    	{
    		case 1:{ system("cls");
                    cout<<"---------------GYM MANAGEMENT SYSTEM---------------\n";
                    cout<<"\nAll Member Records:-\n";
    				show_all_records();
                    system("pause");
    				break;
            }
    		case 2: {system("cls");
                    cout<<"---------------GYM MANAGEMENT SYSTEM---------------\n";
                    new_mem();
                    cout<<"New Member Created\n";
                    system("pause");
                    break;
            }
    		case 3:{system("cls");
                   cout<<"---------------GYM MANAGEMENT SYSTEM---------------\n";
                   int r=edit();
                   if (r==1){
                        cout<<"Details Edited\n";
                        
                   }
                   else cout<<"Try Again\n";
                   
                   system("pause");
                       				
    			    break;
            }
    		case 4:{ system("cls");
                    cout<<"---------------GYM MANAGEMENT SYSTEM---------------\n";
                    delete_member();
                    system("pause");
    			    break;
            }
    		case 5: {string num;
   				    system("cls");
                    cout<<"---------------GYM MANAGEMENT SYSTEM---------------\n";
    				cout<<"\nPlease Enter The member Number: ";
    				cin>>num;
    			    display_record(num);
                    system("pause");
    		        break;
            }
    		case 6: {system("cls");
                    return;
    				break;
            }
    		default:{
                    cout<<"\n\nInavlid Input \nTry Again"; 
                    system("pause");
                    func();
    		}}
    	}
    }
};
class member{
    public:
    string name;
    int age;
    int  a;
    int serialnum()
    {
        ifstream fin("AllMemberDetails.txt");
        int word=1; 
        char ch;
        fin.seekg(0,ios::beg); 
 
        while(fin)
        {
        fin.get(ch);
        if(ch==' '||ch=='\n')
        word++;
        }
        fin.close();
        return word;
    }
    void quit(){
        system("cls");
        int nopi=0;
        cout<<"---------------GYM MANAGEMENT SYSTEM---------------\n";
        string mem;
        string line;
        cout<<"Enter Membership Number\n";
        cin>>mem;
        ifstream in("AllMemberDetails.txt");
        ofstream out("outfile.txt");
        int c=0;
        while( getline(in,line) )
        {
        if(line != mem && c<=0)
           { out << line << "\n";
            c--;}
        else if(line==mem){
            c=3;
            nopi=1;
        }
        else{
            c--;
        }    
        }    
    in.close();
    out.close();    
    remove("AllMemberDetails.txt");
    rename("outfile.txt","AllMemberDetails.txt"); 
    if(nopi==1){
        cout<<"\nMember Deleted ";
    }
    else{
        cout<<"\nMember Not found ";
    }
    system("pause");   
    }
       int time_slots()
       {    
            int k;
            cout<<"please select your preferred timings\n press 1 for: morining 6-7\n press 2 for: morning 7-8\npress 3 for:morning 8-9\n";
            cout<<" press 4 for: evening 4-5\npress 5 for:evening 5-6\npress 6 for:evening 6-7\n";
            cout<<"\n enter the choice :";
            cin>>k;
            cout<<"registered time :";
            switch(k)
            {
                case 1:cout<<"6AM-7AM"<<endl;break;
                case 2:cout<<"7AM-8AM"<<endl;break;
                case 3:cout<<"8AM-9AM"<<endl;break;
                case 4:cout<<"4PM-5PM"<<endl;break;
                case 5:cout<<"5PM-6PM"<<endl;break;
                case 6:cout<<"6PM-7PM"<<endl;break;
                default:
                cout<<"enter the correct choice"<<endl;
            }
       }
       int pay_options()
       {    
            int l;
            cout<<"please select payment option\n press 1 for:upi payment\n press 2 for: Credit card\npress 3 for:Debit card\n";
            cout<<" press 4 for: Net banking\npress 5 for:Cash\n";
            cout<<"\n enter the choice :"<<endl;
            cin>>l;
            cout<<"Selected payment option :"<<endl;
            switch(l)
            {
                case 1:cout<<"Upi Payment"<<endl;break;
                case 2:cout<<"Credit card"<<endl;break;
                case 3:cout<<"Debit card"<<endl;break;
                case 4:cout<<"Net banking"<<endl;break;
                case 5:cout<<"Cash"<<endl;break;
                default:
                cout<<"enter the correct choice"<<endl;
            }
       }

    void joins(){
        system("cls");
        cout<<"---------------GYM MANAGEMENT SYSTEM---------------\n";
        cout<<"\nEnter Your Name : ";
        cin>>name;
        cout<<"\nEnter Your Age : ";
        cin>>age;
        cout<<"\nPreffered Membership choice (1. Gold/ 2.Platinum) :";
        cin>>a;
        if(a==1)
        {
            cout<<"Your Fee is "<<1500<<endl;
        }
        else if(a==2)
        {
            cout<<"Your Fee is "<<2500<<endl;
        }
        else{
            cout<<"choice invalid...."<<endl;
        }
        time_slots();
        pay_options();
        int num=serialnum();  
        stringstream ss;  
        ss<<num;  
        string s;  
        ss>>s;  
        ofstream out;
        out.open("AllMemberDetails.txt",ios::app);
        out<<s<<"\n";
        out<<name<<endl;
        out<<age<<endl;
        out<<a<<endl;
        out<<endl;
        out.close();
        cout<<"Gym Membership Number Alotted : "<<num<<"\n";
        system("pause");
    }
    int edit_details(){
        system("cls");
        cout<<"---------------GYM MANAGEMENT SYSTEM---------------\n";
        string mem;
        string line;
        int nk=0;
        cout<<"Enter Membership Number\n";
        cin>>mem;
        ifstream in("AllMemberDetails.txt");
        ofstream out("outfile.txt");
        int c=0;
        while( getline(in,line) )
        {
        if(line != mem && c<=0)
           { out << line << "\n";
            c--;}
        else if(line==mem){
            c=3;
            nk=1;
        }
        else{
            c--;
        }    
        }
        in.close();
        out.close();    
        remove("AllMemberDetails.txt");
        rename("outfile.txt","AllMemberDetails.txt");
        if(nk==1){
            string name;
        int age;
        string a;
        cout<<"\nEnter Your Name : ";
        cin>>name;
        cout<<"\nEnter Your Age : ";
        cin>>age;
        cout<<"\nPreffered Membership choice (a. Gold/ b.Platinum) :";
        cin>>a;
        int num=serialnum();  
        stringstream ss;  
        ss<<num;  
        string s;  
        ss>>s;  
        ofstream out;
        out.open("AllMemberDetails.txt",ios::app);
        out<<s<<"\n";
        out<<name<<endl;
        out<<age<<endl;
        out<<a<<endl;
        out<<endl;
        out.close();
        cout<<"Gym Membership Number Alotted is : "<<num<<"\n";
        return 1;
        }
        else {cout<<"No member Found ";
        return 0;}
    }
};
int logincontrol(){
    system("cls");
    cout<<"---------------GYM MANAGEMENT SYSTEM---------------\n";
    cout<<"\n1 -> MANAGER LOGIN";
    cout<<"\n2 -> USER LOGIN";
    cout<<"\n3 -> EXIT";
    cout<<"\n\n Enter your choice -- ";
    int n;
    cin>>n;
    system("cls");
    return n;
}
int main()
{
    while(1){
    int choice=logincontrol();
    if(choice==1){
        manager my;
        int kr=my.login();
        if(kr==1){
            system("cls");
            cout<<"---------------GYM MANAGEMENT SYSTEM---------------\n";
            cout<<"Welcome Mr Manager !!\n";
            system("pause");
            my.func();
        }
        else{
            if(kr==0){
                cout<<"Login Failed !!";
                cout<<"Press 1 to go to main page or any other key to exit";
                int n;
                cin>>n;
                if(n!=1){
                    
                    exit(0);
                }

                
            }
        }
    
    }
    else if(choice==2){
        member m12;
        system("cls");
        int optchoice;
        cout<<"---------------GYM MANAGEMENT SYSTEM---------------\n";
        cout<<"\t\nUSER MODE:-";
        cout<<"\n1 -> Join Gym";
        cout<<"\n2 -> Quit Gym";
        cout<<"\n3 -> Edit Details";
        cout<<"\n4 -> Return to Main screen";
        cout<<"\n\n Enter Preffered Choice : ";
        cin>>optchoice;
        if(optchoice==1)m12.joins();
        else if(optchoice==2)m12.quit();
        else if(optchoice==3){
            int res=m12.edit_details();
            if (res==1){
                        cout<<"\nDetails Edited";                    
                   }
                   else{ cout<<"\nTry Again";}
                   
                   system("pause");            
        }
    }
    else if(choice==3){
        return 0;
    }
    else {
        cout<<"\nRetry !!";
    }
    }
}
