#pragma once
#include<vector>
#include<cstring>
#include<iostream>
#include"csv_file.h"
#include<map>

const int MAX_TALENT_REPLACE_NUM = 20;	//最大的替换天赋数量
const int MAX_TALENT_EXCLUDE_NUM = 20;	//最大的互斥天赋数量
const int MAX_EVENT_BRANCH_NUM = 5;    //最大的事件分支数量
const int MAX_ASSIGNABLE_PROPERTIES = 20;   //当前可分配最大的属性值

extern map<int, int>AEVT;  //历史发生事件
extern int TMS;		//游玩次数
extern map<int, int>TLT;	//天赋
extern map<int, int>EVT;	//已发生事件



struct AgeEvent {
	int age;
	vector<int>event;
	vector<double>probability;  //概率
	int event_idx;
};

struct Talents {
	int id;
	string name;
	string description;
	string condition;
	int grade;
	int exclusive;
	int status;
	int SPR;       //快乐
	int MNY;	   //家境
	int CHR;        //颜值
	int STR;		//体质
	int INT;		//智力
	int RDM;		//随机属性
	int replacement_grade;  //随机同等级天赋
	string replacement[MAX_TALENT_REPLACE_NUM];  //替换天赋
	int exclude[MAX_TALENT_EXCLUDE_NUM];	//互斥天赋
	int replacement_idx;
	int exclude_idx;
};

struct Events {
	int id;
	string event;
	int grade;
	string post_event;
	int CHR;    //颜值
	int INT;	//智力
	int STR;	//体质
	int MNY;	//家境
	int SPR;	//快乐
	int LIF;	//生命
	int AGE;    //年龄
	int no_random;
	string include;
	string exclude;
	string branch[MAX_EVENT_BRANCH_NUM];
};

struct InitAttribute {
	int CHR = 0;		//颜值
	int INT = 0;		//智力
	int STR = 0;		//体质
	int MNY = 0;		//家境
	int SPR = 5;	   //快乐
	int AGE = 0;		//年龄
	int LIF = 1;	    //生命
};


class  AgeEventAssign {
public:
	AgeEventAssign();
	~AgeEventAssign();
	void AgeEventAssignData();

public:
	vector<vector<string>>str_array_;
	vector<AgeEvent>age_events_array_;
};


class  TalentsAssign {
public:
	TalentsAssign();
	~TalentsAssign();
	void TalentsAssignData();

public:
	vector<vector<string>>str_array_;
	vector<Talents>talents_array_;
	map<int, int>talents_array_id_to_idx_;
};


class  EventsAssign {
public:
	EventsAssign();
	~EventsAssign();
	void  EventsAssignData();

public:
	vector<vector<string>>str_array_;
	vector<Events>events_array_;
	map<int, int>events_array_id_to_idx_;
};


class InitAttributeAssign {
public:
	InitAttributeAssign();
	~InitAttributeAssign();
	static void UpdateInitArrayByEvent(InitAttribute& init_array, vector<Events>& events_array, int cur_event_id);
	void UpdateInitArrayByTalent(vector<Talents>& talents_array, int three_talents[]);
	void Print();
	void UpdateInitArrayByInput();

public:
	InitAttribute init_array_;		 //初始数组
	int cur_status_attributes = MAX_ASSIGNABLE_PROPERTIES;   //当前可分配的属性大小
};