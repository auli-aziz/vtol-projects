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
    int inputMenu, hours1, minutes1, seconds1, hours2, minutes2, seconds2, start, end, diff,
    diff_hours, diff_minutes, days, diff_days;
    double total_fee = 0, initial_fee = 3000;
    char inputDay;

    std::cout << "WELCOME TO THE PARKING METER 1.0" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Enter your option:\n1. START\n2. QUIT\nInput: ";
    std::cin >> inputMenu;
    std::cout << "=====================================" << std::endl;
    
    if(inputMenu == 1){

        //input time
        do{
            std::cout << "Enter starting time (HH:MM): ";
            std::cin >> std::setw(2) >> hours1;
            std::cin.ignore();
            std::cin >> std::setw(2) >> minutes1;
            seconds1 = hours1 * 3600 + minutes1 * 60;
            
            if(hours1 < 0 || minutes1 < 0 || seconds1 >= 86400)
                std::cout << "Error! Invalid starting time" << "\n";
        }while(hours1 < 0 || minutes1 < 0 || seconds1 >= 86400);

        std::cout << "Did you exit on a different day? (Y/n)";
        std::cin >> inputDay;
        if(inputDay == 'y' || inputDay == 'Y'){
            std::cout << "Enter the amount of days parked: ";
            std::cin >> days;
        }
        
        do{
            std::cout << "Enter exit time (HH:MM): ";
            std::cin >> std::setw(2) >> hours2;
            std::cin.ignore();
            std::cin >> std::setw(2) >> minutes2;
            seconds2 = hours2 * 3600 + minutes2 * 60;
            
            if(hours2 < 0 || minutes2 < 0 || seconds2 >= 86400)
                std::cout << "Error! Invalid exit time" << "\n";
        }while(hours2 < 0 || minutes2 < 0 || seconds2 >= 86400);

        std::cout << "=====================================" << std::endl;

        //calculation (can be modularized)
        start = hours1 * 3600 + minutes1 * 60;
        end = hours2 * 3600 + minutes2 * 60;
        diff = abs(end - start);
        diff_hours = diff / 3600;
        diff_minutes = (diff % 3600) / 60;

        //ternary oparator idea for the s*
        std::cout << "Total parking time: " << diff_hours << " hour(s) and " << diff_minutes << " minute(s) \n";
        
        //fee calculation & output
        if(diff_hours != 0){
            total_fee += initial_fee;
            if(diff_hours >= 2){
                total_fee += 1000 * (diff_hours - 1);
                if(diff_minutes >= 1) total_fee += 1000;
            }
            std::cout << "Total payment: Rp" << total_fee << "\n";
        } else{
            std::cout << "Your parking is still Free!";
        }
    }
}