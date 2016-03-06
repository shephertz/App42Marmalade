//
//  PushService.h
//  App42
//
//  Created by damucz on 6/8/14.
//

#ifndef __App42__PushService__
#define __App42__PushService__

#include "App42Result.h"
#include <map>
#include <vector>
#include <string>

class PushService{
private:
	std::string SERVER_ADDRESS;
	std::string API_KEY;
	std::string SECRET_KEY;
	std::string GetBaseUrl(const std::string& resource);
    std::string BuildCompletePostUrl(const std::string& resource, const std::string& body);
    std::string BuildCompleteGetUrl(const std::string& resource, const std::map<std::string, std::string>& params, bool exposeParams = false);
    std::string BuildCompleteGetUrl(const std::string& resource);

	static PushService* _instance;
	PushService();
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
	* Builds the instance of PushService.
	*
	* @return PushService - PushService Object
	*/
	static PushService* GetInstance();

    /**
    * Upload apiKey/certificate to server that will be used while sending notifications to the devices.
    *
    * @param apiKey - the apiKey which you have received while registering for GCM.
    * @param password - Password which has been given while export .p12 file.
    * @param filePath - Path of certificates.p12 file.
    * @param environment - It can be development or production.
    * @return app42Result - The result of the request
    *
    */
    //void UploadP12FileForiOS(const std::string& apiKey, const std::string& password, const std::string& filePath, const std::string& environment, IApp42Callback* callBack);

    /**
    * Stores your device token on server with particular username.
    *
    * @param userName - username with which you want your device to be registered.
    * @param deviceToken - Device Token that has to be registered.
    * @param deviceType - Type of the device like Android, iOS , WP7.
    * @return app42Result - The result of the request
    *
    */
    void StoreDeviceToken(const std::string& userName, const std::string& deviceToken, const std::string& type, IApp42Callback* callBack);

    /**
    * Create Channel for app on which user can subscribe and get the notification for that channel.
    * 
    * @param channel - Channel name which you want to create.
    * @param description - Description for that channel.
    * @return app42Result - The result of the request
    *
    */
    void CreateChannelForApp(const std::string& channel, const std::string& description, IApp42Callback* callBack);

    /**
    * User will be subscribed to the selected existing Channel.
    *
    * @param channel - Name of the channel which you want to subscribe.
    * @param userName - Name of the user which you want to subscribe for the channel.
    * @return app42Result - The result of the request
    *
    */
    void SubscribeToChannel(const std::string& channel, const std::string& userName, IApp42Callback* callBack);

    /**
    * Unsubscribe from particular channel.
    *
    * @param channel - Name of the channel which you want to unsubscribe.
    * @param userName - Name of the user which you want to unsubscribe from the channel.
    * @return app42Result - The result of the request
    *
    */
    void UnsubscribeToChannel(const std::string& channel, const std::string& userName, IApp42Callback* callBack);

    /**
    * Send push message to a particular channel.
    * 
    * @param channel - Name of the channel for which you want to send message.
    * @param message - Message which you want to send.
    * @return app42Result - The result of the request
    *
    */
    void SendPushMessageToChannel(const std::string& channel, const std::string& message, IApp42Callback* callBack);

    /**
    * Send push message to all your users.
    *
    * @param message - Message which you want to send.
    * @return app42Result - The result of the request
    *
    */
    void SendPushMessageToAll(const std::string& message, IApp42Callback* callBack);

    /**
    * Send push message to all by device type which is subscribed e.g :- WP7/Android/iOS
    *
    * @param message - Message which you want to send.
    * @param deviceType - Type of device for which you want to send a message.
    * @return app42Result - The result of the request
    *
    */
    void SendPushMessageToAllByType(const std::string& message, const std::string& deviceType, IApp42Callback* callBack);

    /**
    * Send push message to channel containing JSON. On receive of this message on device, it has to be parsed and accessed accordingly.
    *
    * @param channel - Name of the channel for which you want to send message.
    * @param message - Message which you want to send. (keys: alert, badge[iOS], sound[iOS], sendingFrom[custom])
    * @return app42Result - The result of the request
    *
    */
    //void SendCustomPushMessageToChannel(const std::string& channel, const std::map<std::string, std::string>& message, IApp42Callback* callBack);

    /**
    * Send push message to a particular user.
    *
    * @param userName - Name of the user which you want to send the message.
    * @param message - Message which you want to send.
    * @return app42Result - The result of the request
    *
    */
    void SendPushMessageToUser(const std::string& userName, const std::string& message, IApp42Callback* callBack);

    /**
    * Subscribe your device to a particular channel with device token and type.
    *
    * @param userName - Username which want to subscribe.
    * @param channelName - Name of channel for which user want to subscribe.
    * @param deviceToken - Device token which you want to subscribe.
    * @param deviceType - Device Type which you want to subscribe.
    * @return app42Result - The result of the request
    *
    */
    void SubscribeToChannelWithDeviceToken(const std::string& userName, const std::string& channel, const std::string& deviceToken, const std::string& type, IApp42Callback* callBack);

    /**
    * Unsubscribe your device to a particular channel with device token.
    *
    * @param userName - Name of user who want to unsubscribe to channel.
    * @param channelName - Name of channel for which user want to unsubscribe.
    * @param deviceToken - Device token which you want to unsubscribe.
    * @return app42Result - The result of the request
    *
    */
    void UnsubscribeDeviceToChannel(const std::string& userName, const std::string& channel, const std::string& deviceToken, IApp42Callback* callBack);

    /**
    * Unsubscribe your device form push-notification service.
    *
    * @param userName - Name of user whose device token has to delete.
    * @param deviceToken - Device token which has to be deleted.
    * @return app42Result - The result of the request
    *
    */
    void DeleteDeviceToken(const std::string& userName, const std::string& deviceToken, IApp42Callback* callBack);

    /**
    * Send push message to list of specific users.
    *
    * @param message - Message which you have to send.
    * @param userList - List of the users for which message has to be send.
    * @return app42Result - The result of the request
    *
    */
    void SendPushMessageToGroup(const std::string& message, const std::vector<std::string>& userList, IApp42Callback* callBack);

    /**
    * !!!!!!!! This method is removed from API , use appHQ to send push to inactive users
    * Send message to the users inactive between start and end timestamp.
    *
    * @param startDate - Start of the interval. 'yyyy-mm-ddThh:mm:ss.miliZ'
    * @param endDate - Start of the interval. 'yyyy-mm-ddThh:mm:ss.miliZ'
    * @return app42Result - The result of the request
    *
    */
    //void SendMessageToInactiveUsers(const std::string& startDate, const std::string& endDate, const std::string& message, IApp42Callback* callBack);

    /**
    * Send message to a particular user with schedule time.
    * @param userName - Name of the user which you want to send the message.
    * @param message - Message which you have to send.
    * @param scheduleDate - Time on which send message to user. 'yyyy-mm-ddThh:mm:ss.miliZ'
    * @return app42Result - The result of the request
    *
    */
    void ScheduleMessageToUser(const std::string& userName, const std::string& message, const std::string& scheduleDate, IApp42Callback* callBack);
};

#endif /* defined(__App42__PushService__) */
