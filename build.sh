mkdir -p build  
cd build  
cmake .. 
cmake --build .  
make 
bash -c './main && cd ..'
