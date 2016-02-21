// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "桃源亭");
        set("long", @LONG
这里位于桃花峰上，周围溪流环绕，宛若仙居，故称桃源亭，此
处最佳之处在于可以静心欣赏黄山三名瀑之一的“人字瀑”，远看过
去，瀑布倾泄，恰好是个人字，煞是有趣。
LONG
        );
        set("exits", ([ 
  "north"  : __DIR__"ciguang",
]));
        set("objects", ([
                __DIR__"obj/ting" : 1,
       ]) );
        set("outdoors", "huangshan");
	set("coor/x",-530);
	set("coor/y",-520);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
