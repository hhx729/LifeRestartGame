#include"config.h"
#include "csv_file.h"
#include "talent.h"
#include "condition.h"
using namespace std;

map<int, int>AEVT;  //历史发生事件
int TMS = 0;		//游玩次数
 map<int, int>TLT;	//天赋
map<int, int>EVT;	//已发生事件


AgeEventAssign::AgeEventAssign(){}
AgeEventAssign::~AgeEventAssign(){
	str_array_.clear();
	age_events_array_.clear();
}

void AgeEventAssign::AgeEventAssignData() {
	CsvFile a;
	a.ReadCsv("./age.csv", str_array_);
	for (int i = 2; i < str_array_.size(); i++) {
		AgeEvent cur_age_event;
		int idx = 0;
		for (int j = 0; j < str_array_[i].size(); j++) {
			bool flag = 1;
			int cur_event = 0;
			string cur_probability = "";
			double probability = 0.0;
			for (int k = 0; k < str_array_[i][j].size(); k++) {
				if (j == 0) {
					cur_age_event.age = str_array_[i][j][k] - '0';
					break;
				}
				if (str_array_[i][j][k] == '*') {
					flag = 0;
					continue;
				}
				if (flag == 1) {
					cur_event = cur_event * 10 + (str_array_[i][j][k] - '0');
				}
				if (flag == 0) {
					cur_probability += str_array_[i][j][k];
				}
			}

			if (j != 0) {
				probability = atof(cur_probability.c_str());
				cur_age_event.event.push_back(cur_event);
				if (flag == 0)
					cur_age_event.probability.push_back(probability);
				else
					cur_age_event.probability.push_back(1.0);
				idx++;
			}
		}
		cur_age_event.event_idx = idx;
		age_events_array_.push_back(cur_age_event);
		cur_age_event.event.clear();
		cur_age_event.probability.clear();
	}
}

TalentsAssign::TalentsAssign(){}
TalentsAssign::~TalentsAssign(){
	str_array_.clear();
	talents_array_.clear();
	talents_array_id_to_idx_.clear();
}

void TalentsAssign::TalentsAssignData() {
	CsvFile a;
	a.ReadCsv("./talents.csv", str_array_);
	int cur_idx = 0;
	for (int i = 2; i < str_array_.size(); i++) {
		Talents cur;
		cur.id = atoi(str_array_[i][0].c_str());
		talents_array_id_to_idx_[cur.id] = cur_idx++;
		cur.name = str_array_[i][1];
		cur.description = str_array_[i][2];
		cur.condition = str_array_[i][3];
		cur.grade = atoi(str_array_[i][4].c_str());
		cur.exclusive = atoi(str_array_[i][5].c_str());
		cur.status = atoi(str_array_[i][6].c_str());
		cur.SPR = atoi(str_array_[i][7].c_str());
		cur.MNY = atoi(str_array_[i][8].c_str());
		cur.CHR = atoi(str_array_[i][9].c_str());
		cur.STR = atoi(str_array_[i][10].c_str());
		cur.INT = atoi(str_array_[i][11].c_str());
		cur.RDM = atoi(str_array_[i][12].c_str());
		if (str_array_[i][13] == "") {
			cur.replacement_grade = -1;
		}
		else  cur.replacement_grade = atoi(str_array_[i][13].c_str());
		int idx = 0;
		for (int j = 14; j <= 29; j++) {
			cur.replacement[idx++] = str_array_[i][j].c_str();
		}
		cur.replacement_idx = idx;
		idx = 0;
		for (int j = 30; j < str_array_[i].size(); j++) {
			cur.exclude[idx++] = atoi(str_array_[i][j].c_str());
		}
		cur.exclude_idx = idx;
		talents_array_.push_back(cur);
	}
	
}

EventsAssign::EventsAssign(){}
EventsAssign::~EventsAssign(){
	str_array_.clear();
	events_array_.clear();
	events_array_id_to_idx_.clear();
}

