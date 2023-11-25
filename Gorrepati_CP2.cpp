// Program by Deekshita Gorrepati
// 3/10/2022
// This program is a user interface that asks the user for a desired gender and year 
// and pulls information from BabyNames.txt to report the results accordingly 
// as well as the number of instances of that name in the data set 

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
    string filename;
    int i; //represents the rows of the array
    int j; //represents the columns of the array
    int x, y;  //counters used for the array
    int year; // input value for year by user
    int count; //represents the number of times a name appears
    string array[103][3]; //103 x 3 array
    char gender;
    //input variable for gender (used for switch case)
    string m, f;
    string name;
    char repeat; //input variable for whether user wants to repeat or not
    cout << "Welcome! This program tells you the most popular boy and girl names in any given year!" << endl;
    ifstream infile; //set data type to the infile
    cout << "Please enter the name for your input file: ";
    cin >> filename;
    infile.open(filename.c_str()); //put file name here
    if (!infile) //if the file does not open successfully
    {
        cout << "Unable to open BabyNames.txt file" << endl;
        system ("pause"); //terminates program
        exit (0);
    }
    else
    {
        infile >> filename;
        cout << "Successfully read file! " << endl;
        //reads the data into an array with 103 rows + 3 columns
        for (i=0; i<103; i++)
        {
            for (j=0; j<3; j++)
            {
                infile>>array[i][j];
            }
        }
    }
    do { //do-while loop that doesn't stop until user says that they no longer want to search for a name
        cout << "****************************************************" << endl;
        cout << "What gender are you interested in?" << endl;
        cout << "Please choose between male (m) and female (f): ";
        cin >> gender; //takes gender as an input
        cout << "What year do you want the top name for?" << endl;
        cout << "Please choose between 1917 and 2018: ";
        cin >> year;
        cout << "****************************************************" << endl;
        i = year - 1915; //how to get the row of the array that we are looking at based on the year that has inputted
        switch (gender) //case switch
        {
            case 'm': //if user wants male, find the most popular name in desired year in column 1 (male)
                name = array[i][1];
                break;
            case 'f': //if user wants female, find the most popular name in desired year in column 0 (female)
                name = array[i][0];
                break;
            default:
                cout << "Not a valid input. Please enter either m or f." << endl; //displayed if user does not input either m or f (error message)
                system ("pause"); //terminates program
                break;
        }
        for (x = 0; x < 102; x++) //create a counter array
        {
            for (y = 0; y < 3; y++) {
                if (name == array[x][y]) {
                    count++; //see how many times name appears
                }
            }
        }
        if (gender == 'm') { //if user asked for a male name, the most common male name in the desired year is displayed
            //the number of times the name appears in the entire data set is also displayed
            cout << "The top male name in " << year << " is " << name << " and it appears " << count << " times in the data set."
                 << endl;
        } else { //if user asked for a female name, the most common female name in the desired year is displayed
            //the number of times the name appears in the entire data set is also displayed
            cout << "The top female name in " << year << " is " << name << " and it appears " << count << " times in the data set."
                 << endl;
        }
        cout << "Would you like to search for another name? (Y/N): "; //asks user if they want to perform another search
        cin >> repeat; //user input is taken in
    }
  while (repeat == 'Y'); //continue the do-while loop if user says yes
}
