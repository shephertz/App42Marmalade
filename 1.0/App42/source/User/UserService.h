//
//  UserService.h
//  App42
//
//  Created by Dhruv Chopra on 3/30/13.
//  Copyright (c) 2013 Dhruv Chopra. All rights reserved.
//

#ifndef __App42__UserService__
#define __App42__UserService__

#include "App42Result.h"
#include <map>
#include <vector>
#include <string>

class UserService{
private:
	std::string SERVER_ADDRESS;
	std::string API_KEY;
	std::string SECRET_KEY;
	std::string GetBaseUrl(const std::string& resource);
    std::string BuildCompletePostUrl(const std::string& resource, const std::string& body);
    std::string BuildCompleteGetUrl(const std::string& resource, const std::map<std::string, std::string>& params);
    std::string BuildCompleteGetUrl(const std::string& resource);

	static UserService* _instance;
	UserService();
public:
    class Profile;

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
	* Builds the instance of UserService.
	*
	* @return UserService - UserService Object
	*/
	static UserService* GetInstance();

	/**
	* Create a User with userName, password & emailAddress
	*
	* @param userName - Name of the User
	* @param password - Password for the User
	* @param email - Email address of the user
	* @return app42Result - The result of the request
	* 
	*/
	void CreateUser(const std::string& userName, const std::string& password, const std::string& email, IApp42Callback* callBack);

    /**
    * This function enables you to create App users along with granting them specific roles.Required Parameters
    * @param userName - Name of the user for whom the user session is to be created.
    * @param pwd - Password for the user.
    * @param emailId - EmailId of the user.
    * @param roleList - List of roles to be assigned to user.
    * @return app42Result - The result of the request
    * 
    */
    void CreateUserWithRole(const std::string& username, const std::string& password, const std::string& email, const std::vector<std::string>& roleList, IApp42Callback* callBack);

    /**
	* Create user for the App
	*
    * @param userName - Name of the User.
    * //@param pwd - Password for the User.
    * //@param email - Email address of the user.
    * @param request - An object with success and error callbacks.
    * @return app42Result - The result of the request
    */
    //void CreateOrUpdateProfile(const std::string& username, const Profile& profile, IApp42Callback* callBack);
    //void CreateOrUpdateProfile(const std::string& username, const std::string& pwd, const Profile& profile, IApp42Callback* callBack);
    void CreateOrUpdateProfile(const std::string& username, /*const std::string& pwd, const std::string& email,*/ const Profile& profile, IApp42Callback* callBack);

	/**
	* Authenticate user based on userName and password
	* 
	* @param userName  - UserName which should be unique for the App
	* @param password - Password for the User
	* @return app42Result - The result of the request
    *
	*/
	void Authenticate(const std::string& userName, const std::string& password, IApp42Callback* callBack);

    /**
	* Change the password for user based on the userName. If the old password is valid.
	*
    * @param userName - UserName which should be unique for the App 
	* @param oldPwd - Old Password for the user for authentication 
	* @param newPwd - New Password for the user to change
    * @return app42Result - The result of the request
    *
	*/
    void ChangeUserPassword(const std::string& userName, const std::string& oldPwd, const std::string& newPwd, IApp42Callback* callBack);

    /**
    * Assign Roles to the existing user.
    * @param userName - Name of the user to whom the roles have to be assigned.
    * @param roleList - List of roles assigned to user.
    * @return app42Result - The result of the request
    *
    */
    void AssignRoles(const std::string& userName, const std::vector<std::string>& roleList, IApp42Callback* callBack);

	/**
	* Gets the User details based on userName
	* 
	* @param userName - Name of the User to retrieve.
	* @return app42Result - The result of the request.
	*/
	void GetUser(const std::string& userName, IApp42Callback* callBack);

    /**
    * Get the assigned roles to the specified User
    *
    * @param userName - Name of the User for whom roles have to be retrieved
    * @return app42Result - The result of the request
    *
    */
    void GetRolesByUser(const std::string& userName, IApp42Callback* callBack);

    /**
    * Get all the Users who have the specified role assigned
    *
    * @param role - Role for which Users needs to be retrieved
    * @return app42Result - The result of the request
    *
    */
    void GetUsersByRole(const std::string& role, IApp42Callback* callBack);

	/**
	* Gets the details of all users
	* 
	* @return app42Result - The result of the request.
	*/
	void GetAllUsers(IApp42Callback* callBack);

    /**
    * Gets the count of all the users
    * @return app42Result - The result of the request
    *
    */
    void GetAllUsersCount(IApp42Callback* callBack);

    /**
    * Gets all users by Paging
    *
    * @param max - Maximum number of records to be fetched
    * @param offset - From where the records are to be fetched
    * @return app42Result - The result of the request
    *
    */
    void GetAllUsersPaging(int max, int offset, IApp42Callback* callBack);

    /**
    * Gets user details based on emailId
    *
    * @param emailId - EmailId of the user to be retrieved
    * @return app42Result - The result of the request
    *
    */
    void GetUserByEmailId(const std::string& emailId, IApp42Callback* callBack);

