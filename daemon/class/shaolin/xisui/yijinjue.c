// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;
	object corp;
	if( !target ) target = me;

        if((int)me->query_skill("xisui",1) < 120 )
                return notify_fail("你的洗髓经不够高！\n");

	if( !target || target != me)
		return notify_fail("你只能对自己用易筋诀\n");
        if( (int)target->query_temp("xisui") ) return
	notify_fail("已经在施展易筋诀了。\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("你的气血不够！\n");
	me->receive_wound("kee", 100);
	msg = HIC "$N凝神聚力，身形居然高大了一截！！\n\n" NOR;
	message_vision(msg,me);
	target->add_temp("apply/strength", (int)target->query_str()/10);
	target->set_temp("xisui",1);
	target->start_busy(1);
	me->start_busy(2);
	        target->start_call_out( (: call_other, __FILE__, "remove_effect", target,
(int)target->query_str()/10 :), (int)me->query_skill("xisui")/7);

	return 1;
}
void remove_effect(object me, int amount)
{
        me->delete_temp("xisui");
        tell_object(me, "你用功完毕，全身恢复正常。\n");
	me->add_temp("apply/strength",-amount);
}

