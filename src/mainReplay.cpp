#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

#include "Battleship.h"
#include "Controller.h"
#include "Entity.h"
#include "Position.h"
#include "Replay.h"
#include "Submarine.h"
#include "Support.h"
#include "Unit.h"

int main(int argc, char* argv[]) {
    // content for input file
    std::vector<std::string> iFile;

    // content for output file
    std::vector<std::string> oFile;

    static const int placedUnits = 16;

    bool invalid = false;
    try {
        while (!invalid) {
            if (argc < 3 || argc > 4) {
                std::cout << "\ninvalid arguments\n"
                             "You can use: parameter v [name_file_log]\nor"
                             "parameter f [name_file_log] [name_file_output_replay]\n";

                invalid = true;

            } else if (argc == 3 && strcmp(argv[1], "v") == 0) {
                struct stat sb;
                const char* argv2 = argv[2];
                if (stat(argv2, &sb) == 0) {
                    if (sb.st_mode & S_IFDIR) {
                        throw std::invalid_argument("This is a folder!");
                    }
                }

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

                Replay replay(iFile);
                std::cout << std::endl;
                std::cout << "####################################\n";
                std::cout << "###          REPLAY              ###\n";
                std::cout << "####################################\n";

                std::cout << replay.getPlayer1() << std::endl;
                std::cout << replay.getPlayer2() << std::endl;

                int i = placedUnits;

                while (i < iFile.size()) {
                    replay.addStringToLog(inputHelper::handlePlayerAction(replay.getPlayer1(), replay.getPlayer2(), iFile[i]));
                    std::cout << replay.getPlayer1() << std::endl;

                    i++;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                    replay.addStringToLog(inputHelper::handlePlayerAction(replay.getPlayer2(), replay.getPlayer1(), iFile[i]));
                    std::cout << replay.getPlayer2() << std::endl;
                    i++;

                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                }

                invalid = true;
            } else if (argc == 4 && strcmp(argv[1], "f") == 0) {
                if (strcmp(argv[2], argv[3]) == 0) {
                    throw std::invalid_argument("You are tring to r/w the same file!\n");
                }
                struct stat sb;
                const char* argv2 = argv[2];
                if (stat(argv2, &sb) == 0) {
                    if (sb.st_mode & S_IFDIR) {
                        throw std::invalid_argument("This is a folder!");
                    }
                }
                const char* argv3 = argv[3];
                if (stat(argv3, &sb) == 0) {
                    if (sb.st_mode & S_IFDIR) {
                        throw std::invalid_argument("This is a folder!");
                    }
                }

                std::ifstream my_ifile(argv[2]);
                std::ofstream my_ofile(argv[3]);

                if (my_ifile.is_open()) {
                    std::string line;
                    while (getline(my_ifile, line)) {
                        iFile.push_back(line);
                    }
                    my_ifile.close();
                } else {
                    std::cout << "Unable to open file" << std::endl;
                }

                Replay replay(iFile);
                std::cout << std::endl;
                std::cout << "####################################\n";
                std::cout << "###          REPLAY              ###\n";
                std::cout << "####################################\n";

                my_ofile << inputHelper::logToString(replay.getLog());

                int i = placedUnits;
                while (i < iFile.size()) {
                    my_ofile << "\nPLAYER 1 ACTION\n";

                    std::cout.setstate(std::ios_base::failbit);

                    replay.addStringToLog(inputHelper::handlePlayerAction(replay.getPlayer1(), replay.getPlayer2(), iFile[i]));
                    my_ofile << "\t-> " + iFile[i];
                    my_ofile << replay << std::endl;
                    i++;

                    if (replay.getPlayer2()->removeDeadUnits()) {
                        my_ofile << "\nUnit destroyed\n";
                    }

                    my_ofile << "PLAYER 2 ACTION\n";
                    replay.addStringToLog(inputHelper::handlePlayerAction(replay.getPlayer2(), replay.getPlayer1(), iFile[i]));
                    my_ofile << "\t-> " + iFile[i];
                    my_ofile << replay << std::endl;
                    i++;

                    if (replay.getPlayer1()->removeDeadUnits()) {
                        my_ofile << "\nUnit destroyed\n";
                    }

                    std::cout.clear();

                    if (replay.getPlayer2()->isDead()) {
                        my_ofile << "######################################\n";
                        my_ofile << "########        VINCE PC1       ######\n";
                        my_ofile << "######################################\n";
                    }
                    if (replay.getPlayer1()->isDead()) {
                        my_ofile << "######################################\n";
                        my_ofile << "########        VINCE PC2       ######\n";
                        my_ofile << "######################################\n";
                    }
                    my_ofile.flush();
                }

                my_ofile.close();
                std::cout << "You can find the output of the Replay in " << argv[3] << std::endl;
                invalid = true;

            } else {
                std::cout << "\ninvalid arguments\n"
                             "You can use: parameter v [name_file_log]\nor"
                             "parameter f [name_file_log] [name_file_output_replay]\n";

                invalid = true;
            }
        }
    } catch (std::invalid_argument e) {
        std::cout << "Something went wrong... " << std::endl;
    }

    return 0;
}
