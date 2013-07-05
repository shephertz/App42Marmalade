//
//  RewardService.h
//  App42
//
//  Created by Dhruv Chopra on 3/30/13.
//  Copyright (c) 2013 Dhruv Chopra. All rights reserved.
//

#ifndef __App42__RewardService__
#define __App42__RewardService__

#include <iostream>
#include "App42Result.h"

using namespace std;
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
	string SERVER_ADDRESS;
	string API_KEY;
	string SECRET_KEY;
	string GetBaseUrl(string resource);
	string BuildCompletePostUrl(string baseUrl, string body);
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
	static void Initialize(string apikey, string secretkey, string server="api.shephertz.com");
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
	void CreateReward(string rewardName,string description, IApp42Callback* callBack);
	/**
	* Fetches all the Rewards
	* 
	* @return app42Result - The result of the request.
	* 
	*/
	void GetAllRewards(IApp42Callback* callBack);
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
	void EarnRewards(string gameName, string userName, string rewardName, double rewardPoints,IApp42Callback* callBack);
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
	void RedeemRewards(string gameName, string userName, string rewardName, double rewardPoints,IApp42Callback* callBack);
	/**
	* Fetches the reward points for a particular user
	* 
	* @param gameName - Name of the game for which reward points have to be fetched
	* @param userName - The user for whom reward points have to be fetched
	* @return app42Result - The result of the request.
	* 
	*/
	void GetGameRewardPointsForUser(string gameName, string userName, IApp42Callback* callBack);
};

#endif /* defined(__App42__RewardService__) */
