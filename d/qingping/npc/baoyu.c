inherit NPC;

void create()
{
        set_name("小宝儿", ({ "baoer", "fang baoyu" }) );
        set("gender", "男性");
        set("age", 12);
        set("long", 
	"一个十一二岁的锦衣童子，长得唇红齿白，十分招人喜欢，正在竹塌上看书。\n"
	);
	set("attitude", "friendly");
        set("max_kee", 150);

	set("combat_exp", 5000);
        set_skill("dodge", 30);

        setup();
        carry_object(__DIR__"obj/jinyi")->wear();
	add_money("silver", 5);
}

