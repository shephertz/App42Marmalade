#ifndef __app42__App42StorageResult__
#define __app42__App42StorageResult__

#include <iostream>
#include "App42Result.h"
#include <vector>

using namespace std;

struct App42Storage;
struct JSONDocument;

class App42StorageResult : public App42Result
{
public:
    App42StorageResult(int code, string body, HttpRequest* request);
    vector<App42Storage> storages;
    vector<JSONDocument> documents;
	~App42StorageResult();
private:
    void init();
};

typedef struct JSONDocument
{
	string docId;
	string jsonDoc;
}JSONDocument;

typedef struct App42Storage
{
    string dbName;
    string collectionName;
}App42Storage;

#endif /* defined(__app42__App42StorageResult__) */
