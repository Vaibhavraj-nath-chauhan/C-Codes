//liberary of Standard input-output
#include<iostream>								
//liberary of strings
#include<string.h>								
//liberary of data to read from a file as an input and data to write into the file
#include<fstream>								 
//liberary of subsystems and functions (usedfor sleep function)
#include<windows.h>								

                              
using namespace std;                          

//declearing it globally because we need this in maximum functions
string user_ok;                                
//defining a structue to store name
struct Person                                  
{
    string name,u_pass;
}o[6];

//user login function
void login();	
//user register function	                                          									
void registr();    
//forget function                                           
void forgot();     
//url oppener function                                          
void url_open(char);       
//in this function we will take file name from inserting_data function and insert data according to our need                                   
void inserting_file_data(string);      
//in this function we will take file name from reading_data function and read whole data                       
void reading_file_data(string);  
//calling login page again and again                            
void login_again();

//main function
int main()                                                   
{
	//changing color of screen and text
	system("Color F4");                                       
	char choice;                                              
	cout<<"                                       ******************************************\n"; 
	cout<<"                                       *          WELCOME to Main Menu          *";
	cout<<"\n                                       *                                        *";
	cout<<"\n                                       ******************************************\n\n";
	
	cout<<"\t\t\tLogin                --> 1                            Register       --> 2\n\n\t\t\tForgot               --> 3                            Exit           --> 4\n\n"<<endl;
	cout<<"\t\t\t\t\t  Enter your choice -->  ";
	cin>>choice;                                                   //################
	cout<<endl;
	switch(choice)
	{
		case '1':
			
			//function calling 
			login();                                            
			break;
		case '2':
			
			//function calling
			registr();                                          
			break;
		case '3':
			
			//function calling
			forgot();                                          
			break; 
		case '4':
			
			//program exit;
			cout<<"Thanks for using this program!!\n";         
            break;
		default:
			
			//clearing screen
			system("cls");                                     
			cout<<"\n\t\t\t\t\t\tEnter Right Value "; 
			Sleep(2000);
			system("cls"); 
			//calling main function again                     
			main();                                          
			break;
    }
}


//......................................................................................................................................................................................


//function defination
void login()                                                   
{
	//defining parameter
	int count;         
	//defining parameter                                       
	string pass_ok,u,p;       
	//clearing screen                        
	system("cls");   
	cout<<"\n\tTo go on home page please enter : \\"<<endl;;                                        
	cout<<"\n\n\tEnter your Username:-";         
	//clearing white space if any               
	cin>>ws;                                                  
	getline(cin,user_ok);
	if(user_ok[0] == '\\')
	{
		system("cls");
		main();
	}                                         
	cout<<"\n\tEnter your Password:-"; 
	//clearing white space if any                           
	cin>>ws;                                                 
	getline(cin,pass_ok);
	if(pass_ok[0] == '\\')
	{
		system("cls");
		main();
	}   
	//inputting data into file
	ifstream input("data.txt"); 
	 //reading word by word after every space                             
	while(input>>u>>p)
	{        
	    //checking every username and password if match then it will increase the value of count                              
		if(u==user_ok & p==pass_ok)
	    {                         
			count=1;       
			//clearing screen       
			system("cls");                                   
	    }
    }   
	input.close();
	//if data does not exist then this code execute
	if (count==1)                                            
	{
         login_again();
	}
	else
	{
		system("cls");
		cout<<"\n\t\t\t\t\t\t    LOGIN ERROR \n\n\t\t\t\t\tPlease check your username and password"<<endl;
		Sleep(3000);
		system("cls");
		main();
	}

}


//......................................................................................................................................................................................


