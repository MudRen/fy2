// tea_waiter.c

inherit NPC;
void create()
{
        set_name("���", ({ "xiang ke" }) );
        set("gender", (random(2)? "Ů��":"����") );
        set("age", random(40)+10);
        set("long",
                "һ����ɽ�������������\n");
	set("combat_exp", 5+random(500));
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
                "���ָ����Χ�ľ�ɫ̾��������ѽ����\n",
		"��͵�������Ϊһ����ɽ����\n",
                "��Ͷ���˵������Ҳ��������ģ�\n",
                "��Ͷ���˵�����������������ˣ�\n",
                "��Ͷ���˵������������ݰ����ԣ�������飡\n",
                "��Ͷ���˵�������ϴ��ڴ˽������ӣ�����������ˣ����������Ը�ģ�\n",
        }) );

        set("attitude", "friendly");
        set("rank_info/respect", "ʩ��");
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{
        add_action("do_vendor_list", "list");
}
