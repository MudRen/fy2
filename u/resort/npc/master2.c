
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("雪蕊儿", ({ "master xuerui", "master","xuerui" }) );
        set("gender", "女性" );
        set("title", "多情剑客");
        set("age", 26);
        set("int", 30);
        set("per", 30);
        set("apprentice_available", 50);
        create_family("铁雪山庄", 1, "女庄主");
	set("long",
		"雪蕊儿从十五岁开始就和爱夫铁少行侠江湖，俩人刀剑合壁，\n"
		"天下无敌。正当俩人名声顶盛之时，又忽然退出江湖，隐居于此。\n"
		);
        set("force_factor", 200);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);

        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set_skill("throwing", 100);
       set_skill("perception", 100);


	set_skill("meihua-shou", 100);
	set_skill("deisword", 150);
	set_skill("qidaoforce", 150);
	set_skill("fall-steps", 100);

	map_skill("unarmed", "meihua-shou");
        map_skill("sword", "deisword");
        map_skill("force", "qidaoforce");
        map_skill("parry", "deisword");
        map_skill("dodge", "fall-steps");

	setup();
	carry_object(__DIR__"obj/yellowcloth")->wear();
        carry_object(__DIR__"obj/msword");
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本庄主今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "女性" )
          {      command("say 我只收女弟子，你还是去拜我的外子吧！");
          }
        else {

                command("smile");
                command("say 你日后必有大成！");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "legend");
        add("apprentice_availavble", -1);
}
int accept_fight(object me)
{
        object xiaocui;
        if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
        {
        command("smile");
        command("say 还是让小翠来吧。");
        return 0;
        }
        else
                command("sigh");
                command("雪蕊儿慢慢的从翠竹凳上站起来，放下了手中的紫砂杯。");
                command("wield wangsword");
                command("say 请！");
                call_out("do_unwie", 3);
                return 1;
}

int do_unwie()
{
	if( !this_object()->is_fighting()) 
	{	
		command("unwield wangsword");
                message_vision("$N拿起茶杯浅啖一口，含情脉脉的望了铁少一眼，又坐在竹凳上。\n", this_object());
                command("smile");
		return 1;
	}
	else
		call_out("do_unwie", 3);
}
void init()
{
        add_action("do_killing", "kill");

}

int do_killing(string arg)
{

        object player, victim, weapon;
        string name;
	if(!arg) return 0;
        player = this_player();
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = victim->name();
                if( name == "铁少")
                {
                message_vision("$N皱皱眉头。\n", this_object());
                message_vision("$N从赤皮剑鞘中抽出一把只有两指宽的虞姬剑握在手中。\n", this_object());
                weapon = present("wangsword", this_object());
                weapon->wield();
                this_object()->kill_ob(player);
                player->kill_ob(this_object());
                call_out("do_unwie", 3);
                return 0;
                }
                if( name == "雪蕊儿")
                {
                message_vision("$N皱皱眉头。\n", this_object());
                message_vision("$N从赤皮剑鞘中抽出一把只有两指宽的虞姬剑握在手中。\n", this_object());
                weapon = present("wangsword", this_object());
                weapon->wield();
                call_out("do_unwie", 3);
                return 0;
                }
                return 0;
        }
        return 0;
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","铁雪派弟子");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","铁雪派小侠");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","铁雪派少侠");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","铁雪派大侠");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","铁雪派奇侠");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","铁雪派长老");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","铁雪派元老");
                return ;
        } else
                student->set("title","铁雪派副掌门");
                return ;
}

