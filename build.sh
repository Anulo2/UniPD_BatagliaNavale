mkdir -p build  
cd build  
cmake .. 
cmake --build .  
make 
#bash -c ' ./main pc'
#bash -c './mainReplay v ../logs/mainLogPCVSPC.txt'
#bash -c './mainReplay f ../logs/mainLogPCVSPC.txt ../logs/outputMainReplay.txt'
#bash -c  '${EDITOR:-vi} ../logs/outputMainReplay.txt'