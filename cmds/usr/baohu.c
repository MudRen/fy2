// user list
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string id, id2;
	object obj, *pros;
	int i;
	if (!arg)
		return notify_fail("指令格式 : baohu <对象>\n");
	if(!stringp(id=me->query("marry")))
		return notify_fail("你好象并没有结婚！\n");
	if(id != arg)
		return notify_fail(arg+"好象并不是你的妻子／丈夫！\n");
	if(!objectp(obj=present(id,environment(me))))
		return notify_fail(id+"好象并不在你的周围！\n");
	id2 = obj->query("marry");
	if( id2 != me->query("id"))
		return notify_fail(arg+"好象并不是你的妻子／丈夫！\n");
// passed all checks!
	pros = obj->query_temp("protectors");
	for(i=0;i<sizeof(pros);i++)
		if(pros[i] == me) 
		{
		 pros -= ({ me });
		return notify_fail("你停止保护"+arg+"了！\n");
		}

	if(sizeof(pros))
		pros += ({ me });
	else
		pros = ({ me });
	obj->set_temp("protectors",pros);
	write("你开始保护"+arg+"\n");
	return 1;
	
}

int help(object me)
{
write(@HELP
指令格式 : baohu <对象>

这是已婚夫妇用来保护对方（妻子／丈夫）的指令
当你成为保护者时，你可以用自己高超的拆招的技能来保护
自己的同伴，替对方拆架敌人的攻击。
HELP
    );
    return 1;
}
