// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("南宫灵", ({ "master nangong", "master"}) );
        set("nickname", HIR "神掌" NOR);
        set("gender", "男性" );
        set("age", 34);
	set("per", 35);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 30);
        set("long",
"
现任天下第一大帮的帮主，前老帮主任慈的爱子。
\n"
	);
        create_family("丐帮", 7, "龙头帮主");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xianglongwuhui" :)
        }) );
        set("combat_exp", 2000000);
        set_skill("move", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
	set_skill("unarmed",150);
	set_skill("doggiesteps",100);
	set_skill("dragonstrike",100);
	set_skill("huntunforce",100);
	set_skill("staff",150);
	set_skill("dagou-stick",150);
	set_skill("begging",120);
	set_skill("inquiry",120);
        map_skill("dodge", "doggiesteps");
	map_skill("force", "huntunforce");
	map_skill("unarmed", "dragonstrike");
	map_skill("staff","dagou-stick");
	map_skill("parry","dagou-stick");
        set("inquiry", ([
                "谋杀" : (: kill_him :),
                "任慈" : (: kill_him :),
        ]));
        setup();
        carry_object(__DIR__"obj/9bagcloth")->wear();

}

void attempt_apprentice(object me)
{
	if((int)me->query("deposit")<=0)
	{
	command("say 看在你一贫如洗的份上，我就收你为徒吧！\n");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("sigh");
        command("say 看来真的是树大招风，你有钱有势的，为什么要加入我丐帮？\n");

	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "beggar");
}
int kill_him()
{
	object me;
	me = this_player();
	command("say 看来你已经知道得太多了！！ \n");
	this_object()->kill_ob(me);
	me->kill_ob(this_object());
	return 1;
}
void re_rank(object student)
{
	int exp;
	exp = (int) student->query("combat_exp");
	if( exp <= 32000 ) {
		student->set("title","丐帮堂外弟子");
		return ;	
	} else if ( exp <= 64000 ) {
		student->set("title","丐帮一袋弟子");
		return ;
        } else if ( exp <= 128000 ) {
                student->set("title","丐帮两袋弟子");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","丐帮三袋弟子");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","丐帮四袋弟子");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","丐帮五袋弟子");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","丐帮六袋弟子");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","丐帮七袋弟子");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","丐帮八袋弟子");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","丐帮九袋弟子");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","丐帮长老");
                return ;
        } else 
                student->set("title","丐帮副帮主");
                return ;

}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
	if(ob) 
	ob->set_temp("killed_master_nangong",1);
        ::die();
}
