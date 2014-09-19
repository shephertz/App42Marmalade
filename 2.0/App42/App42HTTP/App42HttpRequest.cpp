//
//  HttpClient.cpp
//  App42
//
//  Created by Dhruv Chopra on 3/30/13.
//  Copyright (c) 2013 Dhruv Chopra. All rights reserved.
//

#include "App42HttpRequest.h"
#include "IwHTTP.h"
#include "Signing.h"
#include "App42HttpResponse.h"
#include "App42RewardResponse.h"
#include "App42StorageResponse.h"
#include "App42TimerResponse.h"
#include "App42AvatarResponse.h"
#include "App42BuddyResponse.h"
#include "App42CustomCodeResponse.h"
#include "App42EmailResponse.h"
#include "App42SocialResponse.h"
#include "App42PushNotificationResponse.h"
#include "App42SessionResponse.h"
#include "App42GameResponse.h"
#include "App42UserResponse.h"
#include <typeinfo.h>

static int32 GotData(void*, void* userData)
{    
    // Firstly see if there's an error condition.
    App42HttpRequest* caller = (App42HttpRequest*)userData;
    
    CIwHTTP* theHttpObject = caller->getNativeApp42HttpRequest();

    // Firstly see if there's an error condition.
    if (theHttpObject->GetStatus() == S3E_RESULT_ERROR)
    {
        // Something has gone wrong
        caller->onComplete(500);
    }
    else if (theHttpObject->ContentReceived() != theHttpObject->ContentLength())
    {
        
        // We have some data but not all of it. We need more space.
        uint32 oldLen = caller->_resultLen;
        // If iwhttp has a guess how big the next bit of data is (this
        // basically means chunked encoding is being used), allocate
        // that much space. Otherwise guess.
        if ((caller->_resultLen) < theHttpObject->ContentExpected()){
            (caller->_resultLen) = theHttpObject->ContentExpected();
        }
        else{
            (caller->_resultLen) += 1024;
        }
        IwDebugTraceLinePrintf("GotData::Realloc data len is %d", caller->_resultLen);
        // Allocate some more space and fetch the data.
        char **resultBuffer = &(caller->_result);
        *resultBuffer = (char*)s3eRealloc(caller->_result, (caller->_resultLen));
        theHttpObject->ReadContent(&(caller->_result)[oldLen], (caller->_resultLen) - oldLen, GotData, caller);
    }
    else
    {
        
        IwDebugTraceLinePrintf("GotData::Status is %d", theHttpObject->GetStatus());
        IwDebugTraceLinePrintf("GotData::ContentReceived is %s", caller->_result);
        IwDebugTraceLinePrintf("GotData::ContentReceived data len is %d", caller->_resultLen);
        caller->onComplete(theHttpObject->GetResponseCode());
    }
    
    return 0;
}

//-----------------------------------------------------------------------------
// Called when the response headers have been received
//-----------------------------------------------------------------------------
static int32 GotHeaders(void*, void* userData)
{
    App42HttpRequest* caller = (App42HttpRequest*)userData;
    
    CIwHTTP* theHttpObject = caller->getNativeApp42HttpRequest();
    
    if (theHttpObject->GetStatus() == S3E_RESULT_ERROR)
    {
		IwDebugTraceLinePrintf("GotHeaders::ERROR!");
        caller->onComplete(500);
    }
    else
    {
        caller->_resultLen = theHttpObject->ContentExpected();
        if (!(caller->_resultLen))
        {
            (caller->_resultLen) = 1024;
        }
        
        char **resultBuffer = &(caller->_result);
        s3eFree(*resultBuffer);
        *resultBuffer = (char*)s3eMalloc((caller->_resultLen) + 1);
        (*resultBuffer)[(caller->_resultLen)] = 0;
        theHttpObject->ReadDataAsync(*resultBuffer, (caller->_resultLen), 0, GotData, caller);
    }
    
    return 0;
}

