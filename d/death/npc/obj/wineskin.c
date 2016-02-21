// waterskin.c
#include <login.h>
inherit ITEM;
inherit F_LIQUID;
string *revive_loc= ({
        "/d/fy/church",
        "/u/guanwai/tower",
});
void create()
{
	set_name("ţƤ�ƴ�", ({ "jiudai", "dai" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ţƤ��Ĵ�ƴ������װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 20);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "������",
		"remaining": 5,
		"drunk_apply": 6,
	]) );
}

int do_drink(string arg)
{
   int foo;
   foo=::do_drink(arg);
   if (!foo) return foo;
   if(this_player()->is_ghost())
   {
	this_player()->reincarnate();
	this_player()->move(revive_loc[random(sizeof(revive_loc))]);
	this_player()->set("startroom", base_name(environment(this_player())));
	message("vision",
                "���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
                "�ܾ��ˣ�ֻ����һֱû������\n", environment(this_player()), this_player());

   }	
  return 1;
}
