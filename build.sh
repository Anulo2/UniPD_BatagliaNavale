mkdir -p build  
cd build  
cmake .. 
cmake --build .  
make 
#bash -c './main && cd .. '
bash -c './mainReplay v ../mainLogPCVSPC.txt'
#bash -c './mainReplay f ../mainLogPCVSPC.txt ../outputMainReplay.txt'