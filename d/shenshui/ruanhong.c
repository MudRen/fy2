// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "软红山庄");
        set("long", @LONG
走过曲折的石梯，终于到达了路的尽头，在这山腹之中能有如此建筑已是
绝顶的奇迹，偏偏如此一间普通的屋子却有着一个非常好听的名字－－软红山
庄，再往前是一幢小楼，已经可以上面四个黑底金嵌的字－－星星小楼．
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"xingxing",
  "northdown" : __DIR__"huoyan",
]));
	set("outdoors","shenshui");
	set("coor/x",200);
	set("coor/y",12320);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
