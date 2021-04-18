// ITCS2520Assign5.cpp //
// Rob Shiner //

// Johnny Utah owns a surf shop on the beach called �Point Break Surf Shop�. //
// Johnny sells surfboards in three sizes: small (2 meters), medium (3 meters), and large (4 meters). //
// The cost of one smallsurfboard is $175.00, one medium is $190.00, and one large is $200.00. //
// Write a program that will make the surf shop operational. // 
// Your program should allow the user to do the following: //
// Buy any surfboard in any sizeand in any quanity. //
// At any time show the total number of surfboards of each size sold. //
// At any time show the total money made. //


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Declare the costs as constants //
const double smallSurfboardCost = 175.00;
const double mediumSurfboardCost = 190.00;
const double largeSurfboardCost = 200.00;

// A function to show the user how to use the program //
void ShowUsage() {
	cout << "To show program usage 'S'" << endl;
	cout << "To purchase a surfboard press 'P'" << endl;
	cout << "To display current purchases press 'C'" << endl;
	cout << "To display total amount due press 'T'" << endl;
	cout << "To quit the program press 'Q'" << endl;
	cout << endl;
}

// A function to sell surfboards //
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge) {

	// Declare variables //
	int theQuantity;
	string theType;

	// Print message and take input of quantity and type //
	cout << "Please enter the quantity and type ( S=small, M=medium, L=large) of the surfboard you would like to purchase:";
	cin >> theQuantity >> theType;
	cout << endl;

	// If statements to determine which type gets calculated //
	if (theType == "S" || theType == "s") {
		iTotalSmall += theQuantity;
	}
	else if (theType == "M" || theType == "m") {
		iTotalMedium += theQuantity;
	}
	else if (theType == "L" || theType == "l") {
		iTotalLarge += theQuantity;
	}

	cout << endl;

}

// A function to show the number of surfboards of each size sold //
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {

	// If statements to print out what surfboard types the user has inputted //
	if (iTotalSmall > 0) {
		cout << "The total number of small surfboards is " << iTotalSmall << endl;
		
	}
	if (iTotalMedium > 0) {
		cout << "The total number of medium surfboards is " << iTotalMedium << endl;
	
	}
	if (iTotalLarge > 0) {
		cout << "The total number of large surfboards is " << iTotalLarge << endl;
		
	}

	cout << endl;
}

// A function to show the total amount of money made //
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {

	// Set precision of variables //
	cout << fixed << setprecision(2);

	// Declare variables //
	double theTotalAmount = 0;
	double smallSurfboardValue = 0;
	double mediumSurfboardValue = 0;
	double largeSurfboardValue = 0;

	// If statements to determine which surfboards are calculated and printed to the screen //
	if (iTotalSmall > 0) {
		smallSurfboardValue = iTotalSmall * smallSurfboardCost;
		cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << smallSurfboardValue << endl;
		theTotalAmount += smallSurfboardValue;
	}
	if (iTotalMedium > 0) {
		mediumSurfboardValue = iTotalMedium * mediumSurfboardCost;
		cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << mediumSurfboardValue << endl;
		theTotalAmount += mediumSurfboardValue;
	}
	if (iTotalLarge > 0) {
		largeSurfboardValue = iTotalLarge * largeSurfboardCost;
		cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << largeSurfboardValue << endl;
		theTotalAmount += largeSurfboardValue;
	}

	// Print total amount that is due //
	cout << "Amount due: $" << theTotalAmount << endl;
	cout << endl;

}

// Main function //
using namespace std;
int main() {

	// Declare variables //
	string theSelection;
	int theTotalSmall = 0;
	int theTotalMedium = 0;
	int theTotalLarge = 0;

	// Print message to screen //
	cout << "************************************************************" << endl;
	cout << "***** Welcome to my Johnny Utah's PointBreak Surf Shop *****" << endl;
	cout << "************************************************************" << endl;
	cout << endl;
	cout << endl;

	// Show the user the program usage //
	ShowUsage();

	// Prompt user for a selection //
	cout << "Please enter selection: ";
	cin >> theSelection;

	// Loop until user inputs "Q" or "q" to quit //
	while (theSelection != "Q" && theSelection != "q") {

	// If statements to determine what selection the user inputs //
	
		// If user inputs "S" or "s" the ShowUsage() function is run //
		if (theSelection == "S" || theSelection == "s") {
			cout << endl;
			ShowUsage();
		}
		// If user inputs "P" or "p" the MakePurchase() function is run //
		else if (theSelection == "P" || theSelection == "p") {
			MakePurchase(theTotalSmall, theTotalMedium, theTotalLarge);
		}
		// If user inputs "C" or "c" the DisplayPurchase() function is run //
		else if (theSelection == "C" || theSelection == "c") {
			// If the user has not made any purchases yet, a message is printed to the screen //
			if (theTotalSmall == 0 && theTotalMedium == 0 && theTotalLarge == 0) {
				cout << "No purchases made yet." << endl;
				cout << endl;
			}
			// If the user has made purchases, the function is run //
			else {
				DisplayPurchase(theTotalSmall, theTotalMedium, theTotalLarge);
			}
		}
		// If user inputs "T" or "t" the DisplayTotal() function is run //
		else if (theSelection == "T" || theSelection == "t") {
			// If the user has not made any purchases yet, a message is printed to the screen //
			if (theTotalSmall == 0 && theTotalMedium == 0 && theTotalLarge == 0) {
				cout << "No purchases made yet." << endl;
				cout << endl;
			}
			// If the user has made purchases, the function is run //
			else {
				DisplayTotal(theTotalSmall, theTotalMedium, theTotalLarge);
			}
		}
		// If a value is inputted that is not a choice, a message is printed to the screen //
		else {
			cout << "Your choice is invalid, see selection options below." << endl;
			cout << endl;
			ShowUsage();
		}
		// Re-prompt the user for a selection //
		cout << "Please enter selection: ";
		cin >> theSelection;

	}

	// If user inputs "Q" or "q" a "Thank you" message is printed, and the program ends //
	cout << "Thank you" << endl;

	system("pause");
	return(0);

}





