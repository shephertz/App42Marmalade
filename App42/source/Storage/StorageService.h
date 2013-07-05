#ifndef __App42__StorageService__
#define __App42__StorageService__

#include <iostream>
#include "App42Result.h"

using namespace std;

/**
 * Storage service on cloud provides the way to store the JSON document in NoSQL
 * database running on cloud. One can store the JSON document, update it ,
 * search it and can apply the map-reduce search on stored documents. Example :
 * If one will store JSON doc {"Company":"Shephertz"} it will be stored with unique
 * Object Id and stored JSON object will look like { "Company" : "Shephertz" , "_id" : {
 * "$oid" : "4f423dcce1603b3f0bd560cf"}}. This oid can further be used to
 * access/search the document.
 * @see Storage
 * 
 */
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
	/**
	* Save the JSON document in given database name and collection name.
	* 
	* @param dbName - Unique handler for storage name.
	* @param collectionName - Name of collection under which JSON doc has to be saved.
	* @param json - Target JSON document to be saved. 
	* @return app42Result - The result of the request
	* 
	*/
	void InsertJsonDocument(string dbName, string collectionName, string json, IApp42Callback* callBack);
	/**
	* Find all collections stored in given database.
	* 
	* @param dbName - Unique handler for storage name 
	* @return app42Result - The result of the request
	*
	*/
	void FindAllCollections(string dbName, IApp42Callback* callBack);
	/**
	* Find all documents stored in given database and collection.
	* 
	* @param dbName - Unique handler for storage name
	* @param collectionName - Name of collection under which JSON doc needs to be searched
	* 
	* @return app42Result - The result of the request
	*
	*/
	void FindAllDocuments(string dbName, string collectionName, IApp42Callback* callBack);
	/**
	* Find target document by given unique object id.
	* 
	* @param dbName - Unique handler for storage name.
	* @param collectionName - Name of collection under which JSON doc needs to be searched.
	* @param docId - Unique Object Id handler.
	* @return app42Result - The result of the request
	*
	*/
	void FindDocumentById(string dbName, string collectionName, string docId, IApp42Callback* callBack);
	/**
	* Find target document using key value search parameter. This key value
	* pair will be searched in the JSON doc stored on the cloud and matching
	* Doc will be returned as a result of this method.
	* 
	* @param dbName - Unique handler for storage name
	* @param collectionName - Name of collection under which JSON doc needs to be searched
	* @param key - Key to be searched for target JSON doc
	* @param value - Value to be searched for target JSON doc
	* @return app42Result - The result of the request
	*
	*/
	void FindDocumentByKeyValue(string dbName, string collectionName, string key,string value, IApp42Callback* callBack);
};

#endif /* defined(__App42__StorageService__) */
