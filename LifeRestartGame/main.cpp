#include<cstdlib>
#include"csv_file.h"
#include"config.h"
#include "talent.h"
#include"event.h"
using namespace std;


int main()
{  
    //对配置文件进行读取并进行赋值
    AgeEventAssign age_event;
    age_event.AgeEventAssignData();
    TalentsAssign talents;
    talents.TalentsAssignData();
    EventsAssign events;
    events.EventsAssignData();
    if (age_event.age_events_array_.size() > 0) {
        cout << "读取age.csv配置文件成功" << endl;
    }
    else {
        cout << "读取age.csv配置文件失败" << endl;
    }
    if (talents.talents_array_.size() > 0) {
        cout << "读取talents.csv配置文件成功" << endl;
    }
    else {
        cout << "读取talents.csv配置文件失败" << endl;
    }
    if (events.events_array_.size() > 0) {
        cout << "读取events.csv配置文件成功" << endl;
    }
    else {
        cout << "读取events.csv配置文件失败" << endl;
    }

    cout << "欢迎来到人生模拟器！" << endl;
    cout << endl;
    Talent rand_ten_talent;
    while (1) {
        TLT.clear();
        EVT.clear();     
        InitAttributeAssign init_array;
        //初始化
        rand_ten_talent.Init();
        //随机天赋
        rand_ten_talent.RandTalent(talents.talents_array_);
        //玩家选择天赋
        rand_ten_talent.SelectTalent(talents.talents_array_);
        //根据效果替换天赋
        rand_ten_talent.ReplaceTalent(talents.talents_array_, talents.talents_array_id_to_idx_);
        //根据天赋更新初始数组的值
        init_array.UpdateInitArrayByTalent(talents.talents_array_, rand_ten_talent.three_talents_);
        //玩家进行输入分配的属性大小
        cout << "请输入初始属性，格式为：<颜值 智力 体质 家境>，如（3 7 6 4）" << endl;
        cout << "注意：单个属性不能小于0或大于10，总和不能大于" << init_array.cur_status_attributes << "!" << endl;
        init_array.UpdateInitArrayByInput();
        cout << "你的初始属性：" << endl;
        //输出对应信息
        init_array.Print();
        cout << endl;
        //进行随机事件
        Event start_rand_event;
        start_rand_event.Init();
        while (init_array.init_array_.LIF >= 1) {
            //判断是否触发天赋条件
            start_rand_event.TriggerTalentCondition(talents.talents_array_, rand_ten_talent.three_talents_, init_array.init_array_);
            //随机并输出事件
            start_rand_event.RandEvent(age_event.age_events_array_, events.events_array_id_to_idx_, init_array.init_array_, events.events_array_);
            cout << endl;
            if (init_array.init_array_.LIF <= 0) {
                cout << "人生总结：" << endl;
                cout << "颜值 :" << init_array.init_array_.CHR << " " << "智力: " << init_array.init_array_.INT << " " << "体质: " << init_array.init_array_.STR << endl;
                cout << "家境: " << init_array.init_array_.MNY << " " << "快乐: " << init_array.init_array_.SPR << " " << "年龄:" << init_array.init_array_.AGE << endl;
                cout << "总评:" << init_array.init_array_.CHR + init_array.init_array_.INT + init_array.init_array_.STR + init_array.init_array_.MNY + init_array.init_array_.SPR + init_array.init_array_.AGE << endl;
                break;
            }
            init_array.init_array_.AGE++;
            Sleep(1000);
        }
        cout << "天使姐姐出现了，询问你是否要在人间重新走一回（y or n）？" << endl;
        string remake;
        cin >> remake;
        TMS++;
        if (remake == "y") {
            //选择保留天赋
            rand_ten_talent.SelectSaveTalent(talents.talents_array_);
        }
        else {
            break;
        }
    }



    return 0;
}

