// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "青鸾桥");
        set("long", @LONG
说是青鸾桥，确切的应该是倚山势看上去是桥，实际上是一座石
梁，远望去好似青鸾腾空，背上可以行人，石梁左侧刻有“青鸾”二
字，北去便是黄山三名瀑之“百丈泉”，西行便是半山寺了。
LONG
        );
        set("exits", ([ 
  "eastup"  : __DIR__"ciguang",
  "south" : __DIR__"renzi",
  "southwest" : __DIR__"zuishi",
  "north" : __DIR__"baizhang",
  "westup" : __DIR__"banshan",
]));
        set("objects", ([
                __DIR__"obj/stone" : 1,
       ]) );
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-510);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
