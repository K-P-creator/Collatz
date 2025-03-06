//c++ function for calculating how many iterations are required to traverse the
//collatz conjecture until the output == 1

//collatz conj says any number will eventually equal one if you apply n/2 for even
//and 3n+1 for odd
//so far it is an unproven conjecture

//I also want to record more data such as number frequency and others in the future

#include <iostream>
#include <array>
#include <string>

using namespace std;

void collatz(size_t in, size_t& count);

int main(int argc, char ** argv){
    
    if (argc != 2){
        cerr << "Must Specify Input on Command Line\n";
        return 1;
    }

    size_t in = stoull(string(argv[1]));
    size_t count = 0;

    collatz(in, count);

    cout << count << endl;

    return 0;
}

void collatz(size_t in, size_t& count)
{
    //base case
    if (in == 1){
        return;
    }

    count++;

    //even case
    if (in % 2 == 0){
        collatz(in/2, count);
    //odd case
    }else{
        collatz(in*3+1, count);
    }
    return;
}
