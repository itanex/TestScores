/*Bryan Wood           lib.h
*/


#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*-------------------------------------------------------
opens files to be used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void openfiles (ifstream &input, ofstream &output);

/*-------------------------------------------------------
closes files used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void closefiles (ifstream &input, ofstream &output);

/*-------------------------------------------------------
collects the data
Receives: input, name, testtype, score1, score2
Returns: name, testtype, score1, score2
---------------------------------------------------------*/
void getdata (ifstream &input, ofstream &output, char name1[], 
			  char testtype1[], char testtype2[], double &avgscr1, 
			  double &avgscr2, double &avgscr3, double &avgscr4,
			  int &counter1, int &counter2, int &counter3, int &counter4);

/*-------------------------------------------------------
manips the data
Receives: input, name, testtype, score1, score2
Returns: name, testtype, score1, score2
---------------------------------------------------------*/
void manipdata (ifstream &input, ofstream &output, char testtype1[], 
			  char testtype2[], double &avgscr1, double &avgscr2, 
			  double &avgscr3, double &avgscr4, int &counter1, 
			  int &counter2, int &counter3, int &counter4);
