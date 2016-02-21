// TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
	string msg;
	int lvl, ap, dp;

	if(!me->is_fighting())
	return notify_fail("���Ƿ��еģۺ��Ǿ���ֻ������ս����ʩչ��\n");
	if( !target ) target = offensive_target(me);
        if((int)me->query_skill("spells") < 80 )
                return notify_fail("��ķ��������ߣ�\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse() )
	
		return notify_fail("��Ҫ��˭ʩչ���������\n");

	if(target->query_temp("in_hanxing"))
	return notify_fail("�����ڲ�����Ҫʩչ���Ǿ���\n");

	if((int)me->query("mana") < 300 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("mana", -300);
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 30 ) {
		write("��ʧ���ˣ�\n");
		return 1;
	}

	msg = HIC "$N���������дʣ�һ����â��$Nͷ�������������$n��Χ��\n\n" ;

	ap = me->query_skill("spells");
	ap = ( ap * ap /100 * ap/30 ) * (int)me->query("sen") ;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
	msg +="��â����һ����ף�����ס$n��ȫ��\n";
	lvl = (int)me->query_skill("spells") * 2;
		target->set_temp("in_hanxing",1);
		target->add_temp("apply/extra_fle",lvl);
        	seteuid(ROOT_UID);
		target->start_call_out( (: call_other, __FILE__, "remove_hanxing",target, lvl :),
		random(lvl/20)+lvl/20);
	} else
		msg += "�������Ͼ���ʧ�ˡ�\n";
        if(me == target) 
        {
        msg = replace_string(msg, "$n","$N");
        message_vision(msg+NOR,me);
        }
        else
        message_vision(msg+NOR, me, target);
	me->start_busy(1);
	return 1;
}

void remove_hanxing(object me, int lvl)
{
   me->delete_temp("in_hanxing");
   me->add_temp("apply/extra_fle",-lvl);
   message_vision(HIY "\n\n$N����Ĺ�׷���ҫ�۵�һ������ʧ�ˡ�\n\n" NOR, me);
}
