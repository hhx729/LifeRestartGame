#pragma once
#include"condition.h"
#include<windows.h>


class Event {
public:
	void RandEvent(vector<AgeEvent>& age_events_array, map<int, int>& events_array_id_to_idx, InitAttribute& init_array, vector<Events>& events_array);
	void TriggerTalentCondition(vector<Talents>& talents_array, int three_talents[], InitAttribute& init_array);
	void Init();
public:
	int cur_age = 0;				//��ǰ������	
	int aleady_happen[3] = { 0 };   //�ж��츳�����Ƿ��Ѿ�����
	int aleady_reborn[3] = { 0 };   //�жϸ����츳�Ƿ��Ѿ�ʹ��
};