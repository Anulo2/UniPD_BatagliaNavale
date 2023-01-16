#include <fstream>
#include <iostream>
#include <string.h>
#include <chrono>
#include <thread>
#include <stdio.h>

#include "Controller.h"
#include "Entity.h"
#include "Battleship.h"
#include "Support.h"
#include "Submarine.h"
#include "Unit.h"
#include "Position.h"

#include "Replay.h"

int main(int argc, char* argv[]){
    std::cout << std::endl;
    std::cout <<"####################################\n";
    std::cout<<"###          REPLAY              ###\n";
    std::cout<<"####################################\n";

    //content for input file
    std::vector<std::string> iFile;   

    //content for output file
    std::vector<std::string> oFile;

    static const int placedUnits = 16;  
    
    bool invalid = false;
    while (!invalid){

        if (argc < 3 || argc > 4){
            std::cout << "\ninvalid arguments\n"
                         "You can use: parameter v [name_file_log]\nor"
                         "parameter f [name_file_log] [name_file_output_replay]\n";
            
            invalid = true;

        } else if(argc == 3 && strcmp(argv[1],"v")==0){
            
            std::ifstream my_ifile(argv[2]);
    
            if (my_ifile.is_open()) {
                std::string line;
                while (getline(my_ifile, line)) {
                    iFile.push_back(line);
                }
                my_ifile.close();
            } else {
                std::cout << "Unable to open file" << std::endl;
            }


            Replay a(iFile);
            std::cout << a.getPlayer1() << std::endl;
            std::cout << a.getPlayer2() << std::endl;

            
            int i = placedUnits;    

            while(i < iFile.size()){
                a.addStringToLog(inputHelper::handlePlayerAction(a.getPlayer1(), a.getPlayer2(),iFile[i]));
                std::cout<<a.getPlayer1()<<std::endl;
                
                i++;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000) );
                a.addStringToLog(inputHelper::handlePlayerAction(a.getPlayer2(), a.getPlayer1(),iFile[i]));
                std::cout<<a.getPlayer2()<<std::endl;
                
                i++;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000) );
            }
           
            
            invalid = true;
        }
        else if (argc == 4 && strcmp(argv[1],"f")==0){
            
            std::ifstream my_ifile(argv[2]);
            std::ofstream my_ofile(argv[3]);

            if (my_ifile.is_open()){
                std::string line;
                while (getline(my_ifile, line)) {
                    iFile.push_back(line);
                }
                my_ifile.close();
            }
            else{
                std::cout << "Unable to open file" << std::endl;
            }

            Replay a(iFile);
            my_ofile <<inputHelper::logToString(a.getLog());

            int i = placedUnits;
                while(i < iFile.size()){
                    a.addStringToLog(inputHelper::handlePlayerAction(a.getPlayer1(), a.getPlayer2(),iFile[i]));
                    my_ofile<<iFile[i];
                    my_ofile<<a<<std::endl;
                    i++;
                    a.addStringToLog(inputHelper::handlePlayerAction(a.getPlayer2(), a.getPlayer1(),iFile[i]));
                    my_ofile<<iFile[i];
                    my_ofile<<a<<std::endl;
                    i++;
                }
            
            my_ofile.close();
            invalid = true;

        } else {
            std::cout << "\ninvalid arguments\n"
                         "You can use: parameter v [name_file_log]\nor"
                         "parameter f [name_file_log] [name_file_output_replay]\n";
            
            invalid = true;
        }
    } 
        
    

   
    return 0;
}