//function defincation
void registr()                                                  
{   
    string reguser,name,fname,mobile;
    string regpass,ru,rp;
    system("cls");
    cout<<"\t\t************************Enter Your Details For New REGISTRATION**************************"<<endl;
    cout<<"\n Rules to Enter UserName and Password\n  1. No Space are allowed\n  2. In place of space use usederscore ( _ )\n  3. Back to login page enter \\"<<endl;
    cout<<"\n\tEnter the Username :";
    //ye line buffer se whitespaces remove krti h 
    cin>>ws;       
	 //fetching username with spcae                                             
    getline(cin,reguser);     
	if(reguser[0] == '\\')
	{
		system("cls");
		main();
	}                                   
    //checking condition if spcae is there then username will not be consider..........
    for(int l=0;l<reguser.size(); l++)
	{                          
		    if(reguser[l]==' ')
			{
		    	system("cls");
		    	cout<<"\n\t\t\t\t\t\t  Input Name Contain Space"<<endl;
		    	Sleep(2000);
		    	registr();
			}
    } 
    //checking that data of new user is already taken or not..........
    ifstream check("data.txt");
    while(check>>name)
	{
    	if(reguser==name)
		{
    		system("cls");
    		cout<<"\t\t....................................User Already Exist..........................................\n";
    		Sleep(2000);
    		registr();
		}
	}
	//fetching user mobile number
	cout<<"\n\tEnter Your Mobile Number :";
	cin>>ws;
	getline(cin,mobile);
	if(mobile[0] == '\\')
	{
		system("cls");
		main();
	} 
	//checking conditing for mobile number 
	if(mobile.size()!=10)
    {
		system("cls");
		cout<<"\n\t\t\t\t\t\t"<<mobile<<" is Invalid"<<endl;
		Sleep(2000);
		registr();
	}
	for(int i=0;i<mobile.size();i++){
		if(mobile[i]==' '){
			system("cls");
			cout<<"\n\t\t\t\t\t\tNumber Contain Space"<<endl;
			Sleep(2000);
			registr();
		}
	}
    cout<<"\n\tEnter the Password :";
    cin>>ws;
    getline(cin,regpass);
    if(regpass[0] == '\\')
	{
		system("cls");
		main();
	} 
    //checking condition if spcae is there then password will not be consider..........
    for(int l=0;l<regpass.size(); l++)
	{
		    if(regpass[l]==' ')
			{
		    	system("cls");
		    	cout<<"\n\t\t\t\t\t\tInput Password Contain Space"<<endl;
		    	Sleep(2000);
		    	registr();
			}
    }
    //inserting data to file..........
    ofstream reg("data.txt",ios::app);
    reg<<reguser<<' '<<regpass<<' '<<mobile<<endl;
    //..........................................................
    system("cls");
    //adding .txt in last of username   login.txt
    fname= reguser + ".txt";                           
	//creatting file of username      
    ofstream creation(fname.c_str());                        
    cout<<"\n\n\t\t\t\t\t\tRegistration Sucessful!!!\n\n";          
	//closing file         
    creation.close();        
	//closing file                                
    check.close();                       
	//calling main function                    
    main();                                                  
}


//......................................................................................................................................................................................


