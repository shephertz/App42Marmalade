//
//  App42Response.h
//  App42
//
//  Created by Dhruv Chopra on 3/30/13.
//  Copyright (c) 2013 Dhruv Chopra. All rights reserved.
//

#ifndef App42Result_h
#define App42Result_h

#include <iostream>


// fwd declaration
class App42Result;
class HttpRequest;

class IApp42Callback{
  
public:
    virtual void onResult(App42Result* result) = 0;
};

/*
 Represents the response from the App42 cloud REST server
 */
class App42Result{

protected:
    int _result;
    std::string _body;
    HttpRequest* _httpRequest;
    
public:
    App42Result(int code, std::string body, HttpRequest* request);
    
    virtual ~App42Result();
    
    // The HTTP response code.
    int getCode();
    
    // The JSON body of the HTTP response containing details
    std::string getBody();
};


#endif
