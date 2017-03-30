#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<string>

using namespace std;
void Read_data(string [], float [][4]);//function prototype
void Print_report(string [],float [], float  [],float , float);//function prototype

int main()
{
	string storename_array[4];
	float storesales_array[4][4];
	float total_sales_per_storearray[4]={0.0,0.0,0.0,0.0};//initializes the array
	float average_sales_perstorearray[4]={0.0,0.0,0.0,0.0};
	float totalsales =0.0;
	float average_totalsales=0.0;
	Read_data(storename_array, storesales_array);//calls the read data function
	for(int row=0;row<4;row++)//for loop to add the sales
	{
		for(int col=0;col<4;col++)//for loop to add the sales
		{
			total_sales_per_storearray[row]=total_sales_per_storearray[row]+storesales_array[row][col];//adds up the total sales per store
			average_sales_perstorearray[row]=total_sales_per_storearray[row]/4;//calculates the average sales per store
			totalsales=totalsales+total_sales_per_storearray[row];//calculates the total sales of all sales
		}
	}
	average_totalsales=totalsales/4;//takes the average of total sales
	Print_report(storename_array,total_sales_per_storearray,average_sales_perstorearray,totalsales,average_totalsales);
	return 0;
}
void Read_data(string store_namearray[], float store_salesarray[][4])//function to read the data from the file
{
	char dummie;
	ifstream infile;
	infile.open("assn247_a.txt");//opens the file
	while(infile)//while loop to read the file
	{
		for(int row=0;row<4;row++)//for loop to read the names
		{
			infile>>store_namearray[row];//reads the store names and stores it an array
			for(int col=0;col<4;col++)//for loop to read the store sales
			{
				infile>>store_salesarray[row][col];//reads the store values and stores it a multidimensional array
			}
		}
		infile.get(dummie);
	}
}

void Print_report(string name[], float total_sales_perstore[], float average_perstore [],float total_sales, float average_total_sales)//function to print the report
{
	     
  cout<<"       ANNUAL SALES REPORT"<<endl<<endl;//prints heading
  cout<<"Date - 05/03/10"<<endl<<endl;//prints date
  cout<<"STORE                TOTAL             AVERAGE"<<endl;//prints heading
  cout<<" NAME                SALES               SALES"<<endl<<endl;//prints heading
  cout<<name[0]<<"         $ "<<total_sales_perstore[0]<<"         $"<<average_perstore [0]<<endl;//prints name and sales
  cout<<name[1]<<"          $ "<<total_sales_perstore[1]<<"          $"<<average_perstore [1]<<endl;//prints name and sales
  cout<<name[2]<<"           $ "<<total_sales_perstore[2]<<"         $"<<average_perstore [2]<<endl;//prints name and sales
  cout<<name[3]<<"       $ "<<total_sales_perstore[3]<<"          $"<<average_perstore [3]<<endl<<endl;//prints name and sales
  cout<<"TOTAL              $"<<total_sales<<endl<<endl;//prints total sales
  cout<<"AVERAGE            $"<<average_total_sales<<endl;//prints average sales
  cout<<"PER STORE"<<endl;
}
/*       ANNUAL SALES REPORT

Date - 03/29/17

STORE                TOTAL             AVERAGE
 NAME                SALES               SALES

Washington         $ 79677.3         $19919.3
Baltimore          $ 232555          $58138.7
Richmond           $ 11299.7         $2824.91
Jacksonville       $ 176116          $44029.1

TOTAL              $1.2943e+006

AVERAGE            $323575
PER STORE */

