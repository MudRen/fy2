#include <vote.h>
#include <ansi.h>
#define COL_PERIOD 300
inherit F_DBASE;
void check_vote(string whowhat);
int get_value(string what);
void create()
{
        seteuid( ROOT_UID );
}
int add_vote(object me, string what, string who)
{
// three things can happen when we adding a vote:
// 1. Brand new vote, 2. Increment vote count, 3. decision vote
// case 1, brand new votes
	if(!query(who+"/"+what))
	{
	set(who+"/"+what, ({ (string)me->query("id") }));
	set(who+"/"+what+"_time", time());
	call_out("check_vote", COL_PERIOD, who+"/"+what);
	return 1;
	}
// case 2 adding votes
	if(sizeof(query(who+"/"+what)) < get_value(what))
	{
	string *ids;
	int i;	
	ids = query(who+"/"+what);
	// see if this guy already voted on this matter
	for(i=0;i<sizeof(query(who+"/"+what));i++)
		if(ids[i] == (string)me->query("id"))
				return 0;
	add(who+"/"+what, ({ (string)me->query("id") }));
        if(sizeof(query(who+"/"+what)) < get_value(what))
		return sizeof(query(who+"/"+what));
	else

// delete this record and go do it!
	delete(who+"/"+what);
	return i+1;

	}
}

void check_vote(string whowhat)
{
// this is a check to cancel votes that is not fullfilled within 5 mins
	string who,what;
	string msg;
	if(sscanf(whowhat,"%s/%s",who,what) !=2 ) return;
	if(query(whowhat))
	{
	msg = HIW "��ͶƱ�����������Ʊ�����������ڶ�"+who+"ʵ��"+what+"�ı������ȡ����\n" NOR; 	
	message("system",msg,users());	
	delete(who+"/"+what);
	}
	return;
}
int get_value(string what)
{
switch(what) {
	case "right": return (int) right_no;
        case "noright": return (int) noright_no;
        case "kickout": return (int) kickout_no;
        case "robot": return (int) robot_no;
        case "block": return (int) block_no;
        case "noblock": return (int) noblock_no;
        case "ban": return (int) ban_no;
        case "off": return (int) off_no;
        case "on": return (int) on_no;
	case "imprison" : return (int) imprison_no;
	case "redis" : return (int) sizeof(users())/2 + 1;
	default : return 0;
		}

}
