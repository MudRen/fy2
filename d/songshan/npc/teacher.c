// teacher.c

inherit NPC;

void create()
{
	set_name("�λ�", ({ "meng huan", "huan" }) );
        create_family("������", 20, "����");
	set("title", "��������");
        set("vendetta_mark","shaolin");
	set("int",1);
	set("gender", "����" );
	set("age", 57);
        set("chat_chance", 10);
        set("chat_msg", ({
                "�λ��������󽭶�ȥ�����Ծ�ǧ�ŷ��������\n",
        }) );
	set("long",
		"�λ��Ǹ���Ȥ�ĺ��У�������ʱ�����й���ţ�����\n"
		"��Ϊ������;����������Ϊɮ�������Ըѧ����ͷ�\n"
		"�λ����ǻ�̵ģ�\n");
	set("attitude", "peaceful");
	set_skill("literate", 140);
	set_skill("buddhism",100);
	setup();
}

int recognize_apprentice(object ob)
{
	return 1;
}
