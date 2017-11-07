debug.so: debug.cpp
	g++ debug.cpp -ldl -fPIC --shared -o debug.so -std=c++11

buggy: buggy.cpp
	g++ buggy.cpp -o buggy -funwind-tables -rdynamic

bundle:
	g++ debug.cpp buggy.cpp -ldl -o bundle

test-buggy:
	LD_PRELOAD=./debug.so ./buggy

clean: 
	rm ./buggy ./debug.so

