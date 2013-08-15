
#include "s3e.h"
#include "IwNUI.h"
#include <IwPropertyString.h> 

#include "User/UserService.h"
#include "Game/ScoreBoardService.h"
#include "Game/GameService.h"
#include "User/App42UserResult.h"
#include "Game/App42GameResult.h"

#include <sstream>
#include <stdlib.h>

class App
{
	ScoreBoardService *scoreboard;
	IApp42Callback *callback;

	bool m_btn_Click(IwNUI::CButton* button)
	{
		IwNUI::CString name;
		IwNUI::CString score;

		m_text->GetAttribute("text",name);

		if(strcmp(name.Get(), "") != 0)
		{
			m_text2->GetAttribute("text",score);

			if(strcmp(score.Get(), "") != 0)
			{
				std::string temp;
				temp.append(score.Get());
				//SetText(temp);
				scoreboard->SaveUserScore("Game Name",name.Get(),std::atof(temp.c_str()),callback);
			}
			else
			{
				m_text2->SetAttribute("text","Enter a score");
			}
		}
		else
		{
			m_text->SetAttribute("text", "Enter a name");
		}

		return true;
	}

	bool m_btn2_Click(IwNUI::CButton* button)
	{
		msg_log = "";
		m_label->SetAttribute("caption", "");
		scoreboard->GetTopRankings("Game Name",callback);
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

	void Init(ScoreBoardService *service, IApp42Callback *cb)
	{
		
		scoreboard = service;
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
			.Set("caption", "Save Score")
    		.Set("x1",      "5%")
    		.Set("y1",      "86")
			.Set("fontSize", IwNUI::CFontSize(6))
			.Set("width","40%")
			.Set("height","28"));
		m_btn2 = IwNUI::CreateButton(IwNUI::CAttributes()
			.Set("name", "button2")
			.Set("caption", "Get Top Score")
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

class CApp42ScoreBoardCallback : public IApp42Callback
{
	App *m_app;
	ScoreBoardService *scoreboard;
public:

	CApp42ScoreBoardCallback(App *app,ScoreBoardService *service){
		m_app = app;
		scoreboard = service;
	}

	void onResult(App42Result* result){
		App42GameResult* gameResult = static_cast<App42GameResult*>(result);
		vector<App42Score> scores = gameResult->scores;

		std::stringstream str;

		for(vector<App42Score>::iterator it2=scores.begin(); it2<scores.end(); ++it2)
			str << it2->userName << " -- " << it2->value << "\n";

		m_app->SetText(str.str());

		delete gameResult;
	}
};

int main()
{	
	std::string api_key = "YOUR_API_KEY";
    std::string secret_key = "YOUR_SECRET_KEY";

	IwNUI::CAppPtr app = IwNUI::CreateApp();
	App *myapp = new App(app);

	ScoreBoardService::Initialize(api_key, secret_key);
	ScoreBoardService* scoreBoardService = ScoreBoardService::GetInstance();
	CApp42ScoreBoardCallback *topRankingsCallback = new CApp42ScoreBoardCallback(myapp,scoreBoardService);

	
	myapp->Init(scoreBoardService,topRankingsCallback);

	
	scoreBoardService->GetTopRankings("Game Name",topRankingsCallback);

	myapp->Run();

	ScoreBoardService::Terminate();
	delete topRankingsCallback;
	delete myapp;

	return 0;
}