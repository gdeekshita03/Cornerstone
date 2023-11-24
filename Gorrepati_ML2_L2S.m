%Deekshita Gorrepati 
%1/31/2022
%This program is intended to find the greatest and smallest values in each row of the array that is loaded
clc; 
clear; 
%load in array
MyArray=load('Largest_and_Smallest_Numbers.txt');
%go through each row and set the 1st number in each row as the biggest and smallest as a reference for comparison 
for row=1:6
    big=MyArray(row,1);
    small=MyArray(row,1);
%go through each column and compare each number within the row to the number before to see if it's the biggest or the smallest in each row
    for col=1:24
        if MyArray(row,col)>big
            big=MyArray(row,col);
        end
        if MyArray(row,col)<small
            small=MyArray(row,col);
        end
    end
%after each row, display the maximum (biggest) # and the minimum (smallest) # of that row to the user
        fprintf('In row %i, the maximum number is %i and the minimum number is %i.\n',row,big,small)
end
  
