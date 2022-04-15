#pragma once
#include<vector>
#include<cstring>
#include<iostream>
#include"csv_file.h"
#include<map>

const int MAX_TALENT_REPLACE_NUM = 20;	//�����滻�츳����
const int MAX_TALENT_EXCLUDE_NUM = 20;	//���Ļ����츳����
const int MAX_EVENT_BRANCH_NUM = 5;    //�����¼���֧����
const int MAX_ASSIGNABLE_PROPERTIES = 20;   //��ǰ�ɷ�����������ֵ

extern map<int, int>AEVT;  //��ʷ�����¼�
extern int TMS;		//�������
extern map<int, int>TLT;	//�츳
extern map<int, int>EVT;	//�ѷ����¼�



struct AgeEvent {
	int age;
	vector<int>event;
	vector<double>probability;  //����
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
	int SPR;       //����
	int MNY;	   //�Ҿ�
	int CHR;        //��ֵ
	int STR;		//����
	int INT;		//����
	int RDM;		//�������
	int replacement_grade;  //���ͬ�ȼ��츳
	string replacement[MAX_TALENT_REPLACE_NUM];  //�滻�츳
	int exclude[MAX_TALENT_EXCLUDE_NUM];	//�����츳
	int replacement_idx;
	int exclude_idx;
};

struct Events {
	int id;
	string event;
	int grade;
	string post_event;
	int CHR;    //��ֵ
	int INT;	//����
	int STR;	//����
	int MNY;	//�Ҿ�
	int SPR;	//����
	int LIF;	//����
	int AGE;    //����
	int no_random;
	string include;
	string exclude;
	string branch[MAX_EVENT_BRANCH_NUM];
};

struct InitAttribute {
	int CHR = 0;		//��ֵ
	int INT = 0;		//����
	int STR = 0;		//����
	int MNY = 0;		//�Ҿ�
	int SPR = 5;	   //����
	int AGE = 0;		//����
	int LIF = 1;	    //����
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
	InitAttribute init_array_;		 //��ʼ����
	int cur_status_attributes = MAX_ASSIGNABLE_PROPERTIES;   //��ǰ�ɷ�������Դ�С
};