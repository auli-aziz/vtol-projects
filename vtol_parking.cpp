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
    int input, hours1, minutes1, hours2, minutes2;

    std::cout << "WELCOME TO THE PARKING METER 1.0" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Enter your option:\n1. START\n2. QUIT\nInput: ";
    std::cin >> input;
    std::cout << "=====================================" << std::endl;
    if(input == 1){
        std::cout << "Enter starting time (HH:MM): ";
        std::cin >> std::setw(2) >> hours1; //setw comes from iomanip library and limits the input to 2 characters 
        std::cin.ignore(); //ignores the ":" separator
        std::cin >> std::setw(2) >> minutes1;

        auto duration1 = std::chrono::seconds(hours1 * 3600 + minutes1 * 60);

        auto h1 = std::chrono::duration_cast<std::chrono::hours>(duration1);
        auto m1 = std::chrono::duration_cast<std::chrono::minutes>(duration1 % std::chrono::hours(1));

        std::cout << "Start time: " << std::setfill('0') << std::setw(2) << h1.count() << ':'
        << std::setfill('0') << std::setw(2) << m1.count() << std::endl;

        std::cout << "Enter exit time (HH:MM): ";
        std::cin >> std::setw(2) >> hours2;
        std::cin.ignore();
        std::cin >> std::setw(2) >> minutes2;
        
        auto duration2 = std::chrono::seconds(hours2 * 3600 + minutes2 * 60);

        auto h2 = std::chrono::duration_cast<std::chrono::hours>(duration2);
        auto m2 = std::chrono::duration_cast<std::chrono::minutes>(duration2 % std::chrono::hours(1));

        std::cout << "Exit time: " << std::setfill('0') << std::setw(2) << h2.count() << ':'
        << std::setfill('0') << std::setw(2) << m2.count();

        int start = hours1 * 3600 + minutes1 * 60;
        int end = hours2 * 3600 + minutes2 * 60;
        int diff = abs(end - start);
        int diff_hours = diff / 3600;
        int diff_minutes = diff % 3600;

        std::cout << "Total parking time: ";
    }
}