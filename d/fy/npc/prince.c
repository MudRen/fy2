// Tie @ fy3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("С����", ({ "prince", "little prince"}) );
        set("gender", "����" );
        set("age", 12);
        set("long", "���ǵ�����ϵ�С���ӣ����ܳ谮��һ��\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
	set_skill("dodge", 100);
	set_skill("leadership",300);
	set_skill("strategy",300);
        set("intellgent",1);
        set("chat_chance", 1);
	set("class","official");
        set("chat_msg", ({
                "С�����ſڵ�����"+HIR"��"NOR+"һ�������δ�����"+HIG"��"NOR+"��\n",
        }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: ccommand, "alert" :),
        }) );
	setup();
	add_money("gold", 5);
        carry_object(__DIR__"obj/fycloth")->wear();
}

