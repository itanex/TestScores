/*
Bryan Wood           Main.cpp

This program uses input from a file and manipulates it into an average 
  and then finds the highest and lowest of the averages. After it is done 
  finding the info about the input it creates two files to display the data 
  that was created.
*/

#include "lib.h"

void main (void)
{
	ifstream
		input;   //used for name and test type/score input
	ofstream
		output;  //created for ending data
	char
		name1[40],
		testtype1[20], 
		testtype2[20];
	double
		avgscr1 = 0, 
		avgscr2 = 0, 
		avgscr3 = 0, 
		avgscr4 = 0;
	int
		counter1 = 0, 
		counter2 = 0, 
		counter3 = 0, 
		counter4 = 0;

	/*--------------------------------------------*/

	openfiles (input, output);
	
	//header
	output << setiosflags(ios::left)   << setw(20) << "Name"
     	   << resetiosflags(ios::left) << setw(5)  << "Score"

 	       << " " << setiosflags(ios::left) << setw(5) << "Topic"
		   << resetiosflags(ios::left)      << setw(8) << "Score"
		   << " " << setiosflags(ios::left) << setw(5) << "Topic" << endl << endl;

	getdata (input, output, name1, testtype1, testtype2, avgscr1, avgscr2, avgscr3, avgscr4, 
		     counter1, counter2, counter3, counter4);

	output << endl 
		   << setiosflags(ios::left)   << setw(10) << "Topic"
     	   << resetiosflags(ios::left) << setw(10) << "N"
		   << setw(10) << "Avg" << endl << endl;

	manipdata (input, output, testtype1, testtype2, avgscr1, avgscr2, avgscr3, avgscr4,
		       counter1, counter2, counter3, counter4);
	closefiles (input, output);


}//end main