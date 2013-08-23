//
//  UserService.h
//  App42
//
//  Created by Dhruv Chopra on 3/30/13.
//  Copyright (c) 2013 Dhruv Chopra. All rights reserved.
//

#ifndef __App42__UserService__
#define __App42__UserService__

#include <iostream>
#include "App42Result.h"

using namespace std;

class UserService{

private:
	string SERVER_ADDRESS;
	string API_KEY;
	string SECRET_KEY;
	string getBaseUrl(string resource);
	string buildCompletePostUrl(string baseUrl, string body);
	static UserService* _instance;
	UserService();
public:

	/**
	* This is a constructor that takes
	* 
	* @param apiKey
	* @param secretKey
	* @param server
	* 
	*/
	
	static void Initialize(string apikey, string secretkey, string server="api.shephertz.com");

	static void Terminate();

	/**
	* Builds the instance of UserService.
	*
	* @return UserService - UserService Object
	*/
	static UserService* getInstance();

	/**
	* Create a User with userName, password & emailAddress
	*
	* @param userName - Name of the User
	* @param password - Password for the User
	* @param email - Email address of the user
	* @return app42Result - The result of the request
	* 
	*/
	void CreateUser(string userName, string password, string email, IApp42Callback* callBack);

	/**
	* Authenticate user based on userName and password
	* 
	* @param userName  - UserName which should be unique for the App
	* @param password - Password for the User
	* @return app42Result - The result of the request
	*/
	void Authenticate(string userName, string password, IApp42Callback* callBack);

	/**
	* Gets the User details based on userName
	* 
	* @param userName - Name of the User to retrieve.
	* @return app42Result - The result of the request.
	*/
	void GetUser(string username, IApp42Callback* callBack);
	/**
	* Gets the details of all users
	* 
	* @return app42Result - The result of the request.
	*/
	void GetAllUsers(IApp42Callback* callBack);
};

#endif /* defined(__App42__UserService__) */
