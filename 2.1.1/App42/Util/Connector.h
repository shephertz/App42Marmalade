//
//  Connector.h
//  App42CPPSDK
//
//  Created by Rajeev Ranjan on 16/10/13.
//
//

#ifndef App42CPPSDK_Connector_h
#define App42CPPSDK_Connector_h

#include "App42Response.h"
#include "Common.h"
#include "App42HttpRequest.h"

using namespace std;

namespace Util
{
    
    static const char* url_encode(string &url)
    {

        return "";
    }
    
    static void printMap(map<std::string, std::string>map)
    {
        std::map<string,string>::iterator it;
        for(it=map.begin(); it!=map.end(); ++it)
        {
            app42Trace("%s=%s",it->first.c_str(),it->second.c_str());
        }
    }
    
    static void printVector(vector<std::string>vector)
    {
        std::vector<string>::iterator it;
        for(it=vector.begin(); it!=vector.end(); ++it)
        {
            app42Trace("%s",it->c_str());
        }
    }
    
    static void executePost(string baseUrl,std::vector<std::string> headers, const char* postData, App42Response* pTarget, SEL_App42Response pSelector)
    {
        App42HttpRequest* request = new App42HttpRequest(pTarget);
        request->executePost(baseUrl, postData, headers);
    }
    
    
    static void executePut(string baseUrl,std::vector<std::string> headers, const char* postData,App42Response* pTarget, SEL_App42Response pSelector)
    {
        App42HttpRequest* request = new App42HttpRequest(pTarget);
        request->executePut(baseUrl, postData, headers);
    }

    static void executeGet(string baseUrl,std::vector<std::string> headers,App42Response* pTarget, SEL_App42Response pSelector)
    {
        App42HttpRequest* request = new App42HttpRequest(pTarget);
        request->executeGet(baseUrl, headers);
    }
    
    static void executeDelete(string baseUrl,std::vector<std::string> headers,App42Response* pTarget, SEL_App42Response pSelector)
    {
        App42HttpRequest* request = new App42HttpRequest(pTarget);
        request->executeDelete(baseUrl, headers);
    }
}

#endif
