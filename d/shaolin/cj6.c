// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
�����ӻҳ����ƺ����������������ݶ��Ǿ���������¥���вؾ�¥
������������������Ҳ�ѽ��룬����ǽ���Ͻ������ľ����ഫΪ����
��Զ��ʦ�������÷������ڡ�����ѧ֮�еĲ������š�
LONG
        );
        set("exits", ([ 
  "down": __DIR__"cj5",
]));
        set("objects", ([
                __DIR__"obj/xisui" : 3,
       ]) );
	set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",120);
	setup();

}
