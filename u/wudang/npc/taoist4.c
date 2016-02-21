inherit NPC;

void create()
{
        set_name("���", ({ "li" }) );
        set("gender", "����");
        set("age", 29);
        set("long",
		"�䵱�ɵ��ӣ���һ����ɫ�ĵ���\n"
	);
        set("combat_exp", random(20000));
        set("score", 200);
        set("class", "taoist");
        set("force", random(300));
        set("max_force", random(300));

        create_family("�䵱��", 58, "����");

        set_skill("move", 10+random(80));
        set_skill("force", 10+random(80));
        set_skill("unarmed", 10+random(80));
        set_skill("sword", 10+random(80));
        set_skill("parry", 10+random(80));
        set_skill("dodge", 10+random(80));
        set_skill("taijiforce", 10+random(50));
        set_skill("taiji", 10+random(50));
        set_skill("three-sword", 10+random(50));
        set_skill("five-steps", 10+random(50));

        map_skill("force", "taijiforce");
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");

        set_skill("changelaw", 60);
        setup();

        add_money("silver", 5);
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/cloth")->wear();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="�䵱��" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say �䵱�ɲ��ͱ��ɵ��˹��С�");
        return 0;
}

int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 10000 ) {
                        say("�����Ǯ�Ž�����˵������������ˡ�\n");
                        who->set_temp("marks/͵��", 0);
                        return 1;
                } else {
                    say("�������˵�������ǲ�����ڻ�¸�ģ�\n");
                        return 0;
                }
        return 0;
} 

 