//
//  RewardService.h
//  App42
//
//  Created by Dhruv Chopra on 3/30/13.
//  Copyright (c) 2013 Dhruv Chopra. All rights reserved.
//

#ifndef __App42__RewardService__
#define __App42__RewardService__

#include "App42Result.h"
#include <string>
#include <map>
#include <vector>

/**
* Define a Reward e.g. Sword, Energy etc. Is needed for Reward Points
* 
* The Game service allows Game, User, Score and ScoreBoard Management on the
* Cloud. The service allows Game Developer to create a Game and then do in Game
* Scoring using the Score service. It also allows to maintain a Scoreboard
* across game sessions using the ScoreBoard service. One can query for average
* or highest score for user for a Game and highest and average score across
* users for a Game. It also gives ranking of the user against other users for a
* particular game. The Reward and RewardPoints allows the Game Developer to
* assign rewards to a user and redeem the rewards. E.g. One can give Swords or
* Energy etc. The services Game, Score, ScoreBoard, Reward, RewardPoints can be
* used in Conjunction for complete Game Scoring and Reward Management.
* 
* @see Game, RewardPoint, Score, ScoreBoard
*/
class RewardService{

private:
	std::string SERVER_ADDRESS;
	std::string API_KEY;
	std::string SECRET_KEY;
	std::string GetBaseUrl(const std::string& resource);
    std::string BuildCompletePostUrl(const std::string& resource, const std::string& body);
    std::string BuildCompleteGetUrl(const std::string& resource, const std::map<std::string, std::string>& params, bool exposeParams = false);
    std::string BuildCompleteGetUrl(const std::string& resource);

    static RewardService* _instance;
	RewardService();
public:
	/**
	* This is a constructor that takes
	* 
	* @param apiKey
	* @param secretKey
	* @param baseURL
	* 
	*/
	static void Initialize(const std::string& apikey, const std::string& secretkey, const std::string& server="api.shephertz.com");
	static void Terminate();
	/**
	* Builds the instance of ScoreService.
	*
	* @return ScoreService - ScoreService Object
	*/
	static RewardService* GetInstance();

	/**
	* Creates Reward. Reward can be Sword, Energy etc. When Reward Points have
	* to be added the Reward name created using this method has to be
	* specified.
	* 
	* @param rewardName - The reward that has to be created
	* @param description - The description of the reward to be created.
	* @return app42Result - The result of the request.
	* 
	*/
	void CreateReward(const std::string& rewardName, const std::string& description, IApp42Callback* callBack);

	/**
	* Fetches all the Rewards
	* 
	* @return app42Result - The result of the request.
	* 
	*/
	void GetAllRewards(IApp42Callback* callBack);

    /**
    * Fetches the count of all the Rewards.
    * 
    * @return app42Result - The result of the request.
    * 
    */
    void GetAllRewardsCount(IApp42Callback* callBack);

    /**
    * Fetches all the rewards by paging.
    *
    * @param max - Maximum number of records to be fetched.
    * @param offset - From where the records are to be fetched.
    *
    * @return app42Result - The result of the request.
    * 
    */
    void GetAllRewardsPaging(int max, int offset, IApp42Callback* callBack);

    /**
    * Fetch the reward by the specified name.
    *
    * @param rewardName - Name of the reward that has to be fetched.
    *
    * @return app42Result - The result of the request.
    * 
    */
    void GetRewardByName(const std::string& rewardName, IApp42Callback* callBack);

	/**
	* Adds the reward points to an users account. Reward Points can be earned
	* by the user which can be redeemed later.
	* 
	* @param gameName - Name of the game for which reward points have to be added
	* @param userName - The user for whom reward points have to be added
	* @param rewardName - The rewards for which reward points have to be added
	* @param rewardPoints - The points that have to be added
	* @return app42Result - The result of the request.
	* 
	*/
	void EarnReward(const std::string& gameName, const std::string& userName, const std::string& rewardName, double rewardPoints, IApp42Callback* callBack);
	
    /**
	* Deducts the reward points from the earned rewards by a user.
	* 
	* @param gameName - Name of the game for which reward points have to be deducted
	* @param userName - The user for whom reward points have to be deducted
	* @param rewardName - The rewards for which reward points have to be deducted
	* @param rewardPoints - The points that have to be deducted
	* @return app42Result - The result of the request.
	* 
	*/
	void RedeemReward(const std::string& gameName, const std::string& userName, const std::string& rewardName, double rewardPoints, IApp42Callback* callBack);

	/**
	* Fetches the reward points for a particular user
	* 
	* @param gameName - Name of the game for which reward points have to be fetched
	* @param userName - The user for whom reward points have to be fetched
	* @return app42Result - The result of the request.
	* 
	*/
	void GetGameRewardPointsForUser(const std::string& gameName, const std::string& userName, IApp42Callback* callBack);

    /**
    * This function provides a list of specified number of top reward earners for a specific game.
    *
    * @param gameName - Name of the game for which reward earners are to be fetched.
    * @param rewardName - The user for whom reward points have to be fetched.
    * @param max - Specifies the number of top earners to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetTopNRewardEarners(const std::string& gameName, const std::string& reward, int max, IApp42Callback* callBack);

    /**
    * This function returns you a list of group wise users who earned the top rewards in the specified game.
    *
    * @param gameName - Name of the game for which reward earners are to be fetched.
    * @param rewardName - The user for whom reward points have to be fetched.
    * @param userList - List of group wise users earning specified rewards.
    *
    * @return app42Result - The result of the request.
    */
    void GetTopNRewardEarnersByGroup(const std::string& gameName, const std::string& rewardName, const std::vector<std::string>& userList, IApp42Callback* callBack);

    /**
    * This function returns you the details of all the specific rewards earned by the specified user.
    *
    * @param userName - Name of the user whose rewards are to be fetched.
    * @param rewardName - Name of the reward for which details are to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetAllRewardsByUser(const std::string& userName, const std::string& rewardName, IApp42Callback* callBack);

    /**
    * 
    * @param gameName - Name of the game for which top reward earners are to be fetched
    * @param rewardName - Name of the reward for which top earners are to be listed
    * @param userName - Name of the user whose rewards are to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetUserRankingOnReward(const std::string& gameName, const std::string& rewardName, const std::string& userName, IApp42Callback* callBack);
};

#endif /* defined(__App42__RewardService__) */
