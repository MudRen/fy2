// zhuzao.c
#include <ansi.h>
inherit NPC;

void create()
{
    set_name("夜帝",({"ye di","ye","di"}));
    set("long","他容光焕发，须发有如衣衫般轻柔，\n看来虽是潇洒飘逸，又带有一种不可抗拒之威严。\n");
    set("title","");
    set("gender","男性");
    set("no_arrest",1);
    set("age",42);
    set("int",22);
    set("cor",30);
    set("per",30);
    set("cps",20);
    set("gin",3000);
    set("max_gin",3000);
    set("eff_gin",3000);
    set("max_kee",3000);
    set("eff_kee",3000);
    set("kee",3000);  
    set("max_sen",3000);
    set("sen",3000);    
    set("eff_sen",3000);
    set("combat_exp",10000000);  
    set_skill("ill-quan",200);
    set_skill("force",200);
    set_skill("jiayiforce",150);
    set_skill("unarmed",200);
    set_skill("parry",150);
    set_skill("dodge",150);
    set("force",10000);
    set("max_force",10000);
    set("force_factor",200);
    map_skill("force","jiayiforce");
    map_skill("unarmed","ill-quan");
    set("attitude", "heroism");
    set("chat_chance",10);     
    set("chat_msg",({
          "夜帝开怀大笑。\n",
          }) );

    setup();
    carry_object(__DIR__"obj/sicloth")->wear();   
    add_money("tenthousand-cash", 1);
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    if (me->query_temp("marks/pass_hole_to_yedi") && !query_temp("marks/gived_reward") )
    {
    	me->delete_temp("marks/pass_hole_to_yedi"); 
    	set_temp("marks/gived_reward",1);
    	command("say 你竟能走过我的迷宫，很了不起。");
    	me->add("combat_exp",random(100));
    	me->add("potential",50+random(100));
    }	
    say ("夜帝说道：“你看看老夫这地方还好吗？”\n");
    return 1;
}
 
