// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "莲花峰");
        set("long", @LONG
黄山第一高峰。它超然鹤立，群峰簇拥，象一多初绽莲花，仰天怒放，
融雄伟俏丽于一体，是当之无愧的“菡萏金芙蓉”。峰上景色皆以莲花为名，
如莲花沟，莲花梗等。每逢天气晴朗，东望天目，西瞻匡庐，北眺九华，南临
诸峰，视野极为开阔。西去便是后山。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"yuping",
  "westdown" : __DIR__"guangming",
]));
        set("objects", ([
        __DIR__"npc/xiao" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-590);
	set("coor/y",-520);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
