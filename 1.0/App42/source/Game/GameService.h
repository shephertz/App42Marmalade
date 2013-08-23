//
//  GameService.h
//  App42
//
//  Created by Dhruv Chopra on 3/30/13.
//  Copyright (c) 2013 Dhruv Chopra. All rights reserved.
//

#ifndef __App42__GameService__
#define __App42__GameService__

#include <iostream>
#include "App42Result.h"

using namespace std;

class GameService{

private:
	string SERVER_ADDRESS;
	string API_KEY;
	string SECRET_KEY;
	string GetBaseUrl(string resource);
	string BuildCompletePostUrl(string baseUrl, string body);
	static GameService* _instance;
	GameService();
public:
	/**
	* This is a constructor that takes
	* 
	* @param apiKey
	* @param secretKey
	* @param baseURL
	* 
	*/
	static void Initialize(string apikey, string secretkey, string server="api.shephertz.com");
	static void Terminate();
	/**
	* Builds the instance of GameService.
	*
	* @return GameService - GameService Object
	*/
	static GameService* GetInstance();

	/**
	* Creates a game on the cloud
	* 
	* @param gameName - Name of the game that has to be created.
	* @param description - Description of the game to be created.
	* @return app42Result - The result of the request.
	* 
	*/
	void CreateGame(string gameName,string description, IApp42Callback* callBack);
	/**
	* Retrieves the game by the specified name
	* 
	* @param gameName - Name of the game that has to be fetched
	* @return app42Result - The result of the request.
	* 
	*/
	void GetGamebyName(string gameName,IApp42Callback* callBack);
	/**
	* Fetches all games for the App
	* 
	* @return app42Result - The result of the request.
	* 
	*/
	void GetAllGames(IApp42Callback* callBack);

};

#endif /* defined(__App42__GameService__) */
