// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "达摩洞");
        set("long", @LONG
蜿蜒的山间小路，伴随着路边摇曳的竹影，就到了五乳峰的达
摩洞，洞口朝向西南，洞外有明建石坊，正面额题“默玄处”，相
传禅宗初祖达摩在此面壁九年而成正果，现在为少林圣地，由少林
僧兵之佼佼者把守此地。若再往上行片刻，便是五乳峰顶。
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"talin",
  "westup" : __DIR__"wuru",
]));
	set("coor/x",-230);
	set("coor/y",420);
	set("coor/z",70);
	setup();
        replace_program(ROOM);
}
