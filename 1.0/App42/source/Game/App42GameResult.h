#ifndef __app42__App42GameResult__
#define __app42__App42GameResult__

#include <iostream>
#include "App42Result.h"
#include <vector>

struct App42Game;
struct App42Score;

class App42GameResult : public App42Result
{
public:
    App42GameResult(int code, const std::string& body, HttpRequest* request);
    std::vector<App42Game> games;
    std::vector<App42Score> scores;
    int totalRecords;
	~App42GameResult();    
    
private:
    void init();
};

typedef struct App42Score
{
	std::string userName;
    double value;
    std::string scoreId;
    std::string createdOn;
    int rank;
}App42Score;

typedef struct App42Game
{
    std::string name;
    std::string description;
}App42Game;

#endif /* defined(__app42__App42GameResult__) */