void App42HttpRequest::onComplete(int httpcode){
    App42HttpResponse* app42HttpResponse = new App42HttpResponse(this);
    
    app42HttpResponse->setResponseCode(httpcode);
    app42HttpResponse->setResponseData(_result);
    if (httpcode==200)
    {
        app42HttpResponse->setSucceed(true);
    }
    else
    {
        app42HttpResponse->setSucceed(false);
    }
    
    if (_callBack)
    {
        if (( typeid(App42UserResponse) == typeid(*_callBack) ))
        {
            ((App42UserResponse*)_callBack)->App42UserResponse::onComplete(this, app42HttpResponse);
        }
        else if (( typeid(App42StorageResponse) == typeid(*_callBack) ))
        {
            ((App42StorageResponse*)_callBack)->App42StorageResponse::onComplete(this, app42HttpResponse);
        }
        else if (( typeid(App42TimerResponse) == typeid(*_callBack) ))
        {
            ((App42TimerResponse*)_callBack)->App42TimerResponse::onComplete(this, app42HttpResponse);
        }
        else if (( typeid(App42AvatarResponse) == typeid(*_callBack) ))
        {
            ((App42AvatarResponse*)_callBack)->App42AvatarResponse::onComplete(this, app42HttpResponse);
        }
        else if (( typeid(App42BuddyResponse) == typeid(*_callBack) ))
        {
            ((App42BuddyResponse*)_callBack)->App42BuddyResponse::onComplete(this, app42HttpResponse);
        }
        else if (( typeid(App42CustomCodeResponse) == typeid(*_callBack) ))
        {
            ((App42CustomCodeResponse*)_callBack)->App42CustomCodeResponse::onComplete(this, app42HttpResponse);
        }
        else if (( typeid(App42EmailResponse) == typeid(*_callBack) ))
        {
            ((App42EmailResponse*)_callBack)->App42EmailResponse::onComplete(this, app42HttpResponse);
        }
        else if (( typeid(App42SocialResponse) == typeid(*_callBack) ))
        {
            ((App42SocialResponse*)_callBack)->App42SocialResponse::onComplete(this, app42HttpResponse);
        }
        else if (( typeid(App42PushNotificationResponse) == typeid(*_callBack) ))
        {
            ((App42PushNotificationResponse*)_callBack)->App42PushNotificationResponse::onComplete(this, app42HttpResponse);
        }
        else if (( typeid(App42SessionResponse) == typeid(*_callBack) ))
        {
            ((App42SessionResponse*)_callBack)->App42SessionResponse::onComplete(this, app42HttpResponse);
        }
        else if (( typeid(App42RewardResponse) == typeid(*_callBack) ))
        {
            ((App42RewardResponse*)_callBack)->App42RewardResponse::onComplete(this, app42HttpResponse);
        }
        else if (( typeid(App42GameResponse) == typeid(*_callBack) ))
        {
            ((App42GameResponse*)_callBack)->App42GameResponse::onComplete(this, app42HttpResponse);
        }
    }
}

CIwHTTP* App42HttpRequest::getNativeApp42HttpRequest(){
    return _httpObject;
}

App42HttpRequest::App42HttpRequest(App42Response* callback)
{
    _callBack = callback;
    _result = NULL;
    _httpObject = NULL;
}



App42HttpRequest::~App42HttpRequest(){

    if(_httpObject != NULL){
        delete _httpObject;
    }
    if(_result != NULL){
        s3eFree(_result);
    }
}

void App42HttpRequest::executeGet(string url,vector<string>headers)
{
    _httpObject = new CIwHTTP;
    buildHeaders(headers);
	_httpObject->SetRequestHeader("Accept", "application/json");
    _httpObject->Get(url.c_str(), GotHeaders, this);
}

void App42HttpRequest::executeDelete(string url,vector<string>headers)
{
    _httpObject = new CIwHTTP;
    buildHeaders(headers);
    _httpObject->SetRequestHeader("Accept", "application/json");
    _httpObject->Delete(url.c_str(), GotHeaders, this);
}

void App42HttpRequest::executePost(string url, string body,vector<string>headers){
    _httpObject = new CIwHTTP;
    
    buildHeaders(headers);
	_httpObject->SetRequestHeader("Accept", "application/json");
	_httpObject->SetRequestHeader("Content-Type", "application/json");
	_httpObject->Post(url.c_str(), body.c_str(),body.length(),GotHeaders, this);
}

void App42HttpRequest::executePut(string url, string body,vector<string>headers){
    _httpObject = new CIwHTTP;
    
    buildHeaders(headers);
    _httpObject->SetRequestHeader("Accept", "application/json");
    _httpObject->SetRequestHeader("Content-Type", "application/json");
    _httpObject->Put(url.c_str(), body.c_str(),body.length(),GotHeaders, this);
}

void App42HttpRequest::buildHeaders(vector<string>headers)
{
    vector<string>::iterator it;
    for (it=headers.begin(); it!=headers.end(); it++)
    {
        std::size_t loc = it->find(':');
        _httpObject->SetRequestHeader(it->substr(0,loc).c_str(), it->substr(loc+1));
    }
}
