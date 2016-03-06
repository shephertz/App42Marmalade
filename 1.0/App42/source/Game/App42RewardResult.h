#ifndef __app42__App42RewardResult__
#define __app42__App42RewardResult__

#include <iostream>
#include "App42Result.h"
#include <vector>
#include <string>

struct App42Reward;

class App42RewardResult : public App42Result
{
public:
    App42RewardResult(int code, const std::string& body, HttpRequest* request);
    std::vector<App42Reward> rewards;
    int totalRecords;
	~App42RewardResult();    
    
private:
    void Init();
};

typedef struct App42Reward
{
    App42Reward() : points(0.0), rank(0) {}
    std::string name;
    std::string gameName;
    std::string userName;
	double points;
    std::string description;
    int rank;
}App42Reward;

#endif /* defined(__app42__App42RewardResult__) */
