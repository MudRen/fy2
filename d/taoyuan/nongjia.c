inherit ROOM;
void create()
{
        set("short", "村居");
        set("long", @LONG
眼前是几处极为普通的村舍，几个小孩子正在屋外追逐打闹，几只肥肥的
大白鹅，看见你来，伸长了脖子嘎嘎的叫，似乎奇怪你居然找到了这里。这里
每当夕阳西下的时候，厚厚的茅草毡成的屋顶便会被淡淡的炊烟罩住，整个村
里弥漫着一股诱人的米饭的香味。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "south" : __DIR__"road1",
   "west" : __DIR__"farm1",
   "east" : __DIR__"farm2",
   "north" : __DIR__"farm",
   ]));

   set("objects", ([
      __DIR__"npc/kid": 2,
   ]) );

   	set("outdoors","taoyuan");
        set("coor/x",190);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}