void EventsAssign::EventsAssignData() {
	CsvFile a;
	a.ReadCsv("./events.csv", str_array_);
	//cout << str_array_.size() << endl;
	vector<string>cur_str;
	string temp = "";
	int start = 0;
	str_array_[str_array_.size() - 1].push_back("123321");
	int cur_idx = 0;
	for (int i = 10, flag = 0, flag2 = 0, flag3 = 0; i < str_array_.size(); i++) {
		for (int j = 0; j < str_array_[i].size(); j++) {
			if (str_array_[i][j] == "") {
				cur_str.push_back("0");
				continue;
			}
			for (int k = 0; k < str_array_[i][j].size(); k++) {
				if (str_array_[i][j][k] != '\"' && flag == 0) {
					if (atoi(str_array_[i][j].c_str()) >= 10000) {
						if (start == 1) {
							while (cur_str.size() < 17) {
								cur_str.push_back("0");
							}
							Events cur;
							cur.id = atoi(cur_str[0].c_str());
							events_array_id_to_idx_[cur.id] = cur_idx++;
							cur.event = cur_str[1];
							cur.grade = atoi(cur_str[2].c_str());
							cur.post_event = cur_str[3];
							cur.CHR = atoi(cur_str[4].c_str());
							cur.INT = atoi(cur_str[5].c_str());
							cur.STR = atoi(cur_str[6].c_str());
							cur.MNY = atoi(cur_str[7].c_str());
							cur.SPR = atoi(cur_str[8].c_str());
							cur.LIF = atoi(cur_str[9].c_str());
							cur.AGE = atoi(cur_str[10].c_str());
							cur.no_random = atoi(cur_str[11].c_str());
							cur.include = cur_str[12];
							cur.exclude = cur_str[13];
							cur.branch[0] = cur_str[14];
							cur.branch[1] = cur_str[15];
							cur.branch[2] = cur_str[16];
							events_array_.push_back(cur);
						}
						else start = 1;
						cur_str.resize(0);
					}
					cur_str.push_back(str_array_[i][j]);
					break;
				}
				else if (str_array_[i][j][k] == '\"' && flag == 0) {
					temp = str_array_[i][j];
					flag = 1;
					flag2 = 0;
					flag3 = 1;
					break;
				}
				else if (str_array_[i][j][k] == '\"' && flag == 1) {
					flag2 = 1;
					temp = temp + " " + str_array_[i][j];
					cur_str.push_back(temp);
					temp = "";
					flag = 0;
					break;
				}
				flag3 = 0;
			}
			if (flag == 1 && flag3 == 0) {
				if (flag2 == 0) temp = temp + " " + str_array_[i][j];
			}
		}
	}
}


InitAttributeAssign::InitAttributeAssign() {}
InitAttributeAssign::~InitAttributeAssign() {}

void InitAttributeAssign::UpdateInitArrayByEvent(InitAttribute& init_array, vector<Events>& events_array, int cur_event_id) {
	init_array.CHR += events_array[cur_event_id].CHR;
	init_array.INT += events_array[cur_event_id].INT;
	init_array.STR += events_array[cur_event_id].STR;
	init_array.MNY += events_array[cur_event_id].MNY;
	init_array.SPR += events_array[cur_event_id].SPR;
	init_array.AGE += events_array[cur_event_id].AGE;
	init_array.LIF += events_array[cur_event_id].LIF;
}

void InitAttributeAssign::UpdateInitArrayByTalent(vector<Talents>& talents_array, int three_talents[]) {
	for (int i = 0; i < 3; i++) {
		TLT[talents_array[three_talents[i]].id]++;
		if (talents_array[three_talents[i]].condition != "") {
			continue;
		}
		cur_status_attributes += talents_array[three_talents[i]].status;
		init_array_.CHR += talents_array[three_talents[i]].CHR;
		init_array_.SPR += talents_array[three_talents[i]].SPR;
		init_array_.MNY += talents_array[three_talents[i]].MNY;
		init_array_.STR += talents_array[three_talents[i]].STR;
		init_array_.INT += talents_array[three_talents[i]].INT;
		if (talents_array[three_talents[i]].RDM > 0) {
			int tmp_rand = rand() % 4;
			if (tmp_rand == 0) {
				init_array_.CHR += talents_array[three_talents[i]].RDM;
			}
			else if (tmp_rand == 1) {
				init_array_.INT += talents_array[three_talents[i]].RDM;
			}
			else if (tmp_rand == 2) {
				init_array_.STR += talents_array[three_talents[i]].RDM;
			}
			else if (tmp_rand == 3) {
				init_array_.MNY += talents_array[three_talents[i]].RDM;
			}
		}
	}

}

void InitAttributeAssign::Print()
{
	cout << "颜值 :" << init_array_.CHR << " " << "智力: " << init_array_.INT << " " << "体质: " << init_array_.STR << " " << "家境: " << init_array_.MNY << " " << "快乐: " << init_array_.SPR << endl;
}

void InitAttributeAssign::UpdateInitArrayByInput()
{
	while (1) {
		int flag = 0;
		int cur_CHR = 0;
		int cur_INT = 0;
		int cur_STR = 0;
		int cur_MNY = 0;
		cin >> cur_CHR;
		cin >> cur_INT;
		cin >> cur_STR;
		cin >> cur_MNY;
		if (cur_CHR < 0 || cur_CHR>10 || cur_INT < 0 || cur_INT > 10 || cur_STR < 0 || cur_STR>10
			|| cur_MNY < 0 || cur_MNY > 10 || cur_CHR + cur_INT + cur_STR + cur_MNY > cur_status_attributes) {
			flag = 1;
		}
		if (flag == 1) {
			cout << "属性值输入不合法，请重新输入:" << endl;
			continue;
		}
		init_array_.CHR += cur_CHR;
		init_array_.INT += cur_INT;
		init_array_.STR += cur_STR;
		init_array_.MNY += cur_MNY;
		break;
	}

}






