#include "s3e.h"
#include "IwNUI.h"
#include <IwPropertyString.h> 
#include "Storage/StorageService.h"
#include "Storage/App42StorageResult.h"

#include <sstream>
#include <stdlib.h>

class App
{
	StorageService *storageService;
	IApp42Callback *callback;
	IwNUI::CString dbName;
	IwNUI::CString collectionName;
		
	bool m_btn_Click(IwNUI::CButton* button)
	{
		m_text->GetAttribute("text",dbName);
		if(strcmp(dbName.Get(), "") != 0)
		{
			m_text2->GetAttribute("text",collectionName);
			if(strcmp(collectionName.Get(), "") != 0)
			{
				storageService->InsertJsonDocument(dbName.Get(),collectionName.Get(),"{\"employeeName\":\"Nick\"}",callback);
			}
			else
			{
				m_text2->SetAttribute("text","Enter a collectionName");
			}
		}
		else
		{
			m_text->SetAttribute("text", "Enter a DBName");
		}
		return true;
	}

	bool m_btn2_Click(IwNUI::CButton* button)
	{
		msg_log = "";
		m_text->GetAttribute("text",dbName);
		if(strcmp(dbName.Get(), "") != 0)
		{
			m_text2->GetAttribute("text",collectionName);
			if(strcmp(collectionName.Get(), "") != 0)
			{
				storageService->FindAllDocuments(dbName.Get(),collectionName.Get(),callback);
			}
			else
			{
				m_text2->SetAttribute("text","Enter a collectionName");
			}
		}
		else
		{
			m_text->SetAttribute("text", "Enter a DBName");
		}
		return true;
	}
	
public:
	std::string msg_log;

	IwNUI::CAppPtr m_app;
	IwNUI::CWindowPtr m_window;
	IwNUI::CViewPtr m_view;

	IwNUI::CButtonPtr m_btn;
	IwNUI::CButtonPtr m_btn2;
	IwNUI::CTextFieldPtr m_text;
	IwNUI::CTextFieldPtr m_text2;

	IwNUI::CLabelPtr m_label;

	App(IwNUI::CAppPtr app)
	{
		m_app = app;
	}

	void Init(StorageService *service, IApp42Callback *cb)
	{
		
		storageService = service;
		callback = cb;

		m_window = IwNUI::CreateWindow();
		m_view = IwNUI::CreateView();
		
		m_text = IwNUI::CreateTextField(IwNUI::CAttributes()
			.Set("name", "text")
			.Set("x1","5%")
			.Set("y1","10")
			.Set("fontSize", IwNUI::CFontSize(6))
			.Set("width","90%")
			.Set("height","28"));
		m_text2 = IwNUI::CreateTextField(IwNUI::CAttributes()
			.Set("name", "text2")
			.Set("x1","5%")
			.Set("y1","48")
			.Set("fontSize", IwNUI::CFontSize(6))
			.Set("width","90%")
			.Set("height","28"));
		m_btn = IwNUI::CreateButton(IwNUI::CAttributes()
			.Set("name", "button")
			.Set("caption", "Insert Doc")
    		.Set("x1",      "5%")
    		.Set("y1",      "86")
			.Set("fontSize", IwNUI::CFontSize(6))
			.Set("width","40%")
			.Set("height","28"));
		m_btn2 = IwNUI::CreateButton(IwNUI::CAttributes()
			.Set("name", "button2")
			.Set("caption", "Find All Docs")
    		.Set("x1",      "55%")
    		.Set("y1",      "86")
			.Set("fontSize", IwNUI::CFontSize(6))
			.Set("width","40%")
			.Set("height","28"));

		m_label = IwNUI::CreateLabel(IwNUI::CAttributes()
			.Set("name", "listbox")
			.Set("x1","5%")
			.Set("y1","124")
			.Set("width","90%")
			.Set("height","200")
			.Set("fontSize", IwNUI::CFontSize(6))
			.Set("fontAlignH", "left")
    		.Set("fontAlignV", "top"));

		m_btn->SetEventHandler("click", this, &App::m_btn_Click);
		m_btn2->SetEventHandler("click", this, &App::m_btn2_Click);

		m_app->AddWindow(m_window);
		m_window->SetChild(m_view);

		m_view->AddChild(m_btn);
		m_view->AddChild(m_btn2);
		m_view->AddChild(m_text);
		m_view->AddChild(m_text2);
		m_view->AddChild(m_label);

		m_app->ShowWindow(m_window);	

	}

	void SetText(std::string msg)
	{
		msg_log = msg_log + "\n" + msg;
		IwNUI::CString cstr;
		cstr.Set(msg_log.c_str());
		m_label->SetAttribute("caption", cstr);
	}

	void Run()
	{
		m_app->Run();
	}

	
};

class CApp42StorageCallback : public IApp42Callback
{
	App *m_app;
	StorageService *storageService;
public:

	CApp42StorageCallback(App *app,StorageService *service){
		m_app = app;
		storageService= service;
	}

	void onResult(App42Result* result){
		
		App42StorageResult* storageResult = static_cast<App42StorageResult*>(result);
		vector<JSONDocument> documents = storageResult->documents;
		
		std::stringstream str;
		for(vector<JSONDocument>::iterator it2=documents.begin(); it2<documents.end(); ++it2)
			str << it2->jsonDoc << " document in the storage with doc id :- " << it2->docId << "\n";

		m_app->SetText(str.str());

		delete storageResult;
	}
}; 

int main()
{	
	std::string api_key = "30de7e0dcf044cb4c5b46b606868a619a7057e727312392a0f346aafb3036e0f";
    std::string secret_key = "80375913972b990a07495686c40ebe012672aa9821d1999e19b9459a3f133191";

	IwNUI::CAppPtr app = IwNUI::CreateApp();
	App *myapp = new App(app);
	StorageService::Initialize(api_key, secret_key);
	StorageService* storageService = StorageService::GetInstance();
	CApp42StorageCallback *storageCallback = new CApp42StorageCallback(myapp,storageService);

	myapp->Init(storageService,storageCallback);
	myapp->Run();

	StorageService::Terminate();
	delete storageCallback;
	delete myapp;

	return 0;
}