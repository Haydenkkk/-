#include"String.h"

struct Course
{
    Course(String name="", int beginTime=0, int endTime=0, String place="", String teacher="")
            :name(name),beginTime(beginTime),endTime(endTime),place(place),teacher(teacher){}
    String name;
    int beginTime;
    int endTime; //minute+hour*60
    String place;
    String teacher;
    void print2console(){
        std::cout<<name<<"  "<<beginTime/60<<":"<<beginTime%60<<"-"<<endTime/60<<":"<<endTime%60<<"  at: "<<place<<"  teacher: "<<teacher<<'\n';
    }
    // String groupNumber;
    // int examTime;
    // String examPlace;
    // String materialUrl;//课程资料
    // String homeworkedUrl;//已交作业
    // String homeworkUrl;//待交作业
};
struct Activity
{
    Activity(String Type="",String name="", int beginTime=0, int endTime=0, String place="")
            :Type(Type),name(name),beginTime(beginTime),endTime(endTime),place(place){}
    String Type;//集体活动||个人活动
    String name;
    int beginTime;
    int endTime;
    String place;
    void print2console(){
        std::cout<<name<<"  "<<Type<<"  "<<beginTime/60<<":"<<beginTime%60<<"-"<<endTime/60<<":"<<endTime%60<<"  at: "<<place<<'\n';
    }
};
struct Item
{
    Item(Course *course) {activity=nullptr; this->course=course;}
    Item(Activity *activity=nullptr) {course=nullptr; this->activity=activity;}
    Course *course;
    Activity *activity;
    bool isMatching(int beginTime)
    {
        if(course){
            if(course->beginTime==beginTime){
                return true;
            }else{
                return false;
            }
        }else if(activity){
            if(activity->beginTime==beginTime){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    int beginTime(){
        if(course){
            return course->beginTime;
        }else if(activity){
            return activity->beginTime;
        }else{
            return 0;
        }
    }
    void print2console(){
        if(course){
            course->print2console();
        }else if(activity){
            activity->print2console();
        }else{
            std::cout<<"null.";
        }
    }
};
class ItemList
{
public:
    Item exampleItem;
private:
    struct ItemNode
    {
        ItemNode(Item &item){
            this->item=item;
            next=nullptr;
        }
        Item item;
        ItemNode *next;
    };
public:
    ItemList()
    {
        length=0;
        header=nullptr;
    }
    void addItem(Item &item)
    {
        if(header==nullptr){
            header=new ItemNode(item);
            exampleItem=item;
            length=1;
        }else{
            ItemNode *pNode=header;
            while(pNode->next!=nullptr){
                pNode=pNode->next;
            }
            pNode->next=new ItemNode(item);
            length++;
        }
    }
    bool removeItem(int beginTime)//*delete
    {
        if(header==nullptr) return false;
        if(header->item.isMatching(beginTime)){
            header=header->next;
            length--;
            return true;
        }else{
            ItemNode *pNode=header;
            while(pNode->next!=nullptr){
                if(pNode->next->item.isMatching(beginTime)){
                    pNode->next=pNode->next->next;
                    length--;
                    return true;
                }else{
                    pNode=pNode->next;
                }
            }
            return false;
        }
    }
    void dump()
    {
        if(header==nullptr) return;
        ItemNode *pNode=header;
        while(pNode!=nullptr){
            pNode->item.print2console();
            pNode=pNode->next;
        }
    }
    int len() {return length;}
    Item &example()
    {
        return exampleItem;
    }
private:
    ItemNode* header;
    int length;

};
enum Key
{
    Name,
    BeginTime
};