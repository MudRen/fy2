// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������ķ����Ժ֮һ���ഫ�Ǻ�����Ϊ�����ĸ�ɮ��
�����뾭�����ҹ�����ĵڶ������£�ֻ�����������������ꡣ��
�۵�ǰ��ǧ��������Ҷ�����������ǡ��¶�˫����죬�л����ţ�
�����˵Ƿ�˾�֮�����Ŵ��¡��澰��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"shita", 
]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"obj/tree" : 1,
       ]) );
	set("coor/x",-220);
	set("coor/y",430);
	set("coor/z",70);
	setup();
        replace_program(ROOM);
}