/*Bryan Wood           lib.cpp*/

#include "lib.h"

/*-------------------------------------------------------
opens files to be used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void openfiles (ifstream &input, ofstream &output)
{
	char
		infile [20],  
		outfile [20]; 
	
	// opens the file that will be used as the input file
	cout << "Enter the name of input file to be opened: ";
	cin >> infile;

	input.open(infile, ios::nocreate);
	while (input.fail())
	{
		cout << "Could not open " << infile 
			 << " please re-enter the file name: " << endl;
		cin >> infile;
		input.open(infile, ios::nocreate);
		input.clear();
	}

	// opens the file that will be used as the output file
	cout << "Enter the name of output file to be opened: ";
	cin >> outfile;

	output.open (outfile, ios::in);    // creates output file for output 

}//end openfiles

/*-------------------------------------------------------
closes files used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void closefiles (ifstream &input, ofstream &output)
{
	input.close ();
	output.close();

}//end closefiles


/*-------------------------------------------------------
collects the first line of data
Receives: input, name, testtype, score1, score2
Returns: name, testtype, score1, score2
---------------------------------------------------------*/
void getdata (ifstream &input, ofstream &output, char name1[], 
			  char testtype1[], char testtype2[], double &avgscr1, 
			  double &avgscr2, double &avgscr3, double &avgscr4,
			  int &counter1, int &counter2, int &counter3, int &counter4)			  
{
	char catcher[20] = "", strtemp[20] = "";
	int
		score1 = 0,	score2 = 0;
	double
		avgscr1a = 0, avgscr2a = 0, avgscr3a = 0, avgscr4a = 0,
		avgscr1b = 0, avgscr2b = 0, avgscr3b = 0, avgscr4b = 0;
	
	do
	{
  	input.getline (name1, 20);
	strcpy (strtemp, catcher);
	strcat (strtemp, name1);
	strcpy (name1, strtemp);

	input >> score1 >> testtype1;
	input >> score2;
	input >> testtype2;
	input >> catcher;


	output << setiosflags(ios::left)   << setw(20) << name1
		   << resetiosflags(ios::left) << setw(5)  << score1    << " "
		   << setiosflags(ios::left)   << setw(5)  << testtype1
		   << resetiosflags(ios::left) << setw(8)  << score2    << " "
		   << setiosflags(ios::left)   << setw(5)  << testtype2 << endl;
	
	testtype1[0] = tolower (testtype1[0]);
	testtype2[0] = tolower (testtype2[0]);
	
	switch (testtype1[0])
	{
	case 'a':
		avgscr1a += double (score1);
		counter1++;
		break;
	case 'g':
		avgscr2a += double (score1);
		counter2++;
		break;
	case 's':
		avgscr3a += double (score1);
		counter3++;
		break;
	case 'v':
		avgscr4a += score1;
		counter4++;
		break;
	default:
		break;
	}

	switch (testtype2[0])
	{
	case 'a':
		avgscr1b += double (score2);
		counter1++;
		break;
	case 'g':
		avgscr2b += double (score2);
		counter2++;
		break;
	case 's':
		avgscr3b += double (score2);
		counter3++;
		break;
	case 'v':
		avgscr4b += double (score2);
		counter4++;
		break;
	default:
		break;
	}
	avgscr1 = (avgscr1a + avgscr1b) / counter1;
	avgscr2 = (avgscr2a + avgscr2b) / counter2;
	avgscr3 = (avgscr3a + avgscr3b) / counter3;
	avgscr4 = (avgscr4a + avgscr4b) / counter4;
	}while (!input.eof());
}//end getdata

/*-------------------------------------------------------
manips the data
Receives: input, name, testtype, score1, score2
Returns: name, testtype, score1, score2
---------------------------------------------------------*/
void manipdata (ifstream &input, ofstream &output, char testtype1[], 
			  char testtype2[], double &avgscr1, double &avgscr2, 
			  double &avgscr3, double &avgscr4, int &counter1, 
			  int &counter2, int &counter3, int &counter4)
{
	output.precision(4);	
	output << setiosflags(ios::left)   << setw(10) << "Arith" 
		   << resetiosflags(ios::left) << setw(10) << counter1
		   << setw(10) << setiosflags(ios::showpoint) << avgscr1 << endl
		   
		   << setiosflags(ios::left)   << setw(10) << "Geog"
		   << resetiosflags(ios::left) << setw(10) << counter2 
		   << setw(10) << setiosflags(ios::showpoint) << avgscr2  << endl
		   
		   << setiosflags(ios::left)   << setw(10) << "Spell"
		   << resetiosflags(ios::left) << setw(10) << counter3 
		   << setw(10) << setiosflags(ios::showpoint) << avgscr3  << endl
		   
		   << setiosflags(ios::left)   << setw(10) << "Vocab"
		   << resetiosflags(ios::left) << setw(10) << counter4 
		   << setw(10) << setiosflags(ios::showpoint) << avgscr4  << endl
		   
		   << setiosflags(ios::left)   << setw(10) << "Over-all"
		   << resetiosflags(ios::left) 
		   << setw(10) << (counter1 + counter2 + counter3 + counter4) 
		   << setw(10) << setiosflags(ios::showpoint) 
		   << (avgscr1 + avgscr2 + avgscr3 + avgscr4) / 4.0  << endl;

}//end manipdata