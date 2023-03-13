#include <iostream>
#include <chrono>
#include <iomanip>

/*
the first hour is rp 3000
the next hour fee is 1000/hour
if more than 24h, dicount/reduce by 10 000 per 24h
output the duration of time of parking
*/

int main(){
    int input, hours1, minutes1, seconds1, hours2, minutes2, seconds2;

    std::cout << "WELCOME TO THE PARKING METER 1.0" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Enter your option:\n1. START\n2. QUIT\nInput: ";
    std::cin >> input;
    std::cout << "=====================================" << std::endl;
    if(input == 1){

    //input time
    do{
        std::cout << "Enter starting time: ";
        std::cin >> std::setw(2) >> hours1;
        std::cin.ignore();
        std::cin >> std::setw(2) >> minutes1;
        seconds1 = hours1 * 3600 + minutes1 * 60;
        
        if(hours1 < 0 || minutes1 < 0 || seconds1 >= 86400)
            std::cout << "Error! Invalid starting time" << "\n";
    }while(hours1 < 0 || minutes1 < 0 || seconds1 >= 86400);
    
    do{
        std::cout << "Enter exit time: ";
        std::cin >> std::setw(2) >> hours2;
        std::cin.ignore();
        std::cin >> std::setw(2) >> minutes2;
        seconds2 = hours2 * 3600 + minutes2 * 60;
        
        if(hours2 < 0 || minutes2 < 0 || seconds2 >= 86400)
            std::cout << "Error! Invalid exit time" << "\n";
    }while(hours2 < 0 || minutes2 < 0 || seconds2 >= 86400);


    std::cout << "Start time: " << std::setfill('0') << std::setw(2) << hours1 << ':'
    << std::setfill('0') << std::setw(2) << minutes1 << std::endl;
    
    std::cout << "Exit time: " << std::setfill('0') << std::setw(2) << hours2 << ':'
    << std::setfill('0') << std::setw(2) << minutes2 << std::endl;

    //calculation (can be modularized)
    int start = hours1 * 3600 + minutes1 * 60;
    int end = hours2 * 3600 + minutes2 * 60;
    int diff = abs(end - start);
    std::cout << "Difference: " << diff << "\n";
    int diff_hours = diff / 3600;
    int diff_minutes = (diff % 3600) / 60;

    //ternary oparator idea for the s*
    std::cout << "Total parking time: " << diff_hours << " hour(s) and " << diff_minutes << " minute(s) \n";

    //fee calculation
    }
}