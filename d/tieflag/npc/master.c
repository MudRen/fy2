inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({ "master tie", "master","tie" }) );
        set("gender", "����" );
        set("age", 26);
        set("int", 30);
        set("per", 15);
	set("agi",35);
        set("apprentice_available", 50);
        create_family("��Ѫ������", 8, "����");
	set("long",
		"����������Ѫ�����ŵĴ��ˡ�\n"
		);
        set("force_factor", 30);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 5000);
        set("force", 5000);
        set("attitude", "peaceful");
        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("dormancy",150);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
		set_skill("dodge", 100);
		set_skill("ill-quan", 150);
		set_skill("fy-sword", 100);
		set_skill("cloudsforce", 100);
		set_skill("tie-steps", 150);
    	
		map_skill("unarmed", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "cloudsforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");

		setup();
        	carry_object(__DIR__"obj/tieflag");
		carry_object("obj/cloth")->wear();
}
void reset()
{
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �����Ž����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
        if (ob->query_temp("mark/can_apprentice_master_tie"))
        if( (string)ob->query("gender") != "����" )
          {      command("say ��ֻ���е��ӣ�");
          }
        else {

                command("smile");
                command("say ���պ���д�ɣ�");
                command("smile");
                command("recruit " + ob->query("id") );
	 }
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tieflag");
        add("apprentice_availavble", -1);
}

int accept_object(object me, object obj)
{
        if(obj->query("id")=="silk book" && me->query_temp("mark/silkbook"))
        {
        	me->set_temp("mark/can_apprentice_master_tie",1);
        	me->delete_temp("mark/silkbook");
        	command("say ��⣬�����������\n");
        	return 1;
        }
	if(obj->query("id")=="flag" && obj->query("fake"))
	{
	command("say �󵨣����Ķ�Ū��һ����������Ū�Ϸ�\n");
	kill_ob(me);
	return 1;
	}
        return 0;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��Ѫ�����ŵ���");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","��Ѫ������С��");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��Ѫ����������");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��Ѫ�����Ŵ���");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��Ѫ����������");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��Ѫ������Ԫ��");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��Ѫ������Ԫ��");
                return ;
        } else
                student->set("title","��Ѫ�����Ÿ�����");
                return ;
}
