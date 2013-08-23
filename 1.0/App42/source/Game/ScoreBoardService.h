//
//  GameService.h
//  App42
//
//  Created by Dhruv Chopra on 3/30/13.
//  Copyright (c) 2013 Dhruv Chopra. All rights reserved.
//

#ifndef __App42__ScoreBoardService__
#define __App42__ScoreBoardService__

#include <iostream>
#include "App42Result.h"

using namespace std;

/**
 * ScoreBoard allows storing, retrieving, querying and ranking scores for users
 * and Games across Game Session. The Game service allows Game, User, Score and
 * ScoreBoard Management on the Cloud. The service allows Game Developer to
 * create a Game and then do in Game Scoring using the Score service. It also
 * allows to maintain a Scoreboard across game sessions using the ScoreBoard
 * service. One can query for average or highest score for user for a Game and
 * highest and average score across users for a Game. It also gives ranking of
 * the user against other users for a particular game. The Reward and
 * RewardPoints allows the Game Developer to assign rewards to a user and redeem
 * the rewards. E.g. One can give Swords or Energy etc. The services Game,
 * Score, ScoreBoard, Reward, RewardPoints can be used in Conjunction for
 * complete Game Scoring and Reward Management.
 * 
 * @see Game, RewardPoint, Score
 * 
 */
class ScoreBoardService{

private:
	string SERVER_ADDRESS;
	string API_KEY;
	string SECRET_KEY;
	string GetBaseUrl(string resource);
	string BuildCompletePostUrl(string baseUrl, string body);
	static ScoreBoardService* _instance;
	ScoreBoardService();
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
	* Builds the instance of ScoreBoardService.
	*
	* @return ScoreBoardService - ScoreBoardService Object
	*/
	static ScoreBoardService* GetInstance();
	/**
	* Saves the User score for a game
	* 
	* @param gameName - Name of the game for which score has to be saved.
	* @param userName - The user for which score has to be saved.
	* @param score - The sore that has to be saved.
	* @return app42Result - The result of the request.
	* 
	*/
	void SaveUserScore(string gameName,string userName, double score, IApp42Callback* callBack);
	/**
	* Retrieves the highest game score for the specified user
	* 
	* @param gameName - Name of the game for which highest score has to be fetched
	* @param userName - The user for which highest score has to be fetched
	* @return app42Result - The result of the request.
	* 
	*/
	void GetHighestScoreByUser(string gameName,string userName , IApp42Callback* callBack);
	/**
	* Retrieves the average game score for the specified user
	* 
	* @param gameName - Name of the game for which average score has to be fetched
	* @param userName - The user for which average score has to be fetched
	* @return app42Result - The result of the request.
	* 
	*/
	void GetAverageScoreByUser(string gameName, string userName, IApp42Callback* callBack);
	/**
	* This function returns the top score attained by the specified user in the game.
	* 
	* @param gameName - Name of the game
	* @param userName - Name of the user for which score has to retrieve
	* @return app42Result - The result of the request.
	* 
	*/
	void GetLastScoreByUser(string gameName,string userName,IApp42Callback* callBack);
	/**
	* Retrieves the Top Rankings for the specified game
	* 
	* @param gameName - Name of the game for which ranks have to be fetched
	* @return app42Result - The result of the request.
	* 
	*/
	void GetTopRankings(string gameName,IApp42Callback* callBack);
	/**
	* Retrieves the User Ranking for the specified game
	* 
	* @param gameName - Name of the game for which ranks have to be fetched.
	* @param userName - Name of the user for which ranks have to be fetched.
	* @return app42Result - The result of the request.
	* 
	*/
	void GetUserRanking(string gameName, string userName,IApp42Callback* callBack); 
};

#endif /* defined(__App42__GameService__) */
