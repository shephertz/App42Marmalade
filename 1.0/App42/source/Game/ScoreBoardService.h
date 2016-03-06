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
#include <map>
#include <vector>
#include "App42Result.h"

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
	std::string SERVER_ADDRESS;
	std::string API_KEY;
	std::string SECRET_KEY;
	std::string GetBaseUrl(const std::string& resource);
	std::string BuildCompletePostUrl(const std::string& baseUrl, const std::string& body);
    std::string BuildCompleteGetUrl(const std::string& baseUrl, const std::map<std::string, std::string>& data);
    std::string BuildCompleteGetUrl(const std::string& baseUrl);
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
	static void Initialize(const std::string& apikey, const std::string& secretkey, const std::string& server="api.shephertz.com");
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
	void SaveUserScore(const std::string& gameName,const std::string& userName, double score, IApp42Callback* callBack);
    /**
     * Retrieves the scores for the specified user of a specific game.
     *
     * @param gameName - Name of the game for which scores are to be fetched.
     * @param userName - User for which scores are to be fetched.
     * @return app42Result - The result of the request.
     *
     */
    void GetScoresByUser(const std::string& gameName, const std::string& userName, IApp42Callback* callBack);
	/**
	* Retrieves the highest game score for the specified user
	* 
	* @param gameName - Name of the game for which highest score has to be saved
	* @param userName - The user for which highest score has to be saved
	* @return app42Result - The result of the request.
	* 
	*/
	void GetHighestScoreByUser(const std::string& gameName,const std::string& userName , IApp42Callback* callBack);
	/**
	* Retrieves the lowest game score for the specified user
	* 
	* @param gameName - Name of the game for which highest score has to be saved
	* @param userName - The user for which highest score has to be saved
	* @return app42Result - The result of the request.
	* 
	*/
	void GetLowestScoreByUser(const std::string& gameName,const std::string& userName , IApp42Callback* callBack);
	/**
	* Retrieves the average game score for the specified user
	* 
	* @param gameName - Name of the game for which average score has to be fetched
	* @param userName - The user for which average score has to be fetched
	* @return app42Result - The result of the request.
	* 
	*/
	void GetAverageScoreByUser(const std::string& gameName, const std::string& userName, IApp42Callback* callBack);
	/**
	* Retrieves the Top Rankings for the specified game
	* 
	* @param gameName - Name of the game for which ranks have to be fetched
	* @return app42Result - The result of the request.
	* 
	*/
	void GetTopRankings(const std::string& gameName,IApp42Callback* callBack);
	/**
	* Retrieves the Top Rankings for the specified game and time interval
	* 
	* @param gameName - Name of the game for which ranks have to be fetched
    * @param startDate - Start of the time interval in format 'yyyy-mm-ddThh:mm:ss.miliZ'
    * @param endDate - End of the time interval in format 'yyyy-mm-ddThh:mm:ss.miliZ'
	* @return app42Result - The result of the request.
	* 
	*/
    void GetTopRankingsByDate(const std::string& gameName, const std::string& startDate, const std::string& endDate, IApp42Callback* callBack);
	/**
	* Retrieves the Top Rankings for the specified game and group of users
	* 
	* @param gameName - Name of the game for which ranks have to be fetched
    * @param userList - List of the users in group to be fetched
	* @return app42Result - The result of the request.
	* 
	*/
    void GetTopRankingsByGroup(const std::string& gameName, const std::vector<std::string>& userList, IApp42Callback* callBack);
	/**
	* Retrieves the Top N Rankings for the specified game
	* 
	* @param gameName - Name of the game for which ranks have to be fetched
    * @param max - Maximum number of records to be fetched.
	* @return app42Result - The result of the request.
	* 
	*/
	void GetTopNRankings(const std::string& gameName, int max, IApp42Callback* callBack);
    /**
    * Retrieves the Top N Ranked users for the specified game and time interval
    * 
    * @param gameName - Name of the game for which ranks have to be fetched
    * @param max - Maximum number of records to be fetched.
    * @return app42Result - The result of the request.
    * 
    */
    void GetTopNRankers(const std::string& gameName, int max, IApp42Callback* callBack);
    /**
    * Retrieves the Top N Ranked users for the specified game
    * 
    * @param gameName - Name of the game for which ranks have to be fetched
    * @param startDate - Start of the time interval in format 'yyyy-mm-ddThh:mm:ss.miliZ'
    * @param endDate - End of the time interval in format 'yyyy-mm-ddThh:mm:ss.miliZ'
    * @param max - Maximum number of records to be fetched.
    * @return app42Result - The result of the request.
    * 
    */
    void GetTopNRankersByDate(const std::string& gameName, const std::string& startDate, const std::string& endDate, int max, IApp42Callback* callBack);
	/**
	* Retrieves the Top N Ranked users for the specified game and group of users
	* 
	* @param gameName - Name of the game for which ranks have to be fetched
    * @param userList - List of the users in group to be fetched
    * @param max - Maximum number of records to be fetched.
	* @return app42Result - The result of the request.
	* 
	*/
    void GetTopNRankersByGroup(const std::string& gameName, const std::vector<std::string>& userList, int max, IApp42Callback* callBack);
	/**
	* Retrieves the User Ranking for the specified game
	* 
	* @param gameName - Name of the game for which ranks have to be fetched.
	* @param userName - Name of the user for which ranks have to be fetched.
	* @return app42Result - The result of the request.
	* 
	*/
	void GetUserRanking(const std::string& gameName, const std::string& userName,IApp42Callback* callBack); 
	/**
	* This function returns the top score attained by the specified user in the game.
	* 
	* @param gameName - Name of the game
	* @param userName - Name of the user for which score has to retrieve
	* @return app42Result - The result of the request.
	* 
	*/
	void GetLastScoreByUser(const std::string& gameName,const std::string& userName,IApp42Callback* callBack);
	/**
	* This function returns the score attained by the specified user in the last game session.
	* 
	* @param userName - Name of the user for which score has to retrieve
	* @return app42Result - The result of the request.
	* 
	*/
	void GetLastGameScore(const std::string& gameName, IApp42Callback* callBack);
	/**
	* Edit the score value of the game in existing score id.
	* 
    * @param scoreId - ScoreId of the gameUser for which value has to be edited.
    * @param gameScore - The score that has to be added.
	* @return app42Result - The result of the request.
	* 
	*/
	void EditScoreValueById(const std::string& scoreId, double gameScore, IApp42Callback* callBack);
    /**
    * This function returns the specified number of top rankers in a specific game from buddy group.
    * @param gameName- Name of the game.
    * @param userName- Name of the user who fetch top rankers from group.
    * @param ownerName- Group owner name.
    * @param groupName- Name of the group.
    * @return app42Result - The result of the request.
    * 
    */
    void GetTopRankersFromBuddyGroup(const std::string& gameName, const std::string& userName, const std::string& ownerName, const std::string& groupName, IApp42Callback* callBack);
    /**
    * This method helps to fetch the top N rankers from your facebook friends.
    * 
    * @param gameName - Name of the game for which ranks have to be fetched
    * @param accessToken - Facebook access token of the user who is fetching the record.
    * @param max - Maximum number of records to be fetched.
    * @return app42Result - The result of the request.
    * 
    */
    void GetTopNRankersFromFacebook(const std::string& gameName, const std::string& accessToken, int max, IApp42Callback* callBack);
    /**
    * Fetch the top N rankers from your facebook friends between specific date.
    * 
    * @param gameName - Name of the game for which ranks have to be fetched
    * @param accessToken - Facebook access token of the user who is fetching the record.
    * @param startDate - Start of the time interval in format 'yyyy-mm-ddThh:mm:ss.miliZ'
    * @param endDate - End of the time interval in format 'yyyy-mm-ddThh:mm:ss.miliZ'
    * @param max - Maximum number of records to be fetched.
    * @return app42Result - The result of the request.
    * 
    */
    void GetTopNRankersFromFacebookByDate(const std::string& gameName, const std::string& accessToken, const std::string& startDate, const std::string& endDate, int max, IApp42Callback* callBack);
    /**
    * Fetch the top N target rankers from your game.Required Parameters
    * @param gameName - Game name for which top N rankers has to fetch.
    * @param max - Max number of rankers to be fetched.
    * @return app42Result - The result of the request.
    * 
    */
    void GetTopNTargetRankers(const std::string& gameName, int max, IApp42Callback* callBack);
};

#endif /* defined(__App42__GameService__) */
