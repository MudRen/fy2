// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
	int s;

	s = me->query_skill("literate", 1);
        if( s%10==9 && (int)me->query("int") < s/5) {
		tell_object(me, HIW "由於你的勤学苦读，你的悟性提高了。\n" NOR);
		me->add("int", 2);
	}
}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

