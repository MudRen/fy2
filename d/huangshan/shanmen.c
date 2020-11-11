// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山门");
        set("long", @LONG
这是一座石雕门坊，过了山门后，便是黄山，这里地属丘陵，古
代称为黔山，因山色黝黑，远望如黛得名，后因唐明皇听信“黄帝在
此飞升”，所以改为黄山。连绵百里，群峰无数，引来无数游人。过
山门后，便是温泉。
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"wenquan", 
  "east" : "/d/chenxiang/cxs1",
]));
        set("objects", ([
        __DIR__"npc/3cheng" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-510);
	set("coor/y",-510);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
