#include "GameDie.h"
#include <vector>
#include <cstdlib>
#include <ctime>

/*
 * get_distribution() keeps a tally of how many times each face has been rolled, but some users are reporting that
 * they want this same information as a percentage of total rolls.

Add a public member function vector<double> GameDie::get_percentages() that returns
 the percentage of rolls for each face relative to the number of total rolls.
 Each percentage should be a double between 0 and 1 inclusively.
 For example, if we have a 4-sided die that has rolled each face 1 time and has the get_distribution() of:
{1,1,1,1}
then the get_percentages() function should return:
{0.25,0.25,0.25,0.25}

If there are no rolls yet, percentages should report 0 for each face in the vector.
 Otherwise, the percentage should be calculated by face rolls / total rolls.
 */


//class constructor that seeds the random number generator
GameDie::GameDie()
{
    srand(time(NULL));
    roll_counter.resize(FACES);

    for(int i=0; i<FACES; i++)
      roll_counter[i] = 0;
}

//overloaded constructor
GameDie::GameDie(unsigned int num)
{
    if( num == 0 )
    {
        roll_counter.resize(FACES);
    }
    else{
        roll_counter.resize(num);
    }
    for(int i=0; i<FACES; i++)
    {
        roll_counter[i] = 0;
    }

}

GameDie::vector<double> get_percentages(){
    vector<double> percentages;
    vector<int> distribution = get_distribution();

    int totalRolls = 0;
    for (int i = 0; i < FACES; i++){
        totalRolls += distribution[i];
    }
    for (int i = 0; i < FACES ; ++){
        percentages[i] = distribution / totalRolls;
    }

    return percentages;
}

//generate a random number between 1-n where n is the counter size
// (inclusive) and return it
int GameDie::roll()
{
    int roll = rand() % roll_counter.size();
    roll_counter[roll]++;
    return roll + 1;
}

// return the count of how many times each face has been rolled, as a vector
// where each face's count is at index face-1 (i.e. Face 1 is at index 0)
vector <int> GameDie::get_distribution(){
    return roll_counter;
}