    /**
    * Locks the user based on the userName. Apps can use these feature to lock
    * a user because of reasons specific to their usercase e.g. If payment not
    * received and the App wants the user to be inactive
    *
    * @param uName - UserName which should be unique for the App
    * @return app42Result - The result of the request
    *
    */
    void LockUser(const std::string& userName, IApp42Callback* callBack);

    /**
    * Unlocks the user based on the userName. App developers can use this
    * feature to unlock a user because of reasons specific to their usercase
    * e.g. When payment received, the App developer wants the user to be
    * active.
    *
    * @param uName - UserName which should be unique for the App
    * @return app42Result - The result of the request
    *
    */
    void UnlockUser(const std::string& userName, IApp42Callback* callBack);

    /**
    * Gets the details of all the locked users
    *
    * @return app42Result - The result of the request
    */
    void GetLockedUsers(IApp42Callback* callBack);

    /**
    * Gets the count of all the locked users
    * @return app42Result - The result of the request
    *
    */
    void GetLockedUsersCount(IApp42Callback* callBack);

    /**
    * Gets the details of all the locked users By paging.
    *
    * @param max - Maximum number of records to be fetched
    * @param offset - From where the records are to be fetched
    * @return app42Result - The result of the request
    *
    */
    void GetLockedUsersPaging(int max, int offset, IApp42Callback* callBack);

    /**
    * Gets the list of Users based on Profile Data
    *
    * @param profileData - Profile Data key/value for which Users need to be retrieved
    * @return app42Result - The result of the request
    *
    */
    void GetUsersByProfileData(const Profile& profile, IApp42Callback* callBack);

    /**
    * Updates the User password based on userName. Username cannot be updated.
    *
    * @param uName - UserName which should be unique for the App
    * @return app42Result - The result of the request
    *
    */
    void ResetUserPassword(const std::string& userName, IApp42Callback* callBack);

    /**
    * Revokes the specified role from the user.
    *
    * @param userName - UserName from whom the role has to be revoked
    * @param role - Role that has to be revoked
    * @return app42Result - The result of the request
    *
    */
    void RevokeRole(const std::string& userName, const std::string& role, IApp42Callback* callBack);

    /**
    * Revokes all the roles from the user.
    *
    * @param userName - Name of the User from whom Roles have to be revoked
    * @return app42Result - The result of the request
    *
    */
    void RevokeAllRoles(const std::string& userName, IApp42Callback* callBack);

    /**
    * Updates the User's Email Address based on userName. Note: Only email can
    * be updated. Username cannot be updated.
    *
    * @param uName - UserName which should be unique for the App
    * @param emailAddress - Email address of the user
    * @return app42Result - The result of the request
    *
    */
    void UpdateEmail(const std::string& userName, const std::string& emailAddress, IApp42Callback* callBack);

    /**
    * Deletes a particular user based on userName.
    *
    * @param userName - UserName which should be unique for the App
    * @return app42Result - The result of the request
    *
    */
    void DeleteUser(const std::string& userName, IApp42Callback* callBack, bool permanent = false);

    /**
    * Log out the session
    *
    * @param sessionId - session id to log out
    * @return app42Result - The result of the request
    *
    */
    void LogOut(const std::string&sessionId, IApp42Callback* callBack);

    /**
    * Permanently deletes a particular user based on userName.
    *
    * @param userName - UserName which should be unique for the App
    * @return app42Result - The result of the request
    *
    */
    void DeleteUserPermanent(const std::string& userName, IApp42Callback* callBack);

	/**
	* Authenticate user based on userName and password
	* 
	* @param userName  - UserName which should be unique for the App
	* @param password - Password for the User
	* @return app42Result - The result of the request
    *
	*/
	void AuthenticateWithEmail(const std::string& emailId, const std::string& password, IApp42Callback* callBack);

    class Profile
    {
    public:
        void SetDateOfBirth(const std::string& dateOfBirth);
        void SetLastName(const std::string& lastName);
        void SetSex(const std::string& sex);
        void SetOfficeLandLine(const std::string& officeLandLine);
        void SetHomeLandLine(const std::string& homeLandLine);
        void SetState(const std::string& state);
        void SetFirstName(const std::string& firstName);
        void SetCountry(const std::string& country);
        void SetCity(const std::string& city);
        void SetMobile(const std::string& mobile);
        void SetLine1(const std::string& line1);
        void SetLine2(const std::string& line2);
        void SetPinCode(const std::string& pincode);

        std::string GetDateOfBirth() const;
        std::string GetLastName() const;
        std::string GetSex() const;
        std::string GetOfficeLandLine() const;
        std::string GetHomeLandLine() const;
        std::string GetState() const;
        std::string GetFirstName() const;
        std::string GetCountry() const;
        std::string GetCity() const;
        std::string GetMobile() const;
        std::string GetLine1() const;
        std::string GetLine2() const;
        std::string GetPinCode() const;

        std::map<std::string, std::string> GetData() const;

    protected:
        std::map<std::string, std::string> profileData;

        void SetData(const std::string& key, const std::string& value);
        std::string GetData(const std::string& key) const;
    };
};

#endif /* defined(__App42__UserService__) */
