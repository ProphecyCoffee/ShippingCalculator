#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>  
// brings the transform word
using namespace std;
// header filename constants:
// 

const string INFILENAME = "Order.txt";
const string OUTFILENAME = "Order.txt";

// pricing constants:
// initial fees
// 
// shipping fees added onto overall total (with the users inputed order total):
const double USA_LOW_SHIPPING_FEE = 6.00, USA_MID_SHIPPING_FEE = 9.00, USA_HIGH_SHIPPING_FEE = 12.00, //usa
CAN_LOW_SHIPPING_FEE = 8.00, CAN_MID_SHIPPING_FEE = 12.00, CAN_HIGH_SHIPPING_FEE = 15.00, // canada
AUS_LOW_SHIPPING_FEE = 10.00, AUS_MID_SHIPPING_FEE = 14.00, AUS_HIGH_SHIPPING_FEE = 17.00, // Australia
MARS_LOW_SHIPPING_FEE = 20'000.00, MARS_MID_SHIPPING_FEE = 300'000.00, MARS_HIGH_SHIPPING_FEE = 700'000.00, // Australia	

FRAGILE_FEE = 2.00; // adds fragile fee to  overall total with the users inputed order total and shipping fees (if fragile)

// Order Totals 
const double ORDER_TOTAL_LOW = 50.00, ORDER_TOTAL_MID = 100.00, ORDER_TOTAL_PRICEY = 150.00; // pricing for comparing with user input.
const string ORDER_TOTAL_FREE = "Free"; // This is for free shipping.
// country type constants																						
const string USA = "USA", CAN = "CAN", AUS = "AUS", MARS = "MARS";
// yes or no 'y' and 'n' constants
const string YES = "Y", NO = "N";


