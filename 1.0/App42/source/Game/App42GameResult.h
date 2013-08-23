#ifndef __app42__App42GameResult__
#define __app42__App42GameResult__

#include <iostream>
#include "App42Result.h"
#include <vector>

using namespace std;

struct App42Game;
struct App42Score;

class App42GameResult : public App42Result
{
public:
    App42GameResult(int code, string body, HttpRequest* request);
    vector<App42Game> games;
    vector<App42Score> scores;
	~App42GameResult();    
    
private:
    void init();
};

typedef struct App42Score
{
	string userName;
    double value;
    string scoreId;
}App42Score;

typedef struct App42Game
{
    string name;
    string description;
}App42Game;

#endif /* defined(__app42__App42GameResult__) */
