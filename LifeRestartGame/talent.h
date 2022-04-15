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
	int last_talent_ = -1;   //�����һ����Ϸѡ�������츳
	int play_number_ = 0;	//����������
	int three_talents_[3] = {0};    //���ѡ���3���츳
	int save_three_talents_[3] = {0};	//������ҳ�ʼѡ����츳
	int rand_talents_array_[10] = {0}; //�������10���츳
};