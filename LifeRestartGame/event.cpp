#include "event.h"

void Event::RandEvent(vector<AgeEvent>& age_events_array, map<int, int>& events_array_id_to_idx, InitAttribute& init_array, vector<Events>& events_array)
{
	cur_age = init_array.AGE;
	cout << cur_age << "岁:" << endl;
	map<int, int>can_rand_event;
	can_rand_event.clear();
	vector<int>cur_rand_event;
	cur_rand_event.clear();
	for (int i = 0; i < age_events_array[cur_age].event.size(); i++) {
		int x = events_array_id_to_idx[age_events_array[cur_age].event[i]];
		if (events_array[x].no_random == 1) {
			can_rand_event[age_events_array[cur_age].event[i]]++;
			continue;
		}
		int gg = 0;
		int hh = 0;
		if (Condition::ConditionJudgment(events_array[x].include, init_array) > 0) {
			gg = 1;
		}
		if (Condition::ConditionJudgment(events_array[x].exclude, init_array) > 0) {
			hh = 1;
		}
		if (gg == 1 && hh == 0) {
			can_rand_event[age_events_array[cur_age].event[i]]++;
			continue;
		}
		else {
			continue;
		}

	}

	double max_probability = 0.0;
	int cur_event_id = 0;
	int low_probability = 0;
	for (int i = 0; i < age_events_array[cur_age].event.size(); i++) {
		if (can_rand_event[age_events_array[cur_age].event[i]] > 0) {
			if (age_events_array[cur_age].probability[i] < 1.0) {
				low_probability = 1;
			}
			if (age_events_array[cur_age].probability[i] > max_probability) {
				max_probability = age_events_array[cur_age].probability[i];
				cur_event_id = age_events_array[cur_age].event[i];
				cur_event_id = events_array_id_to_idx[cur_event_id];
			}
		}
	}

	if (max_probability >= 10000.0) {

	}
	else {
		if (low_probability == 1) {
			for (int i = 0; i < age_events_array[cur_age].event.size(); i++) {
				if (can_rand_event[age_events_array[cur_age].event[i]] > 0) {
					int xx = age_events_array[cur_age].probability[i] * 100;
					for (int j = 0; j < xx; j++) {
						cur_rand_event.push_back(age_events_array[cur_age].event[i]);
					}
				}
			}
		}
		else {
			for (int i = 0; i < age_events_array[cur_age].event.size(); i++) {
				if (can_rand_event[age_events_array[cur_age].event[i]] > 0) {
					int xx = age_events_array[cur_age].probability[i];
					for (int j = 0; j < xx; j++) {
						cur_rand_event.push_back(age_events_array[cur_age].event[i]);
					}
				}
			}
		}
		if(cur_rand_event.size() > 0)cur_event_id = events_array_id_to_idx[cur_rand_event[rand() % cur_rand_event.size()]];
	}

	string print_str1 = "";
	string print_str2 = "";
	string print_str3 = "";
	string print_str3_condition = "";
	print_str1 = events_array[cur_event_id].event;
	EVT[events_array[cur_event_id].id]++;
	AEVT[events_array[cur_event_id].id]++;
	if (events_array[cur_event_id].post_event != "" || events_array[cur_event_id].post_event != "0") {
		print_str2 = events_array[cur_event_id].post_event;
	}
	InitAttributeAssign::UpdateInitArrayByEvent(init_array, events_array, cur_event_id);
	int cur_val1 = Condition::ConditionJudgment(events_array[cur_event_id].branch[0], init_array);
	int cur_val2 = Condition::ConditionJudgment(events_array[cur_event_id].branch[1], init_array);
	int cur_val3 = Condition::ConditionJudgment(events_array[cur_event_id].branch[2], init_array);
	if (cur_val1 > 1) {
		cur_val1 = events_array_id_to_idx[cur_val1];
		print_str3 = events_array[cur_val1].event;
		print_str3_condition = events_array[cur_val1].post_event;
		EVT[events_array[cur_val1].id]++;
		AEVT[events_array[cur_val1].id]++;
		InitAttributeAssign::UpdateInitArrayByEvent(init_array, events_array, cur_val1);
	}
	else if (cur_val2 > 1) {
		cur_val2 = events_array_id_to_idx[cur_val2];
		print_str3 = events_array[cur_val2].event;
		print_str3_condition = events_array[cur_val2].post_event;
		EVT[events_array[cur_val2].id]++;
		AEVT[events_array[cur_val2].id]++;
		InitAttributeAssign::UpdateInitArrayByEvent(init_array, events_array, cur_val2);
	}
	else if (cur_val3 > 1) {
		cur_val3 = events_array_id_to_idx[cur_val3];
		print_str3 = events_array[cur_val3].event;
		print_str3_condition = events_array[cur_val3].post_event;
		EVT[events_array[cur_val3].id]++;
		AEVT[events_array[cur_val3].id]++;
		InitAttributeAssign::UpdateInitArrayByEvent(init_array, events_array, cur_val3);
	}

	cout << "颜值 :" << init_array.CHR << " " << "智力: " << init_array.INT << " " << "体质: " << init_array.STR << " " << "家境: " << init_array.MNY << " " << "快乐: " << init_array.SPR << endl;
	bool already_print_str3 = false;
	if (print_str1 != "" && print_str1 != "0") {
		cout << print_str1 << endl;
	}
	if (print_str3 != "" && print_str3 != "0") {
		cout << print_str3 << endl;
		already_print_str3 = true;
	}
	if (print_str3_condition != "" && print_str3_condition != "0" && already_print_str3 == true) {
		cout << print_str3_condition << endl;
	}

	if (print_str2 != "" && print_str2 != "0" && already_print_str3 == false) {
		cout << print_str2 << endl;

	}
	
	if (init_array.LIF <= 0) {
		for (int i = 0; i < 3; i++) {
			int cur_id = Condition::ConditionJudgment(events_array[0].branch[i], init_array);
			if (cur_id > 1 && aleady_reborn[i] == 0) {
				cout << events_array[events_array_id_to_idx[cur_id]].event << endl;
				init_array.LIF++;
				aleady_reborn[i] = 1;
				break;
			}
		}
	}

}

void Event::TriggerTalentCondition(vector<Talents>& talents_array, int three_talents[], InitAttribute& init_array)
{
	for (int i = 0; i < 3; i++) {
		if (Condition::ConditionJudgment(talents_array[three_talents[i]].condition, init_array) > 0 && aleady_happen[i] == 0) {
			init_array.CHR += talents_array[three_talents[i]].CHR;
			init_array.SPR += talents_array[three_talents[i]].SPR;
			init_array.MNY += talents_array[three_talents[i]].MNY;
			init_array.STR += talents_array[three_talents[i]].STR;
			init_array.INT += talents_array[three_talents[i]].INT;
			aleady_happen[i] = 1;
		}
	}
}

void Event::Init()
{
	cur_age = 0;
	for (int i = 0; i < 3; i++) {
		aleady_happen[i] = 0;
	}
	for (int i = 0; i < 3; i++) {
		aleady_reborn[i] = 0;
	}

}


