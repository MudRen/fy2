// teacher.c

inherit NPC;
#include <ansi.h>

int test_dart();
void create()
{
	set_name("����", ({ "meng", "cha meng" }) );
	set("title", HIY "��ʨ��" NOR);
	set("gender", "����" );
	set("age", 42);
	set("skill_public",1);
	set("inquiry",	([
		"mission" : (: test_dart :),
		"����" : (: test_dart :),
	]) );
	set("int", 30);
        create_family("�����׼�", 21, "����");
	set("long",
		"��ʨ�Ʋ����������׼ҵ��ӣ��˲��������ˬ���ҹ㽻���ѣ�
		 ������������̵ģ�ֻҪΪ�ھֳ����������ͿϽ̣�\n"
		);
       set("chat_chance", 10);
        set("chat_msg", ({
                "����˵����������ھ����ⲻ��\n",
		"����˵�������ڣ�����������£�������\n",
        }) );
	set("attitude", "peaceful");
	set_skill("unarmed", 30);
	set_skill("changquan", 30);
	set_skill("literate", 30);
	set_skill("force", 30);
	set_skill("dodge",30);
	set_skill("parry",30);
	map_skill("unarmed", "changquan");
	set("combat_exp", 90000);
	setup();
	carry_object(__DIR__"obj/jinzhuang")->wear();
}
void init()
{
        ::init();
        add_action("do_accept", "accept");
}

int recognize_apprentice(object ob)
{
        if((time() - ob->query("marks/��ʨ") ) > 1800  ){
                say("����˵�����㣮�������ܾ�ûΪ�ھֳ�������....\n");
                return 0;
        }

        return 1;
}
int test_dart()
{
	object me;
	
	me=this_player();
	if (random(100)>50  || query("marks/gived") )
	{
		set("marks/gived",1);
		command("say �����ھ�����û����Ҫ�����ڡ�");
		return 1;
	}
	
	command("say �����Ϲ�Ǯׯ��һ��������Ҫ�˵����������Ը��Э�����ǣ�(accept mission)");
	return 1;
}
int do_accept(string arg)
{    
	object ob,cart,biaotou;
	object me,*team;
	int i;	
	if (arg != "mission") return 0;
	me=this_player();
	team=me->query_team();
	if (sizeof(team)==0) team=({me});
	for (i=0;i<sizeof(team);i++)
	{
		if (team[i]->query("combat_exp")<10000)
		{
			command("say ����·;Σ�գ��ҿ���λ"+RANK_D->query_respect(team[i])+"�ƺ����ˣ�");
			return 1;
		}
		if (!intp(team[i]->query("deposit")) || team[i]->query("deposit")<1000000)
		{
			command("say ������Σ�յ��£��ҿ�"+RANK_D->query_respect(team[i])+"û���⳥������");
			return 1;
		}
	}
	if (random(100)>50 || query("marks/gived") )
	{
		set("marks/gived",1);
		command("say �������ˣ��Ѿ����˽�����֧���ˡ�");
		return 1;
	}
	
	if (sizeof(team) != 0 && (team[0]!=me)) 
			return notify_fail("say ֻ�ж����������������ڡ�\n");
	set("marks/gived",1);
	command("say �ðɡ���������ͷ�߰ɡ�");
	command("say ���ڿ���Ҫ��˫�ݵģ�һ·С�ġ�");
	
	say("һ���ڳ�����Ժʻ����\n");
	
	ob=new(__DIR__"obj/cart");
	ob->move(environment());
	cart=ob;
	
	biaotou=new(__DIR__"biaotou");
	biaotou->move(environment());
	biaotou->get_quest("/obj/dartway1");
	biaotou->set_cart(cart);
	biaotou->set_protector(team);
	
	
	ob=new(SILVER_OB);
	ob->set_amount(10000+random(10000));
	ob->set("name","����");
	ob->move(cart);
	
	ob=new(__DIR__"biaoshi");
	ob->move(environment());
	ob->set_leader(biaotou);
	ob->set_temp("protecting",cart);
	
	ob=new(__DIR__"biaoshi1");
	ob->move(environment());
	ob->set_leader(biaotou);
	ob->set_temp("protecting",cart);
	
	ob=new(__DIR__"biaoshi1");
	ob->move(environment());
	ob->set_leader(biaotou);
	ob->set_temp("protecting",cart);
    
    for(i=0;i<sizeof(team);i++)
       	team[i]->set_temp("protecting",cart);
    	
    me->set_temp("protecting",cart);
    me->set_leader(biaotou);
    biaotou->go_now();
    return 1;	
}
void reset()
{
delete("marks/gived");
}
