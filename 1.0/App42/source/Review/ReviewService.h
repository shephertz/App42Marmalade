//
//  ReviewService.h
//  App42
//
//  Created by damucz on 6/14/14.
//

#ifndef __App42__ReviewService__
#define __App42__ReviewService__

#include "App42Result.h"
#include <map>
#include <vector>
#include <string>

class ReviewService{
private:
	std::string SERVER_ADDRESS;
	std::string API_KEY;
	std::string SECRET_KEY;
	std::string GetBaseUrl(const std::string& resource);
    std::string BuildCompletePostUrl(const std::string& resource, const std::string& body);
    std::string BuildCompleteGetUrl(const std::string& resource, const std::map<std::string, std::string>& params, bool exposeParams = false);
    std::string BuildCompleteGetUrl(const std::string& resource);

	static ReviewService* _instance;
	ReviewService();
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
	* Builds the instance of ReviewService.
	*
	* @return ReviewService - ReviewService Object
	*/
	static ReviewService* GetInstance();

    /**
    * Creates review for the specified item with comment and rating on that item.
    *
    * @param userID - The user who created the review.
    * @param itemID - The item for which the review has to be created.
    * @param reviewComment - Comment on review.
    * @param reviewRating - Rating on the item.e.g 1,2 or etc
    *
    * @return app42Result - The result of the request.
    */
    void CreateReview(const std::string& userID, const std::string& itemID, const std::string& reviewComment, double reviewRating, IApp42Callback* callBack);

    /**
    * Fetches all reviews in the App.
    *
    * @return app42Result - The result of the request.
    */
    void GetAllReviews(IApp42Callback* callBack);

    /**
    * Fetches count of all reviews in the App.
    *
    * @return app42Result - The result of the request.
    */
    void GetAllReviewsCount(IApp42Callback* callBack);

    /**
    * Fetches all reviews in the App by Paging.
    *
    * @param max - Maximum number of records to be fetched.
    * @param offset - From where the records are to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetAllReviewsPaging(int max, int offset, IApp42Callback* callBack);

    /**
    * Fetches All Reviews based on the itemId.
    *
    * @param itemId - The item id for which reviews have to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetReviewsByItem(const std::string& itemID, IApp42Callback* callBack);

    /**
    * Fetches count of all reviews in the App.
    *
    * @return app42Result - The result of the request.
    */
    void GetReviewsByItemCount(const std::string& itemID, IApp42Callback* callBack);

    /**
    * Fetches all reviews in the App by Paging.
    *
    * @param max - Maximum number of records to be fetched.
    * @param offset - From where the records are to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetReviewsByItemPaging(const std::string& itemID, int max, int offset, IApp42Callback* callBack);

    /**
    * Fetch the highest review for the specified itemId.
    *
    * @param itemId - The item id for which the highest review has to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetHighestReviewByItem(const std::string& itemID, IApp42Callback* callBack);

    /**
    * Fetch the lowest review for the specified itemId.
    *
    * @param itemId - The item id for which the lowest review has to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetLowestReviewByItem(const std::string& itemID, IApp42Callback* callBack);

    /**
    * Fetch the average review for the specified itemId.
    *
    * @param itemId - The item for which the average review has to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetAverageReviewByItem(const std::string& itemID, IApp42Callback* callBack);

    /**
    * Fetches count of All Reviews based on the itemId and rating.
    *
    * @param itemId - The item id for which count of reviews has to be fetched.
    * @param rating - Rating for which count of reviews has to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetReviewsCountByItemAndRating(const std::string& itemID, double rating, IApp42Callback* callBack);

    /**
    * Add a review comment for the existing itemId of the user.
    *
    * @param userId - User who want to add the comment.
    * @param itemId - Item for which the comment has to be added.
    * @param comment - Comment for the review.
    *
    * @return app42Result - The result of the request.
    */
    void AddComment(const std::string& userID, const std::string& itemID, const std::string& comment, IApp42Callback* callBack);

    /**
    * Fetch the review comment for the item.
    *
    * @param itemId - The item for which the comment has to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetCommentsByItem(const std::string& itemID, IApp42Callback* callBack);

    /**
    * Mute the specified review.
    *
    * @param reviewId - The Id of the review which has to be muted.
    *
    * @return app42Result - The result of the request.
    */
    void Mute(const std::string& reviewID, IApp42Callback* callBack);

    /**
    * Unmute the specified review.
    *
    * @param reviewId - The Id of the review which has to be unmuted.
    *
    * @return app42Result - The result of the request.
    */
    void Unmute(const std::string& reviewID, IApp42Callback* callBack);

    /**
    * Delete the specific review based on review id.
    *
    * @param reviewId - The Id of the review which has to be deleted.
    *
    * @return app42Result - The result of the request.
    */
    void DeleteReviewByReviewId(const std::string& reviewID, IApp42Callback* callBack);

    /**
    * Delete the specific comment by comment id.
    *
    * @param commentId - The Id of the comment which has to be deleted.
    *
    * @return app42Result - The result of the request.
    */
    void DeleteCommentByCommentId(const std::string& commentID, IApp42Callback* callBack);

    /**
    * Fetch all the reviews for the specified user.
    *
    * @param iuserId - The user id for which the reviews have to be fetched.
    *
    * @return app42Result - The result of the request.
    */
    void GetAllReviewsByUser(const std::string& userID, IApp42Callback* callBack);
};

#endif /* defined(__App42__ReviewService__) */
