#ifndef __App42__StorageService__
#define __App42__StorageService__

#include <iostream>
#include "App42Result.h"

using namespace std;

class StorageService{

private:
	string SERVER_ADDRESS;
	string API_KEY;
	string SECRET_KEY;
	string GetBaseUrl(string resource);
	static StorageService* _instance;
	StorageService();
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
	* Builds the instance of StorageService.
	*
	* @return storageService - StorageService Object
	*/
	static StorageService* GetInstance();

	
	void InsertJsonDocument(string dbName, string collectionName, string json, IApp42Callback* callBack);
	void FindAllCollections(string dbName, IApp42Callback* callBack);
	void FindAllDocuments(string dbName, string collectionName, IApp42Callback* callBack);
	void FindDocumentById(string dbName, string collectionName, string docId, IApp42Callback* callBack);
	void FindDocumentByKeyValue(string dbName, string collectionName, string key,string value, IApp42Callback* callBack);
};

#endif /* defined(__App42__StorageService__) */
