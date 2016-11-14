#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

main(){
	string baris;
	bool flag1, flag2;
	int jumlah_baris;
	jumlah_baris = 0;
	
    //Check Jumlah baris
	ifstream data_file("input.txt");
    while (data_file.good ())
	{
        getline(data_file, baris);
        if (baris=="")
        {
            cout << "Jumlah baris "<<jumlah_baris<<endl;
            jumlah_baris=0;
        }
        else 
        {
            ++jumlah_baris;
        }
        
        if(jumlah_baris>1){        	
        	ofstream data_file("output.txt");
			while(data_file.is_open()){
				data_file<<"error";
				data_file.close();	
			}
			exit(0);
		}
		else{
			flag1=true;
		}
        
	}
	
	//Persamaan angka ajaib
	if(flag1==true){
		int n, i, rumus, firstn, secondn;
		
		ifstream data_file("input.txt");
		if(data_file.is_open()){
		while (getline(data_file,baris)){
			
			flag2 = (baris.find_first_not_of( "0123456789" ) == string::npos);

			if(flag2==true){
				
				n=atoi(baris.data());
			
				if(n>=0&&n<=10000){
					i=100;
				}
				else if(n>10000&&n<=100000){
					i=1000;
				}
				else if(n>100000&&n<=1000000){
					i=10000;
				}
				else if(n>1000000&&n<=10000000){
					i=100000;
				}
				else if(n>10000000&&n<=100000000){
					i=1000000;
				}
				else if(n>100000000&&n<=1000000000){
					i=10000000;
				}
				else if(n>1000000000&&n<=10000000000){
					i=100000000;	
				}
				else if(n>10000000000&&n<=100000000000){
					i=1000000000;
				}
				
				rumus=(((n/i)+(n%i))*((n/i)+(n%i)));
			
				if(rumus==n){
				
					firstn=(n/i);
					secondn=(n%i);
				
					//convert int to string
					string firstnconvert;
					ostringstream convertfirstn;	
					convertfirstn << firstn;	
					firstnconvert = convertfirstn.str();
				
					string secondnconvert;
					ostringstream convertsecondn;	
					convertsecondn << secondn;	
					secondnconvert = convertsecondn.str();
					
					int P_data=baris.length();
					int P_firstn=firstnconvert.length();
					int P_secondn=secondnconvert.length();
					string check1,check2;
	
					check1.append(firstnconvert);
					check1.append(secondnconvert);

					string afterzero;
					
					if(baris!=check1){
						afterzero.append(baris,P_firstn,(P_data-P_firstn-P_secondn));
						afterzero.append(secondnconvert);

						if(firstnconvert.length()%2==0){
							if(afterzero.length()%2==0){
								cout<<firstnconvert<<", "<<"dan "<<afterzero;
							
								ofstream data_file("output.txt");
							
								if(data_file.is_open()){
									data_file<<firstnconvert<<", "<<"dan "<<afterzero;
									data_file.close();
								}
							}
							
							else{
								cout<<"Tidak dapat menulis";
							}
						}	
					}
					
					else{
						if(firstnconvert.length()%2==0){
							if(secondnconvert.length()%2==0){
								cout<<firstnconvert<<", "<<"dan "<<secondnconvert;
							
								ofstream data_file("output.txt");
							
								if(data_file.is_open()){
									data_file<<firstnconvert<<", "<<"dan "<<secondnconvert;
									data_file.close();
								}
							}
							
							else{
								cout<<"Tidak dapat menulis";
							}
						}
					}
									
				}
				else{
					cout<<"Bukan angka ajaib!";
				}
			}
			else{
				ofstream data_file("output.txt");
				while(data_file.is_open()){
					data_file<<"error";
					data_file.close();					
				}
			}
			
		}
		}
	}
	
}

