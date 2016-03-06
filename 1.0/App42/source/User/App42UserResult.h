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
#include "UserService.h"

struct App42User;

class App42UserResult : public App42Result
{
public:
    App42UserResult(int code, const std::string& body, HttpRequest* request);
    std::vector<App42User> users;
    int totalRecords;
	~App42UserResult();
private:
    void Init();
};

typedef struct App42User
{
    std::string userName;
    std::string email;
    bool accountLocked;
    std::string sessionId;
    // @todo password? (hashed) ChangeUserPassword
    std::vector<std::string> roles;

    UserService::Profile profile;
}App42User;

#endif /* defined(__app42__App42UserResult__) */
