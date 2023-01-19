// Eris Sanson

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include <iostream>

#include "Replay.h"

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

                // Open input file!
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

                /*********************************************************
                 *                      Placing Units                     *
                 **********************************************************/

                Replay replay;
                replay.startGame(iFile);

                std::cout << std::endl;
                std::cout << "####################################\n";
                std::cout << "###          REPLAY              ###\n";
                std::cout << "####################################\n";
                std::cout << "\n\n";

                std::cout << "####################################\n";
                std::cout << "###          PLAYER 1            ###\n";
                std::cout << "####################################\n";
                std::cout << "\n\n";

                std::cout << replay.getPlayer1() << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));

                std::cout << "####################################\n";
                std::cout << "###          PLAYER 2            ###\n";
                std::cout << "####################################\n";
                std::cout << "\n\n";

                std::cout << replay.getPlayer2() << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));

                /*********************************************************
                 *                      LIVE REPLAY                      *
                 **********************************************************/

                if (replay.getStartingPlayer(iFile[0])) {
                    replay.printActionInOrder(replay.getPlayer1(), replay.getPlayer2(), iFile);
                } else {
                    replay.printActionInOrder(replay.getPlayer2(), replay.getPlayer1(), iFile);
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

                /*********************************************************
                 *                      Placing Units                     *
                 **********************************************************/

                Replay replay;
                replay.startGame(iFile);

                std::cout << std::endl;
                std::cout << "####################################\n";
                std::cout << "###          REPLAY              ###\n";
                std::cout << "####################################\n";

                my_ofile << Helper::logToString(replay.getLog());

                my_ofile << "####################################\n";
                my_ofile << "###          PLAYER 1            ###\n";
                my_ofile << "####################################\n";
                my_ofile << "\n\n";
                my_ofile << replay.getPlayer1();

                my_ofile << "####################################\n";
                my_ofile << "###          PLAYER 2            ###\n";
                my_ofile << "####################################\n";
                my_ofile << "\n\n";
                my_ofile << replay.getPlayer2();

                /*********************************************************
                 *                      REPLAY ON FILE!                  *
                 **********************************************************/

                if (replay.getStartingPlayer(iFile[0])) {
                    replay.writeActionInOrder(replay.getPlayer1(), replay.getPlayer2(), iFile, my_ofile);
                } else {
                    replay.writeActionInOrder(replay.getPlayer2(), replay.getPlayer1(), iFile, my_ofile);
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
        std::cout << e.what() << std::endl;
        std::cout << "Something went wrong... " << std::endl;
    }

    return 0;
}
