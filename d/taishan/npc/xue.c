#include <ansi.h>
inherit NPC;
void create()
{
        set_name("雪衣人", ({ "xue yi ren" }) );
        set("gender", "女性");
	set("age",25);
	set("env/wimpy",90);
        set("combat_exp", 1000000);
        set("long",
		"一个很漂亮的女人，她的来去就像是一阵风，一朵云，一片雪花。\n"
	);
	set_skill("move",300);
        set_skill("dodge", 50);
	set_skill("unarmed",30);
        set("chat_chance", 15);
        set("chat_msg", ({
	(: random_move :),
	name()+"笑了笑：丁鹏练的那一刀并不是用来对付你的。\n",
	name()+"道：丁鹏练这一招，为的是对付谢家三少爷。\n"
        }) );
        setup();
}
