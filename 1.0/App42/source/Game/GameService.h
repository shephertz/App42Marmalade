//
//  GameService.h
//  App42
//
//  Created by Dhruv Chopra on 3/30/13.
//  Copyright (c) 2013 Dhruv Chopra. All rights reserved.
//

#ifndef __App42__GameService__
#define __App42__GameService__

#include "App42Result.h"
#include <map>
#include <string>

class GameService{

private:
	std::string SERVER_ADDRESS;
	std::string API_KEY;
	std::string SECRET_KEY;
	std::string GetBaseUrl(const std::string& resource);
	std::string BuildCompletePostUrl(const std::string& baseUrl, const std::string& body);
    std::string BuildCompleteGetUrl(const std::string& baseUrl, const std::map<std::string, std::string>& data);
    std::string BuildCompleteGetUrl(const std::string& baseUrl);
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
	static void Initialize(const std::string & apikey, const std::string & secretkey, const std::string & server="api.shephertz.com");
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
	void CreateGame(const std::string & gameName,const std::string & description, IApp42Callback* callBack);
	/**
	* Retrieves the game by the specified name
	* 
	* @param gameName - Name of the game that has to be fetched
	* @return app42Result - The result of the request.
	* 
	*/
	void GetGameByName(const std::string & gameName,IApp42Callback* callBack);
	/**
	* Fetches all games for the App
	* 
	* @return app42Result - The result of the request.
	* 
	*/
	void GetAllGames(IApp42Callback* callBack);
	/**
	* Retrieves all games count for the App
	* 
	* @return app42Result - The result of the request.
	* 
	*/
	void GetAllGamesCount(IApp42Callback* callBack);
	/**
	* Fetches all games for the App
	* 
    * @param max - Maximum number of records to be fetched.
    * @param offset - From where the records are to be fetched
	* @return app42Result - The result of the request.
	* 
	*/
	void GetAllGamesWithPaging(int max, int offset, IApp42Callback* callBack);

};

#endif /* defined(__App42__GameService__) */
