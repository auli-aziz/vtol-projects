#include <iostream>
#include <iomanip>

/*
the first hour is Rp 3 000
the next hour fee is Rp 1 000/hour
if more than 24h, dicount/reduce by Rp 10 000 per 24h
output the duration of time of parking
*/

void parking_meter();
void time_output(int diff_days, int diff_hours, int diff_minutes);
void fee_output(int total_fee);

int main(){
    int inputMenu = 1, loop = 1;
    
    std::cout << "WELCOME TO THE PARKING METER 1.0" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Enter your option:\n1. START\n2. QUIT\nInput: ";
    std::cin >> inputMenu;
    std::cout << "=====================================" << std::endl;

    while(inputMenu == 1){
        parking_meter(); 
        std::cout << "=====================================" << std::endl;
        std::cout << "Enter your option:\n1. START\n2. QUIT\nInput: ";
        std::cin >> inputMenu;
        std::cout << "=====================================" << std::endl;
    } 
    std::cout << "THANK YOU FOR USING PARKING METER 1.0 \n";    
    
    return 0;
}

void parking_meter(){
    int hours1 = 0, minutes1 = 0, seconds1 = 0, hours2 = 0, minutes2 = 0, seconds2 = 0, start = 0, end = 0, diff = 0, diff_hours = 0, diff_minutes = 0, days = 0, diff_days = 0, total_fee = 0;
    char inputDay = 'x';
    
    //input time
    do{
        std::cout << "Enter starting time (HH:MM): ";
        std::cin >> std::setw(2) >> hours1;
        std::cin.ignore();
        std::cin >> std::setw(2) >> minutes1;
        
        if(hours1 < 0 || minutes1 < 0 || seconds1 >= 86400)
            std::cout << "Error! Invalid starting time" << "\n";
    }while(hours1 < 0 || minutes1 < 0 || seconds1 >= 86400);
    
    std::cout << "Did you exit after more than 24h? (Y/n) "; 
    std::cin >> inputDay;

    if(inputDay == 'y' || inputDay == 'Y'){
            std::cout << "Enter the amount of day(s) parked: ";
            std::cin >> days;
        }                       
    
    do{
        std::cout << "Enter exit time (HH:MM): ";
        std::cin >> std::setw(2) >> hours2;
        std::cin.ignore();
        std::cin >> std::setw(2) >> minutes2;
        
        if(hours2 < 0 || minutes2 < 0 || seconds2 >= 86400)
            std::cout << "Error! Invalid exit time" << "\n";
    }while(hours2 < 0 || minutes2 < 0 || seconds2 >= 86400);

    std::cout << "=====================================" << std::endl;

    //time calculation
    seconds1 = (hours1 * 3600) + (minutes1 * 60);
    seconds2 = (hours2 * 3600) + (minutes2 * 60);
    start = seconds1;
    (days >= 1)? end = (days * 86400) + seconds2:end = seconds2;

    diff = end - start;
    if(diff < 0 && seconds1 > seconds2){
        diff = 86400 + diff;
    }
    if(diff == 0){
        diff = 86400*days;
    }
    diff_days = diff / 86400;
    diff_hours = (diff % 86400) / 3600;
    diff_minutes = (diff % 3600) / 60;

    //time output
    time_output(diff_days, diff_hours, diff_minutes);

    //fee calculation & output
    if(diff_hours != 0 || diff_days != 0){
        total_fee += 3000;
        if(diff_hours >= 2 || diff_days != 0){
            if(days == 0) 
                total_fee += 1000 * (diff_hours - 1);
            else 
                total_fee += (days * 23000);
            //if parking time is x hours and >0 minutes it adds 1000
            if(diff_minutes >= 1) 
                total_fee += 1000;
        }
        
        //discount fee
        if(diff_days >= 1){
            total_fee -= (days * 10000);
        }
        fee_output(total_fee);
    } else{
        std::cout << "Your parking is still Free! \n";
    }
}

void time_output(int diff_days, int diff_hours, int diff_minutes){
    std::cout << "Total parking time: " << diff_days << " day(s) " << diff_hours << 
    " hour(s) and " << diff_minutes << " minute(s) \n";
}

void fee_output(int total_fee){
    std::cout << "Total payment: Rp" << total_fee << "\n";
}