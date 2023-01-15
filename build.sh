mkdir -p build  
cd build  
cmake .. 
cmake --build .  
make 
bash -c './mainReplay f ../replay.txt ../output.txt'