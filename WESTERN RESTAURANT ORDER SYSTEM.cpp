#include <iostream>
#include <string.h>
#include <Windows.h>
#include <unistd.h>
using namespace std;

//FUNTION PROTOTYPE
string getName();
long getnoPhone();
string getAddress();
void displayMenu();
float calcTotalMeal();
float calcTotalBev();
float calcTotalAll (float, float);
void displayReceipt(string, long, string, float, float, float);

//MAIN FUNCTION
int main(){
	//DECLARATION OF VARIABLE
	string name, address;
	int mealCode, mealQty, bevQty;
	long noPhone;
	char bevCode, answer;
	float totalMeal, totalBev, totalAll;
	
	do
	{
		//FUCNTION CALL
		name = getName();
		
		noPhone = getnoPhone();
		
		address = getAddress();
		
		sleep(3);        //SYSTEM WILL PAUSE FOR 3 SECONDS
		system("cls");   //SYSTEM WILL CLEAR SCREEN
		
		displayMenu();
	
		totalMeal = calcTotalMeal();
	
		totalBev = calcTotalBev();
	
		totalAll = calcTotalAll (totalMeal, totalBev);
	
		displayReceipt(name, noPhone, address, totalMeal, totalBev, totalAll);
	
		cout << endl;
		cout << "\nDo you want to order again? (ENTER Y OR N): ";    //USER WILL ENTER WHETHER THEY WANT TO ORDER AGAIN OR NOT
		cin >> answer;
		
		sleep(3);
		system("cls");
	
	} while (answer == 'Y' || answer == 'y');
	
	cout << "\nTHANK YOU SO MUCH FOR ORDERING <3 PLEASE WAIT FOR YOUR MEAL !" << endl;
	cout << "DON'T WORRY IT WON''T BE LONG !";
	
	return 0;
}

//FIRST FUNCTION : TO GET NAME FROM THE USER
string getName()
{
	string name;
	
	cout << "** PLEASE FILL IN YOUR INFORMATION **" << endl;
	cout << "Please enter your name: ";
	cin >> ws;
	getline(cin, name);
	
	return name;
}

//SECOND FUNCTION : TO GET PHONE NUMBER FROM THE USER
long getnoPhone()
{
	long noPhone;
	
	cout << "\nPlease enter your phone number (EXAMPLE: 0123456789): ";
	cin >> noPhone;
	
	return noPhone;
}

//THIRD FUNCTION : TO GET ADDRESS FROM THE USER
string getAddress()
{
	string address;
	
	cout << "\nPlease enter your full address: ";
	cin >> ws;
	getline(cin, address);
	
	return address;	
}	

//FOURTH FUNCTION : TO DISPLAY MENU
void displayMenu()
{
	cout << "\n               WELCOME TO OUR FINEST WESTERN RESTAURANT ALA GORSON RAMSAY" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "|                                        FOODS                                   |" << endl;
	cout << "|--------------------------------------------------------------------------------|" << endl;
	cout << "|1 - Spaghetti Bolognese     |  RM 13.00" << "    |   " << "4 - Rib Eye Stick  |   RM 15.00  |" << endl;
	cout << "|2 - Lasagna                 |  RM 15.00" << "    |   " << "5 - Roasted Beef   |   RM 20.00  |" << endl;
	cout << "|3 - Chicken Grill           |  RM 15.00" << "    |   " << "6 - Chicken Fillet |   RM 25.00  |" << endl;
	cout << "|--------------------------------------------------------------------------------|";
	cout << "\n|                                      DRINKS                                    |   " << endl;
	cout << "|--------------------------------------------------------------------------------|" << endl;
	cout << "| S - Syrup                  |  RM 1.50                                          |" << endl;
	cout << "| L - Lychee                 |  RM 2.80                                          |" << endl;
	cout << "| C - Coconut                |  RM 3.50                                          |" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
}

//FIFTH FUNCTION : TO CALCULATE TOTAL PRICE OF MEALS BASED ON THE MEALCODE ENTERED BY USER
float calcTotalMeal()
{
	float totalMeal, totalAllMeal = 0;
	int mealCode, mealQty;
	char answerMeal = 'Y';
	
	while (answerMeal == 'Y' || answerMeal == 'y')
	{
		cout << endl;
		cout << "Enter meal code based on the table above: ";
		cin >> mealCode;
		cout << "Meal Quantity: ";
		cin >> mealQty;
	
		if (mealCode == 1)
    	totalMeal = mealQty * 13.0;

		else if (mealCode == 2)
    	totalMeal = mealQty * 15.0;
    	
    	else if (mealCode == 3)
    	totalMeal = mealQty * 15.0;
    
    	else if (mealCode == 4)
    	totalMeal = mealQty * 15.0;
   		 
   		else if (mealCode == 5)
    	totalMeal = mealQty * 20.0;
   			
   		else if (mealCode == 6)
    	totalMeal = mealQty * 25.0;
        
    	else
		cout << "Invalid meal code !" << endl;
		
		totalAllMeal = totalAllMeal + totalMeal;
		
		cout << "Do you want to add more meals? (ENTER Y OR N): ";
		cin >> answerMeal;
	}
	
	return totalAllMeal;		 
}

//SIXTH FUNCTION : TO CALCULATE THE TOTAL PRICE OF BEVERAGE BASED ON THE BEVERAGE CODE ENTERED BY USER
float calcTotalBev()
{
	float totalBev, totalAllBev = 0;
	char bevCode, answerDrinks = 'Y';
	int bevQty;
	
	while (answerDrinks == 'Y' || answerDrinks == 'y')
	{
		cout << endl;
		cout << "Enter beverage code based on the table above: ";
		cin >> bevCode;
		cout << "Beverage Quantity: ";
		cin >> bevQty;
	
		if (bevCode == 'S' || bevCode == 's')
    	totalBev = bevQty * 1.50;
    
   		else if (bevCode == 'L' || bevCode == 'l')
		totalBev = bevQty * 2.80;
    
    	else if (bevCode == 'C' || bevCode == 'c')
    	totalBev = bevQty * 3.50;

		else
		cout << "Invalid beverage code !" << endl;
		
		totalAllBev = totalAllBev + totalBev;
		
		cout << "Do you want to add more drinks? (ENTER Y OR N) : ";
		cin >> answerDrinks;
	}
	
	return totalAllBev;	
}

//SEVENTH FUNCTION : TO CALCULATE THE TOTAL PRICE OF MEALS AND BEVERAGES
float calcTotalAll (float totalAllMeal, float totalAllBev)
{
	float totalAll;
	
	totalAll = totalAllMeal + totalAllBev;
	
	cout.setf(ios::fixed);
	cout.precision(2);
	
	return totalAll;
}

//EIGHTH FUNCTION : TO DISPLAY RECEIPT
void displayReceipt(string name, long noPhone, string address, float totalAllMeal, float totalAllBev, float totalAll)
{
	system("cls");
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "                                    RECEIPT                                      " << endl;
	cout << "---------------------------------------------------------------------------------";
	cout << "\nName                   : " << name;
	cout << "\nTelephone Number       : " << noPhone;
	cout << "\nAddress                : " << address;
	cout << "\nTotal Meal Price       : RM " << totalAllMeal;
	cout << "\nTotal Beverage Price   : RM " << totalAllBev;
	cout << "\nTotal All              : RM " << totalAll;
	cout << "\n----------------------------------------------------------------------------------" << endl;
}


