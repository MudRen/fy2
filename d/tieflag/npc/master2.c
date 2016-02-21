
inherit NPC;
inherit F_MASTER;

void create()
{
		object armor;
        set_name("�պ�", ({ "master queen", "master","queen" }) );
        set("gender", "Ů��" );
        set("age", 46);
	set("agi",35);
        set("int", 30);
        set("per", 30);
        set("apprentice_available", 50);
        create_family("������", 1, "����");
	set("long",
		"�պ�����Ѫ�����ŵ��ߴ�����������֮�ޣ��򿴲�����Ѫ�������˶���\n"
		"���ӵ����飬����������һ�ɣ�������������������Ů�ӡ�\n"
		);
        set("force_factor", 10);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 3000);
        set("force", 3000);
        set("attitude", "peaceful");
        set("combat_exp", 3000000);
        set("score", 90000);
        set_skill("dormancy",150);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
		set_skill("dodge", 100);
		set_skill("ill-quan", 100);
		set_skill("fy-sword", 150);
		set_skill("jiayiforce", 120);
		set_skill("tie-steps", 150);
    	
		map_skill("unarmed", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "jiayiforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");

		setup();
	    armor=new(__DIR__"obj/corclot");
		armor->set_name("����˿��",({"cloth"}) );
		armor->move(this_object());
		armor->wear();

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
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �����Ž����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
          {      command("say ��ֻ��Ů���ӣ�");
          }
        else {

                command("smile");
                command("say �����ҳ�������ѧ�������书���������������˾������壡");
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

void init()
{
	object me;
	me = this_player();
	if(userp(me) && interactive(me) && me->query("class") == "tieflag" 
	&&  me->query("marry"))
	{
       command("say �󵨣����Ҵ����Ź棡");
	this_object()->kill_ob(me);
	}
	

}


void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","����������");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","������С��Ů");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��������Ů");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","����������Ů");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��������Ů");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��������Ů");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","������ʥŮ");
                return ;
        } else
                student->set("title","������������");
                return ;
}

