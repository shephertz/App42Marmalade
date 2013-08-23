#ifndef __app42__App42RewardResult__
#define __app42__App42RewardResult__

#include <iostream>
#include "App42Result.h"
#include <vector>

using namespace std;

struct App42Reward;

class App42RewardResult : public App42Result
{
public:
    App42RewardResult(int code, string body, HttpRequest* request);
    vector<App42Reward> rewards;
	~App42RewardResult();    
    
private:
    void init();
};

typedef struct App42Reward
{
    string name;
    string gameName;
	double points;
    string description;
}App42Reward;

#endif /* defined(__app42__App42RewardResult__) */
