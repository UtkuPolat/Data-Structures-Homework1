#include <iostream>
#include <string>
#include <fstream>
#include "header.h"
using namespace std;
class Node{
	public:
		string distinct;                             				/*City of distinct names*/
		int p1,p2,p3;												/*Number of votes for distinct*/
		
		friend istream& operator>>(istream &,Node &);
		friend ostream& operator<< (ostream& ,Node& );
		bool operator== (Node& item);
};
istream& operator>>(istream &nis,Node &obj)
{
	nis>>obj.distinct>>obj.p1>>obj.p2>>obj.p3;
	return nis;
}
ostream& operator<<(ostream &nos,Node &obj)
{
	nos<<obj.distinct<<" "<<obj.p1<<" "<<obj.p2<<" "<<obj.p3<<" ";
}
bool Node::operator== (Node& item)
	{
		if(item.distinct==this->distinct)
		 {
		 	return 1;
		 }
		else
			return 0;
	}
class City{
	public:
		string cityname;											/*City names*/
		int P1,P2,P3;												/*Total votes for each party*/
		LL<Node> area;												/*Holds the city's distinct's names and number of votes for each party*/
		
		City(){
			P1=P2=P3=0;
		}
		~City(){}
		void setCity(string name)
		{
			cityname=name;
		}
		friend ostream& operator<<(ostream &,City &);
};
ostream& operator<< (ostream& os,City& obj)
{
	os<<obj.cityname<<" "<<obj.P1<<" "<<obj.P2<<" "<<obj.P3<<endl;
	return os;
}
istream& operator>> (istream& is,City& obj)
{
	is>>obj.cityname>>obj.P1>>obj.P2>>obj.P3;
	return is;
}
int main(){
	City Election[3];                                             /*Array for three city*/
	
	Election[0].cityname="Ankara";
	Election[1].cityname="Istabul";
	Election[2].cityname="Izmir";
	
	Node saver;													/*To create link list from textfile*/
	string s1;													/*Read an city name from textfile*/

	ifstream list("list.txt");
	list>>s1;

	while(!list.eof())
	{
		if(s1=="Ankara")
		{
			list>>saver;
			Election[0].area.insertLast(saver);
			
			Election[0].P1+=saver.p1;
			Election[0].P2+=saver.p2;
			Election[0].P3+=saver.p3;
		}
		else if(s1=="Istanbul")
		{
			list>>saver;
			Election[1].area.insertLast(saver);
			
			Election[1].P1+=saver.p1;
			Election[1].P2+=saver.p2;
			Election[1].P3+=saver.p3;
		}
		else if(s1=="Izmir")
		{
			list>>saver;
			Election[2].area.insertLast(saver);
			
			Election[2].P1+=saver.p1;
			Election[2].P2+=saver.p2;
			Election[2].P3+=saver.p3;
		}
		list>>s1;
	}
	string choice;												
	string name;
	do{
		cout<<"List"<<"  |  "<<"District"<<"  |  "<<"City"<<"  |  "<<"Quit"<<endl;
		
		cout<<"Enter your choice of action:";
		cin>>choice;
		if(choice=="List" || choice=="list")
		{
			cout<<"Enter city name:";
			cin>>name;
			if(name=="Ankara")
			{
				cout<<"City:"<<Election[0].cityname;
				cout<<" District:"<<Election[0].area;
				cout<<endl;
			}
			else if(name=="Istanbul")
			{
				cout<<"City:"<<Election[1].cityname;
				cout<<" District:"<<Election[1].area;
				cout<<endl;
			}
			else if(name=="Izmir")
			{
				cout<<"City:"<<Election[2].cityname;
				cout<<" District:"<<Election[2].area;
				cout<<endl;
			}
		}
		
		else if(choice=="District" || choice=="district")
		{
			cout<<"Enter district name:";
			Node save;                                        /*To read a linklist(distinct and p1,p2,p3) from textfile*/
			
			cin>>save.distinct;
			
			for(int i=0;i<3;i++){
				int max;
				if(Election[i].area.search(save)!=NULL)
				{
					
					node<Node> *ptr;						
					ptr=Election[i].area.search(save);
					max=ptr->info.p1;
					
					if(ptr->info.p1 < ptr->info.p2 && ptr->info.p2>ptr->info.p3)
					{
						max=ptr->info.p2;
						cout<<"In "<<save.distinct<<"-"<<Election[i].cityname<<" "<<"Party 2 won with "<<" won with "<<max<<" votes"<<endl;
					}
					else if(ptr->info.p1 < ptr->info.p3 && ptr->info.p3>ptr->info.p2)
					{
						max=ptr->info.p3;
						cout<<"In "<<save.distinct<<"-"<<Election[i].cityname<<" "<<"Party 3 won with "<<max<<" votes"<<endl;
					}
					else
					{
						cout<<"In "<<save.distinct<<"-"<<Election[i].cityname<<" "<<"Party 1 won with "<<max<<" votes"<<endl;
					}							
				}
				
			}
			
			
		}
		else if(choice=="City" || choice=="city")
		{
			string city1;
			if(choice=="City" || choice=="city"){
			cout<<"Enter city name: ";
			cin>>city1;
			if(city1==Election[0].cityname)
			{
				if(Election[0].P1>Election[0].P2 && Election[0].P1>Election[0].P3)
				{
					cout<<Election[0].cityname<<" Party1 won with "<<Election[0].P1<<" votes"<<endl;
				}
				else if(Election[0].P2>Election[0].P1 && Election[0].P2>Election[0].P3)
				{
					cout<<Election[0].cityname<<" Party2 won with "<<Election[0].P2<<" votes"<<endl;
				}
				else if(Election[0].P3>Election[0].P1 && Election[0].P3>Election[0].P2)
				{
					cout<<Election[0].cityname<<" Party3 won with "<<Election[0].P3<<" votes"<<endl;
				}
			}
			if(city1==Election[1].cityname)
			{
				if(Election[1].P1>Election[1].P2 && Election[1].P1>Election[1].P3)
				{
					cout<<Election[1].cityname<<" Party1 won with "<<Election[1].P1<<" votes"<<endl;
				}
				else if(Election[1].P2>Election[1].P1 && Election[1].P2>Election[1].P3)
				{
					cout<<Election[1].cityname<<" Party2 won with "<<Election[1].P2<<" votes"<<endl;
				}
				else if(Election[1].P3>Election[1].P1 && Election[1].P3>Election[1].P2)
				{
					cout<<Election[1].cityname<<" Party3 won with "<<Election[1].P3<<" votes"<<endl;
				}
			}
			if(city1==Election[2].cityname)
			{
				if(Election[2].P1>Election[2].P2 && Election[2].P1>Election[2].P3)
				{
					int max=Election[2].P1;
					cout<<Election[2].cityname<<" Party1 won with "<<Election[2].P1<<" votes"<<endl;
				}
				else if(Election[2].P2>Election[2].P1 && Election[2].P2>Election[2].P3)
				{
					cout<<Election[2].cityname<<" Party2 won with "<<Election[2].P2<<" votes"<<endl;
				}
				else if(Election[2].P3>Election[2].P1 && Election[2].P3>Election[2].P2)
				{
					cout<<Election[2].cityname<<" Party3 won with "<<Election[2].P3<<" votes"<<endl;
				}
			}
		  }
		}
	}while(choice!="Quit" && choice!="quit");
	
	return 0;
}
