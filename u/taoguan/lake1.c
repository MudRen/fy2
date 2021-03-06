
inherit ROOM;

void create()
{
	set("short", "三清湖");
	set("long", @LONG
湖水清澈透明，不时可以看到几尾鱼跳上水面。湖水尽头
是一个大瀑布。在这里可以听到瀑布从山上直冲而下，发出的
轰轰雷声。湖边一块巨石，上写＂三清湖＂。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/u/taoguan/grassland1",
  "north" : "/u/taoguan/lake2",
]));
        set("resource/water",1);
	set("outdoors", "taoguan");
	set("coor/x",-10);
	set("coor/y",2070);
	set("coor/z",80);
	setup();
}

void init()
{
        add_action("do_fillwater", "fillwater");
        add_action("do_swim", "swim");
}

int do_swim(string arg)
{
   return 1;
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "清水",
                                "remaining": 30,
                                "drunk_apply": 6,
                        ]) );
                        write("你从湖里装满了清水! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？");
        }
        return 1;
}
