data.dat: c.x
    ./c.x 10 > data.dat 
c.x : pendulo.cpp
    c++ pendulo.cpp -o c.x
clean :
    rm -r c.x 