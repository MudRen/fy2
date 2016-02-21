// TIE@FY3
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("��ھ�", ({ "shen bijun","shen" }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("long",
		"�޹�ɽׯ��ׯ���ˣ��򾲼�˼�������ܵ�����������С���⡣\n");
	set("combat_exp", 900000);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϰ���");
	set("vendor_goods", ([
		__DIR__"obj/bu1" : 10,
		__DIR__"obj/bu2" : 30,
		__DIR__"obj/bu3" : 10,
		__DIR__"obj/bu4" : 5,
	]) );
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "��ھ����˸��򸣣�Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "��Ҫ��ʲô��\n");
			break;
		case 1:
			say( "��ھ��ƺ��������������λ" + RANK_D->query_respect(ob)
				+ "�������û������������ʮһ�ɵ���Ϣ��\n");
			break;
		case 2:
			say( "��ھ������ʵ�����λ" + RANK_D->query_respect(ob)
				+ "���þ�û�л��޹�ɽׯ�ˣ���ʲô��Ϣ��\n");

			break;
	}
}
