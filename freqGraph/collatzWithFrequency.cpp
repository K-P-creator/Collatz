//c++ function for calculating how many iterations are required to traverse the
//collatz conjecture until the output == 1

//collatz conj says any number will eventually equal one if you apply n/2 for even
//and 3n+1 for odd
//so far it is unproven... 

//Here I am using a min/max on the command line and I am using a hash map to keep track
//of all the freqency data. I then output the hash map and the counts to either a 
//csv which will then be parsed by the python analysis script

#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//global map for frequency values
unordered_map <size_t, int> freq;

void collatz(size_t in, size_t& count, bool first);
void outputFreq();
bool verifyArgs(size_t & min, size_t& max, int argc, char** argv);

int main(int argc, char ** argv)
{
    
    size_t min = 0;
    size_t max = 0;

    if(!verifyArgs(min, max, argc, argv)){
        cerr << "Terminating Process\n";
        return 1;
    }

    size_t count = 0;
    vector <size_t> counts = {};

    ofstream out;
    out.open("data/counts.csv");

    //loop through collatz from min to max
    for (size_t in = min; in <= max; in ++){
        collatz(in, count, true);
        out << count << endl;
        count = 0;
    }

    outputFreq();

    return 0;
}


//This implementation of collatz will keep track of frequencies in the hash map
void collatz(size_t in, size_t& count, bool first)
{
    //base case
    if (in == 1){
        return;
    }

    count++;
    //increment the frequency for current value
    //Dont count the first iteration
    if (!first){
        if (freq.count(in) != 0){
            freq[in]++;
        }else{
            freq[in] = 1;
        }
    }
    first = false;

    //even case
    if (in % 2 == 0){
        collatz(in/2, count, first);
    //odd case
    }else{
        collatz(in*3+1, count, first);
    }

    return;
}

void outputFreq()
{
    ofstream out;
    out.open("data/freq.csv");


    for (auto n : freq){
        out << n.first <<", "<< n.second << endl;
    }

    out.close();

    return;
}

bool verifyArgs(size_t &min, size_t &max, int argc, char** argv)
{
    //verify arguments
    try{
        if (argc < 3){
            throw runtime_error("Too Few Command Line Arguments\nUsage: ./exeName min max");
        }
        if (argc > 3){
            throw runtime_error("Too Many Command Line Arguments\nUsage: ./exeName min max\n");
        }
    }

    catch (const runtime_error& e){
        cerr << e.what() << endl;
        return 0;
    }

    try{
        min = stoull(string(argv[1]));
        max = stoull(string(argv[2]));
    }

    catch (const invalid_argument&){
        cerr << "Min/Max Must be Type Int\nUsage: ./exeName min max\n";
        return 0;
    }

    if (min > max){
        cerr << "Max must be >= Min\nUsage: ./exeName min max\n";
        return 0;
    }

    return 1;
}
