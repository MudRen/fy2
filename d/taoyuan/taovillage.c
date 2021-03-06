inherit ROOM;
void create()
{
        set("short", "桃源村");
        set("long", @LONG
眼前树影山阴之下，离离地散布着几户房舍，袅袅炊烟轻若无痕，偶有犬吠，
也很快归于平静。在这里，你感觉不到任何尘世的嘈杂，一切都是那样的安宁，就
连轻风拂面，也只带来清清泥草芳香，和远山鸟啼。你的脚旁的一块山石上，依稀
刻着一些字。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"northwest" : __DIR__"fenghuo",
	"east" : __DIR__"road1",
	]) );

	set("item_desc", ([
	"山石": "爬满石苔的山石上，依稀刻着＂桃源村＂三字。\n",
	"stone": "爬满石苔的山石上，依稀刻着＂桃源村＂三字。\n",
	]) );

   	set("outdoors","taoyuan");
        set("coor/x",180);
        set("coor/y",-40);
        set("coor/z",0);
        setup();
}

void pipe_notify()
{
	object  room;
	
message_vision("哨音在这里显的各外得幽美动听。\n", this_player());
	call_out("animal_come", 3);
}

void animal_come()
{
	object deer;

	deer = present("little deer", this_object());
	if(!objectp(deer)) {
		deer = new(__DIR__"npc/deer");
		deer->move(this_object());
message("vision","哨音未落，一只小梅花鹿就从树丛后跑了出来。\n", this_object());
	}
	return;	
}
