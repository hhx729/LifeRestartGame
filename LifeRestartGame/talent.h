#pragma once
#include"config.h"

class Talent{
public:
	void Init();
	void RandTalent(vector<Talents>& talents_array);
	void SelectTalent(vector<Talents>& talents_array);
	void ReplaceTalent(vector<Talents>& talents_array, map<int, int>&id_to_idx);
	void SelectSaveTalent(vector<Talents>& talents_array);
public:
	int last_talent_ = -1;   //玩家上一轮游戏选择保留的天赋
	int play_number_ = 0;	//玩家游玩次数
	int three_talents_[3] = {0};    //玩家选择的3个天赋
	int save_three_talents_[3] = {0};	//保留玩家初始选择的天赋
	int rand_talents_array_[10] = {0}; //随机到的10个天赋
};