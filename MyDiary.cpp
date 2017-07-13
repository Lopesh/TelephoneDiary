#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string>
#include<ctype.h>
#include<fstream>
#include<cstdlib>

using namespace std;

class TelephoneDiary{
	int x,y;
	private:
		 
		char Name[20];
		char MainName[20];
		char PhoneNumber[20]; 
		char MainPhoneNumber[20];
		int count,count1,count2; 
		 
	
	public:
		
		TelephoneDiary(){
			count=0;
			count1=0;
			count2=1;
		}
		
		
		bool contains_number(const std::string &c)
		{
		    return (
		        c.find('0') != std::string::npos ||
		        c.find('1') != std::string::npos ||
		        c.find('2') != std::string::npos ||
		        c.find('3') != std::string::npos ||
		        c.find('4') != std::string::npos ||
		        c.find('5') != std::string::npos ||
		        c.find('6') != std::string::npos ||
		        c.find('7') != std::string::npos ||
		        c.find('8') != std::string::npos ||
		        c.find('.') != std::string::npos ||
		        c.find('9') != std::string::npos
		    );
		}
		
		bool is_digits(const std::string &str)
		{
    		return str.find_first_not_of("0123456789") == std::string::npos;
		}

		
		static void gotoxy(short x, short y) {
			COORD pos = {x, y};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		
		void Addition(){
		//==========================================================================
			
		//						Input Section is here
			
		//==========================================================================
			x=16,y=19;
			gotoxy(x,y); 
			cout<<"  Insert Following Value:\n ";
			x=16,y=21;
			gotoxy(x,y); 	
			cout<<"  Name         : ";
			x=16,y=23;
			gotoxy(x,y);
			cout<<"  Phone Number : ";
			x=35,y=21;
			gotoxy(x,y);
			cin>>Name;
			 
		//==========================================================================
			
		//						Name Validation  is here
			
		//==========================================================================
			if(strlen(Name)<=10){
			
					for(int i=0;i<=strlen(Name);i++){
						if(!contains_number(Name)){
							     		 	 
							  strcpy(MainName,Name);
							  count=0; 
						} 
						else{ 
							x=40,y=21;
							gotoxy(x,y);
							cout<<"  Invalid Name ";
							count=1;
						} 
				}
			}
			else{  
						gotoxy(x,y);
						cout<<"   Name Should with in 10 character ";
						count=1; 
			}
		//==========================================================================
			
		//						Phone Validation  is here
			
		//==========================================================================
			x=35,y=23;
			gotoxy(x,y);
			cin>>PhoneNumber;
			
			if(strlen(PhoneNumber)>10 || strlen(PhoneNumber)<10){
				x=45,y=23;
				gotoxy(x,y);
				cout<<"  Number Should be 10 Digit";
				count1=1;
			} 
			else if(strlen(PhoneNumber)==10){
				for(int i=0;i<=strlen(PhoneNumber);i++){
					
					if(is_digits(PhoneNumber)){
						strcpy(MainPhoneNumber,PhoneNumber); 
						count1=0;
					}	
					else{
						x=40,y=23;
						gotoxy(x,y);
						cout<<"  Invalid Number";
						count1=1; 
					} 
				} 
			} 
			
			if(count1==1){
				x=30,y=28;
				gotoxy(x,y);
				cout<<"  You Not Enter Number Properly "; 
			}
			
			if(count==1){
				x=30,y=26;
				gotoxy(x,y);
				cout<<"  You Not Enter Name Properly ";
				
			}
			else if(count==0 && count1==0){ 
			
				ofstream obj;
				obj.open("TelephoneDiary.txt",ios::out | ios::app); 
				obj<<MainName<<"\t\t"<<MainPhoneNumber<<endl<<endl; 
				obj.close();
				x=18,y=26;
				gotoxy(x,y);
				cout<<"Data Inserted Successfully ! ! ! ! !"; 
			} 
		} 
		//==========================================================================
			
		//						ReadData Function is here
			
		//==========================================================================
		
		void ReadData(){
			
		 	ifstream readData;
		 	readData.open("TelephoneDiary.txt",ios::in);
		 	int m=1;
		 	string line;
		 	
				while(!readData.eof()){ 
				
					getline (readData,line);
      				cout <<"\t\t"<< line <<"\n";  
      				m++;  
				} 
			readData.close();  
		}
		
		//==========================================================================
			
		//						DisplayData Function is here
			
		//==========================================================================
		
		void DisplayData(){
			int c=1;
			ifstream in;
			in.open("TelephoneDiary.txt");
			string Data;
			cout<<"\n\t\tFor Searching Enter Record:\n";
			cout<<"\n\t\tEnter Name : ";
			cin>>Data;
			string myline;
			x=16,y=23;
			while (getline(in, myline)) {
			        if (myline.find(Data) != string::npos) {
			        	gotoxy(x,y);
			            cout << myline << endl;
			        }   
			}
			in.close(); 
		}
		
		void DeleteData(){
			ifstream fin;
			fin.open("TelephoneDiary.txt");
			string h,line;
			ofstream temp;
			temp.open("TelephoneDiary.txt");
			cout<<"Which Name you want to Delete"<<endl;
			cout<<"Name: ";
			cin>>h;
			while (getline(fin,line))
			{
			    line.replace(line.find(h),h.length(),"");
			    temp << line << endl;
			
			} 
		}
			
}; 

int main(){
	int x=10,y=10;
	TelephoneDiary diary;
	int input;
	cout<<"\t\tTelephone Diary\n";
	cout<<"\t\t--------- -----";
	cout<<"\n\n\n";
	cout<<"\t\t=====================\n";
	cout<<"\t\t| 1. ADD RECORD     |\n";
	cout<<"\t\t|                   |   \n";
	cout<<"\t\t| 2. DISPLAY RECORD |\n";
	cout<<"\t\t|                   |   \n";
	cout<<"\t\t| 3. DELETE RECORD  |\n";
	cout<<"\t\t|                   |   \n";
	cout<<"\t\t| 4. SEARCH RECORD  |\n";
	cout<<"\t\t|                   |   \n";
	cout<<"\t\t| 0. EXIT           |\n";
	cout<<"\t\t|                   |   \n";
	cout<<"\t\t=====================";
	cout<<"\n\n\t\tEnter Your Number: ";
	cin>>input;
	
	switch(input){ 
				case 1: 
						diary.Addition();				
			 		break;
			 		
			 	case 2:
				 		diary.ReadData();
				 	break;
				
				case 3:
						 diary.DeleteData();
					break; 	
				case 4:
						diary.DisplayData();
					break;	
				case 0:
						cout<<"\n\n\t\tThe Application Are Exiting ! ! ! ";
						  exit(0);
					break;	
				default:
						cout<<"\n\n\t\tInvalid Input";
					break; 
	} 
	cout<<"\n\n\n";
	return 0;
}
