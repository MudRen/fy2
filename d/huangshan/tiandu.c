// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "天都峰");
        set("long", @LONG
天都是三大主峰中最为险峻的一座，古称“群仙所都”，意为天
上都会。现在路边已有依山凿就的石级和铁索围护的登山道，但是仍
然令人有“难于上青天”之感。途中有一石屏风，刻有“天上玉屏”
四字，由此处远望，浮云怪峰，山泉松海，尽收眼底。
LONG
        );
        set("exits", ([ 
  "southdown"  : __DIR__"jiyu",
  "westdown" : __DIR__"yixian",
]));
        set("objects", ([
        __DIR__"npc/hong" : 1,
	__DIR__"npc/lu" :1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-560);
	set("coor/y",-490);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
