// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "九龙瀑");
        set("long", @LONG
此瀑源于天都，玉屏诸峰，然后在香炉，罗汉两峰的悬崖九折而下，
一折一潭，九瀑九潭，因此得名。每逢大雨之后，瀑水从天而降，流
而复折，折而复聚，悬于千仞绝壁，宛如九龙飞舞，姿态曼妙。
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"baizhang",
//  "up" : "/d/shenshui/midao1",
  "northdown" : __DIR__"kuzhu",
]));
        set("item_desc", ([
                "绝壁": "这里虽然陡峭无比，但石壁突兀不平，你可以试着从这（cliff）爬（climb）上去。\n"
        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-490);
	set("coor/z",20);
	setup();
}
void init()
{
add_action("do_climb","climb");
}
int do_climb(string arg)
{
object me;
me= this_player();
if(!arg || arg != "cliff") return 0;
message_vision("$N抓住绝壁上突出的石块，向上小心爬去！\n", me);
me->start_busy(2);
call_out("arrive",2,me);
return 1;
}
int arrive(object me)
{
if(me)
{
message_vision("$N一失手，从上面掉了下来！\n",me);
me->receive_wound("kee",100);
}
return 1;
}
