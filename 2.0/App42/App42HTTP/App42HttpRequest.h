//
//  HttpClient.h
//  App42
//
//  Created by Dhruv Chopra on 3/30/13.
//  Copyright (c) 2013 Dhruv Chopra. All rights reserved.
//

#ifndef App42HttpRequest__h
#define App42HttpRequest__h

#include <iostream>
//#include "App42Response.h"
#include "IwHTTP.h"
#include "IwGx.h"
#include <vector>
#include <map>

using namespace std;

class App42HttpResponse;
class App42HttpRequest;
class App42Response;

class App42HttpRequest{
  
public:
    App42HttpRequest(App42Response *callback);
    
    void buildHeaders(vector<string>headers);
    void executePost(string url, string body,vector<string>headers);
    void executePut(string url, string body,vector<string>headers);
    void executeGet(string url,vector<string>headers);
    void executeDelete(string url,vector<string>headers);
    void executeMultiPartWithFileData(string requestName,string fileName, unsigned char* postData, int fileDatSize,map<string, string>postParams,string url, vector<string>headers);
    void executeMultiPartWithFile(string requestName,string fileName, string filePath,map<string, string>postParams,string url, string body,vector<string>headers);
    
    CIwHTTP* getNativeApp42HttpRequest();
    
    ~App42HttpRequest();
    virtual void onComplete(int httpcode);
    char* _result;
    uint32 _resultLen;
    
protected:
    App42Response* _callBack;

private:
    CIwHTTP* _httpObject;
    size_t HandleData(char *buffer, size_t size, size_t nmemb);
    static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);
};

#endif /* defined(__App42__HttpClient__) */
