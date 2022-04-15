#include"talent.h"

void Talent::Init() {
	if (play_number_ == 0) {
		cout << "一道闪光过后，新的人生开始了！" << endl;
	}
	cout << "命运的轮盘开始转动，逐渐显示出十个天赋：" << endl;
}

void Talent::RandTalent(vector<Talents>& talents_array) {
	srand((unsigned)time(NULL));
	map<int, int>rand_talents;
	map<int, int>exclude_talents;
	for (int i = 0; i < 10; i++) {
		int cur_rand = rand() % talents_array.size();
		if (rand_talents[cur_rand] < 1 && talents_array[cur_rand].exclusive != 1 && exclude_talents[talents_array[cur_rand].id] < 1) {
			rand_talents_array_[i] = cur_rand;
			rand_talents[cur_rand]++;
			for (int j = 0; j < 8; j++)
				if (talents_array[cur_rand].exclude[j] >= 1000)	exclude_talents[talents_array[cur_rand].exclude[j]]++;
		}
		else {
			i--;
		}
	}
	if (last_talent_ != -1) rand_talents_array_[0] = last_talent_;
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << ": ";
		if (talents_array[rand_talents_array_[i]].grade == 0) {
			cout << "【白色】 ";
		}
		else if (talents_array[rand_talents_array_[i]].grade == 1) {
			cout << "【蓝色】 ";
		}
		else if (talents_array[rand_talents_array_[i]].grade == 2) {
			cout << "【紫色】 ";
		}
		else if (talents_array[rand_talents_array_[i]].grade == 3) {
			cout << "【橙色】 ";
		}
		cout << talents_array[rand_talents_array_[i]].name << " " << "(" << talents_array[rand_talents_array_[i]].description << ")" << endl;
	}
}

void Talent::SelectTalent(vector<Talents>& talents_array) {
	cout << "请输入选择3个天赋序号（1~10）,用空格分隔，如：（1 2 3）:" << endl;
	while (1) {
		int flag = 0;
		for (int i = 0; i < 3; i++) {
			cin >> three_talents_[i];
			if (three_talents_[i] > 10 || three_talents_[i] < 1) {
				flag = 1;
			}
		}
		if (flag == 1) {
			cout << "输入序号错误，需要在1~10之间，请重新输入！" << endl;
			continue;
		}

		cout << "您选择的天赋：" << endl;
		for (int i = 0; i < 3; i++) {
			if (talents_array[rand_talents_array_[three_talents_[i] - 1]].grade == 0) {
				cout << "【白色】 ";
			}
			else if (talents_array[rand_talents_array_[three_talents_[i] - 1]].grade == 1) {
				cout << "【蓝色】 ";
			}
			else if (talents_array[rand_talents_array_[three_talents_[i] - 1]].grade == 2) {
				cout << "【紫色】 ";
			}
			else if (talents_array[rand_talents_array_[three_talents_[i] - 1]].grade == 3) {
				cout << "【橙色】 ";
			}
			cout << talents_array[rand_talents_array_[three_talents_[i] - 1]].name << " " << "(" << talents_array[rand_talents_array_[three_talents_[i] - 1]].description << ")" << endl;

		}
		break;
	}
}

