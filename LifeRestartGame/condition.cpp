#include "condition.h"

int Condition::ConditionJudgment(string str, InitAttribute& init_array)
{
	if (str == "" || str == "0") return 1;
	str += "&";
	string cur1 = "";   //表示哪个变量条件
	string cur2 = "";	//表示哪个符号
	string cur3 = "";   //存储当前数字
	string cur4 = "";    //表示字符串中所有的|或&
	string cur5 = "";    //存储1或0表示当前条件是否成立
	string cur6 = "";     //表示branch分支:后面出现的数字
	vector<int>number;   
	number.clear();
	int cur_flag = 0;    //表示是否出现:这个符号
	int res = 0;          
	int cur_flag2 = 0;      
	int cur_flag3 = 0;
	for (int j = 0; j < str.size(); j++) {
		if (str[j] == ':') {
			cur_flag = 1;
			continue;
		}
		if (cur_flag == 1 && str[j] >= '0' && str[j] <= '9') {
			cur6 += str[j];
			continue;
		}
		if (str[j] == '(' || str[j] == '\"') {
			continue;
		}

		if (str[j] == 'C' && str[j + 1] == 'H' && str[j + 2] == 'R') {
			cur1 = "CHR";
		}
		if (str[j] == 'I' && str[j + 1] == 'N' && str[j + 2] == 'T') {
			cur1 = "INT";
		}
		if (str[j] == 'S' && str[j + 1] == 'T' && str[j + 2] == 'R') {
			cur1 = "STR";
		}
		if (str[j] == 'M' && str[j + 1] == 'N' && str[j + 2] == 'Y') {
			cur1 = "MNY";
		}
		if (str[j] == 'S' && str[j + 1] == 'P' && str[j + 2] == 'R') {
			cur1 = "SPR";
		}
		if (str[j] == 'L' && str[j + 1] == 'I' && str[j + 2] == 'F') {
			cur1 = "LIF";
		}
		if (str[j] == 'A' && str[j + 1] == 'G' && str[j + 2] == 'E') {
			cur1 = "AGE";
		}
		if (str[j] == 'E' && str[j + 1] == 'V' && str[j + 2] == 'T') {
			cur1 = "EVT";
		}
		if (str[j] == 'T' && str[j + 1] == 'L' && str[j + 2] == 'T') {
			cur1 = "TLT";
		}
		if (str[j] == 'T' && str[j + 1] == 'M' && str[j + 2] == 'S') {
			cur1 = "TMS";
		}
		if (str[j] == 'A' && str[j + 1] == 'E' && str[j + 2] == 'V' && str[j + 3] == 'T') {
			cur1 = "AEVT";
		}
		if (str[j] == '>') {
			cur2 = ">";
		}
		if (str[j] == '<') {
			cur2 = "<";
		}
		if (str[j] == '!') {
			cur2 = "!";
		}
		if (str[j] == '?') {
			cur2 = "?";
		}
		if (str[j] == ')' && str[j + 1] == ')' && str[j + 2] == '|') {
			cur_flag2 = 1;
		}
		if (str[j] == '&' && str[j + 1] == '(' && str[j + 2] == '(') {
			cur_flag3 = 1;
		}
		if (str[j] >= '0' && str[j] <= '9') {
			cur3 += str[j];
		}
		if (str[j] == ' ' || str[j] == ')' || str[j] == ']') {
			number.push_back(atoi(cur3.c_str()));
			cur3 = "";
		}
		if (str[j] == '|' || str[j] == '&') {
			if (cur3 != "") number.push_back(atoi(cur3.c_str()));
			cur3 = "";
			cur4 += str[j];
			if (cur1 == "CHR") {
				if (cur2 == ">") {
					if (init_array.CHR > number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "<") {
					if (init_array.CHR < number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
			}
			if (cur1 == "INT") {
				if (cur2 == ">") {
					if (init_array.INT > number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "<") {
					if (init_array.INT < number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
			}
			if (cur1 == "STR") {
				if (cur2 == ">") {
					if (init_array.STR > number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "<") {
					if (init_array.STR < number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
			}

			if (cur1 == "MNY") {
				if (cur2 == ">") {
					if (init_array.MNY > number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "<") {
					if (init_array.MNY < number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
			}

			if (cur1 == "SPR") {
				if (cur2 == ">") {
					if (init_array.SPR > number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "<") {
					if (init_array.SPR < number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
			}

			if (cur1 == "LIF") {
				if (cur2 == ">") {
					if (init_array.LIF > number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "<") {
					if (init_array.LIF < number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
			}

			if (cur1 == "AGE") {
				if (cur2 == ">") {
					if (init_array.AGE > number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "<") {
					if (init_array.AGE < number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "?") {
					if (init_array.AGE == number[0]) {
						cur5 += "1";
					}
				}
			}



			if (cur1 == "TMS") {
				if (cur2 == ">") {
					if (TMS > number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "<") {
					if (TMS < number[0]) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
			}

			if (cur1 == "EVT") {
				if (cur2 == "?") {
					int gg = 0;
					for (int k = 0; k < number.size(); k++) {
						if (EVT[number[k]] > 0) {
							gg = 1;
							break;
						}
					}
					if (gg == 1) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "!") {
					int gg = 1;
					for (int k = 0; k < number.size(); k++) {
						if (EVT[number[k]] > 0) {
							gg = 0;
							break;
						}
					}
					if (gg == 0) {
						cur5 += "0";
					}
					else {
						cur5 += "1";
					}
				}
			}

			if (cur1 == "AEVT") {
				if (cur2 == "?") {
					int gg = 0;
					for (int k = 0; k < number.size(); k++) {
						if (AEVT[number[k]] > 0) {
							gg = 1;
							break;
						}
					}
					if (gg == 1) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "!") {
					int gg = 1;
					for (int k = 0; k < number.size(); k++) {
						if (AEVT[number[k]] > 0) {
							gg = 0;
							break;
						}
					}
					if (gg == 0) {
						cur5 += "0";
					}
					else {
						cur5 += "1";
					}
				}
			}


			if (cur1 == "TLT") {
				if (cur2 == "?") {
					int gg = 0;
					for (int k = 0; k < number.size(); k++) {
						if (TLT[number[k]] > 0) {
							gg = 1;
							break;
						}
					}
					if (gg == 1) {
						cur5 += "1";
					}
					else {
						cur5 += "0";
					}
				}
				else if (cur2 == "!") {
					int gg = 1;
					for (int k = 0; k < number.size(); k++) {
						if (TLT[number[k]] > 0) {
							gg = 0;
							break;
						}
					}
					if (gg == 0) {
						cur5 += "0";
					}
					else {
						cur5 += "1";
					}
				}
			}
			cur1 = "";
			cur2 = "";
			cur3 = "";
			number.clear();
		}
		if (str[j] == ':') {
			cur_flag = 1;
		}
	}
	int gg = 0;
	int hh = 0;
	int kk = 0;
	for (int k = 0; k < cur4.size(); k++) {
		if (cur4[k] == '|') {
			gg = 1;
		}
	}
	for (int k = 0; k < cur5.size(); k++) {
		if (cur5[k] == '0') {
			hh = 1;
		}
		if (cur5[k] == '1') {
			kk = 1;
		}
	}

	if (cur_flag3 == 1) {
		if (cur5[0] == '1' && cur5[1] == '1' && cur5[2] == '0') {
			return 1;
		}
		if (cur5[0] == '1' && cur5[1] == '0' && cur5[2] == '1') {
			return 1;
		}
		if (cur5[0] == '1' && cur5[1] == '1' && cur5[2] == '1') {
			return 1;
		}
		return 0;
	}

	if (cur_flag2 == 1) {
		if (cur5[0] == '1' && cur5[1] == '1' && cur5[2] == '1') {
			return 1;
		}
		if (cur5[0] == '1' && cur5[1] == '1' && cur5[2] == '0') {
			return 1;
		}
		if (cur5[2] == '1') {
			return 1;
		}

		return 0;

	}
	if (cur_flag == 1) {
		res = atoi(cur6.c_str());
	}

	if (cur_flag == 1) {
		if (gg == 0 && hh == 0) return res;
		else if (gg == 1 && kk == 1)return res;
		else  return 0;
	}


	if (gg == 0 && hh == 0) return 1;
	else if (gg == 1 && kk == 1)return 1;
	else  return 0;
}
