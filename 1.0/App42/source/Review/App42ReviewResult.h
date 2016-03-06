//
//  App42ReviewResult.h
//  app42
//
//  Created by damucz on 6/14/14.
//
//

#ifndef __app42__App42ReviewResult__
#define __app42__App42ReviewResult__

#include "App42Result.h"
#include <vector>
#include <string>

struct App42Review;

class App42ReviewResult : public App42Result
{
public:
    App42ReviewResult(int code, const std::string& body, HttpRequest* request);
	~App42ReviewResult();

    std::vector<App42Review> reviews;
    int totalRecords;
private:
    void Init();
};

typedef struct App42Review
{
    App42Review() : rating(0.0) {}
    std::string userID;
    std::string itemID;
    std::string reviewID;
    std::string status;
    std::string comment;
    double rating;
    std::string createdOn;
} App42Review;

#endif /* defined(__app42__App42ReviewResult__) */
