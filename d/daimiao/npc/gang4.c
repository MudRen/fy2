// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("�����", ({ "zhao", "zhao gang"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "������������Ĵ���֮һ��\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
	set_skill("demon-strike",10);
	set_skill("demon-steps",30);
	set_skill("dodge", 40);
       	map_skill("unarmed", "demon-strike");
	map_skill("dodge","demon-steps");
	set_skill("iron-cloth",150);
	create_family("�������", 8, "����");
	setup();
	add_money("silver", 5);
        carry_object(__DIR__"obj/yellowrobe")->wear();
}