//main
int main()
{
	//  vars
	ofstream outData; // out data stream object.
	double shippingCostNotTotal = 0.00;
	double preTotal = 0.00;		// the total amount that is gained from the user input.
	double postTotal = 0.00;	// this total amount that will be calculated after shipping fees (and fragile if selected) is added.
	string itemName;			// the item they are order.
	string fragile;				// yes or no (y or n) input
	string destination;			// aus/usa/can input


	//opening output file
	outData.open(OUTFILENAME);
	if (!outData) { // the file checker thingy from vid
		cout << "Error in opening the file:" << endl;
		return 1;
	}

	//***********************************
	//    The heading for the  program:
	cout << setw(51) << setfill('.') << '\n';
	cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
	cout << setw(51) << setfill('.') << '\n';
	// for outfile
	outData << setw(51) << setfill('.') << '\n';
	outData << "ITCS 2530 - Programming Assignment for week #3" << endl;
	outData << setw(51) << setfill('.') << '\n';
	//**********************************************
	// spacing between heading and user prompt lines
	cout << endl;
	cout << endl;
	// for outFile
	outData << endl;
	outData << endl;
	//************
	// user prompt  (out file at bottom of program) for this part
	cout << "Please enter the item name (no space)" << setw(13) << setfill('.') << ":";
	cin >> itemName; 																		// user inputs item name, the line ends.
	outData << "Please enter the item name (no space)" << setw(13) << setfill('.') << ":" << itemName << "\n";
	cout << "Is the item fragile? (y=yes/n=no)" << setw(17) << setfill('.') << ":";
	cin >> fragile;
	// user inputs 'y'/'n' for fragile, line ends.
	transform(fragile.begin(), fragile.end(), fragile.begin(), ::toupper); // changes fragile input to upper case

	outData << "Is the item fragile? (y=yes/n=no)" << setw(17) << setfill('.') << ":" << fragile << "\n";
	if (fragile != YES && fragile != NO) { // out data is here for this part
		cout << "\n" << "Invalid entry, exiting";
		outData << "\n" << "Invalid entry, exiting";
		return 0;
	}
	// exits the program if fragile input
	//is invalid

	cout << "Please enter your order total" << setw(21) << setfill('.') << ":";
	cin >> preTotal;
	// user inputs preTotal, the line ends.

	outData << "Please enter your order total" << setw(21) << setfill('.') << ":" << preTotal << "\n";
	cout << "Please enter destination. (usa/can/aus/mars)" << setw(11) << setfill('.') << ":";
	cin >> destination;
	transform(destination.begin(), destination.end(), destination.begin(), ::toupper); // changes destination to uppercase
	outData << "Please enter destination. (usa/can/aus/mars)" << setw(11) << setfill('.') << ":" << destination << "\n";
	if (destination != USA && destination != CAN && destination != AUS && destination != MARS) {
		cout << "\n" << "Invalid entry, exiting";
		outData << "\n" << "Invalid entry, exiting";
		return 0;
	}
	// exits the program if destination input
	//is invalid
// user inputs item name, the line ends.
	cout << endl;
	outData << endl;



	//Note to self: I was using 'cout << endl; (ctrl + k + c)' and \n and was confused by why the couts were making empty lines
				// 	   !!!!! cin seems to move onto the next line without making an entire blank line.
				// I swear I program like i've never programmed before sometimes...
				//fragile = "Hello";

	// Shipping cost order ctrl structure
	if (preTotal <= ORDER_TOTAL_LOW) // 50 and below
	{
		if (destination == USA) // usa low total action 
		{
			shippingCostNotTotal = USA_LOW_SHIPPING_FEE;

		}
		if (destination == CAN) // can low total action 
		{
			shippingCostNotTotal = CAN_LOW_SHIPPING_FEE;

		}
		if (destination == AUS) // aus low total action 
		{
			shippingCostNotTotal = AUS_LOW_SHIPPING_FEE;

		}
		if (destination == MARS) // aus low total action 
		{
			shippingCostNotTotal = MARS_LOW_SHIPPING_FEE;

		}


	}
	else if ((ORDER_TOTAL_LOW < preTotal) && (preTotal <= ORDER_TOTAL_MID)) // between 50.01 and 100.00 (inclusive)
	{
		if (destination == USA) // usa low total action 
		{
			shippingCostNotTotal = USA_MID_SHIPPING_FEE;

		}
		else if (destination == CAN) // can low total action 
		{
			shippingCostNotTotal = CAN_MID_SHIPPING_FEE;

		}
		else if (destination == AUS) // aus low total action 
		{
			shippingCostNotTotal = AUS_MID_SHIPPING_FEE;

		}
		else if (destination == MARS) // aus low total action 
		{
			shippingCostNotTotal = MARS_MID_SHIPPING_FEE;

		}



	}
	else if ((ORDER_TOTAL_MID < preTotal) && (preTotal <= ORDER_TOTAL_PRICEY)) // between 100.01 and 150.00 (inclusive)
	{
		if (destination == USA) // usa low total action 
		{
			shippingCostNotTotal = USA_HIGH_SHIPPING_FEE;

		}
		else if (destination == CAN) // can low total action 
		{
			shippingCostNotTotal = CAN_HIGH_SHIPPING_FEE;

		}
		else if (destination == AUS) // aus low total action 
		{
			shippingCostNotTotal = AUS_HIGH_SHIPPING_FEE;

		}
		else if (destination == MARS) // aus low total action 
		{
			shippingCostNotTotal = MARS_HIGH_SHIPPING_FEE;

		}


	}
	else if (preTotal > ORDER_TOTAL_PRICEY) // over 150 (exclusive of 150)
	{
		shippingCostNotTotal = 0.00;


	}
	if (fragile == YES) // IF FRAHILE THIS GETS ADDED ON.
		shippingCostNotTotal += FRAGILE_FEE;
	postTotal = shippingCostNotTotal + preTotal;

	cout << setprecision(2) << fixed << showpoint; // fixed no expo, show point all nums have .xx+, setprecision rounding decimal.
	cout << "Your item is" << setw(37) << setfill('.') << itemName << endl;
	if (shippingCostNotTotal == 0) // over 150 (exclusive of 150) // triggers if the shipping fee is free and no fragile fee.
	{
		cout << "Your shipping cost is" << setw(23) << setfill('.') << ORDER_TOTAL_FREE << endl;
	}
	else // this happens even with fragile fee and no shipping fee
	{
		cout << "Your shipping cost is" << setw(20) << setfill('.') << "$" << shippingCostNotTotal << endl;
	}

	cout << "Your are shipping to" << setw(23) << setfill('.') << destination << endl;
	cout << "Your total shipping cost are" << setw(13) << setfill('.') << "$" << postTotal << endl;




	// into Order file (ending part)



	//end data
	outData << setprecision(2) << fixed << showpoint; // fixed no expo, show point all nums have .xx+, setprecision rounding decimal.
	outData << "Your item is" << setw(37) << setfill('.') << itemName << endl;
	if (shippingCostNotTotal == 0) // over 150 (exclusive of 150) // triggers if the shipping fee is free and no fragile fee.
	{
		outData << "Your shipping cost is" << setw(23) << setfill('.') << ORDER_TOTAL_FREE << endl;
	}
	else // this happens even with fragile fee and no shipping fee
	{
		outData << "Your shipping cost is" << setw(20) << setfill('.') << "$" << shippingCostNotTotal << endl;
	}

	outData << "Your are shipping to" << setw(23) << setfill('.') << destination << endl;
	outData << "Your total shipping cost are" << setw(13) << setfill('.') << "$" << postTotal << endl;

	//fragile = "Hello";
   /*fragilechar = *fragile.begin();
   fragile = toupper(fragilechar);
   */
   //return 0;




	return 0;
}