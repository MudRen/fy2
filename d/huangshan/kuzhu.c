// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ϫ");
        set("long", @LONG
��;ʢ����������ϪˮҲ�е�����ɬζ��������ҩ��ڣ������
����ҩ����Ʒ����������֮����Ȼ������Ȫ�����ڽⷦ�����а�����
�������ص�����ȡ�����ҩ�����Ǳ���ɽ���ڴ˷�������
LONG
        );
        set("exits", ([ 
  "southup" : __DIR__"jiulong",
]));
        set("objects", ([
                __DIR__"npc/snake" : 2,
       ]) );
        set("item_desc", ([
                "����Ϫ": "��������Ŵ�Ϫ��xi���кȣ�drink��һ�ڡ�\n",
                "kuzhuxi": "��������Ŵ�Ϫ��xi���кȣ�drink��һ�ڡ�\n"
        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-480);
	set("coor/z",10);
	setup();
}
init()
{
add_action("do_drink","drink");
}
int do_drink(string arg)
{
object me;
me=this_player();
if(!arg || arg != "xi") return 0;
if(me->query("water") >= me->max_water_capacity())
return notify_fail("���ƺ������ʡ�\n");
message_vision("$N���������ڿ���Ϫ�к���һ��ڿ�ˮ��\n",me);
me->add("water",50);
me->apply_condition("kuzhu",3+random(5));
return 1;
}
