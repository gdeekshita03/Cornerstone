// Program by Deekshita Gorrepati
// 3/24/2022

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#define MAX 50 //universal value for the max value of the array

using namespace std;
float total_volume (const float seafloor[MAX][MAX],int row, int col); //declaration of function for volume

int main() {
    char repeat; //variable for repeat
    do { //do-while loop that doesn't stop until user says that they no longer want to continue
        string filename; //input file
    string resultsfile; //output file
    ifstream infile; //set data type to the infile
    float seafloor[MAX][MAX]; //set maxs for the array
    int row; //represents the rows of the array
    int col; //represents the columns of the array
    //introduce the program and ask user what file they want to anayze
    cout << "****************************************************" << endl;
    cout << "Welcome! This program was written by Deekshita Gorrepati." << endl;
    cout << "This is Lab #3: The Sea Floor Analysis Program." << endl;
    cout << "****************************************************" << endl;
    cout << "Please tell me the name of the file to analyze: ";
    cin >> filename; //takes filename as an input
    cout << "PLease tell me the size of the file." << endl; //provide size for the file by asking user for row and columb inputs
    cout << "Number of Rows: ";
    cin >> row;
    cout << "Number of Columns: ";
    cin >> col;
    infile.open(filename.c_str()); //put file name here
    if (!infile) //if the file does not open successfully
    {
        cout << "Unable to open file" << endl;
        system("pause"); //terminates program
        exit(0);
    } else {
        cout << "Successfully read file! " << endl;
        for (int i = 0; i < row; i++) { //read in the data from the file
            for (int j = 0; j < col; j++) {
                infile >> seafloor[i][j];
            }
        }
    }     ofstream outfile; //set data type for output
        cout << "Please tell me the name of your results file: ";
        cin >> resultsfile; //ask user for the name of the results file folder
        outfile.open(resultsfile.c_str()); //put file name here
        infile.close();
        cout << "****************************************************" << endl;
        cout << "Part A: " << endl;
        outfile << "The depth matrix is: " << endl;
       // cout << "The depth matrix is: " << endl;
//write the depth matrix to the output file
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                outfile << setw(10); //set width of the matrix in the outfile
                //Write the depth matrix to the output file
                outfile << seafloor[i][j];
            }
            outfile << endl;
        }
//Find the largest value in the matrix and its row & column coordinates
        int a, b, maxrow, maxcol; //variables for the counters for the row and column as well as the maximum value in each row and column
        double max = 0;
        for (a = 0; a < row; a++) { //create a counter array
            for (b = 0; b < col; b++) {
                if (max < seafloor[a][b]) {
                    max = seafloor[a][b];
                    maxrow = a + 2; //define the max row value as +2 of the a value so that user can read it
                    maxcol = b + 2; //define the max column value as +2 of the a value so that user can read it
                }
            }
        }
        //print the deepest point and its coordinates to outfile and user interface
        outfile << "The deepest point in the ocean is " << max << " occurring at coordinates (" << maxcol << ","
                << maxrow << ")" << endl;
        cout << "The deepest point in the ocean is " << max << " occurring at coordinates (" << maxcol << "," << maxrow
             << ")" << endl;

        //Calculate the deepest 2 x 2 area and its corresponding row and column coordinates
        cout << "****************************************************" << endl;
        cout << "Part B: " << endl;
        int x, y, r, s;
        double area, maxarea, maxaverage = 0; //declare variables for the area and maximum area as well as the average area which is what will be outputted to user
        for (x = 0; x < row - 1; x++) { //loop of going through every 2 by 2 matrix
            for (y = 0; y < col - 1; y++) {
                area = (seafloor[x][y] + seafloor[x + 1][y] + seafloor[x][y + 1] + seafloor[x + 1][y + 1]); //calculate the total area by adding together the four parts of the matrix
                if (area > maxarea) {
                    maxarea = area;
                    //make coordinates readable by user
                    r=y+1;
                    s=x+1;
                }
            }
        }
        maxaverage = (maxarea / 4); //to find the average max area divide the maximum area by 4
        //print the deepest 2x2 area and its bounds to outfile and user interface
        outfile << "The deepest 2x2 area in the ocean is " << maxaverage << " bounded by: (" << r << "," << s << "), ("<< r+1 << "," << s << "), (" << r << "," << s+1 << "), (" << r+1 << "," << s+1 << "), " << endl;
        cout << "The deepest 2x2 area in the ocean is " << maxaverage << " bounded by: (" << r << "," << s << "), ("<< r+1 << "," << s << "), (" << r << "," << s+1 << "), (" << r+1 << "," << s+1 << "), " << endl;

        //Send the depth matrix and its size to a function to find the total volume
        cout << "****************************************************" << endl;
        cout << "Part C: " << endl;
        double finalvolume; //variable for the final volume that is set equal to the total volume function
        finalvolume = total_volume(seafloor, row, col);
        //print the volume in cubic meters to outfile and user interface
        outfile << "The oceans volume is " << finalvolume << " cubic meters." << endl;
        cout << "The oceans volume is " << finalvolume << " cubic meters." << endl;
        outfile << "This program is done with the analysis!" << endl;
        cout << "This program is done with the analysis!" << endl;
        outfile.close(); //close all files
        cout << "Would you like to run another file? (Y/N): "; //asks user if they want to perform another search
        cin >> repeat; //user input is taken in
    }
while (repeat == 'Y'); //continue the do-while loop if user says yes
return 0;
}
//function for total volume that takes in array and the row and column sizes that are in inputted by the user
float total_volume (const float seafloor[MAX][MAX],int row, int col){
    float volume;
    //goes through each row and column and adds all the data points to get the volume
    for (int p = 0; p< row; p++) {
        for (int q = 0; q< col; q++){
            volume = volume + seafloor[p][q];
        }
    }
    return volume; //send volume back to the main program
}