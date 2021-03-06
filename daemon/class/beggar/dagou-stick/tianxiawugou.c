// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［天下无狗］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	if((int)me->query_skill("dagou-stick",1) < 100)
		return notify_fail("你的打狗棒法还不够精纯！\n");
	extra = me->query_skill("staff") / 7;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N低喝一声［天下无狗］，内力聚于手中的"+ weapon->name() +"，"+
weapon->name() +
"化成满天棍影，昏天黑地般盖向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
