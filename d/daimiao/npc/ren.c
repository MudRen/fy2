// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("�˺�����", ({ "master ren", "master"}) );
        set("nickname", HIW "�˶����"NOR);
        set("gender", "����" );
        set("age", 62);
	set("per", 3);
        set("agi",25);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 30);
        set("long",
"
�˺���������������еĵ�λ�ǽ����ڵ������˵ģ�
�˺�����ͳ������������е��˶档
\n"
	);
        create_family("�������", 4, "����");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.renmo" :),
                (: perform_action, "dodge.lianhuanbabu" :),
                (: perform_action, "unarmed.renmo" :),
                (: exert_function, "mihun" :)
        }) );
        set("combat_exp", 1000000);
        set("score", 200000);

        set_skill("move", 60);
        set_skill("parry",60);
        set_skill("dodge", 60);
        set_skill("force", 60);
        set_skill("literate", 60);
	set_skill("unarmed",60);
	set_skill("demon-steps",60);
	set_skill("demon-strike",60);
	set_skill("demon-force",60);
	set_skill("perception",60);
	set_skill("stealing",60);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
        setup();
        carry_object(__DIR__"obj/duoyi3")->wear();

}

void attempt_apprentice(object me)
{
	if(me->query("family/family_name") == "�������")
	{
		command("say ������������̵��ӣ���˭ѧ��һ����\n");
		return;
	}
	command("smile");
	command("say ���Ŭ��������һ�鲻��֮�ģ�\n");
        command("recruit " + me->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bandit");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","������̽�ͽ");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","������̸�����");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","�����������");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","������̸�̳��");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","�������̳��");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","������̸�����");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","������̶���");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","������̻���");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","������̴󻤷�");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","������̳���");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","������̴���");
                return ;
        } else
                student->set("title","������̸�����");
                return ;

}
