// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("dodge");
	if ( extra < 200) return notify_fail("�����Ծ����֮�����������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ÿ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(me->query("env/invisibility"))
		return notify_fail("������ʩչ����ÿ����\n");
	if(me->query("force") < 100)
		return notify_fail("�������������\n");
	me->add("force",-100);
message_vision( HIR "$N\n\nʹ��������ղ�����һʽ����ÿ��飢���������񣬲�����գ�\n
��Ӱ��$n����ǰٿ����ʧ����Ȼ���٣�������\n\n" NOR,me,target);
	me->set("env/invisibility",1);
	me->start_busy(3);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/10);
	return 1;
}
void remove_effect(object me)
{
        me->delete("env/invisibility");
        tell_object(me, "�����ÿ���ʩչ��ϣ�����ͣ��������\n");
}