//function calling
void forgot()                                              
{
    char ch;       
	//clearing screen                                        
    system("cls");                                          
	cout<<"\n\t\t\t\t\t  Forgotten ? We're here for help\n\n";
	cout<<"\tSearch your id by username  --> 1"<<endl;
    cout<<"\n\tSearch your id by password  --> 2"<<endl;
    cout<<"\n\tMain menu                   --> 3"<<endl;
    cout<<"\n\n\t\t  Enter your choice -->";
    cin>>ch;                                             //###########
    switch(ch)
        {
                case '1':
                {
                	    //searching by username
                        int count=0;                                             
                        string searchuser,su,sp,mo,mobile;
                        cout<<"\nTo Back enter: \\"<<endl;
                        cout<<"\nEnter your remembered username --> ";
                        cin>>ws;
                        getline(cin,searchuser);
                        if(searchuser[0] == '\\')
						{
								system("cls");
								forgot();
						}
                        for(int l=0;l<searchuser.size(); l++)
						{
							    if(searchuser[l]==' ')
								{
							    	system("cls");
							    	cout<<"\n\t\t\t\t\t\tInput UserName Contain Space"<<endl;
							    	Sleep(2000);
							    	forgot();
								}
					    }
					    cout<<"\nEnter your Mobile Number --> ";
					    cin>>ws;
					    getline(cin,mobile);
					    if(mobile[0] == '\\')
						{
							system("cls");
							forgot();
						}
                        ifstream searchu("data.txt");
                        //reading data at every spcae
                        while(searchu>>su>>sp>>mo)                                 
                        {
                                if(su==searchuser && mo==mobile)
                                {
                                        count=1;
                                        break;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                Sleep(5000);
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\n\n\t\t\t\t\tSorry, Your userID is not found in our database\n";
    							cout<<"\n\n\t\t\t\tPlease kindly contact your system administrator for more details \n";
                                Sleep(5000);
                                system("cls");
                                main();
                        }
                        break;
                }
                case '2':
                {
                        int count=0;
                        string searchpass,su2,sp2,mo,mobile;
                        cout<<"\nTo Back enter : \\"<<endl;
                        cout<<"\nEnter the remembered password :";
                        cin>>ws;
                        getline(cin,searchpass);
                        if(searchpass[0] == '\\')
						{
							system("cls");
							forgot();
						}
                        for(int l=0;l<searchpass.size(); l++)
						{
							    if(searchpass[l]==' ')
								{
							    	system("cls");
							    	cout<<"\n\t\t\t\t\t\tInput Password Contain Space"<<endl;
							    	Sleep(2000);
							    	forgot();
								}
					    }
                        cout<<"\nEnter your Mobile Number :";
					    cin>>ws;
					    getline(cin,mobile);
					    if(mobile[0] == '\\')
						{
							system("cls");
							forgot();
						}
                        ifstream searchp("data.txt");
                        while(searchp>>su2>>sp2>>mo)
                        {
                                if(sp2==searchpass && mo==mobile)
                                {
                                        count=1;
                                        break;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                Sleep(5000);
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\n\n\t\t\t\t\tSorry, Your Password is not found in our database\n";
    							cout<<"\n\n\t\t\t\tPlease kindly contact your system administrator for more details \n";
                                Sleep(5000);
                                system("cls");
                                main();
                        }
                
                        break;
                }

                case '3':
                {
                	    system("cls");
                        main();
                }
                default:
                        cout<<"\n\n\t\t\t\t    Sorry, You entered wrong choice. Kindly try again";
                        forgot();
        }
}


//.......................................................................................................................................................................................


//function defination
void inserting_file_data(string file_name)
{       
                         
		char k;      
		int y=0,x=0;                                                   
		string user_name,password,fname;        
		fname = file_name + ".txt"; 
		system("cls");
		//asking user what he/se want to add      
		cout<<"\n\t\t\t                         Insert Data\n\n";                    
		cout<<"\n\t\t       Inastagram  --> 1\t\t             FaceBook  --> 2\n\n";
		cout<<"\t\t       Twitter     --> 3\t\t             Linkend   --> 4\n\n";
		cout<<"\t\t       Gmail       --> 5\n\n";
		cout<<"\t\t       Back        --> 7\n\n\n";
		cout<<"\t\t\t                    Enter Your Choice --> ";
		cin>>k;
		//using ofstream because we need to create file if there is not file of that data 
		ofstream insert;       
		//here we are using append function and also we are converting file_name into character if we dont convert than we will face error                                                
		insert.open(fname.c_str(),ios::app);              
		system("cls");
		switch(k)
		{
		case '1':
			cout<<"\nTo Back enter : \\"<<endl;
			cout<<"\nEnter Instagram username-->";
			cin>>ws;
			getline(cin,user_name);
			if(user_name[0] == '\\')
			{
					system("cls");
					inserting_file_data(user_ok);
			}  
			//asking credential                                   
            for(int l=0;l<user_name.size(); l++)
			{                          
		    if(user_name[l]==' ')
			    {
			    	system("cls");
			    	cout<<"\n\t\t\t\t\t\tInput UserName Contain Space"<<endl;
			    	Sleep(2000);
			    	system("cls");
			    	inserting_file_data(user_ok);
			    }
            }                   
			cout<<"\nEnter Instagram Password-->";
			cin>>ws;
			//asking credential
			getline(cin,password); 
			if(password[0] == '\\')
			{
					system("cls");
					inserting_file_data(user_ok);
			}                                             
			for(int l=0;l<password.size(); l++)
			{                          
		    if(password[l]==' ')
			   {
			    	system("cls");
			    	cout<<"\n\t\t\t\t\t\tInput Password Contain Space"<<endl;
			    	Sleep(2000);
			    	system("cls");
			    	inserting_file_data(user_ok);
		       }
		    }
		    //Inserting data
			insert<<"Instagram "<<user_name<<" "<<password<<endl;     
			break;
			
		case '2':
			
			cout<<"\nTo Back enter : \\"<<endl;
			cout<<"\nEnter FaceBook username-->";
			cin>>ws;
			//asking credential
			getline(cin,user_name); 
			if(user_name[0] == '\\')
			{
					system("cls");
					inserting_file_data(user_ok);
			}                                     
            for(int l=0;l<user_name.size(); l++)
			{                          
		    if(user_name[l]==' ')
			    {
			    	system("cls");
			    	cout<<"\n\t\t\t\t\t\tInput UserName Contain Space"<<endl;
			    	Sleep(2000);
			    	system("cls");
			    	inserting_file_data(user_ok);
		        }
			}
			cout<<"\nEnter FaceBook Password-->";
			cin>>ws;
			 //asking credential
			getline(cin,password); 
			if(password[0] == '\\')
			{
					system("cls");
					inserting_file_data(user_ok);
			}                                            
			for(int l=0;l<password.size(); l++)
			{                          
		    if(password[l]==' ')
		     	{
			    	system("cls");
			    	cout<<"\n\t\t\t\t\t\tInput Password Contain Space"<<endl;
			    	Sleep(2000);
			    	system("cls");
			    	inserting_file_data(user_ok);
			    }
		    }
			insert<<"FaceBook "<<user_name<<" "<<password<<endl;
			break;
			
		case '3':
			
			cout<<"\nTo Back enter : \\"<<endl;
			cout<<"\nEnter Twitter username-->";
			cin>>ws;
			//asking credential
			getline(cin,user_name);
			if(user_name[0] == '\\')
			{
					system("cls");
					inserting_file_data(user_ok);
			}                                       
            for(int l=0;l<user_name.size(); l++)
			{                          
		    if(user_name[l]==' ')
				{
			    	system("cls");
			    	cout<<"\n\t\t\t\t\t\tInput UserName Contain Space"<<endl;
			    	Sleep(2000);
			    	system("cls");
			    	inserting_file_data(user_ok);
			    }
			}
			cout<<"\nEnter Twitter Password-->";
			cin>>ws;
			//asking credential
			getline(cin,password);  
			if(password[0] == '\\')
			{
					system("cls");
					inserting_file_data(user_ok);
			}                                             
			for(int l=0;l<password.size(); l++){                          
		    if(password[l]==' '){
		    	system("cls");
		    	cout<<"\n\t\t\t\t\t\tInput Password Contain Space"<<endl;
		    	Sleep(2000);
		    	system("cls");
		    	inserting_file_data(user_ok);
			}
		}
			insert<<"Twitter "<<user_name<<" "<<password<<endl;
			break;
			
		case '4':
			
			cout<<"\nTo Back enter : \\"<<endl;
			cout<<"\nEnter Linkedin username-->";
			cin>>ws;
			//asking credential
			getline(cin,user_name); 
			if(user_name[0] == '\\')
			{
					system("cls");
					inserting_file_data(user_ok);
			}                                     
            for(int l=0;l<user_name.size(); l++)
			{                          
		    if(user_name[l]==' ')
				{
			    	system("cls");
			    	cout<<"\n\t\t\t\t\t\tInput UserName Contain Space"<<endl;
			    	Sleep(2000);
			    	system("cls");
			    	inserting_file_data(user_ok);
			    }
			}
			cout<<"\nEnter Linkedin Password-->";
			cin>>ws;
			//asking credential
			getline(cin,password); 
			if(password[0] == '\\')
			{
					system("cls");
					inserting_file_data(user_ok);
			}                                             
			for(int l=0;l<password.size(); l++)
			{                          
		    if(password[l]==' ')
				{
			    	system("cls");
			    	cout<<"\n\t\t\t\t\t\tInput Password Contain Space"<<endl;
			    	Sleep(2000);
			    	system("cls");
			    	inserting_file_data(user_ok);
				}
		   }
			insert<<"Linkedin "<<user_name<<" "<<password<<endl;
			break;
		
		case '5':
			
			cout<<"\nTo Back enter : \\"<<endl;
			cout<<"\nEnter Gmail username-->";
			cin>>ws;
			//asking credential
			getline(cin,user_name);
			if(user_name[0] == '\\')
			{
					system("cls");
					inserting_file_data(user_ok);
			}                                        
            for(int l=0;l<user_name.size(); l++)
			{                          
			    if(user_name[l]==' ')
					{
				    	system("cls");
				    	cout<<"\n\t\t\t\t\t\tInput UserName Contain Space"<<endl;
				    	Sleep(2000);
				    	system("cls");
				    	inserting_file_data(user_ok);
				    }
			    if(user_name[l]=='@'){
			    	y++;	
				}
				if(user_name[l]=='.'){
					x++;
				}
			}
			if(y!=1 || x!=1){
				system("cls");
				cout<<"\n\t\t\t\t\t\tInput UserName Invalid";
				Sleep(2000);
				inserting_file_data(user_ok);
				
			}
			cout<<"\nEnter Gmail Password-->";
			cin>>ws;
			//asking credential
			getline(cin,password); 
			if(password[0] == '\\')
			{
					system("cls");
					inserting_file_data(user_ok);
			}                                               
			for(int l=0;l<password.size(); l++)
			{                          
		    if(password[l]==' ')
				{
			    	system("cls");
			    	cout<<"\n\t\t\t\t\t\tInput Password Contain Space"<<endl;
			    	Sleep(2000);
			    	system("cls");
			    	inserting_file_data(user_ok);
				}
		    }
			insert<<"Email "<<user_name<<" "<<password<<endl;
			break;
				
		case '7':
			
			system("cls");
			//going to main page again
			login_again();    
			                                                   
		default:
			
			system("cls");
            cout<<"\n\t\t\t\t\t\tEnter Right Code";
            Sleep(2000);
            inserting_file_data(user_ok);
			break;	
	    }
		system("cls");
		 //we are calling this function again ang again to insert data
		inserting_file_data(user_ok);                                    
}


//......................................................................................................................................................................................


//function defination
void reading_file_data(string file_name){                                   //reading whole data

	string word,fname;
	string w_user,w_pass;

	fname = file_name + ".txt";                             
	//opening file in read data only
	ifstream reading;
	reading.open(fname.c_str());  
	//fetching value on every space                                       
	while(reading>>word>>w_user>>w_pass)
	{                        
	//reading instagram data only                
		if(word=="Instagram")
		{                                                
			o[0].name=w_user;
			o[0].u_pass=w_pass;
		}
	//reading facebook data only
		if(word=="FaceBook")                            
		{
			o[1].name=w_user;
			o[1].u_pass=w_pass;
		}
	//reading twitter data only
		if(word=="Twitter")                             
		{
			o[2].name=w_user;
			o[2].u_pass=w_pass;
		}
	//reading Linkedin data only
		if(word=="Linkedin")                           
		{
			o[3].name=w_user;
			o[3].u_pass=w_pass;
		}
		if(word=="Email")
		{
			o[4].name=w_user;
			o[4].u_pass=w_pass;
		}
	}
	system("cls");
	char k;
	cout<<"\n\t\t\t                         Reading Data\n\n";
	cout<<"\n\t\t       Inastagram  --> 1\t\t             FaceBook  --> 2\n\n";
	cout<<"\t\t       Twitter     --> 3\t\t             Linkend   --> 4\n\n";
	cout<<"\t\t       Gmail       --> 5\n\n";
	cout<<"\t\t       Back        --> 7\n\n\n";
	cout<<"\t\t\t                    Enter Your Choice --> ";
	cin>>k;
    //showing data to user..........
	switch(k)
	{
		case '1':
			cout<<"\n\n\n\t\t\t         .................  Instagram Passowrd  ................. \n\n";
			//if data is empty this condition will work 
			if(o[0].name.empty())                                                      
			{
				cout<<"User Name   --->No Data"<<endl;
				cout<<"Password    --->No Data"<<endl;
				cout<<"\n                                         Screen will dissapper in 5 Sec";
			    Sleep(5000);
				break;
			}
			//otherwise this will work
			else                                              
			{
				cout<<"User Name   --->"<<o[0].name;
				cout<<"\nPassword  --->"<<o[0].u_pass;
				url_open(k);
				cout<<"\n                                         Password will dissapper in 15 Sec";
				Sleep(15000);
				break;
			}
			
		case '2':
			
			cout<<"\n\n\n\t\t\t         .................  FaceBook Passowrd  ................. \n\n";
			if(o[1].name.empty())
			{
				cout<<"User Name  --->No Data"<<endl;
				cout<<"Password   --->No Data"<<endl;
				cout<<"\n                                         Screen will dissapper in 5 Sec";
				Sleep(5000);
				break;
			}
			else
			{	
				cout<<"User Name   --->"<<o[1].name;
				cout<<"\nPassword  --->"<<o[1].u_pass;
				url_open(k);
				cout<<"\n                                         Password will dissapper in 15 Sec";
				Sleep(15000);
				break;
			}
			
		case '3':
			
			cout<<"\n\n\n\t\t\t         .................  Twitter Passowrd  ................. \n\n";
			if(o[2].name.empty())
			{
				cout<<"User Name  --->No Data"<<endl;
				cout<<"Password   --->No Data"<<endl;
				cout<<"\n                                         Screen will dissapper in 5 Sec";
			    Sleep(5000);
				break;
			}
			else
			{
				cout<<"User Name   --->"<<o[2].name;
				cout<<"\nPassword  --->"<<o[2].u_pass;
				url_open(k);
				cout<<"\n                                         Password will dissapper in 15 Sec";
				Sleep(15000);
				break;
			}
			
		case '4':
			
			cout<<"\n\n\n\t\t\t         .................  Linkedin Passowrd  ................. \n\n";
			if(o[3].name.empty())
			{
				cout<<"User Name  --->No Data"<<endl;
				cout<<"Password   --->No Data"<<endl;
				cout<<"\n                                         Screen will dissapper in 5 Sec";
			    Sleep(5000);
				break;
			}
			else
			{
				cout<<"User Name   --->"<<o[3].name;
				cout<<"\nPassword  --->"<<o[3].u_pass;
				url_open(k);
				cout<<"\n                                         Password will dissapper in 15 Sec";
				Sleep(15000);
				break;
			}
			
		case '5':
			
			cout<<"\n\n\n\t\t\t         .................  Email Passowrd  ................. \n\n";
			if(o[4].name.empty())
			{
				cout<<"User Name  --->No Data"<<endl;
				cout<<"Password   --->No Data"<<endl;
				cout<<"\n                                         Screen will dissapper in 5 Sec";
			    Sleep(5000);
				break;
			}
			else
			{
				cout<<"User Name   --->"<<o[4].name;
				cout<<"\nPassword  --->"<<o[4].u_pass;
				url_open(k);
				cout<<"\n                                         Password will dissapper in 15 Sec";
				Sleep(15000);
				break;
			}
			
			
		case '7':
			
			reading.close();
			system("cls");
			login_again();
			break;
			
		default:
			
			cout<<"\n\n\t\t\t\t\t\tEnter Right Code.......";
			break;		
	}
	reading_file_data(user_ok);
}


//......................................................................................................................................................................................


//defining a function which carry urls and open when user input code
void url_open(char k){              

    //Instagram Url                                             
	string I = "start https://www.instagram.com/?hl=en"; 
	//twitter url                        
	string T = "start https://twitter.com/login?lang=en";     
	//facebook url                   
	string F = "start https://www.facebook.com/";       
	//gmail url
	string G = "start https://accounts.google.com/signin/v2/identifier?flowName=GlifWebSignIn&flowEntry=ServiceLogin";
	//linkedin url                         
	string L = "start https://www.linkedin.com/login";                                    
	//          ^^^^    
	
	//One Important thing we have to use "start" in front of url to avoide error 
	switch(k)
	{                              
		case '1':
			
			cout<<"\n                                         Opening Instagram Login Page"<<endl;
			Sleep(3000);
			//syntex to open url here if we dont use start it will give error
			system(I.c_str());                                                    
			break;
			
		case '2':
			
			cout<<"\n                                         Opening FaceBook Login Page"<<endl;
			Sleep(3000);
			system(F.c_str());
			break;
			
		case '3':
			
			cout<<"\n                                         Opening Twitter Login Page"<<endl;
			Sleep(3000);
			system(T.c_str());
			break;
			
		case '4':
			
			cout<<"\n                                         Opening Linkened Login Page"<<endl;
			Sleep(3000);
			system(L.c_str());
			break;
			
		case '5':
			
			cout<<"\n                                         Opening Google Login Page"<<endl;
			Sleep(3000);
			system(G.c_str());
			break;
			
		default:
			
			break;			
	}
}
 

//.......................................................................................................................................................................................


void login_again(){
	
	    system("cls"); 
		cout<<"\t\t****************************Hello!!"<<user_ok<<" LOGIN SUCCESSFUL!****************************\n\n";     
		cout<<"\t\t                           Hello!!"<<user_ok <<" What you want to do\n"<<endl;
		int i;
		cout<<"\t\t\tInsert Data  --> 1                            ";                               
		cout<<"Read Data    --> 2"<<endl;
		cout<<"\n\n\t\t\tLogout       --> 3                            ";
		cout<<"EXIT         --> 4"<<endl;
		cout<<"\n\n\t\t\t\t\t  Enter your choice -->  ";
		cin>>i;
		system("cls");
			switch(i)
			{        
			    //applying switch case according to user need                                                              
		        case 1:         
				//calling inserting_data function        
			        inserting_file_data(user_ok);                                     
			        break;
			        
		        case 2:
		        	
		        //calling reading_data function
			        reading_file_data(user_ok);                                       
			        break; 
			        
			    case 3:
			    	
			    	//clearing screen
			    	system("cls"); 
					//calling main function                                                
			    	main(); 
					                                                      
		        case 4:
		        	
		        	system("cls");
		        	//closing programm
		        	cout<<"Thanks for using this program!!\n";                    
			        exit(0);    
					break; 
					                            
		        default:
		        	
		        	//clearing screen
			        system("cls");                                           
			        cout<<".................................................Enter Right Code.................................................\n";
			        //calling main function again (its a recursion function)
			        main();                                                
	        }	
		main();
}