void Talent::ReplaceTalent(vector<Talents>& talents_array, map<int, int>& id_to_idx) {
	vector<int>white_attributes;
	vector<int>blue_attributes;
	vector<int>purple_attributes;
	vector<int>orange_attributes;
	vector<int>cur_three_talents;
	//存储各种品质的天赋
	for (int i = 0; i < talents_array.size(); i++) {
		id_to_idx[talents_array[i].id] = i;
		if (talents_array[i].id == talents_array[rand_talents_array_[three_talents_[0] - 1]].id) {
			cur_three_talents.push_back(i);
		}
		if (talents_array[i].id == talents_array[rand_talents_array_[three_talents_[1] - 1]].id) {
			cur_three_talents.push_back(i);
		}
		if (talents_array[i].id == talents_array[rand_talents_array_[three_talents_[2] - 1]].id) {
			cur_three_talents.push_back(i);
		}
		if (talents_array[i].grade == 0) {
			white_attributes.push_back(i);
		}
		if (talents_array[i].grade == 1) {
			blue_attributes.push_back(i);
		}
		if (talents_array[i].grade == 2) {
			purple_attributes.push_back(i);
		}
		if (talents_array[i].grade == 3) {
			orange_attributes.push_back(i);
		}
	}

	//将id换成idx
	for (int i = 0; i < 3; i++) {
		three_talents_[i] = cur_three_talents[i];
		save_three_talents_[i] = three_talents_[i];
	}

	// 根据天赋随机替换为同等级的其他天赋
	for (int i = 0; i < 3; i++) {
		if (talents_array[three_talents_[i]].replacement_grade == 0) {
			int cur_rand = rand() % white_attributes.size();
			three_talents_[i] = white_attributes[cur_rand];
		}
		else if (talents_array[three_talents_[i]].replacement_grade == 1) {
			int cur_rand = rand() % blue_attributes.size();
			three_talents_[i] = blue_attributes[cur_rand];
		}
		else if (talents_array[three_talents_[i]].replacement_grade == 2) {
			int cur_rand = rand() % purple_attributes.size();
			three_talents_[i] = purple_attributes[cur_rand];
		}
		else if (talents_array[three_talents_[i]].replacement_grade == 3) {
			int cur_rand = rand() % orange_attributes.size();
			three_talents_[i] = orange_attributes[cur_rand];
		}
	}

	//将天赋随机替换为replacement[]的天赋
	for (int i = 0; i < 3; i++) {
		if (talents_array[three_talents_[i]].replacement[0] != "" && talents_array[three_talents_[i]].replacement[0] != "0") {
			vector<int>cur_rand_talents;
			for (int j = 0; j < talents_array[three_talents_[i]].replacement_idx; j++) {
				string tmp_str = "";
				if (talents_array[three_talents_[i]].replacement[j] != "" && talents_array[three_talents_[i]].replacement[j] != "0") {
					for (int k = 0; k < talents_array[three_talents_[i]].replacement[j].size(); k++) {
						if (talents_array[three_talents_[i]].replacement[j][k] != '*')
							tmp_str += talents_array[three_talents_[i]].replacement[j][k];
						else {
							break;
						}
					}
				}
				if (tmp_str != "") cur_rand_talents.push_back(atoi(tmp_str.c_str()));
				tmp_str = "";
			}
			int cur_num = cur_rand_talents[rand() % cur_rand_talents.size()];
			three_talents_[i] = id_to_idx[cur_num];
		}
	}
	white_attributes.clear();
	blue_attributes.clear();
	purple_attributes.clear();
	orange_attributes.clear();
	cur_three_talents.clear();

}

void Talent::SelectSaveTalent(vector<Talents>& talents_array)
{
	cout << "请输入的天赋序号（如 1），下辈子还能抽到:" << endl;
	for (int i = 0; i < 3; i++) {
		three_talents_[i] = save_three_talents_[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << i + 1;
		if (talents_array[three_talents_[i]].grade == 0) {
			cout << "【白色】 ";
		}
		else if (talents_array[three_talents_[i]].grade == 1) {
			cout << "【蓝色】 ";
		}
		else if (talents_array[three_talents_[i]].grade == 2) {
			cout << "【紫色】 ";
		}
		else if (talents_array[three_talents_[i]].grade == 3) {
			cout << "【橙色】 ";
		}
		cout << talents_array[three_talents_[i]].name << " " << "(" << talents_array[three_talents_[i]].description << ")" << endl;

	}
	while (1) {
		int flag = 0;
		cin >> last_talent_;
		if (last_talent_ > 3 || last_talent_ < 1) {
			flag = 1;
		}
		if (flag == 1) {
			cout << "输入序号错误，需要在1~3之间，请重新输入！" << endl;
			continue;
		}
		last_talent_ = three_talents_[last_talent_ - 1];
		break;
	}
}
