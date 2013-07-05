//
//  ScoreService.h
//  App42
//
//  Created by Dhruv Chopra on 3/30/13.
//  Copyright (c) 2013 Dhruv Chopra. All rights reserved.
//

#ifndef __App42__ScoreService__
#define __App42__ScoreService__

#include <iostream>
#include "App42Result.h"

using namespace std;

class ScoreService{

private:
	string SERVER_ADDRESS;
	string API_KEY;
	string SECRET_KEY;
	string GetBaseUrl(string resource);
	string BuildCompletePostUrl(string baseUrl, string body);
	static ScoreService* _instance;
	ScoreService();
public:

	/**
	* This is a constructor that takes
	* 
	* @param apiKey
	* @param secretKey
	* @param server
	* 
	*/
	static void Initialize(string apikey, string secretkey, string server="localhost:8082");
	static void Terminate();
	/**
	* Builds the instance of ScoreService.
	*
	* @return ScoreService - ScoreService Object
	*/
	static ScoreService* GetInstance();
	/**
	* Adds game score for the specified user.
	* 
	* @param gameName - Name of the game for which scores have to be added.
	* @param userName - The user for whom scores have to be added.
	* @param score - The scores that have to be added.
	* @return app42Result - The result of the request.
	* 
	*/

	void AddScore(string gameName, string userName, double score, IApp42Callback* callBack);
	/**
	* Deducts the score from users account for a particular Game
	* 
	* @param gameName - Name of the game for which scores have to be deducted
	* @param userName - The user for whom scores have to be deducted
	* @param score - The scores that have to be deducted
	* @return app42Result - The result of the request.
	* 
	*/
	void DeductScore(string gameName, string userName, double score, IApp42Callback* callBack);
};

#endif /* defined(__App42__ScoreService__) */
