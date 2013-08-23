//
//  App42UserResult.h
//  app42
//
//  Created by Dhruv Chopra on 6/5/13.
//
//

#ifndef __app42__App42UserResult__
#define __app42__App42UserResult__

#include <iostream>
#include "App42Result.h"
#include <vector>

using namespace std;

struct App42User;

class App42UserResult : public App42Result
{
public:
    App42UserResult(int code, string body, HttpRequest* request);
    vector<App42User> users;
	~App42UserResult();
private:
    void init();
};

typedef struct App42User
{
    string userName;
    string email;
    bool accountLocked;
    
}App42User;

#endif /* defined(__app42__App42UserResult__) */
