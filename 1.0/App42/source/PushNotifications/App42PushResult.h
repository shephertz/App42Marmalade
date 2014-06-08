//
//  App42UserResult.h
//  app42
//
//  Created by damucz on 6/8/14.
//
//

#ifndef __app42__App42PushResult__
#define __app42__App42PushResult__

#include "App42Result.h"
#include <vector>
#include <string>

struct App42PushChannel;

class App42PushResult : public App42Result
{
public:
    App42PushResult(int code, const std::string& body, HttpRequest* request);
	~App42PushResult();

    std::string message;
    std::string userName;
    std::string expiry;
    std::string deviceToken;
    std::string type;
    std::vector<App42PushChannel> channelList;
private:
    void Init();
};

typedef struct App42PushChannel
{
    std::string channelName;
    std::string description;
} App42PushChannel;

#endif /* defined(__app42__App42PushResult__) */
