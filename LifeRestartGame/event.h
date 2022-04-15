#pragma once
#include"condition.h"
#include<windows.h>


class Event {
public:
	void RandEvent(vector<AgeEvent>& age_events_array, map<int, int>& events_array_id_to_idx, InitAttribute& init_array, vector<Events>& events_array);
	void TriggerTalentCondition(vector<Talents>& talents_array, int three_talents[], InitAttribute& init_array);
	void Init();
public:
	int cur_age = 0;				//当前的年龄	
	int aleady_happen[3] = { 0 };   //判断天赋条件是否已经发生
	int aleady_reborn[3] = { 0 };   //判断复活天赋是否已经使用
};